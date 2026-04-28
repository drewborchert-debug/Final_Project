#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>

class GameLogic {
public:
    static std::string playSeasonGame(Player &p) {
        std::string report = "";

        //Dynamic Difficulty
        int goalieDifficulty = (rand() % 20) + 55 + (p.getGameNum());
        report += "MATCHUP: " + p.getTeam() + " vs " + p.getNextOpponent() + "\n";
        report += "Opposing Goalie Rating: " + std::to_string(goalieDifficulty) + "\n";

        // Fight Logic for GUI
        // 15% chance to win a fight automatically.
        if ((rand() % 100) < 15) {
            report += "!!! A fight broke out on the ice! !!!\n";
            if ((rand() % 2) == 0) {
                report += "VICTORY: You won the scrap! Momentum up.\n";
                p.addFightWin();
            } else {
                report += "DEFEAT: You took a heavy right hook.\n";
            }
        }

        // Match Simulation
        int performance = (p.getSkating() + p.getShooting() + p.getHockeyIQ()) / 3;
        if (p.getEnergy() < 30) performance -= 15;

        int result = performance + ((rand() % 21) - 10);

        if (result >= goalieDifficulty) {
            report += "RESULT: GOAL!! You scored the game winner!\n";
            p.addGoal();
            p.addWin();
        } else {
            report += "RESULT: Loss. You were shut out today.\n";
            p.addLoss();
        }

        p.gainExperience();
        p.nextGame();

        return report;
    }
};

#endif