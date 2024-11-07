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


#ifndef CONTACT_H
# define CONTACT_H

# include <cstring>
# include <string>

class Contact {

public:
	Contact( void );
	~Contact( void );
    void    Create(void);
    void    Print(void);
    void    PrintDetail(void);
    time_t     date;

private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    bool        initialized;
};

#endif