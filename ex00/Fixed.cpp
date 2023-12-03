/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/15 17:04:07 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << "\n";
	setRawBits(0);
}

Fixed::Fixed(const Fixed&)
{
	std::cout << "Copy constructor called" << "\n";
	getRawBits();
}

Fixed& Fixed::operator=(const Fixed& x)
{
	std::cout << "Copy assignment operator called" << "\n";
	getRawBits();
	_num = x._num;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << "\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called " << "\n";
	return (_num);
}

void	Fixed::setRawBits(int const raw)
{
	_num = raw / _bits;
}
