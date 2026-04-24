#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include <cstdlib>
#include <ctime>

class GameLogic {
public:
    static void playSeasonGame(Player &p) {
        // 1. Dynamic Difficulty: Random Goalie Rating for each game
        // Random rating between 55 (Rookie) and 85 (Vezina Winner)
        int goalieDifficulty = (rand() % 31) + 55; 

        std::cout << std::endl << "--- GAME DAY: " << p.getTeam() << " vs RIVAL ---" << std::endl;
        std::cout << "Opposing Goalie Skill Level: " << goalieDifficulty << std::endl;

    // 2. The Continuous Fight Factor (15% Chance)
    if ((rand() % 100) < 15) {
        std::cout << std::endl << "!!! DROPPING THE GLOVES: A fight has broken out! !!!" << std::endl;
    
        int punchesLanded = 0;
        int targetPunches = 3; // Must land 3 punches to win
        bool knockedOut = false;

        while (punchesLanded < targetPunches && !knockedOut) {
            std::cout << "Punches landed: " << punchesLanded << "/" << targetPunches << std::endl;
            std::cout << "Type 'f' to PUNCH! (Anything else and you get countered): ";
        
            char fightInput;
            std::cin >> fightInput;

        if (fightInput == 'f' || fightInput == 'F') {
            punchesLanded++;
            std::cout << "DIRECT HIT!" << std::endl;
        } else {
            std::cout << "MISS! You got countered!" << std::endl;
            knockedOut = true; // Fight ends if you miss
        }
    }

        if (punchesLanded == targetPunches) {
            std::cout << "KNOCKOUT! You won the fight and the crowd is going wild!" << std::endl;
            p.addFightWin();
        } else {
            std::cout << "You've been sent to the penalty box after taking a tough hit." << std::endl;
        }
    
        std::cout << std::endl;
    }

        // 3. Match Simulation Logic
        // Calculate performance based on your attributes
        int skillAverage = (p.getSkating() + p.getShooting() + p.getHockeyIQ()) / 3;
        
        // Fatigue Penalty: If energy is low, performance drops
        if (p.getEnergy() < 30) {
            skillAverage -= 15;
            std::cout << "[NOTICE] You look sluggish out there due to low energy." << std::endl;
        }

        int puckLuck = (rand() % 21) - 10; // Random factor between -10 and 10
        int performanceScore = skillAverage + puckLuck;

        // Determine if a goal was scored
        if (performanceScore >= goalieDifficulty) {
            std::cout << "HE SCORES!! A beautiful snipe into the top shelf!" << std::endl;
            p.addGoal();
        } else {
            std::cout << "Great save! You couldn't beat the goalie this time." << std::endl;
        }

        // 4. Feature: Passive Skill Gain (Gain XP even if you lose)
        p.gainExperience();

        // 5. Advance the Season Calendar
        p.nextGame();
        
        std::cout << "--- Game Over ---" << std::endl;
    }
};

#endif