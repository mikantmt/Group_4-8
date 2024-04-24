#include "ScenePlay.h"

void cPlay::Init()
{
	sound.Init();
	player.Init();
}

void cPlay::Step()
{
	player.Step();

	if(input.IsKeyPush(KEY_INPUT_SPACE)) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
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
	
	cScene::SceneID = SCENE_ID::SCENE_ID_RESULT;
}