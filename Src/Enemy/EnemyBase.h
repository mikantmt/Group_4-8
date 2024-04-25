#pragma once
#include "../Collision/Collision.h"
#include "../Random/Random.h"
#include "../Mapchip/MapChip.h"

const int FLY_MAX_NUM	 = 10;	//�����ɑ��݂ł���G�̐�
const int GROUND_MAX_NUM = 10;	//�����ɑ��݂ł���G�̐�

const float MOVE_RANGE = 240.0f;//�G�̈ړ��͈�

const float MOVE_SPEED = 2.5f;	//�G�̈ړ��X�s�[�h

class EnemyBase {
private:

	enum ENEMY_TYPE {
		FLY_ENEMY,		//���̓G
		GROUND_ENEMY,	//����̓G

		ENEMY_EYPE_NUM, //�G�̎�ނ̐�
	};

	const char EnemyPath[ENEMY_EYPE_NUM][256]{
		"Data/Enemy/Fly.png",
		"Data/",
	};

	//����̓����_�������Ȃ̂Ŏg��Ȃ�
	//const float EnemyPos[ENEMY_EYPE_NUM][3][2] = {
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//���̍��W�̐ݒ�
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//����̍��W�̐ݒ�
	//};

	Collision collision;
	Random	  random;

public:

	class Enemy {
	private:
		
	public:
		int	  Handle;		//�摜�n���h��
		float EnemyX;		//�GX���W
		float EnemyY;		//�GY���W
		float EnemySaveX;	//�GX���W�ۑ��p
		float EnemySaveY;	//�GY���W�ۑ��p

		float SpaceMinX;	//�G�̈ړ���
		float SpaceMaxX;	//�G�̈ړ���

		bool IsActive;		//�����t���O(�����l��false)
		bool FlipFlg;		//���]�t���O(�����l��false)

		bool DetecFlg;		//�v���C���[�����t���O(�����l��false)

		//���W�擾
		float GetPosX()		{ return EnemyX; }
		float GetPosY()		{ return EnemyY; }
		float GetSavePosX() { return EnemySaveX; }
		float GetSavePosY() { return EnemySaveY; }
		
		//���W�ݒ�
		void SetSaveX(float EnemyX);
		void SetSaveY(float EnemyY);

		//�i��ł���������`�F�b�N
		void GetMoveDirection(bool* dirArray);

		void SetSpace(float X);	//�ړ�����ݒ�

		void Flip();			//�G�̐܂�Ԃ��t���O��؂�ւ���

		//�G�̍��W����10�}�X�ȓ��ɂ����甭�����ꂽ���ƂɂȂ�
		void FindPlayer(float X);
	};

	Enemy Fly	[FLY_MAX_NUM];	  //���̓G�錾
	Enemy Ground[GROUND_MAX_NUM]; //����̓G�錾

	void Init();
	void Step(float X);
	void Draw(int X);
	void Fin();

	// ���W���X�V
	void Update();
};