#include "ScenePlay.h"

void cPlay::Init()
{
	sound.Init();
	player.Init();

	g_CurrentSceneId = SCENE_ID_LOOP_PLAY;
}

void cPlay::Step()
{
	player.Step();

	if(input.IsKeyPush(KEY_INPUT_SPACE)) {
		g_CurrentSceneId = SCENE_ID_FIN_PLAY;
	}
}

void cPlay::Draw()
{
	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(255, 255, 255), "ƒvƒŒƒC");

	player.Draw();
}

void cPlay::Fin()
{
	sound.Fin();
	player.Fin();
	
	g_CurrentSceneId = SCENE_ID_INIT_RESULT;
}