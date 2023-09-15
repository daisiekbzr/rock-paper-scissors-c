#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main(){

    char player;
    char computer; 

    player = getUserChoice();
    std::cout << "You chose: ";
    showChoice(player);

    computer = getComputerChoice();
    std::cout << "Computer chose: ";
    showChoice(computer);

    chooseWinner(player, computer);

    return 0;
}
char getUserChoice(){
    
    char player;
    
    std::cout << "Rock Paper Scissors Game\n";
    std::cout << "************************\n";

    do{
        std::cout << "Choose one of the following:\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";

        std::cin >> player;
        std::cin.clear(); // resets any error flags when the std::cin fails to interpret the input
        fflush(stdin); // this clears the input buffer
    }while(player != 'r' && player != 'p' && player != 's');

    return player;
}
char getComputerChoice(){
    
    srand(time(0));
    int num = rand() % 3 + 1;

    switch(num){
        case 1: return 'r'; // dont need break here because return already breaks it
        case 2: return 'p';
        case 3: return 's';
    }

    return 0; // it works without as well but returns sort of an error indicating that there can be a value that doesn't return any of the cases, therefore this is needed
}
void showChoice(char choice){
    
    switch(choice){
        case 'r': 
            std::cout << "rock\n";
            break;
        case 'p': 
            std::cout << "paper\n";
            break;
        case 's': 
            std::cout << "scissors\n";
            break;
    }
}
void chooseWinner(char player, char computer){
    
    switch(player){
        case 'r': 
            if(computer == 'r'){
                std::cout << "It's a tie!";
            }
            else if (computer == 'p'){
                std::cout << "You lost...";
            }
            else{
                std::cout << "You won!";
            }
            break;
        case 'p': 
            if(computer == 'p'){
                std::cout << "It's a tie!";
            }
            else if (computer == 's'){
                std::cout << "You lost...";
            }
            else{
                std::cout << "You won!";
            }
            break;
        case 's': 
            if(computer == 's'){
                std::cout << "It's a tie!";
            }
            else if (computer == 'r'){
                std::cout << "You lost...";
            }
            else{
                std::cout << "You won!";
            }
            break; 
    }
}