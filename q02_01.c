// 12S23030 - SimorangkirJonathan
// 12S23045 - Chyntia Reginauli rajaguguk

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv){
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));
    char input[100];
    char id[12];
    char student_name[40];
    char year[5];
    char dorm_name[40];
    unsigned short capacity;
    char *masukan;
    int data_student, data_dorm;
    int stdnt=0, drm=0;

    while (true)
    {
        fflush(stdin);
        input[0] = '\0';
        int c = 0;
        do
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        } while (true);

        masukan = strtok(input, "#");
        if(strcmp(masukan, "---")==0){
            break;
        } else if (strcmp(masukan, "student-print-all")==0) {
            void (*pf)(struct student_t *_student, int count) = NULL;
            pf = print_student;
            pf(students, stdnt);

        } else if (strcmp(masukan, "student-print-all-detail")==0) {
            void (*pf)(struct student_t *_student, int count) = NULL;
            pf = print_student_detail;
            pf(students, stdnt);

        } else if (strcmp(masukan, "student-add")==0){
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(student_name, masukan);
            masukan = strtok(NULL, "#");
            strcpy(year, masukan);
            masukan = strtok(NULL, "#");
            if (strcmp(masukan, "male")==0){
                struct student_t (*pf)(char *_id, char *_name, char *_year,enum gender_t _gender) = NULL;
                pf = create_student;
                students[stdnt] = pf(id, student_name, year, GENDER_MALE);
            } else if (strcmp(masukan, "female")==0){
                struct student_t (*pf)(char *_id, char *_name, char *_year,enum gender_t _gender) = NULL;
                pf = create_student;
                students[stdnt] = pf(id, student_name, year, GENDER_FEMALE);
            }
            stdnt++;

        } else if (strcmp(masukan, "dorm-print-all")==0) {
            void (*pf)(struct dorm_t *_dorm, int count) = NULL;
            pf = print_dorm;
            pf(dorms, drm);

        } else if (strcmp(masukan, "dorm-print-all-detail")==0) {
            void (*pf)(struct dorm_t *_dorm, int count) = NULL;
            pf = print_dorm_detail;
            pf(dorms, drm);

        } else if (strcmp(masukan, "dorm-add")==0){
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            masukan = strtok(NULL, "#");
            capacity = atoi(masukan);
            masukan = strtok(NULL, "#");
            if (strcmp(masukan, "male")==0){
                struct dorm_t (*pf)(char *_name, unsigned short _capacity, enum gender_t _gender) = NULL;
                pf = create_dorm;
                dorms[drm] = pf(dorm_name, capacity, GENDER_MALE);
            } else if (strcmp(masukan, "female")==0){
                struct dorm_t (*pf)(char *_name, unsigned short _capacity, enum gender_t _gender) = NULL;
                pf = create_dorm;
                dorms[drm] = pf(dorm_name, capacity, GENDER_FEMALE);
            }
            drm++;

        } else if (strcmp(masukan, "assign-student")==0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_student = -99;
            data_dorm = -99;
            for (int i = 0; i < stdnt; i++)
            {
                if(strcmp(students[i].id, id)==0){
                    data_student = i;
                    break;
                }
            }

            for (int i = 0; i < stdnt; i++)
            {
                if(strcmp(dorms[i].name, dorm_name)==0){
                    data_dorm = i;
                    break;
                }
            }

            if (data_student!=-99 && data_dorm!=-99)
            {
                void (*pf)(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name) = NULL;
                pf = assign_student;
                pf(&students[data_student], &dorms[data_dorm], id, dorm_name);
            }

        } else if (strcmp(masukan, "move-student")==0) {
            masukan = strtok(NULL, "#");
            strcpy(id, masukan);
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_student = -99;
            data_dorm = -99;
            for (int i = 0; i < stdnt; i++){
                if(strcmp(students[i].id, id)==0){
                    data_student = i;
                    break;
                }
            }

            for (int i = 0; i < drm; i++){
                if(strcmp(dorms[i].name, dorm_name)==0){
                    data_dorm = i;
                    break;
                }
            }

            if (data_student!=-99 && data_dorm!=-99){
                if (students[data_student].dorm==NULL){
                    void (*pf)(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name) = NULL;
                    pf = assign_student;
                    pf(&students[data_student], &dorms[data_dorm], id, dorm_name);

            } else {
                for (int i = 0; i < drm; i++){
                    if(strcmp(students[data_student].dorm->name, dorms[i].name)==0){
                        void (*pf)(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name) = NULL;
                        pf = move_student;
                        pf(&students[data_student], &dorms[data_dorm], &dorms[i], id, dorm_name);
                        break;
                        }
                    }
                }
            }
            
        } else if (strcmp(masukan, "dorm-empty")==0){
            masukan = strtok(NULL, "#");
            strcpy(dorm_name, masukan);
            data_dorm = -99;
            for (int i = 0; i < drm; i++){
                if(strcmp(dorms[i].name, dorm_name)==0){
                    data_dorm = i;
                    break;
                }
            }

            if (data_dorm!=-99){
                void (*pf)(struct student_t *students, struct dorm_t *dorms, int stdnt);
                pf = dorm_empty;
                pf(students, &dorms[data_dorm], stdnt);
            }
        }
    }
    free(students);
    free(dorms);
    return 0;
}