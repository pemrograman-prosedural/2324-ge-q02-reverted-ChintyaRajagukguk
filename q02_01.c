//12S23030 - Simorangkir Jonathan
//12S23045 - Chintya Reginauli Rajaguguk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

#define MAX_INPUT_LENGTH 75

int main(int argc, char **argv)
{
    char input[MAX_INPUT_LENGTH];
    int dorm_count = 0;
    int student_count = 0;
    struct dorm_t *dorms = NULL;
    struct student_t *students = NULL;
    char *token;

    while (1)
    {
        fgets(input, MAX_INPUT_LENGTH, stdin);
        trim_newline(input);

        token = strtok(input, "#");
        if (strcmp(token, "---") == 0)
        {
            break;
        }
        else if (strcmp(token, "dorm-add") == 0)
        {
            dorm_count++;
            dorms = realloc(dorms, dorm_count * sizeof(struct dorm_t));
            dorms[dorm_count - 1] = create_dorm(input);
        }
        else if (strcmp(token, "dorm-print-all") == 0)
        {
            print_all_dorms(dorms, dorm_count);
        }
        else if (strcmp(token, "dorm-print-all-detail") == 0)
        {
            print_all_dorms_detail(dorms, dorm_count);
        }
        else if (strcmp(token, "student-add") == 0)
        {
            student_count++;
            students = realloc(students, student_count * sizeof(struct student_t));
            students[student_count - 1] = create_student(input);
        }
        else if (strcmp(token, "student-print-all") == 0)
        {
            print_all_students(students, student_count);
        }
        else if (strcmp(token, "student-print-all-detail") == 0)
        {
            print_all_students_detail(students, student_count);
        }
        else if (strcmp(token, "assign-student") == 0)
        {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            assign_student(dorms, students, nim, asrama, student_count, dorm_count, find_id, find_dorm);
        }
        else if (strcmp(token, "move-student") == 0)
        {
            char *nim = strtok(NULL, "#");
            char *asrama = strtok(NULL, "#");
            move_student(dorms, students, nim, asrama, student_count, dorm_count, find_id, find_dorm);
        }
        else if (strcmp(token, "dorm-empty") == 0)
        {
            char *asrama = strtok(NULL, "#");
            dorm_empty(asrama, student_count, dorm_count, students, dorms, find_dorm);
        }
    }

    free(students);
    free(dorms);

    return 0;
}

void trim_newline(char *str)
{
    while (*str != '\0' && (*str == '\n' || *str == '\r'))
    {
        *str = '\0';
    }
}

void print_all_dorms(struct dorm_t *dorms, int count)
{
    for (int i = 0; i < count; i++)
    {
        print_dorm(dorms[i]);
    }
}

void print_all_dorms_detail(struct dorm_t *dorms, int count)
{
    for (int i = 0; i < count; i++)
    {
        print_dorm_detail(dorms[i]);
    }
}

void print_all_students(struct student_t *students, int count)
{
    for (int i = 0; i < count; i++)
    {
        print_student(students[i]);
    }
}

void print_all_students_detail(struct student_t *students, int count)
{
    for (int i = 0; i < count; i++)
    {
        print_student_detail(students[i]);
    }
}