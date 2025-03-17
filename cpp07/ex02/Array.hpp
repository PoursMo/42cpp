#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *array;
	unsigned int _size;

public:
	Array() : array(0), _size(0) {}

	Array(const unsigned int size) : array(new T[size]), _size(size) {}

	Array(const Array &rhs) : array(0), _size(0)
	{
		*this = rhs;
	}

	Array &operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			delete[] array;
			_size = rhs._size;
			array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
				array[i] = rhs.array[i];
			}
		}
		return *this;
	}

	~Array()
	{
		delete[] array;
	}

	T &operator[](const unsigned int pos)
	{
		if (pos >= _size)
		{
			throw std::out_of_range("Index out of range");
		}
		return (array[pos]);
	}

	unsigned int size() const
	{
		return _size;
	}
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
	{
		stream << array[i];
		if (i != array.size() - 1)
			stream << ", ";
	}
	return stream;	
}

#endif