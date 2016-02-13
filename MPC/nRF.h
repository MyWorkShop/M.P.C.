//	---------------------------------
//	|	控制包定义		|
//	|-------------------------------|
//	|bit	|数据	|解释		|
//	|-------------------------------|
//	|0	|0xAA	|控制包帧头	|
//	|1	|Height	|高度 		|
//	|2	|Yaw	| 欧 		|
//	|3 	|Pitch	| 拉 		|
//	|4	|Roll	| 角 		|
//	|5	|	|		|
//	|6	|	|		|
//	|7 	|0x8A	|控制包结束	| 
//	---------------------------------

#include <Arduino.h>
#include <SPI.h>
#include <nRF905.h>
#include <nRF905_config.h>
#include <nRF905_defs.h>
#include <nRF905_types.h>

#define RXADDR {0xFE, 0x4C, 0xA6, 0xE5} // Address of this device (4 bytes)
#define TXADDR {0x58, 0x6F, 0x2E, 0x10} // Address of device to send to (4 bytes)

void nRF_Init();
void nRF_Loop();
void *nRF_RX();

byte RF_RX[NRF905_MAX_PAYLOAD];

//=============================
//==========nRF_Init===========
//=============================
void nRF_Init()
{
  nRF905_init();

  // Set address of this device
  byte addr[] = RXADDR;
  nRF905_setRXAddress(addr);

  // Put into receive mode
  nRF905_receive();
  
}

//=============================
//==========nRF_Loop===========
//=============================

void nRF_Loop()
{
  byte buffer[NRF905_MAX_PAYLOAD];
  
  if (nRF905_getData(buffer, sizeof(buffer)))
  {
    if (buffer[0]==0xAA)
    {
  //  nRF_RX();
    }
  }
    
}
