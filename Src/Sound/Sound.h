#pragma once
#include "DxLib.h"

//�T�E���h�̎��
enum SOUND_TYPE
{
	TITLE,

	SOUND_TYPE_NUM,
};

class Sound {
private:

	//�T�E���h�̃t�@�C���p�X
	const char SoundPath[SOUND_TYPE_NUM][256] =
	{
		"Data/Sound/Title.mp3"
	};

	int Sound[SOUND_TYPE_NUM];

public:
	//LOOP�̎���Init,Step�𓯎��ɌĂ�
	void Init();
	//�T�E���h�Đ�(�T�E���h�̎��,
	//�Đ��^�C�v(�m�[�}��,�o�b�N�O���E���h,���[�v),����(%))
	void Step(SOUND_TYPE sound, int playtype,int volume);
	void Fin();
};