#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    std::string nhlTeam;
    int skating, shooting, hockeyIQ, energy;
    
    int goals;
    int fightsWon;
    int seasonGameCount;

public:
    Player(std::string n, std::string team) 
        : name(n), nhlTeam(team), skating(50), shooting(50), hockeyIQ(50), energy(100), 
          goals(0), fightsWon(0), seasonGameCount(1) {}

    // --- The 4 Getters required by GameLogic ---
    int getSkating() const { return skating; }
    int getShooting() const { return shooting; }
    int getHockeyIQ() const { return hockeyIQ; }
    int getEnergy() const { return energy; }

    // --- Other Getters & Setters ---
    std::string getTeam() const { return nhlTeam; }
    int getGameNum() const { return seasonGameCount; }
    void nextGame() { seasonGameCount++; }
    
    void gainExperience() {
        skating += 1;
        shooting += 1;
        std::cout << "[XP] Game experience gained: +1 Skating, +1 Shooting!" << std::endl;
    }

    void addGoal() { goals++; }
    void addFightWin() { fightsWon++; }
    
    void trainOnIce(int sk, int sh) { 
        if (energy >= 25) {
            skating += sk; 
            shooting += sh; 
            energy -= 25; 
        } else {
            std::cout << "Too tired to train!" << std::endl;
        }
    }

    void studyFilm(int iq) { 
        if (energy >= 15) {
            hockeyIQ += iq; 
            energy -= 15; 
        } else {
            std::cout << "Too tired to study!" << std::endl;
        }
    }

    void rest() { 
        energy = 100; 
        std::cout << "[REST] Energy fully restored!" << std::endl;
    }
    
    void displaySeasonStats() {
        std::cout << std::endl << "--- " << nhlTeam << " ROSTER: " << name << " ---" << std::endl;
        std::cout << " Game: " << seasonGameCount << "/20 | Goals: " << goals << " | Fights Won: " << fightsWon << std::endl;
        std::cout << " Stats -> SKT: " << skating << " | SHT: " << shooting << " | IQ: " << hockeyIQ << std::endl;
        std::cout << " Energy: " << energy << "%" << std::endl;
    }
};

#endif