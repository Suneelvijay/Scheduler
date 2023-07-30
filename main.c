#include<stdio.h>
#include<string.h>
typedef struct team 
{
    char v[30];
}t;
void empty();
void venue(char arq[]);
void month(int mnt[]);
void day(int* k);
void date(int cal[], int mnt[]);
void playoffs(int* b,int cal[],int mnt[]);
void league(int n,int* z,t ar[] ,int cal[],int mnt[]);

int main()
{
    printf("\t\tWELCOME TO IPL SCHEDULER\n");
    int i, n, z, n1, cal[3], mnt[12];
    month(mnt);
    printf("Input number of teams: ");
    scanf("%d",&n);
    t arr[n],*p;
    printf("\nEnter the teams:\n");
    p = &arr[0];
    for(i=0;i<n;i++)
        scanf("%s",(p+i)->v);
    printf("Enter date for tournament to start: ");
    scanf("%d",&cal[0]);
    printf("Enter month of commencement [1 for jan, 2 for feb, 3 for march and so on]: ");
    scanf("%d",&cal[1]);
    cal[1] = cal[1] - 1;
    printf("Enter year of occurence: ");
    scanf("%d",&cal[2]);
    printf("Enter the day of beginning of the tournament:\n\nEnter 1 for Sunday 3.30pm, 2 for Sunday 7.30pm, 3 for Monday 7.30pm, 4 for Tuesday 7.30pm, 5 for Wednesday 7.30pm, 6for Thursday 7.30pm, 7 for Friday 7.30pm,\n8 for Saturday 3.30pm, 9 for Saturday 7.30pm: ");
    scanf("%d",&z);
    if((z>=1)&&(z<=9))
    {
        
    }
    else do
    {
        printf("\nInvaild input\n\nEnter1 for Sunday 3.30pm, 2 for Sunday 7.30pm, 3 for Monday 7.30pm, 4 for Tuesday 7.30pm, 5 for Wednesday 7.30pm, 6 for Thursday 7.30pm, 7 for Friday 7.30pm, 8 for Saturday 3.30pm, 9 for Saturday 7.30pm: ");
        scanf("%d",&z);
    }while((z>9)||(z<=0));
    printf("\n\t\tLEAGUE\n\n");
    league(n,&z,arr,cal,mnt);
}

void venue(char arq[])
{
    if(strcmp(arq,"CSK")==0)
        printf("Venue: Chennai\n---------------------------------\n");
    else if(strcmp(arq,"DC")==0)
        printf("Venue: Delhi\n---------------------------------\n");
    else if(strcmp(arq,"GT")==0)
        printf("Venue: Ahmedabad\n---------------------------------\n");
    else if(strcmp(arq,"KKR")==0)
        printf("Venue: Kolkata\n---------------------------------\n");
    else if(strcmp(arq,"PBKS")==0)
        printf("Venue: Mohali\n---------------------------------\n");
    else if(strcmp(arq,"RR")==0)
        printf("Venue: Jaipur\n---------------------------------\n");
    else if(strcmp(arq,"LSG")==0)
        printf("Venue: Lucknow\n---------------------------------\n");
    else if(strcmp(arq,"MI")==0)
        printf("Venue: Mumbai\n---------------------------------\n");
    else if(strcmp(arq,"SRH")==0)
        printf("Venue: Hyderabad\n---------------------------------\n");
    else if(strcmp(arq,"RCB")==0)
        printf("Venue: Bangalore\n---------------------------------\n");
    else if(arq[0]=='s')
        printf("Venue: Ahmedabad\n---------------------------------\n");
    else if(arq[0]=='t')
        printf("Venue: Lucknow\n---------------------------------\n");
    else printf("Venue: Home Ground of Team %s\n---------------------------------\n",arq);
}
void month(int mnt[])
{
    int *p;
    p = &mnt[0];
    for (int i=0;i<12;i++)
        *(p+i) = i+1;
}
void day(int* k)
{
    if(*k==1)
        printf("Sunday\nTime-3:30pm\n");
    else if(*k==2)
        printf("Sunday\nTime-7:30pm\n");
    else if(*k==3)
        printf("Monday\nTime-7:30pm\n");
    else if(*k==4)
        printf("Tuesday\nTime-7:30pm\n");
    else if(*k==5)
        printf("Wednesday\nTime-7:30pm\n");
    else if(*k==6)
        printf("Thursday\nTime-7:30pm\n");
    else if(*k==7)
        printf("Friday\nTime-7:30pm\n");
    else if(*k==8)
        printf("Saturday\nTime-3:30pm\n");
    else if(*k==9)
        printf("Saturday\nTime-7:30pm\n");
}
void date(int cal[], int mnt[])
{
    if(cal[0]==32)
    {
        if(cal[1]==11)
        {
            cal[1]=0;
            cal[2]=cal[2] +1;
            cal[0]=1;
        }
        else
        {
            cal[1]=cal[1] +1;
            cal[0]=1;
        }
    } 
    else if(cal[0]==31)
    {
        if((cal[1]==3)||(cal[1]==5)||(cal[1]==8)||(cal[1]==10))
        {
            cal[1]=cal[1] +1;
            cal[0]=1;
        }
    }
    else if((cal[1]==1) &&(cal[0]==29))
    {
        cal[1]=cal[1] +1;
        cal[0]=1;
    }
    printf("%d-%d-%d\n",cal[0],mnt[cal[1]],cal[2]);
}
void playoffs(int* b,int cal[],int mnt[])
{
    t w,x,y,h,wq1,lq1,we1,wq2;
    printf("\t\tPLAYOFFS\n\nInput Top 4 teams of leaderboard in order: ");
    scanf("%s %s %s %s",w.v,x.v,y.v,h.v);
    printf("\n\t\tQualifier 1\n");
    *b=*b+1;
    cal[0] =cal[0] +1;
    if(*b>9)
        *b=*b%9;
    date(cal,mnt);
    day(b);
    printf(" %s vs  %s\n",w.v,x.v);
    venue("s");
    printf("Input winner of qualifier 1 :  %s vs  %s: ",w.v,x.v);
    scanf("%s",wq1.v);
    if(strcmp(wq1.v,w.v)==0)
        strcpy(lq1.v,x.v);
    else strcpy(lq1.v,w.v);
    printf("\n\t\tEliminator\n");
    *b=*b+1;
    cal[0] =cal[0] +1;
    if(*b>9)
        *b=*b%9;
    date(cal,mnt);
    day(b);
    printf(" %s vs  %s\n",y.v,h.v);
    venue("t");
    printf("Input winner of eliminator 1 :  %s vs  %s: ",y.v,h.v);
    scanf("%s",we1.v);
    printf("\n\t\tQualifier 2\n");
    *b=*b+2;
    cal[0] =cal[0] +2;
    if(*b>9)
        *b=*b%9;
    date(cal,mnt);
    day(b);
    printf(" %s vs  %s\n",lq1.v,we1.v);
    venue("t");
    printf("Input winner of Qualifier 2 :  %s vs  %s: ",lq1.v,we1.v);
    scanf("%s",wq2.v);
    printf("\n\t\tFINALS\n");
    *b=*b+4;
    cal[0] =cal[0] +2;
    if(*b>9)
        *b=*b%9;
    date(cal,mnt);
    day(b);
    printf(" %s vs  %s\n",wq1.v,wq2.v);
    venue("s");
}
void league(int n,int* z,t ar[] ,int cal[],int mnt[])
{
    int a, b, c, l, *p, j, k, n1;
    char d[30], e[30], x[30];
    n1 =n-1;
    if(n%2==0)
    {
        a=0;
        b=n1;
        c=b-a;
        l=0;
        p=&l;
        while(c>=1)
        {
            *p=*p+1;
            strcpy(d,ar[a].v);
            strcpy(e,ar[b].v);
            a=a+1;
            b=b-1;
            printf("Match no. : %d\n",*p);
            date(cal,mnt);
            day(z);
            printf("  %s vs %s\n",d,e);
            venue(d);
            if(*z==1||*z==8)
            {   
            
            }
            else cal[0] =cal[0] +1;
            *z=*z+1;
            if(*z>9)
                *z=*z%9;
            c=b-a;
        }
        k=0;
        while(k<n1-1)
        {
            k=k+1;
            strcpy(x,ar[n1].v);
            for(j=n1;j>=1;j--)
            {
                ar[j]=ar[j-1];
            }
            strcpy(ar[1].v,x);
            a=-1;
            b=n;
            c=b-a;
            while(c>1)
            {
                a=a+1;
                b=b-1;
                strcpy(d,ar[a].v);
                strcpy(e,ar[b].v);
                *p=*p+1;
                printf("Match no. : %d\n",*p);
                date(cal,mnt);
                day(z);
                printf(" %s vs %s\n",d,e);
                venue(d);
                if(*z==1||*z==8)
                {
                    
                }
                else cal[0] =cal[0] +1;
                *z=*z+1;
                if(*z>9)
                    *z=*z%9;
                c=b-a;
            }
        }
        k=0;
        while(k<n1)
        {
            k=k+1;
            strcpy(x,ar[n1].v);
            for(j=n1;j>=1;j--)
            {
                ar[j]=ar[j-1];
            }
            strcpy(ar[1].v,x);
            a=-1;
            b=n;
            c=b-a;
            while(c>1)
            {
                a=a+1;
                b=b-1;
                strcpy(d,ar[a].v);
                strcpy(e,ar[b].v);
                *p=*p+1;
                printf("Match no. : %d\n",*p);
                date(cal,mnt);
                day(z);
                printf(" %s vs %s\n",e,d);
                venue(e);
                if(*z==1||*z==8)
                {
                    
                }
                else cal[0] = cal[0] +1;
                *z=*z+1;
                if(*z>9)
                    *z=*z%9;
                c=b-a;
            }
        }
    }
    else
    {
        a=1;
        b=n1;
        c=b-a;
        l = 0;
        *p=&l;
        while(c>=1)
        {
            *p=l+1;
            strcpy(d,ar[a].v);
            strcpy(e,ar[n1].v);
            a=a+1;
            b=b-1;
            printf("Match no : %i\n",*p);
            date(cal,mnt);
            day(z);
            printf(" %s vs %s\n",d,e);
            venue(d);
            if(*z==1||*z==8)
            {
                
            }
            else cal[0] =cal[0] +1;
            *z=*z+1;
            if(*z>9)
                *z=*z%9;
            c=b-a;
        }
        k=0;
        while(k<n-1)
        {
            k=k+1;
            strcpy(x,ar[n1].v);
            for(j=n1;j>=1;j--)
            {
                ar[j]=ar[j-1];
            }
            strcpy(ar[0].v,x);
            a=0;
            b=n;
            c=b-a;
            while(c>1)
            {
                a=a+1;
                b=b-1;
                strcpy(d,ar[a].v);
                strcpy(e,ar[b].v);
                *p=*p+1;
                printf("Match no : %i\n",l);
                date(cal,mnt);
                day(z);
                printf(" %s vs %s\n",d,e);
                venue(d);
                if(*z==1||*z==8)
                {
                    
                }
                else cal[0] =cal[0] +1;
                *z=*z+1;
                if(*z>9)
                    *z=*z%9;
                c=b-a;
            }
        }
        k=0;
        while(k<=n1)
        {
            k=k+1;
            strcpy(x,ar[n1].v);
            for(j=n1;j>=1;j--)
            {
                ar[j]=ar[j-1];
            }
            strcpy(ar[0].v,x);
            a=0;
            b=n;
            c=b-a;
            while(c>1)
            {
                a=a+1;
                b=b-1;
                strcpy(d,ar[a].v);
                strcpy(e,ar[b].v);
                *p=*p+1;
                printf("Match no : %i\n",*p);
                date(cal,mnt);
                day(z);
                printf(" %s vs %s\n", e,d);
                venue(e);
                if(*z==1||*z==8)
                {
                    
                }
                else cal[0] =cal[0] +1;
                *z=*z+1;
                if(*z>9)
                    *z=*z%9;
                c=b-a;
            }
        }
    }
    playoffs(z,cal,mnt);
}
