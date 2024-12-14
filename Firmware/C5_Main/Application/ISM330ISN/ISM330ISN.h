/*
 * ISM330ISN.h
 *
 *  Created on: Nov 30, 2024
 *      Author: user
 */

#ifndef ISM330ISN_H_
#define ISM330ISN_H_
#include "ISM330ISN_Config.h"
#ifndef ISM_Delay
#error "Define the delay function!"
#endif
#ifndef ISM_WriteData
#error "Define uploading values to a given address!"
#endif
#ifndef ISM_ReceiveData
#error "Define reading values from under a given address!"
#endif
#ifndef ISM_CS_Low
#error "Define the operation of the CS line!"
#endif
#ifndef ISM_CS_High
#error "Define the operation of the CS line!"
#endif
#define ISM330_ACC_DRDY_MASK  0x01
#define ISM330_GYRO_DRDY_MASK 0x02
typedef enum
{
   ISM330_REG_FUNC_CFG_ACCESS           = 0x01,
   ISM330_REG_PIN_CTRRL                 = 0x02,
   ISM330_REG_DRDY_PULSED_REG           = 0x0B,
   ISM330_REG_INT1_CTRL                 = 0x0D,
   ISM330_REG_INT2_CTRL                 = 0x0E,
   ISM330_REG_WHU_AM_I                  = 0x0F,
   ISM330_REG_CTRL1_XL                  = 0x10,
   ISM330_REG_CTRL2_G                   = 0x11,
   ISM330_REG_CTRL3_C                   = 0x12,
   ISM330_REG_CTRL4_C                   = 0x13,
   ISM330_REG_CTRL5_C                   = 0x14,
   ISM330_REG_CTRL6_C                   = 0x15,
   ISM330_REG_CTRL7_G                   = 0x16,
   ISM330_REG_CTRL9_C                   = 0x18,
   ISM330_REG_CTRL10_C                  = 0x19,
   ISM330_REG_ISPU_INT_STATUS0_MAINPAGE = 0x1A,
   ISM330_REG_ISPU_INT_STATUS1_MAINPAGE = 0x1B,
   ISM330_REG_ISPU_INT_STATUS2_MAINPAGE = 0x1C,
   ISM330_REG_ISPU_INT_STATUS3_MAINPAGE = 0x1D,
   ISM330_REG_STATUS_REG                = 0x1E,
   ISM330_REG_TEMP_L                    = 0x20,
   ISM330_REG_TEMP_H                    = 0x21,
   ISM330_REG_OUTX_L_G                  = 0x22,
   ISM330_REG_OUTX_H_G                  = 0x23,
   ISM330_REG_OUTY_L_G                  = 0x24,
   ISM330_REG_OUTY_H_G                  = 0x25,
   ISM330_REG_OUTZ_L_G                  = 0x26,
   ISM330_REG_OUTZ_H_G                  = 0x27,
   ISM330_REG_OUTX_L_A                  = 0x28,
   ISM330_REG_OUTX_H_A                  = 0x29,
   ISM330_REG_OUTY_L_A                  = 0x2A,
   ISM330_REG_OUTY_H_A                  = 0x2B,
   ISM330_REG_OUTZ_L_A                  = 0x2C,
   ISM330_REG_OUTZ_H_A                  = 0x2D,
   ISM330_REG_STATUS_MASTER_MAINPAGE    = 0x39,
   ISM330_REG_TIMESTAM0                 = 0x40,
   ISM330_REG_TIMESTAM1                 = 0x41,
   ISM330_REG_TIMESTAM2                 = 0x42,
   ISM330_REG_TIMESTAM3                 = 0x43,
   ISM330_REG_MD1_CFG                   = 0x5E,
   ISM330_REG_MD2_CFG                   = 0x5F,
   ISM330_REG_INTERNAL_FREQ_FINE        = 0x63,
   ISM330_REG_ISPU_DUMMY_CFG_1_L        = 0x73,
   ISM330_REG_ISPU_DUMMY_CFG_1_H        = 0x74,
   ISM330_REG_ISPU_DUMMY_CFG_2_L        = 0x75,
   ISM330_REG_ISPU_DUMMY_CFG_2_H        = 0x76,
   ISM330_REG_ISPU_DUMMY_CFG_3_L        = 0x77,
   ISM330_REG_ISPU_DUMMY_CFG_3_H        = 0x78,
   ISM330_REG_ISPU_DUMMY_CFG_4_L        = 0x79,
   ISM330_REG_ISPU_DUMMY_CFG_4_H        = 0x7A,
} ISM30ISNRegisterName_TypeDef;
typedef struct
{
   float AccX;
   float AccY;
   float AccZ;
   float GX;
   float GY;
   float GZ;
} ISM_TypeDef;
void ISM330ISN_Init(void);
void ISM330ISN_Hanler(ISM_TypeDef *ISM);
#endif /* ISM330ISN_H_ */
