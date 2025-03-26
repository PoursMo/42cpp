#ifndef SPAN_HPP
#define SPAN_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	std::vector<int> integers;
	unsigned int size;

public:
	Span();
	Span(const unsigned int N);
	Span(const Span &rhs);
	Span &operator=(const Span &rhs);
	~Span();
	unsigned int getSize() const;
	int &operator[](unsigned int pos);
	const int &operator[](unsigned int pos) const;
	void addNumber(int num);

	template <typename T>
	void addNumbers(T begin, T end)
	{
		while (begin != end)
		{
			addNumber(*begin);
			begin++;
		}
	}
	int shortestSpan() const;
	int longestSpan() const;
};

std::ostream &operator<<(std::ostream &stream, const Span &span);

#endif