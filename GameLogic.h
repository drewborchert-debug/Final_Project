#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include <cstdlib>
#include <ctime>

class GameLogic {
public:
    static void playSeasonGame(Player &p) {
        // 1. Dynamic Difficulty
        int goalieDifficulty = (rand() % 31) + 55; 
        std::cout << std::endl << "MATCHUP: " << p.getTeam() << " vs " << p.getNextOpponent() << std::endl;
        std::cout << "Scouting Report: Opposing Goalie is rated " << goalieDifficulty << std::endl;

        // 2. Continuous Reflex Fight (15% Chance)
        if ((rand() % 100) < 15) {
            std::cout << std::endl << "!!! CHIRP ALERT: A fight has broken out! !!!" << std::endl;
            int punchesLanded = 0;
            int targetPunches = 3;
            bool knockedOut = false;
            char keys[4] = {'a', 's', 'd', 'f'};

            while (punchesLanded < targetPunches && !knockedOut) {
                char targetKey = keys[rand() % 4];
                std::cout << "LAND PUNCH " << (punchesLanded + 1) << "! Hit '" << targetKey << "' quickly!" << std::endl;

                time_t startTime = time(0);
                char userInput;
                std::cin >> userInput;
                time_t endTime = time(0);

                if (userInput == targetKey && difftime(endTime, startTime) <= 2.0) {
                    punchesLanded++;
                    std::cout << "CLEAN HIT!" << std::endl;
                } else {
                    std::cout << "COUNTERED! You took a heavy right hook." << std::endl;
                    knockedOut = true;
                }
            }

            if (punchesLanded == targetPunches) {
                std::cout << "VICTORY: You won the fight! Momentum is yours." << std::endl;
                p.addFightWin();
            } else { std::cout << "DEFEAT: You're headed to the trainer's room." << std::endl; }
        }

        // 3. Match Simulation
        int performance = (p.getSkating() + p.getShooting() + p.getHockeyIQ()) / 3;
        if (p.getEnergy() < 30) performance -= 15;
        
        int result = performance + ((rand() % 21) - 10);

        if (result >= goalieDifficulty) {
            std::cout << "GOAL!! You scored the game winner!" << std::endl;
            p.addGoal();
            p.addWin();
        } else {
            std::cout << "Loss. You were shut out today." << std::endl;
            p.addLoss();
        }

        p.gainExperience();
        p.nextGame();
    }
};

#endif