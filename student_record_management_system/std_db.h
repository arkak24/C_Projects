#pragma once

typedef struct student{
      char name[50];
      unsigned long long int roll_no;    // %llu
      unsigned long long int ph_no;
      float CGPA;
      int semester;
      struct student* next_address;
}student;

extern student* head;
extern student* new_student;
extern student* temp;

void add_student(void);
void delete_student(void);
void print_db(void);
void free_list(void);