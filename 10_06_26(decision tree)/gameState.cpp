#include "gameState.h"

GameState::GameState()
{
    characters.push_back(new fighter("Snowball the White"));
    characters.push_back(new rogue("Evey the Grey"));
    characters.push_back(new magician("Molly the Brown"));
    characters.push_back(new cleric("Oscar the Orange"));
}

void GameState::reduceHealth(double percent)
{
    for (character *c : characters)
    {
        c->setHp(c->getHp() - c->getHp() * percent);
    }
}

bool GameState::operator<(GameState oth) const
{
    double myHealthState = healthPercent();
    double othHealthState = oth.healthPercent();
    bool less = myHealthState < (othHealthState - othHealthState * .1);
    return less;
}

bool GameState::operator>(GameState oth) const
{
    double myHealthState = healthPercent();
    double othHealthState = oth.healthPercent();
    bool more = myHealthState > (othHealthState + othHealthState * .1);
    return more;
}

bool GameState::operator==(GameState oth) const
{
    double myHealthState = healthPercent();
    double othHealthState = oth.healthPercent();
    bool same = myHealthState < (othHealthState + othHealthState * .1) && myHealthState > (othHealthState - othHealthState * .1);
    return same;
}

bool GameState::operator!=(GameState oth) const
{
    return !(*this == oth);
}

double GameState::healthPercent() const
{
    fighter f("test");
    rogue r("test2");
    cleric c("test3");
    magician m("test4");

    double totalHealth = 0;
    totalHealth = f.getHp() + r.getHp() + c.getHp() + m.getHp();
    double currentHealth = 0;
    for (character *c : characters)
    {
        currentHealth += c->getHp();
    }

    return currentHealth / totalHealth;
}

void Action::doAction(GameState &gs)
{
    action(gs);
}

Action::Action(void (*action)(GameState &gs))
{
    this->action = action;
}

Action::Action()
{
    this->action = flee;
}
