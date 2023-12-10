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

Fixed::Fixed(const Fixed& x)
{
	std::cout << "Copy constructor called" << "\n";
	*this = x;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &f)
		this->_fpn = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << "\n";
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << "\n";
	return (_fpn);
}

void	Fixed::setRawBits(int const raw)
{
	_fpn = raw;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int Constructor called" << "\n";
	_fpn = (i << _bits);
}

Fixed::Fixed(float const f)
{
	std::cout << "Float Constructor called" << "\n";
	_fpn = roundf((f * (1 << _bits)));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (_fpn >> _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	return os << f.toFloat();
}
