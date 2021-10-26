/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:53 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/26 21:45:32 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../Utils/utils.hpp"
#include "iterator.hpp"
#include <map>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map
		{
			public:
			// Types //
				typedef Key													key_type;
				typedef T													mapped_type;
				typedef ft::pair<const key_type, mapped_type>				value_type;
				typedef Compare												key_compare;
				// typedef std::less<value_type>								value_compare;
				typedef Alloc												allocator_type;
				typedef Tree_node<value_type>								Node;

				typedef typename allocator_type::reference					reference;
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::pointer					pointer;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef std::ptrdiff_t										difference_type;
				typedef size_t												size_type;

				typedef typename ft::iterator<Key, T>								iterator;
				typedef typename std::map<Key, T>::const_iterator			const_iterator;
				typedef typename std::map<Key, T>::reverse_iterator			reverse_iterator;
				typedef typename std::map<Key, T>::const_reverse_iterator	const_reverse_iterator;

			private:

				Node			*_tree;
				size_type		_size;
				allocator_type	_alloc;
				key_compare		_comp;

				void	display_all(Node *root, int space)
				{
					if (root == NULL)
						return;
					space += 10;
					display_all(root->right, space);
					std::cout << std::endl;
					for (int i = 10; i < space; i++)
						std::cout << " ";
					std::cout <<root->value.first << '[' << root->value.second << ']'<< "\n";

					display_all(root->left, space);
				}

				void display(Node *tree)
				{
					std::cout << "------------------ DISPLAY -----------------\n";
					display_all(tree, 0);
					std::cout << "\n------------------ END -----------------\n\n";
				}

				Node *find_node(Node *root, key_type val)
				{
					Node *ret = root;

					while (ret)
					{
						if (val < ret->value.first)
							ret = ret->left;
						else if (val > ret->value.first)
							ret = ret->right;
						else
							break;
					}
					if (!ret)
						return (NULL);
					return (ret);
				}

				Node *find_lower_node()
				{
					Node *ret = this->_tree;
					if (ret != NULL)
					{
						while (ret->left != NULL)
							ret = ret->left;
					}
					return (ret);
				}

				Node *find_high_node()
				{
					Node *ret = this->_tree;
					if (ret != NULL)
					{
						while (ret->right != NULL)
							ret = ret->right;
					}
					return (ret);
				}

				void	place(Node *n, Node **tree)
				{
					Node *previous;
					Node *curent = *tree;

					if (!*tree)
						*tree = n;
					else
					{
						while (curent)
						{
							previous = curent;
							if (n->value < curent->value)
								curent = curent->left;
							else if (n->value > curent->value)
								curent = curent->right;
						}
						if (n->value < previous->value)
							previous->left = n;
						if (n->value > previous->value)
							previous->right = n;
					}
				}

				void	push(Node **tree, value_type val)
				{
					// Node *n;
					// n = this->_alloc.allocate(sizeof (Node));

					Node *n = new Node;
					n->left = NULL;
					n->right = NULL;
					this->_alloc.construct(&n->value, val);
					place(n, tree);
				}

				void erase_node(Node **tree, key_type val)
				{
					Node *curent = *tree;
					Node *tmp = find_node(*tree, val);

					if (!tmp)
						return;

					Node *left = tmp->left;
					Node *right = tmp->right;

					if (val == curent->value.first)
					{
						*tree = right;
						if (left)
							place(left, tree);
						delete (tmp);
					}
					else
					{
						while(curent != tmp)
						{
							if(curent->right == tmp || curent->left == tmp)
								break;
							if(tmp->value >= curent->value)
								curent = curent->right;
							else
								curent = curent->left;
						}

						if(curent->right == tmp)
							curent->right = right;
						else
							curent->left = right;
						if(left)
							place(left, tree);
						delete tmp;
					}
				}

			public:

				void display()
				{
					display(this->_tree);
				}
																		// CONSTRUCTOR //
				// Empty container constructor (default constructor) Constructs an empty container, with no elements
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(NULL), _size(0), _alloc(alloc), _comp(comp)
				{
					std::cout << "Empty Constructor Call\n";
				}

				/* Range constructor
					Constructs a container with as many elements as the range [first,last], with each element constructed from its corresponding element in that range.*/
			template <class InputIterator>
				map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					 : _tree(NULL), _size(0), _alloc(alloc), _comp(comp)
				{
					(void)first;
					(void)last;
					std::cout << "Range Constructor Call\n";
				}

				/* copy
					Constructs a container with a copy of each of the elements in x */
				map (const map& copy) : _tree(NULL), _size(0), _alloc(copy._alloc)
				{
					std::cout << "Copy Constructor Call\n";
					*this = copy;
				}

				~map ()
				{
					std::cout << "Destructor Call\n";
				}

				map& operator= (const map& x)
				{
					(void)x;
					std::cout << "Operator= Call\n";
				}

																		// ITERATORS //

				iterator begin( void ) {return iterator(find_lower_node());}
				const_iterator begin( void ) const {return const_iterator(find_lower_node());}

				iterator end( void ) {return iterator(find_high_node());}
				const_iterator end( void ) const {return const_iterator(find_high_node());}

				reverse_iterator rbegin( void ) { return reverse_iterator(this->end()); }
				const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(this->end()); }

				reverse_iterator rend( void ) { return reverse_iterator(this->begin()); }
				const_reverse_iterator rend( void ) const { return const_reverse_iterator(this->begin()); }

																		// CAPACITY //

				bool empty() const {return (this->_size == 0 ? true : false);} // Test whether map is empty.
				size_type size() const {return this->_size;} // Return size.
				size_type max_size() const // max_size() -> Return maximum size.
				{
					allocator_type a;
					return a.max_size();
				}

																		// ELEMENT ACCESS //
				mapped_type& operator[] (const key_type& k)
				{
					mapped_type &ret = (*((this->insert(make_pair(k,mapped_type()))).first)).second;
					return (ret);
				}

																		// MODIFIERS //

				ft::pair<iterator,bool> insert (const value_type& val) // Insert Single Element
				{
					ft::pair<iterator, bool> ret;
					Node *tmp = find_node(this->_tree, val.first);

					if (tmp)
					{
						std::cout << "Val " << val.first << " Find\n";
						ret.second = false;
					}
					else
					{
						std::cout << "Val " << val.first << " Not Find, then insert\n";
						ret.second = true;
						push(&this->_tree, val);
						this->_size++;
					}
					ret.first = find(val.first);
					return (ret);
				}

				iterator insert (iterator position, const value_type& val) // Insert Single Element with hint to accelerate search
				{
					std::cout << "HINT PASS\n";
					(void)position;
					return (insert(val).first);
				}

				// template <class InputIterator>
				// void insert (InputIterator first, InputIterator last) // Insert Range Element
				// {

				// }

				// void erase (iterator position)
				// {
				// 	erase_node(&this->_tree, );
				// }

				size_type erase (const key_type& k)
				{
					erase_node(&this->_tree, k);
					this->_size--;
					return (0);
				}

				// void erase (iterator first, iterator last)
				// {

				// }

				void clear()
				{
					Node *tmp = this->_tree;
					while (tmp)
						erase_node(&tmp, tmp->value.first);
					this->_tree = NULL;
				}
				iterator find (const key_type& k)
				{
					Node *tmp = find_node(this->_tree, k);

					// std::cout << tmp->value.first << "[" << tmp->value.second << "]\n";

					return (iterator(tmp));
				}


		};
}
#endif
