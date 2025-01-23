#ifndef KEYBOARD_TYPING_H
#define KEYBOARD_TYPING_H

/* All systems libs that need */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * @brief This function load text with pre-loaded text sample
 *
 * @param filename File that will be loaded
 *
 */
void choose_difficulty(const FILE *filename);

/*
 * @brief This function calculate how accurate user was
 *
 * @param correct_words Amount of correct words entered by user
 *
 * @param wrong_words Amount of incorrent words entered by user
 */
double accuracy_calculate(const size_t correct_words, const size_t incorrect_words);

/* 
 * @brief This function prints all stats of user's typing
 *
 * @param filename What difficult was selected
 *
 * @param accuracy How accuracy user was on the race
 *
 * @param typing_speed How fast user was ont the race
 */
void print_summary(
    const FILE *filename,
    const double accuracy,
    const double typing_speed
);


#endif
