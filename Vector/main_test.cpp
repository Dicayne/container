/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 13:48:04 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/16 14:17:09 by vmoreau          ###   ########.fr       */
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

template < class T >
void disp_info(ns::vector<T> &vec)
{
	std::cout << "Size of vec:  " << vec.size() << std::endl;
	std::cout << "Capacity of vec:  " << vec.capacity() << std::endl;
	std::cout << std::endl;
}

template < class T >
void disp_vec(ns::vector<T> &vec)
{
	std::cout << "Display Vector:\n" << BLUE << "---------------------\n" << NC;

	disp_info(vec);
	if (vec.empty() == true)
		std::cout << "Stack is Empty\n";
	else
		for (typename ns::vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << " ";

	std::cout << BLUE << "\n---------------------\n\n" << NC;
}

void constructor_test()
{
	std::cout << YELLOW <<"----CONSTRUCTOR FUNCTION TEST BEGIN----" << NC << std::endl << std::endl;
	std::cout << CYAN << "-TEST OF DEFAULT CONSTRUCTOR vec1-" << NC << std::endl;
	ns::vector<int> vec1;

	disp_vec(vec1);

	std::cout << CYAN << "-TEST OF FILL CONSTRUCTOR vec2(5, 100)-" << NC << std::endl;
	ns::vector<int> vec2(5, 100);

	disp_vec(vec2);

	std::cout << CYAN << "-TEST OF COPY CONSTRUCTOR v3(vec2)-" << NC << std::endl;
	ns::vector<int> vec3(vec2);

	disp_vec(vec3);

	std::cout << CYAN << "-TEST OF RANGE CONSTRUCTOR v4(v3.begin() v3.end())-" << NC << std::endl;
	ns::vector<int> vec4(vec3.begin(), vec3.end());

	disp_vec(vec4);

	std::cout << CYAN << "-TEST OF OPERATOR= -" << NC << std::endl;
	std::cout << PURPLE << "\nv5(3, 42)\n" << NC;
	ns::vector<int> vec5(3, 42);

	disp_vec(vec5);
	std::cout << PURPLE << "v5 = v3\n" << NC;
	vec5 = vec3;
	disp_vec(vec5);
	std::cout << YELLOW <<"----CONSTRUCTOR FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void capacity_test()
{
	std::cout << YELLOW <<"----CAPACITY FUNCTION TEST BEGIN----" << NC << std::endl << std::endl;
	{
		ns::vector<char> vec1(4,'q');
		std::cout << "ns::vector<char> vec1(4,'q') created." << std::endl;

		std::cout << CYAN << "-TEST OF SIZE|CAPACITY|MAX_SIZE-" << NC << std::endl;
		std::cout << "Max_Size of vec1:  " << vec1.max_size() << std::endl;
		disp_info(vec1);

		ns::vector<std::string> vec2(4,"std_string");
		std::cout << "Max_Size of vec2:  " << vec2.max_size() << std::endl;
		disp_info(vec2);

		ns::vector<int> vec3(4,100);
		std::cout << "Max_Size of vec3:  " << vec2.max_size() << std::endl;
		disp_info(vec3);

		ns::vector<float> vec4(4, 42.24);
		std::cout << "Max_Size of vec4:  " << vec2.max_size() << std::endl;
		disp_info(vec4);

		ns::vector<double> vec5(4, 24.42222222);
		std::cout << "Max_Size of vec5:  " << vec2.max_size() << std::endl;
		disp_info(vec5);

		ns::vector< ns::pair<char, int> > vec6(4, ns::make_pair< char, int >('a' , 42));
		std::cout << "Max_Size of vec6:  " << vec2.max_size() << std::endl;
		disp_info(vec6);

		std::cout << CYAN << "-TEST OF RESIZE-" << NC << std::endl;
		disp_vec(vec1);

		std::cout << YELLOW << "vec1.resize(6,'@')" << std::endl << NC;
		vec1.resize(6, '@');
		disp_vec(vec1);

		std::cout << YELLOW << "vec1.resize(7,'{')" << std::endl << NC;
		vec1.resize(7, '{');
		disp_vec(vec1);

		std::cout << YELLOW << "vec1.resize(12,'a')" << std::endl << NC;
		vec1.resize(12, 'a');
		disp_vec(vec1);

		std::cout << YELLOW << "vec1.resize(3,'4')" << std::endl << NC;
		vec1.resize(3, '4');
		disp_vec(vec1);

		std::cout << CYAN << "-TEST OF EMPTY-" << NC << std::endl;
		disp_vec(vec1);
		std::cout << "Is vec1 empty?  : " << vec1.empty() << std::endl;
		std::cout << std::endl << "Clear Vectors" << std::endl << std::endl;
		vec1.clear();
		disp_vec(vec1);
		std::cout << "Is vec1 empty?  : " << vec1.empty() << std::endl;
	}
	{
		std::cout << CYAN << "-TEST OF RESERVE-" << NC << std::endl;

		std::cout << "ns::vector<int> vec1 created." << std::endl;
		ns::vector<int>::size_type capacity;
		ns::vector<int>::size_type capacity_tmp;

		ns::vector<int> vec1;
		capacity = vec1.capacity();
		std::cout << "making vec1:\n";
		for (int i = 0; i < 100; ++i)
		{
			vec1.push_back(i);
			if (capacity != vec1.capacity())
			{
				capacity_tmp = capacity;
				capacity = vec1.capacity();
				std::cout<< "At i = " << i << " capacity vec1 changed: " << capacity_tmp << " -> " << capacity << '\n';
			}
		}
		std::cout << std::endl;
		std::cout << "ns::vector<int> vec created." << std::endl;
		ns::vector<int> vec2;
		capacity = vec2.capacity();
		vec2.reserve(100);	 // this is the only difference with vec1 above
		std::cout << "making vec2 grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			vec2.push_back(i);
			if (capacity != vec2.capacity())
			{
				capacity_tmp = capacity;
				capacity = vec2.capacity();
				std::cout << "At i = " << i << " capacity vec2 changed: " << capacity_tmp << " -> " << capacity << '\n';
			}
		}
	}
	std::cout << YELLOW <<"----CAPACITY FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void element_access_test()
{
	std::cout << YELLOW <<"----ELEMENT ACCESS FUNCTION TEST START----" << NC << std::endl << std::endl;

	std::cout << "ns::vector<int> vec created. And filled with random integer" << std::endl;
	ns::vector<int> vec;
	int random;

	for (size_t i = 0; i < 10; i++)
	{
		random = rand() % 100;
		vec.push_back(random);
	}
	disp_vec(vec);

	std::cout << CYAN << "-TEST OF OPERATOR[ ]-" << NC << std::endl;

	std::cout << "vec[3]			= " << vec[3] << '\n';
	std::cout << "vec[8]			= " << vec[8] << '\n';;
	std::cout << "vec[0]			= " << vec[0] << '\n';;
	std::cout << "vec[v.size() - 1]	= " << vec[vec.size() - 1] << '\n';

	std::cout << std::endl;

	std::cout << CYAN << "-TEST OF AT-" << NC << std::endl;

	std::cout << "vec.at(4)		= " << vec.at(4) << '\n';
	std::cout << "vec.at(7)		= " << vec.at(7) << '\n';
	std::cout << "vec.at(0)		= " << vec.at(0) << '\n';
	std::cout << "vec.at(v.size() - 1)	= " << vec.at(vec.size() -1) << '\n';

	std::cout << std::endl;

	std::cout << CYAN << "-TEST OF FRONT & BACK-" << NC << std::endl;

	std::cout << "vec.front() = " << vec.front() << '\n';
	std::cout << "vec.back() =  " << vec.back() << '\n';

	std::cout << YELLOW <<"----ELEMENT ACCESS FUNCTION TEST END----" << NC << std::endl << std::endl;
}

void modifier_test()
{
	std::cout << YELLOW <<"----MODIFIER FUNCTION TEST START----" << NC << std::endl << std::endl;
	std::cout << "ns::vector<int> vec created." << std::endl;

	std::cout << CYAN << "-TEST OF PUSH_BACK, POP_BACK & CLEAR-" << NC << std::endl;
	{
		ns::vector<int> vec;
		int random;

		std::cout << PURPLE << "Push_Back 5 integer\n" << NC;
		for (size_t i = 0; i < 5; i++)
		{
			random = rand() % 100;
			vec.push_back(random);
			disp_vec(vec);
		}

		std::cout << PURPLE << "Pop_Back 4 time\n" << NC;
		for (size_t i = 0; i < 4; i++)
		{
			vec.pop_back();
			disp_vec(vec);
		}

		std::cout << PURPLE << "Clear vectors\n" << NC;
		vec.clear();
		disp_vec(vec);
	}
	std::cout << CYAN << "-TEST OF SWAP-" << NC << std::endl;
	{
		ns::vector<std::string> vec1(3,"Hello");	// three std::string with a value of "Hello"
		ns::vector<std::string> vec2(5,"World");	// five  std::string with a value of "World"

		std::cout << "2 Vectors created, vec1(3,\"Hello\") & vec2 (5,\"World\");\n";
		std::cout << PURPLE << "Before Swap\n" << NC;

		std::cout << "vec1 contains:";
		for (size_t i = 0; i < vec1.size(); i++)
			std::cout << ' ' << vec1[i];
		std::cout << '\n';
		disp_info(vec1);

		std::cout << "vec2 contains:";
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << ' ' << vec2[i];
		std::cout << '\n';
		disp_info(vec2);

		vec1.swap(vec2);

		std::cout << PURPLE << "After Swap\n" << NC;
		std::cout << "vec1 contains:";
		for (size_t i = 0; i < vec1.size(); i++)
			std::cout << ' ' << vec1[i];
		std::cout << '\n';
		disp_info(vec1);

		std::cout << "vec2 contains:";
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << ' ' << vec2[i];
		std::cout << '\n';
		disp_info(vec2);
	}
	std::cout << CYAN << "-TEST OF ASSIGN-" << NC << std::endl;
	{
		std::cout << "2 Vectors created, vec1(10, 48) & vec2(15, 13)\n\n";
		ns::vector<int> vec1 (10, 48);
		ns::vector<int> vec2 (15, 13);

		std::cout << "vec1 contains:";
		for (size_t i = 0; i < vec1.size(); i++)
			std::cout << ' ' << vec1[i];
		std::cout << '\n';
		disp_info(vec1);

		std::cout << "vec2 contains:";
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << ' ' << vec2[i];
		std::cout << '\n';
		disp_info(vec2);

		std::cout << YELLOW << "vec2.assign(vec1.begin() + 1 , vec1.begin() + 5) :\n";
		vec2.assign(vec1.begin() + 1 , vec1.begin() + 5);

		std::cout << "vec1.assign(5, 98) :\n\n" << NC;
		vec1.assign(5, 98);

		std::cout << "vec1 contains:";
		for (size_t i = 0; i < vec1.size(); i++)
			std::cout << ' ' << vec1[i];
		std::cout << '\n';
		disp_info(vec1);

		std::cout << "vec2 contains:";
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << ' ' << vec2[i];
		std::cout << '\n';
		disp_info(vec2);
	}
	std::cout << CYAN << "-TEST OF ERASE-" << NC << std::endl;
	{
		ns::vector<int> vec;

		for (size_t i = 0; i < 15; i++)
			vec.push_back(i);

		disp_vec(vec);
		// 1st
		std::cout << PURPLE << "v.erase(v.begin())\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.begin())) << std::endl;
		disp_vec(vec);

		std::cout << PURPLE << "v.erase(v.end() - 2)\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.end() - 2)) << std::endl;
		disp_vec(vec);

		std::cout << PURPLE << "v.erase(v.begin() + 4)\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.begin() + 4)) << std::endl;
		disp_vec(vec);

		// 2nd
		std::cout << PURPLE << "v.erase(v.begin() + 10, v.end() - 1)\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.begin() + 10 , vec.end() - 1)) << std::endl;
		disp_vec(vec);

		std::cout << PURPLE << "v.erase(v.begin(), v.end() - 7)\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.begin() , vec.end() - 7)) << std::endl;
		disp_vec(vec);

		std::cout << PURPLE << "v.erase(v.end() - 3, v.end() - 2)\n" << NC;
		std::cout << "Return :  " << *(vec.erase(vec.end() - 3 , vec.end() - 2)) << std::endl;
		disp_vec(vec);
	}
	std::cout << CYAN << "-TEST OF INSERT-" << NC << std::endl;
	{
		std::cout << "For each test of insert we create vec(4, 100)\n\n";
		std::cout << BLUE << "INSERT SINGLE ELEMENT\n" << NC;
		{
			ns::vector<int> vec(4, 100);

			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin() + 2, 200)\n" << NC;
			std::cout << "Return :  " << *(vec.insert(vec.begin() + 2, 200)) << std::endl;
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin() + 5, 42))\n" << NC;
			std::cout << "Return :  " << *(vec.insert(vec.begin() + 5, 42)) << std::endl;
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin(),8))\n" << NC;
			std::cout << "Return :  " << *(vec.insert(vec.begin(), 8)) << std::endl;
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.end() - 1, 79))\n" << NC;
			std::cout << "Return :  " << *(vec.insert(vec.end() - 1, 79)) << std::endl;
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.end() - 2, 25))\n" << NC;
			std::cout << "Return :  " << *(vec.insert(vec.end() - 2, 25)) << std::endl;
			disp_vec(vec);
		}
		std::cout << BLUE << "INSERT FILL ELEMENT\n" << NC;
		{
			ns::vector<int> vec(4, 100);

			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin() + 2, 4, 200)\n" << NC;
			vec.insert(vec.begin() + 2, 5, 200);
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin() + 5, 5, 42))\n" << NC;
			vec.insert(vec.begin() + 5, 5, 42);
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.begin(), 2, 8))\n" << NC;
			vec.insert(vec.begin(), 2, 8);
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.end() - 1, 1, 79))\n" << NC;
			vec.insert(vec.end() - 1, 1, 79);
			disp_vec(vec);

			std::cout << PURPLE << "v.insert(v.end(),3, 25))\n" << NC;
			vec.insert(vec.end(), 3, 25);
			disp_vec(vec);

		}
		std::cout << BLUE << "INSERT RANGE ELEMENT\n" << NC;
		{
			ns::vector<int> vec1(4, 100);
			ns::vector<int> vec2;

			for (size_t i = 0; i < 15; i++)
				vec2.push_back(i);
			disp_vec(vec1);

			std::cout << PURPLE << "vec1.insert(vec1.begin() + 1, vec2.begin() + 3, vec2.end() - 3)\n" << NC;
			vec1.insert(vec1.begin() + 1, vec2.begin() + 3, vec2.end() - 3);
			disp_vec(vec1);

			std::cout << PURPLE << "vec1.insert(vec1.end(), vec1.begin(), vec1.end())\n" << NC;
			vec1.insert(vec1.end(), vec1.begin(), vec1.end());

			disp_vec(vec1);
		}
	}
	std::cout << YELLOW <<"----MODIFIER FUNCTION TEST END----" << NC << std::endl << std::endl;
}


void allocator_test()
{
	ns::vector<int> vec1;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = vec1.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) vec1.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) vec1.get_allocator().destroy(&p[i]);
	vec1.get_allocator().deallocate(p,5);
}

void test_iterator()
{
	std::cout << YELLOW << "----TEST ITERATOR BEGIN----\n" << NC;
	ns::vector<int> vec1;
	ns::vector<int> vec2 (vec1);
	int random;

	for (size_t i = 0; i < 15; i++)
	{
		random = rand() % 100;
		vec1.push_back(random);
	}

	for (ns::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
		std::cout << *it << "  ";
	std::cout << "\n\n";
	std::cout << CYAN << "vec1.begin() = " << NC << *vec1.begin() << NC << std::endl;
	std::cout << CYAN << "--vec1.end() = " << NC << *--vec1.end() << NC << std::endl;
	std::cout << CYAN << "vec1.rbegin() = " << NC << *vec1.rbegin() << NC << std::endl;
	std::cout << CYAN << "--vec1.rend() = " << NC << *--vec1.rend() << NC << std::endl << std::endl;

	ns::vector<int>::const_iterator cit1 = vec1.begin();
	ns::vector<int>::const_iterator cit2 = vec2.begin();
	ns::vector<int>::iterator it1 = vec1.begin();
	ns::vector<int>::iterator it2 = vec2.begin();

	std::cout << CYAN << "it_V1 == it_V2 : " << NC << (it1 == it2) << '\n';
	std::cout << CYAN << "it_V1 != it_V2 : " << NC << (it1 != it2) << '\n';
	std::cout << CYAN << "it_V1 < it_V2  : " << NC << (it1 < it2) << '\n';
	std::cout << CYAN << "it_V1 > it_V2  : " << NC << (it1 > it2) << '\n';
	std::cout << CYAN << "it_V1 <= it_V2 : " << NC << (it1 <= it2) << '\n';
	std::cout << CYAN << "it_V1 >= it_V2 : " << NC << (it1 >= it2) << "\n\n";

	std::cout << CYAN << "cit_V1 == cit_V2 : " << NC << (cit1 == cit2) << '\n';
	std::cout << CYAN << "cit_V1 != cit_V2 : " << NC << (cit1 != cit2) << '\n';
	std::cout << CYAN << "cit_V1 < cit_V2  : " << NC << (cit1 < cit2) << '\n';
	std::cout << CYAN << "cit_V1 > cit_V2  : " << NC << (cit1 > cit2) << '\n';
	std::cout << CYAN << "cit_V1 <= cit_V2 : " << NC << (cit1 <= cit2) << '\n';
	std::cout << CYAN << "cit_V1 >= cit_V2 : " << NC << (cit1 >= cit2) << "\n\n";

	std::cout << CYAN << "it_V1 == cit_V2 : " << NC << (it1 == cit2) << '\n';
	std::cout << CYAN << "it_V1 != cit_V2 : " << NC << (it1 != cit2) << '\n';
	std::cout << CYAN << "it_V1 < cit_V2  : " << NC << (it1 < cit2) << '\n';
	std::cout << CYAN << "it_V1 > cit_V2  : " << NC << (it1 > cit2) << '\n';
	std::cout << CYAN << "it_V1 <= cit_V2 : " << NC << (it1 <= cit2) << '\n';
	std::cout << CYAN << "it_V1 >= cit_V2 : " << NC << (it1 >= cit2) << "\n\n";

	std::cout << CYAN << "cit_V1 == it_V2 : " << NC << (cit1 == it2) << '\n';
	std::cout << CYAN << "cit_V1 != it_V2 : " << NC << (cit1 != it2) << '\n';
	std::cout << CYAN << "cit_V1 < it_V2  : " << NC << (cit1 < it2) << '\n';
	std::cout << CYAN << "cit_V1 > it_V2  : " << NC << (cit1 > it2) << '\n';
	std::cout << CYAN << "cit_V1 <= it_V2 : " << NC << (cit1 <= it2) << '\n';
	std::cout << CYAN << "cit_V1 >= it_V2 : " << NC << (cit1 >= it2) << "\n\n";

	std::cout << YELLOW << "----TEST ITERATOR END----\n\n" << NC;
}

void non_member_function_overloads_test()
{
	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD START----" << NC << std::endl << std::endl;
	ns::vector<int> vec1;
	ns::vector<int> vec2;

	for (size_t i = 0; i < 15; i++)
	{
		vec1.push_back(i); vec2.push_back(i);
	}

	disp_vec(vec1);
	disp_vec(vec2);

	std::cout << CYAN << "V1 == V2 : " << NC << (vec1 == vec2) << '\n';
	std::cout << CYAN << "V1 != V2 : " << NC << (vec1 != vec2) << '\n';
	std::cout << CYAN << "V1 < V2  : " << NC << (vec1 < vec2) << '\n';
	std::cout << CYAN << "V1 > V2  : " << NC << (vec1 > vec2) << '\n';
	std::cout << CYAN << "V1 <= V2 : " << NC << (vec1 <= vec2) << '\n';
	std::cout << CYAN << "V1 >= V2 : " << NC << (vec1 >= vec2) << "\n\n";

	std::cout << PURPLE << "vec1 pop_back()\n\n" << NC;
	vec1.pop_back();

	std::cout << CYAN << "V1 == V2 : " << NC << (vec1 == vec2) << '\n';
	std::cout << CYAN << "V1 != V2 : " << NC << (vec1 != vec2) << '\n';
	std::cout << CYAN << "V1 < V2  : " << NC << (vec1 < vec2) << '\n';
	std::cout << CYAN << "V1 > V2  : " << NC << (vec1 > vec2) << '\n';
	std::cout << CYAN << "V1 <= V2 : " << NC << (vec1 <= vec2) << '\n';
	std::cout << CYAN << "V1 >= V2 : " << NC << (vec1 >= vec2) << "\n\n";

	std::cout << CYAN << "- SWAP FUNCTION TEST -\n" << NC;

	ns::vector<int> vec1_tmp (vec1);

	std::cout << PURPLE << "vec2 push_back() 42 and 24\n" << NC;
	vec2.push_back(42); vec2.push_back(24);

	std::cout << PURPLE << "Before Swap\n" << NC;
	disp_vec(vec1);
	disp_vec(vec2);

	ns::swap(vec1, vec2);

	std::cout << PURPLE << "After Swap\n" << NC;

	disp_vec(vec1);
	disp_vec(vec2);
	if (vec2 == vec1_tmp){std::cout << GREEN << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ Swap is good\n" << NC;}

	std::cout << YELLOW <<"----NON MEMBER FUNCTION OVERLOAD END----" << NC << std::endl << std::endl;
}

void test_speed()
{
	ns::vector<int>vec(500000000, 42);
	ns::vector<int>vec2(vec);

	vec.clear();
	vec2.clear();
}

int main()
{
	std::cout << std::boolalpha; // Used to see bool results as tru instead of 1/0

	constructor_test();
	capacity_test();
	element_access_test();
	modifier_test();
	allocator_test();
	test_iterator();
	non_member_function_overloads_test();
	test_speed();

	return (0);
}
