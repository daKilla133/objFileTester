#include <iostream>
#include <boost\algorithm\algorithm.hpp>
#include "ObjLoader.cpp"
#include <string>
int main()
{
	ObjIntermediate ob;
	ob.LoadObj("../res/cube.obj");

	std::cin.get();
	return 0;
}