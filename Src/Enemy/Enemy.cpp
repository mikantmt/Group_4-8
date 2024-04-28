#include "EnemyBase.h"

void EnemyBase::Init() {
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].Handle = LoadGraph(EnemyPath[FLY_ENEMY]);

		Fly[FlyIndex].EnemyX = random.ScopingRand(25.0f* (float)MAPCIP_X_SIZE, (float)(MAPCIP_X_MAXNUM * MAPCIP_X_SIZE));
		Fly[FlyIndex].EnemyY = 128;

		Fly[FlyIndex].EnemySaveX = Fly[FlyIndex].EnemyX;
		Fly[FlyIndex].EnemySaveY = Fly[FlyIndex].EnemyY;

		Fly[FlyIndex].IsActive = false;
		Fly[FlyIndex].FlipFlg  = false;
		Fly[FlyIndex].DetecFlg = false;

		Fly[FlyIndex].SetSpace(Fly[FlyIndex].EnemyX);
		Fly[FlyIndex].PlayerHide = false;
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].Handle = LoadGraph(EnemyPath[GROUND_ENEMY]);

		Ground[GroundIndex].EnemyX = random.ScopingRand(10.0f * (float)MAPCIP_X_SIZE, (float)(MAPCIP_X_MAXNUM * MAPCIP_X_SIZE));
		Ground[GroundIndex].EnemyY = 100;

		Ground[GroundIndex].EnemySaveX = Ground[GroundIndex].EnemyX;
		Ground[GroundIndex].EnemySaveY = Ground[GroundIndex].EnemyY;
		Ground[GroundIndex].YSpeed = 0.0f;

		Ground[GroundIndex].FlipFlg = false;
		Ground[GroundIndex].DetecFlg = false;

		Ground[GroundIndex].SetSpace(Ground[GroundIndex].EnemyX);
	}
}

void EnemyBase::Step(float X,float Y,bool hide) {

	//���̓G
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].FlipPlus();//���]�؂�ւ�
		Fly[FlyIndex].FindPlayer(X,10);//�v���C���[��T��
		Fly[FlyIndex].GetHide(hide);
		
		if (!Fly[FlyIndex].DetecFlg) {//�v���C���[�𔭌����Ă��Ȃ����
			if (!Fly[FlyIndex].FlipFlg) {//���]������
				Fly[FlyIndex].EnemySaveX--;
			}
			else {
				Fly[FlyIndex].EnemySaveX++;
			}
		}
		else {//�v���C���[�𔭌����Ă����
			if (Fly[FlyIndex].PlayerHide) {//�v���C���[���B��Ă���Γ�����
				if (Fly[FlyIndex].FlipFlg) {//���]������
					Fly[FlyIndex].EnemySaveX--;
				}
				else {
					Fly[FlyIndex].EnemySaveX++;
				}
			}
		}
	}

	//����̓G
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].YSpeed += MOVE_YSPEED;
		Ground[GroundIndex].EnemySaveY += Ground[GroundIndex].YSpeed;
		Ground[GroundIndex].FlipMinus();
		Ground[GroundIndex].FindPlayer(X,7);//�v���C���[��T��
		if (!Ground[GroundIndex].DetecFlg) {//�v���C���[�𔭌����Ă��Ȃ����
			
		}
		else {//�������Ă����
			if (!Ground[GroundIndex].FlipFlg) {
				Ground[GroundIndex].EnemySaveX -= 3;
			}
			else
				Ground[GroundIndex].EnemySaveX += 3;
		}
	}
}

void EnemyBase::Draw(int X) {
	//���
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		DrawGraph(Fly[FlyIndex].EnemyX - X, Fly[FlyIndex].EnemyY, Fly[FlyIndex].Handle, true);
	}
	//����
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		DrawGraph(Ground[GroundIndex].EnemyX - X, Ground[GroundIndex].EnemyY, Ground[GroundIndex].Handle, true);
	}
}

void EnemyBase::Enemy::SetSaveX(float EnemyX) {
	EnemySaveX = EnemyX;
}

void EnemyBase::Enemy::SetSaveY(float EnemyY) {
	EnemySaveY = EnemyY;
}

void EnemyBase::Enemy::GetMoveDirection(bool* dirArray) {
	if (EnemySaveY < EnemyY) {
		dirArray[0] = true;
	}
	if (EnemySaveY > EnemyY) {
		dirArray[1] = true;
	}
	if (EnemySaveX < EnemyX) {
		dirArray[2] = true;
	}
	if (EnemySaveX > EnemyX) {
		dirArray[3] = true;
	}
}

void EnemyBase::Enemy::SetSpace(float X) {
	SpaceMinX = X - MOVE_RANGE;
	SpaceMaxX = X + MOVE_RANGE;
}

void EnemyBase::Enemy::FlipPlus() {
	if (SpaceMinX > GetPosX()) {
		FlipFlg = false;
	}
	if (SpaceMaxX < GetPosX()) {
		FlipFlg = true;
	}
}

void EnemyBase::Enemy::FlipMinus() {
	if (SpaceMinX > GetPosX()) {
		FlipFlg = true;
	}
	if (SpaceMaxX < GetPosX()) {
		FlipFlg = false;
	}
}

void EnemyBase::Enemy::FindPlayer(float X,float Scale) {
	if (EnemyX + MAPCIP_X_SIZE * Scale > X && EnemyX - MAPCIP_X_SIZE * Scale < X) {
		DetecFlg = true;
	}
	else
		DetecFlg = false;
}

void  EnemyBase::Enemy::GetHide(bool hide) {
	PlayerHide = hide;
}

void EnemyBase::MapToEnemyY(int X, int Y) {
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {

		bool dirArray[4] = { false,false,false,false };
		Ground[GroundIndex].GetMoveDirection(dirArray);

		// ���������l����
		// ��`�̓����蔻��p�̃f�[�^������
		// �v���C���[�̏��
		float Ax = Ground[GroundIndex].GetPosX();
		float Ay = Ground[GroundIndex].GetPosY();
		float Aw = 32;
		float Ah = 32;

		// �I�u�W�F�N�g�̏��
		int Bx = X * MAPCIP_X_SIZE;
		int By = Y * MAPCIP_Y_SIZE;
		int Bw = MAP_SIZE;
		int Bh = MAP_SIZE;

		// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
		Ay = Ground[GroundIndex].GetSavePosY();
		Ax = Ground[GroundIndex].GetPosX();

		// �������Ă��邩�`�F�b�N
		if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
			// ������̏C��
			if (dirArray[0]) {
				// ���������l����
				// �߂荞�ݗʂ��v�Z����
				float overlap = By + Bh - Ay;
				Ground[GroundIndex].SetSaveY(Ay + overlap);
			}

			// �������̏C��
			if (dirArray[1]) {
				// ���������l����
				// �߂荞�ݗʂ��v�Z����
				float overlap = Ay + Ah - By;
				Ground[GroundIndex].SetSaveY(Ay - overlap);
				Ground[GroundIndex].YSpeed = 0.0f;
			}
		}
	}
}

void EnemyBase::MapToEnemyX(int X, int Y) {
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {

		bool dirArray[4] = { false,false,false,false };
		Ground[GroundIndex].GetMoveDirection(dirArray);

		// ���������l����
		// ��`�̓����蔻��p�̃f�[�^������
		// �v���C���[�̏��
		float Ax = Ground[GroundIndex].GetPosX();
		float Ay = Ground[GroundIndex].GetPosY();
		float Aw = 32;
		float Ah = 32;

		// �I�u�W�F�N�g�̏��
		int Bx = X * MAPCIP_X_SIZE;
		int By = Y * MAPCIP_Y_SIZE;
		int Bw = MAP_SIZE;
		int Bh = MAP_SIZE;

		// ��Y�����݂̂Ɉړ������Ɖ��肵�����W�œ����蔻����`�F�b�N���܂�
		Ay = Ground[GroundIndex].GetSavePosY();
		Ax = Ground[GroundIndex].GetSavePosX();

		// �������Ă��邩�`�F�b�N
		if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
			// ������̏C��
			if (dirArray[2]) {
				// ���������l����
				// �߂荞�ݗʂ��v�Z����
				float overlap = Bx + Bw - Ax;
				Ground[GroundIndex].SetSaveX(Ax + overlap);
			}

			// �������̏C��
			if (dirArray[3]) {
				// ���������l����
				// �߂荞�ݗʂ��v�Z����
				float overlap = Ax + Aw - Bx;
				Ground[GroundIndex].SetSaveX(Ax - overlap);
			}
		}
	}
}

void EnemyBase::Update(){
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].EnemyX = Fly[FlyIndex].EnemySaveX;
		Fly[FlyIndex].EnemyY = Fly[FlyIndex].EnemySaveY;
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].EnemyX = Ground[GroundIndex].EnemySaveX;
		Ground[GroundIndex].EnemyY = Ground[GroundIndex].EnemySaveY;
	}
}