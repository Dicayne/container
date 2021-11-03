/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:28:14 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/03 17:00:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

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
			struct Tree_node*	parent;

			// For max_size, don't know why
			int a;
			int b;
		};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map_iterator
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

				Node 		*_root;
				Node 		*_last;
				key_compare _comp;

				Node* find_start_node(Node *root)
				{
					while (root->parent != NULL)
						root = root->parent;
					return (root);
				}

				Node* find_min_node(Node *root)
				{
					while (root->left != root->left->left && root->left != this->_last)
						root = root->left;
					return (root);
				}

				Node* find_max_node(Node *root)
				{
					while (root->right != root->right->right && root->right != this->_last)
						root = root->right;
					return (root);
				}

			public :

				map_iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _root(ptr), _last(end), _comp(comp)
				{ }

				map_iterator(const map_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }

				~map_iterator()
				{ }
				map_iterator& operator=(const map_iterator& assign)
				{
					if (this == &assign)
						return *this;
					_root = assign._root;
					_last = assign._last;
					_comp = assign._comp;
					return *this;
				}
				reference operator*() const
				{	return (_root->value);	}

				pointer operator->() const
				{	return &(_root->value);	}

				bool operator==(const map_iterator &__x) const
				{	return _root == __x._root;	}

				bool operator!=(const map_iterator &__x) const
				{	return _root != __x._root;	}

				Node *get_root() const {return (this->_root);}
				Node *get_last() const {return (this->_last);}
				key_compare get_comp() const {return (this->_comp);}

				map_iterator &operator++()
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_iterator operator++(int)
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_iterator &operator--()
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
						{
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
						}
					}
					return (*this);
				}

				map_iterator operator--(int)
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
					}
					return (*this);
				}
		};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map_const_iterator
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
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef map_iterator<Key, T>								iterator;

				Node 		*_root;
				Node 		*_last;
				key_compare _comp;

				Node* find_start_node(Node *root)
				{
					while (root->parent != NULL)
						root = root->parent;
					return (root);
				}

				Node* find_min_node(Node *root)
				{
					while (root->left != root->left->left && root->left != this->_last)
						root = root->left;
					return (root);
				}

				Node* find_max_node(Node *root)
				{
					while (root->right != root->right->right && root->right != this->_last)
						root = root->right;
					return (root);
				}

			public :

				map_const_iterator(Node *root = 0, Node *last = 0, key_compare comp = Compare()) : _root(root), _last(last), _comp(comp)
				{ }
				map_const_iterator(const map_const_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				map_const_iterator(const iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				~map_const_iterator()
				{ }
				map_const_iterator& operator=(const map_const_iterator& assign)
				{
					if (this == &assign)
						return *this;
					_root = assign._root;
					_last = assign._last;
					_comp = assign._comp;
					return *this;
				}
				const_reference operator*() const
				{	return (_root->value);	}
				const_pointer operator->() const
				{	return &(_root->value);	}
				bool operator==(const map_const_iterator &__x) const
				{	return _root == __x._root;	}

				bool operator!=(const map_const_iterator &__x) const
				{	return _root != __x._root;	}

				Node *get_root() const {return (this->_root);}
				Node *get_last() const {return (this->_last);}
				key_compare get_comp() const {return (this->_comp);}

				map_const_iterator &operator++()
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_const_iterator operator++(int)
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_const_iterator &operator--()
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
						{
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
						}
					}
					return (*this);
				}

				map_const_iterator operator--(int)
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
					}
					return (*this);
				}
		};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ // REVERSE
			template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map_reverse_iterator
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

				typedef map_iterator<Key, T>								iterator;

				Node 		*_root;
				Node 		*_last;
				key_compare _comp;

				Node* find_start_node(Node *root)
				{
					while (root->parent != NULL)
						root = root->parent;
					return (root);
				}

				Node* find_min_node(Node *root)
				{
					while (root->left != root->left->left && root->left != this->_last)
						root = root->left;
					return (root);
				}

				Node* find_max_node(Node *root)
				{
					while (root->right != root->right->right && root->right != this->_last)
						root = root->right;
					return (root);
				}

			public :

				map_reverse_iterator(Node *ptr = 0, Node *end = 0, key_compare comp = Compare()) : _root(ptr), _last(end), _comp(comp)
				{ }

				map_reverse_iterator(const map_reverse_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }

				map_reverse_iterator(const iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }

				~map_reverse_iterator()
				{ }
				map_reverse_iterator& operator=(const map_reverse_iterator& assign)
				{
					if (this == &assign)
						return *this;
					_root = assign._root;
					_last = assign._last;
					_comp = assign._comp;
					return *this;
				}
				reference operator*() const
				{	return (_root->value);	}

				pointer operator->() const
				{	return &(_root->value);	}

				bool operator==(const map_reverse_iterator &__x) const
				{	return _root == __x._root;	}

				bool operator!=(const map_reverse_iterator &__x) const
				{	return _root != __x._root;	}

				Node *get_root() const {return (this->_root);}
				Node *get_last() const {return (this->_last);}
				key_compare get_comp() const {return (this->_comp);}

				iterator base()
				{
					map_reverse_iterator cpy = *this;
					--cpy;
					return ((iterator(cpy._root, _last)));
				}

				map_reverse_iterator &operator++()
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
						{
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
						}
					}
					return (*this);
				}

				map_reverse_iterator operator++(int)
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_reverse_iterator &operator--()
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_reverse_iterator operator--(int)
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}
		};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
		class map_const_reverse_iterator
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
				typedef typename allocator_type::const_reference			const_reference;
				typedef typename allocator_type::const_pointer				const_pointer;
				typedef map_reverse_iterator<Key, T>							reverse_iterator;
				typedef map_const_iterator<Key, T>								const_iterator;
				typedef map_iterator<Key, T>									iterator;

				Node 		*_root;
				Node 		*_last;
				key_compare _comp;

				Node* find_start_node(Node *root)
				{
					while (root->parent != NULL)
						root = root->parent;
					return (root);
				}

				Node* find_min_node(Node *root)
				{
					while (root->left != root->left->left && root->left != this->_last)
						root = root->left;
					return (root);
				}

				Node* find_max_node(Node *root)
				{
					while (root->right != root->right->right && root->right != this->_last)
						root = root->right;
					return (root);
				}

			public :

				map_const_reverse_iterator(Node *root = 0, Node *last = 0, key_compare comp = Compare()) : _root(root), _last(last), _comp(comp)
				{ }
				map_const_reverse_iterator(const map_const_reverse_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				map_const_reverse_iterator(const reverse_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				map_const_reverse_iterator(const const_iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				map_const_reverse_iterator(const iterator &i) : _root(i.get_root()), _last(i.get_last()), _comp(i.get_comp())
				{ }
				~map_const_reverse_iterator()
				{ }
				map_const_reverse_iterator& operator=(const map_const_reverse_iterator& assign)
				{
					if (this == &assign)
						return *this;
					_root = assign._root;
					_last = assign._last;
					_comp = assign._comp;
					return *this;
				}
				const_reference operator*() const
				{	return (_root->value);	}
				const_pointer operator->() const
				{	return &(_root->value);	}
				bool operator==(const map_const_reverse_iterator &__x) const
				{	return _root == __x._root;	}

				bool operator!=(const map_const_reverse_iterator &__x) const
				{	return _root != __x._root;	}

				Node *get_root() const {return (this->_root);}
				Node *get_last() const {return (this->_last);}
				key_compare get_comp() const {return (this->_comp);}

				const_iterator base()
				{
					map_const_reverse_iterator cpy = *this;
					--cpy;
					return ((const_iterator(cpy._root, _last)));
				}

				map_const_reverse_iterator &operator++()
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
						{
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
						}
					}
					return (*this);
				}

				map_const_reverse_iterator operator++(int)
				{
					Node *start = find_start_node(this->_root);
					Node *min_val = find_min_node(start);
					Node *base_val = this->_root;

					if (this->_root == min_val)
					{
						this->_root = this->_root->left;
						return (*this);
					}
					if (this->_root->left != this->_last && this->_root != this->_last)
					{
						this->_root = this->_root->left;
						this->_root = find_max_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						if (this->_root != start && base_val != this->_last)
							while (!this->_comp(this->_root->value.first, base_val->value.first))
								this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_const_reverse_iterator &operator--()
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}

				map_const_reverse_iterator operator--(int)
				{
					Node *start = find_start_node(this->_root);
					Node *max_val = find_max_node(start);
					Node *base_val = this->_root;

					if (this->_root == max_val)
					{
						this->_root = this->_root->right;
						return (*this);
					}
					if (this->_root->right != this->_last && this->_root->right != this->_root->right->right)
					{
						this->_root = this->_root->right;
						this->_root = find_min_node(this->_root);
					}
					else
					{
						this->_root = this->_root->parent;
						while (this->_comp(this->_root->value.first, base_val->value.first))
							this->_root = this->_root->parent;
					}
					return (*this);
				}
		};
}

#endif
