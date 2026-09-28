#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : _size(0)
{}

Span::Span(const Span& other)
{
	_size = other._size;
	for (std::vector<int>::const_iterator it = other._storage.begin();
		it != other._storage.end(); it++)
	{
		_storage.push_back(*it);
	}
}

Span& Span::operator=(const Span& other)
{
	_storage.erase(_storage.begin(), _storage.end());
	_size = other._size;
	for (std::vector<int>::const_iterator it = other._storage.begin();
		it != other._storage.end(); it++)
	{
		_storage.push_back(*it);
	}
	return *this;
}

Span::~Span()
{}

Span::Span(unsigned int num) : _size(num)
{}

void Span::addNumber(int num)// Any attempt to add a new element if there are already N elements stored should throw an exception
{
	if (_storage.size() == _size)
	{
		throw FullSpanException();
	}
	_storage.push_back(num);
}

long Span::shortestSpan()
{
	if (_storage.size() < 2)
		throw NoSpanException();
	std::vector<int> sortCpy(_storage);
	std::sort(sortCpy.begin(), sortCpy.end());
	long shortest = std::numeric_limits<long>::max();
	for(std::vector<int>::const_iterator it = (sortCpy.begin() + 1);
		it != (sortCpy.end()); ++it)
	{
		long actual = static_cast<long>(*it) - static_cast<long>(*(it - 1));
		if (shortest > actual)
			shortest = actual;
	}
	return shortest;
}

long Span::longestSpan()
{
	if (_storage.size() < 2)
		throw NoSpanException();
    long higest = *std::max_element(_storage.begin(), _storage.end());
    long smallest = *std::min_element(_storage.begin(), _storage.end());
	return higest - smallest;
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to get a span";
}
