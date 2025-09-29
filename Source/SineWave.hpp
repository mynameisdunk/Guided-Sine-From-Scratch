//
//  SineWave.hpp
//  GuidedSine
//
//  Created by Harry on 26/09/2025.
//

#ifndef SineWave_hpp
#define SineWave_hpp

#include <stdio.h>
#include <juce_audio_basics/juce_audio_basics.h>

class SineWave
{
public:
    void prepare (double sampleRate, int numChannels);
    void process (juce::AudioBuffer<float>&buffer);
    [[nodiscard]] float getAmplitude() const {return amplitude; }
    [[nodiscard]] float getFrequency() const {return frequency; }
    void setAmplitude(const float newAmplitude) {amplitude = newAmplitude; }
    void setFrequency(const float newFrequency) {frequency = newFrequency; }
    
private:
    float amplitude = 0.2f;
    float frequency = 330.0f;
    float currentSampleRate = 0.0f;
    float timeIncrement = 0.0f;
    std::vector<float> currentTime;
    
    
    
    
};



#endif /* SineWave_hpp */
