/* Functions to work with */
#include "../include/keyboard_typing.h"

int main(void) 
{
     char diff_choice; /* Stores user selection about difficult */

    /* Get a difficult of text to type */
    printf("Hello! What's level of file do you want to choose?\n"
            "1. Easy\n2. Medium\n3. Hard\nYour choice: ");

    scanf("%c", &diff_choice);
    switch (diff_choice) {
        case '1': 
            typing_test(choose_difficulty(EASY_FILE_PATH));
            break;
        case '2':
            typing_test(choose_difficulty(MEDIUM_FILE_PATH));
            break;
        case '3':
            typing_test(choose_difficulty(HARD_FILE_PATH));
            break;
        default:
            perror("No such selection!\n");
            return EXIT_FAILURE;
    }

    
}
