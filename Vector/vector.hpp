/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:46 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/03 17:10:56 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../Utils/utils.hpp"
#include "iterator_vec.hpp"

namespace ft
{
	// Use Namespace "ft" to differentiate from the STL Vector //

	template < class T, class Alloc = std::allocator<T> >
		class vector
		{
		public:
		// Types //
			typedef T									value_type;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef Alloc								allocator_type;
			typedef size_t								size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef ft::vec_iterator<T>					iterator;
			typedef ft::vec_const_iterator<T>			const_iterator;
			typedef ft::vec_reverse_iterator<T>			reverse_iterator;
			typedef ft::vec_const_reverse_iterator<T>	const_reverse_iterator;

		private:
			T*				_array;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;

			T* realloc_array(size_type n, const value_type val)
			{
				if (n <= this->_size * 2)
					this->_capacity = this->_capacity * 2;
				else
					this->_capacity = n;

				T *ret = this->_alloc.allocate(sizeof (T) * n);
				for (size_t i = 0; i < n; i++)
				{
					if (i < this->_size)
						this->_alloc.construct(&(ret[i]), this->_array[i]);
					else
						this->_alloc.construct(&(ret[i]), val);
				}
				return ret;
			}

		public:
																		// CONSTRUCTOR //

			// Explicit Specifies that a constructor is explicit, that is, it cannot be used for implicit conversions and copy-initialization.
			// Default constructor, Constructs an empty container, with no elements.
			explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _alloc(alloc){
				// std::cout << "Default constructor" << std::endl;
			}

			// Fill constructor, Constructs a container with n elements. Each element is a copy of val.
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(NULL), _size(n), _capacity(n), _alloc(alloc)
			{
				//std::cout << "Fill constructor " << _capacity << " " << _size << std::endl;
				this->_array = this->_alloc.allocate(sizeof (T) * n);
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(&(this->_array[i]), val);
			}

			/* Range constructor, Constructs a container with as many elements as the range [first,last),
					with each element constructed from its corresponding element in that range, in the same order.*/
		template <class InputIterator>
			vector (InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last, const allocator_type& alloc = allocator_type())
				: _array(NULL), _size(0), _capacity(0), _alloc(alloc)
			{
				// std::cout << "Range constructor" << std::endl;
				InputIterator tmp = first;
				while (tmp != last)
				{
					this->_capacity++;
					tmp++;
				}
				this->_array = this->_alloc.allocate(sizeof(T) * this->_capacity);
				for (InputIterator it = first; it != last; it++)
				{
					this->_alloc.construct(&(this->_array[this->_size]), *it);
					this->_size++;
				}
			}

			// Copy constructor, Constructs a container with a copy of each of the elements in x, in the same order.
			vector(const vector& copy) : _array(NULL), _size(0), _capacity(0), _alloc(copy._alloc)
			{
				// std::cout << "Copy constructor" << std::endl;
				*this = copy;
			}

			~vector(void)
			{
				this->clear();
				this->_alloc.deallocate(this->_array, this->_capacity);
				// std::cout << "Destructor\n";
			}

			vector& operator= (const vector& x)
			{
				// std::cout << "Operator=\n";
				if (this->_array != NULL)
				{
					this->clear();
					this->_alloc.deallocate(this->_array, this->_capacity);
					this->_size = 0;
					this->_capacity = 0;
				}
				if (x._array != NULL)
				{
					this->_size = x._size;
					this->_capacity = x._capacity;
					this->_array = this->_alloc.allocate(sizeof(T) * this->_capacity);
					for (size_type i = 0; i < _size; i++)
						this->_alloc.construct(&(this->_array[i]) ,x._array[i]);
				}
				return *this;
			}

																		// ITERATORS //
			iterator begin( void ) {return iterator(this->_array);}
			const_iterator begin( void ) const {return const_iterator(this->_array);}

			iterator end( void ) {return iterator(&this->_array[this->_size]);}
			const_iterator end( void ) const {return const_iterator(&this->_array[this->_size]);}

			reverse_iterator rbegin( void ) { return reverse_iterator(--this->end()); }
			const_reverse_iterator rbegin( void ) const { return const_reverse_iterator(--this->end()); }

			reverse_iterator rend( void ) { return reverse_iterator(--this->begin()); }
			const_reverse_iterator rend( void ) const { return const_reverse_iterator(--this->begin()); }


																		// CAPACITY //

			size_type size() const {return this->_size;} // Return size.

			size_type max_size() const // max_size() -> Return maximum size.
			{
				allocator_type a;
				return a.max_size();
			}

			void resize (size_type n, value_type val = value_type()) // Change size.
			{
				if (n > this->_capacity)
				{
					T *tmp = realloc_array(n, val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&(this->_array[i]));
					this->_alloc.deallocate(this->_array, this->_capacity);
					this->_array = tmp;
					this->_size = n;
				}
				else if (n > this->_size)
				{
					for (size_t i = this->_size; i < n; i++)
					{
						this->_alloc.construct(&(this->_array[i]), val);
						this->_size++;
					}
				}
				else
				{
					for (size_t i = n; i < this->_size; i++)
						this->_alloc.destroy(&(this->_array[i]));
					this->_size = n;
				}
			}

			size_type capacity() const {return this->_capacity;} // Return size of allocated storage capacity.

			bool empty() const{return (this->_size == 0 ? true : false);} // Test whether vector is empty.

			void reserve (size_type n)		// Request a change in capacity.
			{
				if (n > this->max_size())
					throw std::length_error("n exceeds max_size()");
				else if (n > this->_capacity)
				{
					T *tmp = this->_alloc.allocate(sizeof(T) * n);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(&(tmp[i]), this->_array[i]);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&(this->_array[i]));
					this->_alloc.deallocate(this->_array, this->_capacity);
					this->_array = tmp;
					this->_capacity = n;
				}
			}

																		// ELEMENTS ACCESS //

			reference operator[] (size_type n) {return this->_array[n];}				//Returns a reference to the element at position n in the vector container.
			const_reference operator[] (size_type n) const {return this->_array[n];}


			reference at (size_type n)	// Same as operator[], but at() throw out_of_range exeption if n >= vector::size()
			{
				if (n >= this->_size)
					throw std::out_of_range("");
				return this->_array[n];
			}
			const_reference at (size_type n) const
			{
				if (n >= this->_size)
					throw std::out_of_range("");
				return this->_array[n];
			}

			reference front() {return this->_array[0];}								// Returns a reference to the first element in the vector.
			const_reference front() const {return this->_array[0];}


			reference back() {return this->_array[this->_size - 1];}				// Returns a reference to the last element in the vector.
			const_reference back() const {return this->_array[this->_size - 1];}


																		// MODIFIERS //


		template <class InputIterator>	// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			void assign (InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last)
			{
				InputIterator tmp = first;
				size_type sz = 0;
				while (tmp != last)
				{
					sz++;
					tmp++;
				}
				if (this->_array != NULL)
					this->clear();
				if (this->_capacity < sz)
					this->_capacity = sz;
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = this->_alloc.allocate(sizeof(T) * sz);
				this->_size = sz;
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&(this->_array[i]), *first);
					first++;
				}
			}

			void assign (size_type n, const value_type& val)
			{
				if (this->_array != NULL)
					this->clear();
				if (this->_capacity < n)
					this->_capacity = n;
				this->_alloc.deallocate(this->_array, this->_capacity);
				this->_array = this->_alloc.allocate(sizeof(T) * n);
				this->_size = n;
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&(this->_array[i]), val);
			}

			void push_back (const value_type& val) // Adds a new element at the end of the vector, after its current last element.
			{
				if (this->_size == this->capacity())
				{
					T* tmp = realloc_array(this->_size + 1, val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&(this->_array[i]));
					this->_alloc.deallocate(this->_array, this->_capacity);
					this->_array = tmp;
				}
				else
					this->_alloc.construct(&(this->_array[this->_size]), val);
				this->_size++;
			}

			void pop_back() // Removes the last element in the vector, effectively reducing the container size by one.
			{
				this->_alloc.destroy(&(this->_array[this->_size - 1]));
				this->_size--;
			}

			iterator insert (iterator position, const value_type& val) // Insert one elements // The vector is extended by inserting new elements before the element at the specified position.
			{
				size_t pos = 0;
				for (iterator it = this->begin(); it != position; it++)
					pos++;
				this->push_back(val);
				iterator pos_ret = this->begin();
				for (size_t i = 0; i < pos; i++)
					pos_ret++;
				iterator it_tmp = this->end();

				while (it_tmp != pos_ret)
				{
					*it_tmp = *(it_tmp - 1);
					it_tmp--;
				}
				*pos_ret = val;
				return (pos_ret);
			}

			void insert (iterator position, size_type n, const value_type& val) // Insert fill elements
			{
				size_t i = 0;
				size_t pos = 0;

				for (iterator it = this->begin(); it != position; it++)
					pos++;

				if (n + this->_size > this->_capacity)
				{
					if (n + this->_size <= this->_size * 2)
						this->reserve(this->_capacity * 2);
					else
						this->reserve(n + this->_size);
				}
				iterator pos_ret = this->begin();
				for (size_t i = 0; i < pos; i++)
					pos_ret++;

				while (i < n)
				{
					pos_ret = this->insert(pos_ret, val);
					i++;
				}
			}

		template <class InputIterator>
			void insert (iterator position, InputIterator first, typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type last) // Insert range elements
			{
				size_type pos_position = 0;
				size_type n = 0;
				vector tmp(first, last);

				for (InputIterator it(first); it != last; it++)
					n++;
				for (iterator it = this->begin(); it != position; it++)
					pos_position++;

				if (n + this->_size > this->_capacity)
				{
					if (n + this->_size <= this->_size * 2)
						this->reserve(this->_capacity * 2);
					else
						this->reserve(n + this->_size);
				}
				iterator pos_ret = this->begin();
				for (size_t i = 0; i < pos_position; i++)
					pos_ret++;

				for (size_t i = 0; i < n; i++)
				{
					pos_ret = this->insert(pos_ret, tmp[i]);
					pos_ret++;
				}
			}

			iterator erase (iterator position) // Removes from the vector either a single element (position) or a range of elements ([first,last)).
			{
				iterator ret = position;
				iterator tmp;

				while (position + 1 != this->end())
				{
					tmp = position + 1;
					this->_alloc.destroy(&(*position));
					this->_alloc.construct(&(*position), *tmp);
					position++;
				}
				this->pop_back();
				return (ret);
			}

			iterator erase (iterator first, iterator last)
			{
				iterator ret = first;
				iterator tmp;

				if (last != this->end())
				{
					while (last != this->end())
					{
						tmp = last;
						// @@@@@@@@@ ASKIP DOUBLE FREE AVEC CA ! @@@@@@@@@ //
						// this->_alloc.destroy(&(*first));
						this->_alloc.construct(&(*first), *tmp);
						last++;
						first++;
					}
				}
				while(first != this->end())
					this->pop_back();
				return (ret);
			}

			void swap (vector& x) // Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
			{
				T* tmp_array = this->_array;
				size_type	tmp_size = this->_size;
				size_type	tmp_capacity = this->_capacity;

				this->_array = x._array;
				this->_size = x._size;
				this->_capacity = x._capacity;

				x._array = tmp_array;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}

			void clear() // Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			{
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&(this->_array[i]));
				this->_size = 0;
			}

																		// ALLOCATOR //
			allocator_type get_allocator() const
			{
				allocator_type ret(this->_alloc);
				return (ret);
			}
		};

	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (lhs.size() == rhs.size())
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			return (false);
		}

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs == rhs);
		}

	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		}

	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		}

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		}

	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)	{x.swap(y);}

}
#endif
