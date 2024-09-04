/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:44:38 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 15:03:11 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat();
        Cat(Cat const & src);
        Cat & operator=(Cat const & src);
        virtual void makeSound() const;
        void setIdea(int i, std::string idea);
        void getIdeas() const;
    protected:

    private:
        Brain* _brain;
};

#endif