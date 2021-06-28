#ifndef DATA_STRUCTURES_MATH_H
#define DATA_STRUCtURES_MATH_H


class Math
{
public:
    // The Natural logarithm 
    static float elog(size_t x);

    // The Power operator 
    static float pow(ssize_t val, ssize_t power);

    // The ceiling operator
    static ssize_t ceil(ssize_t val);

    // The floor operator
    static ssize_t floor(ssize_t val);

    // The exponent operator
    static size_t exp(size_t base, size_t pow);
   
    // Find the most significant bit given a value
    static size_t msb(size_t word);
    
    // The Remez Algorithm
    // TODO
    static void remez_computation(void);
private:
    // The number of bits in a byte
    static const ssize_t BITS_PER_BYTE = 8;
    // Highest bit in a 32-bit word
    static const ssize_t HIGH_32BIT = 31;
}
