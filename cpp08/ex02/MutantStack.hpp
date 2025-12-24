#include <stack>
template<class T>
class MutantStack:public std::stack<T>
{
private:

public:
    typedef typename std::stack<T>::iterator iterator;
    MutantStack();
    ~MutantStack();
    
};

