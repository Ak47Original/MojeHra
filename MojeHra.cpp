#include "rang/rang.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*void fullHP(){
HealedHP = MaxHP - HP;
HP = MaxHP;

}
int PlusMaxHP (int n){
MaxHP = MaxHP + n;
}
int Heal(int n){
HP = HP + n;
HealedHP = n;
if (HP > MaxHP){
    HealedHP = MaxHP - HP;
    HP = MaxHP;
}
}
*/
struct
{
    int HP, Armor, MaxHP, HealedHP, Damage, XP, MaxXP, LogicXP, Gold, Level, Mana, MaxMana, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
} Player;

/*
struct
{
    int HP, Damage, Armor, Gold, Mana, Level, XP;
    string monstr;
} Enemy, Enemy1, Enemy2, Enemy3;
*/

struct {
    string monstr;
    int HP, Damage, Armor, Gold, Mana, Level, XP;
} Whispershade, Blooddepth, Earthdevourer, Darkscale, Rockclaw, Gloomcrawler, CreepingShadow, Deepcry, Mudlurker, Stoneworm, Dustfiend, Toothhorn, Quartzglow, Riftmad, Rotnewt, Enemy, Enemy1, Enemy2, Enemy3;


struct
{
    int HP, Damage, Gold, XP, Level, Mana, action, potvrzeni, konecCyklu;
    string monstr = "Miniboss";
}Miniboss;

// int HP, Damage, Armor, Gold, Mana;
void SetValues()
{
    Whispershade = {"whispershade", 7, 2, 2, 5, 1, 0};
    Blooddepth = {"blooddepth", 11, 1, 1, 7, 2, 1};
    Earthdevourer = {"earthdevourer", 9, 2, 1, 9, 1, 2};
    Darkscale = {"darkscale", 8, 3, 0, 14, 3, 3};
    Rockclaw = {"rockclaw", 7, 1, 3, 12, 1, 4};
}

void Statistic()
{
    cout << setw(12) << rang::fgB::green << "HP: " << Player.HP << "/" << Player.MaxHP << endl << rang::style::reset;
    cout << setw(12) << rang::fgB::red << "Útok: " << Player.Damage << endl << rang::style::reset;
    cout << setw(12) << rang::fgB::blue << "Mana: " << Player.Mana << "/" << Player.MaxMana << endl << rang::style::reset;
    cout << setw(12) << rang::fgB::yellow << "Gold: " << Player.Gold << endl << rang::style::reset;
    cout << rang::fgB::cyan << "XP: " << Player.XP << "/" << Player.MaxXP << endl << rang::style::reset;
    cout << rang::fgB::cyan << "Level: " << Player.Level << endl << rang::style::reset;
}

void PlayerAttack()
{
    Enemy.HP = Enemy.HP - (Player.Damage - Enemy.Armor);
    cout << "Útočíš na monstra. Dostává " << Player.Damage << " zranění.\n";
}
void EnemyAttack()
{
    Player.HP = Player.HP - Enemy.Damage;
    if (Player.HP <= 0) {
        cout << "Dostáváš " << Enemy.Damage << " zranění.\nZemřel jsi";
    }
    cout << "Dostáváš " << Enemy.Damage << " zranění.\nMůžeš zaútočit na monstrum (0) nebo utéct (1).\n";
}
void LevelUp()
{
    Player.XP = Player.XP - Player.MaxXP;
    Player.Level++;
    Player.MaxXP = Player.MaxXP + Player.LogicXP;
    Player.LogicXP = Player.MaxXP - Player.LogicXP;
    Player.MaxHP++;
    Player.HP++;
    Player.Damage++;
    Player.Mana++;
    Player.MaxMana++;
}
void EnemyDie()
{
    cout << "Monstrum zemřel.\n";
    srand(time(0));
    int a = rand() % 10 + 1;
    if (a <= 5)
    {
        cout << "Dostavaš " << Enemy.XP << " zkušenosti a jdeš dal.\n";
        Player.XP = Player.XP + Enemy.XP;
    }
    else if (a > 5)
    {
        Player.Gold = Player.Gold + Enemy.Gold;
        cout << "Dostavaš " << Enemy.Gold << " zlata, " << Enemy.XP << " zkušenosti a jdeš dal.\n";
    }
    if (Player.XP > Player.MaxXP){
        LevelUp();
    }
    }

void Monstr()
{
    srand(time(0));
    int a = rand() % 5 + 1;
    switch (a)
    {
    case 1:
        Enemy = Whispershade;
        break;
    case 2:
        Enemy = Blooddepth;
        break;
    case 3:
        Enemy = Earthdevourer;
        break;
    case 4:
        Enemy = Darkscale;
        break;
    case 5:
        Enemy = Rockclaw;
        break;
    }
    int Choice, Choice1;
    int end = 0;
    cout << "Potkal jsi " << Enemy.monstr << ". Můžeš zaútočit na monstrum (0) nebo utéct (1).\n";
    cin >> Choice;
    switch (Choice)
    {
    case 0:
        PlayerAttack();
        while (end == 0 && Enemy.HP > 0) {
            cout << "Monstrum ještě žije. Útočí na tebe. ";
            EnemyAttack();
            cin >> Choice1;
            switch (Choice1)
            {
            case 0:
                PlayerAttack();
                break;

            case 1:
                cout << "Utekl jsi od monstra jdeš dal.\n";
                end == 1;
                break;
            }
            }
        if (Enemy.HP <= 0){
            EnemyDie();
        }

        break;
    case 1:
        cout << "Utekl jsi od monstra jdeš dal.\n";

    }
}

void TwoMonstrs(){

}

void BossAttack(){
    int tah = 1;
    Enemy.Damage = Enemy.Damage * tah;
    tah++;
    if (tah > 4){
        tah = 1;
    }
    Player.HP = Player.HP - Enemy.Damage;
    if (Player.HP <= 0)
    {
        cout << "Dostáváš " << Enemy.Damage << " zranění.\nZemřel jsi";
    }
    cout << "Dostáváš " << Enemy.Damage << " zranění.\nMůžeš zaútočit na monstrum (0) nebo utéct (1).\n";
}

void Spiketail(){
    int Choice, Choice1;
    Enemy.monstr = "Hlavni boss";
    Enemy.HP = 50;
    Enemy.Damage = 3;
    int end = 0;
    cout << "Potkal jsi hlavniho bossa Spiketaila. Můžeš zaútočit na monstrum (0) nebo utéct (1).\n";
    cin >> Choice;
    switch (Choice)
    {
    case 0:
        PlayerAttack();
        while (end == 0 && Enemy.HP > 0)
        {
            cout << "Monstrum ještě žije. Útočí na tebe. ";
            EnemyAttack();
            cin >> Choice1;
            switch (Choice1)
            {
            case 0:
                PlayerAttack();
                break;

            case 1:
                cout << "Utekl jsi od monstra jdeš dal.\n";
                end == 1;
                break;
            }
        }
        if (Enemy.HP <= 0)
        {
            EnemyDie();
        }

        break;
    case 1:
        cout << "Utekl jsi od monstra jdeš dal.\n";
    }
}
void Village(){
int action, potvrzeni;
potvrzeni = 0;
while (potvrzeni == 0){
cout << "Nasel jsi vesnici. Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
cin >> action;
switch (action){
case 1:
cout << "Bude to stat 5 zlata. Chces doplnit zivoty?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        void fullHP();
        action = 0;
        cout << "Doplnil jsi " << "zivotu a odesel z vesnice.";
    }
    break;
case 2:
    cout << "Bude to stat 15 zlata. Chces zvetsit pocet max zivotu?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        int PlusMaxHP (5);
        int Heal (5);
        action = 0;
        cout << "Doplnil jsi " << "zivotu a odesel z vesnice.";
    }
    break;
case 3:
    cout << "Bude to stat 15 zlata. Chces zvetsit pocet max many?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1)
    {
        int PlusMaxHP(5);
        int Heal(5);
        action = 0;
        cout << "Doplnil jsi " << "many a odesel z vesnice.";
    }
    break;
}
}
}





void RandomRoom(){

}
void ChooseDifficulty()
{
    int Difficulty;
    cout << "Vyber slozitost hry.\nLehka (0)\nStredni (1)\nTezka (2)\nPro ucitele (3)\n";
    cin >> Difficulty;
}
void ChooseGameMode()
{
    int Gamemode;
    cout << "Vyber game mode.\nNormal (0)\nEndless (1)\nBoss Rush (2)\n";
    cin >> Gamemode;
}
void ChooseClass()
{

    cout << "Vyber class.\n";
    cout << setw(5) << "Tank (0)" << setw(10) << "Archer (1)" << setw(15) << "Rogue (2)\n" << rang::style::reset;
    cout << rang::fgB::green << "HP:" << setw(5) << "5" << setw(10) << "3" << setw(15) << "4\n" << rang::style::reset;
    cout << rang::fgB::red << "Útok:" << setw(5) << "3" << setw(10) << "5" << setw(15) << "4\n" << rang::style::reset;
    cout << rang::fgB::blue << "Mana:" << setw(5) << "0" << setw(10) << "2" << setw(15) << "2\n" << rang::style::reset;
    cout << rang::fgB::magenta << "Věci:" << setw(5) << "meč" << setw(10) << "luk" << setw(15) << "dýka\n" << rang::style::reset;
    cin >> Player.Class;
    switch (Player.Class)
    {
    case 0:
        Player.MaxHP = Player.HP = 5;
        Player.Damage = 3;
        Player.MaxMana = Player.Mana = 0;
        Player.Inventory[0] = "mec";
        break;
    case 1:
        Player.MaxHP = Player.HP = 3;
        Player.Damage = 5;
        Player.MaxMana = Player.Mana = 2;
        Player.Inventory[0] = "luk";
        break;
    case 2:
        Player.MaxHP = Player.HP = 4;
        Player.Damage = 5;
        Player.MaxMana = Player.Mana = 2;
        Player.Inventory[0] = "dyka";
        break;
    }
    Player.Level = 1;
    Player.MaxXP = 1;
    Player.LogicXP = 1;
}



int main(){
    int HP, MaxHP, HealedHP, Utok, EnemyHP, Choice, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
    ChooseGameMode();
    ChooseDifficulty();
    ChooseClass();
    SetValues();
    Statistic();
    cout << "Ty vstupuješ do podzemí. Po pěti minutách chůze potkáš monstra. Nezbývá ti nic jiného než bojovat na život a na smrt.\n";
    Monstr();
    Village();

}

