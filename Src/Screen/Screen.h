#pragma once
#include "../Common.h"

class Screen {
private:
	//�X�N���[���̃��[���h���W
	float screenX = 0.0f;
	float screenY = 0.0f;

public:
	// �X�N���[���̃X�e�b�v
	// �����v���C���[X���W�AY���W
	void StepScreen(float x, float y);

	//�X�N���[���̂w���W���擾
	float GetScreenX();

	//�X�N���[���̂x���W���擾
	float GetScreenY();
};