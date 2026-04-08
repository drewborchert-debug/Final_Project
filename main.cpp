#include <iostream>
#include <ctime>
#include "Player.h"
#include "GameLogic.h"

int main() {
    srand(time(0));
    
    std::cout << "Welcome to MyPlayer: Road to the Cup!" << std::endl;
    std::cout << "Enter your Prospect's Name: ";
    std::string name;
    std::getline(std::cin, name);

    Player player(name);
    int choice = 0;

    while (choice != 5) {
        player.displayStats();
        std::cout << "DAILY SCHEDULE:" << std::endl;
        std::cout << "1. Power Skating & Shooting" << std::endl;
        std::cout << "2. Study Opponent Film" << std::endl;
        std::cout << "3. Play Next Game" << std::endl;
        std::cout << "4. Rest/Recover" << std::endl;
        std::cout << "5. Save and Quit" << std::endl;
        std::cout << "Select Activity: ";
        std::cin >> choice;

        if (choice == 1) player.trainOnIce(4, 3);
        else if (choice == 2) player.studyFilm(5);
        else if (choice == 3) GameLogic::playGame(player);
        else if (choice == 4) player.rest();
        else if (choice == 5) std::cout << "Heading to the bus..." << std::endl;
        else std::cout << "Coach didn't like that choice. Try again." << std::endl;
    }
    
    return 0;
}