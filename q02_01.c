//12S23030 - SimorangkirJonathan
//12S23045 - Chintya ReginaUli Rajagukguk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"


token = strtok(input, "#");
if (strcmp(token, "---") == 0)
{
  break;
}
else if (strcmp(token, "dorm-add") == 0)
{
  size++;
  drm = realloc(drm, size * sizeof(struct dorm_t));
  drm[zdrm] = create_dorm(input);
  zdrm++;
}
else if (strcmp(token, "dorm-print-all") == 0)
{
  for (int m = 0; m < zdrm; m++)
  {
    print_dorm(drm[m]);
  }
}
else if (strcmp(token, "dorm-print-all-detail") == 0)
{
  for (int m = 0; m < zdrm; m++)
  {
    print_dorm_detail(drm[m]);
  }
}
else if (strcmp(token, "student-add") == 0)
{
  sizee++;
  mhs = realloc(mhs, sizee * sizeof(struct student_t));
  mhs[zstd] = create_student(input);
  zstd++;
}
else if (strcmp(token, "student-print-all") == 0)
{
  for (int m = 0; m < zstd; m++)
  {
    print_student(mhs[m]);
  }
}
else if (strcmp(token, "student-print-all-detail") == 0)
{
  for (int m = 0; m < zstd; m++)
  {
    print_student_detail(mhs[m]);
  }
}
else if (strcmp(token, "assign-student") == 0)
{
  char *nim = strtok(NULL, "#");
  char *asrama = strtok(NULL, "#");
  assign_student(drm, mhs, nim, asrama, zstd, zdrm, find_id, find_dorm);
}
else if (strcmp(token, "move-student") == 0)
{
  char *nim = strtok(NULL, "#");
  char *asrama = strtok(NULL, "#");
  move_student(drm, mhs, nim, asrama, zstd, zdrm, find_id, find_dorm);
}
else if (strcmp(token, "dorm-empty") == 0)
{
  char *asrama = strtok(NULL, "#");
  dorm_empty(asrama, zstd, zdrm, mhs, drm, find_dorm);
}