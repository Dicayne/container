/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:04:46 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/09 19:14:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

# include <iostream>
# include <string>

namespace ft
{
	template <typename T>
	struct is_integral
	{ static const bool value = false; };

	template <>
	struct is_integral<bool>
	{ static const bool value = true; };

	template <>
	struct is_integral<char>
	{ static const bool value = true; };

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

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
}
#endif