#include "Scene.h"
#include "../Title/SceneTitle.h"
#include "../Play/ScenePlay.h"
#include "../Result/SceneResult.h"

SCENE_TYPE cScene::cScene::SceneTypeID;
SCENE_ID cScene::cScene::SceneID;

void cScene::SceneInit() {
	cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_INIT;
	cScene::SceneID = SCENE_ID::SCENE_ID_TITLE;

	scene = nullptr;
}

void cScene::SceneLoop(){
	switch (cScene::SceneTypeID) {
	case SCENE_TYPE::TYPE_ID_INIT:
		switch (SceneID) {
		case SCENE_ID::SCENE_ID_TITLE:
			scene = new cTitle;
			break;
		case SCENE_ID::SCENE_ID_SELECT:
			//¡‚Ì‚Æ‚±‚ë‚È‚µ
			break;
		case SCENE_ID::SCENE_ID_PLAY:
			scene = new cPlay;
			break;
		case SCENE_ID::SCENE_ID_RESULT:
			scene = new cResult;
			break;
		}

		scene->Init();
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_LOOP;

		break;
	case SCENE_TYPE::TYPE_ID_LOOP:
		scene->Step();
		scene->Draw();
		break;

	case SCENE_TYPE::TYPE_ID_FIN:
		scene->Fin();
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_INIT;
		break;
	}
}