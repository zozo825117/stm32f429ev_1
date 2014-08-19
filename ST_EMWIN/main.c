/**
  ******************************************************************************
  * @file    SysTick_Example/main.c
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-November-2013
  * @brief   This example shows how to configure the SysTick to generate a time 
  *          base equal to 1 ms. the SysTick is clocked by the AHB clock(HCLK).
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "GUI.h"
#include "sdram_config.h"
#include "WM.h"
#include "Dialog.h"
#include "neonode.h"

#include "motion.h"
#include "erase.c"
#include "clear.c"
extern void delay1_Touch(unsigned int n);
#define abs(a,b)  ((a>b)?(a-b):(b-a))
unsigned char stepkey=1;

//LED强度测试
volatile uint8_t count_ledpad=0,led_testflag=0; 
unsigned char string_LEDLevel[]={'L','E','D',' ',' ','L','e','v','0',':',' ',' ',' ','\0'};



led_level_t  LedLevelTest[NUMBEROFAXISLEDS_X+NUMBEROFAXISLEDS_Y+10];

extern  void	NeonodeLEDLevelsTest(led_level_t *level_buf,uint8_t *num);
/* Private functions ---------------------------------------------------------*/

long secondPointX=0,secondPointY=0;

touch_notification_t TouchNotesBuf[5];

typedef struct {
  unsigned char           down;
	unsigned char           up;
	unsigned char           move;
	unsigned char secondpoint;
	GUI_COLOR   color;
	GUI_COLOR colorsecond;
	uint8_t erase;

} FLAG;


FLAG flag;
 uint8_t step;
  GUI_PID_STATE   State = {0};
volatile short g_sTouchX1;
volatile short g_sTouchY1;
uint8_t GUI_Initialized   = 0;
uint32_t Tmr1Cnt=0;
#define  ID_BUTTON  (GUI_ID_USER+0)
uint8_t res=0;  //初始化返回值变量
uint8_t buf[30];
	
	
uint8_t NumLeds=0;

static unsigned char hasstep2=0;
typedef struct {
  int          xPos;
  int          yPos;
  int          xSize;
  int          ySize;
  const char * acLabel;
	GUI_COLOR color;
  void (* pfDraw)(WM_HWIN hWin);
} BUTTON_DATA;
/*********************************************************************
*
*       Static data using function pointers
*
**********************************************************************
*/
//static const BUTTON_DATA _aButtonData[] = {
//  {   0,   555,  45, 44, "RED",GUI_RED },
//  {  46,   555,  45, 44, "BLUE",GUI_BLUE},
//  {  102,   555,  45, 44, "YELLOW" ,GUI_YELLOW},
//  {  153,   555,  45, 44, "GRAY",GUI_GRAY },
//  {  46*4,   555,  45, 44, "CYAN",GUI_CYAN },
//  {  46*5,   555,  45, 44, "BROWN",GUI_BROWN},
//  {  46*6,   555,  45, 44, "ORANGE" ,GUI_ORANGE},

//};

static const BUTTON_DATA _aButtonData[] = {
  {   0,   435,  45, 44, "RED",GUI_RED },
  {  46,   435,  45, 44, "BLUE",GUI_BLUE},
  {  46*2,   435,  45, 44, "YELLOW" ,GUI_YELLOW},
  {  46*3,  435,  45, 44, "GRAY",GUI_GRAY },
  {  46*4,  435,  45, 44, "CYAN",GUI_CYAN },
  {  46*5,   435,  45, 44, "BROWN",GUI_BROWN},
  {  46*6,   435,  45, 44, "ORANGE" ,GUI_ORANGE},
	
	
	{   800-46,   435,  45, 44, "RED",GUI_RED },
  { 800-46*2,   435,  45, 44, "BLUE",GUI_BLUE},
  {  800-46*3,   435,  45, 44, "YELLOW" ,GUI_YELLOW},
  {  800-46*4,  435,  45, 44, "GRAY",GUI_GRAY },
  { 800- 46*5,   435,  45, 44, "CYAN",GUI_CYAN },
  { 800- 46*6,   435,  45, 44, "BROWN",GUI_BROWN},
  { 800- 46*7,   435,  45, 44, "ORANGE" ,GUI_ORANGE},
	
	
	
//	 { 1023- 46*6,   555,  45, 44, "Clear",GUI_BROWN},
//  { 1023- 46*7,   555,  45, 44, "ORANGE" ,GUI_ORANGE},

};


//回调函数
void __cbDeskCallback(WM_MESSAGE *_pMsg)
{
		
	 int      NCode,i;
   unsigned Id;
switch (_pMsg->MsgId)
{
	case WM_PAINT:
		GUI_SetBkColor(GUI_WHITE);
	
	  GUI_Clear();
	 for (i = 0; i < GUI_COUNTOF(_aButtonData); i++) 
	{
		GUI_SetColor(_aButtonData[i].color);
		GUI_FillRect(_aButtonData[i].xPos,_aButtonData[i].yPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos+_aButtonData[i].ySize);
		
	 }
	
	 GUI_DrawBitmap(&bmerase,46*8,435);
	 GUI_DrawBitmap(&bmclear,46*9,435);
	 // GUI_SetColor(GUI_WHITE);
	
	
//	  GUI_SetPenSize(60);
//    GUI_DrawHLine(550,0,1023);
	//  GUI_CURSOR_Show();
		break;
	 case WM_NOTIFY_PARENT:
    Id    = WM_GetId(_pMsg->hWinSrc);      /* Id of widget */
    NCode = _pMsg->Data.v;                 /* Notification code */
			switch (NCode) {
			//case WM_NOTIFICATION_CLICKED:
			case WM_NOTIFICATION_RELEASED:
				break;
			default:break;
			}
	  default:
    WM_DefaultProc(_pMsg);
		break;
}

}
void Key_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  //配置DITHB
  GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5 ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

uint8_t GetKeyVal(void)
{

if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5))
  {

   return 1;
  }
	else
	{
		delay1_Touch(12000);
		delay1_Touch(12000);
	while(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5));
	return 0;
	}
}
void calkey(void)
{
  if(!GetKeyVal())
  {
   stepkey++;
		if(stepkey==3)
		{
		stepkey=1;
		}
  }
}

unsigned int last_x1,last_y1,last_x2,last_y2;
uint8_t PoinCal(uint16_t x,uint16_t y,uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2);
int main(void)
{
	int i;
	
	BUTTON_Handle hButton;

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
 Key_Init();
	SDRAM_Init();
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);  
	 
//	 /* neonode init*/
	CommsNeonodeInit(); 
	//GUI_Delay(10);//wait fot zForec DR high
	for(i=0;i<0xffffff;i++);
	res=NeonodeSetting();	
	MotionEventInit();
  GUI_Init();	

	
	 SysTick_Config(SystemCoreClock / 1000);
	if(res==0x01)     //初始化成功
	{
		 GUI_Initialized = 1;
	   WM_SetCallback(WM_HBKWIN,__cbDeskCallback);
		 GUI_SetColor(GUI_BLACK);//设置默认颜色
		flag.color=GUI_BLACK;
		flag.colorsecond=GUI_BLACK;
     GUI_SetPenSize(10);
	}
 else
 {
 
 
 }

	
	while(1)
	{
	calkey();
			if(stepkey==2)
		{
			if(!hasstep2)
			{
			GUI_SetBkColor(GUI_BLACK);
			GUI_Clear();
			GUI_SetFont(GUI_FONT_8X16_ASCII);
			}
			
	    NeonodeLEDLevelsTest(LedLevelTest,&NumLeds);
				for(i=0;i<0xfffff;i++);
					for(count_ledpad=0;count_ledpad<26;count_ledpad++)           //26个LED  
						{
							if(count_ledpad<=9)                                          //int转换为字符 led标号处理
									{
										string_LEDLevel[3]=0+'0';
										string_LEDLevel[4]=count_ledpad+'0';
									}
							else
									{
										string_LEDLevel[3]=count_ledpad/10+'0';
										string_LEDLevel[4]=count_ledpad%10+'0';
									}
							if(LedLevelTest[count_ledpad].led_level_0==0)   //led_level_0信号太强
							{
//							 led_testflag=0x01;
								string_LEDLevel[8]=0+'0';
								string_LEDLevel[11]=0+'0';
								string_LEDLevel[12]=0+'0';
								GUI_SetColor(GUI_RED);
//							 GrContextForegroundSet(&sContext, ClrRed) ;
//							 GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//								 13,10+130*(count_ledpad/5),215+54*(count_ledpad%5), 0); 
								GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),215+54*(count_ledpad%5));
							}
							else if(LedLevelTest[count_ledpad].led_level_0>=1&&LedLevelTest[count_ledpad].led_level_0<=12) //led_level_0 pass
							{
//							GrContextForegroundSet(&sContext, ClrGreen) ;
							string_LEDLevel[8]=0+'0';
							string_LEDLevel[11]=LedLevelTest[count_ledpad].led_level_0/10+'0';
							string_LEDLevel[12]=LedLevelTest[count_ledpad].led_level_0%10+'0';
									GUI_SetColor(GUI_GREEN);
//							GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//							 13,10+130*(count_ledpad/5),215+54*(count_ledpad%5), 0);
								GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),215+54*(count_ledpad%5));
							}
							else                                          //led_level_0 信号太弱
							{
//							GrContextForegroundSet(&sContext, ClrYellow) ;
							string_LEDLevel[8]=0+'0';
							string_LEDLevel[11]=LedLevelTest[count_ledpad].led_level_0/10+'0';
							string_LEDLevel[12]=LedLevelTest[count_ledpad].led_level_0%10+'0';
									GUI_SetColor(GUI_YELLOW);
//							led_testflag=0x01;
//							GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//							13,10+130*(count_ledpad/5),215+54*(count_ledpad%5), 0);
									GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),215+54*(count_ledpad%5));
							}
							if(LedLevelTest[count_ledpad].led_level_1==0)  // led_level_1信号太强
							{
								string_LEDLevel[8]=0+'0';
								string_LEDLevel[11]=0+'0';
								string_LEDLevel[12]=0+'0';
									GUI_SetColor(GUI_RED);
								GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),235+54*(count_ledpad%5));
//							 led_testflag=0x01;
//							 GrContextForegroundSet(&sContext, ClrRed) ;
//								GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//							 13,10+130*(count_ledpad/5),235+54*(count_ledpad%5), 0);
							}
							else if(LedLevelTest[count_ledpad].led_level_1>=1&&LedLevelTest[count_ledpad].led_level_1<=12) //led_level_1 pass
							{
//							GrContextForegroundSet(&sContext, ClrGreen) ;
							string_LEDLevel[8]=1+'0';
							string_LEDLevel[11]=LedLevelTest[count_ledpad].led_level_1/10+'0';
							string_LEDLevel[12]=LedLevelTest[count_ledpad].led_level_1%10+'0';
									GUI_SetColor(GUI_GREEN);
									GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),235+54*(count_ledpad%5));
//							GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//							 13,10+130*(count_ledpad/5),235+54*(count_ledpad%5), 0);
							}
							else                                          //led_level_1 信号太弱
							{
							string_LEDLevel[8]=1+'0';
							string_LEDLevel[11]=LedLevelTest[count_ledpad].led_level_1/10+'0';
							string_LEDLevel[12]=LedLevelTest[count_ledpad].led_level_1%10+'0';
								GUI_SetColor(GUI_YELLOW);
								GUI_DispStringAt((const char GUI_UNI_PTR *)string_LEDLevel,10+130*(count_ledpad/5),235+54*(count_ledpad%5));
//							led_testflag=0x01;
//							GrContextForegroundSet(&sContext, ClrYellow) ;
//							GrStringDraw(&sContext, (const char*)string_LEDLevel, 
//							 13,10+130*(count_ledpad/5),235+54*(count_ledpad%5), 0);
							}
						}
			
			
			hasstep2=1;
		}
		//GUI_DispDecAt(TouchNotesBuf[0].Height,10,10,10);
		if(stepkey==1)
		{
			if(hasstep2)
			{
				hasstep2=0;
			WM_InvalidateWindow(WM_HBKWIN);
			}
		       GUI_SetPenSize((int)((TouchNotesBuf[0].Height*TouchNotesBuf[0].Width*1.0)/(3.14)));
					  GUI_Delay(10);
						if(flag.down)
						{
							    
							if(g_sTouchY1>_aButtonData[0].yPos-20)
							{
								if(g_sTouchX1<_aButtonData[6].xPos+_aButtonData[6].xSize) //左边
								{
									for (i = 0; i < GUI_COUNTOF(_aButtonData)-7; i++) 
									 {
											if(PoinCal(g_sTouchX1,g_sTouchY1,_aButtonData[i].xPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos,_aButtonData[i].yPos+_aButtonData[i].ySize))
											{
												GUI_SetColor(GUI_GREEN);//设置按钮外框颜色
												GUI_DrawRect(_aButtonData[i].xPos,_aButtonData[i].yPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos+_aButtonData[i].ySize);
											 // GUI_SetColor();
												flag.color=_aButtonData[i].color;
												flag.erase=0;
											}
											else
											{
											GUI_SetColor(_aButtonData[i].color);
											GUI_FillRect(_aButtonData[i].xPos,_aButtonData[i].yPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos+_aButtonData[i].ySize);
											}
									}
								}
								
								if(g_sTouchX1>_aButtonData[13].xPos)//右边
								{
							   	for (i = GUI_COUNTOF(_aButtonData)-7; i < GUI_COUNTOF(_aButtonData); i++) 
									 {
											if(PoinCal(g_sTouchX1,g_sTouchY1,_aButtonData[i].xPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos,_aButtonData[i].yPos+_aButtonData[i].ySize))
											{
												GUI_SetColor(GUI_GREEN);//设置按钮外框颜色
												GUI_DrawRect(_aButtonData[i].xPos,_aButtonData[i].yPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos+_aButtonData[i].ySize);
											 // GUI_SetColor();
												flag.colorsecond=_aButtonData[i].color;
												flag.erase=0;
											}
											else
											{
											GUI_SetColor(_aButtonData[i].color);
											GUI_FillRect(_aButtonData[i].xPos,_aButtonData[i].yPos,_aButtonData[i].xPos+_aButtonData[i].xSize,_aButtonData[i].yPos+_aButtonData[i].ySize);
											}
									}
								}
								
								if(PoinCal(g_sTouchX1,g_sTouchY1,46*8,46*8+45,435,435+44))//橡皮擦
								{
								        GUI_SetColor(GUI_GREEN);//设置按钮外框颜色
												GUI_DrawRect(46*8,435,46*8+49,435+43);
									      GUI_DrawBitmap(&bmclear,46*9,435);
									    // GUI_DrawCircle(200,100,20);
									     flag.erase=1;
								}
								if(PoinCal(g_sTouchX1,g_sTouchY1,46*9,46*9+45,435,435+43)) //清屏
								{
								      GUI_SetColor(GUI_GREEN);//设置按钮外框颜色
											GUI_DrawRect(46*9,435,46*9+49,435+43);
										 GUI_DrawBitmap(&bmerase,46*8,435);
									flag.erase=0;
									WM_InvalidateWindow(WM_HBKWIN);
									
								}
						  
									 
									
					   }
						
//							
//							    last_x1=g_sTouchX1;
//						      last_y1=g_sTouchY1;
							
							
						}
						if(flag.move)//移动
						{
							     
								if(g_sTouchY1<_aButtonData[0].yPos-20)//防止画到底部部分
								{
										if(!flag.erase)
										{
										GUI_CURSOR_Hide();
//											if(abs(last_x1,g_sTouchX1)<60&&abs(last_y1,g_sTouchY1)<60)
//											{
									  GUI_SetColor(flag.color) ;  
									  GUI_DrawLine(last_x1,last_y1,g_sTouchX1,g_sTouchY1);//移动的时候画线
								//			}
										}
										else  //橡皮擦
										{
//											GUI_SetColor(GUI_GREEN);
//											GUI_DrawRect(g_sTouchX1-1,g_sTouchY1-1,TouchNotesBuf[0].Width+g_sTouchX1+2,g_sTouchY1+TouchNotesBuf[0].Height+2);
													GUI_CURSOR_Show();
											GUI_CURSOR_Select(&GUI_CursorCrossL);
										  GUI_SetColor(GUI_WHITE);
												//GUI_FillRect(last_x1-1,last_y1-1,TouchNotesBuf[0].Width+last_x1+2,last_y1+TouchNotesBuf[0].Height+2);
											
											
									   // GUI_FillRect(g_sTouchX1,g_sTouchY1,TouchNotesBuf[0].Width+g_sTouchX1,g_sTouchY1+TouchNotesBuf[0].Height);
											GUI_FillCircle(g_sTouchX1,g_sTouchY1,(int)((TouchNotesBuf[0].Height*TouchNotesBuf[0].Width*1.0)/(3.14)));
									
										
										}
									 
							      last_x1=g_sTouchX1;
						        last_y1=g_sTouchY1;
									
								}
						 
						}
						if(flag.up)
						{
							
	//						WM_InvalidateWindow(WM_HBKWIN);
						}
					if(flag.secondpoint)//第二点
					 {
					          flag.secondpoint=0;
									
                  if(secondPointY<_aButtonData[0].yPos-20)//防止画到底部部分
								{
								
									
								    	GUI_SetColor(flag.colorsecond) ;
                  								
								 
										  GUI_DrawLine(last_x2,last_y2,secondPointX,secondPointY);
									
											last_x2=secondPointX;
						           last_y2=secondPointY;
								}

						     
					 }
					 
					 
				flag.down=flag.move=flag.secondpoint=flag.up=0;	 
		 }
					 
  }


}





uint8_t PoinCal(uint16_t x,uint16_t y,uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2)
{
	if(x>x1&&x<x2&&y>y1&&y<y2)
	{
    return 1;
	}
 return 0;
}


//触摸点的
void  PointHandler(void)
{
    long lX,lY;
   GUI_PID_STATE   State = {0};
    static short pre_x=0,pre_y=0,last_point2_x=0,last_point2_y=0;

    lX = g_sTouchX1;
    lY = g_sTouchY1;

    //
    // See if the touch screen is being touched.
    //
		/* up */
		if(Motion.MotionMsg.Action == ACTION_UP)
			{
        flag.up=1;
				flag.down=1;
				flag.move=0;
				step=0;
			}
	  /* down */
	  else if(Motion.MotionMsg.Action == ACTION_DOWN)

			{
			   flag.up=0;
				flag.down=1;
				flag.move=0;
//    State.x = 0;
//    State.y = 555;
//   // Pressed ^= 1;
//    State.Pressed = 1;
//    GUI_PID_StoreState(&State);
//				GUI_SetColor(GUI_BLUE);
//				GUI_SetPenSize(45);
//		  GUI_DrawPoint(lX,lY);
			}
		/* move */
	  else if(Motion.MotionMsg.Action == ACTION_MOVE)
			{
           flag.up=0;
				   flag.down=0;
			    	flag.move=1;

			}
#if 0			
#endif			
			else
			{
  // UartPrintf("none touch \n");
     }
// test
		 	if(Motion.MotionMsg.mPointer == 1)
			{
				
				secondPointX = Motion.MotionMsg.mPointer_x[0];
				secondPointY = Motion.MotionMsg.mPointer_y[0];
				flag.secondpoint=1;
				//UartPrintf("2_MOVE,x=%d,y=%d\n",lX,lY);
				
//				last_point2_x = lX;
//				last_point2_y = lY;
			}
			
			Motion.MotionMsg.mAction = NO_ACTION;
}





void BT_Hand(void)
{
	static uint8_t noKeyDly = 0;
	int i;
	Tmr1Cnt++;
	
	if( NeonodeNewConvertion() )
		{
		  if((Motion.MotionMsg.Action == ACTION_DOWN)||(Motion.MotionMsg.Action == ACTION_UP)||
				(Motion.MotionMsg.Action == ACTION_MOVE) )
		  	{
		  	 	g_sTouchX1 = getAxisValue(AXIS_X);
					g_sTouchY1 = getAxisValue(AXIS_Y);
		  	}
			PointHandler();
			noKeyDly = 0;
		}
		else
		{
			/* bug, if no response,then reinitial  */
						if(noKeyDly<70)
							{
								noKeyDly++;
							}
						else
							{
								if(CommsNeonodeCmdReadForce(buf))
									{
										if(buf[0] != 0xEE)
										{
											/* neonode init*/
											CommsNeonodeInit(); 
											//delay_ms(10);//wait fot zForec DR high
											for(i=0;i<0xfffff;i++);
											NeonodeSetting();
											MotionEventInit();
											//UartPrintf("reset neonode! \n");
                      
										}
			
									}
                noKeyDly = 0;
							} 
							g_sTouchY1=0xffff;
							g_sTouchX1=0xffff;
		}       
		

}

// void RTUnderflowIntHandler(void)
//{
//Point_Handler_Flag1=1;
//		SysTick_Count++;
//	if(SysTick_Count==100)
//	{
//     SysTick_Count=0;
//		 //flag_1s=1;
//		if(Down_flag)
//		{
//     flag_1s=1;
//    }
//	
//   }
//BT_RTClrUnderflowIntFlag(USER_BT_CH);	 //清除中断标志
//}


#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
