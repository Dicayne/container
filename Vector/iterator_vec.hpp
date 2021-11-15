/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vec.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:05:32 by vmoreau           #+#    #+#             */
/*   Updated: 2021/11/09 21:11:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VEC_HPP
# define ITERATOR_VEC_HPP

namespace ft
{
	template< class T >
		class vec_iterator
		{
		public:
			typedef std::ptrdiff_t						difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef std::random_access_iterator_tag		iterator_category;

			value_type *p;

			vec_iterator(void) : p(NULL) {}
			vec_iterator(pointer ptr) : p(ptr) {}
			vec_iterator(vec_iterator const &it) : p(it.get_ptr()) {}
			~vec_iterator() {}

			value_type *get_ptr() const {return (this->p); }
			vec_iterator& operator=(const vec_iterator& rhs) { this->p = rhs.get_ptr(); return *this;}

			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[n];}

			vec_iterator& operator++() { ++p; return *this;}
			vec_iterator& operator--() {--p;return *this;}
			vec_iterator operator++(int) {vec_iterator tmp(*this); ++this->p; return tmp;}
			vec_iterator operator--(int) {vec_iterator tmp(*this); --this->p; return tmp;}

			vec_iterator operator+(difference_type n) const { return (vec_iterator(p + n)); }
			vec_iterator operator-(difference_type n) const { return (vec_iterator(p - n)); }

			vec_iterator& operator+=(difference_type n) { p += n; return *this; }
			vec_iterator& operator-=(difference_type n) { p -= n; return *this; }

			difference_type operator-(vec_iterator it) const { return (this->p - it.get_ptr()); }

			bool operator==(const vec_iterator& rhs) const { return this->p == rhs.get_ptr(); }
			bool operator!=(const vec_iterator& rhs) const { return this->p != rhs.get_ptr(); }
			bool operator<(const vec_iterator& rhs) const  { return this->p < rhs.get_ptr(); }
			bool operator<=(const vec_iterator& rhs) const { return this->p <= rhs.get_ptr(); }
			bool operator>(const vec_iterator& rhs) const  { return this->p > rhs.get_ptr(); }
			bool operator>=(const vec_iterator& rhs) const { return this->p >= rhs.get_ptr(); }
		};
		template< class T >
			vec_iterator< T > operator+(int nb, const vec_iterator< T >& it)
			{
				vec_iterator< T > newIt(it);
				return (newIt += nb);
			}

		template< class T >
			vec_iterator< T > operator-(int nb, const vec_iterator< T >& it)
			{
				vec_iterator< T > newIt(it);
				return (newIt -= nb);
			}

	template< class T >
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
			typedef std::random_access_iterator_tag		iterator_category;

			value_type *p;

			vec_const_iterator(void) : p(NULL) {}
			vec_const_iterator(pointer ptr) : p(ptr) {}
			vec_const_iterator(iterator const &it) : p(it.get_ptr()) {}
			~vec_const_iterator() {}

			vec_const_iterator& operator=(const vec_const_iterator& rhs) { this->p = rhs.get_ptr(); return *this;}
			value_type *get_ptr() const { return (this->p); }

			const_reference operator*() const { return *p; }
			const_pointer operator->() const { return p; }
			const_reference operator[](difference_type n) const {return p[n];}

			vec_const_iterator& operator++() { ++p; return *this;}
			vec_const_iterator& operator--() {--p;return *this;}
			vec_const_iterator operator++(int) {vec_const_iterator tmp(*this); ++this->p; return tmp;}
			vec_const_iterator operator--(int) {vec_const_iterator tmp(*this); --this->p; return tmp;}

			vec_const_iterator operator+(difference_type n) const {return (vec_const_iterator(p + n));}
			vec_const_iterator operator-(difference_type n) const {return (vec_const_iterator(p - n));}

			vec_const_iterator& operator+=(difference_type n) { p += n; return *this; }
			vec_const_iterator& operator-=(difference_type n) { p -= n; return *this; }

			difference_type operator-(vec_const_iterator it) const { return (this->p - it.get_ptr()); }

			bool operator==(const vec_const_iterator& rhs) const { return this->p == rhs.get_ptr(); }
			bool operator!=(const vec_const_iterator& rhs) const { return this->p != rhs.get_ptr(); }
			bool operator<(const vec_const_iterator& rhs) const  { return this->p < rhs.get_ptr(); }
			bool operator<=(const vec_const_iterator& rhs) const { return this->p <= rhs.get_ptr(); }
			bool operator>(const vec_const_iterator& rhs) const  { return this->p > rhs.get_ptr(); }
			bool operator>=(const vec_const_iterator& rhs) const { return this->p >= rhs.get_ptr(); }
		};
		template< class T >
			vec_const_iterator< T > operator+(int nb, const vec_const_iterator< T >& it)
			{
				vec_const_iterator< T > newIt(it);
				return (newIt += nb);
			}

		template< class T >
			vec_const_iterator< T > operator-(int nb, const vec_const_iterator< T >& it)
			{
				vec_const_iterator< T > newIt(it);
				return (newIt -= nb);
			}

		template< class T >
			bool operator==(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs) { return rhs.get_ptr() == lhs.get_ptr(); }
		template< class T >
			bool operator!=(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs) { return rhs.get_ptr() != lhs.get_ptr(); }
		template< class T >
			bool operator<(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs)  { return rhs.get_ptr() < lhs.get_ptr(); }
		template< class T >
			bool operator<=(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs) { return rhs.get_ptr() <= lhs.get_ptr(); }
		template< class T >
			bool operator>(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs)  { return rhs.get_ptr() > lhs.get_ptr(); }
		template< class T >
			bool operator>=(const vec_iterator<T>& rhs, const vec_const_iterator<T>& lhs) { return rhs.get_ptr() >= lhs.get_ptr(); }

	template< class T >
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
			typedef std::random_access_iterator_tag		iterator_category;

			value_type *p;

			vec_reverse_iterator(void) : p(NULL) {}
			vec_reverse_iterator(pointer ptr) : p(ptr) {}
			vec_reverse_iterator(iterator const &it) : p(it.get_ptr() - 1) {}
			~vec_reverse_iterator() {}

			value_type *get_ptr() const {return (this->p); }
			vec_reverse_iterator& operator=(const vec_reverse_iterator& rhs) { this->p = rhs.get_ptr(); return *this;}

			reference operator*() const { return *p; }
			pointer operator->() const { return p; }
			reference operator[](difference_type n) {return p[-n];}

			vec_reverse_iterator& operator++() { --p; return *this;}
			vec_reverse_iterator& operator--() {++p;return *this;}

			vec_reverse_iterator operator++(int) {vec_reverse_iterator tmp(*this); --this->p; return tmp;}
			vec_reverse_iterator operator--(int) {vec_reverse_iterator tmp(*this); ++this->p; return tmp;}

			iterator base() const { return iterator(p + 1); }
			difference_type operator-(vec_reverse_iterator it) const { return (it.get_ptr() - this->p); }

			vec_reverse_iterator operator+(difference_type n) { return (vec_reverse_iterator(p - n)); }
			vec_reverse_iterator operator-(difference_type n) { return (vec_reverse_iterator(p + n)); }

			vec_reverse_iterator& operator+=(difference_type n) { p -= n; return *this; }
			vec_reverse_iterator& operator-=(difference_type n) { p += n; return *this; }

			bool operator==(const vec_reverse_iterator& rhs) const { return this->p == rhs.get_ptr(); }
			bool operator!=(const vec_reverse_iterator& rhs) const { return this->p != rhs.get_ptr(); }
			bool operator<(const vec_reverse_iterator& rhs) const  { return this->p > rhs.get_ptr(); }
			bool operator<=(const vec_reverse_iterator& rhs) const { return this->p >= rhs.get_ptr(); }
			bool operator>(const vec_reverse_iterator& rhs) const  { return this->p < rhs.get_ptr(); }
			bool operator>=(const vec_reverse_iterator& rhs) const { return this->p <= rhs.get_ptr(); }
		};
		template< class T >
			vec_reverse_iterator< T > operator+(int nb, const vec_reverse_iterator< T >& it)
			{ return (vec_reverse_iterator< T >(it.p - nb)); }

		template< class T >
			vec_reverse_iterator< T > operator-(int nb, const vec_reverse_iterator< T >& it)
			{ return (vec_reverse_iterator< T >(it.p + nb)); }

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
			typedef std::random_access_iterator_tag		iterator_category;

			value_type *p;

			vec_const_reverse_iterator(void) : p(NULL) {}
			vec_const_reverse_iterator(pointer ptr) : p(ptr) {}
			vec_const_reverse_iterator(iterator it) : p(it.get_ptr() - 1) {}
			vec_const_reverse_iterator(const_iterator it) : p(it.get_ptr() - 1) {}
			vec_const_reverse_iterator(reverse_iterator it) : p(it.get_ptr()) {}
			~vec_const_reverse_iterator() {}

			vec_const_reverse_iterator& operator=(const vec_const_reverse_iterator& rhs) { this->p = rhs.get_ptr(); return *this;}
			value_type *get_ptr() const { return (this->p); }

			const_reference operator*() const { return *p; }
			const_pointer operator->() const { return p; }
			const_reference operator[](difference_type n) {return p[-n];}

			vec_const_reverse_iterator& operator++() { --p; return *this;}
			vec_const_reverse_iterator& operator--() {++p;return *this;}
			vec_const_reverse_iterator operator++(int) {vec_const_reverse_iterator tmp(*this); --this->p; return tmp;}
			vec_const_reverse_iterator operator--(int) {vec_const_reverse_iterator tmp(*this); ++this->p; return tmp;}

			const_iterator base() const { return const_iterator(p + 1); }
			difference_type operator-(vec_const_reverse_iterator it) const { return (it.get_ptr() - this->p); }

			vec_const_reverse_iterator operator+(difference_type n) const {return (vec_const_reverse_iterator(p - n));}
			vec_const_reverse_iterator operator-(difference_type n) const {return (vec_const_reverse_iterator(p + n));}

			vec_const_reverse_iterator operator+=(difference_type n) { p -= n; return *this; }
			vec_const_reverse_iterator operator-=(difference_type n) { p += n; return *this; }

			bool operator==(const vec_const_reverse_iterator& rhs) const { return this->p == rhs.get_ptr(); }
			bool operator!=(const vec_const_reverse_iterator& rhs) const { return this->p != rhs.get_ptr(); }
			bool operator<(const vec_const_reverse_iterator& rhs) const  { return this->p > rhs.get_ptr(); }
			bool operator<=(const vec_const_reverse_iterator& rhs) const { return this->p >= rhs.get_ptr(); }
			bool operator>(const vec_const_reverse_iterator& rhs) const  { return this->p < rhs.get_ptr(); }
			bool operator>=(const vec_const_reverse_iterator& rhs) const { return this->p <= rhs.get_ptr(); }
		};
		template< class T >
			vec_const_reverse_iterator< T > operator+(int nb, const vec_const_reverse_iterator< T >& it)
			{ return (vec_const_reverse_iterator< T >(it.p - nb)); }

		template< class T >
			vec_const_reverse_iterator< T > operator-(int nb, const vec_const_reverse_iterator< T >& it)
			{ return (vec_const_reverse_iterator< T >(it.p + nb)); }

		template< class T >
			bool operator==(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs) { return rhs.get_ptr() == lhs.get_ptr(); }
		template< class T >
			bool operator!=(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs) { return rhs.get_ptr() != lhs.get_ptr(); }
		template< class T >
			bool operator<(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs)  { return rhs.get_ptr() > lhs.get_ptr(); }
		template< class T >
			bool operator<=(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs) { return rhs.get_ptr() >= lhs.get_ptr(); }
		template< class T >
			bool operator>(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs)  { return rhs.get_ptr() < lhs.get_ptr(); }
		template< class T >
			bool operator>=(const vec_reverse_iterator<T>& rhs, const vec_const_reverse_iterator<T>& lhs) { return rhs.get_ptr() <= lhs.get_ptr(); }
}
#endif
