// Copyright (c) 2021 Alexander Matheson All rights reserved.
//
// Created by: Alexander matheson
// Created on: Dec 14 2021
// This program gets the user to guess a number
// between 0 and 9 and tells them if it is correct.
#include <iostream>
#include <random>


int main() {
    // this function checks the user's number

    // set variables
    std::string userNumberString;
    int userNumber;
    int correct;

    std::random_device rseed;

    std::mt19937 rgen(rseed());

    std::uniform_int_distribution<int> idist(0, 9);

    correct = idist(rgen);

    // input
    std::cout << "What is your number? ";
    std::getline(std::cin, userNumberString);

    // error checking
    try {
        // convert user input
        userNumber = std::stoi(userNumberString);
        // check user number
        if (userNumber == correct) {
            std::cout << "Correct!\n";
        } else if (userNumber >= 10) {
            std::cout << "Number must be between 0 and 9.\n";
        } else if (userNumber <= -1) {
            std::cout << "Number must be between 0 and 9.\n";
        }  else {
            std::cout << "Wrong, the number was " << correct << ".\n";
        }
    } catch (std::invalid_argument) {
        std::cout << "Your input, " << userNumberString <<
        ", is not a number.\n";
    }

    // thank the user
    std::cout << "Thank you for playing";
}
