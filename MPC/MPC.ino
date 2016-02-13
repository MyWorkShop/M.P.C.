
/************************************************************************
*************************************************************************
           ___        ___             ____________           _________
         /    |     /    |          /   _________  \       /   ________\
        /  |  |    /  |  |         /  /         /  /      /  /
       /  /|  |   /  /|  |        /  /_________/  /      /  /
      /  / |  |  /  / |  |       /   ____________/      /  /
     /  /  |  | /  /  |  |      /  /                   /  /
    /  /   |  |/  /   |  |     /  /                   /  /
   /  /    |  /  /    |  |    /  /                   /  /_________
  /__/     |____/     |__|   /__/                    \_____________\  
                                                               1.0.Beta
*************************************************************************
************************************************************************/

/*
 **** How to connect with nRF905: ****
 * 44 -> CE
 * 47 -> PWR
 * 48 -> TXE
 * 45 -> CD
 * 49 -> DR
 * 53 -> CSN
 * 50 -> SO
 * 51 -> SI
 * 52 -> SCK
 *
 **** How to connect with HMC5883l & MPU6050: ****
 *SDA -> SDA
 *SCL -> SCL
 *
 **** How to connect with ESC_A & ESC_B & ESC_C & ESC_D: ****
 *2 -> ESC_A
 *3 -> ESC_B
 *4 -> ESC_C
 *5 -> ESC_D
 *
 **** How to connect with Servo_1 & Servo_2 & Servo_3 & Servo_4: ****
 *6 -> Servo_1
 *7 -> Servo_2
 *8 -> Servo_3
 *9 -> Servo_4
 */

//=============================
//==========Head File==========
//=============================

#include <SPI.h>



#include <PID_v1.h>

#include <Servo.h>
#include <ESC.h>

#include "IMU.h"
#include <Wire.h>
#include <KalmanFilter.h>
#include <HMC5883L.h>
#include <MPU6050.h>

#include "nRF.h"
#include <nRF905.h>
#include <nRF905_config.h>
#include <nRF905_defs.h>
#include <nRF905_types.h>
//==========================
//==========Define==========
//==========================
/////////////////////////Debug/////////////////////////
#define _DEBUG_                                  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SELECT DEBUG HERE!!!
/////////////////////////Debug/////////////////////////

//PID:
#define DEF_KP_YAW 1
#define DEF_KI_YAW 1
#define DEF_KD_YAW 1
#define DEF_KP_PITCH 1
#define DEF_KI_PITCH 1
#define DEF_KD_PITCH 1
#define DEF_KP_ROLL 1
#define DEF_KI_ROLL 1
#define DEF_KD_ROLL 1
#define DEF_KP_HEIGHT 1
#define DEF_KI_HEIGHT 1
#define DEF_KD_HEIGHT 1

//============================
//==========Function==========
//============================

int ESC_Servo_Init();

//=============================
//==========BianLiang==========
//=============================

//PID:
double Input_Yaw, Output_Yaw, Setpoint_Yaw;
double Input_Pitch, Output_Pitch, Setpoint_Pitch;
double Input_Roll, Output_Roll, Setpoint_Roll;
double Input_Height, Output_Height, Setpoint_Height;

//=========================
//==========Class==========
//=========================

//ESC:
ESC ESC_A, ESC_B, ESC_C, ESC_D;

//Servo:
Servo Servo_1, Servo_2, Servo_3, Servo_4;



//PID:
PID PID_Yaw(&Input_Yaw, &Output_Yaw, &Setpoint_Yaw, DEF_KP_YAW, DEF_KI_YAW, DEF_KD_YAW, DIRECT);
PID PID_Pitch(&Input_Pitch, &Output_Pitch, &Setpoint_Roll, DEF_KP_PITCH, DEF_KI_PITCH, DEF_KD_PITCH, DIRECT);
PID PID_Roll(&Input_Roll, &Output_Roll, &Setpoint_Yaw, DEF_KP_ROLL, DEF_KI_ROLL, DEF_KD_ROLL, DIRECT);
PID PID_Height(&Input_Height, &Output_Height, &Setpoint_Height, DEF_KP_HEIGHT, DEF_KI_HEIGHT, DEF_KD_HEIGHT, DIRECT);

//=========================
//==========Setup==========
//=========================

void setup() {

#ifdef _DEBUG_
  Serial.begin(250000);
#endif

  MPU_Init();
  HMC_Init();
  ESC_Servo_Init();
  IMU_Init();
  nRF_Init();

}

//========================
//==========Loop==========
//========================

void loop() {

  IMU_Loop();
  nRF_Loop();

}

//==================================
//==========ESC_Servo_Init==========
//==================================

int ESC_Servo_Init()
{

#ifdef _DEBUG_
  Serial.println("[INF]  ESC and Servo initing!");
#endif

  ESC_A.attach(2);
  ESC_B.attach(3);
  ESC_C.attach(4);
  ESC_D.attach(5);

  Servo_1.attach(6);
  Servo_2.attach(7);
  Servo_3.attach(8);
  Servo_4.attach(9);

#ifdef _DEBUG_
  Serial.println("[INF]  ESC and Servo init successful!");
#endif

}


