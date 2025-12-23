#ifndef ITER
#define ITER
template<typename array,typename size,typename func>
void iter(array &arr,const size si,func function)
{
    for (size i = 0; i < si; i++)
    {
        function(arr[i]);
    }
}
#endif