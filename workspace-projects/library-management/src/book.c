/*
 * book.c
 *
 *  Created on: April 25, 2025
 *      Author: vishal-hunashikatti
 */

#include "books_def.h"
#include "common_def.h"
#include "constants.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global declarations required for the Users
uint16_t book_count = 0; 
Book book[MAX_BOOK_COUNT];

uint8_t add_book() {
	
	uint8_t translator_count = 0;
	uint8_t author_count = 0;
	uint8_t quantity = 0;
	
	puts("==========================================");
	puts("       Welcome to Book Addition Menu      ");
	puts("   Library Management System - Terminal   ");
	puts("==========================================");
	printf("\n\nPlease enter the new Book details below:\n\n");
	
	printf("Title			: ");
	fgets(book[book_count].title, MAX_TITLE_LEN, stdin);
	book[book_count].title[strcspn(book[book_count].title, "\n")] = 0;
		
	printf("\nPlease enter the number of authors for this book : ");
	scanf("%hhu", &author_count);
	
	// Clear leftover '\n' from input buffer
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	printf("ISBN			: ");
	fgets(book[book_count].isbn, MAX_ISBN_LEN, stdin);
	book[book_count].isbn[strcspn(book[book_count].isbn, "\n")] = 0;
	
	printf("\nBook format		: ");
	fgets(book[book_count].book_format, MAX_FORMAT_LEN, stdin);
	book[book_count].book_format[strcspn(book[book_count].book_format, "\n")] = 0;
	
	printf("\nPlease enter the language in which the book was originally written.\n");
	printf("Primary Language	: ");
	fgets(book[book_count].language.primary_language, MAX_LANGUAGE_LEN, stdin);
	book[book_count].language.primary_language[strcspn(book[book_count].language.primary_language, "\n")] = 0;

	printf("Edition			: ");
	scanf("%hhu", &book[book_count].edition);
	while ((ch = getchar()) != '\n' && ch != EOF);

	printf("Quantity		: ");
	scanf("%hhu", &quantity);
	book[book_count].quantity += quantity;
	
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	printf("Genre			: ");
	fgets(book[book_count].genre, MAX_GENRE_LEN, stdin);
	book[book_count].genre[strcspn(book[book_count].genre, "\n")] = 0;
	
	printf("Pages			: ");
	scanf("%hu", &book[book_count].page_count);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	printf("Publisher		: ");
	fgets(book[book_count].publisher, MAX_PUBLISHER_LEN, stdin);
	book[book_count].publisher[strcspn(book[book_count].publisher, "\n")] = 0;
	
	if(author_count > MAX_AUTHOR_COUNT) {
		printf("Number of authors more than the limit..\n");
		exit_wait_function();
		exit(1);
	} else {
		for(uint8_t author_counter = 0; author_counter < author_count; author_counter++) {
			printf("Enter author %hhu 		: ", (author_counter + 1));
			fgets(book[book_count].author[author_counter], MAX_AUTHOR_LEN, stdin);
			book[book_count].author[author_counter][strcspn(book[book_count].author[author_counter], "\n")] = 0;
			++book[book_count].author_count;		
		}
	}

	printf("\nLeave blank if there is no translated language.\n");
	printf("Translated Language	: ");
	fgets(book[book_count].language.translated_language, MAX_LANGUAGE_LEN, stdin);
	book[book_count].language.translated_language[strcspn(book[book_count].language.translated_language, "\n")] = 0;
/*	
	printf("\nIf the book is translated version, name the authors who translated the original work.\n");
	printf("Are translators available for this book (\"Y/y for yes\"): ");
	char translator_availabe = '\0';
	scanf("%c", &translator_availabe);
	while ((ch = getchar()) != '\n' && ch != EOF);
*/	
//	if(translator_availabe == 'Y' || translator_availabe == 'y') {
	if(strcmp(book[book_count].language.translated_language, "\0")) {
		printf("\nPlease enter the number of authors for this book : ");
		scanf("%hhu", &translator_count);
	
		// Clear leftover '\n' from input buffer
		while ((ch = getchar()) != '\n' && ch != EOF);
	
		if(translator_count > MAX_TRANSLATOR_COUNT) {
			printf("Number of translators more than the limit..\n");
			exit_wait_function();
			exit(1);
		} else {
			for(uint8_t translator_counter = 0; translator_counter < translator_count; translator_counter++) {
				printf("Enter translator %hhu 	: ", (translator_counter + 1));
				fgets(book[book_count].translator[translator_counter], MAX_AUTHOR_LEN, stdin);
				book[book_count].author[translator_counter][strcspn(book[book_count].author[translator_counter], "\n")] = 0;
				++book[book_count].translator_count;		
			}
		}	
	}
		
	printf("Publication date :		");
	book[book_count].publication_date.year = get_input_year();
	book[book_count].publication_date.month = get_input_month();
	book[book_count].publication_date.date = get_input_date(book[book_count].publication_date.year, book[book_count].publication_date.month);
	while ((ch = getchar()) != '\n' && ch != EOF);
		
	printf("\nBook added to database on date :		");
	book[book_count].indatabase_date.year = get_input_year();
	book[book_count].indatabase_date.month = get_input_month();
	book[book_count].indatabase_date.date = get_input_date(book[book_count].indatabase_date.year, book[book_count].indatabase_date.month);
	while ((ch = getchar()) != '\n' && ch != EOF);
	
	printf("\n\nThe details of the book added to the data base :\n\n");
	printf("Title			: %s", book[book_count].title);
	printf("\nAuthors			: ");
	for(uint8_t author_counter = 0; author_counter < author_count; author_counter++) {
		printf("%s(%hhu)", book[book_count].author[author_counter], (author_counter + 1));
		if((author_counter+1) < author_count) {
			//printf(", ");
			printf("\n\t\t\t  ");
		}
	}	
	
	return FUNCTION_EXIT_SUCCESS;
}
