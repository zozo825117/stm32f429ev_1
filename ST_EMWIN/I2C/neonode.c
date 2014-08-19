//---------------------------------------------------------------------------//
//
//! @file 		neonode.c
//! @brief    neonode specific functions for I2C Firmware library
//
//! @author 	zozo 
//! @version 	v00.02
//! @note
//!     
//! 
//! 修改日志  :
//! 2013.7.31    创建初试 zozo
//! 2014.7.4    增加测试函数zozo
//
//
//---------------------------------------------------------------------------//



//****************************************************************************
// 头文件
//****************************************************************************/

#include "neonode.h"
#include "main.h"
#include "string.h"
#include "IIC_config.h"
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
  
//****************************************************************************
// 变量定义
//****************************************************************************/
commands_t NeonodeCmdLine[]={
	{ DEACTIVATE_SIZE 						     ,DEACTIVATE_ID  						       },   //  0 
	{ INITIALIZE_SIZE                  ,INITIALIZE_ID                    },   //  1 
	{ SETRESOLUTION_SIZE               ,SETRESOLUTION_ID                 },   //  2 
	{ SETCONFIGURATION_SIZE            ,SETCONFIGURATION_ID              },   //  3 
	{ STARTTOUCHDETECTION_SIZE         ,STARTTOUCHDETECTION_ID           },   //  4 
	{ SETSCANNINGFREQUENCY_SIZE        ,SETSCANNINGFREQUENCY_ID          },   //  5 
	{ SETTOUCHSIZELIMITS_SIZE          ,SETTOUCHSIZELIMITS_ID            },   //  6 
	{ SETACTIVELEDS_SIZE               ,SETACTIVELEDS_ID                 },   //  7 
	{ STARTPROXIMITYDETECTION_SIZE     ,STARTPROXIMITYDETECTION_ID       },   //  8 
	{ STOPPROXIMITYDETECTION_SIZE      ,STOPPROXIMITYDETECTION_ID        },   //  9 
	{ SETPROXIMITYSIZELIMITS_SIZE      ,SETPROXIMITYSIZELIMITS_ID        },   //  10
	{ LOWSIGNALSREQUEST_SIZE 			     ,LOWSIGNALSREQUEST_ID 			       },   //  11
	{ FIXEDSIGNALSTRENGTH_SIZE  	     ,FIXEDSIGNALSTRENGTH_ID 		       },   //  12
	{ LEDLEVELSREQUEST_SIZE 			     ,LEDLEVELSREQUEST_ID				       },   //  13
	{ FORCEDLEDLEVELSREQUEST_SIZE      ,FORCEDLEDLEVELSREQUEST_ID        },   //  14
	{ STATUSREQUEST_SIZE  				     ,STATUSREQUEST_ID 					       },   //  15
	{ OPENSHORTREQUEST_SIZE  			     ,OPENSHORTREQUEST_ID 			       },   //  16
	{ PRODUCTIDREQUEST_SIZE  			     ,PRODUCTIDREQUEST_ID 			       },   //  17
	{ DEACTIVATERESPONSE_SIZE  				 ,DEACTIVATERESPONSE_ID 					 },   //  18
	{ INITIALIZERESPONSE_SIZE  				 ,INITIALIZERESPONSE_ID 					 },   //  19
	{ SETRESOLUTIONRESPONSE_SIZE  		 ,SETRESOLUTIONRESPONSE_ID				 },   //  20
	{ SETCONFIGURATIONRESPONSE_SIZE  	 ,SETCONFIGURATIONRESPONSE_ID 		 },   //  21
	{ SETSCANNINGFREQUENCYRESPONSE_SIZE,SETSCANNINGFREQUENCYRESPONSE_ID  },   //  22
	{ SETTOUCHSIZELIMITSRESPONSE_SIZE  ,SETTOUCHSIZELIMITSRESPONSE_ID		 },   //  23
	{ LOWSIGNALSRESPONSE_SIZE  				 ,LOWSIGNALSRESPONSE_ID 					 },   //  24
	{ FIXEDSIGNALSTRENGTHRESPONSE_SIZE ,FIXEDSIGNALSTRENGTHRESPONSE_ID 	 },   //  25
	{ LEDLEVELSRESPONSE_SIZE  				 ,LEDLEVELSRESPONSE_ID 						 },   //  26
	{ SETACTIVELEDSRESPONSE_SIZE  		 ,SETACTIVELEDSRESPONSE_ID 		     },   //  27
	{ STATUSRESPONSE_SIZE  						 ,STATUSRESPONSE_ID   						 },		//  28  
	{ OPENSHORTRESPONSE_SIZE					 ,OPENSHORTRESPONSE_ID  					 },		//  29
	{ PRODUCTIDRESPONSE_SIZE    			 ,PRODUCTIDRESPONSE_ID    			   },		//  30
	{ STOPPROXIMITYDETECTIONRESPONSE_SIZE,STOPPROXIMITYDETECTIONRESPONSE_ID}, //  31
	{ SETPROXIMITYSIZELIMITSRESPONSE_SIZE,SETPROXIMITYSIZELIMITSRESPONSE_ID}, //  32
	{ INVALIDCOMMANDRESPONSE_SIZE  			 ,INVALIDCOMMANDRESPONSE_ID  			 }, //  33
	{ TOUCHNOTIFICATION_SIZE        	 ,TOUCHNOTIFICATION_ID 				     },   //  34
	{ BOOTCOMPLETENOTIFICATION_SIZE	   ,BOOTCOMPLETENOTIFICATION_ID      },   //  35
	{ OVERRUNNOTIFICATION_SIZE 			   ,OVERRUNNOTIFICATION_ID 			     },   //  36
	{ PROXIMITYNOTIFICATION_SIZE  	   ,PROXIMITYNOTIFICATION_ID 		     }    //  37
};                                                                            

touch_notification_message_t t_CTNs;

void Comms_IO_Config(void)
{
		 GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH
                         , ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOH, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_Init(GPIOH, &GPIO_InitStructure);

}
void delay_us (uint32_t cycles){ 
  while(cycles>15)                          // 15 cycles consumed by overhead
    cycles = cycles - 4;                    // 6 cycles consumed each iteration
}
/*
	Function name:	CommsNeonodeInit
	Parameters:			none
	Return:					none
	Description:		communication io inital  
*/
//reset PH6  INT PH7
void CommsNeonodeInit(void)
{
  IIC_COMM_INIT;
	
  Comms_IO_Config();
	//IO_DisableFunc(IIC_IO_PORT,IIC_RDY_IO_PIN);
//	IO_ConfigGPIOPin(IIC_IO_PORT,IIC_RDY_IO_PIN,
//									 IO_DIR_INPUT,IO_PULLUP_ON);


	
//  /**/
	//IO_DisableFunc(IIC_RST_PORT,IIC_RST_IO_PIN);
//	IO_ConfigGPIOPin(IIC_RST_PORT,IIC_RST_IO_PIN,
//									 IO_DIR_OUTPUT,IO_PULLUP_ON);

	//IO_WriteGPIOPin(IIC_RST_PORT,IIC_RST_IO_PIN,IO_BIT_CLR);
		GPIO_ResetBits(GPIOH,GPIO_Pin_6);
	delay_us(8000);
	delay_us(8000);
	delay_us(8000);
	delay_us(8000);
	GPIO_SetBits(GPIOH,GPIO_Pin_6);
	//IO_WriteGPIOPin(IIC_RST_PORT,IIC_RST_IO_PIN,IO_BIT_SET);

}
/*
	Function name:	CommsNeonodeCmdRead
	Parameters:			uint8_t *data
	Return:					TRUE or FALSE 
	Description:	
*/
uint8_t CommsNeonodeCmdRead(uint8_t *data)
{
	uint8_t size;
  uint16_t cnt = 10*2000; //wait limit : 1s
	 
	while( GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_7) && cnt)
		{
			cnt--;
		delay_us(1000 );
		};// wait data ready Low
	if(cnt==0)
		{
			goto read_error;
		}
	//delay_us(8000 );
	/* 发送读地址*/
	if(IIC_START_READ==0)
		{
      __nop();
			goto read_error;
		}
	delay_us(300 );
	/* read FrameStart */
	*data++ = IIC_GET_BYTE(0);
	delay_us(300 );
	*data++ = size = IIC_GET_BYTE(1);
	
	if(size >= 0xff)
		{
		*data++ = IIC_GET_BYTE(1);
		  goto read_too_long;
		}
	  IIC_SEND_STOP;
	delay_us(800);

	/* 发送读地址*/
	if(IIC_START_READ==0)
		{
      goto read_error;
		}
	while (size>1)
		{
			*data++ = IIC_GET_BYTE(0);//读 ack
			delay_us(200 );
			size--;
		}
	*data = IIC_GET_BYTE(1);//读 nack
  IIC_SEND_STOP;											// 发送停止位
  return 1;
	
read_error:
read_too_long:		
	IIC_SEND_STOP;

	return 0;


}
/*
	Function name:	CommsNeonodeCmdReadForce
	Parameters:			uint8_t *data
	Return:					TRUE or FALSE 
	Description:	
*/
uint8_t CommsNeonodeCmdReadForce(uint8_t *data)
{
	uint8_t size;
	
	/* 发送读地址*/
	if(IIC_START_READ==0)
		{
      __nop();
			goto read_error;
		}
	delay_us(300 );
	/* read FrameStart */
	*data++ = IIC_GET_BYTE(0);
	delay_us(300 );
	*data++ = size = IIC_GET_BYTE(1);
	
	if(size >= 0xff)
		{
		*data++ = IIC_GET_BYTE(1);
		  goto read_too_long;
		}
	IIC_SEND_STOP;
	delay_us(100);

	/* 发送读地址*/
	if(IIC_START_READ==0)
		{
      goto read_error;
		}
	while (size>1)
		{
			*data++ = IIC_GET_BYTE(0);//读 ack
			delay_us(200 );
			size--;
		}
	*data = IIC_GET_BYTE(1);//读 nack
  IIC_SEND_STOP;											// 发送停止位
  return 1;
	
read_error:
read_too_long:		
	IIC_SEND_STOP;

	return 0;


}

/*
	Function name:	CommsNeonodeCmdWrite
	Parameters:			uint8_t cmd_size,Uint8 *data
	Return:					TRUE or FALSE 
	Description:	
*/
uint8_t CommsNeonodeCmdWrite(uint8_t cmd_size,uint8_t *data)
{

	/* 确定总线空闲
	if(IIC_NO_BUSY == FALSE)							 
		{
			continue;
		}
		*/
	
	/* 发送写地址 */
	if(IIC_START_WRT==0)
		{
			goto write_error;
		}
	delay_us(500 );
	/* 发送 FrameStart*/
	if(IIC_PUT_BYTE(FRAMESTART)==0)
		{
		 	goto write_error;
		}
	delay_us(500);
	/* 发送数据长度 */
	if(IIC_PUT_BYTE(cmd_size)==0)
		{
		 goto write_error;
		}					
	delay_us(500);
	while (cmd_size--)
		{
			if(IIC_PUT_BYTE(*data++)==0)
				{
				 goto write_error;
				}
			delay_us(500 );
		}
	IIC_SEND_STOP;											// 发送停止位
	return 1;
		
		
write_error:
	IIC_SEND_STOP;											// 发送停止位
	return 0;	
}

/*
	Function name:	NeonodeSetting
	Parameters: 		None
	Return: 				None
	Description:	
*/
uint8_t NeonodeSetting(void)
{
	uint8_t buf[20];
	uint16_t k=20;   // loop limit 
	/* wait for boot */
	do
		{
			if(! CommsNeonodeCmdRead(buf))
			{
				/* Initialize */
				buf[2] = 0; // clear cmd
						GPIO_ResetBits(GPIOH,GPIO_Pin_6);
	           delay_us(8000);
	         GPIO_SetBits(GPIOH,GPIO_Pin_6);
				delay_us(600);
				k--;
			}
		}
	while(((buf[2] != BOOTCOMPLETENOTIFICATION_ID)||((buf[3]&0x01)!=0))&&k);//ready to receive data

	if((k) == 0)
		{
			return 0;
		}
	
	/* setting */
	/* Deactivate */
	do
		{
			buf[0] = NeonodeCmdLine[0].ID;
			buf[2] = 0;
			CommsNeonodeCmdWrite(NeonodeCmdLine[0].Size,buf);		
		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != DEACTIVATERESPONSE_ID);

	/*step 2 Initialize */
	do
		{
			buf[0] = NeonodeCmdLine[1].ID;
			buf[2] = 0;
			CommsNeonodeCmdWrite(NeonodeCmdLine[1].Size,buf);		
		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != INITIALIZERESPONSE_ID);

	/*step 3 SetResolution */
	do
		{
			buf[0] = NeonodeCmdLine[2].ID;
			/*  1024*600*/
//			buf[1] = 0x00;
//			buf[2] = 0x04;
//			buf[3] = 0x58;
//			buf[4] = 0x02;			
//			  800*480
			buf[1] = 0x20;
			buf[2] = 0x03;
			buf[3] = 0xE0;
			buf[4] = 0x01;
			CommsNeonodeCmdWrite(NeonodeCmdLine[2].Size,buf);
		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != SETRESOLUTIONRESPONSE_ID);

	/*step 4 SetConfiguration */
	do
		{
			buf[0] = NeonodeCmdLine[3].ID;
			buf[1] = 0x01; // Dual touch	 // 0 = off, 1 = on 
			buf[2] = 0x00;
			buf[3] = 0x00;
			buf[4] = 0x00;
			CommsNeonodeCmdWrite(NeonodeCmdLine[3].Size,buf);

		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != SETCONFIGURATIONRESPONSE_ID);

	/*step 9 SetTouchSizeLimits */
	do
		{
			buf[0] = NeonodeCmdLine[6].ID;
			buf[1] = 0x01; // 
			buf[2] = 0xFF;
			buf[3] = 0x01;
			buf[4] = 0x00;
			CommsNeonodeCmdWrite(NeonodeCmdLine[6].Size,buf);
		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != SETTOUCHSIZELIMITSRESPONSE_ID);

	/*step 10 SetScanningFrequency */
	do
		{
			buf[0] = NeonodeCmdLine[5].ID;
			buf[1] = 40; // Idle Frequency	 // Low Byte 
			buf[2] = 0x00; // Idle Frequency	 // High Byte 
			buf[3] = 40; // Finger Frequency	 // Low Byte 
			buf[4] = 0x00; // Finger Frequency	 // High Byte 
			buf[5] = 40; // Stylus Frequency	 // Low Byte 
			buf[6] = 0x00; // Stylus Frequency	 // High Byte 
			//buf[7] = 0xFA; // Proximity Frequency 	// Low Byte 
			//buf[8] = 0x00; // Proximity Frequency 	// High Byte	
			CommsNeonodeCmdWrite(NeonodeCmdLine[5].Size-2,buf);
		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != SETSCANNINGFREQUENCYRESPONSE_ID);
  // delay_us(8000);
	/*step 11 	write 0x1A read return 0x1A=0 delay is 40.7ms */
	
			
			
#if 0	
			buf[0] = 0x1A;
			CommsNeonodeCmdWrite(1,buf);
			 	delay_us(0xfffffff);
	while(CommsNeonodeCmdRead(buf)==0)
	{
	
	delay_us(8000);
	}
#endif

	/*step 12 StartTouchDetection */
	buf[0] = NeonodeCmdLine[4].ID;
	CommsNeonodeCmdWrite(NeonodeCmdLine[4].Size,buf);
  
	return 1;
	
}

/*
	Function name:	NeonodeNewConvertion
	Parameters:			None
	Return:					updata: 0 none 1 updata 
	Description:	
*/
extern void MotionEvent(void);
uint8_t NeonodeNewConvertion(void)
{
	uint8_t buf[30],len,rc = 0;
	if(!(IIC_RDY_IN))
		{
			if(CommsNeonodeCmdRead(buf))
				{
					/* touch_notification */
					if(buf[2]==NeonodeCmdLine[34].ID)
						{
						  len = buf[1]-1;
						  memcpy((uint8_t *)&t_CTNs.Count,&buf[3],len);
							MotionEvent();
							rc = 1;
						}
				}
		}

	return rc;
}

/*
	Function name:	NeonodeOpenShortTest
	Parameters: 		pd
								0 - pd1 , 1 - pd2 ......
	Parameters: 		led
								0 - led1 , 1 - led2 ......
	Parameters: 		num_pds
	Parameters: 		num_leds

	Return: 				
	Description:	
*/
void	NeonodeOpenShortTest(open_short_t *pd,open_short_t *led,uint8_t *num_pds,uint8_t *num_leds)
{
	static uint8_t buf[30],buf_ptr,stat,j,ptr,cnt=0;
	/*Requesting Open/Short result Axis X*/
	// check ready
	while(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_7) == 0)
		{
			CommsNeonodeCmdReadForce(buf);
		}
	do
		{
			buf[0] = NeonodeCmdLine[16].ID;
			buf[1] = 0x00; // Axis X=0 			
			buf[2] = 0x00; // clear cmd
			CommsNeonodeCmdWrite(NeonodeCmdLine[16].Size,buf);

		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != OPENSHORTRESPONSE_ID);


	buf_ptr=5;
	do{
		  stat = buf[buf_ptr++];
			for(j=0;j<8;j++)
				{
				  if(cnt == 0)
				  	{
				  		ptr=0;
							/*open pd*/
							pd[ptr++].f_open = stat&0x01;
				  	}
					else if(cnt>0 && cnt < NUMBEROFAXISPDS_X)
						{
							/*open pd*/
							pd[ptr++].f_open = stat&0x01;
						}
					else if(cnt == NUMBEROFAXISPDS_X)
						{
							/*short pd*/
							ptr=0;
							pd[ptr++].f_short = stat&0x01;
						}
					else if(cnt > NUMBEROFAXISPDS_X && cnt < 2*NUMBEROFAXISPDS_X)
						{
							/*short pd*/
							pd[ptr++].f_short = stat&0x01;
						}
					else if(cnt == 2*NUMBEROFAXISPDS_X)
						{
							/*short led*/
							ptr=0;
							led[ptr++].f_short = stat&0x01;
						}
					else if(cnt > 2*NUMBEROFAXISPDS_X && cnt < 2*NUMBEROFAXISPDS_X + NUMBEROFAXISLEDS_X)
						{
							/*short pd*/
							led[ptr++].f_short = stat&0x01;
						}
					else if(cnt == 2*NUMBEROFAXISPDS_X + NUMBEROFAXISLEDS_X)
						{
							/*open led*/
							ptr=0;
							led[ptr++].f_open = stat&0x01;
						}
					else if(cnt > 2*NUMBEROFAXISPDS_X + NUMBEROFAXISLEDS_X && cnt < 2*NUMBEROFAXISPDS_X + 2*NUMBEROFAXISLEDS_X)
						{
							/*open led*/
							led[ptr++].f_open = stat&0x01;
						}
					else
						{
							/**/
						}

					cnt++;
					stat>>=1;
				}
		}while(cnt < 2*NUMBEROFAXISPDS_X + 2*NUMBEROFAXISLEDS_X);

	// check ready
	while(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_7) == 0)
		{
			CommsNeonodeCmdReadForce(buf);
		}

	/*Requesting Open/Short result Axis Y*/
	do
		{
			buf[0] = NeonodeCmdLine[16].ID;
			buf[1] = 0x01; // Axis Y=1
			buf[2] = 0x00; // clear cmd
			CommsNeonodeCmdWrite(NeonodeCmdLine[16].Size,buf);

		}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != OPENSHORTRESPONSE_ID);

  cnt=0;
	buf_ptr=5;
	do{
		  stat = buf[buf_ptr++];
			for(j=0;j<8;j++)
				{
				  if(cnt == 0)
				  	{
				  		ptr=0;
							/*open pd*/
							pd[ptr++].f_open = stat&0x01;
				  	}
					else if(cnt>0 && cnt < NUMBEROFAXISPDS_Y)
						{
							/*open pd*/
							pd[ptr++].f_open = stat&0x01;
						}
					else if(cnt == NUMBEROFAXISPDS_Y)
						{
							/*short pd*/
							ptr=0;
							pd[ptr++].f_short = stat&0x01;
						}
					else if(cnt > NUMBEROFAXISPDS_Y && cnt < 2*NUMBEROFAXISPDS_Y)
						{
							/*short pd*/
							pd[ptr++].f_short = stat&0x01;
						}
					else if(cnt == 2*NUMBEROFAXISPDS_Y)
						{
							/*short led*/
							ptr=0;
							led[ptr++].f_short = stat&0x01;
						}
					else if(cnt > 2*NUMBEROFAXISPDS_Y && cnt < 2*NUMBEROFAXISPDS_Y + NUMBEROFAXISLEDS_Y)
						{
							/*short pd*/
							led[ptr++].f_short = stat&0x01;
						}
					else if(cnt == 2*NUMBEROFAXISPDS_Y + NUMBEROFAXISLEDS_Y)
						{
							/*open led*/
							ptr=0;
							led[ptr++].f_open = stat&0x01;
						}
					else if(cnt > 2*NUMBEROFAXISPDS_Y + NUMBEROFAXISLEDS_Y && cnt < 2*NUMBEROFAXISPDS_Y + 2*NUMBEROFAXISLEDS_Y)
						{
							/*open led*/
							led[ptr++].f_open = stat&0x01;
						}
					else
						{
							/**/
						}

					cnt++;
					stat>>=1;
				}
			}while(cnt < 2*NUMBEROFAXISPDS_Y + 2*NUMBEROFAXISLEDS_Y);



	
  /* number*/
	*num_pds = NUMBEROFAXISPDS_X+NUMBEROFAXISPDS_Y;
	*num_leds = NUMBEROFAXISLEDS_X+NUMBEROFAXISLEDS_Y;
  
}
//#define ret
/*
	Function name:	NeonodeOpenShortTest
	Parameters: 		*level_buf
								0 - led1 , 1 - led2 ......
	Parameters: 		*num	number of leds				
	Return: 				
	Description:	
*/
void	NeonodeLEDLevelsTest(led_level_t *level_buf,uint8_t *num)
{
	uint8_t buf[70],i,j,num_leds,cnt;

	// check ready
	while(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_7) == 0)
		{
			CommsNeonodeCmdReadForce(buf);
			
		}
		cnt=0;
		do{

#ifdef ret
			if(cnt>5)
			{
				//	 /* neonode init*/
					CommsNeonodeInit(); 
					//GUI_Delay(10);//wait fot zForec DR high
					delay_us(1000);
					NeonodeSetting();	
					cnt=0;

			}
			cnt++;
#endif
			/*Requesting LED levels   Axis X*/	
			buf[0] = NeonodeCmdLine[14].ID;
			buf[1] = 0x00; // Axis X=0
			buf[2] = 0x00; // clear cmd
			CommsNeonodeCmdWrite(NeonodeCmdLine[14].Size,buf);	
		}	
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != LEDLEVELSRESPONSE_ID);

	/* axis-x number of led levels is determined*/

	num_leds = buf[4]/2;
	for(i=j=0;i<num_leds;i++)
		{
			level_buf[i].led_level_0 = (buf[5+j]>>4)&0x0f;
			level_buf[i].led_level_1 = buf[5+j]&0x0f;
			j+=3;
		}
	*num = num_leds;
	
	// check ready
	while(GPIO_ReadInputDataBit(GPIOH,GPIO_Pin_7) == 0)
		{
			CommsNeonodeCmdReadForce(buf);
			
		}
	cnt=0;
	/*Requesting LED levels  Axis Y*/
	do
	{
#ifdef ret
			if(cnt>5)
			{
				//	 /* neonode init*/
					CommsNeonodeInit(); 
					//GUI_Delay(10);//wait fot zForec DR high
					delay_us(1000);
					NeonodeSetting();	
					cnt=0;

			}
			cnt++;
#endif
			buf[0] = NeonodeCmdLine[14].ID;
			buf[1] = 0x01; // Axis Y=1
			buf[2] = 0x00; // clear cmd
			CommsNeonodeCmdWrite(NeonodeCmdLine[14].Size,buf);			
		  
	}
	while(CommsNeonodeCmdRead(buf) == 0 || buf[2] != LEDLEVELSRESPONSE_ID);

	/* axis-y number of led levels is determined*/
	num_leds = buf[4]/2;
	for(i=j=0;i<num_leds;i++)
		{
			level_buf[i+*num].led_level_0 = (buf[5+j]>>4)&0x0f;
			level_buf[i+*num].led_level_1 = buf[5+j]&0x0f;
			j+=3;
		}
	*num += num_leds;
			
}


