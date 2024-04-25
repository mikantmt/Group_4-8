#include "DxLib.h"
#include "Screen.h"

void Screen::StepScreen(float x, float y)
{
	//スクリーン座標を設定
	if(x > 160)
	screenX = x - (float)SCREEN_SIZE_X / 8;
}

float Screen::GetScreenX()
{
	return screenX;
}

float Screen::GetScreenY()
{
	return screenY;
}
