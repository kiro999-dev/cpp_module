#ifndef SERIALIZER
#define SEARIALZER
#include <cstdint>
#include <iostream>
#include "Data.hpp"

class Serializer
{
private:

public:
    Serializer();
    Serializer(const Serializer &obj);
    Serializer& operator=(const Serializer &obj);
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();
};

#endif


