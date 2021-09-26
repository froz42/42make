/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/26 16:09:28 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>
#include <iostream>
#include <string>


template <typename T>
std::string string_vector(TESTED_NAMESPACE::vector<T> &v)
{
	std::ostringstream ss;

	ss << "{";
	for (typename TESTED_NAMESPACE::vector<T>::iterator it = v.begin(); it != v.end(); ++it)
	{
		ss << *it;
		if (it != v.end() - 1)
			ss << ", ";
	}
	ss << "}";
	return ss.str();
}

void test_constructor()
{
	module_head("vector::constructor");
	TESTED_NAMESPACE::vector<int> v1; // default constructor
	TESTED_NAMESPACE::vector<int> v2(5); // size constructor
	TESTED_NAMESPACE::vector<int> v3(5, 42); // size and value constructor
	TESTED_NAMESPACE::vector<int> v4(v3); // copy constructor
	TESTED_NAMESPACE::vector<int> v5(v3.begin(), v3.end()); // iterator constructor
	module_foot();

	module_test("vector v1", string_vector(v1));
	module_test("vector v2", string_vector(v2));
	module_test("vector v3", string_vector(v3));
	module_test("vector v4", string_vector(v4));
	module_test("vector v5", string_vector(v5));

	module_test("vector::constructor (default)", string_vector(v1));
	module_test("vector::constructor (size)", string_vector(v2));
	module_test("vector::constructor (size and value)", string_vector(v3));
	module_test("vector::constructor (copy)", string_vector(v4));
	module_test("vector::constructor (iterator)", string_vector(v5));

	module_test("vector::constructor (default) (size)", v1.size());
	module_test("vector::constructor (size) (size)", v2.size());
	module_test("vector::constructor (size and value) (size)", v3.size());
	module_test("vector::constructor (copy) (size)", v4.size());
	module_test("vector::constructor (iterator) (size)", v5.size());

	module_test("vector::constructor (default) (capacity)", v1.capacity());
	module_test("vector::constructor (size) (capacity)", v2.capacity());
	module_test("vector::constructor (size and value) (capacity)", v3.capacity());
	module_test("vector::constructor (copy) (capacity)", v4.capacity());
	module_test("vector::constructor (iterator) (capacity)", v5.capacity());

	module_test("vector::constructor (default) (empty)", v1.empty());
	module_test("vector::constructor (size) (empty)", v2.empty());
	module_test("vector::constructor (size and value) (empty)", v3.empty());
	module_test("vector::constructor (copy) (empty)", v4.empty());
	module_test("vector::constructor (iterator) (empty)", v5.empty());

	//module_test("vector::constructor (default) (front)", v1.front());
	module_test("vector::constructor (size) (front)", v2.front());
	module_test("vector::constructor (size and value) (front)", v3.front());
	module_test("vector::constructor (copy) (front)", v4.front());
	module_test("vector::constructor (iterator) (front)", v5.front());

	//module_test("vector::constructor (default) (back)", v1.back());
	module_test("vector::constructor (size) (back)", v2.back());
	module_test("vector::constructor (size and value) (back)", v3.back());
	module_test("vector::constructor (copy) (back)", v4.back());
	module_test("vector::constructor (iterator) (back)", v5.back());

	module_head("at throw");
	try
	{
		v1.at(0);
		std::cout << "KO" << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << "OK" << std::endl;
	}
	module_foot();
	module_test("vector::constructor (size) (at)", v2.at(0));
	module_test("vector::constructor (size and value) (at)", v3.at(0));
	module_test("vector::constructor (copy) (at)", v4.at(0));
	module_test("vector::constructor (iterator) (at)", v5.at(0));

	//module_test("vector::constructor (default) (operator[]", &v1[0]);
	module_test("vector::constructor (size) (operator[])", v2[0]);
	module_test("vector::constructor (size and value) (operator[])", v3[0]);
	module_test("vector::constructor (copy) (operator[])", v4[0]);
	module_test("vector::constructor (iterator) (operator[])", v5[0]);

	//module_test("vector::constructor (default) (begin)", &*(v1.begin()));
	module_test("vector::constructor (size) (begin)", *v2.begin());
	module_test("vector::constructor (size and value) (begin)", *v3.begin());
	module_test("vector::constructor (copy) (begin)", *v4.begin());
	module_test("vector::constructor (iterator) (begin)", *v5.begin());

	//module_test("vector::constructor (default) (end)", &*(v1.end()));
	module_test("vector::constructor (size) (end)", *(v2.end() - 1));
	module_test("vector::constructor (size and value) (end)", *(v3.end() - 1));
	module_test("vector::constructor (copy) (end)", *(v4.end() - 1));
	module_test("vector::constructor (iterator) (end)", *(v5.end() - 1));

	//module_test("vector::constructor (default) (rbegin)", &*(v1.rbegin()));
	module_test("vector::constructor (size) (rbegin)", *v2.rbegin());
	module_test("vector::constructor (size and value) (rbegin)", *v3.rbegin());
	module_test("vector::constructor (copy) (rbegin)", *v4.rbegin());
	module_test("vector::constructor (iterator) (rbegin)", *v5.rbegin());

	//module_test("vector::constructor (default) (rend)", &*(v1.rend()));
	module_test("vector::constructor (size) (rend)", *(v2.rend() - 1));
	module_test("vector::constructor (size and value) (rend)", *(v3.rend() - 1));
	module_test("vector::constructor (copy) (rend)", *(v4.rend() - 1));
	module_test("vector::constructor (iterator) (rend)", *(v5.rend() - 1));
}

void test_operator_assign()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);
	TESTED_NAMESPACE::vector<int> v4(v2);

	module_head("vector::operator=");
	v4 = v1;
	v1 = v2;
	v2 = v3;
	std::cout << string_vector(v1) << std::endl;
	std::cout << "v1::size: " << v1.size() << std::endl;
	std::cout << "v1::capacity: " << v1.capacity() << std::endl;
	std::cout << string_vector(v2) << std::endl;
	std::cout << "v2::size: " << v2.size() << std::endl;
	std::cout << "v2::capacity: " << v2.capacity() << std::endl;
	std::cout << string_vector(v3) << std::endl;
	std::cout << "v3::size: " << v3.size() << std::endl;
	std::cout << "v3::capacity: " << v3.capacity() << std::endl;
	std::cout << string_vector(v4) << std::endl;
	std::cout << "v4::size: " << v4.size() << std::endl;
	std::cout << "v4::capacity: " << v4.capacity() << std::endl;
	module_foot();
}

void test_begin_end()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::begin");
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	module_foot();
}

void test_rbegin_rend()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::rbegin");
	for (TESTED_NAMESPACE::reverse_iterator<TESTED_NAMESPACE::vector<int>::iterator > it = v1.rbegin(); it != v1.rend(); ++it)\
		std::cout << *it << "; ";
	for (TESTED_NAMESPACE::reverse_iterator<TESTED_NAMESPACE::vector<int>::iterator > it = v2.rbegin(); it != v2.rend(); ++it)\
		std::cout << *it << "; ";
	std::cout << std::endl;
	for (TESTED_NAMESPACE::reverse_iterator<TESTED_NAMESPACE::vector<int>::iterator > it = v3.rbegin(); it != v3.rend(); ++it)\
		std::cout << *it << "; ";
	std::cout << std::endl;
	module_foot();
}

void test_size()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::size");
	std::cout << v1.size() << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v3.size() << std::endl;
	module_foot();
}

void  test_max_size()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::max_size");
	std::cout << v1.max_size() << std::endl;
	std::cout << v2.max_size() << std::endl;
	std::cout << v3.max_size() << std::endl;
	module_foot();
}

void test_capacity()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::capacity");
	std::cout << v1.capacity() << std::endl;
	std::cout << v2.capacity() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
}

void test_reserve()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::reserve");
	v1.reserve(42);
	v2.reserve(42);
	v3.reserve(42);
	std::cout << v1.capacity() << std::endl;
	std::cout << v2.capacity() << std::endl;
	std::cout << v3.capacity() << std::endl;
	v1.reserve(1);
	v2.reserve(1);
	v3.reserve(1);
	std::cout << v1.capacity() << std::endl;
	std::cout << v2.capacity() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
}

void test_operator_at()
{
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::operator[]");
	std::cout << v2[0] << std::endl;
	std::cout << v2[1] << std::endl;
	std::cout << v2[2] << std::endl;
	std::cout << v2[3] << std::endl;
	std::cout << v2[4] << std::endl;
	std::cout << v3[0] << std::endl;
	std::cout << v3[1] << std::endl;
	std::cout << v3[2] << std::endl;
	std::cout << v3[3] << std::endl;
	v3[0] = -10;
	v3[1] = -10;
	string_vector(v3);
	module_foot();
}

void test_at()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::at");
	try
	{
		std::cout << v1.at(0) << std::endl;
		std::cout << "KO" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << "OK" << std::endl;
	}
	std::cout << v2.at(0) << std::endl;
	std::cout << v2.at(1) << std::endl;
	std::cout << v2.at(2) << std::endl;

	std::cout << v3.at(0) << std::endl;
	std::cout << v3.at(1) << std::endl;
	v3.at(0) = -10;
	v3.at(1) = -10;
	std::cout << string_vector(v3) << std::endl;
	module_foot();
}

void test_front_back()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::front");
	std::cout << &v1.front() << std::endl;
	std::cout << v2.front() << std::endl;
	std::cout << v3.front() << std::endl;
	module_foot();
	module_head("vector::back");
	std::cout << &v1.back() << std::endl;
	std::cout << v2.back() << std::endl;
	std::cout << v3.back() << std::endl;
	module_foot();
}

void test_assign()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);

	module_head("vector::assign (time");
	for (size_t i = 0; i < 10000; i++)
		v1.assign(420, 60);
	module_foot();
	module_head("vector::assign (size, value)");
	v1.assign(10, 5);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(15, 3);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(4, 4);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(5, 0);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(6, -1);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(5, -42);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(0, 40);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	module_foot();
	module_head("vector::assign (iterator, iterator)");
	v1.assign(v2.begin() + 5, v2.end());
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.assign(v2.begin(), v2.begin());
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	module_foot();
}

void test_push_back()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 10);

	module_head("vector::push_back (time)");
	for (int i = 0; i < 100000; i++)
		v1.push_back(i);
	module_foot();

	module_head("vector::push_back (value)");
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.push_back(32);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v2.push_back(32);
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	v3.push_back(32);
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
}

void test_pop_back()
{
	TESTED_NAMESPACE::vector<int> v(10000, 42);

	module_head("vector::pop_back (time)");
	for (size_t i = 0; i < 10000; i++)
		v.pop_back();
	module_foot();
	module_head("vector::push_back (value)");
	std::cout << string_vector(v) << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	v.assign(40, 42);
	v.pop_back();
	std::cout << string_vector(v) << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	v.pop_back();
	std::cout << string_vector(v) << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	v.pop_back();
	std::cout << string_vector(v) << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	module_foot();
}

void test_insert()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(5, 5);

	module_head("vector::insert (time)");
	for (int i = 0; i < 100; i++)
		v2.insert(v2.begin() + 3, i);
	module_foot();
	module_head("vector::insert (iterator, value) (content)");
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	module_foot();
	module_head("vector::insert (iterator, value) empty");
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 42);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	module_foot();
	module_head("vector::insert (iterator, value)");
	v3.insert(v3.begin() + 2, 42);
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	v3.insert(v3.begin() + 2, 42);
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
	module_head("vector::insert (iterator, iterator, iterator)");
	TESTED_NAMESPACE::vector<int> v4;
	v4.insert(v4.begin(), v2.begin(), v2.end());
	std::cout << string_vector(v4) << std::endl;
	std::cout << v4.size() << std::endl;
	std::cout << v4.capacity() << std::endl;
	v4.insert(v4.begin() + 3, v2.begin(), v2.end());
	std::cout << string_vector(v4) << std::endl;
	std::cout << v4.size() << std::endl;
	std::cout << v4.capacity() << std::endl;
	module_foot();
}

void test_erase()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(10000, 10000);
	TESTED_NAMESPACE::vector<int> v3(5, 5);
	v2.erase(v2.begin());

	module_head("vector::erase (iterator) (content)");
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	module_foot();
	/* THIS CRASH BOTH CASE
	module_head("vector::erase (iterator) empty");
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	v1.erase(v1.begin());
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	*/
	module_head("vector::erase (iterator)");
	std::cout << *v3.erase(v3.begin() + 2) << std::endl;
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
	module_head("vector::erase (iterator, iterator)");
	TESTED_NAMESPACE::vector<int> v4(42, 42);
	std::cout << *v4.erase(v4.begin() + 2, v4.end() - 10) << std::endl;
	std::cout << string_vector(v4) << std::endl;
	std::cout << v4.size() << std::endl;
	std::cout << v4.capacity() << std::endl;
	module_foot();
	/* CRASH ON STL
	module_head("vector::erase (iterator) with end");
	v3.erase(v3.end());
	std::cout << string_vector(v3) << std::endl;
	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;
	module_foot();
	*/
}

void test_swap()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);

	module_head("vector::swap (time)");
	for (int i = 0; i < 10000; i++)
		v2.swap(v1);
	module_foot();

	module_head("vector::swap (content)");
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	module_foot();
}

void test_clear()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);

	module_head("vector::clear");
	v2.clear();
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	module_foot();
	module_head("vector::clear (empty)");
	v1.clear();
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	module_foot();
}

void test_get_allocator()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<std::string> v2;

	module_head("vector::get_allocator");
	TESTED_NAMESPACE::vector<int>::allocator_type alloc1 = v1.get_allocator();
	TESTED_NAMESPACE::vector<std::string>::allocator_type alloc2 = v2.get_allocator();
	int *p1 = alloc1.allocate(1);
	std::string *p2 = alloc2.allocate(1);
	alloc1.construct(p1, 42);
	alloc2.construct(p2, "42");
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	alloc1.destroy(p1);
	alloc2.destroy(p2);
	alloc1.deallocate(p1, 1);
	alloc2.deallocate(p2, 1);
	module_foot();
}

void test_relational_operators()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::vector<int> v3(42, 5);
	TESTED_NAMESPACE::vector<int> v4(33, 5);

	module_head("vector::operator==");
	std::cout << (v1 == v2) << std::endl;
	std::cout << (v2 == v3) << std::endl;
	std::cout << (v3 == v4) << std::endl;
	module_foot();
	module_head("vector::operator!=");
	std::cout << (v1 != v2) << std::endl;
	std::cout << (v2 != v3) << std::endl;
	std::cout << (v3 != v4) << std::endl;
	module_foot();
	module_head("vector::operator<");
	std::cout << (v1 < v2) << std::endl;
	std::cout << (v2 < v3) << std::endl;
	std::cout << (v3 < v4) << std::endl;
	module_foot();
	module_head("vector::operator<=");
	std::cout << (v1 <= v2) << std::endl;
	std::cout << (v2 <= v3) << std::endl;
	std::cout << (v3 <= v4) << std::endl;
	module_foot();
	module_head("vector::operator>");
	std::cout << (v1 > v2) << std::endl;
	std::cout << (v2 > v3) << std::endl;
	std::cout << (v3 > v4) << std::endl;
	module_foot();
	module_head("vector::operator>=");
	std::cout << (v1 >= v2) << std::endl;
	std::cout << (v2 >= v3) << std::endl;
	std::cout << (v3 >= v4) << std::endl;
	module_foot();
}

void test_swap_nonmember()
{
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<int> v2(42, 5);

	module_head("vector::swap (non-member)");
	TESTED_NAMESPACE::swap(v1, v2);
	std::cout << string_vector(v1) << std::endl;
	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;
	std::cout << string_vector(v2) << std::endl;
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	module_foot();
}

void test_vector(void)
{
	test_constructor();
	test_operator_assign();
	test_begin_end();
	test_rbegin_rend();
	test_size();
	test_max_size();
	test_capacity();
	test_operator_at();
	test_at();
	test_front_back();
	test_assign();
	test_push_back();
	test_pop_back();
	test_insert();
	test_erase();
	test_swap();
	test_clear();
	test_get_allocator();
	test_relational_operators();
	test_swap_nonmember();
}
