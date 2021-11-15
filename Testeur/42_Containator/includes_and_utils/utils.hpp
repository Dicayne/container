/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:44:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/11/15 18:27:17 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSS_HPP
#define UTILSS_HPP

#include <string>

int	getTestNumber(int *nb);
std::string toString(int i);
void printTestName(const std::string& nbLine, std::string name, const std::string& info = "");
std::string NumberToString (int Number);

#endif
