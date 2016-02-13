#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <MPU6050.h>
#include <KalmanFilter.h>


//AHRS:
#define Kp 2.0f	 // 比例增益支配收敛率yawerometer/magnetometer  
#define Ki 0.005f	 // 积分增益执政速率陀螺仪的衔接gyroscopeases  
#define halfT 0.5f	 // 采样周期的一半  

int MPU_Init();
int HMC_Init();
void AHRS_Update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
void Get_Eulerian_Angle();
double RADtoDEG(double rad);
void IMU();
void IMU_Loop();
void IMU_Init();

//IMU:
float Yaw_Get, Pitch_Get, Roll_Get;
//AHRS:
float q0 = 1, q1 = 0, q2 = 0, q3 = 0;	// 四元数的元素，代表估计方向
float exInt = 0, eyInt = 0, ezInt = 0;	// 按比例缩小积分误差

//KalmanFilter:
KalmanFilter KalmanFilter_Yaw, KalmanFilter_Pitch, KalmanFilter_Roll;
//MPU6050:
MPU6050 mpu;
//HMC5883L
HMC5883L compass;

//================================
//==========AHRS_Update===========
//================================

void AHRS_Update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz) {

  float norm;
  float hx, hy, hz, bx, bz;
  float vx, vy, vz, wx, wy, wz;
  float ex, ey, ez;

  // 辅助变量，以减少重复操作数
  float q0q0 = q0 * q0;
  float q0q1 = q0 * q1;
  float q0q2 = q0 * q2;
  float q0q3 = q0 * q3;
  float q1q1 = q1 * q1;
  float q1q2 = q1 * q2;
  float q1q3 = q1 * q3;
  float q2q2 = q2 * q2;
  float q2q3 = q2 * q3;
  float q3q3 = q3 * q3;

  // 测量正常化
  norm = sqrt(ax * ax + ay * ay + az * az);
  ax = ax / norm;
  ay = ay / norm;
  az = az / norm;
  norm = sqrt(mx * mx + my * my + mz * mz);
  mx = mx / norm;
  my = my / norm;
  mz = mz / norm;

  // 计算参考磁通方向
  hx = 2 * mx * (0.5 - q2q2 - q3q3) + 2 * my * (q1q2 - q0q3) + 2 * mz * (q1q3 + q0q2);
  hy = 2 * mx * (q1q2 + q0q3) + 2 * my * (0.5 - q1q1 - q3q3) + 2 * mz * (q2q3 - q0q1);
  hz = 2 * mx * (q1q3 - q0q2) + 2 * my * (q2q3 + q0q1) + 2 * mz * (0.5 - q1q1 - q2q2);
  bx = sqrt((hx * hx) + (hy * hy));
  bz = hz;

  //估计方向的重力和磁通（V和W）
  vx = 2 * (q1q3 - q0q2);
  vy = 2 * (q0q1 + q2q3);
  vz = q0q0 - q1q1 - q2q2 + q3q3;
  wx = 2 * bx * (0.5 - q2q2 - q3q3) + 2 * bz * (q1q3 - q0q2);
  wy = 2 * bx * (q1q2 - q0q3) + 2 * bz * (q0q1 + q2q3);
  wz = 2 * bx * (q0q2 + q1q3) + 2 * bz * (0.5 - q1q1 - q2q2);

  // 错误是跨产品的总和之间的参考方向的领域和方向测量传感器
  ex = (ay * vz - az * vy) + (my * wz - mz * wy);
  ey = (az * vx - ax * vz) + (mz * wx - mx * wz);
  ez = (ax * vy - ay * vx) + (mx * wy - my * wx);

  // 积分误差比例积分增益
  exInt = exInt + ex * Ki;
  eyInt = eyInt + ey * Ki;
  ezInt = ezInt + ez * Ki;

  // 调整后的陀螺仪测量
  gx = gx + Kp * ex + exInt;//Yaw
  gy = gy + Kp * ey + eyInt;//Pitch
  gz = gz + Kp * ez + ezInt;//Roll

  // 整合四元数率和正常化
  q0 = q0 + (-q1 * gx - q2 * gy - q3 * gz) * halfT;
  q1 = q1 + (q0 * gx + q2 * gz - q3 * gy) * halfT;
  q2 = q2 + (q0 * gy - q1 * gz + q3 * gx) * halfT;
  q3 = q3 + (q0 * gz + q1 * gy - q2 * gx) * halfT;

  // 正常化四元
  norm = sqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
  q0 = q0 / norm;
  q1 = q1 / norm;
  q2 = q2 / norm;
  q3 = q3 / norm;

}

//=======================================
//==========Get_Eulerian_Angle===========
//=======================================

void Get_Eulerian_Angle()
{

  Yaw_Get = atan2(2 * (q0 * q1 + q2 * q3), 1 - 2 * (q1 * q1 + q2 * q2));
  Pitch_Get = asin(2 * (q0 * q2 - q1 * q3));
  Roll_Get = atan2(2 * (q0 * q3 + q1 * q2), 1 - 2 * (q2 * q2 + q3 * q3));
  Yaw_Get = RADtoDEG(Yaw_Get);
  Pitch_Get = RADtoDEG(Pitch_Get);
  Roll_Get = RADtoDEG(Roll_Get);

}

//=============================
//==========RADtoDEG===========
//=============================

double RADtoDEG(double rad)
{

  return (rad * 180) / M_PI;

}

//========================
//==========IMU===========
//========================

void IMU()
{

  Vector Accel = mpu.readNormalizeAccel();
  Vector Gyro = mpu.readNormalizeGyro();
  Vector norm = compass.readNormalize();

  AHRS_Update(Gyro.XAxis, Gyro.YAxis, Gyro.ZAxis, Accel.XAxis, Accel.YAxis, Accel.ZAxis, norm.XAxis, norm.YAxis, norm.ZAxis);
  Get_Eulerian_Angle();

}

//=============================
//==========IMU_Loop===========
//=============================

void IMU_Loop()
{

  IMU();

  KalmanFilter_Yaw.correct(Yaw_Get);
  KalmanFilter_Pitch.correct(Pitch_Get);
  KalmanFilter_Roll.correct(Roll_Get);
}

//=============================
//==========IMU_Init===========
//=============================

void IMU_Init()
{

  IMU();

  KalmanFilter_Yaw.setState(Yaw_Get);
  KalmanFilter_Pitch.setState(Pitch_Get);
  KalmanFilter_Roll.setState(Roll_Get);
}

//============================
//==========HMC_Init==========
//============================

int HMC_Init()
{

#ifdef _DEBUG_
  Serial.println("[INF]  HMC5883l initing!");
#endif

  // Initialize HMC5883L
  while (!compass.begin())
  {
#ifdef _DEBUG_
    Serial.println("[ERR]  HMC5883l init failed!");
#endif
    delay(500);
  }

  // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_75HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);

  // Set calibration offset. See HMC5883L_calibration.ino
  compass.setOffset(0, 0);

#ifdef _DEBUG_
  Serial.println("[INF]  HMC5883l init successful!");
#endif

}

//============================
//==========MPU_Init==========
//============================

int MPU_Init()
{

#ifdef _DEBUG_
  Serial.println("[INF]  MPU6050 initing!");
#endif

  // Initialize MPU6050
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {

#ifdef _DEBUG_
    Serial.println("[ERR]  MPU6050 init failed!");
#endif

    delay(500);
  }

  // Enable bypass mode
  mpu.setI2CMasterModeEnabled(false);
  mpu.setI2CBypassEnabled(true);
  mpu.setSleepEnabled(false);

#ifdef _DEBUG_
  Serial.println("[INF]  MPU6050 init successful!");
#endif

}


