#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
Base * generate(void)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Base *ptr;
    int random = rand();
    if(random % 3 == 0)
    {
        ptr = new A;
    }
    else if(random % 3 == 0)
        ptr = new B;
    else
        ptr = new C;
    return ptr;
}
void identify(Base* p)
{
    A *AType = dynamic_cast<A*>(p);
    B *BType = dynamic_cast<B*>(p);
    C *CType = dynamic_cast<C*>(p);
    if(AType)
        std::cout<<"Type: A"<<std::endl;
    if(BType)
        std::cout<<"Type: B"<<std::endl;
    if(CType)
        std::cout<<"Type: C"<<std::endl;
}
void identify(Base& p)
{
    try
    {
        A &AType = dynamic_cast<A&>(p);
        std::cout<<"Type: A"<<std::endl;
    }
    catch(const std::exception& e)
    {
        
    }
    try
    {
        B &BType = dynamic_cast<B&>(p);
        std::cout<<"Type: C"<<std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        C &CType = dynamic_cast<C&>(p);
        std::cout<<"Type: C"<<std::endl;
    }
    catch(const std::exception& e)
    {
    }
   
}
int main()
{
    Base *ptr = generate();
    identify(ptr);
    A aclass;
    identify(aclass);
}