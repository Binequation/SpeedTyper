#ifndef KEYBOARD_TYPING_H
#define KEYBOARD_TYPING_H

/* All systems libs that need */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 2056 /* Max amount of characters in texts */
#define EASY_FILE_PATH   "src/difficulties/easy.txt"   /* Path to easy-level file text   */
#define MEDIUM_FILE_PATH "src/difficulties/medium.txt" /* Path to medium-level file text */
#define HARD_FILE_PATH   "src/difficulties/hard.txt"   /* Path to hard-level file text   */

/*
 * @brief This function load text with pre-loaded text sample
 *
 * @param filename File that will be loaded
 *
 * References: 
 *
 * easy level: https://10fastfingers.com/text/6053-Easy-text-to-type
 *
 * medium level: https://10fastfingers.com/text/236000-tough-typind-test-MEDIUM-LENGTH
 *
 * hard level: https://10fastfingers.com/text/3623-A-very-hard-typing-test-text
 */
char *choose_difficulty(const char *filename);

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
        const double accuracy, 
        const double typing_speed,
        const double wpm
);

/*
 * @brief This function start a race
 *
 * @param text Text that user will type
 */
void typing_test(const char *text);


#endif
