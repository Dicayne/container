/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:43:21 by vmoreau           #+#    #+#             */
/*   Updated: 2021/12/02 19:00:33 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Utils/colors.hpp"
#include <iostream>

#ifndef mine
	#include <map>
	namespace ns = std;

#else
	#include "map.hpp"
	namespace ns = ft;

#endif

#define MAX_RAM 42949672960
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main()
{
	ns::map<int, int>m1;

	for (int i = 0; i < COUNT; ++i)
	{
		m1.insert(ns::make_pair(rand(), rand()));
	}

	ns::map<int, int>m2(m1);

	if (m1 == m2)
		std::cout << "M1 and M2 are equal after copy\n\n";
	else
		std::cout << "There is difference between M1 and M2 after cpy\n\n";

	std::cout << PURPLE << "Size = Number of nodes in BST\n" << NC << "Size of m1: " << m1.size() << "\nSize of m2: " << m2.size() << "\n\nClear m1 and m2\n\n";

	m1.clear();
	m2.clear();

	std::cout << "Size of m1: " << m1.size() << "\nSize of m2: " << m2.size() << "\n";
	return (0);
}
