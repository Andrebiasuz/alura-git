#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {

    char previous_guess[26];

    char game_word[20];
    int mistake = 0;
    int counter = 0;
    char hidden_word[20];
    char guess;
    char enter;

    bool got_it = false;
    bool hanged = false;
    bool guess_finder = false;
    bool mistake_finder = true;
    int letters_right = 0;

    sprintf(hidden_word, "VANDA");

    for (int i = 0; i < strlen(hidden_word); i++) { // fill gameword with spaces
        game_word[i] = '_';
        hidden_word[i] = toupper(hidden_word[i]);
    }

    printf("%s\n", hidden_word);

    while (!hanged && !got_it) {

        mistake_finder = true;
        guess_finder = false;

        printf("Game word is %s", game_word);

        printf("\nPlease enter your guess: ");
        scanf(" %c", & guess); // need to give space to skip enter as char

        for (int idx = 0; idx < strlen(previous_guess); idx++) {

            if (previous_guess[idx] == guess) {
                printf("You have already guessed this! \n");
                guess_finder = true;
            }
        }

        if (!guess_finder) {

            for (int i = 0; i < strlen(hidden_word); i++) {

                if (hidden_word[i] == guess) {
                    game_word[i] = guess;
                    letters_right++;
                    mistake_finder = false;
                }
            }

            (mistake_finder) ? (mistake++) : 1;

            previous_guess[counter] = guess;
            printf("You have guessed the following words: ");
            for (int j = 0; j <= counter; j++) {
                printf("%c , ", previous_guess[j]);
            }
            printf("\n");
            counter++;
        }
        printf("Value of letters_right is %d\n", letters_right);
        (letters_right == strlen(hidden_word)) ? got_it = true: 1; //TEST IF USER HAS WON
        (mistake > 5) ? hanged = true : 1;
    }

    (got_it) ? printf("\n\nEnd of game! You have won MY DEAREST TUBI TUBI!"): 1;
    (hanged) ? printf("\n\nEnd of game! You have been HANGED!"): 1;
    return 0;
}
