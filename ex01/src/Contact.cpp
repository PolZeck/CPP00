/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:07:13 by pledieu           #+#    #+#             */
/*   Updated: 2025/06/10 11:05:17 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

// Prompt the user until a non-empty input is provided
static std::string promptNonEmpty(const std::string& label) {
	std::string input;
	while (true) {
		std::cout << label;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "\nInput aborted." << std::endl;
			break;
		}
		if (!input.empty())
			break;
		std::cout << "This field cannot be empty. Please try again." << std::endl;
	}
	return input;
}

// Fill all fields of the contact using user input
void Contact::setContact() {
	firstName		= promptNonEmpty("First name: ");
	lastName		= promptNonEmpty("Last name: ");
	nickname		= promptNonEmpty("Nickname: ");
	phoneNumber		= promptNonEmpty("Phone number: ");
	darkestSecret	= promptNonEmpty("Darkest secret: ");
}

// Truncate a string to 10 characters max, appending a dot if needed
static std::string truncate(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

// Display contact summary in a formatted row
void Contact::displayShort(int index) const {
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << truncate(firstName) << "|"
				<< std::setw(10) << truncate(lastName) << "|"
				<< std::setw(10) << truncate(nickname) << std::endl;
}

// Display full contact details line by line
void Contact::displayFull() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
