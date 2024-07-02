/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:59:51 by akinzeli          #+#    #+#             */
/*   Updated: 2024/07/02 15:46:14 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define HARL_CPP

# include <iostream>
# include <string>

class Harl
{
  public:
    Harl();
    ~Harl();
	void complain(int level);
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif