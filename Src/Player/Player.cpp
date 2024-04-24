#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

//�E�B���h�E�T�C�Y��ݒ�
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//�v���C���[�摜�p�X
#define PLAYER_PATH "Data/Player/player.h"

#define GRAVITY (0.5f)	//�d�͉����x

Input input;

//�R���X�g���N�^
Player::Player() {
	
}

//�f�X�g���N�^
Player::~Player() {}

//������
void Player::Init() {
	playerHan = LoadGraph(PLAYER_PATH);
}

//�ʏ폈��
void Player::Step() {
	//�v���C���[���E�ړ�����
	if (input.IsKeyPush(KEY_INPUT_D)) {
		player_x++;
	}
	else if (input.IsKeyPush(KEY_INPUT_A)) {
		player_x--;
	}

	//�X�y�[�X�L�[�������ꂽ��W�����v
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
	}

	//�d�͂�^����
	isUp = false;
	Yspeed += GRAVITY;
	player_y += Yspeed;
}

//�`��
void Player::Draw() {
	//�v���C���[��`��
	DrawGraph(player_x, player_y, playerHan, true);
}

//�I��
void Player::Fin() {

}