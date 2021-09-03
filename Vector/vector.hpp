/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:46 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/03 19:18:54 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iomanip>

namespace ft
{
	// Use Namespace "ft" to differentiate from the STL Vector //
/*
	template<typename T>
		class Vector_iterator
		{
		public:
			typedef ptrdiff_t		difference_typer;
			typedef size_t 			size_type;
			typedef Vector_iterator	iterator;
			typedef T 				value_type;
			typedef T*				ptr;
			typedef T&				ref;

			Vector_iterator(void) : p(NULL) {}
			Vector_iterator(ptr x) : p(x) {}
			Vector_iterator(const iterator& copy) : p(copy.p) {}
			~Vector_iterator(void) {}

			iterator& operator==(const iterator& rhs) {this->p = rhs.p; return *this;}
			iterator& operator++() {p++; return *this;}
			iterator& operator--() {p--; return *this;}

			ptr operator*() const {return *p;}
			ref operator->() const {return p;}

			const ptr& base() const{ return p;}
		private:
			value_type *p;
		};

	template<typename T>
		class Vector_const_iterator
		{
		public:
			typedef ptrdiff_t		difference_typer;
			typedef size_t 			size_type;
			typedef Vector_const_iterator	 const_iterator;
			typedef T 				value_type;
			typedef T*				ptr;
			typedef T&				ref;

			Vector_const_iterator(void) : p(NULL) {}
			Vector_const_iterator(ptr x) : p(x) {}
			Vector_const_iterator(const const_iterator& copy) : p(copy.p) {}
			~Vector_const_iterator(void) {}

			iterator& operator==(const const_iterator& rhs) {this->p = rhs.p; return *this;}
			iterator& operator++() {p++; return *this;}
			iterator& operator--() {p--; return *this;}

			const ptr& base() const{ return p;}
		private:
			value_type *p;
		};
*/
	template<typename T>
		class Vector_iterator
		{

		public:
			typedef	size_t								size_type;

			typedef Vector_iterator<T>					iterator;
			typedef ptrdiff_t							difference_type;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;


			Vector_iterator(void) : p(NULL) {}
			Vector_iterator(pointer x) : p(x) {}
			Vector_iterator(const iterator& copy) : p(copy.p) {}
			iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
			iterator& operator++() { ++p; return *this;}
			iterator& operator+=(difference_type n) { p += n; return *this; }
			iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
			iterator& operator--() {--p;return *this;}
			iterator& operator-=(difference_type n) { p -= n; return *this; }
			iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
			iterator operator+(difference_type n) { return iterator(p + n); }
			iterator operator-(difference_type n) { return iterator(p - n); }
			reference operator[](difference_type n) { return p[n]; }
			bool operator==(const iterator& rhs) const { return p==rhs.p; }
			bool operator!=(const iterator& rhs) const { return p!=rhs.p; }
			bool operator<(const iterator& rhs) const { return p < rhs.p; }
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			~Vector_iterator(void) {}

			const pointer& base() const { return p; }

		private:
			value_type *p;
		};

	// Non-member function overloads
	// ==================================
	template<typename T>
		bool operator==(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() == rhs.base();
		}
	template<typename T>
		bool operator!=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() != rhs.base();
		}
	template<typename T>
		bool operator<(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() < rhs.base();
		}
	template<typename T>
		bool operator>(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() > rhs.base();
		}
	template<typename T>
		bool operator<=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() <= rhs.base();
		}
	template<typename T>
		bool operator>=(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() >= rhs.base();
		}
	template<typename T>
		typename Vector_iterator<T>::difference_type operator-(const Vector_iterator<T>& lhs, const Vector_iterator<T>& rhs)
		{
			return lhs.base() - rhs.base();
		}
	template<typename T>
		Vector_iterator<T> operator+(typename Vector_iterator<T>::difference_type n , const Vector_iterator<T>& rhs)
		{
			return rhs.base() + n;
		}

	// ==================================
	// Non-member function overloads END

	template<typename T>
		class Vector_const_iterator
		{

		public:
			typedef	size_t								size_type;
			typedef Vector_const_iterator<T>			const_iterator;
			typedef Vector_iterator<T>					iterator;

			typedef ptrdiff_t							difference_type;
			typedef std::bidirectional_iterator_tag		iterator_category;
			typedef	T									value_type;
			typedef const T*							pointer;
			typedef const T&							reference;

			Vector_const_iterator(void) : p(NULL) {}
			Vector_const_iterator(value_type *x) : p(x) {}
			Vector_const_iterator(const const_iterator& copy) : p(copy.p) {}
			Vector_const_iterator(const iterator& copy) : p(copy.p) {}
			const_iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
			const_iterator& operator=(const const_iterator& rhs) { this->p = rhs.p; return *this;}
			const_iterator& operator++() {++p; return *this;}
			const_iterator& operator+=(difference_type n) { p += n; return *this; }
			const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
			const_iterator operator+(difference_type n) { return const_iterator(p + n); }
			const_iterator operator-(difference_type n) { return const_iterator(p - n); }
			reference operator[](difference_type n) { return p[n]; }
			const_iterator& operator--() {--p; return *this;}
			const_iterator& operator-=(difference_type n) { p -= n; return *this; }
			const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
			bool operator==(const const_iterator& rhs) const {return p==rhs.p;}
			bool operator!=(const const_iterator& rhs) const {return p!=rhs.p;}
			reference operator*() const {return *p;}
			pointer operator->() const {return p;}
			~Vector_const_iterator(void) {}

			const pointer& base() const { return p; }

		private:
			const value_type *p;
		};

	// Non-member const_iterator function overloads
	// ==================================
	template<typename T>
		bool operator==(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() == rhs.base();
		}
	template<typename T>
		bool operator!=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() != rhs.base();
		}
	template<typename T>
		bool operator<(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() < rhs.base();
		}
	template<typename T>
		bool operator>(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() > rhs.base();
		}
	template<typename T>
		bool operator<=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() <= rhs.base();
		}
	template<typename T>
		bool operator>=(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() >= rhs.base();
		}
	template<typename T>
		typename Vector_const_iterator<T>::difference_type operator-(const Vector_const_iterator<T>& lhs, const Vector_const_iterator<T>& rhs)
		{
			return lhs.base() - rhs.base();
		}
	template<typename T>
		Vector_const_iterator<T> operator+(typename Vector_iterator<T>::difference_type n , const Vector_const_iterator<T>& rhs)
		{
			return rhs.base() + n;
		}



	template<typename T>
		class vector
		{
		public:
		// Types //
			typedef T										value_type;
			typedef T&										reference;
			typedef const T&								const_reference;
			typedef T*										pointer;
			typedef const T*								const_pointer;
			typedef std::allocator<T>						allocator_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;


			typedef Vector_iterator<T>						iterator;
			typedef Vector_const_iterator<T>		const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		// Member Fonctions //
			// Default constructor, Constructs an empty container, with no elements.
			vector(void) : _capacity(0), _size(0), _array(NULL) {
				std::cout << "default constructor" << std::endl;}

			// Fill constructor, Constructs a container with n elements. Each element is a copy of val.
			vector(size_type n, const value_type& val = value_type())
			: _capacity(n), _size(n), _array(static_cast<T *>(::operator new(sizeof(T) * n)))
			{
				std::cout << "fill constructor " << _capacity << " " << _size << std::endl;
				for (size_type i = 0; i < n; i++)
					new (static_cast<void *>(this->_array + i)) value_type(val);
			}

			/* Range constructor, Constructs a container with as many elements as the range [first,last),
					with each element constructed from its corresponding element in that range, in the same order.*/
		template <class InputIterator>
			vector (InputIterator first, typename std::enable_if< !std::is_integral< InputIterator >::value, InputIterator >::type last)
			{
				std::cout << "range constructor" << std::endl;
			}

			// Copy constructor, Constructs a container with a copy of each of the elements in x, in the same order.
			vector(const vector& copy)
			{
				std::cout << "copy constructor" << std::endl;

				this->_size = copy._size;
				this->_capacity = copy._capacity;
				this->_array = static_cast<T *>(::operator new(sizeof(T) * this->_capacity));

				for (size_type i = 0; i < _size; i++)
					new (static_cast<void *>(this->_array + i)) value_type(copy._array[i]);
			}

			~vector(void) {
				// std::cout << "Destructor\n";
			}
			// Iterators //
			iterator begin( void ) {return iterator(this->_array);}
			const_iterator cbegin( void ) const {return const_iterator(this->_array);}

			iterator end( void ) {return iterator(&this->_array[this->_size]);}
			const_iterator cend( void ) const {return const_iterator(&this->_array[this->_size]);}

			reverse_iterator rbegin( void ) { return reverse_iterator(this->end()); }
			const_reverse_iterator crbegin( void ) const { return const_reverse_iterator(this->end()); }

			reverse_iterator rend( void ) { return reverse_iterator(this->begin()); }
			const_reverse_iterator crend( void ) const { return const_reverse_iterator(this->begin()); }


			// Capacity //
			size_type size() const {return this->_size;}

			size_type max_size() const {
				allocator_type a;
				return a.max_size();}

			void resize (size_type n, value_type val = value_type())
			{
				if (n > this->_capacity)
				{
					T *tmp = realloc_array(n, val);
					// TODO Need clear and destroy this->_array !! //
					this->_array = tmp;
				}
				else if (n > this->_size)
				{
					for (size_t i = this->_size; i < n; i++)
					{
						new (static_cast<void *>(this->_array + i)) value_type(val);
						this->_size++;
					}
				}
				else
				{
					for (size_t i = n; i < this->_size; i++)
						this->_array[i].~value_type();
					this->_size = n;
				}
			}

			size_type capacity() {return this->_capacity;}

			bool empty() const{return (this->_size == 0 ? true : false);}

			// reserve

			vector& operator= (const vector& x)
			{

				return *this;
			}

			reference operator[] (size_type n) {return this->_array[n];}


			void display_vec()
			{
				for (size_type i = 0; i < _size; i++)
					std::cout << this->_array[i] << std::endl;
			}

		private:
			T*			_array;
			size_type	_size;
			size_type	_capacity;

			T* realloc_array(size_type n, const value_type val)
			{
				if (n <= this->_capacity * 2)
					this->_capacity = this->_size * 2;
				else
					this->_capacity = n;
				T *ret(static_cast<T *>(::operator new(sizeof(T) * this->_capacity)));
				for (size_t i = 0; i < n; i++)
				{
					if (i < this->_size)
						new (static_cast<void *>(ret + i)) value_type(this->_array[i]);
					else
					{
						new (static_cast<void *>(ret + i)) value_type(val);
						this->_size++;
					}
				}
				return ret;
			}
		};
}
#endif