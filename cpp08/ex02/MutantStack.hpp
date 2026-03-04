#include <stack>
#include <iostream>
template<class T>
class MutantStack:public std::stack<T>
{
private:

public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    iterator begin();
    iterator end();
    const iterator begin() const;
    const iterator end() const;
    MutantStack();
    ~MutantStack();

    
};
template<class T>
MutantStack<T>::MutantStack()
{

}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}
template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
template<class T>
 const typename MutantStack<T>::iterator MutantStack<T>::begin() const
{
    return this->c.begin();
}
template<class T>
const typename MutantStack<T>::iterator MutantStack<T>::end() const
{
    return this->c.end();
}
template<class T>
MutantStack<T>::~MutantStack()
{

}