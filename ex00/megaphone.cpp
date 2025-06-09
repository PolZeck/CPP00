/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pledieu <pledieu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:30:30 by pledieu           #+#    #+#             */
/*   Updated: 2025/06/05 16:05:20 by pledieu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    // If no arguments are provided, print a default loud message
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    // Otherwise, iterate through each argument and convert all characters to uppercase
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++) {
            std::cout << (char)std::toupper(argv[i][j]);
        }
    }

    // Add a newline at the end of the output
    std::cout << std::endl;
    return 0;
}

