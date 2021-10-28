/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:44:08 by llefranc          #+#    #+#             */
/*   Updated: 2021/10/28 18:52:14 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_TESTER_HPP
#define UTILS_TESTER_HPP

#include <string>

int	getTestNumber(int *nb);
std::string toString(int i);
void printTestName(const std::string& nbLine, std::string name, const std::string& info = "");
std::string NumberToString (int Number);

#endif