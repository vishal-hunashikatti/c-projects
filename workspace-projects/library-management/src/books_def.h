/*
 * books_def.h
 *
 *  Created on: April 22, 2025
 *      Author: vishal-hunashikatti
 */

#ifndef BOOKS_DEF_H_
#define BOOKS_DEF_H_

#include "common_def.h"

typedef struct {
	char author_name[MAX_AUTHOR_COUNT][MAX_AUTHOR_LEN];
	uint8_t author_count;
}Author;

typedef struct {
	char primary_language[MAX_LANGUAGE_LEN];
	char translated_language[MAX_LANGUAGE_LEN];
}Language;

typedef struct {
	char translator_name[MAX_TRANSLATOR_COUNT][MAX_TRANSLATOR_LEN];
	uint8_t translator_count;
}Translator;

typedef struct {
	char 		title[MAX_TITLE_LEN];
	char 		isbn[MAX_ISBN_LEN];
	Author 		author;
	Language 	language;
	uint8_t 	edition;
	char 		genre[MAX_GENRE_LEN];
	Translator 	translator;
	uint16_t 	page_count;
	char 		publisher[MAX_PUBLISHER_LEN];
	Date 		publication_date;
	char 		format[MAX_FORMAT_LEN];
	Date 		in_database;
	char 		user_name[MAX_USER_UID_LEN];
	Date 		lent_date;
}Book;

#endif /* BOOKS_DEF_H_ */
