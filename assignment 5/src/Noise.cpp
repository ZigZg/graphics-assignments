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

// computes the color at a certain position due to Perlin Noise
Vector3f
Noise::getColor(const Vector3f &pos)
{
    // computes the noise function value at a certain position
    float M = sin(frequency * pos[0] + amplitude * perlinOctaveNoise(pos, octaves));
    // clamps the value between 0 and 1 (analogous to shifting the function up, then shrinking it)
    M = (M+1)/2.0;
    // uses the above value to interpolate between two colors
    return M*color[0]+(1-M)*color[1];
}

bool
Noise::isValid()
{
    return init;
}
