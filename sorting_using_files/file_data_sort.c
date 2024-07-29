#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, size = 25, c, d;
    float swapSGPA;
    char swapUSN[11];
    // structure definition
    struct student
    {
        char USN[11];
        float SGPA;
    };

    struct student a[25];
    FILE *file = fopen("student_data.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    for (i = 0; i < size; i++)
    {
        fscanf(file, "%s %f", a[i].USN, &a[i].SGPA);
    }

    fclose(file);

    for (c = 0; c < size - 1; c++)
    {
        for (d = 0; d < size - c - 1; d++)
        {
            if (a[d].SGPA < a[d + 1].SGPA)
            {
                swapSGPA = a[d].SGPA;
                strcpy(swapUSN, a[d].USN);
                a[d].SGPA = a[d + 1].SGPA;
                strcpy(a[d].USN, a[d + 1].USN);
                a[d + 1].SGPA = swapSGPA;
                strcpy(a[d + 1].USN, swapUSN);
            }
        }
    }

    printf("\nSorted student data based on SGPA:\n");
    for (i = 0; i < size; i++)
    {
       // printf("Student %d\t", i + 1);
        printf("USN: %s\t\t", a[i].USN);
        printf("SGPA: %f\n", a[i].SGPA);
    }

    return 0;
}

