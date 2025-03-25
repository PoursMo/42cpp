#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>
#include <cmath>

// *******************************************************************
// Debug
// *******************************************************************

#define DEBUG false
#if DEBUG
extern int level;
extern int comparisons;
#endif

// *******************************************************************
// Colors
// *******************************************************************

// Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

// Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

// Reset
#define CRESET "\e[0m"

// *******************************************************************
// Monitoring
// *******************************************************************

class Monitor
{
private:
	double start_time;
	double time;
	unsigned int range_size;
	std::string container_type;
	Monitor();
	Monitor(const Monitor &rhs);
	Monitor &operator=(const Monitor &rhs);

public:
	Monitor(const int size, const std::string &container);
	~Monitor();
	void stop();
	void print() const;
};

// *******************************************************************
// IteratorGroup
// *******************************************************************

template <typename Iterator>
class IteratorGroup
{
private:
	Iterator base;
	std::size_t size;
	IteratorGroup();

public:
	// *******************************************************************
	// Constructors
	// *******************************************************************

	IteratorGroup(const Iterator &base, std::size_t size) : base(base), size(size) {}
	IteratorGroup(const IteratorGroup &rhs) : base(rhs.base), size(rhs.size) {}
	IteratorGroup(const IteratorGroup &rhs, std::size_t size) : base(rhs.base), size(size) {}

	// *******************************************************************
	// Operations
	// *******************************************************************

	void swap(IteratorGroup rhs)
	{
		std::swap_ranges(base, base + size, rhs.base);
	}

	// *******************************************************************
	// Getters
	// *******************************************************************

	std::size_t getSize()
	{
		return size;
	}

	Iterator getBase()
	{
		return base;
	}

	// *******************************************************************
	// Access operators
	// *******************************************************************

	typename Iterator::reference operator*() const
	{
		return base[size - 1];
	}

	typename Iterator::pointer operator->() const
	{
		return &(*base);
	}

	typename Iterator::reference operator[](std::size_t index)
	{
		return base[index * size + size - 1];
	}

	typename Iterator::reference operator[](std::size_t index) const
	{
		return base[index * size + size - 1];
	}

	// *******************************************************************
	// Increment/decrement operators
	// *******************************************************************

	IteratorGroup &operator++()
	{
		base += size;
		return *this;
	}

	IteratorGroup operator++(int)
	{
		IteratorGroup temp = *this;
		++(*this);
		return temp;
	}

	IteratorGroup &operator--()
	{
		base -= size;
		return *this;
	}

	IteratorGroup operator--(int)
	{
		IteratorGroup temp = *this;
		--(*this);
		return temp;
	}

	// *******************************************************************
	// Assignment operators
	// *******************************************************************

	IteratorGroup &operator+=(std::size_t n)
	{
		base += n * size;
		return *this;
	}

	IteratorGroup &operator-=(std::size_t n)
	{
		base -= n * size;
		return *this;
	}

	IteratorGroup &operator=(const IteratorGroup &rhs)
	{
		if (this != &rhs)
		{
			base = rhs.base;
			size = rhs.size;
		}
		return *this;
	}

	// *******************************************************************
	// Arithmetic operators
	// *******************************************************************

	IteratorGroup operator+(std::size_t n) const
	{
		return IteratorGroup(base + n * size, size);
	}

	IteratorGroup operator-(std::size_t n) const
	{
		return IteratorGroup(base - n * size, size);
	}

	std::ptrdiff_t operator-(IteratorGroup &rhs)
	{
		return (base - rhs.base) / static_cast<std::ptrdiff_t>(size);
	}

	// *******************************************************************
	// Comparison operators
	// *******************************************************************

	bool operator==(const IteratorGroup &rhs) const
	{
		return base == rhs.base;
	}

	bool operator!=(const IteratorGroup &rhs) const
	{
		return base != rhs.base;
	}

	bool operator>=(const IteratorGroup &rhs) const
	{
		return base >= rhs.base;
	}

	bool operator<=(const IteratorGroup &rhs) const
	{
		return base <= rhs.base;
	}

	bool operator<(const IteratorGroup &rhs) const
	{
		return base < rhs.base;
	}

	bool operator>(const IteratorGroup &rhs) const
	{
		return base > rhs.base;
	}
};

typedef IteratorGroup<std::vector<int>::iterator> VectorItGroup;
typedef IteratorGroup<std::deque<int>::iterator> DequeItGroup;

// *******************************************************************
// Utils
// *******************************************************************

std::ostream &operator<<(std::ostream &stream, std::vector<int> &vector);
std::ostream &operator<<(std::ostream &stream, std::vector<VectorItGroup> &vector);
std::ostream &operator<<(std::ostream &stream, std::deque<int> &deque);
std::ostream &operator<<(std::ostream &stream, std::deque<DequeItGroup> &deque);

template <typename T>
bool isSorted(T &container)
{
	int prev = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it < prev)
			return false;
		prev = *it;
	}
	return true;
}

template <typename T>
void printGroups(IteratorGroup<T> &begin, IteratorGroup<T> &end)
{
	std::size_t size = begin.getSize();
	std::size_t count = 0;
	for (T it = begin.getBase(); it != end.getBase(); it++)
	{
		if (count++ % size == 0)
			std::cout << "| ";
		std::cout << *it << " ";
	}
	std::cout << "|" << std::endl;
}

// *******************************************************************
// Algo
// *******************************************************************

// true if a is bigger than b
template <typename T>
bool compare(IteratorGroup<T> a, IteratorGroup<T> b)
{
#if DEBUG
	comparisons++;
#endif
	return *a > *b;
}

template <typename T>
T find(T begin, T end, int value)
{
	for (; begin != end; begin++)
	{
		if (*begin == value)
			return begin;
	}
	throw std::logic_error("function 'find' should always find the value");
}

void mergeSort(VectorItGroup begin, VectorItGroup end);
void mergeSort(DequeItGroup begin, DequeItGroup end);

#endif