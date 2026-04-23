#include <stdio.h>
#include <conio.h>

struct teacher
{
    char name[20];
    int exp;
};

void main()
{
    struct teacher t[50];
    int i, n;

    clrscr();

    printf("Enter number of teachers: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nName: ");
        scanf("%s", t[i].name);

        printf("Experience: ");
        scanf("%d", &t[i].exp);
    }

    printf("\nTeachers with experience > 10:\n");

    for(i = 0; i < n; i++)
    {
        if(t[i].exp > 10)
        {
            printf("%s\n", t[i].name);
        }
    }

    getch();
}
