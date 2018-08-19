#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random(int a);

int main(int argc, char *argv[])
{
    // check for proper input
    if (argc != 2)
    {
        //print error
        fprintf(stderr, "Usage: diceroller ndn\n");
        return 1;
    }

    // find the d
    int d_pos = 0;
    while (!isalpha(argv[1][d_pos]))
    {
        d_pos++;
    }

    // save number of dice and what type
    char dice[d_pos + 1];
    strncpy(dice, argv[1], d_pos);
    int num_of_dice = atoi(dice);

    char die[strlen(argv[1]) - d_pos];
    strncpy(die, &argv[1][d_pos + 1], strlen(argv[1]) - d_pos - 1);
    int type_of_dice = atoi(die);

    //roll
    int result = 0;
    srand(time(0));

    for (int i = 0; i < num_of_dice; i++)
    {
        int roll = random(type_of_dice) + 1;
        result += roll;
    }

    //print result
    fprintf(stdout, "%i\n", result);

    return 0;
}

int random(int a)
{
    int b = (rand() % a);
    return b;
}
