#include "SceneResult.h"

void cResult::Init()
{
	// タイトルのループ処理へ遷移
}

void cResult::Step()
{
	score.Update();
	score.Read();

	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cResult::Draw()
{
	SetFontSize(64);
	DrawFormatString(MID_SCREEN_X - 32, MID_SCREEN_Y - 32, GetColor(255, 255, 255), "%.f", score.ScoreNum);
	SetFontSize(16);
}

void cResult::Fin()
{
	// プレイシーンに遷移
	cScene::SceneID = SCENE_ID::SCENE_ID_TITLE;
	
}