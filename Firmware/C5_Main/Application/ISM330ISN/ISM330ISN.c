/*
 * ISM330ISN.c
 *
 *  Created on: Nov 30, 2024
 *      Author: user
 */
#include "main.h"

#include "ISM330ISN.h"

#include "ISM330ISN_Config.h"

static float ISM330_Map(float x, float in_min, float in_max, float out_min, float out_max)
{
   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static void ISM_WriteDataToRegister(uint8_t *Data, uint8_t Size)
{
   ISM_CS_Low();
   Data[0] &= 0x7F;
   ISM_WriteData(Data, Size);
   ISM_CS_High();
}
static void ISM_ReadDataFromRegister(uint8_t *DataOut, uint8_t *DataIn, uint8_t Size)
{
   ISM_CS_Low();
   DataOut[0] |= 0x80;
   ISM_TransmitReceiveData(DataOut, DataIn, Size);
   ISM_CS_High();
}
static void ISM330_CalculateAcc(ISM_TypeDef *ISM, uint8_t *Data)
{
   int16_t X = (int16_t)(Data[1] | (Data[2] << 8));
   int16_t Y = (int16_t)(Data[3] | (Data[4] << 8));
   int16_t Z = (int16_t)(Data[5] | (Data[6] << 8));
   ISM->AccX = ISM330_Map(X, -32764, 32764, -4, 4);
   ISM->AccY = ISM330_Map(Y, -32764, 32764, -4, 4);
   ISM->AccZ = ISM330_Map(Z, -32764, 32764, -4, 4);
}
static void ISM330_CalculateGyro(ISM_TypeDef *ISM, uint8_t *Data)
{
   ISM->GX = (float)(int16_t)(Data[0] | (Data[1] << 8));
   ISM->GY = (float)(int16_t)(Data[2] | (Data[3] << 8));
   ISM->GZ = (float)(int16_t)(Data[4] | (Data[5] << 8));
}
void ISM330ISN_Init(void)
{
   uint8_t RegisterOut[2] = { ISM330_REG_WHU_AM_I, 0 };
   uint8_t RegisterIn[2]  = { 0 };
   ISM_ReadDataFromRegister(RegisterOut, RegisterIn, 2);
   uint8_t Data[2] = { ISM330_REG_CTRL1_XL, 0b10111000 };
   ISM_WriteDataToRegister(Data, 2);
   Data[0] = ISM330_REG_CTRL2_G;
   Data[1] = 0b00010000;
   ISM_WriteDataToRegister(Data, 2);
}
void ISM330ISN_Hanler(ISM_TypeDef *ISM)
{
   uint8_t DataOut[2] = { ISM330_REG_STATUS_REG, 0 };
   uint8_t DataIn[2]  = { 0 };
   ISM_ReadDataFromRegister(DataOut, DataIn, 2);
   if((DataIn[1] & ISM330_ACC_DRDY_MASK) != 0)
   {
      uint8_t AccDataOut[7] = { ISM330_REG_OUTX_L_A, 0, 0, 0, 0, 0, 0 };
      uint8_t AccDataIn[7]  = { 0 };
      ISM_ReadDataFromRegister(AccDataOut, AccDataIn, 7);
      ISM330_CalculateAcc(ISM, AccDataIn);
   }
   if((DataIn[1] & ISM330_GYRO_DRDY_MASK) != 0)
   {
      uint8_t MagDataOut[7] = { ISM330_REG_OUTX_L_G, 0, 0, 0, 0, 0, 0 };
      uint8_t MagDataIn[7]  = { 0 };
      ISM_ReadDataFromRegister(MagDataOut, MagDataIn, 7);
      ISM330_CalculateGyro(ISM, MagDataIn);
   }
}
