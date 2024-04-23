#pragma once
#include "DxLib.h"

class Input {
public:
	// ���͐��䏉����
	void InitInput();

	// ���͐���X�e�b�v
	// ����Step��葁���Ă�
	void StepInput();

	// �������ꂽ
	bool IsKeyPush(int key_code);

	//�����ꑱ���Ă���
	bool IsKeyKeep(int key_code);

	//�������������ꂽ��
	bool IsKeyRelease(int key_code);

	//�P���ɉ�����Ă��邩
	bool IsButtonDown(int key_code);
};
