/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:53 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/16 17:04:04 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../Utils/utils.hpp"
#include "iterator_map.hpp"
#include <map>

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map
		{
			public:
			// Types //
				typedef Key															key_type;
				typedef T															mapped_type;
				typedef ft::pair<const key_type, mapped_type>						value_type;
				typedef Compare														key_compare;
				typedef Alloc														allocator_type;
				typedef Tree_node<value_type>										Node;

				typedef typename allocator_type::reference							reference;
				typedef typename allocator_type::const_reference					const_reference;
				typedef typename allocator_type::pointer							pointer;
				typedef typename allocator_type::const_pointer						const_pointer;
				typedef std::ptrdiff_t												difference_type;
				typedef size_t														size_type;

				typedef typename ft::map_iterator<Key, T, Compare>					iterator;
				typedef typename ft::map_const_iterator<Key, T, Compare>			const_iterator;
				typedef typename ft::map_reverse_iterator<Key, T, Compare>			reverse_iterator;
				typedef typename ft::map_const_reverse_iterator<Key, T, Compare>	const_reverse_iterator;

				class value_compare : public std::binary_function<value_type, value_type, bool>
				{
					friend class map;

					protected:

						key_compare comp;

						value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

					public:

						typedef bool		result_type;
						typedef value_type  first_argument_type;
						typedef value_type  second_argument_type;

						bool operator()(const value_type& x, const value_type& y) const
						{
							return comp(x.first, y.first);
						}
				};

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

				void	display_all_p()
				{
					display_p(this->_root, 0);
				}

				void	display_p(Node *root, int space)
				{
					if (root == this->_last)
						return;
					space += 10;
					display_p(root->right, space);
					std::cout << std::endl;
					for (int i = 10; i < space; i++)
						std::cout << " ";
					if (root->parent == NULL)
						std::cout << "NULL\n";
					else
						std::cout <<root->parent->value.first << '[' << root->parent->value.second << ']'<< "\n";

					display_p(root->left, space);
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
					this->_size = x._size;
					this->_alloc = x._alloc;
					this->_comp = x._comp;
					this->_alloc_node = x._alloc_node;
					insert(x.begin(), x.end());
					return (*this);
				}

																		// ITERATORS //

				iterator begin( void )
				{
					if (this->_size > 0)
						return iterator(find_left_node(), this->_last, this->_comp);
					else
						return iterator(this->_last, this->_last, this->_comp);
				}

				const_iterator begin( void ) const
				{
					if (this->_size > 0)
						return iterator(find_left_node(), this->_last, this->_comp);
					else
						return iterator(this->_last, this->_last, this->_comp);
				}

				iterator end( void )
				{
					if (this->_size == 1)
						this->_last->parent = this->_root;
					if (this->_size > 0)
					{
						Node *tmp = find_right_node();
						tmp->right->parent = tmp;
						tmp->left->parent = tmp;
						return iterator(tmp->right, this->_last, this->_comp);
					}
					else
						return iterator(this->_last, this->_last, this->_comp);
				}

				const_iterator end( void ) const
				{
					if (this->_size == 1)
						this->_last->parent = this->_root;
					if (this->_size > 0)
					{
						Node *tmp = find_right_node();
						tmp->right->parent = tmp;
						tmp->left->parent = tmp;
						return iterator(tmp->right, this->_last, this->_comp);
					}
					else
						return iterator(this->_last, this->_last, this->_comp);
				}

				reverse_iterator rbegin( void ) { return reverse_iterator(this->end()); }
				const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(this->end()); }

				reverse_iterator rend( void )
				{
					this->_last->right = this->_root;
					this->_last->left = this->_root;
					return reverse_iterator(this->begin());
				}
				const_reverse_iterator rend( void ) const
				{
					this->_last->right = this->_root;
					this->_last->left = this->_root;
					return const_reverse_iterator(this->begin());
				}

																		// CAPACITY //

				bool empty() const { return (this->_size == 0 ? true : false); } // Test whether map is empty.
				size_type size() const { return this->_size; } // Return size.
				size_type max_size() const { return this->_alloc_node.max_size(); } // max_size() -> Return maximum size.

																		// ELEMENT ACCESS //
				mapped_type& operator[] (const key_type& k)
				{
					Node *tmp = find_node(this->_root, k);

					if (tmp != this->_last)
						return tmp->value.second;
					this->insert(ft::make_pair(k,mapped_type()));
					tmp = find_node(this->_root, k);
					return (tmp->value.second);
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
					update_last();
					return (ret);
				}

				iterator insert (iterator position, const value_type& val) // Insert Single Element with hint to accelerate search
				{
					if (this->_comp(position->first, val.first))
					{
						iterator next(position);
						++next;
						while (next != this->end() && next->first <= val.first)
						{
							++position;
							++next;
						}
					}
					else if (!this->_comp(position->first, val.first) && position->first != val.first)
					{
						iterator previous(position);
						--previous;
						while (previous != this->end() && previous->first >= val.first)
						{
							--position;
							--previous;
						}
					}
					if (position != this->end() && val.first == position->first)
						return position;
					return iterator(insert(val).first);
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
						reset_parent(this->_root, this->_root);
						this->_root->parent = NULL;
					}
					return (ret);
				}

				void erase (iterator first, iterator last)
				{
					while (first != last)
					{
						iterator tmp(first);
						first++;
						erase(tmp);
					}
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
				value_compare value_comp() const {value_compare vc(this->_comp); return (vc);}

																		// OPERATIONS //
				iterator find (const key_type& k) { return (iterator(find_node(this->_root, k), this->_last, this->_comp));}
				const_iterator find (const key_type& k) const { return (const_iterator(find_node(this->_root, k), this->_last, this->_comp));}

				size_type count (const key_type& k) const
				{
					if (find_node(this->_root, k) == this->_last)
						return (0);
					else
						return (1);
				}

				iterator lower_bound (const key_type& k)
				{
					key_type min = find_left_node()->value.first;
					key_type max = find_right_node()->value.first;

					if (find(k) != this->end())
						return (find(k));
					if (this->_size != 0)
					{
						if (this->_comp(k, min))
							return (this->begin());
						else if (this->_comp(k, max))
							return (find_close_node(k));
						else
							return (this->end());
					}
					else
						return (this->end());
				}
				const_iterator lower_bound (const key_type& k) const
				{
					key_type min = find_left_node()->value.first;
					key_type max = find_right_node()->value.first;

					if (find(k) != this->end())
						return (find(k));
					if (this->_size != 0)
					{
						if (this->_comp(k, min))
							return (this->begin());
						else if (this->_comp(k, max))
							return (find_close_node(k));
						else
							return (this->end());
					}
					else
						return (this->end());
				}

				iterator upper_bound (const key_type& k)
				{
					key_type min = find_left_node()->value.first;
					key_type max = find_right_node()->value.first;

					if (this->_size != 0)
					{
						if (find(k) != this->end())
							return (++find(k));
						else if (this->_comp(k, min))
							return (this->begin());
						else if (this->_comp(k, max))
							return (find_close_node(k));
						else
							return (this->end());
					}
					else
						return (this->end());
				}

				const_iterator upper_bound (const key_type& k) const
				{
					key_type min = find_left_node()->value.first;
					key_type max = find_right_node()->value.first;

					if (this->_size != 0)
					{
						if (find(k) != this->end())
							return (++find(k));
						else if (this->_comp(k, min))
							return (this->begin());
						else if (this->_comp(k, max))
							return (find_close_node(k));
						else
							return (this->end());
					}
					else
						return (this->end());
				}

				ft::pair<iterator,iterator> equal_range (const key_type& k)
				{
					ft::pair<iterator,iterator> ret;

					if (this->empty() == false)
					{
						ret.first = lower_bound(k);
						ret.second = upper_bound(k);
					}
					else
					{
						ret.first = this->end();
						ret.second = this->end();
					}
					return (ret);
				}

				ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
				{
					ft::pair<const_iterator,const_iterator> ret;

					if (this->empty() == false)
					{
						ret.first = lower_bound(k);
						ret.second = upper_bound(k);
					}
					else
					{
						ret.first = this->end();
						ret.second = this->end();
					}
					return (ret);
				}

				allocator_type get_allocator() const { return (this->_alloc);}
			private :
			////////////////// UTILS /////////////////////

				void update_last()
				{
					if (this->_root == NULL || this->_size == 0)
					{
						this->_last->parent = NULL;
						this->_last->left = NULL;
						this->_last->right = NULL;
						return ;
					}
					this->_last->parent = this->_root;
					this->_last->left = this->_root;
					this->_last->right = this->_root;
				}

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
						if (val == ret->value.first)
							break;
						if (this->_comp(val, ret->value.first))
							ret = ret->left;
						else
							ret = ret->right;
					}
					if (ret == this->_last)
						return (this->_last);
					return (ret);
				}

				Node *find_left_node() const
				{
					Node *ret = this->_root;
					if (ret != this->_last)
					{
						while (ret->left != this->_last)
							ret = ret->left;
					}
					return (ret);
				}

				Node *find_right_node() const
				{
					Node *ret = this->_root;
					if (ret != this->_last)
					{
						while (ret->right != this->_last)
							ret = ret->right;
					}
					return (ret);
				}

				Node *find_close_node(key_type val) const
				{
					const_iterator ret = this->begin();

					while (this->_comp(ret->first, val))
					{
						ret++;
					}
					return (ret.get_root());
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
							if (this->_comp(n->value.first, curent->value.first))
								curent = curent->left;
							else
								curent = curent->right;
						}
						if (this->_comp(n->value.first, previous->value.first))
						{
							previous->left = n;
							previous->left->parent = previous;
						}
						if (!this->_comp(n->value.first, previous->value.first))
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
					value_compare comp = this->value_comp();

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
							if (comp(tmp->value, curent->value))
								curent = curent->left;
							else
								curent = curent->right;
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

				void reset_parent(Node *root, Node *parent)
				{
					if (root == this->_last)
						return;
					reset_parent(root->right, root);
					if (root->parent != NULL)
					{
						if (root->parent != parent)
							root->parent = parent;
					}
					reset_parent(root->left, root);
				}
		};
		/////////// NON MEMBER FUNCTION ///////////////
	template <class Key, class T, class Compare, class Alloc>
		bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			if (lhs.size() == rhs.size())
			{
				typename map<Key, T, Compare, Alloc>::const_iterator lit(lhs.begin());
				typename map<Key, T, Compare, Alloc>::const_iterator rit(rhs.begin());
				while (lit != lhs.end())
				{
					if (*lit != *rit)
						return false;
					++lit;
					++rit;
				}
				return true;
			}
			return false;
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			return !(lhs == rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			typename map<Key, T, Compare, Alloc>::const_iterator lit = lhs.begin();
			typename map<Key, T, Compare, Alloc>::const_iterator rit = rhs.begin();

			while (lit != lhs.end())
			{
				if (rit == rhs.end() || *rit < *lit)
					return false;
				else if (*lit < *rit)
					return true;
				++lit;
				++rit;
			}
			return rit != rhs.end();
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			return !(rhs < lhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			return rhs < lhs;
		}

	template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
		{
			return !(lhs < rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
		{
			x.swap(y);
		}
}
#endif
