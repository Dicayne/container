/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:51 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/28 18:23:54 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef Container							container_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::value_type		value_type;

	protected:
		container_type c;

	public:
		explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

		bool empty() const{return (this->c.empty());}	// Test whether container is empty

		size_type size() const{return (this->c.size());}	// Return size

		value_type& top() {return (this->c.back());}		// Access next element

		const value_type& top() const{return (this->c.back());}

		void push (const value_type& val) {this->c.push_back(val);}	// Insert element

		void pop() {this->c.pop_back();}		// Remove top element

		template<typename _Tp1 , typename _Seq1>
			friend bool operator< (const stack< _Tp1, _Seq1 > &, const stack< _Tp1, _Seq1 > &);
		template<typename _Tp1 , typename _Seq1>
			friend bool operator== (const stack< _Tp1, _Seq1 > &, const stack< _Tp1, _Seq1 > &);
	};

	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return (lhs.c == rhs.c);}

	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return !(lhs == rhs);}

	template <class T, class Container>
		bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return (lhs.c < rhs.c);}

	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return !(rhs < lhs);}

	template <class T, class Container>
		bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return (rhs < lhs);}

	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return !(lhs < rhs);}

	}
#endif
