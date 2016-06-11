//
//  IAudioContext.hpp
//  AudioProject
//
//  Created by Antriksh Bali on 31/05/16.
//
//

#ifndef IAudioContext_hpp
#define IAudioContext_hpp
#include "AudioObject.hpp"

class IAudioContext
{
public:
    virtual ~IAudioContext() {}
    virtual void PlayAudio (AudioObject& ao) = 0;
    virtual void PauseAudio (AudioObject& ao) = 0;
    virtual void StopAudio (AudioObject& ao) = 0;
private:
    
};

#endif /* IAudioContext_hpp */
