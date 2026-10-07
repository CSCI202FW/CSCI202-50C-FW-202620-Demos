#include <iostream>
#include <limits>
#include <random>
#include "character.h"
#include "gameState.h"
#include "AVLTree.h"
#include "pair.h"
const std::string classStr[] = {"Fighter Class", "Rogue Class", "Magician Class", "Cleric Class"};
void resetStream();
void rogueAttack(GameState &gs);
void healParty(GameState &gs);
void fighterAttack(GameState &gs);
void magicAttack(GameState &gs);

int main()
{
    GameState gs;
    AVLTree<Pair<GameState, Action>> decisionTree;
    Pair<GameState, Action> p(gs, Action(rogueAttack));
    decisionTree.insert(p);
    GameState gs1;
    gs1.reduceHealth(.15);
    decisionTree.insert(Pair<GameState, Action>(gs1, Action(magicAttack)));
    GameState gs2;
    gs2.reduceHealth(.30);
    decisionTree.insert(Pair<GameState, Action>(gs2, Action(fighterAttack)));
    GameState gs3;
    gs3.reduceHealth(.45);
    decisionTree.insert(Pair<GameState, Action>(gs3, Action(healParty)));
    int a;
    std::random_device rd;
    std::uniform_real_distribution percent(0.0, 0.3);
    std::default_random_engine generator(rd());
    while (true)
    {
        std::cout << "1. take action" << std::endl;
        std::cout << "2. quit" << std::endl;
        std::cin >> a;
        if (a == 1)
        {
            double p = percent(generator);
            gs.reduceHealth(p);
            auto it = decisionTree.find(gs);
            if (it == decisionTree.end())
            {
                flee(gs);
            }
            else
            {
                it->getValue().doAction(gs);
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void rogueAttack(GameState &gs)
{
    std::cout << "Rogue attacked " << std::endl;
}

void healParty(GameState &gs)
{
    std::cout << "Party Heal" << std::endl;
}

void fighterAttack(GameState &gs)
{
    std::cout << "Fighter attack" << std::endl;
}

void magicAttack(GameState &gs)
{
    std::cout << "Magic Attack" << std::endl;
}

void flee(GameState &gs)
{
    std::cout << "Run away!!" << std::endl;
}
