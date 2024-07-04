/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:37:29 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/04 12:33:35 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed(void);
        Fixed(Fixed const & src);
        ~Fixed(void);
        Fixed & operator=( Fixed const & rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        static const int _bit_value;
};



#endif