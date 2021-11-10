/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/09 20:45:29 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Utils/colors.hpp"
#include <iostream>

#ifndef mine
	#include <stack>
	#include <vector>
	namespace ns = std;
	#define NAMS "STD"

#else
	#include "stack.hpp"
	namespace ns = ft;
	#define NAMS "FT"

#endif

template < class T >
void display_stk(ns::stack<T> &stk)
{
	std::cout << "Display Stack:\n" << BLUE << "---------------------\n" << NC;
	if (stk.empty() == true)
		std::cout << "Stack is Empty\n";

	else
	{
		ns::stack<T> dump = stk;
		while (!dump.empty())
		{
			std::cout << dump.top() << "  ";
			dump.pop();
		}
		std::cout << "\n\n";
	}
	std::cout << BLUE << "---------------------\n" << NC;
}

template < class T >
void disp_vector(ns::vector<T> &ft_v)
{
	std::cout << "Display Vector Iterator:\n" << BLUE << "---------------------\n" << NC;
	for (typename ns::vector<T>::reverse_iterator it = ft_v.rbegin(); it != ft_v.rend(); it++)
		std::cout << *it << ' ';
	std::cout << "\n\n";
	std::cout << BLUE << "---------------------\n" << NC;
}

template < class T >
void disp_vec(ns::vector<T> &vec)
{
	std::cout << "Display Vector:\n" << BLUE << "---------------------\n" << NC;
	if (vec.empty() == true)
		std::cout << "Stack is Empty\n";
	else
	{
		disp_vector(vec);
		ns::vector<T> dump = vec;
		while (!dump.empty())
		{
			std::cout << dump.back() << ' ';
			dump.pop_back();
		}
		std::cout << "\n\n";
	}
	std::cout << BLUE << "---------------------\n" << NC;
}

void non_member_function_test()
{
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD START----" << NC << std::endl << std::endl;
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD END----" << NC << std::endl << std::endl;
}

void constructor_test()
{
	std::cout << YELLOW <<"----CONSTRUCTOR TEST BEGIN----" << NC << std::endl << std::endl;
	ns::vector<int> vec (2,200);					// vector with 2 elements

	ns::stack<int> first;							// empty stack
	ns::stack<int, ns::vector<int> > second;		// empty stack using ft_vector
	ns::stack<int, ns::vector<int> > third(vec);	// cpy stack using vec

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';

	std::cout << YELLOW <<"\n----CONSTRUCTOR TEST END----" << NC << std::endl << std::endl;
}

void info_test()
{
	std::cout << YELLOW <<"----INFO TEST BEGIN----" << NC << std::endl << std::endl;
	ns::stack<char> stk;							// empty stack

	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl << std::endl;
	std::cout << "Push 2 value in the stack:\n";

	stk.push('f');
	stk.push('t');
	display_stk(stk);

	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl;
	std::cout << "Stack top: " << CYAN << stk.top() << NC << std::endl;
	std::cout << YELLOW <<"\n----INFO TEST BEGIN----" << NC << std::endl << std::endl;
}

void push_pop_test()
{
	std::cout << YELLOW <<"----PUSH POP TEST BEGIN----" << NC << std::endl << std::endl;
	ns::stack<char> stk;							// empty stack
	ns::vector<char> vec;
	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl << std::endl;
	std::cout << "Push printable ascii value in the stack:\n";

	for (char i = '!'; i <= '~'; i++)
		stk.push(i);

	std::cout << "----\n";

	for (char i = '!'; i <= '~'; i++)
		vec.push_back(i);

	// display_stk(stk);
	disp_vector(vec);
	ns::vector<char> dump;
	dump = vec;
	disp_vector(vec);
	// disp_vec(vec);

	std::cout << "\n\n";
	std::cout << "Stack empty: " << CYAN << vec.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << vec.size() << NC << std::endl;
	std::cout << "Stack top: " << CYAN << vec.back() << NC << std::endl;

	std::cout << YELLOW <<"\n----PUSH POP TEST BEGIN----" << NC << std::endl << std::endl;
}

int main()
{
	std::cout << std::boolalpha; // Used to see bool results as true/false instead of 1/0
	// constructor_test();
	// info_test();
	push_pop_test();
	// non_member_function_test();
	return (0);
}
