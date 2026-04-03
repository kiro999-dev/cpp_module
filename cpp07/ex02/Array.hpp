#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <cstdlib>

template<class T>
class Array
{
private:
   unsigned int n;
   T *elem;
public:
    class OutofBoundException:public std::exception
    {
       public:
            virtual const char* what() const throw();
    };
    Array();
    Array(unsigned int n);
    Array(const Array &obj);
    Array &operator=(const Array &obj);
     T &operator[](unsigned int indx) ;
     const T& operator[](unsigned int indx) const;
    ~Array();
     unsigned int size() const ;
};

template<class T>
Array<T>::Array()
{
    n= 0;
    elem = NULL;
}
template<class T>
Array<T>::Array(const Array &obj)
{
   n = obj.n;
   elem = new T[n];
   for (size_t i = 0; i <n; i++)
   {
        elem[i] = obj[i];
   }
}
template<class T>
Array<T>& Array<T>::operator=(const Array &obj)
{
    if(this == &obj)
        return *this;
    delete[] elem; 
   n = obj.n;
   elem = new T[n];
   for (size_t i = 0; i <n; i++)
   {
        elem[i] = obj[i];
   }
   return *this;
}
template<class T>
const char *Array<T>::OutofBoundException::what() const throw() 
{
    return "index is out of bound";
}
template<class T>
T &Array<T>::operator[](unsigned int indx) 
{
    if(indx >= n)
        throw OutofBoundException();
    return elem[indx];
}
template<class T>
const T &Array<T>::operator[](unsigned int indx) const
{
    if(indx >= n)
        throw OutofBoundException();
    return elem[indx];
}

template<class T>
Array<T>::Array(unsigned int n)
{
    this->n = n;
    elem = new T[n];
}
template<class T>
 unsigned int Array<T>::size() const
{
    return n;
}
template<class T>
Array<T>::~Array()
{
    delete[] elem ;
}

#endif