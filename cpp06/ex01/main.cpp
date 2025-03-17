#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data = {1, 2};
	std::cout << "original pointer: " << &data << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "serialized value: " << serialized << std::endl;
	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized pointer: " << deserialized << std::endl;
}