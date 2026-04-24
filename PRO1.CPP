#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>

struct TeacherRecord
{
    int SN;
    char name[30];
    char department[50];
    int experience;
    int salary;
};

void main()
{
    struct TeacherRecord t[50];
    int n, i, j;
    int counted[50];

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Title Screen
    setcolor(WHITE);
    rectangle(50, 50, 590, 430);
    settextstyle(3, 0, 3);
    outtextxy(120, 80, "School Teacher System");

    settextstyle(2, 0, 5);
    outtextxy(150, 150, "Press any key to start...");
    getch();
    closegraph();

    clrscr();

    // Input Section
    printf("Enter number of teachers: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of teacher %d:\n", i+1);

        printf("SN: ");
        scanf("%d", &t[i].SN);

        printf("Name: ");
        scanf("%s", t[i].name);

        printf("Department: ");
        scanf("%s", t[i].department);

        printf("Experience: ");
        scanf("%d", &t[i].experience);

        printf("Salary: ");
        scanf("%d", &t[i].salary);

        counted[i] = 0;
    }

    // Graphics Output
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    cleardevice();

    setcolor(YELLOW);
    rectangle(20, 20, 620, 460);

    settextstyle(3, 0, 2);
    outtextxy(120, 30, "Teachers Per Department");

    int y = 80;

    for(i = 0; i < n; i++)
    {
        if(counted[i] == 1)
            continue;

        int count = 1;

        for(j = i + 1; j < n; j++)
        {
            if(strcmp(t[i].department, t[j].department) == 0)
            {
                count++;
                counted[j] = 1;
            }
        }

        char result[100];
        sprintf(result, "%s : %d teachers", t[i].department, count);

        setcolor(CYAN);
        outtextxy(100, y, result);

        y += 40;
    }

    setcolor(WHITE);
    outtextxy(180, 420, "Press any key to exit...");
    getch();

    closegraph();
}
