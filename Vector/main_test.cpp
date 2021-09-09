/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/09 19:36:06 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

// COLORS //
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[35m"
#define CYAN "\033[1;36m"
#define NC "\033[0;37m"

int test = 0;
int ok = 0;
int ko = 0;

void disp_vec(std::vector<int> &std_v, ft::vector<int> &ft_v)
{
	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n\n";
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n\n";
}

void display_vector(std::vector<int> &std_v, ft::vector<int> &ft_v)
{
	std::cout << "ft_vector	std_vector" << std::endl;
	ft::vector<int>::iterator it = ft_v.begin();
	std::vector<int>::iterator it2 = std_v.begin();
	bool same = true;
	while (it != ft_v.end() && it2 != std_v.end())
	{
		std::cout << *it << "		" << *it2;
		if (*it == *it2)
		{
			std::cout << GREEN << "	■\n" << NC;
		}
		else
		{
			std::cout << RED << "	■\n" << NC;
			same = false;
		}
		it++;
		it2++;
	}
	if (it != ft_v.end() || it2 != std_v.end() || same == false)
	{
		std::cout << RED << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\nError Vectors are different \n" << NC;
		ko++;
	}
	else
	{
		std::cout << GREEN << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n" << NC;
		ok++;
	}
	test++;
	std::cout << std::endl;
}

void display_info(std::vector<int> &std_v, ft::vector<int> &ft_v)
{
	std::cout << "Size of ft_v:  " << ft_v.size();
	if (ft_v.size() == std_v.size())
	{
		std::cout << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "Size of std_v: " << std_v.size() << std::endl;

	std::cout << "Capacity of ft_v:  " << ft_v.capacity();
	if (ft_v.capacity() == std_v.capacity())
	{
		std::cout << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "Capacity of std_v: " << std_v.capacity() << std::endl << std::endl;
}

void capacity_test()
{
	std::cout << YELLOW <<"----CAPACITY FUNCTION TEST BEGIN----" << NC << std::endl << std::endl;
	{
		ft::vector<int> ft_v(4,0);
		std::vector<int> std_v(4,0);

		std::cout << "ft::vector<int> ft_v(4,0) and std::vector<int> std_v(4,0) created." << std::endl;

		std::cout << CYAN << "-TEST OF SIZE, CAPACITY, MAX_SIZE-" << NC << std::endl;
		display_info(std_v, ft_v);
		std::cout << "Max_Size of ft_v:  " << ft_v.max_size();
		if (ft_v.max_size() == std_v.max_size())
		{
			std::cout << GREEN << "	■\n" << NC;
			ok++;
		}
		else
		{
			std::cout << RED << "	■\n" << NC;
			ko++;
		}
		test++;
		std::cout << "Max_Size of std_v: " << std_v.max_size() << std::endl << std::endl;

		std::cout << CYAN << "-TEST OF RESIZE-" << NC << std::endl;

		display_info(std_v, ft_v);
		ft_v.resize(6, 50);
		std_v.resize(6, 50);
		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);
		ft_v.resize(7, 78);
		std_v.resize(7, 78);
		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);
		ft_v.resize(12, 5);
		std_v.resize(12, 5);
		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);
		ft_v.resize(3, 42);
		std_v.resize(3, 42);
		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);

		std::cout << CYAN << "-TEST OF EMPTY-" << NC << std::endl;
		display_info(std_v, ft_v);
		std::cout << "Is ft_v empty?  : " << (ft_v.empty() == 1 ? "True" : "False") << std::endl;
		std::cout << "Is std_v empty? : " << (std_v.empty() == 1 ? "True" : "False") << std::endl;
		std::cout << std::endl << "Clear Vectors" << std::endl << std::endl;
		ft_v.clear();
		std_v.clear();
		display_info(std_v, ft_v);
		std::cout << "Is ft_v empty?  : " << (ft_v.empty() == 1 ? "True" : "False") << std::endl;
		std::cout << "Is std_v empty? : " << (std_v.empty() == 1 ? "True" : "False") << std::endl;
	}
	{
		std::cout << CYAN << "-TEST OF RESERVE-" << NC << std::endl;

		std::cout << "ft::vector<int> ft_v1 and std::vector<int> std_v1 created." << std::endl;
		ft::vector<int>::size_type sz;
		std::vector<int>::size_type sz2;

		ft::vector<int> ft_v1;
		std::vector<int> std_v1;
		sz = ft_v1.capacity();
		sz2 = std_v1.capacity();
		std::cout << "making ft_v1 & std_v1 grow:\n";
		std::cout << "ft_v1				| std_v1\n";
		for (int i = 0; i < 100; ++i)
		{
			bool check = false;
			ft_v1.push_back(i);
			std_v1.push_back(i);
			if (sz != ft_v1.capacity()) {
				sz = ft_v1.capacity();
				std::cout << "capacity ft_v changed: " << sz << "	";
				check = true;
			}
			if (sz2 != std_v1.capacity()) {
				sz2 = std_v1.capacity();
				std::cout << " capacity std_v changed: " << sz2 << "	";
				check = true;
			}
			if (check == true)
			{
				if (sz == sz2)
				{
					std::cout << GREEN << "	■\n" << NC;
					ok++;
				}
				else
				{
					std::cout << RED << "	■\n" << NC;
					ko++;
				}
				test++;
			}
		}
		std::cout << std::endl;
		std::cout << "ft::vector<int> ft_v2 and std::vector<int> std_v2 created." << std::endl;
		ft::vector<int> ft_v2;
		std::vector<int> std_v2;
		sz = ft_v2.capacity();
		sz2 = std_v2.capacity();
		ft_v2.reserve(100);	 // this is the only difference with v1 above
		std_v2.reserve(100);
		std::cout << "making ft_v2 & std_v2 grow:\n";
		std::cout << "ft_v2				| std_v2\n";
		for (int i = 0; i < 100; ++i)
		{
			ft_v2.push_back(i);
			std_v2.push_back(i);
			if (sz != ft_v2.capacity()) {
				sz = ft_v2.capacity();
				std::cout << "capacity ft_v changed: " << sz << '	';
			}
			if (sz2 != std_v2.capacity()) {
				sz2 = std_v2.capacity();
				std::cout << " capacity std_v changed: " << sz2 << '\n';
			}
		}
	}
	std::cout << YELLOW <<"----CAPACITY FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void element_access_test()
{
	std::cout << YELLOW <<"----ELEMENT ACCESS FUNCTION TEST START----" << NC << std::endl << std::endl;

	std::cout << "ft::vector<int> ft_v and std::vector<int> std_v created. And filled with random integer" << std::endl;
	ft::vector<int> ft_v;
	std::vector<int> std_v;
	int random;

	for (size_t i = 0; i < 10; i++)
	{
		random = rand() % 100;
		ft_v.push_back(random);
		std_v.push_back(random);
	}
	display_vector(std_v, ft_v);

	std::cout << CYAN << "-TEST OF OPERATOR[ ]-" << NC << std::endl;
	std::cout << "		  ft_v		std_v\n";
	std::cout << "[3]		= ";
	if (ft_v[3] == std_v[3])
	{
		std::cout << ft_v[3] << "\t\t" << std_v[3] << GREEN << "	■\n" << NC;
			ok++;
	}
	else
	{
		std::cout << ft_v[3] << "\t\t" << std_v[3] << RED << "	■\n" << NC;
		ko++;
	}
	test++;

	std::cout << "[8]		= ";
	if (ft_v[8] == std_v[8])
	{
		std::cout << ft_v[8] << "\t\t" << std_v[8] << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v[8] << "\t\t" << std_v[8] << RED << "	■\n" << NC;
		ko++;
	}
	test++;

	std::cout << "[0]		= ";
	if (ft_v[0] == std_v[0])
	{
		std::cout << ft_v[0] << "\t\t" << std_v[0] << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v[0] << "\t\t" << std_v[0] << RED << "	■\n" << NC;
		ko++;
	}
	test++;

	std::cout << "[v.size() - 1]	= ";
	if (ft_v[ft_v.size() - 1] == std_v[std_v.size() - 1])
	{
		std::cout << ft_v[ft_v.size() - 1] << "\t\t" << std_v[std_v.size() - 1] << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v[ft_v.size() - 1] << "\t\t" << std_v[ft_v.size() - 1] << RED << "	■\n" << NC;
		ko++;
	}
	test++;

	std::cout << std::endl;
	std::cout << CYAN << "-TEST OF AT-" << NC << std::endl;
	std::cout << "			ft_v		std_v\n";
	std::cout << "at.(4)			= ";
	if (ft_v.at(4) == std_v.at(4))
	{
		std::cout << ft_v.at(4) << "\t\t" << std_v.at(4) << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.at(4) << "\t\t" << std_v.at(4) << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "at.(7)			= ";
	if (ft_v.at(7) == std_v.at(7))
	{
		std::cout << ft_v.at(7) << "\t\t" << std_v.at(7) << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.at(7) << "\t\t" << std_v.at(7) << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "at.(0)			= ";
	if (ft_v.at(0) == std_v.at(0))
	{
		std::cout << ft_v.at(0) << "\t\t" << std_v.at(0) << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.at(0) << "\t\t" << std_v.at(0) << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "at.(v.size() - 1)	= ";
	if (ft_v.at(ft_v.size() -1) == std_v.at(std_v.size() -1))
	{
		std::cout << ft_v.at(ft_v.size() -1) << "\t\t" << std_v.at(std_v.size() -1) << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.at(ft_v.size() -1) << "\t\t" << std_v.at(std_v.size() -1) << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << std::endl;
	std::cout << CYAN << "-TEST OF FRONT & BACK-" << NC << std::endl;
	std::cout << "v.front() = ";
	if (ft_v.front() == std_v.front())
	{
		std::cout << ft_v.front() << "\t" << std_v.front() << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.front() << "\t" << std_v.front() << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << "v.back() =  ";
	if (ft_v.back() == std_v.back())
	{
		std::cout << ft_v.back() << "\t" << std_v.back() << GREEN << "	■\n" << NC;
		ok++;
	}
	else
	{
		std::cout << ft_v.back() << "\t\t" << std_v.back() << RED << "	■\n" << NC;
		ko++;
	}
	test++;
	std::cout << YELLOW <<"----ELEMENT ACCESS FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void modifier_test()
{
	std::cout << YELLOW <<"----MODIFIER FUNCTION TEST START----" << NC << std::endl << std::endl;
	std::cout << "ft::vector<int> ft_v and std::vector<int> std_v created." << std::endl;

	std::cout << CYAN << "-TEST OF PUSH_BACK, POP_BACK & CLEAR-" << NC << std::endl;
	{
		ft::vector<int> ft_v;
		std::vector<int> std_v;
		int random;

		std::cout << PURPLE << "Push_Back 5 integer\n" << NC;
		for (size_t i = 0; i < 5; i++)
		{
			random = rand() % 100;
			ft_v.push_back(random);
			std_v.push_back(random);
			display_vector(std_v, ft_v);
			display_info(std_v, ft_v);
		}

		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);

		std::cout << PURPLE << "Pop_Back 4 time\n" << NC;
		for (size_t i = 0; i < 4; i++)
		{
			ft_v.pop_back();
			std_v.pop_back();
			display_vector(std_v, ft_v);
			display_info(std_v, ft_v);
		}

		std::cout << PURPLE << "Clear vectors\n" << NC;
		ft_v.clear();
		std_v.clear();
		display_vector(std_v, ft_v);
		display_info(std_v, ft_v);
	}
	std::cout << CYAN << "-TEST OF SWAP-" << NC << std::endl;
	{
		ft::vector<int> v1 (3,100);	// three ints with a value of 100
		ft::vector<int> v2 (5,200);	// five  ints with a value of 200

		std::cout << "2 Vectors created, v1 with 3 ints with a value of 100 and v2 with 5 ints with a value of 200\n";
		std::cout << PURPLE << "Before Swap\n" << NC;
		std::cout << "v1 contains:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << ' ' << v1[i];
		std::cout << '\n';

		std::cout << "v2 contains:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << ' ' << v2[i];
		std::cout << '\n';

		v1.swap(v2);

		std::cout << PURPLE << "After Swap\n" << NC;
		std::cout << "v1 contains:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << ' ' << v1[i];
		std::cout << '\n';

		std::cout << "v2 contains:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << ' ' << v2[i];
		std::cout << "\n\n";
	}
	std::cout << CYAN << "-TEST OF ASSIGN-" << NC << std::endl;
	{
		ft::vector<int> v1 (10, 48);
		ft::vector<int> v2 ( 15, 13);

		std::cout << "v1 contains:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << ' ' << v1[i];
		std::cout << '\n';
		std::cout << "v2 contains:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << ' ' << v2[i];
		std::cout << '\n';

		std::cout << "Size of v1: " << v1.size() << std::endl;
		std::cout << "Size of v2: " << v2.size() << std::endl;
		std::cout << "Capacity of v1: " << v1.capacity() << std::endl;
		std::cout << "Capacity of v2: " << v2.capacity() << std::endl << std::endl;

		v2.assign(v1.begin() + 1 , v1.begin() + 5);
		v1.assign(5, 98);

		std::cout << "v1 contains:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << ' ' << v1[i];
		std::cout << '\n';
		std::cout << "v2 contains:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << ' ' << v2[i];
		std::cout << '\n';

		std::cout << "Size of v1: " << v1.size() << std::endl;
		std::cout << "Size of v2: " << v2.size() << std::endl;
		std::cout << "Capacity of v1: " << v1.capacity() << std::endl;
		std::cout << "Capacity of v2: " << v2.capacity() << std::endl << std::endl;
	}
	std::cout << CYAN << "-TEST OF ERASE-" << NC << std::endl;
	{
		ft::vector<int> v1;
		std::vector<int> v2;
		for (size_t i = 0; i < 15; i++)
		{
			v1.push_back(i);
			v2.push_back(i);
		}
		display_vector(v2, v1);
		display_info(v2, v1);

		// 1st
		std::cout << PURPLE << "v.erase(v.begin())\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.begin())) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.begin())) << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);

		std::cout << PURPLE << "v.erase(v.end() - 1)\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.end() - 1)) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.end() - 1)) << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);

		std::cout << PURPLE << "v.erase(v.begin() + 4)\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.begin() + 4)) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.begin() + 4)) << std::endl << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);

		// 2nd
		std::cout << PURPLE << "v.erase(v.begin() + 10, v.end() - 1)\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.begin() + 10 , v1.end() - 1)) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.begin() + 10 , v2.end() - 1)) << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);

		std::cout << PURPLE << "v.erase(v.begin(), v.end() - 7)\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.begin() , v1.end() - 7)) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.begin() , v2.end() - 7)) << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);

		std::cout << PURPLE << "v.erase(v.end() - 3, v.end())\n" << NC;
		std::cout << "Return ft:  " << *(v1.erase(v1.end() - 3 , v1.end())) << std::endl;
		std::cout << "Return std: " << *(v2.erase(v2.end() - 3 , v2.end())) << std::endl;
		display_vector(v2, v1);
		display_info(v2, v1);
	}
	std::cout << CYAN << "-TEST OF INSERT-" << NC << std::endl;
	{
		std::cout << BLUE << "INSERT SINGLE ELEMENT\n" << NC;
		{
			ft::vector<int> v1(4, 100);
			std::vector<int> v2(4, 100);

			display_vector(v2, v1);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.begin() + 2, 200)\n" << NC;
			std::cout << "Return ft:  " << *(v1.insert(v1.begin() + 2, 200)) << std::endl;
			std::cout << "Return std: " << *(v2.insert(v2.begin() + 2, 200)) << std::endl << std::endl;

			std::cout << PURPLE << "v.insert(v.begin() + 5, 42))\n" << NC;
			std::cout << "Return ft:  " << *(v1.insert(v1.begin() + 5, 42)) << std::endl;
			std::cout << "Return std: " << *(v2.insert(v2.begin() + 5, 42)) << std::endl << std::endl;

			std::cout << PURPLE << "v.insert(v.begin(),8))\n" << NC;
			std::cout << "Return ft:  " << *(v1.insert(v1.begin(), 8)) << std::endl;
			std::cout << "Return std: " << *(v2.insert(v2.begin(), 8)) << std::endl << std::endl;

			std::cout << PURPLE << "v.insert(v.end() - 1, 79))\n" << NC;
			std::cout << "Return ft:  " << *(v1.insert(v1.end() - 1, 79)) << std::endl;
			std::cout << "Return std: " << *(v2.insert(v2.end() - 1, 79)) << std::endl << std::endl;

			std::cout << PURPLE << "v.insert(v.end(), 25))\n" << NC;
			std::cout << "Return ft:  " << *(v1.insert(v1.end(), 25)) << std::endl;
			std::cout << "Return std: " << *(v2.insert(v2.end(), 25)) << std::endl << std::endl;

			display_vector(v2, v1);
			display_info(v2, v1);
		}
		std::cout << BLUE << "INSERT FILL ELEMENT\n" << NC;
		{
			ft::vector<int> v1(4, 100);
			std::vector<int> v2(4, 100);

			display_vector(v2, v1);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.begin() + 2, 4, 200)\n" << NC;
			v1.insert(v1.begin() + 2, 5, 200);
			v2.insert(v2.begin() + 2, 5, 200);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.begin() + 5, 5, 42))\n" << NC;
			v1.insert(v1.begin() + 5, 5, 42);
			v2.insert(v2.begin() + 5, 5, 42);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.begin(), 2, 8))\n" << NC;
			v1.insert(v1.begin(), 2, 8);
			v2.insert(v2.begin(), 2, 8);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.end() - 1, 1, 79))\n" << NC;
			v1.insert(v1.end() - 1, 1, 79);
			v2.insert(v2.end() - 1, 1, 79);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.end(),3, 25))\n" << NC;
			v1.insert(v1.end(), 3, 25);
			v2.insert(v2.end(), 3, 25);
			display_vector(v2, v1);
			display_info(v2, v1);
		}
		std::cout << BLUE << "INSERT RANGE ELEMENT\n" << NC;
		{
			ft::vector<int> v1(4, 100);
			std::vector<int> v2(4, 100);
			ft::vector<int> v3;
			std::vector<int> v4;

			for (size_t i = 0; i < 15; i++){
				v3.push_back(i); v4.push_back(i);}

			display_vector(v2, v1);
			display_info(v2, v1);
			std::cout << PURPLE << "v.insert(v.begin() + 1, v2.begin() + 3, v2.end() - 3)\n" << NC;
			v1.insert(v1.begin() + 1, v3.begin() + 3, v3.end() - 3);
			v2.insert(v2.begin() + 1, v4.begin() + 3, v4.end() - 3);
			display_vector(v2, v1);
			display_info(v2, v1);

			std::cout << PURPLE << "v.end(), v.begin(), v.end())\n" << NC;
			v1.insert(v1.end(), v1.begin(), v1.end());
			v2.insert(v2.end(), v2.begin(), v2.end());

			display_vector(v2, v1);
			display_info(v2, v1);
		}
	}
	std::cout << YELLOW <<"----MODIFIER FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void constructor_test()
{
	std::cout << CYAN << "-TEST OF DEFAULT CONSTRUCTOR v1-" << NC << std::endl;
	ft::vector<int> ft_v1;
	std::vector<int> std_v1;

	display_vector(std_v1, ft_v1);
	display_info(std_v1, ft_v1);

	std::cout << CYAN << "-TEST OF FILL CONSTRUCTOR v2(5, 100)-" << NC << std::endl;
	ft::vector<int> ft_v2(5, 100);
	std::vector<int> std_v2(5, 100);

	display_vector(std_v2, ft_v2);
	display_info(std_v2, ft_v2);


	std::cout << CYAN << "-TEST OF COPY CONSTRUCTOR v3(v2)-" << NC << std::endl;
	ft::vector<int> ft_v3(ft_v2);
	std::vector<int> std_v3(std_v2);

	display_vector(std_v3, ft_v3);
	display_info(std_v3, ft_v3);


	std::cout << CYAN << "-TEST OF RANGE CONSTRUCTOR v4(v3.begin() v3.end())-" << NC << std::endl;
	ft::vector<int> ft_v4(ft_v3.begin(), ft_v3.end());
	std::vector<int> std_v4(std_v3.begin(), std_v3.end());

	display_vector(std_v4, ft_v4);
	display_info(std_v4, ft_v4);

	std::cout << CYAN << "-TEST OF OPERATOR= -" << NC << std::endl;
	std::cout << PURPLE << "\nv5(3, 42)\n" << NC;
	ft::vector<int> ft_v5(3, 42);
	std::vector<int> std_v5(3, 42);

	display_vector(std_v5, ft_v5);
	display_info(std_v5, ft_v5);
	std::cout << PURPLE << "v5 = v3\n" << NC;
	ft_v5 = ft_v3;
	std_v5 = std_v3;
	display_vector(std_v5, ft_v5);
	display_info(std_v5, ft_v5);
	std::cout << "\n\n";
}

void allocator_test()
{
	ft::vector<int> v1;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = v1.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) v1.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) v1.get_allocator().destroy(&p[i]);
	v1.get_allocator().deallocate(p,5);

}

void disp_vec_std(std::vector<int> &std1_v, std::vector<int> &std2_v)
{
	std::cout << "STD_VECTORS :\nV1: ";
	for (std::vector<int>::iterator it = std2_v.begin(); it != std2_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n Size: "<< std2_v.size() << "	Capacity: " << std2_v.capacity() << "\nV2: ";
	for (std::vector<int>::iterator it = std1_v.begin(); it != std1_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n Size: "<< std1_v.size() << "	Capacity: " << std1_v.capacity() << "\n\n";
}

void disp_vec_ft(ft::vector<int> &ft1_v, ft::vector<int> &ft2_v)
{
	std::cout << "FT_VECTORS :\nV1: ";
	for (ft::vector<int>::iterator it = ft2_v.begin(); it != ft2_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n Size: "<< ft2_v.size() << "	Capacity: " << ft2_v.capacity() << "\nV2: ";
	for (ft::vector<int>::iterator it = ft1_v.begin(); it != ft1_v.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n Size: "<< ft1_v.size() << "	Capacity: " << ft1_v.capacity() << "\n\n";
}

void non_member_function_overloads_test()
{
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD START----" << NC << std::endl << std::endl;
	ft::vector<int> v1;
	ft::vector<int> v2;
	std::vector<int> v3;
	std::vector<int> v4;
	for (size_t i = 0; i < 15; i++)
	{
		v1.push_back(i);
		v2.push_back(i);
		v3.push_back(i);
		v4.push_back(i);
	}

	disp_vec_ft(v1, v2);
	disp_vec_std(v3, v4);

	std::cout << std::boolalpha << CYAN << "FT V1 == V2 : " << NC << (v1 == v2);
	std::cout << CYAN << " | STD V1 == V2 : " << NC << (v3 == v4);
	if ((v1 == v2) == (v3 == v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	std::cout << CYAN << "FT V1 != V2 : " << NC << (v1 != v2);
	std::cout << CYAN << " | STD V1 != V2 : " << NC << (v3 != v4);
	if ((v1 != v2) == (v3 != v4)){std::cout << GREEN << "	■\n" << NC;ok++;}
	else{std::cout << RED << "	■\n" << NC; ko++;}

	v1.pop_back();
	v3.pop_back();
	std::cout << PURPLE << "V1 and V3 pop_back()\n" << NC;

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
	std::cout << CYAN << "- SWAP FUNCTION TEST -\n" << NC;
	disp_vec_ft(v1, v2);
	disp_vec_std(v3, v4);
	v1.swap(v2);
	v3.swap(v4);
	disp_vec_ft(v1, v2);
	disp_vec_std(v3, v4);
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD END----" << NC << std::endl << std::endl;
}

int main()
{
	constructor_test();
	capacity_test();
	element_access_test();
	modifier_test();
	allocator_test();
	non_member_function_overloads_test();
	std::cout << "END MAIN : "<< test << " test ->" << GREEN << ok << " OK  " << RED << ko << " KO" << NC << std::endl;
	return (0);
}