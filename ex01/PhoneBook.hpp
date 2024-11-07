/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepie <pepie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:43:02 by pepie             #+#    #+#             */
/*   Updated: 2024/11/05 22:43:02 by pepie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"



#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {

public:
	PhoneBook( void );
	~PhoneBook( void );
	void    NewContact( void );
	void    PrintContacts( void );
    Contact *GetContactAtIndex( int i );
    int     GetOldestContact(void);

private:
	Contact	contact[8];
	int contactCount;
};

#endif