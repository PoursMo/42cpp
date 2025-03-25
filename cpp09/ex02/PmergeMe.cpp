#include "PmergeMe.hpp"

// *******************************************************************
// Monitoring
// *******************************************************************

#if DEBUG
static int maxComparisons(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(std::ceil(log2(value)));
	}
	return sum;
}
#endif

Monitor::Monitor(const int size, const std::string &container) : range_size(size), container_type(container)
{
	timeval tp;
	gettimeofday(&tp, NULL);
	start_time = tp.tv_sec + tp.tv_usec / 1000000.0;
}

Monitor::~Monitor()
{
}

void Monitor::stop()
{
	timeval tp;
	gettimeofday(&tp, NULL);
	time = (tp.tv_sec + tp.tv_usec / 1000000.0) - start_time;
}

void Monitor::print() const
{
	std::cout << "******************************************\n";
	std::cout << std::setw(25) << std::left << "Container type: " << BRED << container_type << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Range size: " << BYEL << range_size << "\n"
			  << CRESET;
	std::cout << std::setw(25) << std::left << "Time: " << BCYN << std::fixed << time << " s\n"
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
// Utils
// *******************************************************************

std::ostream &operator<<(std::ostream &stream, std::vector<int> &vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, std::vector<VectorItGroup> &vector)
{
	for (std::vector<VectorItGroup>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		stream << **it << " ";
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, std::deque<int> &deque)
{
	for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		stream << *it << " ";
	}
	return stream;
}

std::ostream &operator<<(std::ostream &stream, std::deque<DequeItGroup> &deque)
{
	for (std::deque<DequeItGroup>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		stream << **it << " ";
	}
	return stream;
}

// *******************************************************************
// Algo
// *******************************************************************

static const long jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

static std::vector<VectorItGroup>::iterator binarySearch(VectorItGroup target, std::vector<VectorItGroup> &vector)
{
	typename std::vector<VectorItGroup>::iterator left = vector.begin();
	typename std::vector<VectorItGroup>::iterator right = std::find(vector.begin(), vector.end(), target - 1) + 1;
	while (left < right)
	{
		typename std::vector<VectorItGroup>::iterator mid = left + (right - left) / 2;
		if (compare(*mid, target))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

static std::deque<DequeItGroup>::iterator binarySearch(DequeItGroup target, std::deque<DequeItGroup> &deque)
{
	typename std::deque<DequeItGroup>::iterator left = deque.begin();
	typename std::deque<DequeItGroup>::iterator right = std::find(deque.begin(), deque.end(), target - 1) + 1;
	while (left < right)
	{
		typename std::deque<DequeItGroup>::iterator mid = left + (right - left) / 2;
		if (compare(*mid, target))
			right = mid;
		else
			left = mid + 1;
	}
	return left;
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

void mergeSort(DequeItGroup begin, DequeItGroup end)
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
	DequeItGroup last = size & 1 ? end - 1 : end;
	for (DequeItGroup it = begin; it != last; it += 2)
	{
		if (compare(it, it + 1))
			it.swap(it + 1);
	}
#if DEBUG
	printGroups(begin, end);
	std::cout << std::endl;
#endif
	mergeSort(DequeItGroup(begin, begin.getSize() * 2), DequeItGroup(last, last.getSize() * 2));
	std::deque<DequeItGroup> main;
	main.push_back(begin);
	main.push_back(begin + 1);
	for (int i = 2; begin + i != end; i++)
	{
		if (i % 2 != 0)
			main.push_back(begin + i);
	}
	std::deque<DequeItGroup> pend;
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
			std::deque<DequeItGroup>::iterator insert_point = binarySearch(pend[index], main);
			main.insert(insert_point, pend[index]);
#if DEBUG
			std::cout << "inserting: '" << *pend[index] << "'\n";
			std::cout << "main: " << main << std::endl;
#endif
		}
	}
	std::deque<int> main_copy;
	for (std::deque<DequeItGroup>::iterator it = main.begin(); it != main.end(); it++)
	{
		main_copy.push_back(**it);
	}
	for (size_t i = 0; i < main_copy.size(); i++)
	{
		if (*(begin + i) != main_copy[i])
		{
			DequeItGroup ptr = find(begin + i, end, main_copy[i]);
			ptr.swap(begin + i);
		}
	}
#if DEBUG
	std::cout << std::endl;
#endif
}