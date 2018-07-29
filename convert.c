#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    //Prompt currency to convert
    char a;

    do
    {
        a = get_char("Convert which coin (c/s/e/g/p)?: ");
    }
    while (a != 99 && a != 115 && a != 101 && a != 103 && a != 112);

    //Prompt quantity of coins
    int n;

    do
    {
        n = get_int("How many coin to convert?: ");
    }
    while (n <= 0);

    //Check if enough copper
    if (a == 99 && n < 10)
    {
        printf("You need at least 10 copper to convert\n");
        goto end;
    }

    //Prompt currency to convert to
    char b;

    do
    {
        b = get_char("To which coin (c/s/e/g/p)?: ");
    }
    while (b != 99 && b != 115 && b != 101 && b != 103 && b != 112);

    //Check if they input same currency and, if so, ask again
    if (a == b)
    {
        b = get_char("To which coin (c/s/e/g/p)?: ");
    }

    //Check if enough coin to convert. If so, convert
    int w, x, y, z;

    //Copper first
    if (a == 99)
    {
        if (n < 50 && b == 101)
        {
            printf("Not enough copper to convert to electrum\n");
        }

        else if (n < 100 && b == 103)
        {
            printf("Not enough copper to convert to gold\n");
        }

        else if (n < 1000 && b == 112)
        {
            printf("Not enough copper to convert to platinum\n");
        }

        //Do conversion
        else
        {
            //Convert to silver
            if (b == 115)
            {
                x = n / 10;
                y = n % 10;

                //Print with no copper left over
                if (y == 0)
                {
                    printf("%i%c\n", x, b);
                }

                //Print with copper left over
                else
                {
                    printf("%i%c %i%c\n", x, b, y, a);
                }
            }

            //Convert to electrum
            else if (b == 101)
            {
                z = n / 50;
                x = (n - z * 50) / 10;
                y = n % 10;

                //Must go first - Print with no c nor s left over
                if (y == 0 && x == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with no copper left over
                else if (y == 0)
                {
                    printf("%i%c %is\n", z, b, x);
                }

                //Print with no silver left over
                else if (x == 0)
                {
                    printf("%i%c %i%c\n", z, b, y, a);
                }

                //Print with copper and silver left over
                else
                {
                    printf("%i%c %is %i%c\n", z, b, x, y, a);
                }
            }
            //Convert to gold
            else if (b == 103)
            {
                z = n / 100;
                x = (n / 10) % 10;
                y = n % 10;

                //Must go first - Print with no c nor s left over
                if (y == 0 && x == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with no copper left over
                else if (y == 0)
                {
                    printf("%i%c %is\n", z, b, x);
                }

                //Print with no silver left over
                else if (x == 0)
                {
                    printf("%i%c %i%c\n", z, b, y, a);
                }

                //Print with copper and silver left over
                else
                {
                    printf("%i%c %is %i%c\n", z, b, x, y, a);
                }
            }

            //Convert to platinum
            else
            {
                z = n / 1000;
                w = (n / 100) % 10;
                x = (n / 10) % 10;
                y = n % 10;

                //Must go first - Print with no c nor s nor g left over
                if (y == 0 && x == 0 && w == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with no c nor s
                else if (y == 0 && x == 0)
                {
                    printf("%i%c %ig\n", z, b, w);
                }
                //Print with no c nor g
                else if (y == 0 && w == 0)
                {
                    printf("%i%c %is\n", z, b, x);
                }
                //Print with no s nor g
                else if (x == 0 && w == 0)
                {
                    printf("%i%c %i%c\n", z, b, y, a);
                }

                //Print with no copper left over
                else if (y == 0)
                {
                    printf("%i%c %ig %is\n", z, b, w, x);
                }

                //Print with no silver left over
                else if (x == 0)
                {
                    printf("%i%c %ig %i%c\n", z, b, w, y, a);
                }

                //Print with no gold
                else if (w == 0)
                {
                    printf("%i%c %is %i%c\n", z, b, x, y, a);
                }
                //Print with copper, silver, and gold left over
                else
                {
                    printf("%i%c %ig %is %i%c\n", z, b, w, x, y, a);
                }
            }
        }
    }

    //Silver next
    else if (a == 115)
    {
        if (n < 5 && b == 101)
        {
            printf("Not enough silver to convert to electrum\n");
        }

        else if (n < 10 && b == 103)
        {
            printf("Not enough silver to convert to gold\n");
        }

        else if (n < 100 && b == 112)
        {
            printf("Not enough silver to convert to platinum\n");
        }

        //Do conversion
        else
        {
            //Convert to copper
            if (b == 99)
            {
                y = n * 10;
                printf("%i%c\n", y, b);
            }
            //Convert to electrum
            else if (b == 101)
            {
                x = n / 5;
                y = n - x * 5;

                //Print with no silver left over
                if (y == 0)
                {
                    printf("%i%c\n", x, b);
                }

                //Print with silver left over
                else
                {
                    printf("%i%c %i%c\n", x, b, y, a);
                }
            }
            //Convert to gold
            else if (b == 103)
            {
                w = n / 10;
                y = n % 10;

            //Print with no silver left over
                if (y == 0)
                {
                    printf("%i%c\n", w, b);
                }

                //Print with silver left over
                else
                {
                    printf("%i%c %i%c\n", w, b, y, a);
                }

            }
            //Convert to platinum
            else
            {
                z = n / 100;
                w = (n / 10) % 10;
                y = n % 10;

                //Must go first - Print with no s nor g left over
                if (y == 0 && w == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with no silver left over
                else if (y == 0)
                {
                    printf("%i%c %ig\n", z, b, w);
                }

                //Print with no gold left over
                else if (w == 0)
                {
                    printf("%i%c %i%c\n", z, b, y, a);
                }

                //Print with silver and gold left over
                else
                {
                    printf("%i%c %ig %i%c\n", z, b, w, y, a);
                }
            }
        }
    }

    //Electrum penultimate
    else if (a == 101)
    {
        if (n < 2 && b == 103)
        {
            printf("Not enough electrum to convert to gold\n");
        }

        else if (n < 20 && b == 112)
        {
            printf("Not enough electrum to convert to platinum\n");
        }

        //Do conversion
        else
        {
            //Convert to copper
            if (b == 99)
            {
                y = n * 50;
                printf("%i%c\n", y, b);
            }
            //Convert to silver
            else if (b == 115)
            {
                x = n * 5;
                printf("%i%c\n", x, b);
            }
            //Convert to gold
            else if (b == 103)
            {
                w = n / 2;
                y = n % 2;

                //Print with no electrum left over
                if (y == 0)
                {
                    printf("%i%c\n", w, b);
                }

                //Print with electrum left over
                else
                {
                    printf("%i%c %i%c\n", w, b, y, a);
                }

            }
            //Convert to platinum
            else
            {
                z = n / 20;
                w = z / 2;
                y = z % 2;

                //Must go first - Print with no e nor g left over
                if (y == 0 && w == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with no electrum left over
                else if (y == 0)
                {
                    printf("%i%c %ig\n", z, b, w);
                }

                //Print with no gold left over
                else if (w == 0)
                {
                    printf("%i%c %i%c\n", z, b, y, a);
                }

                //Print with electrum and gold left over
                else
                {
                    printf("%i%c %ig %i%c\n", z, b, w, y, a);
                }
            }
        }
    }
    //Gold last
    else if (a == 103)
    {
        if (n < 10 && b == 112)
        {
            printf("Not enough gold to convert to platinum\n");
        }

        //Do conversion
        else
        {
            //Convert to copper
            if (b == 99)
            {
                y = n * 100;
                printf("%i%c\n", y, b);
            }

            //Convert to silver
            else if (b == 115)
            {
                x = n * 10;
                printf("%i%c\n", x, b);
            }
            //Convert to electrum
            else if (b == 101)
            {
                w = n * 2;
                printf("%i%c\n", w, b);
            }
            //Convert to platinum
            else
            {
                z = n / 10;
                w = n % 10;

            //Print with no gold left over
                if (w == 0)
                {
                    printf("%i%c\n", z, b);
                }

                //Print with gold left over
                else
                {
                    printf("%i%c %i%c\n", z, b, w, a);
                }
            }
        }
    }

    //Platinum conversion
    else
    {
        //Convert to copper
        if (b == 99)
        {
            x = n * 1000;
            printf("%i%c\n", x, b);
        }

        //Convert to silver
        else if (b == 115)
        {
            y = n * 100;
            printf("%i%c\n", y, b);
        }
        //Convert to electrum
        else if (b == 101)
        {
            z = n * 20;
            printf("%i%c\n", z, b);
        }
        //Convert to gold
        else
        {
            w = n * 10;
            printf("%i%c\n", w, b);
        }
    }
    end:
    {

    }
}