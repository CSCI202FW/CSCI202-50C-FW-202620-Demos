#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>

class character
{
public:
    character(std::string name, double hp, double mp, int strength, int dexterity, int intelligence, int speed, int endurance, int faith);
    std::string getName() const;
    double getHp() const;
    double getMp() const;
    int getStrength() const;
    int getDexterity() const;
    int getIntelligence() const;
    int getSpeed() const;
    int getEndurance() const;
    int getFaith() const;

    void setHp(double hp);
    void setMp(double mp);
    void setStrength(int strength);
    void setDexterity(int dexterity);
    void setIntelligence(int intelligence);
    void setSpeed(int speed);
    void setEndurance(int endurance);
    void setFaith(int faith);
    double attack();
    virtual std::string tostring();

protected:
    std::string name;
    double hp;
    double mp;
    int strength;
    int dexterity;
    int intelligence;
    int speed;
    int endurance;
    int faith;
};

class fighter : public character
{
public:
    fighter(std::string name);
    double strongAttack();
    std::string tostring();
};

class rogue : public character
{
public:
    rogue(std::string name);
    double steal();
    std::string tostring();
};

class magician : public character
{
public:
    magician(std::string name);
    double cast();
    std::string tostring();
};

class cleric : public character
{
public:
    cleric(std::string name);
    double heal();
    std::string tostring();
};

#endif