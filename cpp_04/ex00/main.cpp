/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinzeli <akinzeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:24:27 by akinzeli          #+#    #+#             */
/*   Updated: 2024/09/04 14:07:57 by akinzeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* ugly_animal = new WrongAnimal();
    const WrongAnimal* ugly_cat = new WrongCat();

    std::cout << "*************** Normal polymorphisme *****************" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete(meta);
    delete(j);
    delete(i);

    std::cout << "*************** Wrong Polymorphisme *******************" << std::endl;

    std::cout << ugly_animal->getType() << " " << std::endl;
    std::cout << ugly_cat->getType() << " " << std::endl;
    ugly_animal->makeSound();
    ugly_cat->makeSound();
    delete(ugly_animal);
    delete(ugly_cat);

    std::cout << "*************** End of the program ********************" << std::endl;
    return 0;
}