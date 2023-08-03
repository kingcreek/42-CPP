/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:15 by imurugar          #+#    #+#             */
/*   Updated: 2023/07/28 13:21:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool        valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else {
            std::cin.clear();
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);
    return (input);
}

void    Contact::init(void) {
    this->_firstName = this->_getInput("Please enter first name: ");
    this->_lastName = this->_getInput("Please enter last name: ");
    this->_nickname = this->_getInput("Please enter nickname: ");
    this->_nickname = this->_getInput("Please enter phone number: ");
    this->_nickname = this->_getInput("Please enter darkest secret: ");
    std::cout << std::endl;
}


std::string Contact::_printLen(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}

void    Contact::view(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void    Contact::display(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
	{
		std::cout << "The index you entered does not exist in the phonebook." << std::endl;
        return ;
	}
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::flush;
    std::cout << "\tFirst Name: " << this->_firstName << std::flush;
    std::cout << "\tLast Name: " << this->_lastName << std::flush;
    std::cout << "\tNickname: " << this->_nickname << std::flush;
    std::cout << std::endl;
}