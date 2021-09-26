/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:12:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/26 16:05:38 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>





template <typename T1, typename T2>
std::string string_map(TESTED_NAMESPACE::map<T1, T2> &v)
{
	std::ostringstream ss;

	ss << "{";
	for (typename TESTED_NAMESPACE::map<T1, T2>::iterator it = v.begin(); it != v.end(); ++it)
	{
		ss << it->first << ": " << it->second;
		if (it != v.end())
			ss << ", ";
	}
	ss << "}";
	return ss.str();
}

static void test_constructor(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	module_head("map::constructor(void)");
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "m1::size: " << m1.size() << std::endl;
	std::cout << "m1::empty: " << m1.empty() << std::endl;
	std::cout << "m1::clear: ";
	m1.clear();
	std::cout << m1.size() << std::endl;
	module_foot();
	TESTED_NAMESPACE::map<std::string, int> m2(m1);
	module_head("map::constructor(map<std::string, int>) (empty)");
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	module_head("map::constructor(map<std::string, int>) (not empty)");
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();

	module_head("map::constructor(iterator, iterator) (empty)");
	TESTED_NAMESPACE::map<std::string, int> m3(m2.begin(), m2.end());
	std::cout << "m3 content: " << string_map(m3) << std::endl;
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	std::cout << "m3::clear: ";
	m3.clear();
	std::cout << m3.size() << std::endl;
	module_foot();
	module_head("map::constructor(iterator, iterator) (not empty)");
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "m3 content: " << string_map(m3) << std::endl;
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	TESTED_NAMESPACE::map<std::string, int> m4(m3.begin(), m3.end());
	std::cout << "m4 content: " << string_map(m4) << std::endl;
	std::cout << "m4::size: " << m4.size() << std::endl;
	std::cout << "m4::empty: " << m4.empty() << std::endl;
	module_foot();

	module_head("map::constructor(const map<std::string, int>)");
	TESTED_NAMESPACE::map<std::string, int> m5(m4);
	std::cout << "m5::size: " << m5.size() << std::endl;
	std::cout << "m5::empty: " << m5.empty() << std::endl;
	std::cout << "m5::clear: ";
	m5.clear();
	std::cout << m5.size() << std::endl;
	module_foot();
}

static void test_insert(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<std::string, int>::iterator, bool> r;
	module_head("map::insert(value)");
	r = m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	module_head("map::insert(value) duplicate");
	r = m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 2));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int>::iterator it;

	module_head("map::insert(iterator, value)");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	module_head("map::insert(iterator, value) duplicate");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 7));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int> m2;

	module_head("map::insert(iterator, iterator)");
	m2.insert(m1.begin(), m1.end());
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();

	module_head("map::insert(iterator, iterator) duplicate");
	m2.insert(m1.begin(), m1.end());
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();

	module_head("map::insert(value) time");
	TESTED_NAMESPACE::map<std::string, int> m3;
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m3.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	module_foot();

	module_head("map::size after time");
	std::cout << "m3.size: " << m3.size() << std::endl;
	module_foot();
}

static void test_assign_operator(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::map<std::string, int> m2;

	module_head("map::= empty");
	m1 = m2;
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "m1.size: " << m1.size() << std::endl;
	std::cout << "m1.empty: " << m1.empty() << std::endl;
	module_foot();

	module_head("map::=");
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 1));
	m2 = m1;
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();
}

static void test_iterators(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::map<std::string, int>::iterator it;
	TESTED_NAMESPACE::map<std::string, int>::iterator it2;
	it = m1.begin();
	it2 = m1.end();
	module_test("map::begin() == map::end()", it == it2);
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 1));

	module_head("map::begin()");
	it = m1.begin();
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	module_head("map::end()");
	it2 = m1.end();
	for (it = m1.begin(); it != it2; ++it)
	{
		std::cout << "it.first.first: " << it->first << std::endl;
		std::cout << "it.first.second: " << it->second << std::endl;
	}
	module_foot();

	TESTED_NAMESPACE::map<std::string, int>::reverse_iterator rit;
	module_head("map::rbegin() && rend");
	for (rit = m1.rbegin(); rit != m1.rend(); ++rit)
	{
		std::cout << "rit.first.first: " << rit->first << std::endl;
		std::cout << "rit.first.second: " << rit->second << std::endl;
	}
	module_foot();
}

static void test_capacity(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	module_test("map::size (empty)", m1.size());
	module_test("map::empty (empty)", m1.empty());
	module_test("map::max_size (empty)", m1.max_size());

	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 1));

	module_test("map::size (not empty)", m1.size());
	module_test("map::empty (not empty)", m1.empty());
	module_test("map::max_size (not empty)", m1.max_size());
}

static void test_access_operator(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));

	module_test("map::operator[]", m1["test1"]);
	module_test("map::operator[]", m1["test2"]);
	module_test("map::operator[]", m1["test3"]);
	module_test("map::operator[]", m1["test4"]);
	module_test("map::operator[]", m1["test5"]);
	m1["test1"] = 6;
	module_test("map::operator[]", m1["test1"]);
	m1["test2"] = 7;
	module_test("map::operator[]", m1["test2"]);
	m1["test3"] = 8;
	module_test("map::operator[]", m1["test3"]);
	m1["test4"] = 9;
	module_test("map::operator[]", m1["test4"]);
	m1["test5"] = 10;
	module_test("map::operator[]", m1["test5"]);

	module_test("map::operator[] (not exist)", m1["test6"]);
	m1["test7"] = 42;
	module_test("map::operator[] (not exist)", m1["test7"]);

	module_head("map::operator[] value check");
	std::cout << string_map(m1) << std::endl;
	std::cout << m1.size() << std::endl;
	module_foot();
}

static void test_at(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	module_head("map::at (not found)");
	try
	{
		m1.at("test1");
		std::cout << "KO" << std::endl;
	}
	catch (std::exception &)
	{
		std::cout << "OK" << std::endl;
	}
	module_foot();
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));
	module_head("map::at (found)");
	std::cout << m1.at("test1") << std::endl;
	std::cout << m1.at("test2") << std::endl;
	std::cout << m1.at("test3") << std::endl;
	std::cout << m1.at("test4") << std::endl;
	std::cout << m1.at("test5") << std::endl;
	module_foot();

	module_head("map::at (access)");
	m1.at("test1") = 6;
	m1.at("test2") = 7;
	m1.at("test3") = 8;
	m1.at("test4") = 9;
	m1.at("test5") = 10;
	std::cout << string_map(m1) << std::endl;
	module_foot();
}

static void test_clear(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	module_head("map::clear (empty)");
	m1.clear();
	std::cout << string_map(m1) << std::endl;
	module_foot();
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));
	module_head("map::clear (not empty)");
	m1.clear();
	std::cout << string_map(m1) << std::endl;
	module_foot();
}

static void test_erase(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));

	module_head("map::erase(key) (not found)");
	std::cout << m1.erase("test6") << std::endl;
	std::cout << string_map(m1) << std::endl;
	module_foot();
	module_head("map::erase(key) (found)");
	std::cout << m1.erase("test1") << std::endl;
	std::cout << string_map(m1) << std::endl;
	std::cout << m1.erase("test2") << std::endl;
	std::cout << string_map(m1) << std::endl;
	std::cout << m1.erase("test3") << std::endl;
	std::cout << string_map(m1) << std::endl;
	std::cout << m1.erase("test4") << std::endl;
	std::cout << string_map(m1) << std::endl;
	std::cout << m1.erase("test5") << std::endl;
	std::cout << string_map(m1) << std::endl;
	module_foot();

	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));

	module_head("map::erase(iterator)");
	TESTED_NAMESPACE::map<std::string, int>::iterator it = m1.begin();
	m1.erase(it);
	std::cout << string_map(m1) << std::endl;
	it = m1.begin();
	it++;
	m1.erase(it);
	std::cout << string_map(m1) << std::endl;
	module_foot();

	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 2));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 3));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 4));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 5));

	module_head("map::erase(it, it)");
	m1.erase(m1.begin(), m1.end());
	std::cout << string_map(m1) << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int> m3;
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m3.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	module_head("map::erase (time)");
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m3.erase(ss.str());
	}
	module_foot();
}

static void test_swap(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	TESTED_NAMESPACE::map<std::string, int> m2;
	for (int i = 0; i < 50; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m2.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::swap");
	m1.swap(m2);
	std::cout << string_map(m1) << std::endl;
	std::cout << string_map(m2) << std::endl;
	std::cout << "size: " << m1.size() << std::endl;
	std::cout << "size: " << m2.size() << std::endl;
	module_foot();
}

static void test_count(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::count");
	std::cout << m1.count("test1") << std::endl;
	std::cout << m1.count("test2") << std::endl;
	std::cout << m1.count("test3") << std::endl;
	std::cout << m1.count("test4") << std::endl;
	std::cout << m1.count("test5") << std::endl;
	std::cout << m1.count("does not exist") << std::endl;
	module_foot();
}

static void test_find(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::find");
	std::cout << m1.find("test1")->second << std::endl;
	std::cout << m1.find("test2")->second << std::endl;
	std::cout << m1.find("test3")->second << std::endl;
	std::cout << m1.find("test4")->second << std::endl;
	std::cout << (m1.find("nothing") == m1.end()) << std::endl;
	module_foot();
}

static void test_key_comp(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	TESTED_NAMESPACE::map<std::string, int>::key_compare comp = m1.key_comp();
	module_head("map::key_compare");
	std::cout << comp("test1", "test1") << std::endl;
	std::cout << comp("test1", "test2") << std::endl;
	module_foot();
}

static void test_value_comp(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	TESTED_NAMESPACE::map<std::string, int>::value_compare comp = m1.value_comp();
	module_head("map::value_compare");
	TESTED_NAMESPACE::pair<std::string, int> p1(std::string("test1"), 1);
	TESTED_NAMESPACE::pair<std::string, int> p2(std::string("test2"), 2);
	std::cout << comp(p1, p2) << std::endl;
	module_foot();
}

static void test_get_allocator(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;

	module_head("map::get_allocator");
	TESTED_NAMESPACE::map<std::string, int>::allocator_type alloc = m1.get_allocator();

	std::cout << "allocator: " << alloc.max_size() << std::endl;
	module_foot();
}

static void test_lower_bound(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::lower_bound");
	std::cout << m1.lower_bound("test1")->second << std::endl;
	std::cout << m1.lower_bound("test2")->second << std::endl;
	std::cout << m1.lower_bound("test3")->second << std::endl;
	std::cout << m1.lower_bound("test4")->second << std::endl;
	std::cout << m1.lower_bound("test5")->second << std::endl;
	std::cout << m1.lower_bound("does not exist")->second << std::endl;
	module_foot();
}

static void test_upper_bound(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::upper_bound");
	std::cout << m1.upper_bound("test1")->second << std::endl;
	std::cout << m1.upper_bound("test2")->second << std::endl;
	std::cout << m1.upper_bound("test3")->second << std::endl;
	std::cout << m1.upper_bound("test4")->second << std::endl;
	std::cout << m1.upper_bound("test5")->second << std::endl;
	std::cout << m1.upper_bound("does not exist")->second << std::endl;
	module_foot();
}

static void test_equal_range(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::equal_range");
	std::cout << m1.equal_range("test1").first->first << std::endl;
	std::cout << m1.equal_range("test1").second->first << std::endl;
	std::cout << m1.equal_range("test2").first->first << std::endl;
	std::cout << m1.equal_range("test2").second->first << std::endl;
	std::cout << m1.equal_range("test3").first->first << std::endl;
	std::cout << m1.equal_range("test3").second->first << std::endl;
	std::cout << m1.equal_range("test4").first->first << std::endl;
	std::cout << m1.equal_range("test4").second->first << std::endl;
	std::cout << m1.equal_range("test5").first->first << std::endl;
	std::cout << m1.equal_range("test5").second->first << std::endl;
	std::cout << m1.equal_range("does not exist").first->first << std::endl;
	module_foot();
}

static void test_relational_operators(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	TESTED_NAMESPACE::map<std::string, int> m2;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "gest" << i;
		m2.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::operator==");
	std::cout << (m1 == m2) << std::endl;
	std::cout << (m1 == m1) << std::endl;
	module_foot();

	module_head("map::operator!=");
	std::cout << (m1 != m2) << std::endl;
	std::cout << (m1 != m1) << std::endl;
	module_foot();

	module_head("map::operator<");
	std::cout << (m1 < m2) << std::endl;
	std::cout << (m2 < m1) << std::endl;
	std::cout << (m1 < m1) << std::endl;
	module_foot();

	module_head("map::operator<=");
	std::cout << (m1 <= m2) << std::endl;
	std::cout << (m2 <= m1) << std::endl;
	std::cout << (m1 <= m1) << std::endl;
	module_foot();

	module_head("map::operator>");
	std::cout << (m1 > m2) << std::endl;
	std::cout << (m2 > m1) << std::endl;
	std::cout << (m1 > m1) << std::endl;
	module_foot();

	module_head("map::operator>=");
	std::cout << (m1 >= m2) << std::endl;
	std::cout << (m2 >= m1) << std::endl;
	std::cout << (m1 >= m1) << std::endl;
	module_foot();
}

static void test_swap_non_member(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	TESTED_NAMESPACE::map<std::string, int> m2;
	for (int i = 0; i < 30; ++i)
	{
		std::ostringstream ss;
		ss << "gest" << i;
		m2.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}

	module_head("map::swap");
	m1.swap(m2);
	std::cout << m1.size() << std::endl;
	std::cout << m2.size() << std::endl;
	std::cout << string_map(m1) << std::endl;
	std::cout << string_map(m2) << std::endl;
	module_foot();
}

void test_map(void)
{
	test_constructor();
	test_insert();
	test_assign_operator();
	test_iterators();
	test_capacity();
	test_access_operator();
	test_at();
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
