#include "SceneResult.h"

void cResult::Init()
{
	// タイトルのループ処理へ遷移
	g_CurrentSceneId = SCENE_ID_LOOP_RESULT;
}

void cResult::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		g_CurrentSceneId = SCENE_ID_FIN_RESULT;
	}
}

void cResult::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "リザルト");
}

void cResult::Fin()
{
	// プレイシーンに遷移
	g_CurrentSceneId = SCENE_ID_INIT_TITLE;
	
}