/*
 ============================================================================
 Name        : library-management.c
 Author      : vishal-hunashikatti
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "common_def.h"
#include "user_def.h"

int main(int argc, char** argv) {
	
	add_user();
	
	printf("\n\nPress Enter to exit the application");
	while (getchar() != '\n')	{}
	getchar();
	
	return EXIT_SUCCESS;
}
