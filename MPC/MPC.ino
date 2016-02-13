
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

#include "Output.h"
#include <PID_v1.h>

#include "ESC_Servo.h"
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
#include <SPI.h>

/////////////////////////Debug/////////////////////////
#define _DEBUG_                                  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SELECT DEBUG HERE!!!
/////////////////////////Debug/////////////////////////

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

