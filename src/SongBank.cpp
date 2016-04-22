#include "SongBank.h"
#include "Log.h"
#include "FileManager.h"

map<string, Mix_Chunk*> SongBank::ChunkList;
map<string, Mix_Music*> SongBank::MusicList;

bool SongBank::Init(){
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ){
        Log("[ERRO] Unable to Initialize SongBank");
        return false;
    }
    Cleanup();
    return LoadSongFolder("etc/Sounds/Effects");
}

void SongBank::Quit(){
    Cleanup();
    Mix_CloseAudio();
}

void SongBank::Cleanup(){
    if (ChunkList.size() <= 0 && MusicList.size() <= 0) return;

    for(auto& Iterator : ChunkList){
        Mix_Chunk* chunk = (Mix_Chunk*)Iterator.second;
        Mix_FreeChunk(chunk);
    }
    ChunkList.clear();

    for(auto& Iterator : MusicList){
        Mix_Music* music = (Mix_Music*)Iterator.second;
        Mix_FreeMusic(music);
    }
    MusicList.clear();
    Log("[ OK ] SongBank Cleaned up");
}

bool SongBank::LoadSongFolder(string Folder){
    vector<string> Files = FileManager::GetFilesInFolder("etc/"+Folder);

    for (auto Filename : Files){
        string ID = FileManager::GetFilenameWithoutExt(Filename);
        string Ext = FileManager::GetFilenameExt(Filename);

        if (ID == "") continue;
        Mix_Chunk* chunk;
        if (Ext == ".wav")
            chunk = Mix_LoadWAV(Filename.data());
        ChunkList[ID] = chunk;
    }
    return true;
}

void SongBank::UnloadSongFolder(string Folder){
    vector<string> Files = FileManager::GetFilesInFolder("etc/"+Folder);

    for (auto Filename : Files){
        string ID = FileManager::GetFilenameWithoutExt(Filename);
        if (ChunkList[ID]){
            Mix_FreeChunk(ChunkList[ID]);
            ChunkList.erase(ID);
        }
    }
}

bool SongBank::LoadMusicFolder(string Folder){
    vector<string> Files = FileManager::GetFilesInFolder("etc/"+Folder);

    for (auto Filename : Files){
        string ID = FileManager::GetFilenameWithoutExt(Filename);
        string Ext = FileManager::GetFilenameExt(Filename);

        if (ID == "") continue;
        Mix_Music* music = Mix_LoadMUS(Filename.data());
        MusicList[ID] = music;
    }
    return true;
}

void SongBank::UnloadMusicFolder(string Folder){
    vector<string> Files = FileManager::GetFilesInFolder("etc/"+Folder);

    for (auto Filename : Files){
        string ID = FileManager::GetFilenameWithoutExt(Filename);
        if (MusicList[ID]){
            Mix_FreeMusic(MusicList[ID]);
            MusicList.erase(ID);
        }
    }

}

void SongBank::PlaySong(string ID){
    Mix_PlayChannel(-1, ChunkList[ID], 0);
}

void SongBank::PlayMusic(string ID){
    Mix_PlayMusic(MusicList[ID], -1);
}

void SongBank::PauseMusic(){
    Mix_PauseMusic();
}

void SongBank::ResumeMusic(){
    Mix_ResumeMusic();
}

void SongBank::StopMusic(){
    Mix_HaltMusic();
}

void SongBank::SetVolume(int volume){
    Mix_Volume(-1, (char)(volume*1.28));
}

void SongBank::FadeOut(int ms){
    Mix_FadeOutMusic((char)ms);
}

void SongBank::FadeIn(string ID, int ms){
    Mix_FadeInMusic(MusicList[ID], -1, (char)ms);
}
