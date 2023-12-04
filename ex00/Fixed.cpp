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
}

Fixed& Fixed::operator=(const Fixed& x)
{
	std::cout << "Copy assignment operator called" << "\n";
	Fixed y = x;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << "\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called " << "\n";
	std::cout << _fpn << "\n";
}

void	Fixed::setRawBits(int const raw)
{
	if (_bits < raw)
	{
		std::cerr << "Out of bits\n";
		std::exit(1);
	}
}
