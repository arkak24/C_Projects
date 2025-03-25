#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/file_handler.h"

#define FILENAME "database.txt"

void load_database_from_file(void){

      FILE* fp = fopen(FILENAME, "r");
      if(fp == NULL){
            printf("No existing database, starting with a new one!\n");
            return;
      }
      
      student* new_node = NULL;
      student* tail = NULL;

      while(1){

            tail = new_node;

            new_node = (student*)malloc(sizeof(student));
            if (new_node == NULL){
                  printf("Memory allocation failed!\n");
                  break;
            }

            // -------> char name_buffer[100]; // temp buffer for the name

            int result = fscanf(
                  fp,
                  "%[^\t]\t%llu\t%llu\t%f\t%d\n",
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
            // printf("file should be empty\n");   //debug
            fclose(fp);
            return;
      }
      
      student* current = head;
      while(current != NULL){

            // prints student data to the file
            fprintf(fp, "%s\t", current -> name);
            fprintf(fp, "%llu\t", current -> roll_no);
            fprintf(fp, "%llu\t", current -> ph_no);
            fprintf(fp, "%f\t", current -> CGPA);
            fprintf(fp, "%d\n", current -> semester);

            current = current -> next_address;
      }

      fclose(fp);
      // printf("database updated\n"); //debug
}