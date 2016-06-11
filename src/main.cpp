//
//  main.cpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#include <iostream>
#include <SDL2/SDL.h>

#include "IAudioDevice.hpp"
#include "IAudioContext.hpp"
#include "AudioObject.hpp"

#include "sdl/SDLAudioDevice.hpp"
#include "sdl/SDLAudioContext.hpp"

#define FILE_PATH "/Users/antrikshbali/Downloads/AudioPlayer/build/res/audio/testClip.wav"


int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_AUDIO);
    
    IAudioDevice* device = new SDLAudioDevice();
    IAudioContext* context = new SDLAudioContext();
    
    IAudioData* data = device->CreateAudioFromFile(FILE_PATH);
    
    SampleInfo info;
    info.volume = 1.0;
    info.pitch = 1.4;
    
    AudioObject sound(info,data);
    
    char in = 0;
    while(in != 'q')
    {
        std::cin>>in;
        switch(in)
        {
            case 'a': context->PlayAudio(sound);
                break;
            case 's': context->PauseAudio(sound);
                break;
            case 'd': context->StopAudio(sound);
                break;
        }
    }
    
    device->ReleaseAudio(data);
    delete context;
    delete device;
    SDL_Quit();
    return 0;
}