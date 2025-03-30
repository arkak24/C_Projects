#include <stdio.h>
#include <stdlib.h>

#include "../include/search.h" 
#include "../include/main_menu.h"
#include "../include/file_handler.h"

static void search_by_name(void){
      char temp_name[50];
      getchar();
      printf("Enter the full name of the student : ");
      scanf("%[^\n]", temp_name);

      int found = 0;

      student* temp4 = NULL;

      if(head == NULL){
            printf("No student present in the database!\n");
      }
      else{
            temp4 = head;
            printf("\n");
            while(temp4 != NULL){
                  int i = 0;
                  while(((temp4 -> name)[i] != '\0') && (temp_name[i] != '\0')){
                        if (((temp4 -> name)[i] != temp_name[i]) && ((temp4 -> name)[i] != temp_name[i]+32) && ((temp4 -> name)[i]+32 != temp_name[i])){
                              // found = 0;
                              // if found present then it also updates itself until the last student name is checked
                              break;
                        }
                        i++; 
                  }
                  if((temp4 -> name)[i] == '\0' && temp_name[i] == '\0'){
                        printf("%s\t%llu\t%f\t%llu\t%d\n", temp4 -> name, temp4 -> roll_no, temp4 -> CGPA, temp4 -> ph_no, temp4 -> semester);
                        found = 1;
                  }
                  temp4 = temp4 -> next_address;
            }
      }

      if(found == 0){
            printf("No such student present in the database!\n\n");
      }
}

static void search_by_roll_no(void){      
      unsigned long long int roll;
      printf("Enter the Roll No. of the student : ");
      scanf("%lld", &roll);

      int found = 0;

      student* temp1 = NULL;

      if(head == NULL){
            printf("No student present in the database!\n");
      }
      else{
            temp1 = head;
            printf("\n");
            while(temp1 != NULL){
                  if(roll == (temp1 -> roll_no)){
                        printf("%s\t%llu\t%f\t%llu\t%d\n", temp1 -> name, temp1 -> roll_no, temp1 -> CGPA, temp1 -> ph_no, temp1 -> semester);
                        found = 1;
                        break;
                  }
                  temp1 = temp1 -> next_address;
            }
      }

      if(found == 0){
            printf("No such student present in the database!\n\n");
      }
}

static void search_by_cgpa_range(void){   
      float lower_bound, upper_bound;
      int found = 0;

      printf("\nEnter the lower bound : ");
      scanf("%f", &lower_bound);
      printf("Enter the upper bound : ");
      scanf("%f", &upper_bound);
      printf("\n");

      student* temp2 = NULL;

      if(head == NULL){
            printf("\nNo student present in the database!\n");
      }
      else{
            temp2 = head;
            while(temp2 != NULL){
                  if((temp2 -> CGPA >= lower_bound) && (temp2 -> CGPA <= upper_bound)){
                        printf("%s\t%llu\t%f\t%llu\t%d\n", temp2 -> name, temp2 -> roll_no, temp2 -> CGPA, temp2 -> ph_no, temp2 -> semester);
                        found = 1;
                  }
                  temp2 = temp2 -> next_address;
            }
      }
      
      if(found == 0){
            printf("No such student present in the database!\n\n");
      }
}

static void search_by_semester(void){     
      int sem;
      printf("Enter the semester : ");
      scanf("%d", &sem);
      printf("\n");
      int found = 0;

      student* temp3 = NULL;

      if(head == NULL){
            printf("No student present in the database!\n");
      }
      else{
            temp3 = head;
            while(temp3 != NULL){
                  if(sem == (temp3 -> semester)){
                        printf("%s\t%llu\t%f\t%llu\t%d\n", temp3 -> name, temp3 -> roll_no, temp3 -> CGPA, temp3 -> ph_no, temp3 -> semester);
                        found = 1;
                  }
                  temp3 = temp3 -> next_address;
            }
      }
      if(found == 0){
            printf("No such student present in the database!\n\n");
      }
}

void search_student(void){
      int choice;

      while(1){
            printf("\n\n<----------SEARCH_MENU---------->\n\n");
            printf("1. Search by Name\n");
            printf("2. Search by Roll_No.\n");
            printf("3. Search by CGPA range\n");
            printf("4. Search by Semester\n");
            printf("5. BacK to MAIN MENU\n");
            printf("6. Exit program\n\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch(choice){
                  case 1 : search_by_name();
                  break;

                  case 2 : search_by_roll_no();
                  break;

                  case 3 : search_by_cgpa_range();
                  break;

                  case 4 : search_by_semester();
                  break;

                  case 5 : main_menu();
                  break;

                  case 6 : save_database_to_file();
                  exit(0);
                  break;

                  default : printf("Invalid input!!!\n");
            }
      }
}