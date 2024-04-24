#include "SceneResult.h"

void cResult::Init()
{
	// タイトルのループ処理へ遷移
}

void cResult::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cResult::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "リザルト");
}

void cResult::Fin()
{
	// プレイシーンに遷移
	cScene::SceneID = SCENE_ID::SCENE_ID_TITLE;
	
}