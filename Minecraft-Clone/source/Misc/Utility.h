#pragma once
#include <fstream>

#define BIT(x) 1 << x

static std::string LoadFile(const char* fileName)
{
	std::ifstream file{ fileName };

	return std::string((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
}