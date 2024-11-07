/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:43:02 by pepie             #+#    #+#             */
/*   Updated: 2024/11/05 22:43:02 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
    this->contactCount = 0;
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

int     PhoneBook::GetOldestContact(void)
{
    int     oldest = 0;
    time_t  date = 900000000000;
    for (int i = 0; i < this->contactCount; i++)
    {
        if (date > this->contact[i].date)
        {
            oldest = i;
            date = this->contact[i].date;
        }
    }
    return (oldest);
}

void    PhoneBook::NewContact(void)
{
    if (this->contactCount >= 8)
    {
        int i = this->GetOldestContact();
        contact[i].Create();
    } else {
        contact[this->contactCount].Create();
        this->contactCount++;
    }
}

Contact    *PhoneBook::GetContactAtIndex(int i)
{
    if (i < 0 || i > 8)
    {
        std::cout << "Index out of range !" << std::endl;
        return (NULL);
    }
    if (i > this->contactCount)
    {
        std::cout << "Contact is not registred yet!" << std::endl;
        return (NULL);
    }
    return (&this->contact[i]);
}


void    PhoneBook::PrintContacts(void)
{
    std::cout << std::endl << "|  Index   |Firstname | Lastname | Nickname |" << std::endl;
    if (this->contactCount == 0)
    {
        std::cout << std::endl << "\tNo Contact registred yet!" << std::endl;
    }
    for (int i = 0; i <= 8; i++)
    {
        if (i < this->contactCount)
        {
            std::cout << std::endl << "|        #" << i;
            contact[i].Print();
        }
    }
    std::cout << std::endl << std::endl << "Select what index do you wanna see?" << std::endl;

    std::string index;

    std::getline(std::cin, index);

    int i = std::atoi(index.c_str());

    Contact *contact = this->GetContactAtIndex(i);

    if (contact == NULL)
        return;

    contact->PrintDetail();
}