#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <graphics.h>

struct TeacherRecord
{
    int SN;
    char name[30];
    char department[50];
    char experience[50];
    int salary;
};

void main()
{
    int gd=DETECT,gm;
    int Num_Teacher, i;
    int max = 0, min = 0;
    int add_y;
    char text[200];

    clrscr();

    printf("Enter number of Teacher: ");
    scanf("%d", &Num_Teacher);

    struct TeacherRecord T[100];

    // Input
    for (i = 0; i < Num_Teacher; i++)
    {
	printf("\nEnter details of Teacher %d\n", i + 1);

	printf("S.N: ");
	scanf("%d", &T[i].SN);

	printf("Name: ");
	scanf("%s", T[i].name);

	printf("Department: ");
	scanf("%s", T[i].department);

	printf("Experience: ");
	scanf("%s", T[i].experience);

	printf("Salary: ");
	scanf("%d", &T[i].salary);
    }

    // File writing
    FILE *fp;
    fp = fopen("Teacher.txt", "w");

    for (i = 0; i < Num_Teacher; i++)
    {
	fprintf(fp, "%d %s %s %s %d\n",
		T[i].SN,
		T[i].name,
		T[i].department,
		T[i].experience,
		T[i].salary);
    }

    fclose(fp);
    fp=fopen("Teacher.txt","r");
    // Find max and min salary

    for (i = 1; i < Num_Teacher; i++)
    {
	if (T[i].salary > T[max].salary)
	    max = i;

	if (T[i].salary < T[min].salary)
	    min = i;
    }

    // Graphics
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Highest salary
    rectangle(50, 100, 300, 220);
    outtextxy(60, 110, "Highest Salary Teacher");

    sprintf(text, "S.N: %d", T[max].SN);
    outtextxy(60, 130, text);

    sprintf(text, "Name: %s", T[max].name);
    outtextxy(60, 150, text);

    sprintf(text, "Department: %s", T[max].department);
    outtextxy(60, 170, text);

    sprintf(text, "Experience: %s", T[max].experience);
    outtextxy(60, 190, text);

    sprintf(text, "Salary: %d", T[max].salary);
    outtextxy(60, 210, text);

    // Lowest salary
    rectangle(350, 100, 600, 220);
    outtextxy(360, 110, "Lowest Salary Teacher");

    sprintf(text, "S.N: %d", T[min].SN);
    outtextxy(360, 130, text);

    sprintf(text, "Name: %s", T[min].name);
    outtextxy(360, 150, text);

    sprintf(text, "Department: %s", T[min].department);
    outtextxy(360, 170, text);

    sprintf(text, "Experience: %s", T[min].experience);
    outtextxy(360, 190, text);

    sprintf(text, "Salary: %d", T[min].salary);
    outtextxy(360, 210, text);
    getch();
}
