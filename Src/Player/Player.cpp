#include "DxLib.h"
#include "Player.h"

//�E�B���h�E�T�C�Y��ݒ�
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//�v���C���[�摜�p�X
#define PLAYER_PATH "Data/Player/player.h"

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

}

//�`��
void Player::Draw() {
	//�v���C���[��`��
	DrawGraph(player_x, player_y, playerHan, true);
}

//�I��
void Player::Fin() {

}