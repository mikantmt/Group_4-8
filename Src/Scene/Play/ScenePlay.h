#pragma once
#include "../manager/Scene.h"
#include "../../Mapchip/MapChip.h"
#include "../../Screen/Screen.h"

class cPlay : public cSceneBase {
private:
	MapChip mapchip;
	Screen screen;
public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void MapCollision();
};