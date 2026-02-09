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
    void    addRange(It begin, It end);
};

