#include "Span.hpp"

Span::Span() : size(0)
{
}

Span::Span(const unsigned int N) : size(N)
{
}

Span::Span(const Span &rhs) : size(rhs.size)
{
	for (size_t i = 0; i < size; i++)
	{
		integers[i] = rhs.integers[i];
	}
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		for (size_t i = 0; i < size; i++)
		{
			integers[i] = rhs.integers[i];
		}
	}
	return *this;
}

Span::~Span()
{
}

unsigned int Span::getSize() const
{
	return size;
}

int &Span::operator[](unsigned int pos)
{
	if (pos >= size)
		throw std::out_of_range("index out of range");
	return integers[pos];
}

const int &Span::operator[](unsigned int pos) const
{
	if (pos >= size)
		throw std::out_of_range("index out of range");
	return integers[pos];
}

void Span::addNumber(int num)
{
	if (integers.size() >= size)
		throw std::length_error("maximum span capacity reached");
	integers.push_back(num);
}

int Span::shortestSpan() const
{
	if (integers.size() < 2)
		throw std::logic_error("no shortest span can be found");
	std::vector<int> tmp = integers;
	std::sort(tmp.begin(), tmp.end());
	int shortest = __INT_MAX__;
	for (size_t i = 1; i < tmp.size(); i++)
	{
		shortest = std::min(shortest, tmp[i] - tmp[i - 1]);
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (integers.size() < 2)
		throw std::logic_error("no longest span can be found");
	return *std::max_element(integers.begin(), integers.end()) - *std::min_element(integers.begin(), integers.end());
}




std::ostream &operator<<(std::ostream &stream, const Span &span)
{
	for (size_t i = 0; i < span.getSize(); i++)
	{
		stream << span[i];
		if (i != span.getSize() - 1)
			stream << ", ";
	}
	return stream;
}