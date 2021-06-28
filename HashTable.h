#ifndef DATA_STRUCTURES_HASHTABLE_H
#define DATA_STRUCTURES_HASHTABLE_H

#include <stdint.h>
/*****************************************************************************************/
// DEFINITION  : Simple linked list
//
// DESCRIPTION : Linked list built such that each element added to the list becomes 
//               the new linked list head. This preserves the O(1) insert for HashTables.
//
// PERFORMANCE : Insert O(1), Search O(n), Delete O(n) [ Worst Case ] 
/*****************************************************************************************/
template<typename TYPE>
struct ListNode
{
    /// MEMBER FUNCTIONS ///
    // Default constructor 
    ListNode()
    : val(0),
      next(nullptr)
    {}
    // One param initialization constructor
    explicit ListNode(TYPE val)
    : val(val),
      next(nullptr)
    {}
    // Two param initialization constructor
    ListNode(TYPE val, ListNode* next) 
    : val(val),
      next(next)
    {}
    // Default destructor
    ~ListNode() = default;

    /// MEMBERS ///
    TYPE val;
    ListNode* next;
};

/*****************************************************************************************/
// DEFINITION  : Hash Table, given a hash function h and a key k, assumes each key k is 
//               convertible some function such that it maps to the set of natural numbers.
//
// DESCRIPTION : Given a key-value pair, hash the key into the table storing in an underlying
//               linked list. The hash function should be suitably chosen, such that it 
//               satisfies the condition of simple uniform hashing. That is, each key is 
//               equally likely to hash into any slot independently of where any other key
//               was hashed to.
//               
// PERFORMANCE : Insert O(1), Search O(n) [ Average O(1) ], Delete O(n) [ Worst Case ] 
/*****************************************************************************************/
template<typename HASH_KEY, typename HASH_VALUE>
class HashTable
{
public:
    /// Special Member Functions ///
    // Constructor
    HashTable();
    // Destructor - Free'ing any heap-allocated memory
    ~HashTable();
    

private:
    /// Private Functions ///
    // NOTE: We assume that a key of type HASH_KEY is convertible, through some mechanism, 
    //       to the set of natural numbers. E.g. character strings can be treated as a summation
    //       of their ASCII values.
    void hashAndStore(HASH_KEY);

    /* Hashing Functions */
    size_t divisionHash(HASH_KEY);
    size_t multiplicationHash(HASH_KEY);
    size_t universalHash(HASH_KEY);
    /* Helper Utility Functions */
    size_t toUint(HASH_KEY k);

    /// Member Variables ///
    // The underlying linked list for each slot in the table
    using LinkedList = ListNode<HASH_VALUE>;
    LinkedList* table;
    // The number of slots chosen
    size_t slots;
    // The number of collisions that occurred
    size_t collisions;
    // The set of primes for integer values bound by 0 < p < 2^(32 - 1)
    size_t* set_of_primes_u32;
    // The number of primes 
    ssize_t number_of_primes_u32;
};

#endif 
