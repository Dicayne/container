/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/28 13:27:52 by vmoreau          ###   ########.fr       */
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

void display(ns::map<char, int> m)
{
	std::cout << "Display Map:\n" << BLUE << "---------------------\n" << NC;
	if (m.empty())
		std::cout << "Map is empty\n";
	else
	{
		for (ns::map<char, int>::iterator it = m.begin() ; it != m.end(); it++)
			std::cout << it->first << ": " << it->second << std::endl;
	}
	std::cout << BLUE << "---------------------\n" << NC;
}

void test_member_function()
{
	std::cout << YELLOW << "----TEST MEMBER FUNCTION BEGIN----\n" << NC;
	ns::map<char, int> m1;

	m1['Z'] = 12;
	m1['X'] = 54;
	m1['A'] = 7;
	m1['F'] = -2;

	ns::map<char, int> m2(m1);
	ns::map<char, int> m3(m2.begin(), m2.end());
	ns::map<char, int> m4;

	m4 = m3;

	std::cout << CYAN << "M1: ns::map<char, int>\n\tm1['Z'] = 12;\n\tm1['X'] = 54;\n\tm1['A'] = 7;\n\tm1['F'] = -2;\n" << NC;
	display(m1);
	std::cout << CYAN << "M2: ns::map<char, int> m2(m1)\n" << NC;
	display(m2);
	std::cout << CYAN << "M3: ns::map<char, int> m3(m2.begin(), m2.end())\n" << NC;
	display(m3);
	std::cout << CYAN << "M4: ns::map<char, int> m4;\n\tm4 = m3;\n" << NC;
	display(m4);
	std::cout << YELLOW << "----TEST MEMBER FUNCTION END----\n\n" << NC;
}

void test_capacity()
{
	std::cout << YELLOW << "----TEST CAPACITY BEGIN----\n" << NC;
	ns::map<char, int> m1;

	m1['Z'] = 12;
	m1['X'] = 54;
	m1['A'] = 7;
	m1['F'] = -2;
	m1['G'] = 43;
	m1['L'] = 89;
	m1['O'] = 70;
	m1['B'] = 34;
	m1['P'] = 4;

	std::cout << "map.size()= " << m1.size() << std::endl;
	std::cout << "map.max_size()= " << m1.max_size() << std::endl;
	std::cout << std::boolalpha << "map.empty()= " << m1.empty() << std::endl;
	std::cout << "clear map\n";
	m1.clear();
	std::cout << std::boolalpha << "map.empty()= " << m1.empty() << std::endl;
	std::cout << YELLOW << "----TEST CAPACITY END----\n\n" << NC;
}

void test_iterator()
{
	std::cout << YELLOW << "----TEST ITERATOR BEGIN----\n" << NC;
	ns::map<char, int> m1;

	m1['Z'] = 12;
	m1['X'] = 54;
	m1['A'] = 7;
	m1['F'] = -2;
	m1['G'] = 43;
	m1['L'] = 89;
	m1['O'] = 70;
	m1['B'] = 34;
	m1['P'] = 4;

	std::cout << CYAN << "m1.begin() = " << NC << m1.begin()->first << ": " << m1.begin()->second << NC << std::endl;
	std::cout << CYAN << "--m1.end() = " << NC << (--m1.end())->first << ": " << (--m1.end())->second << NC << std::endl;
	std::cout << CYAN << "m1.rbegin() = " << NC << m1.rbegin()->first << ": " << m1.rbegin()->second << NC << std::endl;
	std::cout << CYAN << "--m1.rend() - 1 = " << NC << (--m1.rend())->first << ": " << (--m1.rend())->second << NC << std::endl << std::endl;
	std::cout << YELLOW << "----TEST ITERATOR END----\n\n" << NC;
}

void test_element_access()
{
	std::cout << YELLOW << "----TEST ITERATOR BEGIN----\n" << NC;
	ns::map<char, int> m1;

	m1['Z'] = 12;
	m1['X'] = 54;
	m1['A'] = 7;
	m1['F'] = -2;
	m1['G'] = 43;
	m1['L'] = 89;
	m1['O'] = 70;
	m1['B'] = 34;
	m1['P'] = 4;

	std::cout << CYAN << "-Test [] on known key-\n" << NC;
	std::cout << "map['Z']= " << m1['Z'] << std::endl;
	std::cout << "map['X']= " << m1['X'] << std::endl;
	std::cout << "map['A']= " << m1['A'] << std::endl;
	std::cout << "map['F']= " << m1['F'] << std::endl;
	std::cout << "map['G']= " << m1['G'] << std::endl;
	std::cout << "map['L']= " << m1['L'] << std::endl;
	std::cout << "map['O']= " << m1['O'] << std::endl;
	std::cout << "map['B']= " << m1['B'] << std::endl;
	std::cout << "map['P']= " << m1['P'] << std::endl << std::endl;

	std::cout << CYAN << "-Test at on unknown key-\n" << NC;
	std::cout << "map['Q']= " << m1['Q'] << std::endl << std::endl;

	std::cout << YELLOW << "----TEST ITERATOR END----\n\n" << NC;
}

void test_modifiers()
{
	{
		std::cout << CYAN << "-TEST OF INSERT-" << NC << std::endl;
		ns::map<char,int> m;
		std::cout << "Create an empty map\n\n";
		display(m);
		std::cout << "\nInsert few pair of value: m.insert(ns::pair<char, int>('Q', -74))\n";
		m.insert(ns::pair<char, int>('Q', -74));
		m.insert(ns::pair<char, int>('G', 98));
		m.insert(ns::pair<char, int>('F', 214));
		m.insert(ns::pair<char, int>('A', 5));
		m.insert(ns::pair<char, int>('E', 6));
		m.insert(ns::pair<char, int>('W', -10));
		m.insert(ns::pair<char, int>('R', 879));
		display(m);

		m.insert(m.begin() ,ns::pair<char, int>('D', -651321));
		display(m);
	}
}

int main()
{
	test_member_function();
	test_iterator();
	test_capacity();
	test_element_access();
	test_modifiers();
	return (0);
}
