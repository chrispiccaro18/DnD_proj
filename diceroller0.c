#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int a);

int main(int argc, char *argv[])
{
    // check to see proper input
    if (argc != 4)
    {
        //print error
        fprintf(stderr, "Usage: diceroller n d n\n");
        return 1;
    }
    // save number of dice and what type
    int num_of_dice = atoi(argv[1]);
    int type_of_dice = atoi(argv[3]);

    //roll
    int result = 0;
    srand(time(0));

    for (int i = 0; i < num_of_dice; i++)
    {
        int roll = random(type_of_dice) + 1;
        result += roll;
    }

    fprintf(stdout, "%i\n", result);

    return 0;
}

int random(int a)
{
    int b = (rand() % a);
    return b;
}
