#include "filehandler.h"
#define MAX_LINE_LENGTH 1024

long total_line_numbers(const char *filename){
	FILE *fp = NULL;
	long linecount = 0;
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("filehandler.c: %s unable to be opened by ", filename);
		printf("total_line_numbers()\n");
		return -1;
	}

	char line[MAX_LINE_LENGTH];
	while(fgets(line, MAX_LINE_LENGTH, fp) != NULL){
		linecount++;
	}
	fclose(fp);
	return linecount;
}

/* Note: to free an array of strings, free all elements first */
char** extract_to_string_array(const char *filename){
	char **pointer_to_array = NULL;
	char line[MAX_LINE_LENGTH];
	FILE *fp = NULL;

	/*
	 * Allocating memory for holding <linecount> of chars
	 * (Forming dimension 1 of array)
	 */
	int linecount = (int)total_line_numbers(filename);
	//keep this line around for future debugging
	//printf("malloc-ing size %d\n", linecount * sizeof(char*));
	pointer_to_array = malloc(linecount * sizeof(char*));
	if(pointer_to_array == NULL){
		printf("sorth.c: unable to allocate memory for forming dimension ");
		printf("1 of string array in extract_to_string_array()\n");
		return NULL;
	}

	/*
	 * Copying file contents to array
	 * (Forming dimension 2 of array)
	 */
	fp = fopen(filename, "r");	
	if(fp == NULL){
		printf("sorth.c: %s unable to be opened by ", filename);
		printf("extract_to_string_array() while copying file to str array\n");
		return NULL;
	}
	int i = 0;
	while(fgets(line, MAX_LINE_LENGTH, fp) != NULL){
		pointer_to_array[i] = malloc((strlen(line)+1) * sizeof(char));
		/* 
		 * for greater speed, but less stability on devices with
		 * miniscule heap space, consider commenting the following out
		 */
		if(pointer_to_array[i] == NULL){
			printf("filehandler.c: extract_to_string_array() ran out of ");
			printf("heap space while copying file contents to string array\n");
			return NULL;
		}		
		strcpy(pointer_to_array[i], line);
		i++;
	}
	fclose(fp);

	return pointer_to_array;
}
