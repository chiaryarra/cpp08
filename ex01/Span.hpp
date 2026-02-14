#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int>    _numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& copy);
    ~Span();

    void    addNumber(int number);
    int     shortestSpan(void);
    int     longestSpan(void);

    template <typename It>
    void    addRange(It begin, It end)
    {
        if (_numbers.size() + std::distance(begin, end) > this->_maxSize)
            throw std::runtime_error("Span is full!");
        _numbers.insert(_numbers.end(), begin, end);
    }
};

