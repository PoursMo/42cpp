#include "PmergeMe.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <algorithm>
#include <sys/time.h>
#include <cmath>
#include <sstream>

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

int comparisons = 0;

int maxComparisons(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(std::ceil(log2(value)));
	}
	return sum;
}

class Monitor
{
private:
	suseconds_t start_usecs;
	unsigned int range_size;
	std::string container_type;
	Monitor();
	Monitor(const Monitor &rhs);
	Monitor &operator=(const Monitor &rhs);

public:
	Monitor(const int size, const std::string &container);
	~Monitor();
};

Monitor::Monitor(const int size, const std::string &container) : range_size(size), container_type(container)
{
	timeval tp;
	gettimeofday(&tp, NULL);
	start_usecs = tp.tv_usec;
}

Monitor::~Monitor()
{
	timeval tp;
	gettimeofday(&tp, NULL);
	suseconds_t time = tp.tv_usec - start_usecs;
	int max_comp = maxComparisons(range_size);
	std::cout << "******************************************\n";
	std::cout << std::setw(25) << std::left << "Container type: " << BRED << container_type << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Range size: " << BYEL << range_size << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Time: " << BCYN << time << " us\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Max nb comparisons: " << BGRN << max_comp << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Comparisons count: " << BMAG << comparisons << "\n"
			  << CRESET;
	std::cout << "******************************************" << std::endl;
}

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

// *******************************************************************
// Utils
// *******************************************************************

std::ostream &operator<<(std::ostream &stream, std::vector<int> &container)
{
	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
			stream << ", ";
		stream << *it;
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, std::vector<VectorItGroup> &container)
{
	for (std::vector<VectorItGroup>::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
			stream << ", ";
		stream << *(*it);
	}
	return stream;
}

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
	for (IteratorGroup<T> it = begin; it != end; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// *******************************************************************
// Algo
// *******************************************************************

static const long jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

// true if a is bigger than b
template <typename T>
bool compare(IteratorGroup<T> a, IteratorGroup<T> b)
{
	comparisons++;
	return *a > *b;
}

// true if a is bigger than b
bool compare(int a, int b)
{
	comparisons++;
	return a > b;
}

int binarySearch(int T, std::vector<VectorItGroup> &vector)
{
	int L = 0;
	int R = vector.size() - 1;
	while (L <= R)
	{
		int m = (L + R) / 2;
		if (compare(T, *(vector[m])))
			L = m + 1;
		else if (compare(*(vector[m]), T))
			R = m - 1;
		else
			return m;
	}
	return L;
}

void mergeSort(VectorItGroup begin, VectorItGroup end)
{
	printGroups(begin, end); // debug
	std::ptrdiff_t distance = end - begin;
	std::cout << "distance: " << distance << std::endl; // debug
	if (distance < 2)
		return;
	VectorItGroup last = distance & 1 ? end - 1 : end;
	for (VectorItGroup it = begin; it != last; it += 2)
	{
		if (compare(it, it + 1))
			it.swap(it + 1);
	}
	printGroups(begin, end); // debug
	mergeSort(VectorItGroup(begin, begin.getSize() * 2), VectorItGroup(last, last.getSize() * 2));
	std::vector<VectorItGroup> main;
	main.push_back(begin);
	main.push_back(begin + 1);
	for (int i = 2; begin + i != end; i++)
	{
		if (i % 2 != 0)
			main.push_back(begin + i);
	}
	std::cout << "main: " << main << std::endl; // debug
	std::vector<VectorItGroup> pend;
	for (int i = 2; begin + i != end; i++)
	{
		if (i % 2 == 0)
			pend.push_back(begin + i);
	}
	std::cout << "pend: " << pend << std::endl; // debug
	std::size_t i = 0;
	while (static_cast<long>(pend.size()) > jacobsthal[i] - 1)
	{
		i++;
		int index = jacobsthal[i] - 1;
		if (static_cast<int>(pend.size()) < index)
			index = pend.size();
		std::cout << "inserting: "; // debug
		while (--index >= jacobsthal[i - 1] - 1)
		{
			std::cout << *(pend[index]) << ", at: "; // debug
			std::cout << binarySearch(*(pend[index]), main) << "\n";
			// actual insert
			// in main
			// for real
		}
		std::cout << std::endl; // debug
	}
}

int main(int argc, char **argv)
{
	std::vector<int> container;
	for (int i = 1; i < argc; i++)
	{
		int value;
		if (std::sscanf(argv[i], "%d", &value) != 1 || value < 0)
		{
			std::cerr << "Error: use positive integers only" << std::endl;
			return 1;
		}
		container.push_back(value);
	}
	if (isSorted(container)) // try without
	{
		std::cout << "array is already sorted" << std::endl;
		return 0;
	}
	// std::cout << "Before: " << container << std::endl;
	{
		Monitor monitor(container.size(), "std::vector");
		mergeSort(VectorItGroup(container.begin(), 1), VectorItGroup(container.end(), 1));
		// std::cout << "After: " << container << std::endl;
	}
	comparisons = 0;
	{
		// Monitor monitor(container.size(), "std::vector");
		// other container
	}
}