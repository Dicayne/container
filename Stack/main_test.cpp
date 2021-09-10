/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/10 16:21:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <stack>

// COLORS //
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[35m"
#define CYAN "\033[1;36m"
#define NC "\033[0;37m"

int ok = 0;
int ko = 0;
int test = 0;

void non_member_function_test()
{
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD START----" << NC << std::endl << std::endl;
	ft::stack<int> v1;
	ft::stack<int> v2;
	std::stack<int> v3;
	std::stack<int> v4;

	for (size_t i = 0; i < 15; i++)
	{
		v1.push(i);
		v2.push(i);
		v3.push(i);
		v4.push(i);
	}

	std::cout << std::boolalpha << CYAN << "FT V1 == V2 : " << NC << (v1 == v2);
	std::cout << CYAN << " | STD V1 == V2 : " << NC << (v3 == v4);
	if ((v1 == v2) == (v3 == v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	std::cout << CYAN << "FT V1 != V2 : " << NC << (v1 != v2);
	std::cout << CYAN << " | STD V1 != V2 : " << NC << (v3 != v4);
	if ((v1 != v2) == (v3 != v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	v1.pop();
	v3.pop();
	std::cout << PURPLE << "FT_V1 and STD_V1 pop()\n" << NC;

	std::cout << CYAN << "FT V1 < V2  : " << NC << (v1 < v2);
	std::cout << CYAN << " | STD V1 < V2  : " << NC << (v3 < v4);
	if ((v1 < v2) == (v3 < v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	std::cout << CYAN << "FT V1 > V2  : " << NC << (v1 > v2);
	std::cout << CYAN << " | STD V1 > V2  : " << NC << (v3 > v4);
	if ((v1 > v2) == (v3 > v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	std::cout << CYAN << "FT V1 <= V2 : " << NC << (v1 <= v2);
	std::cout << CYAN << " | STD V1 <= V2 : " << NC << (v3 <= v4);
	if ((v1 <= v2) == (v3 <= v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	std::cout << CYAN << "FT V1 >= V2 : " << NC << (v1 >= v2);
	std::cout << CYAN << " | STD V1 >= V2 : " << NC << (v3 >= v4);
	if ((v1 >= v2) == (v3 >= v4)){std::cout << GREEN << "	■\n\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	test += 6;
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD END----" << NC << std::endl << std::endl;
}

void member_function_test()
{
	std::cout << YELLOW <<"----MEMBER FUNCTION TEST BEGIN----" << NC << std::endl << std::endl;
	ft::stack<int> v1;
	std::stack<int> v2;

	std::cout << "ft::stack<int> v1 and std::stack<int> v2 created.\n\n";

	std::cout << CYAN << "- TEST OF EMPTY -" << NC << std::endl;
	std::cout << std::boolalpha << "Is ft_v empty? : " << v1.empty() << "\nIs std_v empty?: " << v2.empty() << "\n\n";

	std::cout << CYAN << "- TEST OF PUSH -" << NC << std::endl;
	std::cout << "15 value push in each stack\n\n";

	for (size_t i = 0; i < 15; i++)
		{v1.push(i); v2.push(i);}

	std::cout << "Is ft_v empty? : " << v1.empty() << "\nIs std_v empty?: " << v2.empty() << "\n\n";

	std::cout << CYAN << "- TEST OF SIZE -" << NC << std::endl;
	std::cout << "ft_v size : " << v1.size() << "\nstd_v size: " << v2.size() << "\n\n";

	std::cout << CYAN << "- TEST OF TOP -" << NC << std::endl;
	std::cout << "ft_v top : " << v1.top() << "\nstd_v top: " << v2.top() << "\n\n";

	std::cout << CYAN << "- TEST OF POP -" << NC << std::endl;

	std::cout << "3 value pop in each stack\n\n";
	for (size_t i = 0; i < 3; i++)
		{v1.pop(); v2.pop();}
	std::cout << "ft_v size : " << v1.size() << "\nstd_v size: " << v2.size() << "\n\n";
	std::cout << "ft_v top : " << v1.top() << "\nstd_v top: " << v2.top() << "\n\n";

	std::cout << "Pop entire stack\n\n";
	while (v1.size() != 0)
		{v1.pop();	v2.pop();}

	std::cout << "Is ft_v empty? : " << v1.empty() << "\nIs std_v empty?: " << v2.empty() << "\n\n";
	std::cout << "ft_v size : " << v1.size() << "\nstd_v size: " << v2.size() << "\n\n";
	std::cout << YELLOW <<"----MEMBER FUNCTION TEST END----" << NC << std::endl << std::endl;
}

int main()
{

	member_function_test();
	non_member_function_test();

	// ft::stack<int> ft_stack;
	// std::stack<int> std_stack;

	// for (int i=0; i<5; ++i) std_stack.push(i);

	// std::cout << "Popping out elements...";
	// while (!std_stack.empty())
	// {
	// 	 std::cout << ' ' << std_stack.top();
	// 	 std_stack.pop();
	// }
	// std::cout << '\n';

	// for (int i=0; i<5; ++i) ft_stack.push(i);

	// std::cout << "Popping out elements...";
	// while (!ft_stack.empty())
	// {
	// 	 std::cout << ' ' << ft_stack.top();
	// 	 ft_stack.pop();
	// }
	std::cout << '\n';
	return (0);
}