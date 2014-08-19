#ifndef __IIC_CONFIG__
#define __IIC_CONFIG__

#include "main.h"

#define I2CTouch_PORT   GPIOH

#define SDATouch_Pin	   GPIO_Pin_5
#define SCLTouch_Pin     GPIO_Pin_4



 void I2cGpioInit(void);
uint8_t i2cPutbyte(uint8_t b);
uint8_t i2cGetbyte(uint8_t last);
uint8_t i2cWriteStart(void);
uint8_t i2cReadStart(void);
void i2cstart(void);
void i2cstop(void);
void SCL_Output_Touch( uint16_t val );
void SDA_Input_Mode_Touch(void);
uint8_t SDA_Input_Touch(void);
void SDA_Output_Mode_Touch(void);
void SDA_Output_Touch( uint16_t val );
void SCL_Output_Mode_Touch(void);

#define IIC_SEND_START          i2cstart()
#define IIC_SEND_STOP           i2cstop()  

#define IOE_I2C                    I2C3
#define IOE_I2C_CLK                RCC_APB1Periph_I2C3
#define IOE_I2C_SCL_PIN            GPIO_Pin_8
#define IOE_I2C_SCL_GPIO_PORT      GPIOA
#define IOE_I2C_SCL_GPIO_CLK       RCC_AHB1Periph_GPIOA
#define IOE_I2C_SCL_SOURCE         GPIO_PinSource8
#define IOE_I2C_SCL_AF             GPIO_AF_I2C3
#define IOE_I2C_SDA_PIN            GPIO_Pin_9
#define IOE_I2C_SDA_GPIO_PORT      GPIOC
#define IOE_I2C_SDA_GPIO_CLK       RCC_AHB1Periph_GPIOC
#define IOE_I2C_SDA_SOURCE         GPIO_PinSource9
#define IOE_I2C_SDA_AF             GPIO_AF_I2C3
#define IOE_I2C_DR                 ((uint32_t)0x40005C10)

/** 
  * @brief  IO Expander Interrupt line on EXTI  
  */ 
#define IOE_IT_PIN                 GPIO_Pin_2
#define IOE_IT_GPIO_PORT           GPIOI
#define IOE_IT_GPIO_CLK            RCC_AHB1Periph_GPIOI
#define IOE_IT_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOI
#define IOE_IT_EXTI_PIN_SOURCE     EXTI_PinSource2
#define IOE_IT_EXTI_LINE           EXTI_Line2
#define IOE_IT_EXTI_IRQn           EXTI2_IRQn   

#define I2C_SDA_HI								SDA_Input_Mode_Touch()
#define I2C_SDA_LO								SDA_Output_Mode_Touch();\
																	SDA_Output_Touch(0)						
#define I2C_SCL_HI								SCL_Input_Mode_Touch()
#define I2C_SCL_LO								SCL_Output_Mode_Touch();\
																	SCL_Output_Touch(0)		
#define HALF_BIT_DLEAY					  delay1_Touch(50)
#endif
