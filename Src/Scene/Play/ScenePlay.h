#pragma once
#include "../manager/Scene.h"

class cPlay : public cSceneBase {
private:

public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};