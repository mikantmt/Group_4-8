#include "DxLib.h"
#include "Player.h"

//ウィンドウサイズを設定
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//プレイヤー画像パス
#define PLAYER_PATH "Data/Player/player.h"

//コンストラクタ
Player::Player() {
	
}

//デストラクタ
Player::~Player() {}

//初期化
void Player::Init() {
	playerHan = LoadGraph(PLAYER_PATH);
}

//通常処理
void Player::Step() {

}

//描画
void Player::Draw() {
	//プレイヤーを描画
	DrawGraph(player_x, player_y, playerHan, true);
}

//終了
void Player::Fin() {

}