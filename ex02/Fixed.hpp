/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:48:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/12/10 13:12:58 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( int const );
		Fixed( float const );
		Fixed( const Fixed& );

		Fixed&	operator=( const Fixed& );

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

		Fixed&	operator++( void );	//++f
		Fixed&	operator--( void );	//--f
		Fixed	operator++( int );	//f++
		Fixed	operator--( int );	//f--
	
		int			getRawBits( void ) const;
		void		setRawBits( int const );

		float		toFloat( void ) const;
		int			toInt( void ) const;

		static const Fixed&		min( Fixed& , Fixed& );
		static const Fixed&		min( const Fixed& , const Fixed& );

		static const Fixed&		max( Fixed& , Fixed& );
		static const Fixed&		max( const Fixed& , const Fixed& );

	private:
		int					_fpn;
		static const int	_bits = 8;
};

std::ostream& operator<<( std::ostream&, const Fixed& );

#endif /* __FIXED_HPP__ */
