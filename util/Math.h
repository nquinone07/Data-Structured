#ifndef DATA_STRUCTURES_MATH_H
#define DATA_STRUCTURES_MATH_H

#include <cstddef>
#include <cstdint>
#include <sys/types.h>

#define BV(bt) (1 << bt) 

namespace Math
{
    namespace GeneratorPolynomial
    {
        union _CRC32_P
        {
            static const int64_t CRC32_GP = 0x04C11DB7; /* x^(32) + x^(26) + x^(23) + x^(22) + x^(16) + x^(12) + x^(11) + x^(10) + x^(10) + x^(9) + x^(8) + x^(6) + 1*/
        } CRC32_P;
    };

    namespace Constants
    {
        // The number of bits in a byte
        static const ssize_t BITS_PER_BYTE = 8;
        // Highest bit in a 32-bit word
        static const ssize_t HIGH_32BIT = 31;
    }

    // The Natural logarithm 
    float elog(size_t x);

    // The Power operator 
    float pow(ssize_t val, ssize_t power);

    // The ceiling operator
    ssize_t ceil(float val);

    // The floor operator
    ssize_t floor(float val);

    // The exponent operator
    size_t exp(size_t base, size_t pow);
   
    // Find the most significant bit given a value
    size_t msb(size_t word);
    
    // The Remez Algorithm
    void remez_computation(void);
}

#endif
