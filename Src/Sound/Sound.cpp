#include "Sound.h"

void Sound::Init() {
	for (int i = 0; i < SOUND_TYPE_NUM; i++) {
		Sound[i] = LoadSoundMem(SoundPath[i]);
	}
}

void Sound::Step(SOUND_TYPE sound,int playtype, int volume) {
	ChangeVolumeSoundMem(255 * volume / 100, Sound[sound]);
	PlaySoundMem(Sound[sound], playtype);
}

void Sound::Fin() {
	for (int i = 0; i < SOUND_TYPE_NUM; i++) {
		DeleteSoundMem(Sound[i]);
	}
}