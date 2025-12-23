#ifndef SERIALIZER
#define SERIALIZER

#include <iostream>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &obj);
        Serializer& operator=(const Serializer &obj);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
        ~Serializer();
};

#endif


