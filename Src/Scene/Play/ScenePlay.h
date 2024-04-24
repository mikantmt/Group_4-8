#pragma once
#include "../manager/Scene.h"
#include "../../Mapchip/MapChip.h"

class cPlay : public cSceneBase {
private:
	MapChip mapchip;
public:
	void Init();
	void Step();
	void Draw();
	void Fin();
};