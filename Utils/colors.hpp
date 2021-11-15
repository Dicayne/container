/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:40:25 by vmoreau           #+#    #+#             */
/*   Updated: 2021/10/18 16:22:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP
	#ifndef uncolored
		#define BLACK "\033[0;30m"
		#define RED "\033[0;31m"
		#define GREEN "\033[32m"
		#define YELLOW "\033[33;33m"
		#define BLUE "\033[0;34m"
		#define PURPLE "\033[35m"
		#define CYAN "\033[1;36m"
		#define NC "\033[0;37m"

	#else
		#define BLACK ""
		#define RED ""
		#define GREEN ""
		#define YELLOW ""
		#define BLUE ""
		#define PURPLE ""
		#define CYAN ""
		#define NC ""
	#endif
#endif