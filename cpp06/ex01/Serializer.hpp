#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &rhs);
	Serializer &operator=(const Serializer &rhs);
	~Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif