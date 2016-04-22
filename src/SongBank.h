#ifndef __TEXTUREBANK_H__
	#define __TEXTUREBANK_H__

#include <SDL2/SDL_mixer.h>
#include <map>
#include <vector>
using namespace std;

class SongBank{
private:
    static map<string, Mix_Chunk*> ChunkList;
    static map<string, Mix_Music*> MusicList;

public:
    static bool Init();
    static void Quit();
	static void Cleanup();
    static bool LoadSongFolder(string Folder);
    static void UnloadSongFolder(string Folder);
    static bool LoadMusicFolder(string Folder);
    static void UnloadMusicFolder(string Folder);
    static void PlaySong(string ID);
    static void PlayMusic(string ID);
    static void PauseMusic();
	static void ResumeMusic();
    static void StopMusic();
	static void SetVolume(int);
	static void FadeOut(int);
	static void FadeIn(string, int);
};

#endif
