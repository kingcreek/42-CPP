/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:26 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/11 00:29:17 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_haveContacts = false;
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::welcome(bool print_welcome) const {
	if (print_welcome)
	{
    	std::cout << std::endl;
    	std::cout << "Welcome to the most useless phonebook in the world." << std::endl;
    	std::cout << std::endl;
	}
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: To quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::addContact(void) {
    static int  i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
	this->_haveContacts = true;
}

void    PhoneBook::printContacts(void) const {
    std::cout << "------------- PHONEBOOK CONTACTS -------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        this->_contacts[i].view(i);
    }
    std::cout << std::endl;
}

int PhoneBook::_readInput() const {
    int input = -1;
    bool valid = false;
    do {
        std::string line;
        std::cout << "Please enter the contact index, 0 to 7: " << std::flush;
        std::getline(std::cin, line);
		//Handle ctrl D
		if (std::cin.eof() == true)
        {
			std::cout << "\nCtrl + D? Ok, bye bye" << std::endl;
            exit(0);
        }
        // Check empty line
        if (line.empty()) {
            std::cout << "Invalid input. Please enter a valid index from 0 to 7." << std::endl;
            continue;
        }

        std::istringstream iss(line);
        iss >> input;

        // Check correct conversion and wrong values/characters
        if (!iss.fail() && iss.eof() && input >= 0 && input <= 7)
            valid = true;
        else
            std::cout << "Invalid input. Please enter a valid index from 0 to 7." << std::endl;
        
    } while (!valid);
    return input;
}

void    PhoneBook::search(void) const {
	if(this->_haveContacts)
	{
    	int i = this->_readInput();
    	if(this->_contacts[i].display(i) == false)
			search();
	} else
		std::cout << "There are no contacts in the phonebook" << std::endl;
}
