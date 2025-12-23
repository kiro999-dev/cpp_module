#include "Serializer.hpp"
Serializer::Serializer()
{
    std::cout<<"Serializer constructor has been called"<<std::endl;
}
Serializer::Serializer(const Serializer &o)
{
    (void)o;
    std::cout<<"Serializer copy constructor has been called"<<std::endl;
}
Serializer& Serializer::operator=(const Serializer &o)
{
    (void)o;
    std::cout<<"Serializer operator = has been called"<<std::endl;
    return *this;
}
uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t data = reinterpret_cast<uintptr_t>(ptr);
    return data;
}
Data* Serializer::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data*>(raw);

    return data;
}
Serializer::~Serializer()
{
    std::cout<<"Serializer destructor has been called"<<std::endl;
}