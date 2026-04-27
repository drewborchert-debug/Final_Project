#include <iostream>
#include <ctime>
#include "Player.h"
#include "GameLogic.h"

int main() {
    srand(time(0));
    
    std::cout << "--- NHL MYPLAYER: ROAD TO THE CHAMPIONSHIP ---" << std::endl;
    std::cout << "Enter your Prospect's Name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter your NHL Team: ";
    std::string team;
    std::getline(std::cin, team);

    Player player(name, team);

    while (player.getGameNum() <= 20) {
        player.displaySeasonStats();
        std::cout << "WHAT IS THE PLAN FOR TODAY?" << std::endl;
        std::cout << "1. Power Skating & Shooting (+Stats, -Energy)" << std::endl;
        std::cout << "2. Video Review (+IQ, -Energy)" << std::endl;
        std::cout << "3. PLAY UPCOMING GAME" << std::endl;
        std::cout << "4. Rest & Recovery" << std::endl;
        std::cout << "5. Retire (Quit Game)" << std::endl;
        std::cout << "Selection: ";
        
        int choice;
        std::cin >> choice;

        if (choice == 3) GameLogic::playSeasonGame(player);
        else if (choice == 1) player.trainOnIce(4, 3);
        else if (choice == 2) player.studyFilm(5);
        else if (choice == 4) player.rest();
        else if (choice == 5) break;
        else std::cout << "Invalid choice. The coach is staring at you." << std::endl;

        if (player.getGameNum() > 20) {
            std::cout << std::endl << "=== SEASON OVER ===" << std::endl;
            player.displaySeasonStats();
            std::cout << "Thanks for playing, Rookie!" << std::endl;
        }
    }

    return 0;
}