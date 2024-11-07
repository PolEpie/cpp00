/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:43:02 by pepie             #+#    #+#             */
/*   Updated: 2024/11/05 22:43:02 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <ctime>

Contact::Contact(void)
{
    this->initialized = false;
	return;
}

Contact::~Contact(void)
{
    return;
}

void    Contact::Create(void)
{
    std::string buff;

	std::cout << "===================================" << std::endl;
	std::cout << "\tCONTACT CREATION" << std::endl;
	std::cout << "===================================" << std::endl << std::endl;
	std::cout << "Please enter the first name: " << std::endl;
	std::getline (std::cin,this->firstName);
    
	std::cout << "Please enter the last name: " << std::endl;
	std::getline (std::cin,this->lastName);

	std::cout << "Please enter the nickname: " << std::endl;
	std::getline (std::cin,this->nickName);

	std::cout << "Please enter the phone number: " << std::endl;
	std::getline (std::cin,this->phoneNumber);

	std::cout << "Please enter the darkest secret: " << std::endl;
	std::getline (std::cin,this->darkestSecret);
    this->initialized = true;
    this->date = std::time(0);
	return;
}

std::string padTo(std::string &str, const size_t num, const char paddingChar = ' ')
{
    if(num > str.size())
        str.insert(0, num - str.size(), paddingChar);
    else if (str.size() > num)
    {
        str = str.substr(0, 9);
        str.append(".");
    }
    return (str);
}

void    Contact::Print(void)
{
    std::string buff;

    if (this->initialized)
    {
        buff = this->firstName;
        std::cout << "|" << padTo(buff, 10);
        buff = this->lastName;
        std::cout << "|" << padTo(buff, 10);
        buff = this->nickName;
        std::cout << "|" << padTo(buff, 10) << "|";
    }
    else 
        std::cout << "|          |          |          |";
    return;
}

void    Contact::PrintDetail(void)
{
    if (!this->initialized)
        return;

    std::cout << "Firstname: " << this->firstName << std::endl;
    std::cout << "Lastname: " << this->lastName << std::endl;
    std::cout << "Nickname: " << this->nickName << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;

    return;
}
