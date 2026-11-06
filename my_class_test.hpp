#include <my_class.hpp>

#include <iostream>
#include <unordered_map>
#include <map>

void test_MyKeyClass()
{

	std::cout << "MyKeyClass TEST" << std::endl << std::endl;
	int passed = 0;
	int failed = 0;

	auto check = [&](bool condition, const std::string test_name)
		{
			if (condition)
			{
				std::cout << "PASSED - " << test_name << std::endl;
				passed++;
			}
			else
			{
				std::cout << "FAILED - " << test_name << std::endl;
				failed++;
			}
		};

	MyKeyClass a1(1, "Lupa", true);
	MyKeyClass a2(1, "Lupa", true);

	MyKeyClass b(2, "Pupa", false);
	MyKeyClass c(1, "Pupa", true);
	MyKeyClass d(1, "Lupa", false);

	// check operators

	std::cout << "OPERATORS TEST:" << std::endl;

	check(a1 == a2, "(==) Equal objests");
	check(!(a1 == b), "(==) Unequal objects");
	check(a1 != b, "(!=) Unequal objects");

	check(a1 < b, "(<) by id");
	check(a1 < c, "(<) by name");
	check(d < a1, "(<) by flag");

	// check std::map 

	std::cout << "MAP TEST:" << std::endl;

	std::map<MyKeyClass, int> ordinary_map;

	ordinary_map[a1] = 10;
	ordinary_map[b] = 20;
	ordinary_map[c] = 30;
	ordinary_map[d] = 40;

	check(ordinary_map.size() == 4, "(map) size");
	check(ordinary_map.at(c) == 30, "(map) find key");

	ordinary_map[a2] = 50; //duplicate key

	check(ordinary_map.size() == 4, "(map) duplicate key insert");


	// check unordered_map

	std::cout << "UNORDERED_MAP TEST:" << std::endl;

	std::unordered_map<MyKeyClass, int> unordered_map;

	unordered_map[a1] = 10;
	unordered_map[b] = 20;
	unordered_map[c] = 30;
	unordered_map[d] = 40;

	check(unordered_map.size() == 4, "(unordered_map) size");
	check(unordered_map.at(c) == 30, "(unordered_map) find key");

	unordered_map[a2] = 50; //duplicate key

	check(unordered_map.size() == 4, "(unordered_map) duplicate key insert");
	check(unordered_map.find(b) != unordered_map.end(), "(unordered_map) find equivalent key");

	std::cout << "\nResults: " << passed << " PASEED, " << failed << " FAILED" << std::endl;
}