/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:15 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/11 02:10:46 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool Contact::IsValidPhoneNumber(const std::string &phoneNumber) const {
    for (std::string::const_iterator it = phoneNumber.begin(); it != phoneNumber.end(); ++it) {
        char c = *it;
        if (!std::isdigit(c) && c != '+' && c != ' ' && c != '(' && c != ')' && c != '-' && c != '#' && c != '*') {
            return false;
        }
    }
    return true;
}

bool Contact::IsSpanishCharacter(char c) const {
    const char *validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZáéíóúÁÉÍÓÚñÑçÇ!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~ ";
    for (const char *p = validChars; *p != '\0'; ++p) {
        if (*p == c) {
            return true;
        }
    }
    return false;
}

bool Contact::ContainsSpanishCharacters(const std::string &input) const {
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
        if (!IsSpanishCharacter(*it) && !std::isspace(*it)) {
            return false;
        }
    }
    return true;
}

std::string Contact::_getInput(std::string str) const {
    std::string input = "";
    bool valid = false;
    do {
        std::cout << str << std::flush;

        std::getline(std::cin, input);
		if (std::cin.eof() == true)
        {
			std::cout << "\nCtrl + D? Ok, bye bye" << std::endl;
            exit(0);
        }

        bool containsOnlySpaces = true;
        bool containsValid = false;

        for (size_t i = 0; i < input.length(); i++) {
            if (!std::isspace(input[i])) {
                containsOnlySpaces = false;
				break;
            }
        }
		if (ContainsSpanishCharacters(input))
            containsValid = true;

        if (!input.empty() && !containsOnlySpaces && containsValid) {
            valid = true;
        } else {
            std::cout << "Invalid input; please try again." << std::endl;
        }
    } while (!valid);

    return input;
}



void    Contact::init(void) {
    this->_firstName = this->_getInput("Please enter first name: ");
    this->_lastName = this->_getInput("Please enter last name: ");
    this->_nickname = this->_getInput("Please enter nickname: ");
	do
	{
		this->_phoneNumber = this->_getInput("Please enter phone number: ");
		if(!IsValidPhoneNumber(this->_phoneNumber))
			std::cout << "Invalid input; Phone number only allow numbers, and follow symbols: \"<space>+-()#*\"" << std::endl;
	} while (!IsValidPhoneNumber(this->_phoneNumber));
    this->_darkestSecret = this->_getInput("Please enter darkest secret: ");
    std::cout << std::endl;
}

void    Contact::setIndex(int i) {
    this->_index = i;
}

size_t Contact::CountLengthWithMultibyte(const std::string& str) const {
    size_t length = 0;
    const char* cstr = str.c_str();
    while (*cstr) {
        int bytes = 1;
        if ((*cstr & 0x80) == 0x00) { // ASCII character 1 byte
            bytes = 1;
        } else if ((*cstr & 0xE0) == 0xC0) { // 2 bytes character
            bytes = 2;
        } else if ((*cstr & 0xF0) == 0xE0) { // 3 bytes character
            bytes = 3;
        } else if ((*cstr & 0xF8) == 0xF0) { // 4 bytes character
            bytes = 4;
        }
        cstr += bytes;
        length++;
    }
    return length;
}

std::string Contact::AdjustColumnWidth(const std::string& str, int colWidth) const{
    int strLength = CountLengthWithMultibyte(str);
    int charsToAdd = colWidth - strLength;

    if (charsToAdd > 0) {
        std::string spaces(charsToAdd, ' ');
        return spaces + str;
    } else if (charsToAdd < 0) {
        int len = 0;
        int i = 0;
        while (i < static_cast<int>(str.length()) && len < colWidth - 1) {
            int bytes = 1;
            unsigned char ch = static_cast<unsigned char>(str[i]);
            if (ch >= 0x80 && ch <= 0xBF) {
                // Continuation byte, skip it and move to the next character
                i++;
                continue;
            } else if (ch >= 0xC0 && ch <= 0xDF) {
                bytes = 2;
            } else if (ch >= 0xE0 && ch <= 0xEF) {
                bytes = 3;
            } else if (ch >= 0xF0 && ch <= 0xF7) {
                bytes = 4;
            }

            if (len + 1 > colWidth) {
                break;
            }

            len += 1; // Increment by 1 for a complete character
            i += bytes;
        }
		/*
		the var i, now have the ammount of bytes to skip, example:
		"a"   -> 1 byte
		"aa"  -> 2 byte
		"aañ" -> 4 byte

		substr function need ammount of characters can be removed as second parameter, but are not safe to process non ASCII characters,
		like utf-8 (ñ) or like:(😋 - 4 bytes), then if the imput have any multibyte character like "ñ" if we skip only 1, the output are wrong.
		If we have 10 emojis and second parameters are 10, the result are a 2 emoji and strange simbol becouse the 3rd character are truncated in 2nd byte.
		And we cant use wstring like in c++11/17 (*sad face*... sorry, in 4 bytes 😔 better), i improvise this to try manage non ASCII characters.
		*/
        return str.substr(0, i) + ".";
    }

    return str;
}

void Contact::view(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return;

    int colWidth = 10;
    std::cout << "|" << std::setw(colWidth) << index << std::flush;
	//example to prove wrong way
	//std::string a(this->_firstName.substr(0, 9) + ".");
	//std::cout << "|" << std::setw(colWidth) << a << std::flush;
    std::cout << "|" << std::setw(colWidth) << AdjustColumnWidth(this->_firstName, colWidth) << std::flush;
    std::cout << "|" << std::setw(colWidth) << AdjustColumnWidth(this->_lastName, colWidth) << std::flush;
    std::cout << "|" << std::setw(colWidth) << AdjustColumnWidth(this->_nickname, colWidth) << std::flush;
    std::cout << "|" << std::endl;
}

bool    Contact::display(int index) const {
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
	{
		std::cout << "The index you entered does not exist in the phonebook." << std::endl;
        return false;
	}
    std::cout << std::endl;
    std::cout << "---->> CONTACT #" << index << " <<----" << std::endl;
	std::cout << "First Name\t: " << this->_firstName << std::endl;
    std::cout << "Last Name\t: " << this->_lastName << std::endl;
    std::cout << "Nickname\t: " << this->_nickname << std::endl;
	std::cout << "Phone Number\t: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret\t: " << this->_darkestSecret << std::endl;
    std::cout << std::endl;
	
	return true;
}
