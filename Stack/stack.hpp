/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:51 by vmoreau           #+#    #+#             */
/*   Updated: 2021/09/10 16:44:28 by vmoreau          ###   ########.fr       */
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
		container_type _stk;

	public:
		explicit stack (const container_type& ctnr = container_type()) : _stk(ctnr) {}

		bool empty() const{return (this->_stk.empty());}	// Test whether container is empty

		size_type size() const{return (this->_stk.size());}	// Return size

		value_type& top() {return (this->_stk.back());}		// Access next element

		const value_type& top() const{return (this->_stk.back());}

		void push (const value_type& val) {this->_stk.push_back(val);}	// Insert element

		void pop() {this->_stk.pop_back();}		// Remove top element

		template<typename _Tp1 , typename _Seq1>
			friend bool operator< (const stack< _Tp1, _Seq1 > &, const stack< _Tp1, _Seq1 > &);
		template<typename _Tp1 , typename _Seq1>
			friend bool operator== (const stack< _Tp1, _Seq1 > &, const stack< _Tp1, _Seq1 > &);
	};

	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return (lhs._stk == rhs._stk);}

	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return !(lhs == rhs);}

	template <class T, class Container>
		bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return (lhs._stk < rhs._stk);}

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