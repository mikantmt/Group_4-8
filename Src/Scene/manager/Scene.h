#pragma once
#include "DxLib.h"
#include "../../Common.h"
#include "../../Collision/Collision.h"
#include "../../Input/Input.h"
#include "../../Sound/Sound.h"

enum SCENE_ID
{
	// タイトルシーンのID
	SCENE_ID_INIT_TITLE = 100,	// 初期化
	SCENE_ID_LOOP_TITLE,		// ループ
	SCENE_ID_FIN_TITLE,			// 終了

	// シーンの情報
	SCENE_ID_INIT_SELECT = 200,	// 初期化
	SCENE_ID_LOOP_SELECT,			// ループ
	SCENE_ID_FIN_SELECT,			// 終了

	// シーンの情報
	SCENE_ID_INIT_PLAY = 300,	// 初期化
	SCENE_ID_LOOP_PLAY,			// ループ
	SCENE_ID_FIN_PLAY,			// 終了

	// シーンの情報
	SCENE_ID_INIT_RESULT = 400,	// 初期化
	SCENE_ID_LOOP_RESULT,		// ループ
	SCENE_ID_FIN_RESULT,		// 終了
};

class cScene {
	public:
		Collision collision;
		Sound sound;
		Input input;

		virtual void Init() = 0;
		virtual void Step() = 0;
		virtual void Draw() = 0;
		virtual void Fin()  = 0;

		int BackGroundHandle;
};

//　現在のシーンID
extern SCENE_ID g_CurrentSceneId;