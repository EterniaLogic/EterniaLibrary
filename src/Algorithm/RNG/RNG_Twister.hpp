#ifndef RNG_TWISTER_H_
#define RNG_TWISTER_H_

// Wiki page
// https://en.wikipedia.org/wiki/Mersenne_Twister
class RNG_Twister{
    unsigned int x[624];
    signed int index;
    
public:

    // initialize the RNG
    void Initialize(unsigned int seed)
    {
        index = 624;
        signed int i = 1;
        *x = seed;
        unsigned int *j = x;
        unsigned int _a; int _b;
        do
        {
            _a = i + 1812433253 * (*j ^ (*j >> 30));
            *(j + 1) = _a;
            _b = i + 1812433253 * (_a ^ (_a >> 30)) + 1;
            i += 2;
            *(j + 2) = _b;
            j += 2;
        } while (j < x + 0x26C);
    }

    // set values
    unsigned int Twist()
    {
        signed int top = 397, l = 623;
        unsigned int *j = x;
        int i; unsigned int _c, out; signed int _f;
        do
        {
            i = (top - 396) % 624;
            _c = (*j ^ (*j ^ (x[i])) & 0x7FFFFFFF) >> 1;
            if ((*j ^ (*j ^ x[i])) & 1)
                _c ^= 0x9908B0DFu;
            _f = top++;
            out = _c ^ x[_f % 624];
            *j = out;
            ++j;
            --l;
        } while (l);
        index = 0;
        return out;
    }

    // Get the final value
    unsigned int Extract()
    {
        int i = index;
        if (index >= 624)
        {
            Twist();
            i = index;
        }
        unsigned int e = x[i];
        unsigned int _v = x[i] >> 11;
        index = i + 1;
        int def = (((_v ^ e) & 0xFF3A58AD) << 7) ^ _v ^ e;
        return ((def & 0xFFFFDF8C) << 15) ^ def ^ ((((def & 0xFFFFDF8C) << 15) ^ def) >> 18);
    }
};

#endif
