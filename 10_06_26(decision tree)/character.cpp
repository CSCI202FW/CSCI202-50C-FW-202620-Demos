#include "character.h"

character::character(std::string name, double hp, double mp, int strength, int dexterity, int intelligence, int speed, int endurance, int faith)
{
    this->name = name;
    this->hp = hp;
    this->mp = mp;
    this->strength = strength;
    this->dexterity = dexterity;
    this->intelligence = intelligence;
    this->speed = speed;
    this->endurance = endurance;
    this->faith = faith;
}

std::string character::getName() const
{
    return name;
}

double character::getHp() const
{
    return hp;
}

double character::getMp() const
{
    return mp;
}

int character::getStrength() const
{
    return strength;
}

int character::getDexterity() const
{
    return dexterity;
}

int character::getIntelligence() const
{
    return intelligence;
}

int character::getSpeed() const
{
    return speed;
}

int character::getEndurance() const
{
    return endurance;
}

int character::getFaith() const
{
    return faith;
}

void character::setHp(double hp)
{
    this->hp = hp;
}

void character::setMp(double mp)
{
    this->mp = mp;
}

void character::setStrength(int strength)
{
    this->strength = strength;
}

void character::setDexterity(int dexterity)
{
    this->dexterity = dexterity;
}

void character::setIntelligence(int intelligence)
{
    this->intelligence = intelligence;
}

void character::setSpeed(int speed)
{
    this->speed = speed;
}

void character::setEndurance(int endurance)
{
    this->endurance = endurance;
}

void character::setFaith(int faith)
{
    this->faith = faith;
}

double character::attack()
{
    return strength;
}

std::string character::tostring()
{
    std::ostringstream out;
    out << std::setprecision(2) << std::fixed << std::showpoint;
    // out << name << " stats:" << std::endl;
    out << "HP: " << hp << std::endl;
    out << "MP: " << mp << std::endl;
    out << "Strength: " << strength << std::endl;
    out << "Dexterity: " << dexterity << std::endl;
    out << "Intelligence: " << intelligence << std::endl;
    out << "Speed: " << speed << std::endl;
    out << "Endurance: " << endurance << std::endl;
    out << "Faith: " << faith << std::endl;
    out << std::endl;
    return out.str();
}

fighter::fighter(std::string name) : character(name, 300, 0, 16, 10, 5, 8, 15, 5)
{
}

double fighter::strongAttack()
{
    return strength + endurance;
}

std::string fighter::tostring()
{
    std::string out = name + " the Fighter stats:\n";
    out += character::tostring();
    return out;
}

rogue::rogue(std::string name) : character(name, 200, 0, 10, 16, 16, 15, 8, 5)
{
}

double rogue::steal()
{
    double h = dexterity + speed + intelligence;
    int randNum = 10 + rand() % (50 - 10 + 1);
    h = h * (randNum / 100.0);
    hp = hp + h;
    return h;
}

std::string rogue::tostring()
{
    std::string out = name + " the Rogue stats:\n";
    out += character::tostring();
    return out;
}

magician::magician(std::string name) : character(name, 250, 200, 5, 10, 16, 16, 5, 8)
{
}

double magician::cast()
{
    mp = mp - (intelligence + speed);
    return intelligence + speed;
}

std::string magician::tostring()
{
    std::string out = name + " the Magician stats:\n";
    out += character::tostring();
    return out;
}

cleric::cleric(std::string name) : character(name, 200, 200, 5, 10, 8, 16, 5, 16)
{
}

double cleric::heal()
{
    mp = mp - faith;
    return faith;
}

std::string cleric::tostring()
{
    std::string out = name + " the Cleric stats:\n";
    out += character::tostring();
    return out;
}
