///////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2014-2016,
/// \file 			 motion.c
/// \brief		 touch panel motion process
///
/// \author 	 zozo 
/// \version	 V00.03
/// \note
//! 		
/// \data 		 2013.9.1 创建初试 
/// \History	 2014.2.22 change to V0.2
/// \History	 2014.7.4  适合红外屏的修改，支持不同时爆点，自带down up消息
///
///////////////////////////////////////////////////////////////////////////////


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
//	header file
//****************************************************************************/

#include "neonode.h"
#include "motion.h"
#include "motionapi_neonode.h"
#include "stdlib.h"



//****************************************************************************
//	Variable
//****************************************************************************/
extern uint32_t Tmr1Cnt;

//static set_meg_t SetMeg;
static motion_finger_move_t MajorFingerMove;
static motion_finger_move_t MinorFingerMove;



motion_t Motion;
touch_finger_message_t FingerMsg;



//****************************************************************************
//	function
//****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
/// \brief			is move loop
/// \param			dlt
/// \param			move_thres
/// \param			mode
/// \param			major_last
/// \param			major_dlt
/// \return 			none
/// \deprecated updata major finger delta xy and last xy 
///////////////////////////////////////////////////////////////////////////////
uint8_t isMovingLoop(int16_t dlt,uint16_t move_thres,uint8_t mode,int16_t *major_last,int16_t *major_dlt)
{
	uint8_t rc=0;
	if(abs(dlt)> move_thres)
		{
			if(dlt > 0)
				{
					dlt -= move_thres;
				}
			else
				{
					dlt += move_thres;
				}


			if(mode == 0)
				{
					*major_last -= dlt;
				}
			else
				{	
					*major_last += dlt;
				}

			if(*major_last < 0)
				{
					*major_last = 0;
				}
			else if(*major_last > 30000)
				{
					*major_last = 30000;
				}
			
			*major_dlt = dlt/POSITION_DIV;

			rc = 1;
		}
	else
		{
			*major_dlt = 0;
		}
 return rc;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief			determine the direction of movement  of the last and now coodinate 
/// \param			x
/// \param			y
/// \return 			none
/// \deprecated none
///////////////////////////////////////////////////////////////////////////////
static uint8_t isMoving(int16_t x,int16_t y,motion_finger_move_t *finger_move)
{
  uint16_t now_x,now_y,move_thres = finger_move->MoveThres;
  int16_t delta_x=0,delta_y=0; 
  uint8_t i,rc = 0,index;

#if !X_Y_DIRECTION
  now_x = x;
  now_y = y;
#else
  now_x = y;
  now_y = x;
#endif
  
  /*
  add  coodinate  to history
  */
	index = finger_move->index;
  finger_move->His_x[index] = now_x;
  finger_move->His_y[index] = now_y;	
  
  finger_move->index++;
  
  if(finger_move->index>=HIS_LEN)
  {
    finger_move->index=0;
  }  
  
  /*
  average move summer
  */
  finger_move->average_cnt++;
  
  if(finger_move->average_cnt >= MOVE_AVG_POINT_CNT)
  {
   finger_move->average_cnt = MOVE_AVG_POINT_CNT;
  }
  else
  {
  	if(finger_move->moving == 0)
  		{
  			return 0;
  		}
      
  }
  

  for(i=0;i<finger_move->average_cnt;i++)
  {
#if !X_DIRECTION
    delta_x += finger_move->Last_x-finger_move->His_x[index];
#else
    delta_x += finger_move->His_x[index] - finger_move->Last_x;
#endif
#if !Y_DIRECTION
    delta_y += finger_move->Last_y-finger_move->His_y[index];
#else
    delta_y += finger_move->His_y[index] - finger_move->Last_y;
#endif
    
    if(index)
    {
      index--;
    }
    else
    {
      index = HIS_LEN - 1;
    }
  }
  
  delta_x /= finger_move->average_cnt;
  delta_y /= finger_move->average_cnt;


  /* 
    	updata last coodinate
    */
#if !X_DIRECTION
	if(isMovingLoop(delta_x,move_thres,0,&finger_move->Last_x,&finger_move->Dlt_x))
#else
	if(isMovingLoop(delta_x,move_thres,1,&finger_move->Last_x,&finger_move->Dlt_x))

#endif  
  	{
  		rc = 1;
  	}
#if !Y_DIRECTION
	if(isMovingLoop(delta_y,move_thres,0,&finger_move->Last_y,&finger_move->Dlt_y))

#else
	if(isMovingLoop(delta_y,move_thres,1,&finger_move->Last_y,&finger_move->Dlt_y))
#endif	
		{
			rc = 1;
		}


	finger_move->average_cnt = 0;

  
  return rc;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief			set finger state
/// \param			none
/// \return 			count of fingers
/// \deprecated none
///////////////////////////////////////////////////////////////////////////////
static uint8_t setFingerState(void)
{
  return 0 ;
}


///////////////////////////////////////////////////////////////////////////////
/// \brief			Gets the value associated with the specified axis.
/// \param			axis The axis identifier for the axis value to retrieve.
/// \return 			The value associated with the axis, or 0 if none.
/// \deprecated none
///////////////////////////////////////////////////////////////////////////////
int16_t getAxisValue(int16_t axis) {
  switch (axis) {
  case AXIS_X:
    return Motion.MotionMsg.x;
  case AXIS_Y:
    return Motion.MotionMsg.y;
  case AXIS_PRESSURE:
    return Motion.MotionMsg.pressure;
  case AXIS_SIZE:
    return Motion.MotionMsg.size;
  case AXIS_TOUCH_MAJOR:
    return Motion.MotionMsg.touchMajor;
  case AXIS_TOUCH_MINOR:
    return Motion.MotionMsg.touchMinor;
  case AXIS_TOOL_MAJOR:
    return Motion.MotionMsg.toolMajor;
  case AXIS_TOOL_MINOR:
    return Motion.MotionMsg.toolMinor;
  case AXIS_ORIENTATION:
    return Motion.MotionMsg.orientation;
  case AXIS_VSCROLL:
    return Motion.MotionMsg.vscroll;
  case AXIS_HSCROLL:
    return Motion.MotionMsg.hscroll;
  default: {
    if (axis < 0 || axis > 63) {
      //("Axis out of range.");
      return 0;
    }
  }
  }
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
/// \brief			Sets the value associated with the specified axis.
/// \param			axis The axis identifier for the axis value to assign.
/// \param			value The value to set.
/// \return 			none
/// \deprecated none
////////////////////////////////////////////////////////////////////////////////
void setAxisValue(int16_t axis, int16_t value) {
  switch (axis) {
  case AXIS_X:
    Motion.MotionMsg.x= value;
    break;
  case AXIS_Y:
    Motion.MotionMsg.y = value;
    break;
  case AXIS_PRESSURE:
    Motion.MotionMsg.pressure = value;
    break;
  case AXIS_SIZE:
    Motion.MotionMsg.size = value;
    break;
  case AXIS_TOUCH_MAJOR:
    Motion.MotionMsg.touchMajor = value;
    break;
  case AXIS_TOUCH_MINOR:
    Motion.MotionMsg.touchMinor = value;
    break;
  case AXIS_TOOL_MAJOR:
    Motion.MotionMsg.toolMajor = value;
    break;
  case AXIS_TOOL_MINOR:
    Motion.MotionMsg.toolMinor = value;
    break;
  case AXIS_ORIENTATION:
    Motion.MotionMsg.orientation = value;
    break;
  case AXIS_VSCROLL:
    Motion.MotionMsg.vscroll = value;
    break;
  case AXIS_HSCROLL:
    Motion.MotionMsg.hscroll = value;
    break;
  default: {
    if (axis < 0 || axis > 63) {
      //("Axis out of range.");
    }
    
  }
  }
}

////////////////////////////////////////////////////////////////////////////////
/// \brief			minor finger process
/// \param			none
/// \return 			none
/// \deprecated none
////////////////////////////////////////////////////////////////////////////////
extern unsigned int last_x2,last_y2;
void MinorFingerPocess(void)
{
	uint32_t now_major_time = Tmr1Cnt,temp_time;
	int16_t x,y;
	uint8_t now_index;

	if(FingerMsg.SFI[1].finger_state == STATE_DOWN)
		{
			MinorFingerMove.finger_down_time = now_major_time;

			/* inital move*/
			MinorFingerMove.Last_x = FingerMsg.SFI[1].Xpos[FingerMsg.SFI[1].use_idx];
			MinorFingerMove.Last_y = FingerMsg.SFI[1].Ypos[FingerMsg.SFI[1].use_idx];
			MinorFingerMove.average_cnt = 0;
			MinorFingerMove.index = 0;
			MinorFingerMove.moved = 0;
			MinorFingerMove.moving = 0;
			MinorFingerMove.MoveThres = NO_MOVE_HYSTERE_THRES; //first move threshold is larger than moved


			/*set message*/
			Motion.MotionMsg.mAction = ACTION_POINTER_DOWN;
			setAxisValue(AXIS_X, MinorFingerMove.Last_x);
			setAxisValue(AXIS_Y, MinorFingerMove.Last_y);
			
			last_x2=MinorFingerMove.Last_x;
			
		  last_y2=MinorFingerMove.Last_y;
		}
	else if(FingerMsg.SFI[1].finger_state == STATE_PRESSED)
		{
			temp_time = now_major_time - MinorFingerMove.finger_down_time;
			if(temp_time > BUTTON_TIMES_MAX)
				{
					MinorFingerMove.MoveThres = MOVE_HYSTERE_THRES;
				}

			
			now_index = FingerMsg.SFI[1].use_idx;
			x = FingerMsg.SFI[1].Xpos[now_index];
			y = FingerMsg.SFI[1].Ypos[now_index];
#if 1
			if(isMoving(x,y,&MinorFingerMove))
				{
					MinorFingerMove.MoveThres = MOVE_HYSTERE_THRES;
					MinorFingerMove.moved = 1;
					MinorFingerMove.moving = 1;
				}
			else
				{
					MinorFingerMove.moving = 0;
				}
#endif

			/*set message*/
			Motion.MotionMsg.mPointer = 1 ;
			Motion.MotionMsg.mPointer_x[0] = x ;
			Motion.MotionMsg.mPointer_y[0] = y ;

		}
	else if(FingerMsg.SFI[1].finger_state == STATE_UP)
		{
		 temp_time = now_major_time - MajorFingerMove.finger_down_time;
		 if((temp_time > BUTTON_TIMES_MIN)&&(temp_time < BUTTON_TIMES_MAX)&&
				(MinorFingerMove.moved == 0))
		 {
			 Motion.MotionMsg.ButtonFlags = BUTTON_SECONDARY;
		 }
			MinorFingerMove.index = 0;
			MinorFingerMove.moved = 0;
			MinorFingerMove.moving = 0;

			/*set message*/
			Motion.MotionMsg.Action = ACTION_POINTER_UP;
			setAxisValue(AXIS_X, MinorFingerMove.Last_x);
			setAxisValue(AXIS_Y, MinorFingerMove.Last_y);
			FingerMsg.SFI[1].finger_state = STATE_NOFINGER;
		}


}
extern  uint8_t step;
////////////////////////////////////////////////////////////////////////////////
/// \brief			major finger process
/// \param			none
/// \return 			none
/// \deprecated major finger use mouse move and primary buttom message
////////////////////////////////////////////////////////////////////////////////
extern unsigned int last_x1,last_y1;
void MajorFingerPocess(void)
{
	uint32_t now_major_time = Tmr1Cnt,temp_time;
	int16_t x,y;
	uint8_t now_index;

	 if(FingerMsg.SFI[0].finger_state == STATE_DOWN)
		{
			MajorFingerMove.finger_down_time = now_major_time;

			/* inital move*/
			MajorFingerMove.Last_x = FingerMsg.SFI[0].Xpos[FingerMsg.SFI[0].use_idx];
			MajorFingerMove.Last_y = FingerMsg.SFI[0].Ypos[FingerMsg.SFI[0].use_idx];
			MajorFingerMove.average_cnt = 0;
			MajorFingerMove.index = 0;
			MajorFingerMove.moved = 0;
			MajorFingerMove.moving = 0;
			MajorFingerMove.MoveThres = NO_MOVE_HYSTERE_THRES; //first move threshold is larger than moved

			/*set message*/
			Motion.MotionMsg.Action= ACTION_DOWN;
			setAxisValue(AXIS_X, MajorFingerMove.Last_x);
			setAxisValue(AXIS_Y, MajorFingerMove.Last_y);
			last_x1=MajorFingerMove.Last_x;
			last_y1=MajorFingerMove.Last_y;
			
		}
	 else if(FingerMsg.SFI[0].finger_state == STATE_PRESSED)
		{
		 temp_time = now_major_time - MajorFingerMove.finger_down_time;
		 if(temp_time > BUTTON_TIMES_MAX)
			 {
				 MajorFingerMove.MoveThres = MOVE_HYSTERE_THRES;
			 }
 
		 now_index = FingerMsg.SFI[0].use_idx;
		 x = FingerMsg.SFI[0].Xpos[now_index];
		 y = FingerMsg.SFI[0].Ypos[now_index];
#if 1
		 if(isMoving(x,y,&MajorFingerMove))
			 {
				 MajorFingerMove.MoveThres = MOVE_HYSTERE_THRES;
				 MajorFingerMove.moved = 1;
				 MajorFingerMove.moving = 1; 
			 }
		 else
			 {
				 MajorFingerMove.moving = 0;
			 }
#endif

			/*set message*/
			Motion.MotionMsg.Action = ACTION_MOVE;
			setAxisValue(AXIS_X, x);
			setAxisValue(AXIS_Y, y);
		}
	 else if(FingerMsg.SFI[0].finger_state == STATE_UP)
		{

			step=0;
			
		 temp_time = now_major_time - MajorFingerMove.finger_down_time;
		 if((temp_time > BUTTON_TIMES_MIN)&&(temp_time < BUTTON_TIMES_MAX)&&
				(MajorFingerMove.moved == 0))
		 {
			 Motion.MotionMsg.ButtonFlags = BUTTON_PRIMARY;
		 }
			
			 MajorFingerMove.index = 0;
			 MajorFingerMove.moved = 0;
			 MajorFingerMove.moving = 0;

			/*set message*/
			Motion.MotionMsg.Action = ACTION_UP;
			setAxisValue(AXIS_X, MajorFingerMove.Last_x);
			setAxisValue(AXIS_Y, MajorFingerMove.Last_y);
			FingerMsg.SFI[0].finger_state = STATE_NOFINGER;
	 
		}
	 


}

////////////////////////////////////////////////////////////////////////////////
/// \brief			Multi Finger Gesture
/// \param			none
/// \return 			none
/// \deprecated Multi finger use mouse move and primary buttom message
////////////////////////////////////////////////////////////////////////////////
void MultiFingerGesture(void)
{
  int16_t dlt_x,dlt_y;
	static uint32_t scroll_state;
	static int16_t dlt_x_buf[2],dlt_y_buf[2];

	if(MajorFingerMove.moving)
		{
			dlt_x = abs(MajorFingerMove.Dlt_x);
			dlt_y = abs(MajorFingerMove.Dlt_y);

			if(dlt_x > dlt_y)
				{
					if( MajorFingerMove.Dlt_x > 0)
						{
							scroll_state &=~ MOVE_1_MASK;
							scroll_state |= MOVE_1_RIGHT;
						}
					else if(MajorFingerMove.Dlt_x < 0)
						{
							scroll_state &=~ MOVE_1_MASK;
							scroll_state |= MOVE_1_LEFT;
						}
					dlt_x_buf[0] = MajorFingerMove.Dlt_x;
				}
			else
				{
					if( MajorFingerMove.Dlt_y > 0)
						{
							scroll_state &=~ MOVE_1_MASK;
							scroll_state |= MOVE_1_UP;
						}
					else if(MajorFingerMove.Dlt_y < 0)
						{
							scroll_state &=~ MOVE_1_MASK;
							scroll_state |= MOVE_1_DOWN;
						}
					dlt_y_buf[0] = MajorFingerMove.Dlt_y;
				}

		}
	
	if(MinorFingerMove.moving)
		{
			dlt_x = abs(MinorFingerMove.Dlt_x);
			dlt_y = abs(MinorFingerMove.Dlt_y);

			if(dlt_x > dlt_y)
				{
					if( MinorFingerMove.Dlt_x > 0)
						{
							scroll_state &=~ MOVE_2_MASK;
							scroll_state |= MOVE_2_RIGHT;
						}
					else if(MinorFingerMove.Dlt_x < 0)
						{
							scroll_state &=~ MOVE_2_MASK;
							scroll_state |= MOVE_2_LEFT;
						}
					dlt_x_buf[1] = MinorFingerMove.Dlt_x;
				}
			else
				{
					if( MinorFingerMove.Dlt_y > 0)
						{
							scroll_state &=~ MOVE_2_MASK;
							scroll_state |= MOVE_2_UP;
						}
					else if(MinorFingerMove.Dlt_y < 0)
						{
							scroll_state &=~ MOVE_2_MASK;
							scroll_state |= MOVE_2_DOWN;
						}
					dlt_y_buf[1] = MinorFingerMove.Dlt_y;
				}

		}

	switch(scroll_state & MOVE_UP_DOWN_MASK)
	{
		case (MOVE_1_DOWN):
			break;
			
		case (MOVE_2_DOWN):
			break;	
			
		case (MOVE_3_DOWN):
			break;	
			
		case (MOVE_1_UP):
			break;	
			
		case (MOVE_2_UP):
			break;	

		case (MOVE_3_UP):
			break;	

		case (MOVE_1_DOWN|MOVE_2_DOWN):

		case (MOVE_1_UP|MOVE_2_UP):
        //SCROLL down
        dlt_y = abs(dlt_y_buf[0]);
        if(dlt_y < abs(dlt_y_buf[1]))
          {
            dlt_y = dlt_y_buf[1];
          }
        else
          {
             dlt_y = dlt_y_buf[0];
          }
        Motion.MotionMsg.Action = ACTION_SCROLL;
        setAxisValue(AXIS_VSCROLL, dlt_y);
        setAxisValue(AXIS_HSCROLL, 0);
        dlt_y_buf[0] = dlt_y_buf[1] = 0;
        scroll_state &=~ MOVE_UP_DOWN_MASK;

			break;

		case (MOVE_1_DOWN|MOVE_2_UP):
        // zoom
				dlt_y_buf[0] = dlt_y_buf[1] = 0;
				scroll_state &=~ MOVE_UP_DOWN_MASK;
			break;

		default:
				dlt_y_buf[0] = dlt_y_buf[1] = 0;
				scroll_state &=~ MOVE_UP_DOWN_MASK;
			break;

	}

	switch(scroll_state & MOVE_RIGHT_LEFT_MASK)
	{
		case (MOVE_1_LEFT):
			break;
			
		case (MOVE_2_LEFT):
			break;	
			
		case (MOVE_3_LEFT):
			break;	
			
		case (MOVE_1_RIGHT):
			break;	
			
		case (MOVE_2_RIGHT):
			break;	

		case (MOVE_3_RIGHT):
			break;	

		case (MOVE_1_LEFT|MOVE_2_LEFT):

		case (MOVE_1_RIGHT|MOVE_2_RIGHT):
        //SCROLL down
        dlt_x= abs(dlt_x_buf[0]);
        if(dlt_x < abs(dlt_x_buf[1]))
          {
            dlt_x = dlt_x_buf[1];
          }
        else
        {
           dlt_x = dlt_x_buf[0];
        }
        Motion.MotionMsg.Action = ACTION_SCROLL;
        setAxisValue(AXIS_HSCROLL, dlt_x);
        setAxisValue(AXIS_VSCROLL, 0);
        dlt_x_buf[0] = dlt_x_buf[1] = 0;
        scroll_state &=~ MOVE_RIGHT_LEFT_MASK;
			break;


		case (MOVE_1_LEFT|MOVE_2_RIGHT):
			// zoom
				dlt_x_buf[0] = dlt_x_buf[1] = 0;
				scroll_state &=~ MOVE_RIGHT_LEFT_MASK;
			break;

		default:
				dlt_x_buf[0] = dlt_x_buf[1] = 0;
				scroll_state &=~ MOVE_RIGHT_LEFT_MASK;
			break;

	}


}

////////////////////////////////////////////////////////////////////////////////
/// \brief			set Motion Message
/// \param			none
/// \return 			none
/// \deprecated none
////////////////////////////////////////////////////////////////////////////////
static void setMotionMsg(void) 
{ 

#if 0
	if(FingerMsg.fType == 1)
		{
			MajorFingerPocess();
		}
	else if(FingerMsg.fType == 2)
		{
			MinorFingerPocess();
		}
	else if(FingerMsg.fType == 3)
		{
			// three finger
		}
	else if(FingerMsg.fType == 4)
		{
			// four finger
		}
	else if(FingerMsg.fType == 5)
		{
			// five finger
		}
	else
		{
			
		}
#endif	

	if(FingerMsg.SFI[0].finger_updata)
		{
			MajorFingerPocess();
			FingerMsg.SFI[0].finger_updata = 0;
		}
	if(FingerMsg.SFI[1].finger_updata)
		{
			MinorFingerPocess();
			FingerMsg.SFI[1].finger_updata = 0;
		}

	// MultiFingerGesture();
}


////////////////////////////////////////////////////////////////////////////////
/// \brief			find and move the notification is the right finger has. 
/// \param			none
/// \return 			none
/// \deprecated neonode 要收到notice 才调用
////////////////////////////////////////////////////////////////////////////////
void MotionEvent(void)
{
  FingerMsg.fType = Motion.whichFingerIs();
  Motion.doFinger();
  Motion.motion();
}


////////////////////////////////////////////////////////////////////////////////
/// \brief			Motion Event initial
/// \param			none
/// \return 			none
/// \deprecated none
////////////////////////////////////////////////////////////////////////////////
void MotionEventInit(void)
{
	NeoNodeNoticewhichFingerIsInit();
	Motion.MotionMsg.mAction = NO_ACTION;
  Motion.whichFingerIs = &NeoNodeNoticewhichFingerIs;
	Motion.doFinger = &setFingerState;
	Motion.motion = &setMotionMsg;
}


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif



