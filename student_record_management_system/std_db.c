#include <stdio.h>
#include <string.h>

#include "std_db.h"

int number_of_students = 0;
students array[10];

void add_student(void){

      if(number_of_students == 9){
            printf("No more students can be added in the database !!!\n\n");
      }

      else{
            printf("Enter the Roll_NO. of the student : ");
            scanf("%d", &array[number_of_students].roll_no);
            while(getchar() != '\n');

            printf("Enter the name of the student : ");
            fgets(array[number_of_students].name, sizeof(array[number_of_students].name), stdin);
            size_t length1 = strlen(array[number_of_students].name);
            if(length1 > 0 && array[number_of_students].name[length1-1] == '\n'){
                  array[number_of_students].name[length1-1] = '\0';
            }
      
            printf("Enter the PH_NO. of the student : ");
            fgets(array[number_of_students].ph_no, sizeof(array[number_of_students].ph_no), stdin);
            size_t length2 = strlen(array[number_of_students].ph_no);
            if(length2 > 0 && array[number_of_students].ph_no[length2-1] == '\n'){
                  array[number_of_students].ph_no[length2-1] = '\0';
            }
      
            printf("Enter the CGPA of the student : ");
            scanf("%f", &array[number_of_students].CGPA);
      
            printf("Enter the year of the student : ");
            scanf("%d", &array[number_of_students].year);
      
            printf("Enter the semester of the student : ");
            scanf("%d", &array[number_of_students].semester);
      
            number_of_students++;

            printf("\nStudent added in the database !!!\n\n");
      }

}

void delete_student(void){

      if(number_of_students == 0){
            printf("\nThere is no student in the database !!!\n\n");
      }

      else{
            printf("\n%d number student deleted from the database\n\n", number_of_students+1);
            number_of_students--;
      }

}

void print_db(void){

      printf("\n\nThe database contains the following students : \n\n");

      for(int i = 0; i < number_of_students; i++){
            
            printf("%2d .", i+1);
            // for name
            // for(int j = 0; array[i].name[j] != '\0'; j++){
            //       printf("%c", array[i].name[j]);
            // }
            printf("%-20s", array[i].name);

            // for roll_no
            printf("%-10d\t", array[i].roll_no);

            // for CGPA
            printf("%-10.2f\t", array[i].CGPA);

            // for semester
            printf("%-10d\n", array[i].semester);
      }

}