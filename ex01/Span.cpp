#include "Span.hpp"

Span::Span(): _maxSize(0), _numbers() {
    std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int N): _maxSize(N), _numbers() {
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span& copy): _maxSize(copy._maxSize), _numbers(copy._numbers){
    std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& copy) {
    std::cout << "Span copy constructor called" << std::endl;
    if (this != &copy)
    {
        _maxSize = copy._maxSize;
        _numbers = copy._numbers;
    }
    return (*this);
}

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

void    Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw   std::runtime_error("Span size reached");
    _numbers.push_back(number);
}

int Span::shortestSpan(void) {
    if (_numbers.size() <= 1)
        throw   std::runtime_error("Not enough numbers to compare");
    std::vector<int> temp = _numbers;
    std::sort(temp.begin(), temp.end());
    int minSpan = temp[1] - temp[0];
    for (int i = 1; i < temp.size() - 1; i++)
    {
        int dif = temp[i + 1] - temp[i];
        if (dif < minSpan)
            minSpan = dif;
    }
    return (minSpan);
}

int Span::longestSpan(void) {
    if (_numbers.size() <= 1)
        throw   std::runtime_error("Not enough numbers to compare");
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());

    return (max - min);
}

