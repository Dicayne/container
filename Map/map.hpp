/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:53 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/27 19:51:28 by vmoreau          ###   ########.fr       */
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
				typedef std::less<value_type>								value_compare;
				typedef Alloc												allocator_type;
				typedef Tree_node<value_type>								Node;

				typedef typename allocator_type::reference					reference;
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::pointer					pointer;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef std::ptrdiff_t										difference_type;
				typedef size_t												size_type;

				typedef typename ft::iterator<Key, T>						iterator;
				typedef typename ft::const_iterator<Key, T>					const_iterator;
				typedef typename std::map<Key, T>::reverse_iterator			reverse_iterator;
				typedef typename std::map<Key, T>::const_reverse_iterator	const_reverse_iterator;

			private:

				Node					*_root;
				Node					*_last;
				size_type				_size;
				allocator_type			_alloc;
				key_compare				_comp;
				std::allocator< Node > 	_alloc_node;

			public:

				void display()
				{
					display(this->_root);
				}
																		// CONSTRUCTOR //
				// Empty container constructor (default constructor) Constructs an empty container, with no elements
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(NULL), _size(0), _alloc(alloc), _comp(comp)
				{
					// std::cout << "Empty Constructor Call\n";
					this->_last = create_node();
					this->_root = this->_last;
					this->_root->left = this->_last;
					this->_root->right = this->_last;
				}

				/* Range constructor
					Constructs a container with as many elements as the range [first,last], with each element constructed from its corresponding element in that range.*/
			template <class InputIterator>
				map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					 : _root(NULL), _size(0), _alloc(alloc), _comp(comp)
				{
					// std::cout << "Range Constructor Call\n";
					this->_last = create_node();
					this->_root = this->_last;
					this->_root->left = this->_last;
					this->_root->right = this->_last;

					insert(first, last);
				}

				/* copy
					Constructs a container with a copy of each of the elements in x */
				map (const map& copy) : _root(NULL), _size(0), _alloc(copy._alloc)
				{
					// std::cout << "Copy Constructor Call\n";
					this->_last = create_node();
					this->_root = this->_last;
					this->_root->left = this->_last;
					this->_root->right = this->_last;
					*this = copy;
				}

				~map ()
				{
					// std::cout << "Destructor Call\n";
					if (this->empty() == false)
						clear();
					this->_alloc_node.deallocate(this->_last, 1);
				}

				map& operator= (const map& x)
				{
					// std::cout << "Operator= Call\n";
					if (empty() == false)
						clear();
					insert(x.begin(), x.end());
					this->_size = x._size;
					this->_alloc = x._alloc;
					this->_comp = x._comp;
					this->_alloc_node = x._alloc_node;
					return (*this);
				}

																		// ITERATORS //

				iterator begin( void ) {return iterator(find_lower_node(), this->_last);}
				const_iterator begin( void ) const {return const_iterator(find_lower_node(), this->_last);}

				iterator end( void )
				{
					Node *tmp = find_high_node();
					tmp->right->parent = tmp;
					tmp->left->parent = tmp;
					return iterator(tmp->right, this->_last);
				}

				const_iterator end( void ) const
				{
					Node *tmp = find_high_node();
					tmp->right->parent = tmp;
					tmp->left->parent = tmp;
					return const_iterator(tmp->right, this->_last);
				}

				reverse_iterator rbegin( void ) { return reverse_iterator(this->end()); }
				const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(this->end()); }

				reverse_iterator rend( void ) { return reverse_iterator(this->begin()); }
				const_reverse_iterator rend( void ) const { return const_reverse_iterator(this->begin()); }

																		// CAPACITY //

				bool empty() const {return (this->_size == 0 ? true : false);} // Test whether map is empty.
				size_type size() const {return this->_size;} // Return size.
				size_type max_size() const // max_size() -> Return maximum size.
				{
					return this->_alloc_node.max_size();
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

					Node *tmp = find_node(this->_root, val.first);
					if (tmp != this->_last)
						ret.second = false;
					else
					{
						ret.second = true;
						push(&this->_root, val);
						this->_size++;
					}
					ret.first = find(val.first);
					return (ret);
				}

				iterator insert (iterator position, const value_type& val) // Insert Single Element with hint to accelerate search
				{
					(void)position;
					return (insert(val).first);
				}

				template <class InputIterator>
				void insert (InputIterator first, InputIterator last) // Insert Range Element
				{
					while (first != last)
					{
						insert(*first);
						first++;
					}
				}

				void erase (iterator position)
				{
					erase(position->first);
				}

				size_type erase (const key_type& k)
				{
					Node *tmp = this->_root;
					size_type ret = 0;

					if (find_node(tmp, k) != this->_last)
					{
						erase_node(&this->_root, k);
						this->_size--;
						ret = 1;
					}
					return (ret);
				}

				void erase (iterator first, iterator last)
				{
					while (first != last)
						erase(first);
				}


				void swap (map& x)
				{
					Node					*tmp_root = this->_root;
					Node					*tmp_last = this->_last;
					size_type				tmp_size = this->_size;
					allocator_type			tmp_alloc = this->_alloc;
					key_compare				tmp_comp = this->_comp;
					std::allocator< Node > 	tmp_alloc_node = this->_alloc_node;

					this->_root = x._root;
					this->_last = x._last;
					this->_size = x._size;
					this->_alloc = x._alloc;
					this->_comp = x._comp;
					this->_alloc_node = x._alloc_node;

					x._root = tmp_root;
					x._last = tmp_last;
					x._size = tmp_size;
					x._alloc = tmp_alloc;
					x._comp = tmp_comp;
					x._alloc_node = tmp_alloc_node;
				}

				void clear()
				{
					Node *tmp = this->_root;
					while (tmp != this->_last)
						erase_node(&tmp, tmp->value.first);
					this->_root = this->_last;
					this->_size = 0;
				}

																		// OBSERVERS //

				key_compare key_comp() const {return (this->_comp);}
				value_compare value_comp() const {value_compare vc; return (vc);}

																		// OPERATIONS //
				iterator find (const key_type& k) { return (iterator(find_node(this->_root, k)));}
				const_iterator find (const key_type& k) const { return (const_iterator(find_node(this->_root, k)));}

				size_type count (const key_type& k) const
				{
					if (find_node(this->_root, k) == this->_last)
						return (0);
					else
						return (1);
				}

				// iterator lower_bound (const key_type& k) {}
				// const_iterator lower_bound (const key_type& k) const {}

				// iterator upper_bound (const key_type& k) {}
				// const_iterator upper_bound (const key_type& k) const {}

				// ft::pair<iterator,iterator> equal_range (const key_type& k) {}
				// ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {}
			private :
			////////////////// UTILS /////////////////////
				void	display_all(Node *root, int space)
				{
					if (root == this->_last)
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

				Node *find_node(Node *root, key_type val) const
				{
					Node *ret = root;
					while (ret != this->_last)
					{
						if (val < ret->value.first)
							ret = ret->left;
						else if (val > ret->value.first)
							ret = ret->right;
						else
							break;
					}
					if (ret == this->_last)
						return (this->_last);
					return (ret);
				}

				Node *find_lower_node() const
				{
					Node *ret = this->_root;
					if (ret != this->_last)
					{
						while (ret->left != this->_last)
							ret = ret->left;
					}
					return (ret);
				}

				Node *find_high_node() const
				{
					Node *ret = this->_root;
					if (ret != this->_last)
					{
						while (ret->right != this->_last)
							ret = ret->right;
					}
					return (ret);
				}

				void	place(Node *n, Node **tree)
				{
					Node *previous;
					Node *curent = *tree;

					if (*tree == this->_last)
						*tree = n;
					else
					{
						while (curent != this->_last)
						{
							previous = curent;
							if (n->value < curent->value)
								curent = curent->left;
							else if (n->value > curent->value)
								curent = curent->right;
						}
						if (n->value < previous->value)
						{
							previous->left = n;
							previous->left->parent = previous;
						}
						if (n->value > previous->value)
						{
							previous->right = n;
							previous->right->parent = previous;
						}
					}
				}

				Node	*create_node()
				{
					Node *ret = this->_alloc_node.allocate(1);

					ret->left = this->_last;
					ret->right = this->_last;
					ret->parent = NULL;

					return (ret);
				}

				void	push(Node **tree, value_type val)
				{
					Node *n = create_node();

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
						this->_alloc.destroy(&tmp->value);
						this->_alloc_node.deallocate(tmp, 1);
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
						this->_alloc.destroy(&tmp->value);
						this->_alloc_node.deallocate(tmp, 1);
					}
				}

		};
}
#endif
