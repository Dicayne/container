/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/03 19:15:05 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> ft_v (4,0);
	std::vector<int> std_v (4,0);

	// std_v = ft_v;
	// ft_v = ft::vector<int>();

	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;

	std::cout << "Size of ft_v: " << int(ft_v.size()) << '\n';
	std::cout << "Size of std_v: " << int(std_v.size()) << '\n';

	std::cout << "Max_Size of ft_v: " << int(ft_v.max_size()) << '\n';
	std::cout << "Max_Size of std_v: " << int(std_v.max_size()) << '\n';

	std::cout << "Capacity of ft_v: " << int(ft_v.capacity()) << '\n';
	std::cout << "Capacity of std_v: " << int(std_v.capacity()) << '\n';

	ft_v.resize(6, 50);
	std_v.resize(6, 50);

	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;

	std::cout << "Size of ft_v: " << int(ft_v.size()) << '\n';
	std::cout << "Size of std_v: " << int(std_v.size()) << '\n';

	std::cout << "Max_Size of ft_v: " << int(ft_v.max_size()) << '\n';
	std::cout << "Max_Size of std_v: " << int(std_v.max_size()) << '\n';

	std::cout << "Capacity of ft_v: " << int(ft_v.capacity()) << '\n';
	std::cout << "Capacity of std_v: " << int(std_v.capacity()) << '\n';

	ft_v.resize(7, 5);
	std_v.resize(7, 5);

	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;

	std::cout << "Size of ft_v: " << int(ft_v.size()) << '\n';
	std::cout << "Size of std_v: " << int(std_v.size()) << '\n';

	std::cout << "Max_Size of ft_v: " << int(ft_v.max_size()) << '\n';
	std::cout << "Max_Size of std_v: " << int(std_v.max_size()) << '\n';

	std::cout << "Capacity of ft_v: " << int(ft_v.capacity()) << '\n';
	std::cout << "Capacity of std_v: " << int(std_v.capacity()) << '\n';
	// ft_v.push_back(42);
	// std_v.push_back(42);

	ft_v.resize(2, 3);
	std_v.resize(2, 3);

	for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;
	std::cout << std::endl;
	for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); ++it)
		std::cout << ' ' << *it << std::endl;

	std::cout << "Size of ft_v: " << int(ft_v.size()) << '\n';
	std::cout << "Size of std_v: " << int(std_v.size()) << '\n';

	std::cout << "Max_Size of ft_v: " << int(ft_v.max_size()) << '\n';
	std::cout << "Max_Size of std_v: " << int(std_v.max_size()) << '\n';

	std::cout << "Capacity of ft_v: " << int(ft_v.capacity()) << '\n';
	std::cout << "Capacity of std_v: " << int(std_v.capacity()) << '\n';


	// ft_v.clear();
	// std_v.clear();

	// std::cout << "Size of ft_v: " << int(ft_v.size()) << '\n';
	// std::cout << "Size of std_v: " << int(std_v.size()) << '\n';

	// std::cout << "Max_Size of ft_v: " << int(ft_v.max_size()) << '\n';
	// std::cout << "Max_Size of std_v: " << int(std_v.max_size()) << '\n';

	// std::cout << "Capacity of ft_v: " << int(ft_v.capacity()) << '\n';
	// std::cout << "Capacity of std_v: " << int(std_v.capacity()) << '\n';

	// for (ft::vector<int>::iterator it = ft_v.begin(); it != ft_v.end(); ++it)
	// 	std::cout << ' ' << *it << std::endl;
	// std::cout << std::endl;
	// for (std::vector<int>::iterator it = std_v.begin(); it != std_v.end(); ++it)
	// 	std::cout << ' ' << *it << std::endl;
	// std::cout << std::endl;
	std::cout << "END MAIN" << std::endl;
	return (0);
	return (0);
}