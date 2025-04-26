/*
 * book.c
 *
 *  Created on: April 25, 2025
 *      Author: vishal-hunashikatti
 */

#include "books_def.h"
#include "constants.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// global declarations required for the Users
uint16_t book_count = 0; 
Book book[MAX_BOOK_COUNT];

uint8_t add_book() {
	
	puts("==========================================");
	puts("       Welcome to Book Addition Menu      ");
	puts("   Library Management System - Terminal   ");
	puts("==========================================");
	printf("\n\nPlease enter the new Book details below:\n\n");
	
	printf("Title	: ");
	fgets(book[book_count].title, MAX_TITLE_LEN, stdin);
	book[book_count].title[strcspn(book[book_count].title, "\n")] = 0;
	
	uint8_t author_count = 0;
	printf("\nPlease enter the number of authors for this book : ");
	scanf("%hhu", &author_count);
	if(author_count > MAX_AUTHOR_COUNT) {
		printf("Number of authors more than the limit..\n");
		exit(1);
	}
	for(uint8_t count_auth = 0; count_auth < author_count; count_auth++) {
		printf("Enter author number %hhu : ", count_auth);
		scanf("%s", &book[book_count].author.author_name);
	}
	/*
	printf("Last Name	: ");
	fgets(user[user_count].last_name, MAX_LAST_NAME_LEN, stdin);
	user[user_count].last_name[strcspn(user[user_count].last_name, "\n")] = 0;
	*/
	
	return FUNCTION_EXIT_SUCCESS;
}

