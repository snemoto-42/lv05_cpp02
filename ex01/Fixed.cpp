/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/15 17:04:16 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << "\n";
	_fpn = 0;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int Constructor called" << "\n";
}

Fixed::Fixed(float const f)
{
	std::cout << "Float Constructor called" << "\n";
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

float	Fixed::toFloat(void) const
{
	;
}

int		Fixed::toInt(void) const
{
	;
}

std::ostream& operator<<( std::ostream& os, const Fixed& f)
{
	return os << f.getRawBits();
}
