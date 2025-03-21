#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &cont, const int &param)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), param);
	if (it == cont.end())
		throw std::logic_error("could not find parameter in container");
	return (it);
}

#endif