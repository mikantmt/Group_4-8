#include "DxLib.h"
#include "Screen.h"

void Screen::StepScreen(float x, float y)
{
	//�X�N���[�����W��ݒ�
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
