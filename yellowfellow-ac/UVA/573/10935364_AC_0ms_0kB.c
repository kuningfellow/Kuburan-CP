#include <stdio.h>
int main()
{
    int h,d,f;
    double u;
    while (scanf("%d%lf%d%d",&h,&u,&d,&f)!=EOF)
    {
        if (h==0)
        {
            break;
        }
        double hei=0;
        int day=1;
        int fail=0;
        double dec=(double)f/100*u;
        u+=dec;
        while (1<2)
        {
            u-=dec;
            if (u>=0)
                hei+=u;
            if (hei>h)
            {
                break;
            }
            hei-=d;
            if (hei<0)
            {
                fail=1;
                break;
            }
            day++;
        }
        if (fail==0)
        {
            printf ("success on day %i\n",day);
        }
        else if (fail==1)
        {
            printf ("failure on day %i\n",day);
        }
    }
    return 0;
}
