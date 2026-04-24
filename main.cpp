#include <iostream>
#include <vector>
#include "Player.h"
#include "GameLogic.h"

int main() {
    srand(time(0));
    
    std::cout << "Welcome to NHL MyPlayer: Road to the Cup" << std::endl;
    std::cout << "Enter Player Name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Choose your NHL Team (e.g., Capitals, Rangers, Bruins): ";
    std::string team;
    std::getline(std::cin, team);

    Player player(name, team);

    while (player.getGameNum() <= 20) {
        player.displaySeasonStats();
        std::cout << "1. Train | 2. Film | 3. PLAY GAME | 4. Rest | 5. Quit" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 3) GameLogic::playSeasonGame(player);
        else if (choice == 1) player.trainOnIce(3, 2);
        else if (choice == 2) player.studyFilm(4);
        else if (choice == 4) player.rest();
        else if (choice == 5) break;

        if (player.getGameNum() > 20) {
            std::cout << std::endl << "SEASON COMPLETE! Check your final stats." << std::endl;
            player.displaySeasonStats();
        }
    }
    return 0;
}