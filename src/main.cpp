/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:04:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/26 15:44:41 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <stdio.h>
// timewatch start globale
struct timespec start;

void module_head(std::string module_name)
{
	std::cout << ">>> " << module_name << std::endl;
}

void module_init(void)
{
	clock_gettime(CLOCK_MONOTONIC, &start);
}

void module_foot(void)
{
	struct timespec end;
	double time_taken;
    
	clock_gettime(CLOCK_MONOTONIC, &end);
	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
	std::cout << "<<< " << std::fixed << time_taken << std::endl;
	clock_gettime(CLOCK_MONOTONIC, &start);
}

int main(void)
{
	module_init();
	module_test("witness test", 42);
	test_iterator();
	test_pair();
	test_vector();
	test_stack();
	test_map();
	test_set();
	test_42();
}
