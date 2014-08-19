///////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2014-2016,
/// \file 			 motion.h
/// \brief		 touch panel motion process head file
///
/// \author 	 zozo 
/// \version	 
/// \note
//! 		
/// \data 		 2013.9.1 ¥¥Ω®≥ı ‘ 
/// \History	 
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __MOTION_H__ 
#define __MOTION_H__

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
//Macro definition
//****************************************************************************/

/*
how many fingers can be support
*/
#define SUPPORT_FINGER_NUM							2
/*
Touch State
*/
#define STATE_NOFINGER									0x00 
#define STATE_DOWN											0x01
#define STATE_PRESSED 									0x02 
#define STATE_UP												0x03
/*
X-Y direct	 0 x-y	1 y-x
*/
#define X_Y_DIRECTION 									0
/*
X  direct  0 pos	1 neg
*/
#define X_DIRECTION 										0
/*
Y direct		0 pos 1 neg
*/
#define Y_DIRECTION 										0
/*
Movement average counter
*/
#define MOVE_AVG_POINT_CNT						 	1
/*
position divide
*/
#define POSITION_DIV					 					1
/*
move hysteresis threshold 
*/
#define NO_MOVE_HYSTERE_THRES						(10)

#define MOVE_HYSTERE_THRES							(3)
/*
Movement
*/
#define MOVE_FAST_THRES 								8*MOVE_HYSTERE_THRES
#define MOVE_NORL_THRES 								5*MOVE_HYSTERE_THRES
#define MOVE_SLOW_THRES 								MOVE_HYSTERE_THRES


#define HIS_LEN 										6
//////////////////////////////////////////////////
/// \def FINGER_POISION_LAST_LEN
//////////////////////////////////////////////////
#define FINGER_POISION_LAST_LEN 		2

/*
mouse button	delay 50ms~350ms
*/
#define BUTTON_TIMES_MIN						50
#define BUTTON_TIMES_MAX						350//25

#define MOVE_1_UP										0x0001u
#define MOVE_2_UP										MOVE_1_UP<<1
#define MOVE_3_UP										MOVE_1_UP<<2

#define MOVE_1_DOWN									0x0010u
#define MOVE_2_DOWN									MOVE_1_DOWN<<1
#define MOVE_3_DOWN									MOVE_1_DOWN<<2



#define MOVE_1_RIGHT								0x0100u
#define MOVE_2_RIGHT								MOVE_1_RIGHT<<1
#define MOVE_3_RIGHT								MOVE_1_RIGHT<<2

#define MOVE_1_LEFT									0x1000u
#define MOVE_2_LEFT									MOVE_1_LEFT<<1
#define MOVE_3_LEFT									MOVE_1_LEFT<<2

#define MOVE_UP_DOWN_MASK						0x00ffu
#define MOVE_RIGHT_LEFT_MASK				0xff00u

#define MOVE_1_MASK 								(MOVE_1_UP|MOVE_1_DOWN|MOVE_1_RIGHT|MOVE_1_LEFT)
#define MOVE_2_MASK 								(MOVE_2_UP|MOVE_2_DOWN|MOVE_2_RIGHT|MOVE_2_LEFT)
#define MOVE_3_MASK 								(MOVE_3_UP|MOVE_3_DOWN|MOVE_3_RIGHT|MOVE_3_LEFT)



/*
multi-touch message
*/
/**
* Bit mask of the parts of the action code that are the action itself.
*/
#define ACTION_MASK 										0xff

/**
A pressed gesture has started, the
motion contains the initial starting location.
*/
#define ACTION_DOWN 										0
  
  /**
  A pressed gesture has finished, the
  motion contains the final release location as well as any intermediate
  points since the last down or move event.
  */
#define ACTION_UP 											1
  
  /*
  A change has happened during a
  press gesture (between {@link #ACTION_DOWN} and {@link #ACTION_UP}).
  The motion contains the most recent point, as well as any intermediate
  points since the last down or move event.
  */
#define ACTION_MOVE 										2
  /*
  *  The current gesture has been aborted.
  * You will not receive any more points in it.	You should treat this as
  * an up event, but not perform any action that you normally would.
  */
#define ACTION_CANCEL 									3
  
  /*
  A movement has happened outside of the
  normal bounds of the UI element.  This does not provide a full gesture,
  but only the initial location of the movement/touch.
  */
#define ACTION_OUTSIDE 									4
  
  /*
  A non-primary pointer has gone down.
  */
#define ACTION_POINTER_DOWN 						5
  
  /*
  A non-primary pointer has gone up.
  */
#define ACTION_POINTER_UP 							6
  /*
  A change happened but the pointer is not down (unlike {@link #ACTION_MOVE}).  
  The motion contains the most recent point, as well as any intermediate points since the last
  hover move event.
  */
#define ACTION_HOVER_MOVE 							7
  
  /*
  The motion event contains relative 
  vertical and/or horizontal scroll offsets.  Use {@link #getAxisValue(int)} to retrieve 
  the information from {@link #AXIS_VSCROLL} and {@link #AXIS_HSCROLL}.
  */
#define ACTION_SCROLL 									8
  /*
  The pointer is not down but has entered the boundaries of a window or view.
  */
#define ACTION_HOVER_ENTER 		 					9
  
  /*
  The pointer is not down but has exited the boundaries of a window or view.
  */
#define ACTION_HOVER_EXIT			 					10
  /*
  The pointer is not down but has exited the boundaries of a window or view.
  */
#define NO_ACTION 											0xffffu
  
  /**
  * Bits in the action code that represent a pointer index, used with
  * {@link #ACTION_POINTER_DOWN} and {@link #ACTION_POINTER_UP}. 
  */
#define ACTION_POINTER_INDEX_MASK				0xff00
  /**
  * Bit shift for the action bits holding the pointer index as
  * defined by {@link #ACTION_POINTER_INDEX_MASK}.
  */
#define ACTION_POINTER_INDEX_SHIFT 			8
  
  
  
  /**
  * Button constant: Primary button (left mouse button).
  *
  * This button constant is not set in response to simple touches with a finger
  * or stylus tip.  The user must actually push a button.
  */
#define BUTTON_PRIMARY 									(1 << 0)
  /**
  * Button constant: Secondary button (right mouse button, stylus first button).
  */
#define BUTTON_SECONDARY 								(1 << 1)
  /**
  * Button constant: Tertiary button (middle mouse button, stylus second button).
  * 
  */
#define BUTTON_TERTIARY									(1 << 2)
  /**
  * Button constant: Back button pressed (mouse back button).
  * The system may send a {@link KeyEvent#KEYCODE_BACK} key press to the application
  * when this button is pressed.
  */
#define BUTTON_BACK 										(1 << 3)
  /**
  * Button constant: Forward button pressed (mouse forward button).
  * The system may send a {@link KeyEvent#KEYCODE_FORWARD} key press to the application
  * when this button is pressed.
  */
#define BUTTON_FORWARD									(1 << 4)
  /**
  * Button constant: Mouse wheel data is present.
  */
#define BUTTON_WHELL										(1 << 5)
  /**
  * Button constant: Mouse horizontal wheel data is present.
  */
#define BUTTON_HWHEEL										(1 << 6)
  
  
  /*
  * The left mouse button changed to down.
  */
#define MOUSE_LEFT_BUTTON_DOWN						(1 << 0)
  /*
  * The left mouse button changed to up.
  */
#define MOUSE_LEFT_BUTTON_UP							(1 << 1)
  /*
  * The right mouse button changed to down.
  */
#define MOUSE_RIGHT_BUTTON_DOWN						(1 << 2)
  /*
  * The right mouse button changed to up.
  */
#define MOUSE_RIGHT_BUTTON_UP 						(1 << 3)
  /*
  *The middle mouse button changed to down.
  */
#define MOUSE_MIDDLE_BUTTON_DOWN 					(1 << 4)
  /*
  * The fourth mouse button changed to down.
  */
#define MOUSE_BUTTON_4_DOWN 							(1 << 5)
  /*
  * The fourth mouse button changed to up.
  */
#define MOUSE_BUTTON_4_UP 								(1 << 6)
  
  /*
  * The fifth mouse button changed to down.
  */
#define MOUSE_BUTTON_5_DOWN 							(1 << 7)
  
  /*
  * The fifth mouse button changed to up.
  */
#define MOUSE_BUTTON_5_UP 								(1 << 8)
  
  /*
  * Mouse wheel data is present.
  */
#define MOUSE_WHEEL 											(1 << 9)
  /*
  * Mouse horizontal wheel data is present.
  */
#define MOUSE_HWHEEL 											(1 << 10)
  
  
  
  
  /**
  * Axis constant: X axis of a motion event.
  * <li>For a touch screen, reports the absolute X screen position of the center of
  * the touch contact area.	The units are display pixels.
  * <li>For a touch pad, reports the absolute X surface position of the center of the touch
  * contact area.	The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * <li>For a mouse, reports the absolute X screen position of the mouse pointer.
  * The units are display pixels.
  * <li>For a trackball, reports the relative horizontal displacement of the trackball.
  * The value is normalized to a range from -1.0 (left) to 1.0 (right).
  * <li>For a joystick, reports the absolute X position of the joystick.
  * The value is normalized to a range from -1.0 (left) to 1.0 (right).
  
  */
#define AXIS_X 										0	
  
  /**
  * Axis constant: Y axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen, reports the absolute Y screen position of the center of
  * the touch contact area.	The units are display pixels.
  * <li>For a touch pad, reports the absolute Y surface position of the center of the touch
  * contact area.	The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * <li>For a mouse, reports the absolute Y screen position of the mouse pointer.
  * The units are display pixels.
  * <li>For a trackball, reports the relative vertical displacement of the trackball.
  * The value is normalized to a range from -1.0 (up) to 1.0 (down).
  * <li>For a joystick, reports the absolute Y position of the joystick.
  * The value is normalized to a range from -1.0 (up or far) to 1.0 (down or near).
  * </ul>
  * </p>
  *
  * @see #getY(int)
  * @see #getHistoricalY(int, int)
  * @see MotionEvent.PointerCoords#y
  * @see InputDevice#getMotionRange
  */
#define AXIS_Y 										1
  
  /**
  * Axis constant: Pressure axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen or touch pad, reports the approximate pressure applied to the surface
  * by a finger or other tool.  The value is normalized to a range from
  * 0 (no pressure at all) to 1 (normal pressure), although values higher than 1
  * may be generated depending on the calibration of the input device.
  * <li>For a trackball, the value is set to 1 if the trackball button is pressed
  * or 0 otherwise.
  * <li>For a mouse, the value is set to 1 if the primary mouse button is pressed
  * or 0 otherwise.
  * </ul>
  * </p>
  *
  * @see #getPressure(int)
  * @see #getHistoricalPressure(int, int)
  * @see MotionEvent.PointerCoords#pressure
  * @see InputDevice#getMotionRange
  */
#define AXIS_PRESSURE 							2
  
  /**
  * Axis constant: Size axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen or touch pad, reports the approximate size of the contact area in
  * relation to the maximum detectable size for the device.	The value is normalized
  * to a range from 0 (smallest detectable size) to 1 (largest detectable size),
  * although it is not a linear scale.  This value is of limited use.
  * To obtain calibrated size information, use
  * {@link #AXIS_TOUCH_MAJOR} or {@link #AXIS_TOOL_MAJOR}.
  * </ul>
  * </p>
  *
  * @see #getSize(int)
  * @see #getHistoricalSize(int, int)
  * @see MotionEvent.PointerCoords#size
  * @see InputDevice#getMotionRange
  */
#define AXIS_SIZE 										3
  
  /**
  * Axis constant: TouchMajor axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen, reports the length of the major axis of an ellipse that
  * represents the touch area at the point of contact.
  * The units are display pixels.
  * <li>For a touch pad, reports the length of the major axis of an ellipse that
  * represents the touch area at the point of contact.
  * The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * </ul>
  * </p>
  *
  * @see #getTouchMajor(int)
  * @see #getHistoricalTouchMajor(int, int)
  * @see MotionEvent.PointerCoords#touchMajor
  * @see InputDevice#getMotionRange
  */
#define AXIS_TOUCH_MAJOR 							4
  
  /**
  * Axis constant: TouchMinor axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen, reports the length of the minor axis of an ellipse that
  * represents the touch area at the point of contact.
  * The units are display pixels.
  * <li>For a touch pad, reports the length of the minor axis of an ellipse that
  * represents the touch area at the point of contact.
  * The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * </ul>
  * </p><p>
  * When the touch is circular, the major and minor axis lengths will be equal to one another.
  * </p>
  *
  * @see #getTouchMinor(int)
  * @see #getHistoricalTouchMinor(int, int)
  * @see MotionEvent.PointerCoords#touchMinor
  * @see InputDevice#getMotionRange
  */
#define AXIS_TOUCH_MINOR 							5
  
  /**
  * Axis constant: ToolMajor axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen, reports the length of the major axis of an ellipse that
  * represents the size of the approaching finger or tool used to make contact.
  * <li>For a touch pad, reports the length of the major axis of an ellipse that
  * represents the size of the approaching finger or tool used to make contact.
  * The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * </ul>
  * </p><p>
  * When the touch is circular, the major and minor axis lengths will be equal to one another.
  * </p><p>
  * The tool size may be larger than the touch size since the tool may not be fully
  * in contact with the touch sensor.
  * </p>
  *
  * @see #getToolMajor(int)
  * @see #getHistoricalToolMajor(int, int)
  * @see MotionEvent.PointerCoords#toolMajor
  * @see InputDevice#getMotionRange
  */
#define AXIS_TOOL_MAJOR 							6
  
  /**
  * Axis constant: ToolMinor axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen, reports the length of the minor axis of an ellipse that
  * represents the size of the approaching finger or tool used to make contact.
  * <li>For a touch pad, reports the length of the minor axis of an ellipse that
  * represents the size of the approaching finger or tool used to make contact.
  * The units are device-dependent; use {@link InputDevice#getMotionRange(int)}
  * to query the effective range of values.
  * </ul>
  * </p><p>
  * When the touch is circular, the major and minor axis lengths will be equal to one another.
  * </p><p>
  * The tool size may be larger than the touch size since the tool may not be fully
  * in contact with the touch sensor.
  * </p>
  *
  * @see #getToolMinor(int)
  * @see #getHistoricalToolMinor(int, int)
  * @see MotionEvent.PointerCoords#toolMinor
  * @see InputDevice#getMotionRange
  */
#define AXIS_TOOL_MINOR 							7
  
  /**
  * Axis constant: Orientation axis of a motion event.
  * <p>
  * <ul>
  * <li>For a touch screen or touch pad, reports the orientation of the finger
  * or tool in radians relative to the vertical plane of the device.
  * An angle of 0 radians indicates that the major axis of contact is oriented
  * upwards, is perfectly circular or is of unknown orientation.  A positive angle
  * indicates that the major axis of contact is oriented to the right.  A negative angle
  * indicates that the major axis of contact is oriented to the left.
  * The full range is from -PI/2 radians (finger pointing fully left) to PI/2 radians
  * (finger pointing fully right).
  * <li>For a stylus, the orientation indicates the direction in which the stylus
  * is pointing in relation to the vertical axis of the current orientation of the screen.
  * The range is from -PI radians to PI radians, where 0 is pointing up,
  * -PI/2 radians is pointing left, -PI or PI radians is pointing down, and PI/2 radians
  * is pointing right.  See also {@link #AXIS_TILT}. 
  * </ul>
  * </p>
  *
  * @see #getOrientation(int)
  * @see #getHistoricalOrientation(int, int)
  * @see MotionEvent.PointerCoords#orientation
  * @see InputDevice#getMotionRange
  */
#define AXIS_ORIENTATION 							8
  
  /**
  * Axis constant: Vertical Scroll axis of a motion event.
  
  * For a mouse, reports the relative movement of the vertical scroll wheel.
  * The value is normalized to a range from -1.0 (down) to 1.0 (up).
  
  * This axis should be used to scroll views vertically.
  
  */
#define AXIS_VSCROLL 							9
  
  /**
  * Axis constant: Horizontal Scroll axis of a motion event.
  * <p>
  * <ul>
  * <li>For a mouse, reports the relative movement of the horizontal scroll wheel.
  * The value is normalized to a range from -1.0 (left) to 1.0 (right).
  * </ul>
  * </p><p>
  * This axis should be used to scroll views horizontally.
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_HSCROLL  							10
  
  /**
  * Axis constant: Z axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute Z position of the joystick.
  * The value is normalized to a range from -1.0 (high) to 1.0 (low).
  * <em>On game pads with two analog joysticks, this axis is often reinterpreted
  * to report the absolute X position of the second joystick instead.</em>
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_Z  										11
  
  /**
  * Axis constant: X Rotation axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute rotation angle about the X axis.
  * The value is normalized to a range from -1.0 (counter-clockwise) to 1.0 (clockwise).
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_RX   									12
  
  /**
  * Axis constant: Y Rotation axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute rotation angle about the Y axis.
  * The value is normalized to a range from -1.0 (counter-clockwise) to 1.0 (clockwise).
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_RY  										13
  
  /**
  * Axis constant: Z Rotation axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute rotation angle about the Z axis.
  * The value is normalized to a range from -1.0 (counter-clockwise) to 1.0 (clockwise).
  * <em>On game pads with two analog joysticks, this axis is often reinterpreted
  * to report the absolute Y position of the second joystick instead.</em>
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_RZ  										14
  
  /**
  * Axis constant: Hat X axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute X position of the directional hat control.
  * The value is normalized to a range from -1.0 (left) to 1.0 (right).
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_HAT_X  								15
  
  /**
  * Axis constant: Hat Y axis of a motion event.
  * <p>
  * <ul>
  * <li>For a joystick, reports the absolute Y position of the directional hat control.
  * The value is normalized to a range from -1.0 (up) to 1.0 (down).
  * </ul>
  * </p>
  *
  * @see #getAxisValue(int, int)
  * @see #getHistoricalAxisValue(int, int, int)
  * @see MotionEvent.PointerCoords#getAxisValue(int)
  * @see InputDevice#getMotionRange
  */
#define AXIS_HAT_Y  								16
  
/**
* Axis constant: Left Trigger axis of a motion event.
* <p>
* <ul>
* <li>For a joystick, reports the absolute position of the left trigger control.
* The value is normalized to a range from 0.0 (released) to 1.0 (fully pressed).
* </ul>
* </p>
*
* @see #getAxisValue(int, int)
* @see #getHistoricalAxisValue(int, int, int)
* @see MotionEvent.PointerCoords#getAxisValue(int)
* @see InputDevice#getMotionRange
*/
#define AXIS_LTRIGGER  							17
  
/**
* Axis constant: Right Trigger axis of a motion event.
* <p>
* <ul>
* <li>For a joystick, reports the absolute position of the right trigger control.
* The value is normalized to a range from 0.0 (released) to 1.0 (fully pressed).
* </ul>
* </p>
*
* @see #getAxisValue(int, int)
* @see #getHistoricalAxisValue(int, int, int)
* @see MotionEvent.PointerCoords#getAxisValue(int)
* @see InputDevice#getMotionRange
*/
#define AXIS_RTRIGGER  							18
  
/**
* Axis constant: Throttle axis of a motion event.
* <p>
* <ul>
* <li>For a joystick, reports the absolute position of the throttle control.
* The value is normalized to a range from 0.0 (fully open) to 1.0 (fully closed).
* </ul>
* </p>
*
* @see #getAxisValue(int, int)
* @see #getHistoricalAxisValue(int, int, int)
* @see MotionEvent.PointerCoords#getAxisValue(int)
* @see InputDevice#getMotionRange
*/
#define AXIS_THROTTLE  							19
  
/**
* Axis constant: Rudder axis of a motion event.
* <p>
* <ul>
* <li>For a joystick, reports the absolute position of the rudder control.
* The value is normalized to a range from -1.0 (turn left) to 1.0 (turn right).
* </ul>
* </p>
*
* @see #getAxisValue(int, int)
* @see #getHistoricalAxisValue(int, int, int)
* @see MotionEvent.PointerCoords#getAxisValue(int)
* @see InputDevice#getMotionRange
*/
#define AXIS_RUDDER  								20
  
/**
* Axis constant: Wheel axis of a motion event.
* <p>
* <ul>
* <li>For a joystick, reports the absolute position of the steering wheel control.
* The value is normalized to a range from -1.0 (turn left) to 1.0 (turn right).
* </ul>
* </p>
*
* @see #getAxisValue(int, int)
* @see #getHistoricalAxisValue(int, int, int)
* @see MotionEvent.PointerCoords#getAxisValue(int)
* @see InputDevice#getMotionRange
*/
#define AXIS_WHEEL   							 	21
  
/**
* Axis constant: Gas axis of a motion event.
* <li>For a joystick, reports the absolute position of the gas (accelerator) control.
* The value is normalized to a range from 0.0 (no acceleration)
* to 1.0 (maximum acceleration).
*/
#define AXIS_GAS   									22

/**
* Axis constant: Brake axis of a motion event.
* For a joystick, reports the absolute position of the brake control.
* The value is normalized to a range from 0.0 (no braking) to 1.0 (maximum braking).
*/
#define AXIS_BRAKE  								23

/**
* Axis constant: Distance axis of a motion event.
* For a stylus, reports the distance of the stylus from the screen.
* A value of 0.0 indicates direct contact and larger values indicate increasing
* distance from the surface.
*/
#define AXIS_DISTANCE  							24
  
  
  
/*
Mech	report finger information & one finger data pointer
*/
#define mech_xy_Info_t														iqs5xx_xy_Info_byte
#define mech_finger_pointer_t 										iqs5xx_point_t


  
//****************************************************************************
// strcut
//****************************************************************************/



#pragma anon_unions
//////////////////////////////////////////////////
/// \struct touch_finger_info_t
/// Touch finger information struct
//////////////////////////////////////////////////

typedef struct{
  uint32_t Cnt;
	uint16_t Xpos[FINGER_POISION_LAST_LEN];
  uint16_t Ypos[FINGER_POISION_LAST_LEN];
	uint16_t UpXpos;
  uint16_t UpYpos;
  uint8_t Index;
	uint8_t use_idx;
	uint8_t last_idx;
	/*
	Touch finger information struct
	Singlefingre and multifinger delay conut and motion message
	*/
	union{
		uint16_t fState;
		struct{
			uint8_t finger_en												: 	1;	/// \var finger_en: 0 disable 1 enable 
			uint8_t finger_updata										: 	1;	/// \var finger_updata: 
			uint8_t finger_state 										: 	3;	/// \var state :   0 nokey  1 down 2 pressed  3 up
			uint8_t reserve 												: 	1;	/// \var state 
			};
  };

  //mech_finger_pointer_t *fPointer;
  //touch_motion_u fMotion;
  //
}touch_finger_info_t;


//////////////////////////////////////////////////
/// \struct touch_finger_message_t
/// Touch finger message struct
//////////////////////////////////////////////////

typedef struct{
	uint8_t fType;				/// \var fType : 1 single finger >1 multifinger
	touch_finger_info_t SFI[SUPPORT_FINGER_NUM];
	//touch_finger_info_t *SFIP[SUPPORT_FINGER_NUM];
	//touch_motion_api_t fMotionApi[SUPPORT_FINGER_NUM];
}touch_finger_message_t; 

//////////////////////////////////////////////////
/// \def NO_FINGER
/// major finger state
//////////////////////////////////////////////////
#define NO_FINGER								0x00
#define FIRST_DOWN							0x01
#define FIRST_UP  							0x02
#define DRAG_DOWN						 		0x03

//////////////////////////////////////////////////
/// \struct set_meg_t
/// set finger messger
//////////////////////////////////////////////////
typedef struct{


	uint32_t minor_down_time;		/// \var last_minor_time : last event time  


	uint32_t last_minor_time;		/// \var last_minor_time : last event time  
}set_meg_t;

  
//////////////////////////////////////////////////
/// \struct set_meg_t
/// set finger messger
//////////////////////////////////////////////////
typedef struct{
	int16_t His_x[HIS_LEN];				/// \var	
	int16_t His_y[HIS_LEN]; 			/// \var	
	int16_t Last_x;
	int16_t Last_y;
	int16_t Dlt_x;
	int16_t Dlt_y;
	uint16_t MoveThres;
	//union{
		//uint16_t MajorState;
		struct{
			uint8_t moved 													: 	1;	/// \var 
			uint8_t moving 													: 	1;	/// \var 
			uint8_t reserve 												: 	1;	/// \var reserve 
			};

	uint8_t index;				/// \var  
	uint8_t average_cnt;
	uint32_t finger_down_time;		/// \var last_major_timer : last event time  
	uint32_t last_finger_time;		/// \var last_major_timer : last event time  

}motion_finger_move_t;


	

//////////////////////////////////////////////////
/// \struct motion_message_t
/// motion messger
//////////////////////////////////////////////////
typedef struct{
  
  union{
    uint16_t mAction;
    struct{
      uint8_t Action;
      uint8_t mPointer;
    };
    
  };
  /*
  motion information struct
  */
  struct{
    int16_t x;
    int16_t y;
    uint16_t pressure;
    uint16_t size;
    int16_t touchMajor;
    int16_t touchMinor;
    int16_t toolMajor;
    int16_t toolMinor;
    int16_t orientation;
    int16_t hscroll;
    int16_t vscroll;
  };
  
  struct {
    uint16_t ButtonFlags;
    uint16_t ButtonData;
  };
	int16_t mPointer_x[4];
	int16_t mPointer_y[4];

}motion_message_t; 

//////////////////////////////////////////////////
/// \def function pointer
//////////////////////////////////////////////////
// typedef uint8_t (*U8FPTR_SPTR_SPTR)(mech_xy_Info_t *a,touch_finger_info_t *b);
//typedef uint8_t (*U8FPTR_ARGV)(void *argv[]);
typedef uint8_t (*U8FPTR_V)(void); 
typedef void	(*VFPTR_V)(void); 

//////////////////////////////////////////////////
/// \struct motion_t
/// motion struct
//////////////////////////////////////////////////
typedef struct{
	//U8FPTR_SPTR_SPTR whichFingerIs;	
	U8FPTR_V whichFingerIs;
	U8FPTR_V doFinger;
	VFPTR_V motion;
	//U8FPTR_ARGV MotionEvent;
	motion_message_t MotionMsg;
}motion_t; 


//****************************************************************************
// variable declared
//****************************************************************************/
extern motion_t Motion;

//****************************************************************************
// function declared
//****************************************************************************/
void MotionEventInit(void);
void MotionEvent(void);
int16_t getAxisValue(int16_t axis);
void setAxisValue(int16_t axis, int16_t value);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif


#endif 

