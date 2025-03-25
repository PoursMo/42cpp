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
// Debug
// *******************************************************************

#define DEBUG false
#if DEBUG
int level = 0;
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
	double start_time;
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
	start_time = tp.tv_sec + tp.tv_usec / 1000000.0;
}

Monitor::~Monitor()
{
	timeval tp;
	gettimeofday(&tp, NULL);
	double time = (tp.tv_sec + tp.tv_usec / 1000000.0) - start_time;
	std::cout << "******************************************\n";
	std::cout << std::setw(25) << std::left << "Container type: " << BRED << container_type << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Range size: " << BYEL << range_size << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Time: " << BCYN << time << " s\n"
			  << CRESET;
#if DEBUG
	std::cout << std::setw(25) << std::left << "Max nb comparisons: " << BGRN << maxComparisons(range_size) << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Comparisons count: " << BMAG << comparisons << "\n"
			  << CRESET;
#endif
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
		stream << *it << " ";
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

static const long jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

// true if a is bigger than b
template <typename T>
bool compare(IteratorGroup<T> a, IteratorGroup<T> b)
{
	comparisons++;
	return *a > *b;
}

std::vector<VectorItGroup>::iterator binarySearch(VectorItGroup T, std::vector<VectorItGroup> &vector)
{
	std::vector<VectorItGroup>::iterator left = vector.begin();
	std::vector<VectorItGroup>::iterator right = std::find(vector.begin(), vector.end(), T - 1) + 1;
	while (left < right)
	{
		std::vector<VectorItGroup>::iterator mid = left + (right - left) / 2;
		if (compare(*mid, T))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

VectorItGroup find(VectorItGroup begin, VectorItGroup end, int value)
{
	for (; begin != end; begin++)
	{
		if (*begin == value)
			return begin;
	}
	throw std::logic_error("function 'find' should always find the value");
}

void mergeSort(VectorItGroup begin, VectorItGroup end)
{
	std::ptrdiff_t size = end - begin;
	if (size < 2)
		return;
#if DEBUG
	level++;
	int my_level = level;
	std::cout << BRED << "level: " << my_level << CRESET << "\n";
	std::cout << "size: " << size << "\n";
	printGroups(begin, end);
#endif
	VectorItGroup last = size & 1 ? end - 1 : end;
	for (VectorItGroup it = begin; it != last; it += 2)
	{
		if (compare(it, it + 1))
			it.swap(it + 1);
	}
#if DEBUG
	printGroups(begin, end);
	std::cout << std::endl;
#endif
	mergeSort(VectorItGroup(begin, begin.getSize() * 2), VectorItGroup(last, last.getSize() * 2));
	std::vector<VectorItGroup> main;
	main.push_back(begin);
	main.push_back(begin + 1);
	for (int i = 2; begin + i != end; i++)
	{
		if (i % 2 != 0)
			main.push_back(begin + i);
	}
	std::vector<VectorItGroup> pend;
	for (int i = 2; begin + i != end; i++)
	{
		if (i % 2 == 0)
			pend.push_back(begin + i);
	}
#if DEBUG
	std::cout << BRED << "level: " << my_level << CRESET << "\n";
	printGroups(begin, end);
	std::cout << "pend: " << pend << "\n";
	std::cout << "main: " << main << std::endl;
#endif
	std::size_t i = 0;
	while (static_cast<long>(pend.size()) > jacobsthal[i] - 1)
	{
		i++;
		int index = jacobsthal[i] - 1;
		if (static_cast<int>(pend.size()) < index)
			index = pend.size();
		while (--index >= jacobsthal[i - 1] - 1)
		{
			std::vector<VectorItGroup>::iterator insert_point = binarySearch(pend[index], main);
			main.insert(insert_point, pend[index]);
#if DEBUG
			std::cout << "inserting: '" << *pend[index] << "'\n";
			std::cout << "main: " << main << std::endl;
#endif
		}
	}
	std::vector<int> main_copy;
	for (std::vector<VectorItGroup>::iterator it = main.begin(); it != main.end(); it++)
	{
		main_copy.push_back(**it);
	}
	for (size_t i = 0; i < main_copy.size(); i++)
	{
		if (*(begin + i) != main_copy[i])
		{
			VectorItGroup ptr = find(begin + i, end, main_copy[i]);
			ptr.swap(begin + i);
		}
	}
#if DEBUG
	std::cout << std::endl;
#endif
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
	{
		std::vector<int> copy(container);
		std::sort(copy.begin(), copy.end());
		if (std::adjacent_find(copy.begin(), copy.end()) != copy.end())
		{
			std::cerr << "Error: duplicate values are not allowed" << std::endl;
			return 1;
		}
	}
	// if (isSorted(container))
	// {
	// 	std::cout << "array is already sorted" << std::endl;
	// 	return 0;
	// }
	std::cout << "Before: " << container << std::endl;
	{
		Monitor monitor(container.size(), "std::vector");
		mergeSort(VectorItGroup(container.begin(), 1), VectorItGroup(container.end(), 1));
		std::cout << "After: " << container << std::endl;
	}
	comparisons = 0;
	{
		// Monitor monitor(container.size(), "std::vector");
		// other container
	}
}