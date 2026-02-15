#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    MutantStack() : std::stack<T>() {};
    MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
    MutantStack& operator=(const MutantStack& copy) 
    {
        if (this != &copy)
            std::stack<T>::operator=(copy);
        return (*this);
    }
    ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return (this->c.begin());
    }
    iterator end() {
        return (this->c.end());
    }
};

