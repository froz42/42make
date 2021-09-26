/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:11:45 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/26 16:05:34 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"





static void test_relational_operators()
{
	TESTED_NAMESPACE::stack<int> stack;
	TESTED_NAMESPACE::stack<int> stack2;
	TESTED_NAMESPACE::stack<int> stack3;
	TESTED_NAMESPACE::stack<int> stack4;

	for (int i = 0; i < 10; i++)
		stack.push(i);
	for (int i = 0; i < 10; i++)
		stack2.push(i);
	for (int i = 0; i < 10; i++)
		stack3.push(6);
	for (int i = 0; i < 10; i++)
		stack4.push(7);
	
	module_test("stack::operator==", stack == stack2);
	module_test("stack::operator!=", stack != stack3);
	module_test("stack::operator<", stack < stack4);
	module_test("stack::operator<=", stack <= stack4);
	module_test("stack::operator>", stack > stack3);
	module_test("stack::operator>=", stack >= stack3);
}

static void test_other_container(void)
{
	TESTED_NAMESPACE::stack<int, std::vector<int> > stack;

	module_test("stack::empty (default constructor)", stack.empty());
	module_test("stack::size (default constructor)", stack.size());
	module_head("stack::push");
	for (int i = 0; i < 100; i++)
		stack.push(i);
	module_foot();
	module_test("stack::empty (push)", stack.empty());
	module_test("stack::size (push)", stack.size());
	module_head("stack::pop");
	for (int i = 0; i < 50; i++)
		stack.pop();
	module_foot();
	module_test("stack::empty (pop)", stack.empty());
	module_test("stack::size (pop)", stack.size());
	module_test("stack::top", stack.top());	

	std::vector<int> v(42, 42);
	TESTED_NAMESPACE::stack<int, std::vector<int> > stack2(v);
	module_test("stack::empty (constructor)", stack2.empty());
	module_test("stack::size (constructor)", stack2.size());
	module_test("stack::top", stack.top());	

	TESTED_NAMESPACE::stack<int, std::vector<int> > stack3(stack);
	module_test("stack::empty (copy constructor)", stack3.empty());
	module_test("stack::size (copy constructor)", stack3.size());
	module_test("stack::top", stack.top());

	TESTED_NAMESPACE::stack<int, std::vector<int> > stack4;
	stack4 = stack;
	module_test("stack::empty (assignment operator)", stack4.empty());
	module_test("stack::size (assignment operator)", stack4.size());
	module_test("stack::top", stack.top());
}

void test_stack()
{
	TESTED_NAMESPACE::stack<int> stack;

	module_test("stack::empty (default constructor)", stack.empty());
	module_test("stack::size (default constructor)", stack.size());
	module_head("stack::push");
	for (int i = 0; i < 100; i++)
		stack.push(i);
	module_foot();
	module_test("stack::empty (push)", stack.empty());
	module_test("stack::size (push)", stack.size());
	module_head("stack::pop");
	for (int i = 0; i < 50; i++)
		stack.pop();
	module_foot();
	module_test("stack::empty (pop)", stack.empty());
	module_test("stack::size (pop)", stack.size());
	module_test("stack::top", stack.top());	
	
	test_relational_operators();
	test_other_container();
}
