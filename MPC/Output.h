#include <PID_v1.h>

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

//PID:
double Input_Yaw, Output_Yaw, Setpoint_Yaw;
double Input_Pitch, Output_Pitch, Setpoint_Pitch;
double Input_Roll, Output_Roll, Setpoint_Roll;
double Input_Height, Output_Height, Setpoint_Height;

//PID:
PID PID_Yaw(&Input_Yaw, &Output_Yaw, &Setpoint_Yaw, DEF_KP_YAW, DEF_KI_YAW, DEF_KD_YAW, DIRECT);
PID PID_Pitch(&Input_Pitch, &Output_Pitch, &Setpoint_Roll, DEF_KP_PITCH, DEF_KI_PITCH, DEF_KD_PITCH, DIRECT);
PID PID_Roll(&Input_Roll, &Output_Roll, &Setpoint_Yaw, DEF_KP_ROLL, DEF_KI_ROLL, DEF_KD_ROLL, DIRECT);
PID PID_Height(&Input_Height, &Output_Height, &Setpoint_Height, DEF_KP_HEIGHT, DEF_KI_HEIGHT, DEF_KD_HEIGHT, DIRECT);
