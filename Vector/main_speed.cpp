/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_speed.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/29 16:00:25 by vmoreau          ###   ########.fr       */
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

	std::cout << NC << "Size of vec1: " << vec1.size() << "\nSize of vec2: " << vec2.size() << '\n';	
	vec1.clear();
	vec2.clear();
	return (0);
}
