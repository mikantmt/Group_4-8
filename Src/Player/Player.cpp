#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

//�E�B���h�E�T�C�Y��ݒ�
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//�v���C���[�摜�p�X
#define PLAYER_PATH "Data/Player/player.png"

#define GRAVITY (0.3f)	//�d�͉����x

Input input;

//�R���X�g���N�^
Player::Player() {
	
}

//�f�X�g���N�^
Player::~Player() {}

//������
void Player::Init() {
	playerHan = LoadGraph(PLAYER_PATH);

	ActiveFlg = false;
	IsHide = false;
}

//�ʏ폈��
void Player::Step() {
	playerNext_x = player_x;
	playerNext_y = player_y;

	IsHide = false;

	//�v���C���[���E�ړ�����
	if (input.IsKeyKeep(KEY_INPUT_D)) {
		playerNext_x += 3;
	}
	else if (input.IsKeyKeep(KEY_INPUT_A)) {
		playerNext_x -= 3;
	}

	//�X�y�[�X�L�[�������ꂽ��W�����v
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
	}

	//�d�͂�^����
	isUp = false;
	Yspeed += GRAVITY;
	playerNext_y += Yspeed;
}

//�`��
void Player::Draw(int X) {
	//�v���C���[��`��
	DrawGraph(player_x - X, player_y, playerHan, true);
}

//�I��
void Player::Fin() {

}

void Player::SetNextPosX(int _posX) {
	playerNext_x = (float)_posX;
}

void Player::SetNextPosY(int _posY) {
	playerNext_y = (float)_posY;
}

void Player::UpdatePos() {
	player_x = playerNext_x;
	player_y = playerNext_y;
}

void Player::GetMoveDirection(bool* _dirArray) {
	// �E�����̃`�F�b�N
	if (playerNext_x > player_x) {
		_dirArray[3] = true;
	}

	// �������̃`�F�b�N
	if (playerNext_x < player_x) {
		_dirArray[2] = true;
	}

	// �������̃`�F�b�N
	if (playerNext_y > player_y) {
		_dirArray[1] = true;
	}

	// ������̃`�F�b�N
	if (playerNext_y < player_y) {
		_dirArray[0] = true;
	}
}


