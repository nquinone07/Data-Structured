#include <HashTable.h>
#include <Math.h>
#include <strings.h>
#include <Search.h>
/**************************************************************
 *
 *                  SPECIAL MEMBER FUNCTIONS
 *
 **************************************************************/
template<typename HASH_KEY, typename HASH_VALUE>
HashTable::HashTable()
: table(nullptr),
  slots(0),
  collisions(0),
  set_of_primes_u32(nullptr),
  number_of_primes_u32
{
    /* TODO: Initialize all of the above */
    // The seive of atkin
    auto seive_of_atkin = [](size_t* set_of_primes, ssize_t number_of_primes, size_t bound)
    {
        // An upper bound on the number of primes that may exist for 
        // bound. Approximated by x/ln(x) given by Prime Number Theorem the number of primes 
        // of x is asymptotic to x/ln(x).
        number_of_primes = Math::ceil(static_cast<float>(bound/static_cast<ssize_t>(Math::elog(bound))));
        set_of_primes = new size_t[number_of_primes];
        // The constant sixty for taking modulus
        const size_t SIXTY = 60;
        const size_t TWO   = 2;
        // Initializing the set of primes to default 2, 3, 5
        set_of_primes[0] = 2; 
        set_of_primes[1] = 3; 
        set_of_primes[2] = 5;
        size_t primes_sz = 3;
        // For each potential prime n:
        // -- Take the modulus of n with 60, producing a modulo-remainder r:
        //  -- if r is in {1, 13, 17, 29, 37, 41, 49, 53} flip the entry for each possible solution to 4x^2 + y^2 = n
        //  -- if r is in {7, 19, 31, 43} flip the entry for each possible solution to : 3x^2 + y^2 = n
        //  -- if r is in {11, 23, 47, 59} flip the entry for each possible solution to : 3x^2 = y^2 = n when x > y
        
        // The sixy segment wheel broken out per primes to its quadratic formula
        // 4x^2 + y^2 = n
        size_t wheel_1 [] =
        {
            1, 13, 17, 29, 37, 41, 49, 53
        };
        // 3x^2 + y^2 = n
        size_t wheel_2 [] =
        {
            7, 19, 31, 43
        };
        // 3x^2 - y^2 = n
        size_t wheel_3 [] =
        {
            11, 23, 47, 59
        };
        // The wheels put together
        size_t* wheels [] = 
        {
            &wheel_1[0], &wheel_2[0], &wheel_3[0]
        };
        size_t wheel_szs [] = 
        {
            sizeof(wheel_1)/sizeof(wheel_1[0]), 
            sizeof(wheel_2)/sizeof(wheel_2[0]),
            sizeof(wheel_3)/sizeof(wheel_3[0]),
        };
        // Enumerating the polynomials
        enum Polynomial 
        {   
            POLY_1,
            POLY_2,
            POLY_3,
        };
        // For each integer upto bound (starting at the first non-marked prime 7),
        // Perform atkins sieve
        for (size_t n = 7; i <= bound; ++n)
        {
            // Remainder of n with sixty 
            size_t r = n % SIXTY;
            // To which set does the remainder belong (if any)?
            ssize_t search_ret  = -1;
            size_t i = 0;
            while ((i < sizeof(wheels)/sizeof(wheels[0])) && (-1 == search_ret))
            {
                // Binary search for the element
                search_ret = Search::binary_search(r, wheels[i], wheel_szs[i]);
                i++;
            }
            // Find the number of solutions
            size_t number_of_solutions = 1;
            switch (i)
            {
                // Calculate number of solutions for each polynomial
                case POLY_1:
                {
                    break;
                }
                case POLY_2:
                {
                    break;
                }
                case POLY_3:
                {
                    break;
                }
            }
            if ( 0 == (number_of_solutions % TWO)) 
            {
                set_of_primes[primes_sz++] = n;
            }
        }
        // Free the local, atkin sieve 
        free(atkin_sieve);
        atkin_sieve = nullptr;
    };
    // Compute the set of primes using the above algorithm
    seive_of_atkin(set_of_primes_u32, UINT32_MAX);
}



/**************************************************************
 *                      HASHING FUNCTIONS 
 *
 *  Division Hash 
 *      Map a key k into one of m slots by taking the
 *      remainder of k/m.
 *
 *  Multiplication Hash
 *
 *  Universal Hash
 *
 **************************************************************/

// Division Hash
template<typename HASH_KEY, typename HASH_VALUE>
size_t HashTable::divisionHash(HASH_KEY k)
{
    // Choose a prime from the list 
    /*TODO: Choose a prime based on the number of slots and 
     *      the set of primes   
     */
    auto choose_prime = [slots, set_of_primes]()
    {
    };
    // The chosen golden prime
    static const size_t GOLDEN_PRIME = choose_prime();

    // Now perform division hash 
    return toUint(k) % GOLDEN_PRIME;
}

// Multiplication Hash
template<typename HASH_KEY, typename HASH_VALUE>
size_t HashTable::multiplicationHash(HASH_KEY k)
{
}

// Universal Hash
template<typename HASH_KEY, typename HASH_VALUE>
size_t HashTable::universalHash(HASH_KEY k)
{
}
