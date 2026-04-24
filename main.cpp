#include <iostream>
#include <ctime>
#include "Player.h"
#include "GameLogic.h"

int main() {
    srand(time(0)); // Important: This makes the random numbers actually random
    
    std::cout << "Enter Player Name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter NHL Team: ";
    std::string team;
    std::getline(std::cin, team);

    Player p(name, team);

    while (p.getGameNum() <= 20) {
        p.displaySeasonStats();
        std::cout << "1. Train | 2. Film | 3. PLAY GAME | 4. Rest | 5. Quit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 3) GameLogic::playSeasonGame(p);
        else if (choice == 1) p.trainOnIce(3, 2);
        else if (choice == 2) p.studyFilm(4);
        else if (choice == 4) p.rest();
        else if (choice == 5) break;
    }

    return 0;
}