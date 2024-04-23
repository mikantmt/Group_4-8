#include "SceneTitle.h"

void cTitle::Init()
{
	collision.Init();

	sound.Init();
	
	g_CurrentSceneId = SCENE_ID_LOOP_TITLE;
}

void cTitle::Step()
{
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		g_CurrentSceneId = SCENE_ID_FIN_TITLE;
	}
}

void cTitle::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "ƒ^ƒCƒgƒ‹");
}

void cTitle::Fin()
{
	sound.Fin();

	g_CurrentSceneId = SCENE_ID_INIT_PLAY;
}