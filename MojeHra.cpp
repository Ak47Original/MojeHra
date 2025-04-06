#include <iostream>
using namespace std;

void fullHP(){
    int HP, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
    HealedHP = MaxHP - HP;
    HP = MaxHP;

}
void PlusMaxHP (){
    int HP, n, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
    MaxHP = MaxHP + n;

}
void Heal(){
    int HP, n, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
    HP = HP + n;
    HealedHP = n;
    if (HP > MaxHP)
    {
        HealedHP = MaxHP - HP;
        HP = MaxHP;
    }

}
void Monstr(){
    string monstr;
cout << "Potkal jsi " << monstr << endl;
}

void Village(){
    int HP, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
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
            cout << "Doplnil jsi "<< HealedHP << "zivotu a odesel z vesnice.";
        }
} else {
cout << "Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
}
if (action == 2){
    cout << "Bude to stat 15 zlata. Chces dzvetsit pocet max zivotu?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        int PlusMaxHP (5);
        int Heal (5);
        action = 0;
        cout << "Doplnil jsi " << HealedHP << "zivotu a odesel z vesnice.";
    }
} else {
cout << "Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
}
}




void RandomRoom(){
}
void ChooseDifficulty(){
    int HP, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
    cout << "Vyber slozitost hry.\nLehka (0)\nStredni (1)\nTezka (2)\nUcitelska (3)";
    cin >> Difficulty;
}
void ChooseGameMode(){
    int HP, MaxHP, HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
    string Tank, Archer, Rogue;
    cout << "Vyber game mode.\nNormal (0)\nEndless (1)\nBoss Rush (2)Teacher (3)";
    cin >> Gamemode;

}
void ChooseClass(){
}

int main(){
int HP, MaxHP,HealedHP, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode;
string Tank, Archer, Rogue;
ChooseGameMode();

}
