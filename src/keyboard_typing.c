/* Prototypes of functions */
#include "../include/keyboard_typing.h"

int    corr_char  = 0;   /* Amount of correct characters        */
double time_taken = 0.0; /* Time spent from start to end typing */
double accuracy   = 0.0; /* How accurate user type              */
double wpm        = 0.0; /* How much user typed                 */

char *choose_difficulty(const char *filename) 
{
    FILE *file = fopen(filename, "r"); /* Open file */

    if (file == NULL) { /* File not open */
        perror("File wasn't opened! There is an error!\n");
        return NULL;
    }
    printf("File was successfuly uploaded!\n"); 
      
    fseek(file, 0, SEEK_END);    /* Go to the end of the file */
    long fileSize = ftell(file); /* Get the file size         */
    rewind(file);                /* Go back to the beginning  */

    char *text = (char *)malloc(fileSize + 1); /* Allocate memory for the text */
    if (text == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(text, 1, fileSize, file); /* Read the file contents into the buffer    */
    text[fileSize] = '\0';          /* Add null terminator to make it a C string */
    fclose(file);

    return text;
}


void typing_test(const char *text)
{
    extern int corr_char;
    extern double wpm;
    extern double accuracy;
    extern double time_taken;

    clock_t start_timer = clock(); /* Timer starts */
    int curr_char = 0; /* Index of current character */
    int total_char = strlen(text); /* Total amount of characters */

    /* Start typing */
    printf("Start typing: \n%s\n", text);
    while (curr_char < total_char) {
        char input = getchar(); /* User input */

        if (input == text[curr_char])
            ++corr_char;
        else if (input == '\n') 
            continue;
        else if (input != EOF)
            printf("Incorrect character!\n");

        ++curr_char; /* Go to next character */
    }

    clock_t end_timer = clock(); /* Timer ends */
    time_taken        = (double)(end_timer - start_timer) / CLOCKS_PER_SEC; /* Calculate time spent */
    wpm               = (double)corr_char / time_taken * 60;
    accuracy          = (double)corr_char / total_char * 100;
}

void print_summary(
        const double accuracy, 
        const double wpm,
        const double time_taken
)
{
    printf("\n----RESULTS OF TYPING----\n"
           "Time taken: %6.2lf seconds\n"
           "WPM (Word Per Minute): %6.2lf WPM\n"
           "Accuracy: %6.2lf\n", 
           time_taken, wpm, accuracy);
}
