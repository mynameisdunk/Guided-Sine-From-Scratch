//
//  SineWave.cpp
//  GuidedSine
//
//  Created by Harry on 26/09/2025.
//

#include "SineWave.hpp"

void SineWave::prepare(double sampleRate, int numChannels){
    currentSampleRate = static_cast <float> (sampleRate);
    timeIncrement = 1.0f / currentSampleRate;
    currentTime.resize(numChannels, 0.0f);
     
    
}

void SineWave::process(juce::AudioBuffer<float>&buffer)
{
    if (currentTime.size() != buffer.getNumChannels())
        return;
    
    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        auto* output = buffer.getWritePointer(channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); sample++)
        {
            output[sample] = amplitude * std::sinf(juce::MathConstants<float>::twoPi * frequency * currentTime[channel]);
            currentTime[channel] = currentTime[channel] + timeIncrement;
        
        }
        
    }
    
}

 
