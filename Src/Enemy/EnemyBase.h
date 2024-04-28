#pragma once
#include "../Collision/Collision.h"
#include "../Mapchip/MapChip.h"
#include "../Random/Random.h"
#include "../Mapchip/MapChip.h"
#include "../Player/Player.h"

const int FLY_MAX_NUM	 = 10;	//�����ɑ��݂ł���G�̐�
const int GROUND_MAX_NUM = 10;	//�����ɑ��݂ł���G�̐�

const float MOVE_RANGE = 240.0f;//�G�̈ړ��͈�

const float MOVE_SPEED  = 2.5f;	//�G�̈ړ��X�s�[�h
const float MOVE_YSPEED = 0.3f;

class EnemyBase {
private:

	enum ENEMY_TYPE {
		FLY_ENEMY,		//���̓G
		GROUND_ENEMY,	//����̓G

		ENEMY_EYPE_NUM, //�G�̎�ނ̐�
	};

	const char EnemyPath[ENEMY_EYPE_NUM][256]{
		"Data/Enemy/Fly.png",
		"Data/Enemy/Ground.png",
	};

	//����̓����_�������Ȃ̂Ŏg��Ȃ�
	//const float EnemyPos[ENEMY_EYPE_NUM][3][2] = {
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//���̍��W�̐ݒ�
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//����̍��W�̐ݒ�
	//};

	Collision collision;
	MapChip	  mapchip;
	Random	  random;
	Player	  player;

public:

	class Enemy {
	private:
		
	public:
		int	  Handle;		//�摜�n���h��
		float EnemyX;		//�GX���W
		float EnemyY;		//�GY���W
		float EnemySaveX;	//�GX���W�ۑ��p
		float EnemySaveY;	//�GY���W�ۑ��p

		float YSpeed;		//�����X�s�[�h

		float SpaceMinX;	//�G�̈ړ���
		float SpaceMaxX;	//�G�̈ړ���

		bool IsActive;		//�����t���O(�����l��false)
		bool FlipFlg;		//���]�t���O(�����l��false)

		bool DetecFlg;		//�v���C���[�����t���O(�����l��false)
		bool PlayerHide;	//�v���C���[���B��Ă��邩

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

		//�ړ�����ݒ�
		void SetSpace(float X);	

		void FlipPlus();	//�G�̐܂�Ԃ��t���O��؂�ւ���(�v���X������)
		void FlipMinus();	//�G�̐܂�Ԃ��t���O��؂�ւ���(�}�C�i�X������)

		//�G�̍��W����w��͈̓}�X�ȓ��ɂ����甭�����ꂽ���ƂɂȂ�
		void FindPlayer(float X, float Scale); 

		//Hide���擾
		void GetHide(bool hide);
	};

	Enemy Fly	[FLY_MAX_NUM];	  //���̓G�錾
	Enemy Ground[GROUND_MAX_NUM]; //����̓G�錾

	void Init();
	void Step(float X, float Y, bool hide);
	void Draw(int X);

	void MapToEnemyX(int X,int Y);
	void MapToEnemyY(int X, int Y);

	void Fin();

	// ���W���X�V
	void Update();
};