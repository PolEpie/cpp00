/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:01:39 by pepie             #+#    #+#             */
/*   Updated: 2024/11/05 22:01:39 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phone;
    //

    std::string buff;

    while (1) 
    {
        std::cout << std::endl << "Your Following option: ADD | SEARCH | EXIT" << std::endl;
	    std::getline (std::cin,buff);

        if (buff == "ADD")
            phone.NewContact();
        else if (buff == "SEARCH")
        {
            phone.PrintContacts();
        }
        else if (buff == "EXIT")
            break;
    }   

	return 0;
}