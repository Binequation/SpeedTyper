/* Prototypes of functions */
#include "../include/keyboard_typing.h"

void choose_difficulty(const FILE *filename);

double accuracy_calculate(const size_t correct_words, const size_t incorrect_words);

void print_summary(
    const FILE *filename,
    const double accuracy,
    const double typing_speed
);
