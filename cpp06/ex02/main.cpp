/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:30:12 by amenesca          #+#    #+#             */
/*   Updated: 2023/08/01 16:10:00 by amenesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseTypes.hpp"

int main()
{
	Base *type = generate();
	identify(type);
	identify(*type);
}