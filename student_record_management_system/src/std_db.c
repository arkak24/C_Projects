#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/std_db.h"
#include "../include/file_handler.h"

student* head = NULL;
student* new_student = NULL;
student* temp = NULL;

// static int count_students(void){
//       int count = 0;
//       temp = head;
//       while(temp != NULL){
//             count++;
//             temp = temp -> next_address;
//       }
//       return count;
// }

void add_student(void){

      char nam[50];
      unsigned long long int roll;
      unsigned long long int phone;
      float marks;
      int sem;

      new_student = (student*)malloc(sizeof(student));

      while(getchar() != '\n');  // flush leftover '\n'

      printf("Name : ");
      scanf("%[^\n]", nam);
      strcpy(new_student -> name, nam);

      printf("Roll_no. :  ");
      scanf("%llu", &roll);
      new_student -> roll_no = roll;

      printf("CGPA : ");
      scanf("%f", &marks);
      new_student -> CGPA = marks;

      printf("Phone_Number : ");
      scanf("%llu", &phone);
      new_student -> ph_no = phone;

      printf("Semester : ");
      scanf("%d", &sem);
      new_student -> semester = sem;

      new_student -> next_address = NULL;

      if(head == NULL){
            head = new_student;
      }
      else{
            // temp -> next_address = new_student;
            // don't use it ^ over here
            // during file operations the temp is dangling
            
            temp = head;
            while(temp -> next_address != NULL){
                  temp = temp -> next_address;
            }
            temp -> next_address = new_student;
      }
}

void delete_student(void){

      student* temp_ptr = NULL;
      student* del_ptr = NULL;

      char choice;

      if(head == NULL){
            printf("\nThere is no student to remove from the database !!!\n\n");

            save_database_to_file();

            printf("Do you want to add student to the database ?\n");
            printf("Press 'Y' to add student or 'N' to exit the program : ");
            scanf(" %c", &choice);
            
            if(choice == 'y' || choice =='Y'){
                  printf("\n");
                  add_student();
            }
            else{
                  save_database_to_file();

                  printf("\nThank You for using the program !!!\n\n");
                  free_list();
                  exit(0);
            }
      }

      else{
            unsigned long long int roll_delete;
            printf("Enter the Roll No. of the student to delete : ");
            scanf("%lld", &roll_delete);

            if(head -> next_address == NULL){
                  if(head -> roll_no == roll_delete){
                        printf("Student '%s' deleted from the database!\n\n", head -> name);
                        free(head);
                        head = NULL;
                  }
                  else{
                        printf("No such Roll No. present in the database!\n");
                  }
            }
            else if((head -> roll_no) == roll_delete){
                  del_ptr = head;
                  head = head -> next_address;
                  printf("Student '%s' deleted from the database!\n\n", del_ptr -> name);
                  free(del_ptr);
            }
            else{
                  int found = 0;
                  
                  temp_ptr = head;
                  printf("\n");
                  while((temp_ptr != NULL) && (temp_ptr -> next_address) != NULL){  
                  // (temp_ptr -> next_address) != NULL : consider this for the last node
                        if(((temp_ptr -> next_address) -> roll_no) == roll_delete){
                              found = 1;
                              break;
                        }
                        temp_ptr = temp_ptr -> next_address;
                  }
            
                  if(found == 0){  
                        printf("No such student present in the database!\n\n");
                        return;
                  }
                  else{
                        del_ptr = temp_ptr -> next_address;
                        temp_ptr -> next_address = (temp_ptr -> next_address) -> next_address;
                        printf("Student '%s' deleted from the database!\n\n", del_ptr -> name);
                        free(del_ptr);
                  }
            }
      
            save_database_to_file();
      }
}

void print_db(void){

      printf("\n");
      // see if we can make a table with the titles
      temp = head;
      while(temp != NULL){
            printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
            temp = temp -> next_address;
      }
      printf("\n");
}

void free_list(){

      temp = head;
      while(temp != NULL){
            student* free_memory = temp -> next_address;
            free(temp);
            temp = free_memory;
      }
}