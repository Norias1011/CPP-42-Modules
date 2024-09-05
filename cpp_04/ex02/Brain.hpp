/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:19:17 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:50:37 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain(Brain const & src);
        Brain & operator=(Brain const & src);
        void setIdea(int i, std::string idea);
        const std::string getIdea(size_t i) const;
        const std::string *getIdeasAddress(size_t i) const;
    protected:
        std::string _ideas[100];
    private:
};

#endif 