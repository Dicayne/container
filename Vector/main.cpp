/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:07:36 by julnolle          #+#    #+#             */
/*   Updated: 2021/05/07 10:59:08 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "Fixed.hpp"
#include <vector>
#include <list>

#ifndef STD
# define NS ft
#else
# define NS std
#endif

template<typename T>
void displayVec(std::vector<T>& v)
{
	typename std::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(const std::vector<T>& v)
{
	typename std::vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(ft::vector<T>& v)
{
	typename ft::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
void displayVec(const ft::vector<T>& v)
{
	typename ft::vector<T>::const_iterator it = v.begin();
	while (it != v.end())
	{
		std::cout << *it << ' ';
		++it;
	}
	std::cout << std::endl;
}

int main(void)
{
	std::cout << "==== std Vector v = (1,2,3,4) ====" << std::endl;
	std::vector<int> v;
	for (int i = 1; i < 5; ++i)	{ v.push_back(i); }
	std::cout << "v: "; displayVec(v);

	std::cout << std::endl << "==== Default Constructor ====" << std::endl;
	
	NS::vector<int> v1;
	std::cout << std::boolalpha << "v1 empty : " << v1.empty() << std::endl;
	std::cout << "---- fill constructor (5, 42) ----" << std::endl;

	NS::vector<int> v5(5, 42);
	std::cout << "v5: "; displayVec(v5);

	std::cout << "---- Constructor by range (v.begin(), v.end()) ----" << std::endl;

	const NS::vector<int> v2(v.begin(), v.end());
	std::cout << "v2: "; displayVec(v2);

	std::cout << "---- Constructor by copy v3(v2) ----" << std::endl;
	NS::vector<int> v3(v2);
	std::cout << "v3: "; displayVec(v3);

	std::cout << "==== Assignation of v1 = v2 ====" << std::endl;
	std::cout << "---- v1 before assignation... ----" << std::endl;
	
	v1.push_back(42);
	v1.push_back(42);
	v1.push_back(42);
	v1.push_back(42);
	v1.push_back(42);

	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "---- Assignation... ----" << std::endl;
	v1 = v2;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	// std::cout << "v1 end: " << *(v1.end()) << std::endl;


	std::cout << std::endl << "==== ITERATORS ====" << std::endl;
	std::cout << "- Inc / Decrementations -------" << std::endl;
	NS::vector<int>::iterator it1 = v1.begin();
	std::cout << "v1: "; displayVec(v1);
	std::cout << "it1: " << *it1 << std::endl;
	++it1;
	std::cout << "++it1: " << *it1 << std::endl;
	it1 += 2;
	std::cout << "it1 += 2: " << *it1 << std::endl;
	it1--;
	std::cout << "it1--: " << *it1 << std::endl;
	--it1;
	std::cout << "--it1: " << *it1 << std::endl;
	it1++;
	std::cout << "it1++: " << *it1 << std::endl;
	it1 -= 2;
	std::cout << "it1 -= 2: " << *it1 << std::endl;
	
	std::cout << "- Binary Operations -------" << std::endl;
	NS::vector<int>::iterator it1bis = v1.begin();
	it1bis += 2;
	std::cout << "it1 - it1bis: " << it1 - it1bis << std::endl;
	std::cout << "it1bis - it1: " << it1bis - it1 << std::endl;
	std::cout << "it1 + 3: " << *(it1 + 3) << std::endl;
	std::cout << "it1: " << *it1 << std::endl;
	it1bis = it1 + 3;
	std::cout << "it1bis = it1 + 3: " << *it1bis << std::endl;
	std::cout << std::boolalpha << "it1bis < it1 : " << (it1bis < it1) << std::endl;
	std::cout << std::boolalpha << "it1bis > it1 : " << (it1bis > it1) << std::endl;
	it1bis -= 3;
	std::cout << "it1bis: " << *it1bis << std::endl;
	std::cout << std::boolalpha << "it1bis == it1 : " << (it1bis == it1) << std::endl;
	std::cout << "it1[0]: " << it1[0] << std::endl;
	std::cout << "it1[2]: " << it1[2] << std::endl;


	std::cout << std::endl << "==== v1 size ====" << std::endl;
	std::cout << "v1 size: " << v1.size() << std::endl;

	std::cout << std::endl << "==== vector max size ====" << std::endl;
	std::cout << "std::vector: " << v.max_size() << std::endl;
	std::cout << "ft::vector: " << v1.max_size() << std::endl;
	
	std::cout << std::endl << "==== operator [] & at() ====" << std::endl;
	std::cout << "- Non const -------" << std::endl;
	std::cout << "v1[2]   : " << v1[2] << std::endl;
	std::cout << "v1.at(2): " << v1.at(2) << std::endl;
	try {
		std::cout << "v1.at(5): " << v1.at(5) << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	std::cout << "v1.at(2)++: " << v1.at(2)++ << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "--v1.at(2): " << --v1.at(2) << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "----  const -------" << std::endl;
	std::cout << "v2[2]   : " << v2[2] << std::endl;
	std::cout << "v2.at(2): " << v2.at(2) << std::endl;
	

	std::cout << std::endl << "==== front() back() ====" << std::endl;
	std::cout << "- Non const -------" << std::endl;
	std::cout << "v1.front(): " << v1.front() << std::endl;
	std::cout << "v1.back()++: " << v1.back()++ << std::endl;
	std::cout << "v1.back(): " << v1.back() << std::endl;
	std::cout << "v1: "; displayVec(v1);

	std::cout << "----  const -------" << std::endl;
	std::cout << "v2.front(): " << v2.front() << std::endl;
	std::cout << "v2.back(): " << v2.back() << std::endl;

	std::cout << std::endl << "==== resize() ====" << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- resize(3) -------" << std::endl;
	v1.resize(3);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	// std::cout << "it end: " << *v1.end() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- resize(9) -------" << std::endl;
	v1.resize(9);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- resize(4) -------" << std::endl;
	v1.resize(4);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- resize(6, 42) -------" << std::endl;
	v1.resize(6, 42);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- resize(17, 50) -------" << std::endl;
	v1.resize(17, 50);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl << "==== reserve() ====" << std::endl;
	std::cout << "-- reserve(10) -------" << std::endl;
	v1.reserve(10);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "-- reserve(20) -------" << std::endl;
	v1.reserve(20);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;

	std::cout << std::endl << "==== assign() ====" << std::endl;
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v3 size: " << v3.size() << std::endl;
	std::cout << "v3 capacity: " << v3.capacity() << std::endl;
	std::cout << "-- v3.assign(v1) -------" << std::endl;
	v3.assign(v1.begin(), v1.end());
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v3 size: " << v3.size() << std::endl;
	std::cout << "v3 capacity: " << v3.capacity() << std::endl;
	
	std::cout << "-- v3.assign(v1 resized at 3) -------" << std::endl;
	v1.resize(3);
	v3.assign(v1.begin(), v1.end());
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v3 size: " << v3.size() << std::endl;
	std::cout << "v3 capacity: " << v3.capacity() << std::endl;

	std::cout << "-- v3.assign(5, 42) -------" << std::endl;
	v3.assign(5, 42);
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v3 size: " << v3.size() << std::endl;
	std::cout << "v3 capacity: " << v3.capacity() << std::endl;

	std::cout << std::endl << "==== push_back() ====" << std::endl;
	NS::vector<int> v4(v1.begin(), v1.end());
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	std::cout << "-- v4.push_back(10) -------" << std::endl;
	v4.push_back(10);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	std::cout << "-- v4.push_back() 2 more time -------" << std::endl;
	v4.push_back(11);
	v4.push_back(12);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	std::cout << "-- v4.push_back(13) 1 more time -------" << std::endl;
	v4.push_back(13);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;

	
	std::cout << std::endl << "==== pop_back() ====" << std::endl;
	std::cout << "-- v4.pop_back() -------" << std::endl;
	v4.pop_back();
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;

	std::cout << std::endl << "==== insert() ====" << std::endl;
	std::cout << "-- v4.insert() 42, 43 & 44 at begin, 2nd pos and end -------" << std::endl;
	NS::vector<int>::iterator pos;
	pos = v4.insert(v4.begin(), 42);
	std::cout << "insert ret (pos): " << *pos << std::endl;
	pos = v4.insert(++v4.begin(), 43);
	std::cout << "insert ret (pos): " << *pos << std::endl;
	pos = v4.insert(v4.end(), 44);
	std::cout << "insert ret (pos): " << *pos << std::endl;
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	
	std::cout << "-- v4.insert(n, xx) -------" << std::endl;
	v4.insert(v4.begin(), 2, 77);
	v4.insert(v4.end(), 4, 99);
	v4.insert(++v4.begin(), 5, 88);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	
	std::cout << "-- v4.insert(list range) -------" << std::endl;
	std::cout << "v1: "; displayVec(v1);
	// v4.insert(v4.begin(), v1.begin(), v1.end());
	// v4.insert(++v4.begin(), v1.begin(), v1.end());
	
	std::list<int> lst(3, 55);
	std::list<int>::iterator lstb = lst.begin(); // to test InputIterator
	std::list<int>::iterator lste = lst.end(); // to test InputIterator

	v4.insert(v4.end(), lstb, lste);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	
	std::cout << std::endl << "==== erase() ====" << std::endl;
	std::cout << "-- v4.erase(++begin) -------" << std::endl;
	v4.erase(++v4.begin());
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	std::cout << "-- v4.erase(first, last) -------" << std::endl;
	NS::vector<int>::iterator it4 = v4.begin();
	NS::vector<int>::iterator it4_cpy(it4 + 3);
	v4.erase(++it4, it4_cpy);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;


	std::cout << std::endl << "==== SWAP ====" << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;
	std::cout << "-- v1.swap(v4) -------" << std::endl;
	v1.swap(v4);
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v1 size: " << v1.size() << std::endl;
	std::cout << "v1 capacity: " << v1.capacity() << std::endl;
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v4 size: " << v4.size() << std::endl;
	std::cout << "v4 capacity: " << v4.capacity() << std::endl;

	std::cout << std::endl << "==== OPERATORS ====" << std::endl;
	std::cout << "v1: "; displayVec(v1);
	std::cout << "v2: "; displayVec(v2);
	v3.assign(v2.begin(), v2.end());
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v4: "; displayVec(v4);
	
	std::cout << std::boolalpha << "v2 == v3: " << (v2 == v3) << std::endl;
	std::cout << std::boolalpha << "v2 == v4: " << (v2 == v4) << std::endl;
	std::cout << std::boolalpha << "v1 == v2: " << (v1 == v2) << std::endl;
	std::cout << std::boolalpha << "v4 < v2: " << (v4 < v2) << std::endl;
	std::cout << std::boolalpha << "v2 > v4: " << (v2 > v4) << std::endl;

	std::cout << "v1: "; displayVec(v1);
	std::cout << "v2: "; displayVec(v2);
	std::cout << "v3: "; displayVec(v3);
	std::cout << "v4: "; displayVec(v4);
	std::cout << "v5: "; displayVec(v5);
	NS::vector<int> v6(v2.begin(), v2.end());

	std::cout << "v6: "; displayVec(v6);



/*	std::cout << std::endl << "==== FIXED ====" << std::endl;
	
	Fixed a(1);

	NS::vector<Fixed> v8(5, 42);
	// NS::vector<Fixed> v7(3, 21);


	v8.resize(4);
	std::cout << "v8: "; displayVec(v8);
	std::cout << "v8 size: " << v8.size() << std::endl;
	std::cout << "v8 capacity: " << v8.capacity() << std::endl;
	

	// std::cout << "v7: "; displayVec(v7);
	// std::cout << "v7 size: " << v7.size() << std::endl;
	// std::cout << "v7 capacity: " << v7.capacity() << std::endl;

	// v7.assign(v8.begin(), v8.end());

	v8.insert(v8.begin(), a);
	std::cout << "v8: "; displayVec(v8);
	std::cout << "v8 size: " << v8.size() << std::endl;
	std::cout << "v8 capacity: " << v8.capacity() << std::endl;*/

	// std::cout << "v7: "; displayVec(v7);
	// std::cout << "v7 size: " << v7.size() << std::endl;
	// std::cout << "v7 capacity: " << v7.capacity() << std::endl;
/*	NS::vector<int> test(3, 3);
	NS::vector<NS::vector<int> > self_assign;
	self_assign.assign(4, test);
*/	return 0;
}