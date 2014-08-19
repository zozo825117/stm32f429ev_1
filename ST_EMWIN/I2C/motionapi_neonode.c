///////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2014-2016,
/// \file 			 motion_iqs5xx.c
/// \brief		 apoint xy date to finger information
///
/// \author 	 zozo 
/// \version	 V0.2
/// \note
//! 		
/// \data 		 2013.9.1 ¥¥Ω®≥ı ‘ 
/// \History	 2014.2.24 change to V0.2
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
//#include "fm3_common.h"
//#include "Pdl_header.h"
//#include "resource.h"
#include "neonode.h"
#include "motion.h"
#include "motionapi_neonode.h"
#include "string.h"



//****************************************************************************
//	Variable
//****************************************************************************/
extern touch_finger_message_t FingerMsg;
extern uint32_t Tmr1Cnt;
extern touch_notification_t TouchNotesBuf[5];

static uint8_t FingerID[SUPPORT_FINGER_NUM];
static uint8_t fIDState,f_id_state_remove,en_finger_num=0;


//****************************************************************************
//	function
//****************************************************************************/


///////////////////////////////////////////////////////////////////////////////
/// \brief			remove finger operate
/// \param			num_remove
/// \param			en_finger_cnt
/// \return 			none
/// \deprecated 
///////////////////////////////////////////////////////////////////////////////
void RemoveFingerOprt(uint8_t num_remove,uint8_t en_finger_cnt)
{
	//uint8_t n,bit_n;

	
	//if(en_finger_cnt == 0 || (en_finger_cnt - num_remove == 0))
		{
			fIDState &=~ (1<<num_remove);
			f_id_state_remove &=~ (1<<num_remove);
			memset( &FingerMsg.SFI[num_remove],0,sizeof(touch_finger_info_t));
		}
	#if 0
	else
		{
     //move forward
		for(n = num_remove;n<=(en_finger_cnt - num_remove);n++)
			{
				//change FingerID
				FingerID[n] = FingerID[n+1];
				//change fIDState
				bit_n = (fIDState & (1<<(n+1)));
				if(bit_n)
						fIDState |= (1<<n);
				else
						fIDState &=~ (1<<n);
				
				//change f_id_state_remove
				bit_n = (f_id_state_remove & (1<<(n+1)));
				if(bit_n)
						f_id_state_remove |= (1<<n);
				else
						f_id_state_remove &=~ (1<<n);
		
		
				//change FingerMsg.SFI								
				memcpy( &FingerMsg.SFI[n],&FingerMsg.SFI[n+1],sizeof(touch_finger_info_t));
        memset( &FingerMsg.SFI[n+1],0,sizeof(touch_finger_info_t));
			}
		}
#endif

}

///////////////////////////////////////////////////////////////////////////////
/// \brief			enable finger operate
/// \param			n_num
/// \param			en_num
/// \return 			none
/// \deprecated 
///////////////////////////////////////////////////////////////////////////////
void EnableFingerOprt(uint8_t n_num,uint8_t en_num)
{
#if 0
	uint8_t f_id_buf,bit_n;
	touch_finger_info_t touch_finger_buf;

	if(n_num > en_num)
		{
			//change FingerID
			f_id_buf =	FingerID[n_num];
			FingerID[n_num] =  FingerID[en_num];
			FingerID[en_num]=f_id_buf;
			//change fIDState
			bit_n = (fIDState & (1<<(en_num)));
			if(bit_n)
					fIDState |= (1<<n_num);
			else
					fIDState &=~ (1<<n_num);
			fIDState |= (1<<en_num);
			//change f_id_state_remove
			bit_n = (f_id_state_remove & (1<<(en_num)));
			if(bit_n)
					f_id_state_remove |= (1<<n_num);
			else
					f_id_state_remove &=~ (1<<n_num);
			f_id_state_remove &=~ (1<<en_num);
			//change FingerMsg.SFI
			memcpy( &touch_finger_buf,&FingerMsg.SFI[n_num],sizeof(touch_finger_info_t));
			memcpy( &FingerMsg.SFI[n_num],&FingerMsg.SFI[en_num],sizeof(touch_finger_info_t));
			memcpy( &FingerMsg.SFI[en_num],&touch_finger_buf,sizeof(touch_finger_info_t));
		}
	#endif
}

///////////////////////////////////////////////////////////////////////////////
/// \brief			FingerBufferOprate
/// \param			x
/// \param			y
/// \param			touch_finger
/// \param			clear

/// \return 			rc 0 nothing 1 finger enable 2 finger disable
/// \deprecated Use a cache to store the location information, the latest position on the last, as 
/// 						calculated using historical data to data. The advantage is that, when data appears 
/// 						some jitter will not affect the calculation of the data immediately.
///////////////////////////////////////////////////////////////////////////////
uint8_t FingerBufferOprate(int16_t x,int16_t y,touch_finger_info_t *touch_finger,uint8_t clear)
{
  uint8_t i,rc = 0;
	if(clear == 1)
		{
			touch_finger->Index = 0;
			touch_finger->finger_en = 0;			
		}
	else
		{
			if(x == 0 && y == 0)
				{
					// dec index
					if(touch_finger->Index)
						{
							touch_finger->Index--;
							if(touch_finger->Index == 0)
								{
									/*finger disable*/
									rc = 2;
								}
						}
				}
			else
				{
					// add index
					if(touch_finger->Index < FINGER_POISION_LAST_LEN)
						{
							touch_finger->Index++;
							if(touch_finger->Index == FINGER_POISION_LAST_LEN)
								{
									/*finger enable*/
									rc = 1;
								}
						}
				}
			
			for(i=0;i<FINGER_POISION_LAST_LEN-1;i++)
				{
					touch_finger->Xpos[i] = touch_finger->Xpos[i+1];
					touch_finger->Ypos[i] = touch_finger->Ypos[i+1];
				}
			touch_finger->Xpos[FINGER_POISION_LAST_LEN-1] = x;
			touch_finger->Ypos[FINGER_POISION_LAST_LEN-1] = y;

		}


	return rc;
	
}

///////////////////////////////////////////////////////////////////////////////
/// \brief			FingerIntoBuffer
/// \param			ID
/// 							xydata ID
/// \return 			num 
/// 							The position of the ID in the buffer. If can't put this ID, then the return 0 XFF.

/// \deprecated num:	number of ID into finger id buffer:0-4;  0xff = error  (no null / up message -- neonode)
///////////////////////////////////////////////////////////////////////////////
static uint8_t FingerIntoBuffer(uint8_t ID)
{
	uint8_t i,bit=1,buf_null[SUPPORT_FINGER_NUM],ptr=0,num;
	/* check ID */
	for(i=0;i<SUPPORT_FINGER_NUM;i++)
		{
			if(fIDState & bit)
				{
					/*ID	 has in finger id buf  return*/
					if((FingerID[i] == ID))
						{
							f_id_state_remove &=~bit;
							num = i;
							return num;						  	
						}	
				}
			else
				{
					/*record null number*/
					buf_null[ptr++] = i; 
				}
			bit<<=1;
		}
	/*add new finger id*/
	if(ptr>0)
		{
			FingerID[buf_null[0]] = ID;
			num = buf_null[0];
			fIDState |= (1<<num);
			return num;
		}
	else
		{
			num = 0xFF;
			return num;
		}
	
	
}

typedef struct{
	uint8_t count;
	uint8_t id1;
	uint8_t x1;
	uint8_t id2;
	uint8_t x2;
	}test_buf_t;

test_buf_t test_buf[100];
uint8_t ptr=0;
///////////////////////////////////////////////////////////////////////////////
/// \brief			which Finger Is use neonode touch notification
/// \param			none
/// \return 			none
/// \deprecated Here is a FingerMsg.SFI array, it will own track reported XYdata, according to the 
/// 						order XYdata.ID appears, into an array 1-5 position.
///////////////////////////////////////////////////////////////////////////////
uint8_t NeoNodeNoticewhichFingerIs(void)
{
	uint8_t i,num,id_buf;//
  uint16_t  now_x,now_y; 
	



	/*ghost change id
	if((t_CTNs.Count == 2)&&(t_CTNs.tNotices[0].State.Bit.State & TOUCH_STATE_GHOST_DETECTED))
		{
			id_buf = t_CTNs.tNotices[0].State.Bit.id;
			t_CTNs.tNotices[0].State.Bit.id = t_CTNs.tNotices[1].State.Bit.id;
			t_CTNs.tNotices[1].State.Bit.id = id_buf;
		}*/
	
	if(t_CTNs.tNotices[0].State.Bit.State & TOUCH_STATE_GHOST_DETECTED || 
			t_CTNs.tNotices[1].State.Bit.State & TOUCH_STATE_GHOST_DETECTED )
		{
			t_CTNs.Count = 0;
		}


	/*check xy_data  from iqs550 set ID to finger buf*/
	for(i=0;i<SUPPORT_FINGER_NUM;i++)
		{
		  if((t_CTNs.Count >0)&&(i <= (t_CTNs.Count-1)))
		  	{
					/*not add hover co-ordinates here*/
					num = FingerIntoBuffer(t_CTNs.tNotices[i].State.Bit.id);
		
					if(num!=0xff)
						{
							now_x =(t_CTNs.tNotices[i].X_lbyte |t_CTNs.tNotices[i].X_hbyte<<8);
							now_y =(t_CTNs.tNotices[i].Y_lbyte |t_CTNs.tNotices[i].Y_hbyte<<8);
							FingerMsg.SFI[num].finger_updata = 1;

							FingerBufferOprate(now_x,now_y,&FingerMsg.SFI[num],0);
							
							memcpy( &TouchNotesBuf[num],&t_CTNs.tNotices[i],sizeof(touch_notification_t));

							 /*finger enable*/
							 if(t_CTNs.tNotices[i].State.Bit.State == TOUCH_STATE_DOWN)
							 	{
							 		
								 if(!(FingerMsg.SFI[num].finger_en))
									{
									 FingerMsg.SFI[num].finger_state = STATE_DOWN;
									 FingerMsg.SFI[num].finger_en = 1;
									 FingerMsg.SFI[num].use_idx = 1;
									 FingerMsg.SFI[num].last_idx = 0;
									 EnableFingerOprt(num,en_finger_num);
									 en_finger_num++;
									}
							 	}
							 else if(t_CTNs.tNotices[i].State.Bit.State == TOUCH_STATE_MOVE)
							 	{
							 		FingerMsg.SFI[num].finger_state = STATE_PRESSED;
							 	}
							 else if(t_CTNs.tNotices[i].State.Bit.State == TOUCH_STATE_UP)
							 	{
									 /*remove this finger and move forward behind finger*/
									 if(FingerMsg.SFI[num].finger_en)
										 {
											 en_finger_num--;
										 }
									 RemoveFingerOprt(num,en_finger_num);
                   FingerMsg.SFI[num].finger_updata = 1;
									 FingerMsg.SFI[num].finger_state = STATE_UP;

							 	}
							}
             else
              {
                
              }

					}
		 }


	////////////////////
	test_buf[ptr].count = t_CTNs.Count;
	test_buf[ptr].id1 = t_CTNs.tNotices[0].State.All;
	test_buf[ptr].x1 = t_CTNs.tNotices[0].X_lbyte;
	
	test_buf[ptr].id2 = t_CTNs.tNotices[1].State.All;
	test_buf[ptr].x2 = t_CTNs.tNotices[1].X_lbyte;

	if(ptr<100)ptr++;
	else
		{
			ptr = 0;
		}
	
	////////////////////

	
	return en_finger_num;

}
void NeoNodeNoticewhichFingerIsInit(void)
{
	fIDState = 0;
}



//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif



