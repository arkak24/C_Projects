#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/file_handler.h"

#define FILENAME "database.csv"

void load_database_from_file(void){

      FILE* fp = fopen(FILENAME, "r");
      if(fp == NULL){
            printf("No existing database, starting with a new one!\n");
            return;
      }
      
      student* new_node = NULL;
      student* tail = NULL;

      char header[100];
      fgets(header, sizeof(header), fp);

      while(1){

            tail = new_node;

            new_node = (student*)malloc(sizeof(student));

            if (new_node == NULL){
                  printf("Memory allocation failed!\n");
                  break;
            }

            // reading data from the csv file
            int result = fscanf(
                  fp,
                  "%99[^,],%llu,%llu,%f,%d\n",
                  new_node->name,        
                  &new_node->roll_no,     
                  &new_node->ph_no,       
                  &new_node->CGPA,        
                  &new_node->semester     
            );

            if(result != 5){
                  if (feof(fp)){
                        free(new_node);
                        break;
                  }
                  printf("Incorrece Data Sturucture!!!\n\n");
                  free(new_node);
                  break;
            }

            // -------> strcpy(new_node -> name, name_buffer);

            new_node -> next_address = NULL;         

            if(head == NULL){
                  head = new_node;
            }
            else{
                  tail -> next_address = new_node;
            }
      }
      fclose(fp);
}

void save_database_to_file(void){

      FILE* fp = fopen(FILENAME, "w");
      if(fp == NULL){
            printf("Error opening file !!!\n");
            return;
      }

      if(head == NULL){
            fclose(fp);
            return;
      }
      
      student* current = head;

      fprintf(fp, "Name,Roll No,Phone No,CGPA,Semester\n");

      while(current != NULL){

            // prints student data to the file
            fprintf(fp, "%s,", current -> name);
            fprintf(fp, "%llu,", current -> roll_no);
            fprintf(fp, "%llu,", current -> ph_no);
            fprintf(fp, "%f,", current -> CGPA);
            fprintf(fp, "%d\n", current -> semester);

            current = current -> next_address;
      }

      fclose(fp);
}