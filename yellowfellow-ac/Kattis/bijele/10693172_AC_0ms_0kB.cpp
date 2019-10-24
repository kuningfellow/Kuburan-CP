#include <stdio.h>
int main()
{
    struct set
    {
        int king;
        int queen;
        int rooks;
        int bishops;
        int knights;
        int pawns;
    };
    struct set mirko;
    scanf ("%d%d%d%d%d%d",&mirko.king,&mirko.queen,&mirko.rooks,&mirko.bishops,&mirko.knights,&mirko.pawns);
    printf ("%i %i %i %i %i %i",1-mirko.king,1-mirko.queen,2-mirko.rooks,2-mirko.bishops,2-mirko.knights,8-mirko.pawns);
}
