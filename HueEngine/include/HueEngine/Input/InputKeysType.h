#pragma once

enum class EKey
{
	_0 = 48,
	_1,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	A = 65,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	Escape = 256,
	Left_Shift = 340,
	Right_Shift = 344,
	Space = 259,
	Enter = 257,
	Tab = 258,
};

enum class EMouseButton
{
	Left = 0,
	Middle,
	Right
};

enum class EJoystickButton
{
	BUTTON_A = 0,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_LEFT_BUMPER,
	BUTTON_RIGHT_BUMPER,
	BUTTON_BACK,
	BUTTON_START,
	BUTTON_GUIDE,
	BUTTON_LEFT_THUMB,
	BUTTON_RIGHT_THUMB,
	BUTTON_DPAD_UP,
	BUTTON_DPAD_RIGHT,
	BUTTON_DPAD_DOWN,
	BUTTON_DPAD_LEFT,
};

enum class EJoystickAxis
{
	AXIS_LEFT_X = 0,
	AXIS_LEFT_Y,
	AXIS_RIGHT_X,
	AXIS_RIGHT_Y,
	AXIS_LEFT_TRIGGER,
	AXIS_RIGHT_TRIGGER,
	AXIS_LAST
};