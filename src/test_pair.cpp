/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:37:11 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/26 16:05:36 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"





void test_pair(void)
{
	module_head("pair");
	TESTED_NAMESPACE::pair<std::string, int> p1(static_cast<std::string>("key"), -42);
	TESTED_NAMESPACE::pair<std::string, int> p2(static_cast<std::string>("key"), 42);

	std::cout << "p1: " << p1.first << " " << p1.second << std::endl;
	std::cout << "p2: " << p2.first << " " << p2.second << std::endl;

	TESTED_NAMESPACE::pair<std::string, int> p3
		= TESTED_NAMESPACE::make_pair(static_cast<std::string>("key"), 42);
	std::cout << "p3: " << p3.first << " " << p3.second << std::endl;
	module_foot();
}
