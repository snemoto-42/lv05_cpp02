/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/15 17:04:22 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << "\n";
	_fpn = 0;
}

Fixed::Fixed(const Fixed& x)
{
	// std::cout << "Copy constructor called" << "\n";
	*this = x;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	// std::cout << "Copy assignment operator called" << "\n";
	if (this != &f)
		this->_fpn = f.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << "\n";
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
	// std::cout << "Int Constructor called" << "\n";
	_fpn = (i << _bits);
}

Fixed::Fixed(float const f)
{
	// std::cout << "Float Constructor called" << "\n";
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

bool	Fixed::operator>(const Fixed& x) const
{
	return (_fpn > x._fpn);
}

bool	Fixed::operator>=(const Fixed& x) const
{
	return (_fpn >= x._fpn);
}

bool	Fixed::operator<(const Fixed& x) const
{
	return (_fpn < x._fpn);
}

bool	Fixed::operator<=(const Fixed& x) const
{
	return (_fpn <= x._fpn);
}

bool	Fixed::operator==(const Fixed& x) const
{
	return (_fpn == x._fpn);
}

bool	Fixed::operator!=(const Fixed& x) const
{
	return (_fpn != x._fpn);
}

Fixed	Fixed::operator+(const Fixed& x) const
{
	return (Fixed(this->toFloat() + x.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& x) const
{
	return (Fixed(this->toFloat() - x.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& x) const
{
	return (Fixed(this->toFloat() * x.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& x) const
{
	if (x._fpn == 0)
	{
		std::cerr << "Devide by zero\n";
		std::exit(1);
	}
	return (Fixed(this->toFloat() / x.toFloat()));
}

Fixed&	Fixed::operator++(void)	//++f
{
	_fpn += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)	//--f
{
	_fpn -= 1;
	return (*this);
}

Fixed	Fixed::operator++(int)	//f++
{
	Fixed f(*this);
	operator++();
	return (f);
}

Fixed	Fixed::operator--(int)	//f--
{
	Fixed f(*this);
	operator--();
	return (f);
}

const Fixed&	Fixed::min(Fixed& x, Fixed& y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

const Fixed&	Fixed::min(const Fixed& x, const Fixed& y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

const Fixed&	Fixed::max(Fixed& x, Fixed& y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

const Fixed&	Fixed::max(const Fixed& x, const Fixed& y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
