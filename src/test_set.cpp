/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:14:09 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 17:12:12 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>

template <class T>
std::string string_set(TESTED_NAMESPACE::set<T> &s)
{
	std::ostringstream ss;

	ss << "{";
	for (typename TESTED_NAMESPACE::set<T>::iterator it = s.begin(); it != s.end(); ++it)
	{
		ss << *it;
		if (it != s.end())
			ss << ", ";
	}
	ss << "}";
	return ss.str();
}

static void test_constructor(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	module_head("set::constructor(void)");
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "s1 size:" << s1.size() << std::endl;
	std::cout << "s1::empty" << s1.empty() << std::endl;
	std::cout << "s1::max_size" << s1.max_size() << std::endl;
	std::cout << "s1::clear: ";
	s1.clear();
	std::cout << s1.size() << std::endl;
	module_foot();
	TESTED_NAMESPACE::set<std::string> s2(s1);
	module_head("set::constructor(set<T>) empty");
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	std::cout << "s2 size:" << s2.size() << std::endl;
	std::cout << "s2::empty" << s2.empty() << std::endl;
	std::cout << "s2::clear: ";
	s2.clear();
	std::cout << s2.size() << std::endl;
	module_foot();
	s2.insert(std::string("test"));
	s2.insert(std::string("test2"));
	s2.insert(std::string("test3"));
	module_head("set::constructor(set<T>) insert test");
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	std::cout << "s2 size:" << s2.size() << std::endl;
	std::cout << "s2::empty" << s2.empty() << std::endl;
	std::cout << "s2::clear: ";
	s2.clear();
	std::cout << s2.size() << std::endl;
	module_foot();

	module_head("set::constructor(iterator, iterator) empty");
	TESTED_NAMESPACE::set<std::string> s3(s2.begin(), s2.end());
	std::cout << "s3 content:" << string_set(s3) << std::endl;
	std::cout << "s3 size:" << s3.size() << std::endl;
	std::cout << "s3::empty" << s3.empty() << std::endl;
	std::cout << "s3::clear: ";
	s3.clear();
	std::cout << s3.size() << std::endl;
	module_foot();
	module_head("set::constructor(iterator, iterator) not empty");
	s3.insert(std::string("test"));
	s3.insert(std::string("test2"));
	s3.insert(std::string("test3"));
	std::cout << "s3 content:" << string_set(s3) << std::endl;
	std::cout << "s3 size:" << s3.size() << std::endl;
	std::cout << "s3::empty" << s3.empty() << std::endl;
	TESTED_NAMESPACE::set<std::string> s4(s3.begin(), s3.end());
	std::cout << "s4 content:" << string_set(s4) << std::endl;
	std::cout << "s4 size:" << s4.size() << std::endl;
	std::cout << "s4::empty" << s4.empty() << std::endl;
	module_foot();

	module_head("set::constructor(const set<T> &)");
	TESTED_NAMESPACE::set<std::string> s5(s2);
	std::cout << "s5 content:" << string_set(s5) << std::endl;
	std::cout << "s5 size:" << s5.size() << std::endl;
	std::cout << "s5::empty" << s5.empty() << std::endl;
	std::cout << "s5::clear: ";
	s5.clear();
	std::cout << s5.size() << std::endl;
	module_foot();
}

static void test_insert(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::set<std::string>::iterator, bool> r;
	module_head("set::insert(T)");
	r = s1.insert(std::string("test"));
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "s1 size:" << s1.size() << std::endl;
	std::cout << "s1::empty" << s1.empty() << std::endl;
	std::cout << "s1::insert(test): " << r.second << std::endl;
	std::cout << "s1::insert(test): " << *r.first << std::endl;
	module_foot();

	module_head("set::insert(T) duplicate");
	r = s1.insert(std::string("test"));
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "s1 size:" << s1.size() << std::endl;
	std::cout << "s1::empty" << s1.empty() << std::endl;
	std::cout << "s1::insert(test): " << r.second << std::endl;
	std::cout << "s1::insert(test): " << *r.first << std::endl;
	module_foot();

	TESTED_NAMESPACE::set<std::string>::iterator it;

	module_head("set::insert(iterator, value)");
	it = s1.insert(s1.begin(), std::string("test"));
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "it: " << *it << std::endl;
	module_foot();

	module_head("set::insert(iterator, value) duplicate");
	it = s1.insert(s1.begin(), std::string("test"));
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "it: " << *it << std::endl;
	module_foot();

	TESTED_NAMESPACE::set<std::string> s2;

	module_head("set::insert(iterator, iterator)");
	s2.insert(s1.begin(), s1.end());
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	module_foot();

	module_head("set::insert(iterator, iterator) duplicate");
	s2.insert(s1.begin(), s1.end());
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	module_foot();

	module_head("set::insert(value) time");
	TESTED_NAMESPACE::set<std::string> s3;
	for (int i = 0; i < 10000; i++)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s3.insert(std::string(ss.str()));
	}
	module_foot();

	module_head("set::insert(value) size");
	std::cout << "s3 size:" << s3.size() << std::endl;
	module_foot();
}

static void test_assign_operator(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	TESTED_NAMESPACE::set<std::string> s2;

	module_head("set::=empty");
	s1 = s2;
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "s1 size:" << s1.size() << std::endl;
	std::cout << "s1::empty" << s1.empty() << std::endl;
	module_foot();

	module_head("set::=non-empty");
	s1.insert(std::string("test"));
	s1.insert(std::string("test2"));
	s2 = s1;
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	std::cout << "s2 size:" << s2.size() << std::endl;
	std::cout << "s2::empty" << s2.empty() << std::endl;
	module_foot();
}

static void test_iterators(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	TESTED_NAMESPACE::set<std::string>::iterator it;
	TESTED_NAMESPACE::set<std::string>::iterator it2;

	it = s1.begin();
	it2 = s1.end();
	module_test("set::begin() == map::end()", it == it2);
	s1.insert(std::string("test1"));
	s1.insert(std::string("test2"));
	s1.insert(std::string("test3"));
	s1.insert(std::string("test4"));
	s1.insert(std::string("test5"));

	module_head("set::begin()");
	it = s1.begin();
	std::cout << "*it: " << *it << std::endl;
	module_foot();

	module_head("set::end()");
	it2 = s1.end();
	for (it = s1.begin(); it != it2; ++it)
		std::cout << "*it: " << *it << std::endl;
	module_foot();

	TESTED_NAMESPACE::set<std::string>::reverse_iterator rit;
	module_head("set::rbegin()");
	for (rit = s1.rbegin(); rit != s1.rend(); ++rit)
		std::cout << "*rit: " << *rit << std::endl;
	module_foot();
}

static void test_capacity(void)
{
	TESTED_NAMESPACE::set<std::string> s1;

	module_test("set::size (empty)", s1.size());
	module_test("set::empty (empty)", s1.empty());
	module_test("set::max_size (empty)", s1.max_size());

	s1.insert(std::string("test1"));
	s1.insert(std::string("test2"));
	s1.insert(std::string("test3"));
	s1.insert(std::string("test4"));
	s1.insert(std::string("test5"));

	module_test("set::size (non-empty)", s1.size());
	module_test("set::empty (non-empty)", s1.empty());
	module_test("set::max_size (non-empty)", s1.max_size());
}

static void test_clear(void)
{
	TESTED_NAMESPACE::set<std::string> s1;

	module_head("set::clear() (empty)");
	s1.clear();
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();
	s1.insert(std::string("test1"));
	s1.insert(std::string("test2"));
	s1.insert(std::string("test3"));
	s1.insert(std::string("test4"));
	s1.insert(std::string("test5"));
	module_head("set::clear() (non-empty)");
	s1.clear();
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();
}

static void test_erase(void)
{
	TESTED_NAMESPACE::set<std::string> s1;

	s1.insert(std::string("test1"));
	s1.insert(std::string("test2"));
	s1.insert(std::string("test3"));
	s1.insert(std::string("test4"));
	s1.insert(std::string("test5"));

	module_head("set::erase(key) (not found)");
	std::cout << s1.erase(std::string("test6")) << std::endl;
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();

	module_head("set::erase(key) (found)");
	std::cout << s1.erase(std::string("test2")) << std::endl;
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();
	s1.insert(std::string("test2"));

	module_head("set::erase(iterator)");
	s1.erase(s1.begin());
	std::cout << "s1 content:" << string_set(s1) << std::endl;

	s1.erase(++s1.begin());
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();

	s1.insert(std::string("test1"));
	s1.insert(std::string("test2"));
	s1.insert(std::string("test3"));
	s1.insert(std::string("test4"));
	s1.insert(std::string("test5"));

	module_head("set::erase(iterator, iterator)");
	s1.erase(s1.begin(), s1.end());
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	module_foot();

	TESTED_NAMESPACE::set<std::string> s2;
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s2.insert(ss.str());
	}
	module_head("set::erase time");
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s2.erase(ss.str());
	}
	module_foot();

	module_test("set::erase time content", string_set(s2));
}

static void test_swap(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	TESTED_NAMESPACE::set<std::string> s2;
	for (int i = 0; i < 50; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s2.insert(ss.str());
	}
	module_head("set::swap()");
	s1.swap(s2);
	std::cout << "s1 content:" << string_set(s1) << std::endl;
	std::cout << "s2 content:" << string_set(s2) << std::endl;
	std::cout << "size: " << s1.size() << std::endl;
	std::cout << "size: " << s2.size() << std::endl;
	module_foot();
}

static void test_count(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}

	module_head("set::count()");
	std::cout << s1.count(std::string("test1")) << std::endl;
	std::cout << s1.count(std::string("test2")) << std::endl;
	std::cout << s1.count(std::string("test3")) << std::endl;
	std::cout << s1.count(std::string("test4")) << std::endl;
	std::cout << s1.count(std::string("test5")) << std::endl;
	std::cout << s1.count(std::string("does not exist")) << std::endl;
	module_foot();
}

static void test_find(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}

	module_head("set::find()");
	std::cout << *s1.find(std::string("test1")) << std::endl;
	std::cout << *s1.find(std::string("test2")) << std::endl;
	std::cout << *s1.find(std::string("test3")) << std::endl;
	std::cout << *s1.find(std::string("test4")) << std::endl;
	std::cout << (s1.find(std::string("not exist")) == s1.end()) << std::endl;
	module_foot();
}

static void test_key_comp(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	TESTED_NAMESPACE::set<std::string>::key_compare comp = s1.key_comp();

	module_head("set::key_comp()");
	std::cout << comp(std::string("test1"), std::string("test1")) << std::endl;
	std::cout << comp(std::string("test1"), std::string("test2")) << std::endl;
	module_foot();
}

static void test_value_comp(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	TESTED_NAMESPACE::set<std::string>::value_compare comp = s1.value_comp();

	module_head("set::value_comp()");
	std::cout << comp(std::string("test1"), std::string("test1")) << std::endl;
	std::cout << comp(std::string("test1"), std::string("test2")) << std::endl;
	module_foot();
}

static void test_get_allocator(void)
{
	TESTED_NAMESPACE::set<std::string> s1;

	module_head("set::get_allocator()");
	TESTED_NAMESPACE::set<std::string>::allocator_type alloc = s1.get_allocator();
	std::cout << alloc.max_size() << std::endl;
	module_foot();
}

static void test_lower_bound(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	module_head("set::lower_bound()");
	std::cout << *s1.lower_bound(std::string("test1")) << std::endl;
	std::cout << *s1.lower_bound(std::string("test2")) << std::endl;
	std::cout << *s1.lower_bound(std::string("test3")) << std::endl;
	std::cout << *s1.lower_bound(std::string("test4")) << std::endl;
	std::cout << *s1.lower_bound(std::string("test5")) << std::endl;
	std::cout << *s1.lower_bound(std::string("does not exist")) << std::endl;
	module_foot();
}

static void test_upper_bound(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	module_head("set::upper_bound()");
	std::cout << *s1.upper_bound(std::string("test1")) << std::endl;
	std::cout << *s1.upper_bound(std::string("test2")) << std::endl;
	std::cout << *s1.upper_bound(std::string("test3")) << std::endl;
	std::cout << *s1.upper_bound(std::string("test4")) << std::endl;
	std::cout << *s1.upper_bound(std::string("test5")) << std::endl;
	std::cout << *s1.upper_bound(std::string("does not exist")) << std::endl;
	module_foot();
}

static void test_equal_range(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	module_head("set::equal_range()");
	std::cout << *(s1.equal_range(std::string("test1")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("test1")).second) << std::endl;
	std::cout << *(s1.equal_range(std::string("test2")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("test2")).second) << std::endl;
	std::cout << *(s1.equal_range(std::string("test3")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("test3")).second) << std::endl;
	std::cout << *(s1.equal_range(std::string("test4")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("test4")).second) << std::endl;
	std::cout << *(s1.equal_range(std::string("test5")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("test5")).second) << std::endl;
	std::cout << *(s1.equal_range(std::string("does not exist")).first) << std::endl;
	std::cout << *(s1.equal_range(std::string("does not exist")).second) << std::endl;
	module_foot();
}

static void test_relational_operators(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	TESTED_NAMESPACE::set<std::string> s2;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "gest" << i;
		s2.insert(ss.str());
	}

	module_head("set::operator==()");
	std::cout << (s1 == s2) << std::endl;
	std::cout << (s2 == s1) << std::endl;
	std::cout << (s1 == s1) << std::endl;
	module_foot();

	module_head("set::operator!=()");
	std::cout << (s1 != s2) << std::endl;
	std::cout << (s2 != s1) << std::endl;
	std::cout << (s1 == s1) << std::endl;
	module_foot();

	module_head("set::operator<()");
	std::cout << (s1 < s2) << std::endl;
	std::cout << (s2 < s1) << std::endl;
	std::cout << (s1 < s1) << std::endl;
	module_foot();

	module_head("set::operator<=()");
	std::cout << (s1 <= s2) << std::endl;
	std::cout << (s2 <= s1) << std::endl;
	std::cout << (s1 <= s1) << std::endl;
	module_foot();

	module_head("set::operator>()");
	std::cout << (s1 > s2) << std::endl;
	std::cout << (s2 > s1) << std::endl;
	std::cout << (s1 > s1) << std::endl;
	module_foot();

	module_head("set::operator>=()");
	std::cout << (s1 >= s2) << std::endl;
	std::cout << (s2 >= s1) << std::endl;
	std::cout << (s1 >= s1) << std::endl;
	module_foot();
}

static void test_swap_non_member(void)
{
	TESTED_NAMESPACE::set<std::string> s1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		s1.insert(ss.str());
	}
	TESTED_NAMESPACE::set<std::string> s2;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "gest" << i;
		s2.insert(ss.str());
	}

	module_head("set::swap() (non member)");
	s1.swap(s2);
	std::cout << s1.size() << std::endl;
	std::cout << s2.size() << std::endl;
	std::cout << string_set(s1) << std::endl;
	std::cout << string_set(s2) << std::endl;
	module_foot();
}

void test_set(void)
{
	test_constructor();
	test_insert();
	test_assign_operator();
	test_iterators();
	test_capacity();
	test_clear();
	test_erase();
	test_swap();
	test_count();
	test_find();
	test_key_comp();
	test_value_comp();
	test_get_allocator();
	test_lower_bound();
	test_upper_bound();
	test_equal_range();
	test_relational_operators();
	test_swap_non_member();
}
