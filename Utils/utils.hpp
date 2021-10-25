/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:04:46 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/25 17:39:37 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
#include <iomanip>
#include <stdexcept>

namespace ft
{
	// Trait class that identifies whether T is an integral type.
	template <typename T>
	struct is_integral
	{ static const bool value = false; };

	template <>
	struct is_integral<bool>
	{ static const bool value = true; };

	// template <>
	// struct is_integral<char16_t>
	// { static const bool value = true; };

	// template <>
	// struct is_integral<char32_t>
	// { static const bool value = true; };

	template <>
	struct is_integral<wchar_t>
	{ static const bool value = true; };

	template <>
	struct is_integral<signed char>
	{ static const bool value = true; };

	template <>
	struct is_integral<short int>
	{ static const bool value = true; };

	template <>
	struct is_integral<int>
	{ static const bool value = true; };

	template <>
	struct is_integral<long int>
	{ static const bool value = true; };

	template <>
	struct is_integral<long long int>
	{ static const bool value = true; };

	template <>
	struct is_integral<unsigned char>
	{ static const bool value = true; };

	template <>
	struct is_integral<unsigned short int>
	{ static const bool value = true; };

	template <>
	struct is_integral<unsigned int>
	{ static const bool value = true; };

	template <>
	struct is_integral<unsigned long int>
	{ static const bool value = true; };

	template <>
	struct is_integral<unsigned long long int>
	{ static const bool value = true; };

	// The type T is enabled as member type enable_if::type if Cond is true.
	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match.
	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	// This class couples together a pair of values, which may be of different types (T1 and T2). The individual values can be accessed through its public members first and second
	template <class T1, class T2>
		struct pair
		{
			T1 first;
			T2 second;

			pair() : first(), second() {}

		template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

			pair (const T1& a, const T2& b) : first(a), second(b) {}

			pair& operator= (const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;

				return *this;
			}
		};

	template <class T1,class T2>
		pair<T1,T2> make_pair (T1 x, T2 y) {return (pair<T1,T2>(x,y));}

	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first==rhs.first && lhs.second==rhs.second;}

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return !(lhs==rhs);}

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);}

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return !(rhs<lhs);}

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return rhs<lhs;}

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {return !(lhs<rhs);}
}

#endif
