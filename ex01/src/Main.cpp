/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:07:10 by pledieu           #+#    #+#             */
/*   Updated: 2025/06/09 14:47:57 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <sstream>

int main() {
    // Create a PhoneBook object to store and manage contacts
	PhoneBook phonebook;
	std::string command;

    // Main read/eval loop: keep prompting the user for commands
	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command); // Read the full line of input

        // Handle end-of-file (Ctrl+D) to exit gracefully
		if (std::cin.eof()) {
			std::cout << "\nExiting..." << std::endl;
			break;
		}

        // ADD command: create and store a new contact
		if (command == "ADD") {
			phonebook.addContact();
		}
        // SEARCH command: show contact list and allow detailed lookup
		else if (command == "SEARCH") {
			phonebook.displayContacts(); // Show summary of all contacts
			std::string input;
			std::cout << "Enter index to view: ";
			std::getline(std::cin, input); // Read index as string

			std::istringstream iss(input);
			int index;
			if (iss >> index)
				phonebook.displayContactByIndex(index); // Show full info of selected contact
			else
				std::cout << "Invalid input format." << std::endl;
		}
        // EXIT command: break the loop and end the program
		else if (command == "EXIT") {
			break;
		}
        // Any other input is not recognized
		else {
			std::cout << "Unknown command." << std::endl;
		}
	}

	return 0;
}

