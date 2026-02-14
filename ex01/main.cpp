#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "===== Teste básico =====" << std::endl;

    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste com números negativos =====" << std::endl;

    try
    {
        Span sp(4);

        sp.addNumber(-10);
        sp.addNumber(5);
        sp.addNumber(20);
        sp.addNumber(-30);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste de exceção (Span cheio) =====" << std::endl;

    try
    {
        Span sp(2);

        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // deve lançar exceção
    }
    catch (std::exception &e)
    {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste addRange =====" << std::endl;

    try
    {
        Span sp(10);
        std::vector<int> v;

        v.push_back(100);
        v.push_back(200);
        v.push_back(300);
        v.push_back(400);

        sp.addRange(v.begin(), v.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n===== Teste cópia =====" << std::endl;

    try
    {
        Span original(3);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);

        Span copy = original;

        std::cout << "Original longest: " << original.longestSpan() << std::endl;
        std::cout << "Copy longest    : " << copy.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
