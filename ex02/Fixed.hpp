/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/10/15 17:04:25 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( int const );
		Fixed( float const );
		Fixed( const Fixed& );

		Fixed&	operator=(const Fixed& );

		~Fixed( void );

		bool	operator>( const Fixed& ) const;
		bool	operator>=( const Fixed& ) const;
		bool	operator<( const Fixed& ) const;
		bool	operator<=( const Fixed& ) const;
		bool	operator==( const Fixed& ) const;
		bool	operator!=( const Fixed& ) const;
	
		Fixed	operator+( const Fixed& ) const;
		Fixed	operator-( const Fixed& ) const;
		Fixed	operator*( const Fixed& ) const;
		Fixed	operator/( const Fixed& ) const;

		Fixed&	operator++( void );
		Fixed&	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );
	
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

		float		toFloat( void ) const;
		int			toInt( void ) const;

		static int	min( Fixed&, Fixed& );
		static int&	min( const Fixed&, const Fixed& );

		static int	max( Fixed&, Fixed& );
		static int&	max( const Fixed&, const Fixed& );

	private:
		int					_fpn;
		static const int	_bits = 8;
};

std::ostream& operator<<( std::ostream&, const Fixed& );

#endif /* __FIXED_HPP__ */
