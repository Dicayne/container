/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:14 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/25 17:48:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
namespace ft
{
	template<class T> /* While T is ft::pair<const Key, T> */
		struct	Tree_node
		{
			T					value;
			struct Tree_node*	left;
			struct Tree_node*	right;

			Tree_node() : value(T()), left(NULL), right(NULL) {}
			Tree_node(const T& val) : value(val), left(NULL), right(NULL) {}
		};
}

#endif
