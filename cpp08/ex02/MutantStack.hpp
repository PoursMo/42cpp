#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T, typename Pointer = T *, typename Reference = T &>
class MutantIterator
{
private:
	Pointer ptr;

public:
	MutantIterator(T *ptr) : ptr(ptr) {}
	MutantIterator &operator++()
	{
		ptr++;
		return *this;
	}
	MutantIterator operator++(int)
	{
		MutantIterator tmp = *this;
		ptr++;
		return tmp;
	}
	MutantIterator &operator--()
	{
		ptr--;
		return *this;
	}
	MutantIterator operator--(int)
	{
		MutantIterator tmp = *this;
		ptr--;
		return tmp;
	}
	MutantIterator operator+(int value)
	{
		return MutantIterator<T>(ptr + value);
	}
	MutantIterator operator-(int value)
	{
		return MutantIterator<T>(ptr - value);
	}
	long operator-(const MutantIterator &rhs)
	{
		return ptr - rhs.ptr;
	}
	MutantIterator &operator+=(int value)
	{
		*this = *this + value;
		return *this;
	}
	MutantIterator &operator-=(int value)
	{
		*this = *this - value;
		return *this;
	}
	Reference operator[](int pos)
	{
		return *(ptr + pos);
	}
	Pointer operator->()
	{
		return ptr;
	}
	Reference operator*()
	{
		return *ptr;
	}
	bool operator==(const MutantIterator &rhs)
	{
		return ptr == rhs.ptr;
	}
	bool operator!=(const MutantIterator &rhs)
	{
		return ptr != rhs.ptr;
	}
	bool operator<(const MutantIterator &rhs)
	{
		return ptr < rhs.ptr;
	}
	bool operator>(const MutantIterator &rhs)
	{
		return ptr > rhs.ptr;
	}
	bool operator<=(const MutantIterator &rhs)
	{
		return ptr <= rhs.ptr;
	}
	bool operator>=(const MutantIterator &rhs)
	{
		return ptr >= rhs.ptr;
	}
};

template <typename T>
MutantIterator<T> operator+(int value, MutantIterator<T> &iterator)
{
	return MutantIterator<T>(iterator + value);
}

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef MutantIterator<T> iterator;
	iterator begin()
	{
		return iterator(&this->c.front());
	}
	iterator end()
	{
		return iterator(&this->c.back() + 1);
	}
};

#endif