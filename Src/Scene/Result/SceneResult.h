#pragma once
#include "../manager/Scene.h"

class cResult : public cSceneBase {
private:

public:
	// �^�C�g��������
	void Init();
	// �^�C�g���ʏ폈��
	void Step();
	// �^�C�g���`�揈��
	void Draw();
	// �^�C�g���I������
	void Fin();
};
