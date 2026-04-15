#include<stdio.h>
struct teacher{
    float salary;
    char name[25];
    char department[25];
    int exp;
};
int main()
{
    struct teacher td[7];
    int i;
    FILE *fp;
    fp=fopen("teachdata.txt","w");
    printf("enter details of 7 teachers");
    for(i=0;i,7;i++)
    {
        printf("salary,name,department,exp=");
        scanf("%f\t %s\t %s\t %d\n",&td[i].salary,td[i].name,td[i].department,&td[i].exp);
        fprintf(fp,"%f\t %s\t %s\t %d\n",&td[i].salary,td[i].name,td[i].department,&td[i].exp);
    }
    printf("written successfully");
    fclose(fp);
    return 0;
    }
