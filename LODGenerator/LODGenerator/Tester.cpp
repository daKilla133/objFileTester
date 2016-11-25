#include <iostream>
#include "ObjLoader.cpp"

int main()
{
	ObjIntermediate ob;
	ob.LoadObj("../res/untitled.obj");

	std::cin.get();
	return 0;
}