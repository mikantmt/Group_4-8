#pragma once
#include "DxLib.h"

class Random {
public:
	//�����Ə����ݒ肵,�w��͈͂��痐�����擾����֐�
	//����(����,���)
	float ScopingRand(float min, float max);

	//�����Ə����ݒ�,����ɂ��͈̔͂���擾�������Ȃ��͈͂�ݒ肵�w��͈͂��痐�����擾����֐�
	//����(����,���,���O�͈͂̉���,���O�͈͂̏��)
	float OutRand(float min, float max, float out_min, float out_max);
};