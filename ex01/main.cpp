#include "Span.hpp"
#include <iostream>

void put_tenthousand(Span &span)
{

		for( int i = 1; i <= 10000; i++)
		{
			try
			{
				span.addNumber(i);
			}
			catch (const Span::FullSpanException &e)
			{
				std::cerr << e.what() << " catched at:" << i << std::endl ;
				return;
			}
		}
}
/*
int main(void)
{
	Span insufficentSpan(500);
	Span justSpan(10000);
	Span spareSpan(10005);

	std::cout << "--- Sobrepasando capacidad en insufficentSpan ---" << std::endl;
	put_tenthousand(insufficentSpan);
	std::cout << "--- Completando capacidad en justSpan ---" << std::endl;
	put_tenthousand(justSpan);
	std::cout << "--- Llenado parcial en spareSpan ---" << std::endl;
	put_tenthousand(spareSpan);

	Span cero(0);
	Span one(1);
	std::cout << "--- Calculando shortestSpan en cero (debe fallar) ---" << std::endl;
	try
	{
		cero.shortestSpan();
	}
	catch (const Span::NoSpanException &e)
	{
		std::cerr << e.what() << " catched" << std::endl;
	}

	std::cout << "--- Calculando shortestSpan en one (debe fallar) ---" << std::endl;
	try
	{
		one.shortestSpan();
	}
	catch (const Span::NoSpanException &e)
	{
		std::cerr << e.what() << " catched" << std::endl;
	}

	Span example(5);
	example.addNumber(0);
	example.addNumber(45);
	example.addNumber(33);
	example.addNumber(1);
	example.addNumber(200);
	std::cout << "--- Calculando shortestSpan en example ---" << std::endl;
	try
	{
		std::cout << "shortestSpan(), esperado:1 tienes:" << example.shortestSpan() << std::endl;
	}
	catch (const Span::NoSpanException &e)
	{
		std::cerr << e.what() << " catched" << std::endl;
	}
	std::cout << "--- Calculando longestSpan en example ---" << std::endl;
	try
	{
		std::cout << "longestSpan(), esperado:200 tienes:" << example.longestSpan() << std::endl;
	}
	catch (const Span::NoSpanException &e)
	{
		std::cerr << e.what() << " catched" << std::endl;
	}
}*/

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}