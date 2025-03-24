#include "PmergeMe.hpp"

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <sys/time.h>

class Timer
{
private:
	suseconds_t start_usecs;
	unsigned int range_size;
	std::string container_type;
	Timer();
	Timer(const Timer &rhs);
	Timer &operator=(const Timer &rhs);

public:
	Timer(const int size, const std::string &container);
	~Timer();
};

Timer::Timer(const int size, const std::string &container) : range_size(size), container_type(container)
{
	timeval tp;
	gettimeofday(&tp, NULL);
	start_usecs = tp.tv_usec;
}

Timer::~Timer()
{
	timeval tp;
	gettimeofday(&tp, NULL);
	suseconds_t diff = tp.tv_usec - start_usecs;
	std::cout << "Time to process a range of " << range_size << " elements with " << container_type << ": " << diff << " μs" << std::endl;
}

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

template <typename Iterator>
class SizedIterator
{
private:
	Iterator it;
	std::size_t step_size;
	SizedIterator();

public:
	SizedIterator(const Iterator &iterator, std::size_t size) : it(iterator), step_size(size) {}

	// SizedIterator(const SizedIterator &rhs) : it(rhs.it), step_size(rhs.step_size) {}

	SizedIterator(const SizedIterator &rhs, std::size_t size) : it(rhs.it), step_size(size) {}

	void swap(SizedIterator rhs)
	{
		std::swap_ranges(it - step_size + 1, it + 1, rhs.it - rhs.step_size + 1);
	}

	ptrdiff_t distance(SizedIterator rhs)
	{
		return std::distance(it - step_size + 1, rhs.it - rhs.step_size + 1);
	}

	Iterator getIterator()
	{
		return it;
	}

	std::size_t getSize()
	{
		return step_size;
	}

	typename Iterator::reference operator*() const
	{
		return *it;
	}

	typename Iterator::pointer operator->() const
	{
		return &(*it);
	}

	SizedIterator &operator++()
	{
		std::advance(it, step_size);
		return *this;
	}

	SizedIterator operator++(int)
	{
		SizedIterator temp = *this;
		std::advance(it, step_size);
		return temp;
	}

	typename Iterator::reference operator[](std::size_t index) const
	{
		Iterator temp = it;
		std::advance(temp, index * step_size);
		return *temp;
	}

	SizedIterator &operator+=(std::size_t n)
	{
		std::advance(it, n * step_size);
		return *this;
	}

	SizedIterator operator+(std::size_t n) const
	{
		Iterator temp = it;
		std::advance(temp, n * step_size);
		return SizedIterator(temp, step_size);
	}

	SizedIterator operator-(std::size_t n) const
	{
		Iterator temp = it;
		std::advance(temp, -n * step_size);
		return SizedIterator(temp, step_size);
	}

	std::ptrdiff_t operator-(const SizedIterator &rhs) const
	{
		return std::distance(rhs.it, it) / static_cast<std::ptrdiff_t>(step_size);
	}

	bool operator==(const SizedIterator &rhs) const
	{
		return it == rhs.it;
	}

	bool operator!=(const SizedIterator &rhs) const
	{
		return it != rhs.it;
	}
};

template <typename T>
void printRange(SizedIterator<T> begin, SizedIterator<T> end)
{
	std::size_t count = 0;
	for (SizedIterator<T> it = begin; it != end; it++)
	{
		if (count++ % 2 == 0)
			std::cout << " | ";
		else
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << " | " << std::endl;
}

void mergeSort(SizedIterator<std::vector<int>::iterator> begin, SizedIterator<std::vector<int>::iterator> end)
{
	std::cout << "full: ";
	for (std::vector<int>::iterator it = begin.getIterator() - begin.getSize() + 1; it != end.getIterator() - end.getSize() + 1; it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	
	int distance = end - begin;
	std::cout << "distance: " << distance << std::endl;
	if (distance < 2)
		return;
	SizedIterator<std::vector<int>::iterator> last = distance & 1 ? end - 1 : end;
	std::cout << "before: ";
	printRange(begin, end);
	for (SizedIterator<std::vector<int>::iterator> it = begin; it != last; it += 2)
	{
		if (it[0] > it[1])
		{
			it.swap(it + 1);
		}
	}
	std::cout << "after: ";
	printRange(begin, end);
	std::cout << std::endl;
	mergeSort(SizedIterator(begin + 1, begin.getSize() * 2), SizedIterator(last + 1, last.getSize() * 2));
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
	if (isSorted(container))
	{
		std::cout << "array is already sorted" << std::endl;
		return 0;
	}
	Timer timer(container.size(), "std::vector");
	mergeSort(SizedIterator(container.begin(), 1), SizedIterator(container.end(), 1));
	std::cout << container << std::endl;
}