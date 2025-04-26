/*
 * user.c
 *
 *  Created on: April 23, 2025
 *      Author: vishal-hunashikatti
 */

#include "common_def.h"
#include "constants.h"
#include "user_def.h"
#include <stdio.h>

// global declarations required for the Users
uint8_t user_count = 0; 
User user[MAX_USER_COUNT];

uint8_t add_user() {
	
	if (user_count >= MAX_USER_COUNT)	{
		printf("ERROR : User limit reached.");
		return FUNCTION_EXIT_FAILURE;
	}
		
	puts("==========================================");
	puts("       Welcome to User Addition Menu      ");
	puts("   Library Management System - Terminal   ");
	puts("==========================================");
	printf("\n\nPlease enter the new user details below:\n\n");
	
	printf("First Name	: ");
	fgets(user[user_count].first_name, MAX_FIRST_NAME_LEN, stdin);
	user[user_count].first_name[strcspn(user[user_count].first_name, "\n")] = 0;

	printf("Last Name	: ");
	fgets(user[user_count].last_name, MAX_LAST_NAME_LEN, stdin);
	user[user_count].last_name[strcspn(user[user_count].last_name, "\n")] = 0;
	
	printf("Email ID	: ");
	fgets(user[user_count].email_id, MAX_EMAIL_ID_LEN, stdin);
	user[user_count].email_id[strcspn(user[user_count].email_id, "\n")] = 0;
		
	// Initialize Book count to 0 to begin with
	user[user_count].book_count = 0;
	
	printf("\nPlease enter the Date of birth of the user: ");
	user[user_count].date_of_birth.year = get_input_year();
	user[user_count].date_of_birth.month = get_input_month();
	user[user_count].date_of_birth.date = get_input_date(user[user_count].date_of_birth.month);
	
	// Assign unique ID to the user
	
	printf("\nName		: %s %s", user[user_count].first_name, user[user_count].last_name);
	printf("\nEmail ID	: %s", user[user_count].email_id);
	printf("\nDate of Birth	: %hhu %s, %hd", user[user_count].date_of_birth.date, 
												   get_month_name(user[user_count].date_of_birth.month),
												   user[user_count].date_of_birth.year);		
	return FUNCTION_EXIT_SUCCESS;
}