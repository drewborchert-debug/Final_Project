#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int skating;
    int shooting;
    int hockeyIQ;
    int energy;

public:
    Player(std::string n) : name(n), skating(50), shooting(50), hockeyIQ(50), energy(100) {}

    std::string getName() const { return name; }
    int getSkating() const { return skating; }
    int getShooting() const { return shooting; }
    int getHockeyIQ() const { return hockeyIQ; }
    int getEnergy() const { return energy; }

    void trainOnIce(int sk, int sh) { skating += sk; shooting += sh; energy -= 25; }
    void studyFilm(int iq) { hockeyIQ += iq; energy -= 15; }
    
    void rest() { 
        energy = 100; 
        std::cout << std::endl << "[Rest] " << name << " hit the cold tub and recovered energy!" << std::endl; 
    }

    void displayStats() {
        std::cout << std::endl << "========= " << name << "'s PRO CARD =========" << std::endl;
        std::cout << " Skating:   [" << skating << "]" << std::endl;
        std::cout << " Shooting:  [" << shooting << "]" << std::endl;
        std::cout << " Hockey IQ: [" << hockeyIQ << "]" << std::endl;
        std::cout << " Energy:    " << energy << "%" << std::endl;
        std::cout << "====================================" << std::endl;
    }
};

#endif