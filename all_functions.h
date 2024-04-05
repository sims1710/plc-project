/* Define all planned functions here, include in all c files (TEMPORARY)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Added
#include <stdbool.h>

/* Fixed Values */
#define MAX_LIVES 7
#define ALPHABET_COUNT 26
#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define EXIT_CHAR 'E'
#define MAX_LEADERBOARD_ENTRIES 10
#define MAX_GUESSES 8
#define MAX_WORD_LENGTH 100

/* Return filename to read from, no external input, only player input inside function */
typedef struct
{
    char *filename;
    int word_len;
} chosen_difficulty;

typedef struct
{
    int current_level;
    int difficulty;
    chosen_difficulty chosenDiff;
} game_level;

/*void choose_difficulty(chosen_difficulty *file_set);*/
void choose_difficulty(game_level *game_levels);

/* Return a selected word, function input is filename */
char *get_word(chosen_difficulty *filename);

/* Update contents of pointer for hidden word, return nothing, function input is pointer to hidden word display and chosen word */
void update_hidden_word(char *hidden_word, char *chosen_word, char input_letter);

/* Check player input, invalid if number or already guessed, run if update if hit. function input is the selected word, hidden word display  */
void player_input(char *chosen_word, char *hidden_word, char *guessed_letters, int *lives, int word_len, int *score);
/* Pending fix */
/*void player_input(char *chosen_word, char *guessed_letters, int *lives, int *score); // Updated*/

/* Display the Hangman menu in console */
void display_hangman(char *hidden_word, int *lives, int word_len);

/* Make connections between letters and numbers */
int *link_number();

/* Clear console screen */
void clear_screen();

/* Clear stdin (Input stream) */
void clear_stdin();

/* Generate random number for the hints */
int *random_number(char *chosen_word, int word_len);

/* Function to suggest hints */
int suggest_hint(char* chosen_word, char *guessed_letters, game_level *game_levels, int* hints_given, int* player_points);

/*Implement the time attack mode*/
void time_attack_mode(char *chosen_word, char *hidden_word, char *guessed_letters, int *lives, int word_len, int *scores);

/* Main Menu */
void main_menu();
int validateChoice(int start, int end);
void enter_player_name(char *name);
int main1(); // Temporary Function

/* Keep track of score */
void score_tracker(int *score, int *lives);

/* Display and update leaderboard */
void updateLeaderboard(int score, int mode);
void addToLeaderboard(const char *name, int score, int mode);
void bubbleSortLeaderboard();
void generateLeaderboardHTML();

/* Display Game Rules */
void display_rules();

/* Endless Mode */
void endless_mode();

/* Multiplayer Mode */
void multiplayer_mode();

/* Adding a new word upon winning */
void add_new_word();

/* Save and resume function */
void save_game_state(int lives, int score, char* lettersGuessed, char* word, int gameOver);
void load_game_state(int* lives, int* score, char* lettersGuessed, char* word, int* gameOver);

/* timer functions */
time_t start_time();
time_t end_time(time_t start);

