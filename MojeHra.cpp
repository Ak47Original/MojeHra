#include "rang/rang.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;



struct
{
    int HP, Damage, Armor, Mana, MaxHP, HealedHP, XP, MaxXP, Gold, Level, MaxMana, Class;
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
    int HP, Damage, Armor, Gold, Mana, XP, Level;
} Whispershade, SP, Blooddepth, Earthdevourer, Darkscale, Rockclaw, Gloomcrawler, Creepingshadow, Deepcry, Mudlurker, Stoneworm, Dustfiend, Toothhorn, Quartzglow, Riftmad, Rotnewt, Enemy, Enemy1, Enemy2, Enemy0;

struct
{
    string monstr;
    int HP, Damage, Armor, Gold, Mana, XP, Level, tah;
} Boss;

struct
{
    int PocetMonstru, HP, Dodge, end, XP;
}Logic;

// int HP, Damage, Armor, Gold, Mana;
void SetValues()
{
    Whispershade = {"Whispershade", 7, 2, 2, 20, 1, 1, 1};
    Blooddepth = {"Blooddepth", 11, 1, 1, 24, 2, 1, 1};
    Earthdevourer = {"Earthdevourer", 9, 2, 1, 23, 1, 1, 1};
    Darkscale = {"Darkscale", 8, 3, 0, 22, 3, 1, 1};
    Rockclaw = {"Rockclaw", 7, 1, 3, 22, 1, 1, 1};
    Creepingshadow = {"Creepingshadow", 18, 3, 1, 42, 6, 3, 1};
    Stoneworm = {"Stoneworm", 21, 4, 2, 45, 2, 3};
    Boss = {"SPIKETAIL", 30, 2, 3, 500, 0, 500, 10, 1};
    SP = {"SPIKETAIL", 30, 2, 3, 500, 0, 500, 10};
}

void Statistic()
{
    cout << rang::fgB::green << "HP: " << Player.HP << "/" << Player.MaxHP << endl << rang::style::reset;
    cout << rang::fgB::red << "Útok: " << Player.Damage << endl << rang::style::reset;
    cout << rang::fgB::blue << "Mana: " << Player.Mana << "/" << Player.MaxMana << endl << rang::style::reset;
    cout << rang::fgB::yellow << "Gold: " << Player.Gold << endl << rang::style::reset;
    cout << rang::fgB::cyan << "Level: " << Player.Level << endl << rang::style::reset;
    cout << rang::fgB::cyan << "XP: " << Player.XP << "/" << Player.MaxXP << endl << rang::style::reset;
}

void BattleStatistic()
{
    cout << rang::fgB::green << "HP: " << Player.HP << "/" << Player.MaxHP << endl << rang::style::reset;
    cout << rang::fgB::red << "Útok: " << Player.Damage << endl << rang::style::reset;
    cout << rang::fgB::blue << "Mana: " << Player.Mana << "/" << Player.MaxMana << endl << rang::style::reset;
}

void CheckHP()
{
    if (Player.HP <= 0)
    {
        cout << "Ty zemřel!\n";
        exit(0);
    }
}

int PlusMaxHP(int n)
{
    Player.MaxHP = Player.MaxHP + n;
}

int PlusMaxMana(int n)
{
    Player.MaxMana = Player.MaxMana + n;
}

int RegenMana(int n)
{
    if ((Player.Mana + n) > Player.MaxMana)
    {
        Player.Mana = Player.MaxMana;
    }
    else
    {
        Player.Mana = Player.Mana + n;
    }
}

int Heal1(int n)
{
    if ((Player.HP + n) > Player.MaxHP)
    {
        Player.HP = Player.MaxHP;
    }
    else
    {
        Player.HP = Player.HP + n;
    }
}

void Heal()
{
    if (Player.Mana < 3)
    {
        cout << "Nemaš dost many.\n";
    }
    else
    {
        Logic.end = 1;
        if ((Player.HP * 1.25) > Player.MaxHP)
        {
            Player.HealedHP = Player.MaxHP - Player.HP;
            Player.HP = Player.MaxHP;
        }
        else
        {
            Player.HP = Player.HP * 1.25;
            Player.HealedHP = Player.HP * 0.25;
        }
        cout << "Vyléčil jsi " << Player.HealedHP << "HP.\n";
        Player.Mana = Player.Mana - 3;
    }
}

void PlayerAttack()
{
    int Choice;
    Logic.end = 1;
    switch (Logic.PocetMonstru)
    {
    case 1:
        Logic.HP = Enemy.HP;
        Enemy.HP = Enemy.HP - (Player.Damage - Enemy.Armor);
        if (Logic.HP <= Enemy.HP)
        {
            Enemy.HP--;
            cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
        }
        else
        {
            cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage - Enemy.Armor) << " zranění.\n";
        }
        break;
    case 2:
        cout << "Na koho budeš utočit\n1. " << rang::fgB::green << Enemy.monstr << "(" << Enemy.HP << ")\n" << rang::style::reset;
        cout << "2. " << rang::fgB::green << Enemy1.monstr << "(" << Enemy1.HP << ")\n" << rang::style::reset;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            Logic.HP = Enemy.HP;
            Enemy.HP = Enemy.HP - (Player.Damage - Enemy.Armor);
            if (Logic.HP <= Enemy.HP)
            {
                Enemy.HP--;
                cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage - Enemy.Armor) << " zranění.\n";
            }
            break;
        case 2:
            Logic.HP = Enemy1.HP;
            Enemy1.HP = Enemy1.HP - (Player.Damage - Enemy1.Armor);
            if (Logic.HP <= Enemy1.HP)
            {
                Enemy1.HP--;
                cout << "Útočíš na " << Enemy1.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy1.monstr << ". Dostává " << (Player.Damage - Enemy1.Armor) << " zranění.\n";
            }
            break;
        }
        break;
    case 3:
        cout << "Na koho budeš utočit\n1. " << rang::fgB::green << Enemy.monstr << "(" << Enemy.HP << ")\n" << rang::style::reset;
        cout << "2. " << rang::fgB::green << Enemy1.monstr << "(" << Enemy1.HP << ")\n" << rang::style::reset;
        cout << "3. " << rang::fgB::green << Enemy2.monstr << "(" << Enemy2.HP << ")\n" << rang::style::reset;
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            Logic.HP = Enemy.HP;
            Enemy.HP = Enemy.HP - (Player.Damage - Enemy.Armor);
            if (Logic.HP <= Enemy.HP)
            {
                Enemy.HP--;
                cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage - Enemy.Armor) << " zranění.\n";
            }
            break;
        case 2:
            Logic.HP = Enemy1.HP;
            Enemy1.HP = Enemy1.HP - (Player.Damage - Enemy1.Armor);
            if (Logic.HP <= Enemy1.HP)
            {
                Enemy1.HP--;
                cout << "Útočíš na " << Enemy1.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy1.monstr << ". Dostává " << (Player.Damage - Enemy1.Armor) << " zranění.\n";
            }
            break;
        case 3:
            Logic.HP = Enemy2.HP;
            Enemy2.HP = Enemy2.HP - (Player.Damage - Enemy2.Armor);
            if (Logic.HP <= Enemy2.HP)
            {
                Enemy2.HP--;
                cout << "Útočíš na " << Enemy2.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy2.monstr << ". Dostává " << (Player.Damage - Enemy2.Armor) << " zranění.\n";
            }
            break;
        }
        break;
    }
}

void MagicAttack()
{
    int Choice;
    if (Player.Mana < 2)
    {
        cout << "Nemáš dost many.\n";
    }
    else
    {
        Logic.end = 1;
        switch (Logic.PocetMonstru)
        {
        case 1:
            Logic.HP = Enemy.HP;
            Enemy.HP = Enemy.HP - (Player.Damage * 2 - Enemy.Armor);
            if (Logic.HP <= Enemy.HP)
            {
                Enemy.HP--;
                cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
            }
            else
            {
                cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage * 2 - Enemy.Armor) << " zranění.\n";
            }
            break;
        case 2:
            cout << "Na koho budeš utočit\n1. " << rang::fgB::green << Enemy.monstr << "(" << Enemy.HP << ")\n" << rang::style::reset;
            cout << "2. " << rang::fgB::green << Enemy1.monstr << "(" << Enemy1.HP << ")\n" << rang::style::reset;
            cin >> Choice;
            switch (Choice)
            {
            case 1:
                Logic.HP = Enemy.HP;
                Enemy.HP = Enemy.HP - (Player.Damage * 2 - Enemy.Armor);
                if (Logic.HP <= Enemy.HP)
                {
                    Enemy.HP--;
                    cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
                }
                else
                {
                    cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage * 2 - Enemy.Armor) << " zranění.\n";
                }
                break;
            case 2:
                Logic.HP = Enemy1.HP;
                Enemy1.HP = Enemy1.HP - (Player.Damage * 2 - Enemy1.Armor);
                if (Logic.HP <= Enemy1.HP)
                {
                    Enemy1.HP--;
                    cout << "Útočíš na " << Enemy1.monstr << ". Dostává 1 zranění.\n";
                }
                else
                {
                    cout << "Útočíš na " << Enemy1.monstr << ". Dostává " << (Player.Damage * 2 - Enemy1.Armor) << " zranění.\n";
                }
                break;
            }
            break;
        case 3:
            cout << "Na koho budeš utočit\n1. " << rang::fgB::green << Enemy.monstr << "(" << Enemy.HP << ")\n"<< rang::style::reset;
            cout << "2. " << rang::fgB::green << Enemy1.monstr << "(" << Enemy1.HP << ")\n"<< rang::style::reset;
            cout << "3. " << rang::fgB::green << Enemy2.monstr << "(" << Enemy2.HP << ")\n"<< rang::style::reset;
            cin >> Choice;
            switch (Choice)
            {
            case 1:
                Logic.HP = Enemy.HP;
                Enemy.HP = Enemy.HP - (Player.Damage * 2 - Enemy.Armor);
                if (Logic.HP <= Enemy.HP)
                {
                    Enemy.HP--;
                    cout << "Útočíš na " << Enemy.monstr << ". Dostává 1 zranění.\n";
                }
                else
                {
                    cout << "Útočíš na " << Enemy.monstr << ". Dostává " << (Player.Damage * 2 - Enemy.Armor) << " zranění.\n";
                }
                break;
            case 2:
                Logic.HP = Enemy1.HP;
                Enemy1.HP = Enemy1.HP - (Player.Damage * 2 - Enemy1.Armor);
                if (Logic.HP <= Enemy1.HP)
                {
                    Enemy1.HP--;
                    cout << "Útočíš na " << Enemy1.monstr << ". Dostává 1 zranění.\n";
                }
                else
                {
                    cout << "Útočíš na " << Enemy1.monstr << ". Dostává " << (Player.Damage * 2 - Enemy1.Armor) << " zranění.\n";
                }
                break;
            case 3:
                Logic.HP = Enemy2.HP;
                Enemy2.HP = Enemy2.HP - (Player.Damage * 2 - Enemy2.Armor);
                if (Logic.HP <= Enemy2.HP)
                {
                    Enemy2.HP--;
                    cout << "Útočíš na " << Enemy2.monstr << ". Dostává 1 zranění.\n";
                }
                else
                {
                    cout << "Útočíš na " << Enemy2.monstr << ". Dostává " << (Player.Damage * 2 - Enemy2.Armor) << " zranění.\n";
                }
                break;
            }
            break;
        }
        Player.Mana = Player.Mana - 2;
    }
}

void EnemyAttack()
{
    srand(time(0));
    int a = rand() % 2;
    if (Enemy.HP > 0){
        if (a == 0)
        {
            Logic.HP = Player.HP;
            Player.HP = Player.HP - (Enemy.Damage - Player.Armor);
            cout << Enemy.monstr << " utoči na tebe\n";
            if (Logic.HP <= Player.HP)
            {
                Player.HP--;
                cout << "Dostáváš 1 zranění.\n";
            }
            else
            {
                cout << "Dostáváš " << (Enemy.Damage - Player.Armor) << " zranění.\n";
            }
            CheckHP();
        }
        else
        {
            cout << "Uhnul jsi od " << Enemy.monstr << " utoku.\n";
        }
    }
}

void EnemyAttack1()
{
    srand(time(0));
    int a = rand() % 2;
    if (Enemy1.HP > 0)
    {
        if (a == 0)
        {
            Logic.HP = Player.HP;
            Player.HP = Player.HP - (Enemy1.Damage - Player.Armor);
            cout << Enemy1.monstr << " utoči na tebe\n";
            if (Logic.HP <= Player.HP)
            {
                Player.HP--;
                cout << "Dostáváš 1 zranění.\n";
            }
            else
            {
                cout << "Dostáváš " << (Enemy1.Damage - Player.Armor) << " zranění.\n";
            }
            CheckHP();
        }
        else
        {
            cout << "Uhnul jsi od " << Enemy1.monstr << " utoku.\n";
        }
    }
}

void EnemyAttack2()
{
    srand(time(0));
    int a = rand() % 2;
    if (Enemy2.HP > 0)
    {
        if (a == 1)
        {
            Logic.HP = Player.HP;
            Player.HP = Player.HP - (Enemy2.Damage - Player.Armor);
            cout << Enemy2.monstr << " utoči na tebe\n";
            if (Logic.HP <= Player.HP)
            {
                Player.HP--;
                cout << "Dostáváš 1 zranění.\n";
            }
            else
            {
                cout << "Dostáváš " << (Enemy2.Damage - Player.Armor) << " zranění.\n";
            }
            CheckHP();
        }
        else
        {
            cout << "Uhnul jsi od " << Enemy2.monstr << " utoku.\n";
        }
    }
}

void SpiketailAttack()
{
    Logic.Dodge = 0;
    srand(time(0));
    int a = rand() % 2;
    Logic.HP = Player.HP;
    if (a == 0)
    {
        if (Logic.Dodge == 0){
            if (Boss.tah < 4 && Boss.tah > 0)
            {
                Player.HP = Player.HP - (Boss.Damage * pow(2, (Boss.tah - 1)) - Player.Armor);
                if (Logic.HP <= Player.HP)
                {
                    Player.HP--;
                    cout << "Dostáváš 1 zranění.\n";
                }
                else
                {
                    cout << "Dostáváš " << (Boss.Damage * pow(2, (Boss.tah - 1)) - Player.Armor) << " zranění.\n";
                }
                Boss.tah++;
            }
            if (Boss.tah == 4)
            {
                Player.HP = Player.HP - Boss.Damage;
                Boss.tah = 1;
                cout << "Dostáváš " << Boss.Damage << " zranění.\n";
            }
            CheckHP();
        }
        else
        {
            Player.HP = Player.HP - (Boss.Damage * 2 - Player.Armor);

            if (Logic.HP <= Player.HP)
            {
                Player.HP--;
                cout << "Dostáváš 1 zranění.\n";
            }
            else
            {
                cout << "Dostáváš " << (Boss.Damage * pow(2, (Boss.tah - 1)) - Player.Armor) << " zranění.\n";
            }
            Boss.tah++;
        }
    }
    else
    {
        cout << "Uhnul jsi od " << Boss.monstr << " utoku.\n";
        Boss.tah = 1;
        Logic.Dodge = 1;
    }
}

void LevelUp()
{
    Player.XP = Player.XP - Player.MaxXP;
    Player.Level++;
    Player.MaxXP = Player.MaxXP + Logic.XP;
    Logic.XP = Player.MaxXP - Logic.XP;
    Player.MaxHP++;
    Player.HP++;
    Player.Damage++;
    Player.Mana++;
    Player.MaxMana++;
    cout << "Dosahl jsi levelu " << Player.Level << ".\n";
    Statistic();
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
        srand(time(0));
        int b = rand() % Enemy.Gold + 1;
        Player.Gold = Player.Gold + b;
        cout << "Dostavaš " << b << " zlata, " << Enemy.XP << " zkušenosti a jdeš dal.\n";
        Player.XP = Player.XP + Enemy.XP;
    }
    if (Player.XP >= Player.MaxXP){
        LevelUp();
    }
}

void EnemyDie1()
{
    cout << "Monstrum zemřel.\n";
    srand(time(0));
    int a = rand() % 10 + 1;
    if (a <= 5)
    {
        cout << "Dostavaš " << Enemy1.XP << " zkušenosti a jdeš dal.\n";
        Player.XP = Player.XP + Enemy1.XP;
    }
    else if (a > 5)
    {
        srand(time(0));
        int b = rand() % Enemy1.Gold + 1;
        Player.Gold = Player.Gold + b;
        cout << "Dostavaš " << b << " zlata, " << Enemy1.XP << " zkušenosti a jdeš dal.\n";
    }
    if (Player.XP > Player.MaxXP)
    {
        LevelUp();
    }
}

void EnemyDie2()
{
    cout << "Monstrum zemřel.\n";
    srand(time(0));
    int a = rand() % 10 + 1;
    if (a <= 5)
    {
        cout << "Dostavaš " << Enemy2.XP << " zkušenosti a jdeš dal.\n";
        Player.XP = Player.XP + Enemy2.XP;
    }
    else if (a > 5)
    {
        srand(time(0));
        int b = rand() % Enemy2.Gold + 1;
        Player.Gold = Player.Gold + b;
        cout << "Dostavaš " << b << " zlata, " << Enemy2.XP << " zkušenosti a jdeš dal.\n";
    }
    if (Player.XP > Player.MaxXP)
    {
        LevelUp();
    }
}

void Monstr(){
    Logic.PocetMonstru = 1;
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
    int Choice;
    cout << "Potkal jsi " << Enemy.monstr << ".\n";
    while (Enemy.HP > 0) {
        Logic.end = 0;
        while (Logic.end == 0)
        {
            BattleStatistic();
            cout << "Můžeš zaútočit na monstrum (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            system("cls");
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }
        }
            EnemyAttack();
        }
    EnemyDie();
}

void Miniboss1()
{
    Logic.PocetMonstru = 1;
    Enemy = Creepingshadow;
    int Choice;
    int end = 0;
    cout << "Potkal jsi minibossa " << Enemy.monstr << ".\n";
    while (Enemy.HP > 0)
    {
        EnemyAttack();
        Logic.end = 0;
        while (Logic.end == 0)
        {
            BattleStatistic();
            cout << "Můžeš zaútočit na minibossa (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }
        }
            system("cls");
        }
    EnemyDie();
}

void Miniboss2()
{
    Logic.PocetMonstru = 1;
    Enemy = Stoneworm;
    int Choice;
    int end = 0;
    cout << "Potkal jsi minibossa " << Enemy.monstr << ".\n";
    while (Enemy.HP > 0)
    {
        EnemyAttack();
        Logic.end = 0;
        while (Logic.end == 0)
        {
            BattleStatistic();
            cout << "Můžeš zaútočit na minibossa (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }
        }
        system("cls");
    }
    EnemyDie();
}

void TwoMonstrs(){
    int Reward1 = 0;
    Logic.PocetMonstru = 2;
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
    srand(time(0));
    int b = rand() % 10 + 1;
    switch (b)
    {
    case 1:
        Enemy1 = Whispershade;
        break;
    case 2:
        Enemy1 = Whispershade;
        break;
    case 3:
        Enemy1 = Blooddepth;
        break;
    case 4:
        Enemy1 = Blooddepth;
        break;
    case 5:
        Enemy1 = Earthdevourer;
        break;
    case 6:
        Enemy1 = Earthdevourer;
        break;
    case 7:
        Enemy1 = Darkscale;
        break;
    case 8:
        Enemy1 = Darkscale;
        break;
    case 9:
        Enemy1 = Rockclaw;
        break;
    case 10:
        Enemy1 = Rockclaw;
        break;
    }
    cout << "Potkal jsi " << Enemy.monstr << " a " << Enemy1.monstr << ".\n";
    while (Enemy.HP > 0 || Enemy1.HP > 1)
    {
        Logic.end = 0;
        while (Logic.end == 0)
        {
            BattleStatistic();
            cout << "Můžeš zaútočit na monstrum (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            system("cls");
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }
        }
        if (Enemy.HP <= 0)
        {
            EnemyDie();
            Logic.PocetMonstru = 1;
            if (Enemy1.HP > 0){
                Enemy0 = Enemy;
                Enemy = Enemy1;
                Enemy1 = Enemy0;
                Reward1 = 1;
            }
        }

        if (Enemy1.HP <= 0 && Reward1 == 0)
        {
            EnemyDie1();
            Logic.PocetMonstru = 1;
        }
        EnemyAttack();
        EnemyAttack1();
    }
}

void ThreeMonstrs()
{
    int Reward, Reward1, Reward2;
    Reward = Reward1 = Reward2 = 0;
    Logic.PocetMonstru = 3;
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
    srand(time(0));
    int b = rand() % 5 + 1;
    switch (b)
    {
    case 1:
        Enemy1 = Whispershade;
        break;
    case 2:
        Enemy1 = Whispershade;
        break;
    case 3:
        Enemy1 = Blooddepth;
        break;
    case 4:
        Enemy1 = Blooddepth;
        break;
    case 5:
        Enemy1 = Earthdevourer;
        break;
    case 6:
        Enemy1 = Earthdevourer;
        break;
    case 7:
        Enemy1 = Darkscale;
        break;
    case 8:
        Enemy1 = Darkscale;
        break;
    case 9:
        Enemy1 = Rockclaw;
        break;
    case 10:
        Enemy1 = Rockclaw;
        break;
    }
    srand(time(0));
    int c = rand() % 5 + 1;
    switch (c)
    {
    case 1:
        Enemy2 = Whispershade;
        break;
    case 2:
        Enemy2 = Whispershade;
        break;
    case 3:
        Enemy2 = Whispershade;
        break;
    case 4:
        Enemy2 = Blooddepth;
        break;
    case 5:
        Enemy2 = Blooddepth;
        break;
    case 6:
        Enemy2 = Blooddepth;
        break;
    case 7:
        Enemy2 = Earthdevourer;
        break;
    case 8:
        Enemy2 = Earthdevourer;
        break;
    case 9:
        Enemy2 = Earthdevourer;
        break;
    case 10:
        Enemy2 = Darkscale;
        break;
    case 11:
        Enemy2 = Darkscale;
        break;
    case 12:
        Enemy2 = Darkscale;
        break;
    case 13:
        Enemy2 = Rockclaw;
        break;
    case 14:
        Enemy2 = Rockclaw;
        break;
    case 15:
        Enemy2 = Rockclaw;
        break;
    }
    cout << "Potkal jsi " << Enemy.monstr << ", " << Enemy1.monstr << " a " << Enemy2.monstr << ".\n";
    while (Enemy.HP > 0 || Enemy1.HP > 0 || Enemy2.HP > 0)
    {
        Logic.end = 0;
        while (Logic.end == 0)
        {
            BattleStatistic();
            cout << "Můžeš zaútočit na monstrum (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            system("cls");
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }
        }
            if (Enemy.HP <= 0)
            {
                EnemyDie();
                Logic.PocetMonstru--;
                if (Enemy1.HP >= 0 && Enemy2.HP >= 0)
                {
                    Enemy0 = Enemy;
                    Enemy = Enemy1;
                    Enemy1 = Enemy2;
                    Enemy2 = Enemy0;
                    Reward2 = 1;
                }
                else{
                    if (Enemy1.HP > 0){
                        Enemy0 = Enemy;
                        Enemy = Enemy1;
                        Enemy1 = Enemy0;
                        Reward1 = 1;
                    }
                    else{
                        if (Enemy2.HP > 0){
                            Enemy0 = Enemy;
                            Enemy = Enemy2;
                            Enemy2 = Enemy0;
                            Reward2 = 1;
                        }
                        else{

                        }
                    }
                }
        }
        else{
            if (Enemy1.HP <= 0)
            {
                EnemyDie1();
                Logic.PocetMonstru--;
                Reward1 = 1;
                if (Enemy2.HP > 0){
                    Enemy0 = Enemy1;
                    Enemy1 = Enemy2;
                    Enemy2 = Enemy0;
                    Reward1 = 0;
                }
            }
            if (Enemy2.HP <= 0 && Reward2 == 0)
            {
                EnemyDie2();
                Logic.PocetMonstru--;
                Reward = 1;
            }
        }
        EnemyAttack();
        EnemyAttack1();
        EnemyAttack2();
        }
}
/*
void Spiketail(){
    int Choice, Choice1;
    Enemy.monstr = "Hlavni boss";
    Enemy.HP = 50;
    Enemy.Damage = 3;
    int end = 0;
    cout << "Potkal jsi hlavniho bossa Spiketaila. Můžeš zaútočit na monstrum (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
    cin >> Choice;
    switch (Choice)
    {
    case 0:
        PlayerAttack();
        while (end == 0 && Enemy.HP > 0)
        {
            cout << "Monstrum ještě žije. Útočí na tebe. ";
            SpiketailAttack();
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
        Heal();
        break;
    }
}
*/

void Spiketail()
{
    Logic.PocetMonstru = 1;
    Enemy = SP;
    int Choice;
    int end = 0;
    Spiketail;
    cout << "Potkal jsi hlavniho bossa SPIKETAILA.\n";
    while (Boss.HP > 0)
    {
        SpiketailAttack();


            BattleStatistic();
            cout << "Můžeš zaútočit na SPIKETAILA (0), zaútočit pomocí many (1) nebo vyléčit se (2).\n";
            cin >> Choice;
            system("cls");
            switch (Choice)
            {
            case 0:
                PlayerAttack();
                break;
            case 1:
                MagicAttack();
                break;
            case 2:
                Heal();
                break;
            }

    }
    cout << "Porazil jsi SPIKETAILA!\nKONEC!";
    exit(0);
}

void Village(){
int action, potvrzeni, end;
potvrzeni = end = 0;
cout << "Našel jsi vesnici.\n";
while (end == 0){

cout << "Mužes doplnit životy a manu (1), zvětšit počet max životu (2), zvětšit počet max many (3), zvětšit utok (4) odejit z vesnice (5).\n";
Statistic();
cin >> action;
system("cls");
switch (action){
case 1:
cout << "Bude to stat 5 zlata. Chceš doplnit životy?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        if (Player.Gold >= 5){
            void fullHP();
            action = 0;
            cout << "Doplnil jsi životy a manu.\n";
            Player.Gold = Player.Gold - 5;
        } else {
            cout << "Nemáš dost zlata.\n";
        }
    }
    break;
case 2:
    cout << "Bude to stat 15 zlata. Chces zvětšit počet max životu?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        if (Player.Gold >= 15)
        {
            int PlusMaxHP(5);
            int Heal1(5);
            action = 0;
            cout << "Zvětšil jsi max životy o 5.\n";
            Player.Gold = Player.Gold - 15;
        } else {
            cout << "Nemáš dost zlata.\n";
        }
    }
    break;
case 3:
    cout << "Bude to stat 15 zlata. Chceš zvětšit počet max many?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        if (Player.Gold >= 15){

            int PlusMaxMana(3);
            int RegenMana(3);
            action = 0;
            cout << "Zvětšil jsi max manu o 3.\n";
            Player.Gold = Player.Gold - 15;
        } else {
            cout << "Nemáš dost zlata.\n";
        }
    }
    break;
case 4:
    cout << "Bude to stat 15 zlata. Chceš zvětšit utok?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1)
    {
        if (Player.Gold >= 15)
        {
            Player.Damage = Player.Damage + 3;
            action = 0;
            cout << "Zvětšil jsi utok o 3.\n";
            Player.Gold = Player.Gold - 15;
        }
        else
        {
            cout << "Nemáš dost zlata.\n";
        }
    }
    break;
case 5:
    cout << "Odešel jsi z vesnice.\n";
    end = 1;
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
    system("cls");
}
void ChooseGameMode()
{
    int Gamemode;
    cout << "Vyber game mode.\nNormal (0)\nEndless (1)\nBoss Rush (2)\n";
    cin >> Gamemode;
    system("cls");
}
void ChooseClass()
{
    int potvrzeni;
    while(potvrzeni != 1){
    cout << "Vyber class.\n";
    cout << "Tank (0)\nArcher (1)\nRogue (2)\nMage (3)\n";
    cin >> Player.Class;
    system("cls");
    switch (Player.Class)
    {
    case 0:
        cout << setw(5) << "Tank\n" << rang::style::reset;
        cout << rang::fgB::green << "HP: 30\n" << rang::style::reset;
        cout << rang::fgB::red << "Útok: 3\n" << rang::style::reset;
        cout << rang::fgB::blue << "Mana: 3\n" << rang::style::reset;
        cout << rang::fgB::magenta << "Brnění: 2\n" << rang::style::reset;
        cout << "Chceš vybrat tento class? (1/0)\n";
        cin >> potvrzeni;
        break;
    case 1:
        cout << setw(5) << "Archer\n" << rang::style::reset;
        cout << rang::fgB::green << "HP: 24\n" << rang::style::reset;
        cout << rang::fgB::red << "Útok: 5\n" << rang::style::reset;
        cout << rang::fgB::blue << "Mana: 6\n" << rang::style::reset;
        cout << rang::fgB::magenta << "Brnění: 0\n" << rang::style::reset;
        cout << "Chceš vybrat tento class? (1/0)\n";
        cin >> potvrzeni;
        break;
    case 2:
        cout << setw(5) << "Rogue\n" << rang::style::reset;
        cout << rang::fgB::green << "HP: 26\n" << rang::style::reset;
        cout << rang::fgB::red << "Útok: 4\n" << rang::style::reset;
        cout << rang::fgB::blue << "Mana: 6\n" << rang::style::reset;
        cout << rang::fgB::magenta << "Brnění: 1\n" << rang::style::reset;
        cout << "Chceš vybrat tento class? (1/0)\n";
        cin >> potvrzeni;
        break;
    case 3:
        cout << setw(5) << "Mage\n"<< rang::style::reset;
        cout << rang::fgB::green << "HP: 18\n"<< rang::style::reset;
        cout << rang::fgB::red << "Útok: 6\n"<< rang::style::reset;
        cout << rang::fgB::blue << "Mana: 10\n"<< rang::style::reset;
        cout << rang::fgB::magenta << "Brnění: 0\n"<< rang::style::reset;
        cout << "Chceš vybrat tento class? (1/0)\n";
        cin >> potvrzeni;
        break;
    }
    system("cls");
    }
    switch (Player.Class)
    {
    case 0:
        Player = {30, 3, 2, 3};
        break;
    case 1:
        Player = {24, 5, 0, 6};
        break;
    case 2:
        Player = {26, 4, 1, 6};
        break;
    case 3:
        Player = {18, 6, 0, 10};
        break;
    }
    Player.MaxHP = Player.HP;
    Player.MaxMana = Player.Mana;
    Player.Level = 1;
    Player.MaxXP = 1;
    Logic.XP = 1;
}



int main(){
    ChooseClass();
    SetValues();
    cout << "Ty vstupuješ do podzemí. Po pěti minutách chůze potkáš monstra. Nezbývá ti nic jiného než bojovat na život a na smrt.\n";
    Monstr();
    TwoMonstrs();
    Village();
    Miniboss1();
    Village();
    Monstr();
    TwoMonstrs();
    TwoMonstrs();
    Village();
    Miniboss2();
    TwoMonstrs();
    TwoMonstrs();
    TwoMonstrs();
    Village();
    TwoMonstrs();
    Spiketail();

}

