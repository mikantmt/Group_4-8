#pragma once
#include "../Collision/Collision.h"
#include "../Input/Input.h"
#include "../Sound/Sound.h"
#include "../Score/Score.h"
#include "../Player/Player.h"
//清水
enum SCENE_TYPE
{
	//シーンのID
	TYPE_ID_INIT = 100,	//初期化

	TYPE_ID_LOOP = 200,	//ループ

	TYPE_ID_FIN = 300,	//終了
};

enum SCENE_ID
{
	//シーンのID
	SCENE_ID_TITLE = 100,	//タイトル

	SCENE_ID_SELECT = 200,	//セレクト

	SCENE_ID_PLAY = 300,	//プレイ

	SCENE_ID_RESULT = 400,	//リザルト
};

class cSceneBase {
private:
public:
	Collision collision;
	Sound sound;
	Input input;
	Score score;
	Player player;

	virtual void Init() = 0;
	virtual void Step() = 0;
	virtual void Draw() = 0;
	virtual void Fin() = 0;
};