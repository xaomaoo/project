#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <graphics.h>

struct TeacherRecord
{
    int SN;
    char name[30];
    char department[50];
    int experience;   // changed to int
    int salary;
};

void main()
{
    int gd = DETECT, gm;
    int Num_Teacher, i;
    int add_y;
    char text[100];

    struct TeacherRecord T[100];

    clrscr();

    printf("Enter number of Teachers: ");
    scanf("%d", &Num_Teacher);

    // INPUT
    for(i = 0; i < Num_Teacher; i++)
    {
        printf("\nEnter Teacher %d details\n", i+1);

        printf("SN: ");
        scanf("%d", &T[i].SN);

        printf("Name: ");
        scanf("%s", T[i].name);

        printf("Department: ");
        scanf("%s", T[i].department);

        printf("Experience (in years): ");
        scanf("%d", &T[i].experience);   // integer input

        printf("Salary: ");
        scanf("%d", &T[i].salary);
    }

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // BOX TITLE
    rectangle(150, 150, 500, 400);
    outtextxy(160, 160, "Teachers with Experience > 10 Years");

    add_y = 180;

    // FILTER: experience > 10
    for(i = 0; i < Num_Teacher; i++)
    {
        if(T[i].experience > 10)
        {
            sprintf(text, "SN: %d", T[i].SN);
            outtextxy(160, add_y, text);
            add_y += 20;

            sprintf(text, "Name: %s", T[i].name);
            outtextxy(160, add_y, text);
            add_y += 20;

            sprintf(text, "Department: %s", T[i].department);
            outtextxy(160, add_y, text);
            add_y += 20;

            sprintf(text, "Experience: %d", T[i].experience);
            outtextxy(160, add_y, text);
            add_y += 20;

            sprintf(text, "Salary: %d", T[i].salary);
            outtextxy(160, add_y, text);
            add_y += 30;
        }
    }

    getch();
    closegraph();
}
