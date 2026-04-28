#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>

class Player {
private:
    std::string name;
    std::string nhlTeam;
    int skating, shooting, hockeyIQ, energy;
    int goals, fightsWon, wins, losses, seasonGameCount;

    // The Schedule
    std::string opponents[20] = {
        "Rangers", "Bruins", "Capitals", "Flyers", "Penguins", 
        "Maple Leafs", "Canadiens", "Lightning", "Panthers", "Red Wings",
        "Islanders", "Devils", "Hurricanes", "Blue Jackets", "Senators",
        "Sabres", "Wild", "Stars", "Avalanche", "Golden Knights"
    };

public:
    Player(std::string n, std::string team) 
        : name(n), nhlTeam(team), skating(50), shooting(50), hockeyIQ(50), energy(100), 
          goals(0), fightsWon(0), wins(0), losses(0), seasonGameCount(1) {}

    // Getters for GameLogic
    int getSkating() const { return skating; }
    int getShooting() const { return shooting; }
    int getHockeyIQ() const { return hockeyIQ; }
    void setHockeyIQ(int val) { hockeyIQ = val; }
    void setShooting(int val) { shooting = val; }
    void setSkating(int val) { skating = val; }
    void setEnergy(int val) { energy = val; }
    int getEnergy() const { return energy; }
    int getGameNum() const { return seasonGameCount; }
    int getWins() const { return wins; }
    int getLosses() const { return losses; }
    int getGoals() const { return goals; }
    int getFightsWon() const { return fightsWon; }
    std::string getName() const { return name; }
    std::string getTeam() const { return nhlTeam; }
    std::string getNextOpponent() const { 
        return (seasonGameCount <= 20) ? opponents[seasonGameCount - 1] : "Playoffs"; 
    }

    // Logic Setters
    void addWin() { wins++; }
    void addLoss() { losses++; }
    void addGoal() { goals++; }
    void addFightWin() { fightsWon++; }
    void nextGame() { seasonGameCount++; }
    
    void gainExperience() {
        skating = std::min(100, skating + 1);
        shooting = std::min(100, shooting +1);
    }

    void trainOnIce(int sk, int sh) {

        if (energy >= 60) {
            skating = std::min(100, skating + sk);
            shooting = std::min(100, shooting + sh);
            energy -= 60;
        }
        else { std::cout << "Too exhausted to train!" << std::endl; }
    }

    void studyFilm(int iq) {
        if (energy >= 40) {
            hockeyIQ = std::min(100, hockeyIQ + iq);
            energy -= 40;
        }
        else { std::cout << "Too tired for film study!" << std::endl; }
    }

    void rest() { energy = 100; std::cout << "[REST] Recovered for the next shift!" << std::endl; }
    
    void displaySeasonStats() {
        std::cout << std::endl << "--- " << nhlTeam << " [" << wins << "-" << losses << "] | PLAYER: " << name << " ---" << std::endl;
        std::cout << "Season Progress: " << seasonGameCount << "/20 | Next Up: vs " << getNextOpponent() << std::endl;
        std::cout << "Stats -> SKT: " << skating << " | SHT: " << shooting << " | IQ: " << hockeyIQ << std::endl;
        std::cout << "Career -> Goals: " << goals << " | Fights Won: " << fightsWon << " | Energy: " << energy << "%" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
    }

};

#endif