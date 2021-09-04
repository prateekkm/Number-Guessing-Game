#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
 
void lineDraw(int n, char ch)
{
    for(int i=0; i<n; i++)
        cout << ch;
    cout << "\n";
}
 
void rules()
{
    system("CLS");
    cout << "\n\n";
    lineDraw(75,'-');
    cout << "\tTHE RULES OF THIS GAME\n";
    lineDraw(75,'-');
    cout << " (1) Choose any number in the range from 1 to 7 (both inclusive)\n";
    cout << " (2) If you bet on correct number, you will win 7 times of the bet amount\n";
    cout << " (3) If you bet on wrong number, you will lose the bet amount\n\n";
    lineDraw(75,'-');
}
 
int main()
{
    string pName;
    int amount; // To store the player's balance amount
    int betAmount; // To store the bet amount
    int guess;  // To store the guessed number
    int random; // To store the generated random number
    char choice;
 
    srand(time(0)); // Seed the random generator

    lineDraw(75,'_');
    cout << "\n\n\n\t\tNumber Guessing (Casino) Game\n\n\n\n";
    lineDraw(75,'_');
 
    cout << "\n\nEnter Your Full Name : ";
    getline(cin, pName);
 
    cout << "\n\nEnter Deposit amount to play game : Rs ";
    cin >> amount;
    
    do{
        system("CLS");
        rules();
        cout << "\n\nYour current balance is Rs " << amount << "\n";
		
		// Get the player's bet amount
        do{
            cout << pName << ", enter the amount you want to bet : Rs ";
            cin >> betAmount;
            if(betAmount > amount)
                cout << "Your bet amount is more than the current balance\n"
                     << "\nEnter a valid amount\n ";
        }while(betAmount > amount);
 
		// Get the player's guessed number
        do{
            cout << "Guess your number to bet between 1 to 7 :";
            cin >> guess;
            if(guess <= 0 || guess > 7)
                cout << "Please check the number! It should be between 1 to 7\n"
                     << "\nEnter a valid amount\n ";
        }while(guess <= 0 || guess > 7);
 
        random = rand()%7 + 1; // To store the generated random integer in the range [1,7]
    
        if(random == guess)
        {
            cout << "\n\nCongratulations! You won Rs " << betAmount * 7;
            amount += betAmount * 7;
        }
        else
        {
            cout << "Bad Luck this time! You lost Rs "<< betAmount << "\n";
            amount -= betAmount;
        }
 
        cout << "\nThe winning number was : " << random << "\n";
        cout << "\n" << pName << ", your current balance is Rs " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no more money to play";
            break;
        }
        cout << "\n\n-->Do you want to play again (Y/N)?";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
	  
    cout << "\n\n\n";
    lineDraw(75,'=');
    cout << "\n\n Thanks for playing this game. Your balance amount is Rs " << amount << "\n\n";
    lineDraw(75,'=');
 	getch();
    return 0;
}
