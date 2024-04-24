#include "ScenePlay.h"

void cPlay::Init()
{
	sound.Init();
	player.Init();
	mapchip.Init();
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
	mapchip.Draw(0);

	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(0, 255, 255), "ƒvƒŒƒC");

	player.Draw();
}

void cPlay::Fin()
{
	sound.Fin();
	player.Fin();
	
	cScene::SceneID = SCENE_ID::SCENE_ID_RESULT;
}