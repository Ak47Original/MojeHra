#include <iostream>
using namespace std;

void fullHP()
{
    int HP, MaxHP, HealedHP, Utok, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    HealedHP = MaxHP - HP;
    HP = MaxHP;
}
int PlusMaxHP(int n)
{
    int HP, MaxHP, HealedHP, Utok, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    MaxHP = MaxHP + n;
}
int Heal(int n)
{
    int HP, MaxHP, HealedHP, Utok, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    HP = HP + n;
    HealedHP = n;
    if (HP > MaxHP)
    {
        HealedHP = MaxHP - HP;
        HP = MaxHP;
    }
}
string Monstr(int monstr)
{
    cout << "Potkal jsi " << monstr << endl;
}

void Village()
{
    int HP, MaxHP, HealedHP, Utok, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    cout << "Nasel jsi vesnici. Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
    cin >> action;
    if (action == 1)
    {
        cout << "Bude to stat 5 zlata. Chces doplnit zivoty?\n Ano (1)    Ne (0)\n";
        cin >> potvrzeni;
        if (potvrzeni == 1)
        {
            void fullHP();
            action = 0;
            cout << "Doplnil jsi zivotu a odesel z vesnice.";
        }
    }
    else
    {
        cout << "Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
    }
    if (action == 2)
    {
        cout << "Bude to stat 15 zlata. Chces dzvetsit pocet max zivotu?\n Ano (1)    Ne (0)\n";
        cin >> potvrzeni;
        if (potvrzeni == 1)
        {
            int PlusMaxHP(5);
            int Heal(5);
            action = 0;
            cout << "Doplnil jsi zivotu a odesel z vesnice.";
        }
    }
    else
    {
        cout << "Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
    }
}

void RandomRoom()
{
}
void ChooseDifficulty()
{
    int Difficulty;
    cout << "Vyber slozitost hry.\nLehka (0)\nStredni (1)\nTezka (2)\nUcitelska (3)\n";
    cin >> Difficulty;
}
void ChooseGameMode()
{
    int Gamemode;
    cout << "Vyber game mode.\nNormal (0)\nEndless (1)\nBoss Rush (2)\nTeacher (3)\n";
    cin >> Gamemode;
}
int ChooseClass()
{
    int Class;
    cout << "Vyber class.\nTank (0)      Archer (1)      Rogue (2)\nHP 5 3 4\nUtok 3 5 4\nMana 0 2 2\nVeci mec luk kynzal \n Schopnosti Kdyz ma stit mu�e odrazit utok. Zadna. Muze okradnout  ";
    cin >> Class;
    return Class;
}

int main()
{
    int HP, MaxHP, HealedHP, Utok, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
    ChooseGameMode();
    ChooseDifficulty();
    Class = ChooseClass();
}
