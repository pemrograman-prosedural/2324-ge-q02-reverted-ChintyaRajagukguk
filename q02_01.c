//12S23030 - Simorangkir Jonathan
//12S23045 - Chintya Reginauli Rajaguguk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"

#define MAX_INPUT_LENGTH 75

void process_input(char *input, struct dorm_t *drm, int *zdrm, struct student_t *mhs, int *zstd);

int main(int _argc, char **_argv)
{
    char input[MAX_INPUT_LENGTH];
    int zdrm = 0;
    int zstd = 0;
    struct dorm_t *drm = malloc(sizeof(struct dorm_t) * 1);
    struct student_t *mhs = malloc(sizeof(struct student_t) * 1);

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "---\n") == 0)
        {
            break;
        }
        process_input(input, drm, &zdrm, mhs, &zstd);
    }

    free(drm);
    free(mhs);

    return 0;
}

void process_input(char *input, struct dorm_t *drm, int *zdrm, struct student_t *mhs, int *zstd)
{
    char *token = strtok(input, "#");

    if (strcmp(token, "dorm-add") == 0)
    {
        (*zdrm)++;
        drm = realloc(drm, sizeof(struct dorm_t) * (*zdrm));
        drm[*zdrm - 1] = create_dorm(input);
    }
    else if (strcmp(token, "dorm-print-all") == 0)
    {
        for (int i = 0; i < *zdrm; i++)
        {
            print_dorm(drm[i]);
        }
    }
    else if (strcmp(token, "dorm-print-all-detail") == 0)
    {
        for (int i = 0; i < *zdrm; i++)
        {
            print_dorm_detail(drm[i]);
        }
    }
    else if (strcmp(token, "student-add") == 0)
    {
        (*zstd)++;
        mhs = realloc(mhs, sizeof(struct student_t) * (*zstd));
        mhs[*zstd - 1] = create_student(input);
    }
    else if (strcmp(token, "student-print-all") == 0)
    {
        for (int i = 0; i < *zstd; i++)
        {
            print_student(mhs[i]);
        }
    }
    else if (strcmp(token, "student-print-all-detail") == 0)
    {
        for (int i = 0; i < *zstd; i++)
        {
            print_student_detail(mhs[i]);
        }
    }
    else if (strcmp(token, "assign-student") == 0)
    {
        char *nim = strtok(NULL, "#");
        char *asrama = strtok(NULL, "#");
        assign_student(drm, mhs, nim, asrama, *zstd, *zdrm, find_id, find_dorm);
    }
    else if (strcmp(token, "move-student") == 0)
    {
        char *nim = strtok(NULL, "#");
        char *asrama = strtok(NULL, "#");
        move_student(drm, mhs, nim, asrama, *zstd, *zdrm, find_id, find_dorm);
    }
    else if (strcmp(token, "dorm-empty") == 0)
    {
        char *asrama = strtok(NULL, "#");
        dorm_empty(asrama, *zstd, *zdrm, mhs, drm, find_dorm);
    }
}
