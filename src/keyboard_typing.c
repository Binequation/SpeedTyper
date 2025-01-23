/* Prototypes of functions */
#include "../include/keyboard_typing.h"

int choose_difficulty(const char *filename) 
{
    FILE *file = fopen(filename, "r"); /* Open file */

    if (file == NULL) { /* File not open */
        perror("File wasn't opened! There is an error!\n");
        return EXIT_FAILURE;
    }
    printf("File was successfuly uploaded!\n"); 

    return EXIT_SUCCESS;
}

double accuracy_calculate(const size_t correct_words, const size_t incorrect_words);

void print_summary(
    const FILE *filename,
    const double accuracy,
    const double typing_speed
);
