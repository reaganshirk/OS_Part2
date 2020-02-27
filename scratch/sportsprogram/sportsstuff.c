#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
  * Enter Sports team information and print it out
  *
**/

struct _record
{
    int number;
    char team[50];
    char *player;
};
typedef struct _record record;

int printrec(const record r)
{
    printf("<%d, %s, %s>\n", r.number, r.team, r.player);
    return 0;
}

int main (int argc, char** argv)
{
    record *hof; // Hall of Fame to store our players
    int hofsize;
    int i;

    // Ask the user for the number of records
    printf("Please enter the number of records >> ");
    scanf("%d", &hofsize);

    printf("You've entered: %d\n", hofsize);
    hof = calloc(hofsize, sizeof(record));

    // Iterate with the user and insert new records
    for (i = 0; i < hofsize; ++i)
    {
        record tmprecord;
        tmprecord.player = malloc(sizeof(char) * 10);
        printf("Please enter user number, team name, and player name:\n");
        scanf("%d %s %s", &tmprecord.number, tmprecord.team, tmprecord.player);
        printrec(tmprecord);
        memcpy(&hof[i], &tmprecord, sizeof(record));
        //free(tmprecord);

    }

    printf("Your hall of fame has: \n---------------------------\n");
    for (int i = 0; i < hofsize; ++i)
    {
        printrec(hof[i]);
        //free(hof[i]);
    }
    //free(hof);

    // exit 0/-1 are exit codes
    return 0;
}
