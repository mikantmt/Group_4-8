#pragma once
#include "DxLib.h"

class Score {
public:
	static FILE* fScore;		//�Ǎ��p�̕ϐ�

	static float ScoreNum;		// �X�R�A�̒l
	static float HighScoreNum;	// �n�C�X�R�A�̒l

	static void Init();		//�X�R�A������
	static void Reset();	//�Q�[�����ɍō��X�R�A�����Z�b�g�ł���
	//���_���X�R�A�ɉ��Z
	static void Add(float AddScoreNum);
	static void Update();	//�X�R�A���n�C�X�R�A��荂�����csv�ɕۑ�
	static void Read();		//�n�C�X�R�A��ǂݍ���
};
