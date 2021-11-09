/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/09 02:15:41 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Utils/colors.hpp"
#include <functional>
#include <iostream>

#ifndef mine
	#include <map>
	namespace ns = std;
	#define NAMS "STD"

#else
	#include "map.hpp"
	namespace ns = ft;
	#define NAMS "FT"

#endif

std::string display_paire(ns::pair<char, int> p)
{
	std::string ret;

	ret += p.first;
	ret += ": ";
	ret += std::to_string(p.second);

	return (ret);
}

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
	std::cout << PURPLE << "m.size()->" << m.size() << std::endl;
	std::cout << BLUE << "---------------------\n" << NC;
}

void display_insert(ns::map<char, int> m, ns::map<char, int>::iterator added)
{
	std::cout << "Display Map:\n" << BLUE << "---------------------\n" << NC;
	if (m.empty())
		std::cout << "Map is empty\n";
	else
	{
		for (ns::map<char, int>::iterator it = m.begin() ; it != m.end(); it++)
		{
			if (it->first == added->first)
				std::cout << YELLOW << it->first << ": " << it->second << NC << std::endl;
			else
				std::cout << it->first << ": " << it->second << std::endl;
		}
	}
	std::cout << PURPLE << "m.size()->" << m.size() << std::endl;
	std::cout << BLUE << "---------------------\n" << NC;
}

void display_insert_range(ns::map<char, int> m, ns::map<char, int> mr)
{
	std::cout << "Display Map:\n" << BLUE << "---------------------\n" << NC;
	if (m.empty())
		std::cout << "Map is empty\n";
	else
	{
		for (ns::map<char, int>::iterator it = m.begin() ; it != m.end(); it++)
		{
			if (mr.find(it->first) != mr.end())
				std::cout << YELLOW << it->first << ": " << it->second << NC << std::endl;
			else
				std::cout << it->first << ": " << it->second << std::endl;
		}
	}
	std::cout << PURPLE << "m.size()->" << m.size() << std::endl;
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

	display(m1);

	std::cout << "\n\nmap.size()= " << m1.size() << std::endl;
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
	std::cout << CYAN << "--m1.rend() = " << NC << (--m1.rend())->first << ": " << (--m1.rend())->second << NC << std::endl << std::endl;

	std::cout << YELLOW << "----TEST ITERATOR END----\n\n" << NC;
}

void test_element_access()
{
	std::cout << YELLOW << "----TEST ELEMENT ACCESS BEGIN----\n" << NC;
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

	std::cout << CYAN << "-Test [ ] on known key-\n" << NC;
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

	display(m1);
	std::cout << YELLOW << "----TEST ELEMENT ACCESS END----\n\n" << NC;
}

void test_modifiers()
{
	{
		std::cout << CYAN << "-TEST OF INSERT-" << NC << std::endl;
		ns::map<char,int> m;
		std::cout << "Create an empty map\n\n";
		display(m);
		std::cout << "Add some value to map\n\tm['Z'] = 12;\n\tm['X'] = 54;\n\tm['A'] = 7;\n\tm['F'] = -2;\n" << NC;
		m['Z'] = 12;
		m['W'] = 54;
		m['A'] = 7;
		m['F'] = -2;
		display(m);

		std::cout << CYAN << "\tSingle Element" << NC << std::endl;

		ns::pair<ns::map<char, int>::iterator, bool> p;
		std::cout << "p = m.insert(ns::p<char, int>('D', -6543214));\n";
		p = m.insert(ns::pair<char, int>('D', -6543214));
		std::cout << std::boolalpha << "p = " << p.first->first << ": " << p.first->second << ". Inserted-> " << p.second << std::endl << std::endl;
		display_insert(m, p.first);

		std::cout << "p = m.insert(ns::p<char, int>('D', 9));" << RED << " WHILE 'D' ALREADY STORE\n" << NC;
		p = m.insert(ns::pair<char, int>('D', 9));
		std::cout << "p = " << p.first->first << ": " << p.first->second << ". Inserted-> " << p.second << std::endl << std::endl;
		display_insert(m, p.first);
		std::cout << std::endl;

		std::cout << CYAN << "\tSingle Element with HINT" << NC << std::endl;

		ns::map<char, int>::iterator it;
		std::cout << "it = m.insert(m.begin(), ns::pair<char, int>('Q', 1234));\n";
		it = m.insert(m.begin(), ns::pair<char, int>('Q', 1234));
		std::cout << std::boolalpha << "it = " << it->first << ": " << it->second << std::endl << std::endl;
		display_insert(m, it);

		std::cout << "it = m.insert(m.begin(), ns::pair<char, int>('Q', 9));" << RED << " WHILE 'Q' ALREADY STORE\n" << NC;
		it = m.insert(m.begin(), ns::pair<char, int>('Q', 9));
		std::cout << "it = " << it->first << ": " << it->second << std::endl << std::endl;
		display_insert(m, it);

		std::cout << "it = m.insert(m.find('W'), ns::pair<char, int>('Y', 9));\n"; // This one will start his search to place Y->9 on iterator returned by find
		it = m.insert(m.find('W'), ns::pair<char, int>('Y', 9)); // If no iterator was find by find() find return m.end() then m.insert() will start his search by m.begin()
		std::cout << "it = " << it->first << ": " << it->second << std::endl << std::endl;
		display_insert(m, it);

		std::cout << CYAN << "\tSingle Range Element" << NC << std::endl;

		ns::map<char,int> mr;
		std::cout << "Create map for range\n\tmr['B'] = 58;\n\tmr['L'] = -72;\n\tmr['O'] = 13;\n\tmr['J'] = -15;\n" << NC;

		mr['B'] = 58;
		mr['L'] = -72;
		mr['O'] = 13;
		mr['F'] = -15;

		std::cout << "m.insert(mr.begin(),mr.end());\n";
		m.insert(mr.begin(),(mr.end()));
		display_insert_range(m, mr);
		std::cout << std::endl;
	}
	{
		std::cout << CYAN << "-TEST OF ERASE-" << NC << std::endl;
		ns::map<char,int> m;
		ns::map<char,int>::iterator it;

		std::cout << "Create Basic map, add some value\n";
		m['G'] = 43;
		m['F'] = -2;
		m['P'] = 4;
		m['X'] = 54;
		m['O'] = 70;
		m['A'] = 7;
		m['B'] = 34;
		m['L'] = 89;
		m['Z'] = 12;
		display(m);

		std::cout << YELLOW << "\nit = m.find('A');  m.erase(it);\n" << NC;
		it=m.find('A');
		m.erase (it);									 // erasing by iterator
		display(m);

		std::cout << YELLOW << "\nm.erase('G);\n" << NC;
		m.erase ('G');									// erasing by key
		display(m);

		std::cout << YELLOW << "\nit = m.find('O');  m.erase(it, m.end());\n" << NC;
		it=m.find ('O');
		m.erase ( it, m.end());		// erasing by range
		display(m);
	}
	{
		std::cout << CYAN << "-TEST OF SWAP-" << NC << std::endl;
		ns::map<char,int> m1;
		ns::map<char,int> m2;

		std::cout << "Create 2 Basic maps, add some value\n";
		m1['Z'] = 12;
		m1['X'] = 54;
		m1['A'] = 7;
		m1['F'] = -2;

		m2['G'] = 43;
		m2['L'] = 89;

		std::cout << "M1↴\n";
		display(m1);
		std::cout << "M2↴\n";
		display(m2);

		std::cout << YELLOW << "m1.swap(m2)\n" << NC;
		m1.swap(m2);
		std::cout << "M1↴\n";
		display(m1);
		std::cout << "M2↴\n";
		display(m2);
	}
	{
		std::cout << CYAN << "-TEST OF CLEAR-" << NC << std::endl;
		ns::map<char,int> m;

		std::cout << "Create Basic map, add some value\n";
		m['Z'] = 12;
		m['X'] = 54;
		m['A'] = 7;
		m['F'] = -2;
		m['G'] = 43;
		m['L'] = 89;
		display(m);

		std::cout << YELLOW << "m.clear(m1)\n" << NC;
		m.clear();
		display(m);
		std::cout << YELLOW << "m['I'] = 123456789;\n" << NC;
		m['I'] = 123456789;
		display(m);
	}
}

void test_observers()
{
	std::cout << CYAN << "-TEST OF KEY_COMP-" << NC << std::endl;
	ns::map<char,int> m;

	std::cout << "Create Basic map, add some value\n";
	m['A'] = 7;
	m['Z'] = 12;
	m['X'] = 54;
	m['F'] = -2;
	m['B'] = 6;
	m['G'] = 43;
	m['L'] = 89;
	display(m);

	ns::map<char, int>::key_compare k_comp = m.key_comp();
	bool res;

	ns::map<char,int>::iterator begin_it = m.begin();
	ns::map<char,int>::iterator begin_it2 = ++m.begin();

	std::cout << CYAN << "\tComp with it->FIRST\n" << NC;
	std::cout << YELLOW << "res = k_comp(begin_it->first, begin_it2->first); as " << begin_it->first << " < " << begin_it2->first << "?\n" << NC;
	res = k_comp(begin_it->first, begin_it2->first);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = k_comp(begin_it2->first, begin_it->first); as " << begin_it2->first << " < " << begin_it->first << "?\n" << NC;
	res = k_comp(begin_it2->first, begin_it->first);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = k_comp(begin_it->first, begin_it->first); as " << begin_it->first << " < " << begin_it->first << "?\n" << NC;
	res = k_comp(begin_it->first, begin_it->first);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << CYAN << "\tComp with it->SECOND\n" << NC;
	std::cout << YELLOW << "res = k_comp(begin_it->second, begin_it2->second); as " << begin_it->second << " < " << begin_it2->second << "?\n" << NC;
	res = k_comp(begin_it->second, begin_it2->second);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = k_comp(begin_it2->second, begin_it->second); as " << begin_it2->second << " < " << begin_it->second << "?\n" << NC;
	res = k_comp(begin_it2->second, begin_it->second);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = k_comp(begin_it->second, begin_it->second); as " << begin_it->second << " < " << begin_it->second << "?\n" << NC;
	res = k_comp(begin_it->second, begin_it->second);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << CYAN << "-TEST OF VALUE_COMP-" << NC << std::endl;

	ns::map<char, int>::value_compare v_comp = m.value_comp();

	std::cout << YELLOW << "res = v_comp(*begin_it, *begin_it2); as [" << display_paire(*begin_it) << "] < [" << display_paire(*begin_it2) << "]? Tested on it->FIRST\n" << NC;
	res = v_comp(*begin_it, *begin_it2);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = v_comp(*begin_it2, *begin_it); as [" << display_paire(*begin_it2) << "] < [" << display_paire(*begin_it) << "]? Tested on it->FIRST\n" << NC;
	res = v_comp(*begin_it2, *begin_it);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;

	std::cout << YELLOW << "res = v_comp(*begin_it, *begin_it); as [" << display_paire(*begin_it) << "] < [" << display_paire(*begin_it) << "]? Tested on it->FIRST\n" << NC;
	res = v_comp(*begin_it, *begin_it);
	std::cout << std::boolalpha << "res-> " << res << std::endl << std::endl;
}

void test_equal_range(char key, ns::map<char, int> m)
{
		ns::pair<ns::map<char,int>::iterator, ns::map<char,int>::iterator> ret;
		ns::pair<ns::map<char,int>::const_iterator, ns::map<char,int>::const_iterator> const_ret;
		std::cout << YELLOW << "ret = m.equal_range(" << key << ");\n" << NC;
		ret = m.equal_range(key);
		std::cout << YELLOW << "const_ret = m.equal_range(" << key << ");\n" << NC;
		const_ret = m.equal_range(key);

		if (ret.first != m.end())
			std::cout << "lower bound points to ret: " << ret.first->first << " => " << ret.first->second << "\n";
		else
			std::cout << RED << "lower bound points to ret: NOTHING\n";

		if (ret.second != m.end())
			std::cout << "upper bound points to ret: " << ret.second->first << " => " << ret.second->second << "\n\n";
		else
			std::cout << RED << "upper bound points to ret: NOTHING\n\n";

		if (const_ret.first != m.end())
			std::cout << "lower bound points to const_ret: " << const_ret.first->first << " => " << const_ret.first->second << "\n";
		else
			std::cout << RED << "lower bound points to const_ret: NOTHING\n";

		if (const_ret.second != m.end())
			std::cout << "upper bound points to const_ret: " << const_ret.second->first << " => " << const_ret.second->second << "\n\n";
		else
			std::cout << RED << "upper bound points to ret: NOTHING\n\n";
}

void test_lower_upper(char key, ns::map<char, int> m)
{
	ns::map<char,int>::iterator itlow,itup;

	std::cout << YELLOW << "itlow = m.lower_bound (" << key << ");\n" << NC;
	itlow = m.lower_bound (key);
	std::cout << YELLOW << "itup = m.upper_bound (" << key << ");\n" << NC;
	itup = m.upper_bound (key);
	if (itlow == m.end())
		std::cout << RED << "itlow ---> m.lower_bound(" << key << ") NOTHING NOT LESS THAN key\n";
	else
		std::cout << "itlow ---> " << display_paire(*itlow) << std::endl;
	if (itup == m.end())
		std::cout << RED << "itup ----> m.upper_bound(" << key << ") NOTHING UPPER THAN key\n";
	else
		std::cout << "itup ----> " << display_paire(*itup) << std::endl;
}

void test_lower_upper_const(char key, ns::map<char, int> m)
{
	ns::map<char,int>::const_iterator const_itlow,const_itup;

	std::cout << YELLOW << "const_itlow = m.lower_bound (" << key << ");\n" << NC;
	const_itlow = m.lower_bound (key);
	std::cout << YELLOW << "const_itup = m.upper_bound (" << key << ");\n" << NC;
	const_itup = m.upper_bound (key);
	if (const_itlow == m.end())
		std::cout << RED << "const_itlow ---> m.lower_bound(" << key << ") NOTHING NOT LESS THAN key\n";
	else
		std::cout << "const_itlow ---> " << display_paire(*const_itlow) << std::endl;
	if (const_itup == m.end())
		std::cout << RED << "const_itup ----> m.upper_bound(" << key << ") NOTHING UPPER THAN key\n";
	else
		std::cout << "const_itup ----> " << display_paire(*const_itup) << std::endl;
}

void test_operations()
{
	{
		std::cout << CYAN << "-TEST OF FIND-" << NC << std::endl;
		ns::map<char,int> m;

		std::cout << "Create Basic map, add some value\n";
		m['A'] = 7;
		m['Z'] = 12;
		m['X'] = 54;
		m['F'] = -2;
		m['B'] = 6;
		m['G'] = 43;
		m['L'] = 89;
		display(m);

		ns::map<char, int>::iterator it;
		ns::map<char, int>::const_iterator const_it;

		std::cout << YELLOW << "it = m.find('A');\n" << NC;
		it = m.find('A');

		if (it == m.end())
			std::cout << RED << "-------> m.find('A') NOT FOUND\n";
		else
			std::cout << "-------> " << display_paire(*it) << std::endl;

		std::cout << YELLOW << "const_it = m.find('A');\n" << NC;
		const_it = m.find('A');

		if (const_it == m.end())
			std::cout << RED << "-------> m.find('A') NOT FOUND\n\n";
		else
			std::cout << "-------> " << display_paire(*const_it) << std::endl << std::endl;
		//
		std::cout << YELLOW << "it = m.find('H');\n" << NC;
		it = m.find('H');
		if (it == m.end())
			std::cout << RED << "-------> m.find('H') NOT FOUND\n";
		else
			std::cout << "-------> " << display_paire(*it) << std::endl;

		std::cout << YELLOW << "const_it = m.find('H');\n" << NC;
		const_it = m.find('H');

		if (const_it == m.end())
			std::cout << RED << "-------> m.find('H') NOT FOUND\n\n";
		else
			std::cout << "-------> " << display_paire(*const_it) << std::endl << std::endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		std::cout << CYAN << "-TEST OF COUNT-" << NC << std::endl;
		size_t count;

		std::cout << YELLOW << "count = m.count('Z');\n" << NC;
		count = m.count('Z');
		std::cout << "-------> count = " << count << std::endl;

		std::cout << YELLOW << "count = m.count('A');\n" << NC;
		count = m.count('A');
		std::cout << "-------> count = " << count << std::endl;

		std::cout << YELLOW << "count = m.count('M');\n" << NC;
		count = m.count('M');
		std::cout << "-------> count = " << count << std::endl;

		std::cout << YELLOW << "count = m.count('P');\n" << NC;
		count = m.count('P');
		std::cout << "-------> count = " << count << std::endl << std::endl;
	}
	{
		std::cout << CYAN << "-TEST OF LOWER_BOUND AND UPPER_BOUND-" << NC << std::endl;
		ns::map<char,int> m;

		m['Z'] = 12;
		m['X'] = 54;
		m['A'] = 5;
		m['F'] = -2;
		m['B'] = 6;
		m['G'] = 43;
		m['L'] = 89;
		display(m);

		std::cout << CYAN << "\tTest no const\n" << NC;

		test_lower_upper('F', m);
		test_lower_upper('A', m);
		test_lower_upper('Z', m);
		test_lower_upper('-', m);
		test_lower_upper('K', m);
		test_lower_upper('a', m);

		/////////////////////////////

		std::cout << CYAN << "\n\tTest const\n" << NC;

		test_lower_upper_const('F', m);
		test_lower_upper_const('A', m);
		test_lower_upper_const('Z', m);
		test_lower_upper_const('-', m);
		test_lower_upper_const('K', m);
		test_lower_upper_const('a', m);

		std::cout << CYAN << "\n-TEST OF EQUAL_RANGE-" << NC << std::endl;

		test_equal_range('F', m);
		test_equal_range('A', m);
		test_equal_range('Z', m);
		test_equal_range('-', m);
		test_equal_range('K', m);
		test_equal_range('a', m);
	}
}

void test_allocator()
{
	std::cout << CYAN << "-TEST OF GET_ALLOCATOR-" << NC << std::endl;
	int psize;
	ns::map<char,int> m;
	ns::pair<const char,int>* p;

	// allocate an array of 5 elements using m's allocator:
	std::cout << YELLOW << "p = m.get_allocator().allocate(5);\n" << NC;
	p = m.get_allocator().allocate(5);

	// assign some values to array
	std::cout << YELLOW << "psize = sizeof(std::map<char,int>::value_type) * 5;\n" << NC;
	psize = sizeof(std::map<char,int>::value_type) * 5;

	std::cout << "The allocated map has a size of " << psize << " bytes.\n";

	std::cout << YELLOW << "m.get_allocator().deallocate(p,5);\n" << NC;
	m.get_allocator().deallocate(p,5);
}

int main()
{
	// std::cout << "Namespace = " << NAMS << std::endl;
	test_member_function();
	test_iterator();
	test_capacity();
	test_element_access();
	test_modifiers();
	test_observers();
	test_operations();
	test_allocator();
	return (0);
}
