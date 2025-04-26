/*
 * constants.h
 *
 *  Created on: April 23, 2025
 *      Author: vishal-hunashikatti
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/***************************************
 * String Length Limits for Book Fields
 ***************************************/
#define MAX_TITLE_LEN        200  // Maximum characters in a book title
#define MAX_AUTHOR_LEN       50   // Maximum characters in a single author's name
#define MAX_ISBN_LEN         20   // Maximum characters in the ISBN
#define MAX_GENRE_LEN        20   // Maximum characters in the genre name
#define MAX_LANGUAGE_LEN     20   // Maximum characters for a language name
#define MAX_TRANSLATOR_LEN   50   // Maximum characters in a single translator's name
#define MAX_PUBLISHER_LEN    100  // Maximum characters in the publisher's name
#define MAX_FORMAT_LEN       20   // Maximum characters in the book format (e.g., hard-cover, paperback, e-book, library-binding)

/****************************************
 * Count Limits for Multi-entry Book Fields
 ****************************************/
#define MAX_AUTHOR_COUNT     5    // Maximum number of authors per book
#define MAX_TRANSLATOR_COUNT 5    // Maximum number of translators per book

/***************************************
 * String Length Limits for User Fields
 ***************************************/
#define MAX_USER_UID_LEN     7    // Maximum characters in the user UID (user_uid -> user unique ID)
#define MAX_PASSWORD_LEN     50   // Maximum characters in the user's password
#define MAX_FIRST_NAME_LEN   50   // Maximum characters in the user's first name
#define MAX_LAST_NAME_LEN    50   // Maximum characters in the user's last name
#define MAX_EMAIL_ID_LEN     75   // Maximum characters in the user's email address

/****************************************
 * Count Limits for Multi-entry User Fields
 ****************************************/
#define MAX_USER_COUNT 		 255   // Maximum users that can be registered
#define MAX_BOOK_COUNT       2048 // Maximum number of books in the data base

/***************************************
 * Other Configurable Limits
 ***************************************/
#define MAX_BORROWED_BOOKS   2   // Maximum number of books a user can borrow at one time
#define CURRENT_YEAR         2025

// Exit codes for the program
#define FUNCTION_EXIT_SUCCESS     	 1   // Indicates successful execution
#define FUNCTION_EXIT_FAILURE     	 0   // Indicates general failure

#endif /* CONSTANTS_H_ */
