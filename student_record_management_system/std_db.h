#pragma once

typedef struct student_details{
      char name[50];
      char ph_no[15];
      float CGPA;
      int roll_no;
      int year;
      int semester;
}students;

extern students array[10];     // try to use linked list in the updated version

extern int number_of_students;

void add_student(void);
void delete_student(void);
void print_db(void);