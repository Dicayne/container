/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/12/02 18:41:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../Utils/colors.hpp"
#include <vector>

#ifndef mine
	#include <vector>
	namespace ns = std;

#else
	#include "vector.hpp"
	namespace ns = ft;

#endif

int main()
{
	ns::vector<int>vec1(500000000, 42);
	ns::vector<int>vec2(vec1);

	std::cout << "Size of vec1:     " << vec1.size() << "\nSize of vec2:     " << vec2.size() << '\n';
	std::cout << "Capacity of vec1: " << vec1.capacity() << "\nCapacity of vec2: " << vec2.capacity() << "\n\nClear vectors\n\n" ;

	vec1.clear();
	vec2.clear();

	std::cout << "Size of vec1:     " << vec1.size() << "\nSize of vec2:     " << vec2.size() << '\n';
	std::cout << "Capacity of vec1: " << vec1.capacity() << "\nCapacity of vec2: " << vec2.capacity() << "\n\n";
	return (0);
}
