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
	_fpn = 0;
}

Fixed::Fixed(const Fixed&)
{
	std::cout << "Copy constructor called" << "\n";
	_fpn = 0;
	_fpn = getRawBits();
}

Fixed& Fixed::operator=(const Fixed&)
{
	std::cout << "Copy assignment operator called" << "\n";
	_fpn = 0;
	_fpn = getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << "\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << "\n";
	return (_fpn / (1 << _bits));
}

void	Fixed::setRawBits(int const raw)
{
	if ((1 << _bits) < raw)
	{
		std::cerr << "Out of bits\n";
		std::exit(1);
	}
	_fpn = raw;
}
