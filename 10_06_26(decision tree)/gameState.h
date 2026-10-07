#ifndef GAME_H
#define GAME_H
#include <vector>
#include "character.h"

class GameState
{
public:
    GameState();
    void reduceHealth(double percent);
    bool operator<(GameState oth) const;
    bool operator>(GameState oth) const;
    bool operator==(GameState oth) const;
    bool operator!=(GameState oth) const;
    double healthPercent() const;

private:
    std::vector<character *> characters;
};
void flee(GameState &gs);
class Action
{
public:
    void doAction(GameState &gs);
    Action(void (*action)(GameState &gs));
    Action();

private:
    // function pointer goes here.
    void (*action)(GameState &gs);
};

#endif