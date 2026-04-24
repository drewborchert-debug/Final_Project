#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include <cstdlib>
#include <ctime> // For the timer logic

class GameLogic {
public:
    static void playSeasonGame(Player &p) {
        // --- 1. Dynamic Difficulty ---
        int goalieDifficulty = (rand() % 31) + 55; 
        std::cout << std::endl << "--- GAME DAY: " << p.getTeam() << " vs RIVAL ---" << std::endl;
        std::cout << "Opposing Goalie Skill Level: " << goalieDifficulty << std::endl;

        // --- 2. The Reflex Fight (NEW TIMER LOGIC) ---
        if ((rand() % 100) < 15) {
            std::cout << std::endl << "!!! DROPPING THE GLOVES: Fight! !!!" << std::endl;
            
            int punchesLanded = 0;
            int targetPunches = 3;
            bool knockedOut = false;
            char keys[4] = {'a', 's', 'd', 'f'};

            while (punchesLanded < targetPunches && !knockedOut) {
                char targetKey = keys[rand() % 4];
                std::cout << "PUNCH " << (punchesLanded + 1) << "! Type '" << targetKey << "' FAST!" << std::endl;

                time_t startTime = time(0); 
                char userInput;
                std::cin >> userInput;
                time_t endTime = time(0); 

                double timeTaken = difftime(endTime, startTime);

                if (userInput == targetKey && timeTaken <= 2.0) { // Giving 2 seconds for terminal lag
                    punchesLanded++;
                    std::cout << "BOOM! Landed in " << timeTaken << " seconds." << std::endl;
                } else {
                    if (timeTaken > 2.0) std::cout << "TOO SLOW! You got rocked." << std::endl;
                    else std::cout << "WHIFF! Wrong key!" << std::endl;
                    knockedOut = true;
                }
            }

            if (punchesLanded == targetPunches) {
                std::cout << "KNOCKOUT! You won the fight!" << std::endl;
                p.addFightWin();
            } else {
                std::cout << "You're heading to the box with a black eye." << std::endl;
            }
        }

        // --- 3. The Match Sim ---
        int skillAvg = (p.getSkating() + p.getShooting() + p.getHockeyIQ()) / 3;
        int performance = skillAvg + ((rand() % 21) - 10);

        if (performance >= goalieDifficulty) {
            std::cout << "GOAL! Top shelf where mom hides the cookies!" << std::endl;
            p.addGoal();
        } else {
            std::cout << "Glove save! No goal." << std::endl;
        }

        // --- 4. Progression ---
        p.gainExperience();
        p.nextGame();
    }
};

#endif