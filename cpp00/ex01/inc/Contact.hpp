/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:17 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/11 02:05:15 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    int         _index;

    std::string _getInput(std::string str) const;
	bool IsValidPhoneNumber(const std::string &phoneNumber) const;
	bool IsSpanishCharacter(char c) const;
	bool ContainsSpanishCharacters(const std::string &input) const;
	size_t CountLengthWithMultibyte(const std::string& str) const;
	std::string AdjustColumnWidth(const std::string& str, int colWidth) const;

public:
    Contact();
    ~Contact();
    void    init(void);
    void    view(int index) const;
    bool    display(int index) const;
    void    setIndex(int i);
};

#endif
