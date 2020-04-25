#include "Game.h"

Game::Game() //constructeur de la classe
{
    puzzle.generatePhrase();
    srand (time(NULL));
    Current_Player = rand()%2;
}
void Game::choix() //fixer le mode du jeu
{
    string mode1;
    cout << "type the mode number : ";
    cin >> mode1;

    while(!(mode1=="1" || mode1== "2"|| mode1=="3"))    { //choisir l'un des modes proposé
        cout << "Retype the mode number : ";
        cin >> mode1;
    }
    mode = mode1;
}
void Game::resoudre() //essayer de resoudre le puzzle
{
    string mot;
    cout << "Guess the word : ";
    cin >> mot;
    while(mot.size()!=puzzle.phrase.size()) //verifier la longueur du mot proposé
    {
        cout << "the word length does not match up, retype your guess : ";
        cin >> mot;
    }
    puzzle.afficherCaractere(mot);
    if(puzzle.phraseChiffree==puzzle.phrase) //vérification de la solution proposée
    {
        cout << players[Current_Player].getNom() <<" won the game" <<endl;
        cout << "the word to guess was : " << puzzle.phrase <<endl;
        puzzle.generatePhrase();
    }
    else
    {
        cout << "your guess is wrong" <<endl;
    }
}
int Game::buyVoyelle() // acheter un voyelle
{
    string voyelle ="AEIUOYaeiuoy";
    char voy;
    bool checkInput = false;
    if(players[Current_Player].getArgent()>=300)
    {
        players[Current_Player].setArgent(players[Current_Player].getArgent()-300);
        cout << "Enter a voyelle you want to buy : ";
        cin >> voy;
        while(true)
        {
            for(int i(0);i<voyelle.size();i++)
            {
                if(voy==voyelle[i])
                {
                    checkInput = true;
                    break;
                }
            }
            if(checkInput){break;}
            cout << "I said a voyelle! please enter a voyelle you want to buy : ";
            cin >> voy;
        }
        string voy1 ="";
        voy1 += voy;
        puzzle.afficherCaractere(voy1);
        return 1;
    }
    else
    {
        return 0;
    }
}
void Game::consonne()
{
    roue.generateMoney();
    cout << roue.money << " for each consonne" << endl;
    string voyelle ="AEIUOYaeiuoy";
    char cons;
    bool checkInput = true;
    cout << "Enter a consonne you want to reveal : ";
    cin >> cons;
    while(true)
    {
        checkInput = true;
        for(int i(0);i<voyelle.size();i++)
        {
            if(cons==voyelle[i])
            {
                checkInput = false;
                break;
            }
        }
        if(checkInput){break;}
        cout << "I said a consonne! please enter a consonne you want to buy : ";
        cin >> cons;
    }
    string cons1 ="";
    cons1 += cons;
    int occ = puzzle.occurrence(cons1);
    puzzle.afficherCaractere(cons1);
    cout << cons1 << " was found " << occ << " times in the sentence" <<endl;
    cout << "you won "<< occ*roue.money << endl;
    players[Current_Player].setArgent(players[Current_Player].getArgent()+occ*roue.money);
}
