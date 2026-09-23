#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	std::vector<int> one_vector;
	for (int i = 1; i < 10; i++)
	{
		one_vector.push_back(i);
	}
	try{
		//buscando un numero que existe
		std::cout << "Buscando el 6 ..." << std::endl;
		std::vector<int>::iterator it = easyfind(one_vector, 6);
		std::cout << "obtenemos:" << *it << std::endl;
		//buscando un numero que no existe
			std::cout << "Buscando el 12 (no existe) ..." << std::endl;
		it = easyfind(one_vector, 12);
		std::cout << "obtenemos:" << *it << std::endl;
	}
	catch (const std::out_of_range &err)
	{
		std::cerr << "main: " << err.what() << std::endl; 
	}

	std::list<int> one_list;
	for (int i = 1; i < 10; i++)
	{
		one_list.push_back(i);
	}
	try{
		//buscando un numero que existe
		std::cout << "Buscando el 4 ..." << std::endl;
		std::list<int>::iterator it = easyfind(one_list, 4);
		std::cout << "obtenemos:" << *it << std::endl;
		//buscando un numero que no existe
			std::cout << "Buscando el 22 (no existe) ..." << std::endl;
		it = easyfind(one_list, 22);
		std::cout << "obtenemos:" << *it << std::endl;
	}
	catch (const std::out_of_range &err)
	{
		std::cerr << "main: " << err.what() << std::endl; 
	}

}