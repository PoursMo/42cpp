#include "PmergeMe.hpp"

#if DEBUG
int comparisons = 0;
int level = 0;
#endif

int main(int argc, char **argv)
{
	std::vector<int> vector;
	std::deque<int> deque;
	for (int i = 1; i < argc; i++)
	{
		int value;
		if (std::sscanf(argv[i], "%d", &value) != 1 || value < 0)
		{
			std::cerr << "Error: use positive integers only" << std::endl;
			return 1;
		}
		vector.push_back(value);
		deque.push_back(value);
	}
	{
		std::vector<int> copy(vector);
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
	std::cout << std::setw(10) << std::left << "Before: " << vector << std::endl;
	{
		Monitor monitor(vector.size(), "std::vector");
		mergeSort(VectorItGroup(vector.begin(), 1), VectorItGroup(vector.end(), 1));
		monitor.stop();
		std::cout << std::setw(10) << std::left << "After: " << vector << std::endl;
		monitor.print();
	}
#if DEBUG
	comparisons = 0;
	level = 0;
#endif
	{
		Monitor monitor(deque.size(), "std::deque");
		mergeSort(DequeItGroup(deque.begin(), 1), DequeItGroup(deque.end(), 1));
		monitor.stop();
		monitor.print();
	}
}