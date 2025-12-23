#include "Serializer.hpp"
int main()
{
    Data data;
    Data *origin = &data;
    uintptr_t data_t = Serializer::serialize(&data);
    Data *dserialized = Serializer::deserialize(data_t);

    if(dserialized == origin)
        std::cout<<"true";
    else
        std::cout<<"false";
    std::cout<<std::endl;
}