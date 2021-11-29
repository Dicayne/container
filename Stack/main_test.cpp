/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/29 16:22:51 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Utils/colors.hpp"
#include <iostream>

#ifndef mine
	#include <stack>
	#include <vector>
	namespace ns = std;

#else
	#include "stack.hpp"
	namespace ns = ft;

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
			std::cout << dump.top() << ' ';
			dump.pop();
		}
		std::cout << "\n\n";
	}
	std::cout << BLUE << "---------------------\n\n" << NC;
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
	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl << std::endl;
	std::cout << "Push printable ascii value in the stack:\n";

	for (char i = '!'; i <= '~'; i++)
		stk.push(i);

	display_stk(stk);
	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl;
	std::cout << "Stack top: " << CYAN << stk.top() << NC << std::endl << std::endl;

	std::cout << "10 Value poped:\n";
	for (size_t i = 0; i < 10; i++)
		stk.pop();

	display_stk(stk);
	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl;
	std::cout << "Stack top: " << CYAN << stk.top() << NC << std::endl << std::endl;

	std::cout << "Clear stack:\n";
	while (!stk.empty())
		stk.pop();

	display_stk(stk);
	std::cout << "Stack empty: " << CYAN << stk.empty() << NC << std::endl;
	std::cout << "Stack size: " << CYAN << stk.size() << NC << std::endl;

	std::cout << YELLOW <<"\n----PUSH POP TEST BEGIN----" << NC << std::endl << std::endl;
}

void non_member_function_test()
{
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD START----" << NC << std::endl << std::endl;
	ns::stack<std::string> stk1;
	ns::stack<std::string> stk2;

	for (int i = 0; i < 10; i++)
		stk1.push("Hello");
	for (int i = 0; i < 5; i++)
		stk2.push("World");
	std::cout << "STK1 ";
	display_stk(stk1);
	std::cout << "STK2 ";
	display_stk(stk2);

	std::cout << "stk1 == stk2 :" << (stk1 == stk2) << '\n';
	std::cout << "stk1 != stk2 :" << (stk1 != stk2) << '\n';
	std::cout << "stk1 < stk2  :" << (stk1 < stk2) << '\n';
	std::cout << "stk1 <= stk2 :" << (stk1 <= stk2) << '\n';
	std::cout << "stk1 > stk2  :" << (stk1 > stk2) << '\n';
	std::cout << "stk1 >= stk2 :" << (stk1 >= stk2) << "\n\n";

	std::cout << "STK1 = STK2\n\n";

	std::cout << "stk1 == stk2 :" << (stk1 == stk2) << '\n';
	std::cout << "stk1 != stk2 :" << (stk1 != stk2) << '\n';
	std::cout << "stk1 < stk2  :" << (stk1 < stk2) << '\n';
	std::cout << "stk1 <= stk2 :" << (stk1 <= stk2) << '\n';
	std::cout << "stk1 > stk2  :" << (stk1 > stk2) << '\n';
	std::cout << "stk1 >= stk2 :" << (stk1 >= stk2) << "\n\n";
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD END----" << NC << std::endl << std::endl;
}

int main()
{
	std::cout << std::boolalpha; // Used to see bool results as true/false instead of 1/0

	constructor_test();			// Test all constructor
	info_test();				// Test empty, size, top
	push_pop_test();			// Test push, pop
	non_member_function_test();	// Test == != < > <= >= on stack
	
	return (0);
}
