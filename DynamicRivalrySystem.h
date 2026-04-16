#ifndef DYNAMIC_RIVALRY_SYSTEM_H
#define DYNAMIC_RIVALRY_SYSTEM_H   

#include <string>
#include <vector>
#include <utility>   // for pair

//  Declarations
class Team;
class RivalryDatabase;
class RivalryMode;

// ------- Team ------
class Team {
private:
    std::string teamName;
    std::vector<std::string> players;

public:
    std::string getTeamStats() const;
    const std::vector<std::string>& getPlayers() const;
};

// -------- RivalryDatabase -------
class RivalryDatabase {
private:
    std::vector<std::pair<Team, Team>> rivalTeamsList;

public:
    std::vector<std::pair<Team, Team>> getRivalTeams() const;
    void addRivalry(const Team& teamA, const Team& teamB);
};

// ------- RivalryMode --------
class RivalryMode {
private:
    bool isActive;
    int intensityLevel;

public:
    void enableMode();
    void disableMode();
    void updateIntensity(int value);
};

// --------- RivalryManager -----------
class RivalryManager {
private:
    RivalryDatabase rivalryDatabase;
    RivalryMode rivalryMode;   // Added

public:
    bool isRivalry(const Team& teamA, const Team& teamB) const;
    void activateRivalryMode();
};

// ------------ CrowdReactionSystem --------------
class CrowdReactionSystem {
private:
    int crowdEnergy;

public:
    void reactToTouchdown();
    void reactToTurnover();
    void increaseNoise();
};

// ------------- CommentarySystem ------------
class CommentarySystem {
private:
    std::vector<std::string> commentaryLines;

public:
    void playRivalryComment();
    void playBigMomentComment();
};

// ----------- MomentumMeter ------------
class MomentumMeter {
private:
    int momentumValue;

public:
    void increaseMomentum();
    void decreaseMomentum();
    void displayMeter() const;
};

// ---------- GameMatch -----------
class GameMatch {
private:
    Team teamA;
    Team teamB;
    std::string matchTime;
    std::string stadium;

    RivalryManager rivalryManager;

    // Added systems (as per diagram)
    
    CrowdReactionSystem crowdSystem;
    CommentarySystem commentarySystem;
    MomentumMeter momentumMeter;

public:
    void startMatch();
    void checkRivalry();
    void updateGameState();
};

#endif