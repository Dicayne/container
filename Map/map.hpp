/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:53 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/27 15:39:13 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../Utils/utils.hpp"

namespace ft
{
	template <	class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key,T> > >
		class map
		{
			public:
			// Types //
				typedef Key								key_type;
				typedef T								mapped_type;
				typedef ft::pair<const Key,T>			value_type;
				typedef Compare							key_compare;
				// typedef 								value_compare;
				typedef Alloc							allocator_type;
				typedef allocator_type::reference		reference;
				typedef allocator_type::const_reference	const_reference;
				typedef allocator_type::pointer			pointer;
				typedef std::ptrdiff_t					difference_type;
				typedef size_t							size_type;

				// typedef 								const_pointer;
				// typedef 								iterator;
				// typedef 								const_iterator;
				// typedef 								reverse_iterator;


		};
}
#endif
