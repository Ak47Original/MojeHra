#include <iostream>
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
string Monstr(monstr){
cout << "Potkal jsi " << monstr << endl;
}

void Village(){
cout << "Nasel jsi vesnici. Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
cin >> action;
if (action == 1){
    cout << "Bude to stat 5 zlata. Chces doplnit zivoty?\n Ano (1)    Ne (0)\n";
    cin >> potvrzeni;
    if (potvrzeni == 1){
        void fullHP();
        action = 0;
        cout << "Doplnil jsi " << << "zivotu a odesel z vesnice."
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
        cout << "Doplnil jsi " << << "zivotu a odesel z vesnice."
    }
} else {
cout << "Muzes doplnit zivoty (1), zvetsit pocet max zivotu (2), zvetsit pocet max many (3), zvetsit utok (4) odejit z vesnice (5).\n";
}
}



*/
void RandomRoom()
{
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
int ChooseClass()
{
    int Class;
    cout << "Vyber class.\nTank (0)      Archer (1)      Rogue (2)\nHP 5 3 4\nUtok 3 5 4\nMana 0 2 2\nVěci meč luk dýka\n";
    cin >> Class;
    return Class;
}
int EnemyAttack(int MonstrType)
{
    int n;
    switch (MonstrType)
    {
    case 0:
        n = 1;
        break;
    case 1:
        n = 2;
        break;
    case 2:
        n = 3;
        break;
    }
    return n;
}

int main()
{
    int HP, MaxHP, HealedHP, Utok, EnemyHP, Choice, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
    ChooseGameMode();
    ChooseDifficulty();
    Class = ChooseClass();
    switch (Class)
    {
    case 0:
        MaxHP = HP = 5;
        Utok = 3;
        Mana = 0;
        Inventory[0] = "mec";
        break;
    case 1:
        MaxHP = HP = 3;
        Utok = 5;
        Mana = 2;
        Inventory[0] = "luk";
        break;
    case 2:
        MaxHP = HP = 4;
        Utok = 5;
        Mana = 2;
        Inventory[0] = "dyka";
        break;
    }
    cout << "Ty vstupuješ do podzemí. Po pěti minutách chůze potkáš monstra. Nezbývá ti nic jiného než bojovat na život a na smrt.\n";
    EnemyHP = 5;
    Damage = EnemyAttack(1);
    HP = HP - Damage;
    cout << "Monstrum na tebe útočí. Dostáváš " << Damage << " zranění.\nMůžeš zaútočit na monstrum (0) nebo utéct (1).\n";
    cin >> Choice;
    switch (Choice)
    {
    case 0:
        EnemyHP = EnemyHP - Utok;
        cout << "Zasadil jsi " << Utok << " zranění.";
        break;
    case 1:
        cout << "Utekl jsi z podzemí.";
        break;
    }
}
