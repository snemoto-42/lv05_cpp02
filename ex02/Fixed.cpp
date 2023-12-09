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
	std::cout << "Default constructor called" << "\n";
	_fpn = 0;
}

Fixed::Fixed(int const i)
{
	std::cout << "Int Constructor called" << "\n";
	_fpn = i;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float Constructor called" << "\n";
	_fpn = (f * (1 << _bits));
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

Fixed	Fixed::operator+(const Fixed& x)
{
	_fpn += x._fpn;
	return (*this);
}

Fixed	Fixed::operator-(const Fixed& x)
{
	_fpn -= x._fpn;
	return (*this);
}

Fixed	Fixed::operator*(const Fixed& x)
{
	_fpn *= x._fpn;
	return (*this);
}

Fixed	Fixed::operator/(const Fixed& x)
{
	if (x._fpn == 0)
	{
		std::cerr << "Devide by zero\n";
		std::exit(1);
	}
	_fpn /= x._fpn;
	return (*this);
}

Fixed&	Fixed::operator++(void)	//++f
{
	int	e = 1;
	_fpn += e;
	return (*this);
}

Fixed&	Fixed::operator--(void)	//--f
{
	int	e = 1;
	_fpn -= e;
	return (*this);
}

Fixed	Fixed::operator++(int e)	//f++
{
	_fpn -= e;
	return (*this);
}

Fixed	Fixed::operator--(int e)	//f--
{
	_fpn -= e;
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
	return (_fpn * (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (_fpn / (1 << _bits));
}

int		Fixed::min(Fixed& x, Fixed& y)
{
	if (x > y)
		return (y._fpn);
	else
		return (x._fpn);
}

const int&	Fixed::min(const int& x, const int& y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int		Fixed::max(Fixed& x, Fixed& y)
{
	if (x > y)
		return (x._fpn);
	else
		return (y._fpn);
}

const int&	Fixed::max(const int& x, const int& y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

std::ostream& operator<<( std::ostream& os, const Fixed& f)
{
	return os << f.getRawBits();
}
