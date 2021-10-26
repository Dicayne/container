/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:14 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/26 19:13:44 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include "map.hpp"

namespace ft
{
	template<class T> /* While T is ft::pair<const Key, T> */
		struct	Tree_node
		{
			T					value;
			struct Tree_node*	left;
			struct Tree_node*	right;
		};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class iterator
		{
			private :

				typedef Key													key_type;
				typedef T													mapped_type;
				typedef Compare												key_compare;
				typedef Alloc												allocator_type;
				typedef ft::pair<const key_type, mapped_type>				value_type;
				typedef Tree_node<value_type>								Node;

				typedef std::bidirectional_iterator_tag 					iterator_category;

				typedef typename std::ptrdiff_t 							difference_type;
				typedef typename allocator_type::reference					reference;
				typedef typename allocator_type::pointer					pointer;

				Node 		*_ptr;
				Node 		*_end;
				key_compare _comp;

			public :

				iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _ptr(ptr), _end(end), _comp(comp)
				{ }
				iterator(const iterator &it) : _ptr(it._ptr), _end(it._end), _comp(it._comp)
				{}
				~iterator()
				{ }
				iterator& operator=(const iterator& assign)
				{
					if (this == &assign)
						return *this;
					_ptr = assign._ptr;
					_end = assign._end;
					_comp = assign._comp;
					return *this;
				}
				reference operator*() const
				{	return (_ptr->value);	}

				pointer operator->() const
				{	return &(_ptr->value);	}

				bool operator==(const iterator &__x) const
				{	return _ptr == __x._ptr;	}

				bool operator!=(const iterator &__x) const
				{	return _ptr != __x._ptr;	}

				// iterator &operator++()
				// {
				// 	if (_ptr == _end)
				// 		return *this;
				// 	if (_ptr->right != NULL)
				// 	{
				// 		if (_ptr->right->left == NULL || _ptr->right == _end)
				// 			_ptr = _ptr->right;
				// 		else
				// 			_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
				// 	}
				// 	else if (_ptr->parent != NULL)
				// 	{
				// 		Node *og = _ptr;
				// 		_ptr = _ptr->parent;
				// 		while (_comp(og->value.first, _ptr->value.first) == false)
				// 			_ptr = _ptr->parent;
				// 	}
				// 	return *this;
				// }

				// iterator operator++(int)
				// {
				// 	if (_ptr == _end)
				// 		return *this;
				// 	iterator tmp = *this;
				// 	if (_ptr->right != NULL)
				// 	{
				// 		if (_ptr->right->left == NULL || _ptr->right == _end)
				// 			_ptr = _ptr->right;
				// 		else
				// 			_ptr = ft::map<Key, T, Compare, Alloc>::getleftmostnode(_ptr->right, _end);
				// 	}
				// 	else if (_ptr->parent != NULL && _ptr->parent != _end)
				// 	{
				// 		Node *og = _ptr;
				// 		_ptr = _ptr->parent;
				// 		while (_comp(og->value.first, _ptr->value.first) == false)
				// 			_ptr = _ptr->parent;
				// 	}
				// 	return tmp;
				// }

				// iterator &operator--()
				// {
				// 	if (_ptr == _end)
				// 		_ptr = _end->right;
				// 	else if (_ptr == _end->left)
				// 		_ptr = _end;
				// 	else if (_ptr->left != NULL)
				// 	{
				// 		if (_ptr->left->right == NULL)
				// 			_ptr = _ptr->left;
				// 		else
				// 			_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
				// 	}
				// 	else if (_ptr->parent != NULL)
				// 	{
				// 		Node *og = _ptr;
				// 		_ptr = _ptr->parent;
				// 		while (_comp(_ptr->value.first, og->value.first) == false)
				// 			_ptr = _ptr->parent;
				// 	}
				// 	return *this;
				// }
				// iterator operator--(int)
				// {
				// 	iterator tmp = *this;
				// 	if (_ptr == _end)
				// 		_ptr = _end->right;
				// 	else if (_ptr == _end->left)
				// 		_ptr = _end;
				// 	else if (_ptr->left != NULL)
				// 	{
				// 		if (_ptr->left->right == NULL)
				// 			_ptr = _ptr->left;
				// 		else
				// 			_ptr = ft::map<Key, T, Compare, Alloc>::getrightmostnode(_ptr->left, _end);
				// 	}
				// 	else if (_ptr->parent != NULL)
				// 	{
				// 		Node *og = _ptr;
				// 		_ptr = _ptr->parent;
				// 		while (_comp(_ptr->value.first, og->value.first) == false)
				// 			_ptr = _ptr->parent;
				// 	}
				// 	return tmp;
				// }
		};

}

#endif
