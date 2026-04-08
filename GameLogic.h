#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include <cstdlib>

class GameLogic {
public:
    static void playGame(Player &p) {
        if (p.getEnergy() < 30) {
            std::cout << std::endl << "[SYSTEM] You are exhausted! Performance penalized!" << std::endl;
        }

        int goalieDifficulty = 65;
        int playerPerformance = (p.getSkating() + p.getShooting() + p.getHockeyIQ()) / 3;
        
        if (p.getEnergy() < 30) playerPerformance -= 15;

        int luck = (rand() % 20) - 10;
        int totalScore = playerPerformance + luck;

        std::cout << std::endl << "--- GAME NIGHT: PUCK DROP ---" << std::endl;
        
        if (totalScore > goalieDifficulty + 10) {
            std::cout << "RESULT: Natural Hat Trick! Victory!" << std::endl;
            p.studyFilm(2); 
        } else if (totalScore >= goalieDifficulty) {
            std::cout << "RESULT: Hard fought win in OT!" << std::endl;
        } else {
            std::cout << "RESULT: Tough loss at home." << std::endl;
        }
        
        std::cout << std::endl << "[COACH'S CLIPBOARD]: ";
        if (p.getShooting() < 60) std::cout << "\"Work on your wrister.\"" << std::endl;
        else if (p.getHockeyIQ() < 60) std::cout << "\"Learn the playbook.\"" << std::endl;
        else std::cout << "\"Good hustle out there.\"" << std::endl;
    }
};

#endif