//
//  SDLWAVAudioData.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#ifndef SDLWAVAudioData_hpp
#define SDLWAVAudioData_hpp

#include "../IAudioData.hpp"
#include <SDL2/SDL.h>
#include <string>


class SDLWAVAudioData : public IAudioData
{
public:
    SDLWAVAudioData(const std::string& fileName, bool streamFromFile);
    virtual ~SDLWAVAudioData();
    
    virtual size_t GenerateSamples(float* stream, size_t streamLength, size_t pos, const SampleInfo& info);
    virtual size_t GetAudioLength();
private:
    Uint8* m_start;
    Uint8* m_pos;
    Uint8* m_end;
    //Uint32 m_length;
    SDLWAVAudioData (SDLWAVAudioData& other) { (void)other; }
    void operator = (const SDLWAVAudioData& other) { (void)other; }
};
#endif /* SDLWAVAudioData_hpp */
