#include "Noise.h"
#include "PerlinNoise.h"

#include <cmath>

Noise::Noise() :
    octaves(0),
    init(false)
{
}

Noise::Noise(int _octaves,
             const Vector3f &color1, 
             const Vector3f &color2,
             float freq,
             float amp) :
    octaves(_octaves),
    frequency(freq),
    amplitude(amp)
{
    color[0] = color1;
    color[1] = color2;
    init = true;
}

Vector3f
Noise::getColor(const Vector3f &pos)
{
    float M = sin(frequency*pos[0] + amplitude*perlinOctaveNoise(pos, octaves));
    M = (M+1)/2.0;
    return M*color[0]+(1-M)*color[1];
}

bool
Noise::isValid()
{
    return init;
}
