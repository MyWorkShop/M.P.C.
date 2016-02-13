#include <Arduino.h>
#include <Servo.h>
#include <ESC.h>

int ESC_Servo_Init();

//ESC:
ESC ESC_A, ESC_B, ESC_C, ESC_D;

//Servo:
Servo Servo_1, Servo_2, Servo_3, Servo_4;

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


