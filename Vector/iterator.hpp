/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:05:32 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/15 13:07:53 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template<class T >
		class iterator
		{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			value_type *p;

			iterator(void) : p(NULL) {}
			iterator(pointer ptr) : p(ptr) {}
			iterator(iterator const &x) : p(x.p) {}

			iterator& operator=(const iterator& rhs) { this->p = rhs.p; return *this;}
			iterator& operator++() { ++p; return *this;}
			iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
			iterator& operator--() {--p;return *this;}
			iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[n];}

			iterator operator+(difference_type n) {return (p + n);}
			iterator operator-(difference_type n) {return (p - n);}
			iterator operator+=(difference_type n) { p += n; return *this; }
			iterator operator-=(difference_type n) { p -= n; return *this; }
			friend iterator operator+(difference_type t, iterator n) {return (n + t);}
			friend iterator operator-(difference_type t, iterator n) {return (n - t);}
			friend iterator operator+=(difference_type t, iterator n) {return (n += t);}
			friend iterator operator-=(difference_type t, iterator n) {return (n -= t);}

			bool operator==(const iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const iterator& rhs) const { return p != rhs.p; }
			bool operator<(const iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const iterator& rhs) const { return p >= rhs.p; }
		};

	template<class T >
		class const_iterator
		{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			value_type *p;

			const_iterator(void) : p(NULL) {}
			const_iterator(pointer ptr) : p(ptr) {}
			const_iterator(iterator<T> x) : p(x.p) {}

			const_iterator& operator=(const const_iterator& rhs) { this->p = rhs.p; return *this;}
			const_iterator& operator++() { ++p; return *this;}
			const_iterator operator++(int) {const_iterator tmp(*this); operator++(); return tmp;}
			const_iterator& operator--() {--p;return *this;}
			const_iterator operator--(int) {const_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[n];}

			const_iterator operator+(difference_type n) {return (p + n);}
			const_iterator operator-(difference_type n) {return (p - n);}
			const_iterator operator+=(difference_type n) { p += n; return *this; }
			const_iterator operator-=(difference_type n) { p -= n; return *this; }
			friend const_iterator operator+(difference_type t, const_iterator n) {return (n + t);}
			friend const_iterator operator-(difference_type t, const_iterator n) {return (n - t);}
			friend const_iterator operator+=(difference_type t, const_iterator n) {return (n += t);}
			friend const_iterator operator-=(difference_type t, const_iterator n) {return (n -= t);}

			bool operator==(const const_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const const_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const const_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const const_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const const_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const const_iterator& rhs) const { return p >= rhs.p; }
		};

	template<class T >
		class reverse_iterator
		{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			value_type *p;

			reverse_iterator(void) : p(NULL) {}
			reverse_iterator(pointer ptr) : p(ptr) {}
			reverse_iterator(iterator<T> x) : p(x.p - 1) {}

			reverse_iterator& operator=(const reverse_iterator& rhs) { this->p = rhs.p; return *this;}
			reverse_iterator& operator++() { --p; return *this;}
			reverse_iterator operator++(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
			reverse_iterator& operator--() {++p;return *this;}
			reverse_iterator operator--(int) {reverse_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[-n];}

			reverse_iterator operator+(difference_type n) {return (p - n);}
			reverse_iterator operator-(difference_type n) {return (p + n);}
			reverse_iterator operator+=(difference_type n) { p -= n; return *this; }
			reverse_iterator operator-=(difference_type n) { p += n; return *this; }
			friend reverse_iterator operator+(difference_type t, reverse_iterator n) {return (n - t);}
			friend reverse_iterator operator-(difference_type t, reverse_iterator n) {return (n + t);}
			friend reverse_iterator operator+=(difference_type t, reverse_iterator n) {return (n -= t);}
			friend reverse_iterator operator-=(difference_type t, reverse_iterator n) {return (n += t);}

			bool operator==(const reverse_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const reverse_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const reverse_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const reverse_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const reverse_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const reverse_iterator& rhs) const { return p >= rhs.p; }
		};

	template< class T >
		class const_reverse_iterator
		{
		public:
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef const T*							const_pointer;
			typedef T&									reference;
			typedef const T&							const_reference;
			value_type *p;

			const_reverse_iterator(void) : p(NULL) {}
			const_reverse_iterator(pointer ptr) : p(ptr) {}
			const_reverse_iterator(iterator<T> x) : p(x.p - 1) {}

			const_reverse_iterator& operator=(const const_reverse_iterator& rhs) { this->p = rhs.p; return *this;}
			const_reverse_iterator& operator++() { --p; return *this;}
			const_reverse_iterator operator++(int) {const_reverse_iterator tmp(*this); operator++(); return tmp;}
			const_reverse_iterator& operator--() {++p;return *this;}
			const_reverse_iterator operator--(int) {const_reverse_iterator tmp(*this); operator--(); return tmp;}
			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[-n];}

			const_reverse_iterator operator+(difference_type n) {return (p - n);}
			const_reverse_iterator operator-(difference_type n) {return (p + n);}
			const_reverse_iterator operator+=(difference_type n) { p -= n; return *this; }
			const_reverse_iterator operator-=(difference_type n) { p += n; return *this; }
			friend const_reverse_iterator operator+(difference_type t, const_reverse_iterator n) {return (n - t);}
			friend const_reverse_iterator operator-(difference_type t, const_reverse_iterator n) {return (n + t);}
			friend const_reverse_iterator operator+=(difference_type t, const_reverse_iterator n) {return (n -= t);}
			friend const_reverse_iterator operator-=(difference_type t, const_reverse_iterator n) {return (n += t);}

			bool operator==(const const_reverse_iterator& rhs) const { return p == rhs.p; }
			bool operator!=(const const_reverse_iterator& rhs) const { return p != rhs.p; }
			bool operator<(const const_reverse_iterator& rhs) const { return p < rhs.p; }
			bool operator<=(const const_reverse_iterator& rhs) const { return p <= rhs.p; }
			bool operator>(const const_reverse_iterator& rhs) const { return p > rhs.p; }
			bool operator>=(const const_reverse_iterator& rhs) const { return p >= rhs.p; }
		};
}
#endif