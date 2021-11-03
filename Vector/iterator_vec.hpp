/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vec.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:05:32 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/03 17:36:01 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VEC_HPP
# define ITERATOR_VEC_HPP

namespace ft
{
	template<class T >
		class vec_iterator
		{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			value_type *p;

			vec_iterator(void) : p(NULL) {}
			vec_iterator(pointer ptr) : p(ptr) {}

			vec_iterator& operator=(const vec_iterator& rhs) { this->p = rhs.p; return *this;}
			vec_iterator& operator++() { ++p; return *this;}
			vec_iterator operator++(int) {vec_iterator tmp(*this); operator++(); return tmp;}
			vec_iterator& operator--() {--p;return *this;}
			vec_iterator operator--(int) {vec_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[n];}

			vec_iterator operator+(difference_type n) {return (p + n);}
			vec_iterator operator-(difference_type n) {return (p - n);}
			vec_iterator operator+=(difference_type n) { p += n; return *this; }
			vec_iterator operator-=(difference_type n) { p -= n; return *this; }
			friend vec_iterator operator+(difference_type t, vec_iterator n) {return (n + t);}
			friend vec_iterator operator-(difference_type t, vec_iterator n) {return (n - t);}
			friend vec_iterator operator+=(difference_type t, vec_iterator n) {return (n += t);}
			friend vec_iterator operator-=(difference_type t, vec_iterator n) {return (n -= t);}

			bool operator==(const vec_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const vec_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const vec_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const vec_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const vec_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const vec_iterator& rhs) const { return p >= rhs.p; }
		};

	template<class T >
		class vec_const_iterator
		{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef vec_iterator< T >					iterator;
			value_type *p;

			vec_const_iterator(void) : p(NULL) {}
			vec_const_iterator(pointer ptr) : p(ptr) {}
			vec_const_iterator(iterator it) : p(it.p) {}
			vec_const_iterator& operator=(const vec_const_iterator& rhs) { this->p = rhs.p; return *this;}
			vec_const_iterator& operator++() { ++p; return *this;}
			vec_const_iterator operator++(int) {vec_const_iterator tmp(*this); operator++(); return tmp;}
			vec_const_iterator& operator--() {--p;return *this;}
			vec_const_iterator operator--(int) {vec_const_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[n];}

			vec_const_iterator operator+(difference_type n) {return (p + n);}
			vec_const_iterator operator-(difference_type n) {return (p - n);}
			vec_const_iterator operator+=(difference_type n) { p += n; return *this; }
			vec_const_iterator operator-=(difference_type n) { p -= n; return *this; }
			friend vec_const_iterator operator+(difference_type t, vec_const_iterator n) {return (n + t);}
			friend vec_const_iterator operator-(difference_type t, vec_const_iterator n) {return (n - t);}
			friend vec_const_iterator operator+=(difference_type t, vec_const_iterator n) {return (n += t);}
			friend vec_const_iterator operator-=(difference_type t, vec_const_iterator n) {return (n -= t);}

			bool operator==(const vec_const_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const vec_const_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const vec_const_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const vec_const_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const vec_const_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const vec_const_iterator& rhs) const { return p >= rhs.p; }
		};

	template<class T >
		class vec_reverse_iterator
		{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef vec_iterator< T >					iterator;
			value_type *p;

			vec_reverse_iterator(void) : p(NULL) {}
			vec_reverse_iterator(pointer ptr) : p(ptr) {}
			vec_reverse_iterator(iterator it) : p(it.p) {}

			vec_reverse_iterator& operator=(const vec_reverse_iterator& rhs) { this->p = rhs.p; return *this;}
			vec_reverse_iterator& operator++() { --p; return *this;}
			vec_reverse_iterator operator++(int) {vec_reverse_iterator tmp(*this); operator++(); return tmp;}
			vec_reverse_iterator& operator--() {++p;return *this;}
			vec_reverse_iterator operator--(int) {vec_reverse_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[-n];}
			iterator base() const { return iterator(p + 1); }

			vec_reverse_iterator operator+(difference_type n) {return (p - n);}
			vec_reverse_iterator operator-(difference_type n) {return (p + n);}
			vec_reverse_iterator operator+=(difference_type n) { p -= n; return *this; }
			vec_reverse_iterator operator-=(difference_type n) { p += n; return *this; }
			friend vec_reverse_iterator operator+(difference_type t, vec_reverse_iterator n) {return (n - t);}
			friend vec_reverse_iterator operator-(difference_type t, vec_reverse_iterator n) {return (n + t);}
			friend vec_reverse_iterator operator+=(difference_type t, vec_reverse_iterator n) {return (n -= t);}
			friend vec_reverse_iterator operator-=(difference_type t, vec_reverse_iterator n) {return (n += t);}

			bool operator==(const vec_reverse_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const vec_reverse_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const vec_reverse_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const vec_reverse_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const vec_reverse_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const vec_reverse_iterator& rhs) const { return p >= rhs.p; }
		};

	template< class T >
		class vec_const_reverse_iterator
		{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			typedef vec_iterator< T >					iterator;
			typedef vec_const_iterator< T >				const_iterator;
			typedef vec_reverse_iterator< T >			reverse_iterator;
			value_type *p;

			vec_const_reverse_iterator(void) : p(NULL) {}
			vec_const_reverse_iterator(pointer ptr) : p(ptr) {}
			vec_const_reverse_iterator(iterator it) : p(it.p) {}
			vec_const_reverse_iterator(const_iterator it) : p(it.p) {}
			vec_const_reverse_iterator(reverse_iterator it) : p(it.p) {}

			vec_const_reverse_iterator& operator=(const vec_const_reverse_iterator& rhs) { this->p = rhs.p; return *this;}
			vec_const_reverse_iterator& operator++() { --p; return *this;}
			vec_const_reverse_iterator operator++(int) {vec_const_reverse_iterator tmp(*this); operator++(); return tmp;}
			vec_const_reverse_iterator& operator--() {++p;return *this;}
			vec_const_reverse_iterator operator--(int) {vec_const_reverse_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[-n];}
			const_iterator base() const { return const_iterator(p + 1); }

			vec_const_reverse_iterator operator+(difference_type n) {return (p - n);}
			vec_const_reverse_iterator operator-(difference_type n) {return (p + n);}
			vec_const_reverse_iterator operator+=(difference_type n) { p -= n; return *this; }
			vec_const_reverse_iterator operator-=(difference_type n) { p += n; return *this; }
			friend vec_const_reverse_iterator operator+(difference_type t, vec_const_reverse_iterator n) {return (n - t);}
			friend vec_const_reverse_iterator operator-(difference_type t, vec_const_reverse_iterator n) {return (n + t);}
			friend vec_const_reverse_iterator operator+=(difference_type t, vec_const_reverse_iterator n) {return (n -= t);}
			friend vec_const_reverse_iterator operator-=(difference_type t, vec_const_reverse_iterator n) {return (n += t);}

			bool operator==(const vec_const_reverse_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const vec_const_reverse_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const vec_const_reverse_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const vec_const_reverse_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const vec_const_reverse_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const vec_const_reverse_iterator& rhs) const { return p >= rhs.p; }
		};
}
#endif
