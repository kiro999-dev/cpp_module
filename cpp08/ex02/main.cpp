
#include "MutantStack.hpp"
#include <list>
int main()
{
    MutantStack<int> mstack;
    std::list<int> numberList;
    numberList.push_front(5);
    numberList.push_front(17);
    mstack.push(5);
    mstack.push(17);
    std::cout <<"MuntanStack: "<< mstack.top() << std::endl;
    std::cout <<"List: "<< numberList.front() << std::endl;
    numberList.pop_front();
    mstack.pop();
    std::cout << "MuntanStack: "<< mstack.size() << std::endl;
    std::cout <<"List: "<< numberList.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout<<"MutantStack : \n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    numberList.push_back(3);
    numberList.push_back(5);
    numberList.push_back(737);
    numberList.push_back(0);
    std::cout<<"List : \n";
    std::list<int>::iterator it1 = numberList.begin();
    std::list<int>::iterator ite2 = numberList.end();
    ++it1;
    --it1;
    while (it1 != ite2)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::stack<int> s(mstack);
    return 0;
}