#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender){
    struct dorm_t d;
    strcpy(d.name, _name);
    d.capacity = _capacity;
    d.gender = _gender;
    d.residents_num = 0;
    return d;
}

void print_dorm(struct dorm_t *_dorm, int count){
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==GENDER_MALE){
            printf("%s|%d|male\n", _dorm[i].name, _dorm[i].capacity);
        } else if(_dorm[i].gender==GENDER_FEMALE){
            printf("%s|%d|female\n", _dorm[i].name, _dorm[i].capacity);
        }
    }   
}
void print_dorm_detail(struct dorm_t *_dorm, int count){
    for (int i = 0; i < count; i++)
    {
        if (_dorm[i].gender==GENDER_MALE){
            printf("%s|%d|male|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        } else if(_dorm[i].gender==GENDER_FEMALE){
            printf("%s|%d|female|%d\n", _dorm[i].name, _dorm[i].capacity, _dorm[i].residents_num);
        }
    }   
}