/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/15 12:48:31 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "------my test for > < >= <= == != ------\n";

	Fixed		c(1);
	Fixed		d(2);
	Fixed		e(c);

	std::cout << "> : " << (c > e) << std::endl;
	std::cout << "> : " << (d > e) << std::endl;

	std::cout << "< : " << (c < e) << std::endl;
	std::cout << "< : " << (d < e) << std::endl;

	std::cout << ">= : " << (c >= e) << std::endl;
	std::cout << ">= : " << (d >= e) << std::endl;

	std::cout << "<= : " << (c <= e) << std::endl;
	std::cout << "<= : " << (d <= e) << std::endl;

	std::cout << "== : " << (c == e) << std::endl;
	std::cout << "== : " << (d == e) << std::endl;

	std::cout << "!= : " << (c != e) << std::endl;
	std::cout << "!= : " << (d != e) << std::endl;

	std::cout << "------my test for + - * / ------\n";

	std::cout << "+ : " << (c + e) << std::endl;
	std::cout << "+ : " << (d + e) << std::endl;

	std::cout << "- : " << (c - e) << std::endl;
	std::cout << "- : " << (d - e) << std::endl;

	std::cout << "* : " << (c * e) << std::endl;
	std::cout << "* : " << (d * e) << std::endl;

	std::cout << "/ : " << (c / e) << std::endl;
	std::cout << "/ : " << (d / e) << std::endl;

	std::cout << "------my test for ++ -- ------\n";

	std::cout << d << std::endl;
	std::cout << ++d << std::endl;
	std::cout << d << std::endl;
	std::cout << --d << std::endl;
	std::cout << d << std::endl;
	std::cout << d++ << std::endl;
	std::cout << d << std::endl;
	std::cout << d-- << std::endl;
	std::cout << d << std::endl;

	return 0;
}
