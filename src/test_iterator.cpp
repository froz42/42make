/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:45:06 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 17:08:30 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>
#include <iostream>
#include <string>

bool mypredicate(int i, int j)
{
	return (i == j);
}

bool mycomp(char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

void test_equal_iterator(void)
{
	module_head("equal_iterator");
	int myints[] = {20, 40, 60, 80, 100};
	std::vector<int> myvector(myints, myints + 5);
	if (TESTED_NAMESPACE::equal(myvector.begin(), myvector.end(), myints))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3] = 81;

	if (TESTED_NAMESPACE::equal(myvector.begin(), myvector.end(), myints, mypredicate))
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";
	module_foot();
}

void test_lexicographical_compare_iterator(void)
{
	module_head("lexicographical_compare_iterator");
	char foo[] = "Apple";
	char bar[] = "apartment";

	std::cout << std::boolalpha;

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << TESTED_NAMESPACE::lexicographical_compare(foo, foo + 5, bar, bar + 9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << TESTED_NAMESPACE::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
	std::cout << '\n';
	module_foot();
}

void test_iterator(void)
{
	std::string str = "Hello World";

	TESTED_NAMESPACE::reverse_iterator<std::string::iterator> rbegin(str.end());
	TESTED_NAMESPACE::reverse_iterator<std::string::iterator> rend(str.begin());

	module_head("reverse_iterator");
	std::cout << "str: " << str << std::endl;
	std::cout << "rbegin: " << &(*rbegin) << std::endl;
	std::cout << "rend: " << &(*rend) << std::endl;
	for (; rbegin != rend; ++rbegin)
		std::cout << *rbegin << "; ";
	std::cout << std::endl;
	module_foot();
	test_equal_iterator();
	test_lexicographical_compare_iterator();
}
