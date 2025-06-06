# Secured

## Description
Hash table implementation in C featuring custom hash functions and collision handling through separate chaining. The project focuses on building a secure data storage system using cryptographic hashing principles.

## Objective
Implement a `libhashtable.a` library that must:
- Develop a custom hash function with proper distribution
- Create a dynamic hash table with separate chaining for collision resolution
- Provide complete CRUD operations (Create, Read, Update, Delete)
- Handle function pointers for flexible hash function assignment

### Hash Function Requirements
The hash function `int hash(char *key, int len)` must meet 4 criteria:
1. Output entirely determined by input data
2. All input data used in hashing process
3. Similar inputs produce very different outputs
4. Even distribution across the hash table

## Key Features
- Custom hash function implementation
- Function pointer integration for flexible hashing
- Dynamic memory management
- Comprehensive error handling
- Separate chaining collision resolution
