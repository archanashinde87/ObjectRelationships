// ReferenceWrapperInStdVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <string>
#include <vector>

int main()
{
	std::string arch{ "Archana" };
	std::string shanky{ "Shankar" };

	std::vector<std::reference_wrapper<std::string>> names{ arch,shanky };

	std::string yug{ "Yugan" };
	names.emplace_back(yug);

	for (auto name : names)
	{
		// Use the get() member function to get the referenced string.
		name.get() += " Shinde";
	}

	std::cout << yug << '\n'; // Yugan Shinde
	std::cout << arch << '\n'; // Archana Shinde
	std::cout << shanky << '\n'; // Shankar Shinde

	return 0;
}

