#include <iostream>
#include <cstdlib>
#include <ctime>
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
    int HP, MaxHP, HealedHP, Damage, Choice, XP, Gold, Level, Mana, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
} Player;

struct
{
    int HP, Damage, Gold, XP, Level, Mana, action, potvrzeni, konecCyklu;
    string monstr;
} Enemy;
void PlayerAttack()
{
    Enemy.HP = Enemy.HP - Player.Damage;
    cout << "Útočíš na monstra. Dostává " << Player.Damage << " zranění.\n";
}
void EnemyAttack()
{
    Player.HP = Player.HP - Enemy.Damage;
    cout << "Dostáváš " << Enemy.Damage << " zranění.\nMůžeš zaútočit na monstrum (0) nebo utéct (1).\n";
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
}
void Monstr(){
    int Choice, Choice1;
    Enemy.monstr = "monstr";
    Enemy.HP = 10;
    Enemy.Damage = 1;
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

    cout << "Vyber class.\nTank (0)      Archer (1)      Rogue (2)\nHP 5 3 4\nUtok 3 5 4\nMana 0 2 2\nVěci meč luk dýka\n";
    cin >> Player.Class;
    switch (Player.Class)
    {
    case 0:
        Player.MaxHP = Player.HP = 5;
        Player.Damage = 3;
        Player.Mana = 0;
        Player.Inventory[0] = "mec";
        break;
    case 1:
        Player.MaxHP = Player.HP = 3;
        Player.Damage = 5;
        Player.Mana = 2;
        Player.Inventory[0] = "luk";
        break;
    case 2:
        Player.MaxHP = Player.HP = 4;
        Player.Damage = 5;
        Player.Mana = 2;
        Player.Inventory[0] = "dyka";
        break;
    }
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

int main(){
    int HP, MaxHP, HealedHP, Utok, EnemyHP, Choice, Damage, XP, Gold, PlusGold, Level, Mana, action, potvrzeni, konecCyklu, Difficulty, Gamemode, Class;
    string Inventory[5], Schopnosti[3];
    string Tank, Archer, Rogue;
    ChooseGameMode();
    ChooseDifficulty();
    ChooseClass();

    cout << "Ty vstupuješ do podzemí. Po pěti minutách chůze potkáš monstra. Nezbývá ti nic jiného než bojovat na život a na smrt.\n";
    Monstr();
    Village();

}

