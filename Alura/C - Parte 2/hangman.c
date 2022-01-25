#include <stdio.h>

#include <string.h>

#include <stdbool.h>

#include <ctype.h>

// functions

void title() {
    printf("******************************\n");
    printf(" Welcome to the Hangman game   \n");
    printf("******************************\n\n");
}

void getWord(char * word) {
    sprintf(word, "VANDA");
    for (int i = 0; i < strlen(word); i++) {
        word[i] = toupper(word[i]);
    }
    //printf("%s \n", word);
}

void fillGameWord(char * hidden, char * guessingWord) {
    guessingWord[strlen(hidden)] = '\0';
    for (int i = 0; i < strlen(hidden); i++) { // fill gameword with spaces
        guessingWord[i] = '_';
    }
}

char enterGuess() {
    char guessTR;
    printf("\nPlease enter your guess: ");
    scanf(" %c", & guessTR);
    return guessTR;
}

bool alreadyGuessed(char * previousGuessArray, char * guessTR) {
    bool guessedBefore = false;
    for (int idx = 0; idx < strlen(previousGuessArray); idx++) {
        if (previousGuessArray[idx] == guessTR) {
            printf("You have already guessed this! \n");
            guessedBefore = true;
        }
    }
    return guessedBefore;
}

void goodGuess(char * hidden, char * guessingWord, char * guessTR, bool * mistake_bool, int * correct_letters) {
    for (int i = 0; i < strlen(hidden); i++) {
        if (hidden[i] == guessTR) {
            guessingWord[i] = guessTR;
            * correct_letters = * correct_letters + 1;
            * mistake_bool = false;
        }
    }
}

void printGuessList(char * previousGuessArray, char * guessTR, int * guesscounter) {
    previousGuessArray[ * guesscounter] = guessTR;
    printf("You have guessed the following words: ");
    for (int j = 0; j <= * guesscounter; j++) {
        printf("%c , ", previousGuessArray[j]);
    }
    printf("\n");
    * guesscounter = * guesscounter + 1;
    printf("Number of guesses: %d \n", * guesscounter);
}

int main() {

    char previous_guess[26];

    int mistake = 0;
    int counter = 0;
    char hidden_word[20];

    getWord(hidden_word);
    char game_word[strlen(hidden_word) + 1];
    //char guess;
    char enter;

    bool got_it = false;
    bool hanged = false;
    //bool guess_finder = false;
    bool mistake_finder = true;

    int letters_right = 0;

    ///////////////////////////////////////////////////////
    // PROGRAM EXECUTION

    fillGameWord(hidden_word, game_word);
    title();

    printf("%s\n", hidden_word);

    while (!hanged && !got_it) {

        mistake_finder = true;
        printf("Game word is %s", game_word);

        char guess = enterGuess();
        bool guess_finder = alreadyGuessed(previous_guess, guess);

        if (!guess_finder) {

            goodGuess(hidden_word, game_word, guess, & mistake_finder, & letters_right);

            (mistake_finder) ? (mistake++) : 1;

            printGuessList(previous_guess, guess, & counter);
        }
        printf("Value of letters_right is %d\n", letters_right);
        (letters_right == strlen(hidden_word)) ? got_it = true: 1; //TEST IF USER HAS WON
        (mistake > 5) ? hanged = true: 1;
    }

    (got_it) ? printf("\n\nEnd of game! You have won MY DEAREST TUBI TUBI!"): 1;
    (hanged) ? printf("\n\nEnd of game! You have been HANGED!"): 1;
    return 0;
}
