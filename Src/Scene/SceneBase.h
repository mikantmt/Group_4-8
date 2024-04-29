#pragma once
#include "../Collision/Collision.h"
#include "../Input/Input.h"
#include "../Sound/Sound.h"
#include "../Score/Score.h"
#include "../Player/Player.h"
//����
enum SCENE_TYPE
{
	//�V�[����ID
	TYPE_ID_INIT = 100,	//������

	TYPE_ID_LOOP = 200,	//���[�v

	TYPE_ID_FIN = 300,	//�I��
};

enum SCENE_ID
{
	//�V�[����ID
	SCENE_ID_TITLE = 100,	//�^�C�g��

	SCENE_ID_SELECT = 200,	//�Z���N�g

	SCENE_ID_PLAY = 300,	//�v���C

	SCENE_ID_RESULT = 400,	//���U���g
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