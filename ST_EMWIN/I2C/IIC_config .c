#include "main.h"
#include "IIC_config.h"





/*
*  SDA 管脚作为输入模式
*/
void SDA_Input_Mode_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDATouch_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(I2CTouch_PORT, &GPIO_InitStructure);
}
/*
*  SDA 管脚作为输出模式
*/
void SDA_Output_Mode_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SDATouch_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_Init(I2CTouch_PORT, &GPIO_InitStructure);
}
/*
*  SDA 管脚输出电平
*/
void SDA_Output_Touch( uint16_t val )
{
	if ( val ) {
		GPIO_SetBits(I2CTouch_PORT,SDATouch_Pin);
	} else {
		GPIO_ResetBits(I2CTouch_PORT,SDATouch_Pin);
	}
}
/*
*  SDA 管脚读取电平
*/
uint8_t SDA_Input_Touch(void)
{
	return GPIO_ReadInputDataBit(I2CTouch_PORT, SDATouch_Pin);
}
/*
*  SCL 管脚作为输出模式
*/
void SCL_Output_Mode_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SCLTouch_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_Init(I2CTouch_PORT, &GPIO_InitStructure);
}
/*
*  SCL 管脚作为输入模式
*/
void SCL_Input_Mode_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = SCLTouch_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(I2CTouch_PORT, &GPIO_InitStructure);
}
/*
*  SCL 管脚输出电平
*/
void SCL_Output_Touch( uint16_t val )
{
	if ( val ) {
		GPIO_SetBits(I2CTouch_PORT,SCLTouch_Pin);
	} else {
		GPIO_ResetBits(I2CTouch_PORT,SCLTouch_Pin);
	}
}
/*
*  SCL 管脚读取电平
*/
uint8_t SCL_Input_Touch(void)
{
	return GPIO_ReadInputDataBit(I2CTouch_PORT, SCLTouch_Pin);
}
/*
*  简单延时
*/
void delay1_Touch(unsigned int n)
{
	unsigned int i;
	for ( i=0;i<n;++i);
}
/*****************************************************************************
*function: IIC start condition
*****************************************************************************/
void I2CStart_Touch(void)
{
	I2C_SDA_HI;HALF_BIT_DLEAY;
	I2C_SCL_HI;HALF_BIT_DLEAY;
	I2C_SDA_LO;HALF_BIT_DLEAY;
	I2C_SCL_LO;HALF_BIT_DLEAY;
	//开始条件  SCL为高电平时  SDA高电平变为低电平 表示一个开始条件
}
/*****************************************************************************
*function: IIC stop condition
*****************************************************************************/
void I2CStop_Touch(void)
{
	I2C_SCL_LO; HALF_BIT_DLEAY;
	I2C_SDA_LO; HALF_BIT_DLEAY;
	I2C_SCL_HI; HALF_BIT_DLEAY;
	I2C_SDA_HI; HALF_BIT_DLEAY;
	//停止条件  SCL为高电平时   SDA低电平变为高电平	 表示一个停止条件
}
/*****************************************************************************
*function: IIC wait ACK
*****************************************************************************/
uint8_t I2CWaitAck_Touch(void)
{
	unsigned short cErrTime = 50;
	SDA_Input_Mode_Touch(); 
	HALF_BIT_DLEAY;
	I2C_SCL_HI;
	while(SCL_Input_Touch() == Bit_RESET);
	HALF_BIT_DLEAY;
	while(SDA_Input_Touch())
	{
		cErrTime--;
		HALF_BIT_DLEAY;
		if (0 == cErrTime)
		{
			SDA_Output_Mode_Touch();
			I2CStop_Touch();
			return ERROR;
		}
	}
	SDA_Output_Mode_Touch();
	I2C_SCL_LO;HALF_BIT_DLEAY; 
	return SUCCESS;
}
/*****************************************************************************
*function: IIC send ACK
*****************************************************************************/
void I2CSendAck_Touch(void)
{
	I2C_SDA_LO;HALF_BIT_DLEAY;
	HALF_BIT_DLEAY;
	I2C_SCL_HI; HALF_BIT_DLEAY;
	I2C_SCL_LO; HALF_BIT_DLEAY;
	//发送确认ACK  SDA拉低 	并发送停止信号
}
/*****************************************************************************
*function: IIC send Not ACK
*****************************************************************************/
void I2CSendNotAck_Touch(void)
{
	I2C_SDA_HI;
	HALF_BIT_DLEAY;
	I2C_SCL_HI; HALF_BIT_DLEAY;
	I2C_SCL_LO; HALF_BIT_DLEAY;
	//确认接受完成  发送NACK  无应答信号
}
/*****************************************************************************
* function: I2CSendByte   
* I2C字节发送
*****************************************************************************/
void I2CSendByte_Touch(unsigned char cSendByte)
{
	unsigned char  i = 8;
	while (i--)
	{
		I2C_SCL_LO;HALF_BIT_DLEAY; 
		if(cSendByte & 0x80)
		{I2C_SDA_HI;}
			
		else
		{
			I2C_SDA_LO;
		}
			
		HALF_BIT_DLEAY;
		cSendByte += cSendByte;
		HALF_BIT_DLEAY; 
		I2C_SCL_HI;HALF_BIT_DLEAY; 
	}
	I2C_SCL_LO;HALF_BIT_DLEAY; 
}
/*****************************************************************************
* function: I2CReceiveByte   
* I2C字节接收
*****************************************************************************/
unsigned char I2CReceiveByte_Touch(void)
{
	unsigned char i = 8;
	unsigned char cR_Byte = 0;
	SDA_Input_Mode_Touch(); 
	while (i--)
	{
		cR_Byte += cR_Byte;
		I2C_SCL_LO;HALF_BIT_DLEAY; 
		HALF_BIT_DLEAY; 
		I2C_SCL_HI;HALF_BIT_DLEAY; 
		cR_Byte |=  SDA_Input_Touch(); 
	}
	I2C_SCL_LO;HALF_BIT_DLEAY; 
	SDA_Output_Mode_Touch();
	return cR_Byte;
}
/*****************************************************************************
* function: i2c_init   
* I2C管脚初始化
*****************************************************************************/
void i2c_init_IO_Touch(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH,ENABLE); //使能B端口时钟
	
  GPIO_InitStructure.GPIO_Pin = SDATouch_Pin|SCLTouch_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_SetBits(I2CTouch_PORT,SDATouch_Pin);
	GPIO_SetBits(I2CTouch_PORT,SCLTouch_Pin);
  GPIO_Init(I2CTouch_PORT, &GPIO_InitStructure);
}

/////////////////////////////////////////////////////////
//以上是模拟I2C写的
/////////////////////////////////////////////////////////


// #define I2C_SPEED_HW                       100000
 #define TIMEOUT_MAX   100000
//  void IOE_I2C_Config(void)
//{
//  I2C_InitTypeDef I2C_InitStructure;

//  /* If the I2C peripheral is already enabled, don't reconfigure it */
//  if ((I2C2->CR1 & I2C_CR1_PE) == 0)
//  {   
//    /* IOE_I2C configuration */
//    I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
//    I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
//    I2C_InitStructure.I2C_OwnAddress1 = 0x00;
//    I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
//    I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
//    I2C_InitStructure.I2C_ClockSpeed = I2C_SPEED_HW;
//  
//    /* Initialize the I2C peripheral */
//    I2C_Init(I2C2, &I2C_InitStructure);
//  
//    /* Enable the I2C peripheral */
//    I2C_Cmd(I2C2, ENABLE);
//  }   
//}
///**
//  * @brief  Initializes the GPIO pins used by the IO expander.
//  * @param  None
//  * @retval None
//  */
 void I2cGpioInit(void)
{
//  GPIO_InitTypeDef GPIO_InitStructure;
//  
//  /* Enable IOE_I2C and IOE_I2C_GPIO_PORT & Alternate Function clocks */
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH | RCC_AHB1Periph_GPIOH |
//                         IOE_IT_GPIO_CLK, ENABLE);
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
//  
//  /* Reset IOE_I2C IP */
//  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, ENABLE);
//  /* Release reset signal of IOE_I2C IP */
//  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, DISABLE);

//  /* Connect PXx to I2C_SCL*/
//  GPIO_PinAFConfig(GPIOH, GPIO_PinSource4, GPIO_AF_I2C2);
//  /* Connect PXx to I2C_SDA*/
//  GPIO_PinAFConfig(GPIOH, GPIO_PinSource5, GPIO_AF_I2C2); 
//    
//  /* IOE_I2C SCL and SDA pins configuration */
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
//  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
//  GPIO_Init(GPIOH, &GPIO_InitStructure);

//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//  GPIO_Init(GPIOH, &GPIO_InitStructure);
i2c_init_IO_Touch();
 
}



////uint8_t IOE_Config(void)
////{
////  /* Configure the needed pins */
////  IOE_GPIO_Config(); 
////  
////  /* I2C initialization */
////  IOE_I2C_Config();
////    
////}
uint8_t i2cPutbyte(uint8_t b)
{
//	uint32_t IOE_TimeOut=0;
//	  /* Send the device's internal address to write to */
//  I2C_SendData(I2C2, b);  
//  
//  /* Test on TXE FLag (data dent) */
//  IOE_TimeOut = TIMEOUT_MAX;
//  while ((!I2C_GetFlagStatus(I2C2,I2C_FLAG_TXE)) && (!I2C_GetFlagStatus(I2C2,I2C_FLAG_BTF)))  
//  {
//    if (IOE_TimeOut-- == 0) return(0);
//  }
//return 1;
	I2CSendByte_Touch(b);
	if(I2CWaitAck_Touch()==0)
		{return 0;}
		return 1;

}
uint8_t i2cGetbyte(uint8_t last)
{
//		uint32_t IOE_TimeOut=0;
	uint8_t tmp=0;
//	  /* Test on EV7 and clear it */
//  IOE_TimeOut = TIMEOUT_MAX;
//  while (!I2C_GetFlagStatus(I2C2, I2C_FLAG_RXNE))
//  {
//    if (IOE_TimeOut-- == 0) return(0);
//  }
//  
//  /* End the configuration sequence */
// // I2C_GenerateSTOP(IOE_I2C, ENABLE);
//  
//  /* Load the register value */
//  tmp = I2C_ReceiveData(I2C2);
//  
//  /* Enable Acknowledgement */
//	if(last)
//	{
//  I2C_AcknowledgeConfig(I2C2, ENABLE);
//	}
//return tmp;
tmp=I2CReceiveByte_Touch();
if(last)
{
I2CSendNotAck_Touch();
}
else
{
I2CSendAck_Touch();
}
return tmp;

}

///*************************************************************************
//** Function Name  : 
//** Description    :   
//** Input       		: 
//** Output     		: 
//*************************************************************************/
uint8_t i2cWriteStart(void)
{
uint32_t IOE_TimeOut=0;
int i=0;
		IIC_SEND_START;																			// do start transition
		if(i2cPutbyte((0x50<<1)|0x00)) 						// send DEVICE address
		  return 1;

else
	 return 0;

}

///*************************************************************************
//** Function Name  : 
//** Description    :   
//** Input       		: 
//** Output     		: 
//*************************************************************************/
uint8_t i2cReadStart(void)
{
IIC_SEND_START;																			// do start transition
		if(i2cPutbyte((0x50<<1)|0x01)) 						// send DEVICE address
		  return 1;

else
	 return 0;

}


///*************************************************************************
//** Function Name  : 
//** Description    :   
//** Input       		: 
//** Output     		: 
//*************************************************************************/
void i2cstart(void)
{
//	 I2C_GenerateSTART(I2C2, ENABLE);
	I2CStart_Touch();
}
///*************************************************************************
//** Function Name  : 
//** Description    :   
//** Input       		: 
//** Output     		: 
//*************************************************************************/
void i2cstop(void)
{
I2CStop_Touch();

}
