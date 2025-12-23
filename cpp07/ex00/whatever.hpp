#ifndef WHATEVER
#define WHATEVER

template<typename A>
void swap(A &value1,A &value2)
{
    A tmp = value1;
    value1 = value2;
    value2 = tmp;
}
template<typename A>
A max(A val1,A val2)
{
    if(val1 > val2)
    {
        return val1;
    }
    else
        return val2;
}
template<typename A>
A min(A val1,A val2)
{
    if(val1 < val2)
    {
        return val1;
    }
    else
        return val2;
}
#endif