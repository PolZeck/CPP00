/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:07:14 by pledieu           #+#    #+#             */
/*   Updated: 2025/06/16 15:51:48 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

// Initialize the phonebook with no contacts
PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

// Add a new contact (overwrite the oldest one if the list is full)
void PhoneBook::addContact() {
	int index = contactCount < 8 ? contactCount : oldestIndex;
	contacts[index].setContact();

	if (contactCount < 8)
		contactCount++;
	else
		oldestIndex = (oldestIndex + 1) % 8;
}

// Display a table with all saved contacts
void PhoneBook::displayContacts() const {
	std::cout	<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++) {
		contacts[i].displayShort(i);
	}
}

// Show full details of a contact by index (if valid)
void PhoneBook::displayContactByIndex(int index) const {
	if (index < 0 || index >= contactCount) {
		std::cout << "Invalid index." << std::endl;
	} else {
		contacts[index].displayFull();
	}
}
