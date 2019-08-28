#include<stdio.h>

int mc[]={0,3,3,6,1,4,6,2,5,0,3,5};
int cc[]={0,5,3,1};
char mnt[][10]={"January","February","March","April",
                "May","June","July","August",
                "September","October","November","December"};
int d[]={31,28,31,30,31,30,31,31,30,31,30,31};

char mntb[][10]={"Boishakh","Joishtho","Asharh","Shrabon",
                 "Bhadro","Ashwin","Kartik","Ogrohayon",
                 "Poush","Magh","Falgun","Choitro"};
int db[12]={31,31,31,31,31,30,30,30,30,30,30,30};

int main()
{
    int c,y,m,i,t;
    printf("Press 1 for English Calendar, 2 for Bangla Calendar\n");
    scanf("%d",&c);
    if(c==1)
    {
        printf("\nYear: ");
        scanf("%d",&y);
        printf("\nMonth (Numerically): ");
        scanf("%d",&m);

        int yt,ct;
        yt=y%100;
        ct=(y/100)%4;
        if(l(y))
        {
            d[1]=29;
            mc[0]=6;
            mc[1]=2;
        }
        t=(1+mc[m-1]+yt+yt/4+cc[ct])%7;

        printf("\n\n %s %d",mnt[m-1],y);
        printf("\n\n|Sat|Sun|Mon|Tue|Wed|Thu|Fri|\n" );
        for(i=0;i<t;i++)
            printf("    ");
        for(i=0;i<(d[m-1]);i++)
        {
            printf("%4d",i+1);
            if((i+1+t)%7==0)
                printf("\n");
        }
        printf("\n");
        }

    if(c==2)
    {
        printf("\nYear: ");
        scanf("%d",&y);
        printf("\nMonth (Numerically): ");
        scanf("%d",&m);

        int yt,mt;
        t=2;
        if(l(y+594))
            db[10]=31;
        for(yt=1;yt<y;yt++){
            if(l(yt+594))
                t=(t+366)%7;
            else
                t=(t+365)%7;
        }
        for(mt=0;mt<m-1;mt++)
            t=(t+db[mt])%7;

        printf("\n\n %s %d",mntb[m-1],y);
        printf("\n\n|Sat|Sun|Mon|Tue|Wed|Thu|Fri|\n");
        for(i=0;i<t;i++)
            printf("    ");

        for(i=0;i<db[m-1];i++)
        {
            printf("%4d",i+1);
            if((i+1+t)%7==0)
                printf("\n");
        }
        printf("\n");
    }

    return 0;
}

int l(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return 1;
    else
        return 0;
}
