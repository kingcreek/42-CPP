/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imurugar <imurugar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:11:20 by imurugar          #+#    #+#             */
/*   Updated: 2023/08/12 17:04:36 by imurugar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook book;
    std::string input = "";
    book.welcome(true);
    while (input.compare("EXIT")) {
        if (input.compare("ADD") == 0)
            book.addContact();
        else if (input.compare("SEARCH") == 0) {
            book.printContacts();
            book.search();
		} else if(input.size() > 0){
			std::cout << "Come on, i know you can! The supported commands are:" << std::endl;
			book.welcome(false);
			std::cin.clear();
		}
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
		{
			std::cout << "\nCtrl + D? Apoco si tilin. Bye tilin." << std::endl;
            exit(0);
        }
		std::cin.clear();
    }
    return 0;
}
