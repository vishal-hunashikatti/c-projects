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
		return FAILURE_EXIT;
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
	
	uint8_t attempts_month = 0;
	while(attempts_month < 3) {
		// printf("\nPlease enter the Date of birth of the user: ");	
		printf("Month		: ");
		scanf("%d", &user[user_count].date_of_birth.month);		
		
		if(is_valid_month(user[user_count].date_of_birth.month))	{
			break;
		} else {
			attempts_month++;
			printf("Invalid month entered.\n");
			printf("You have %hd attempt(s) left.\n", 3 - attempts_month);
		}
	}
	if(attempts_month == 3) {
		printf("ERROR : Invalid month entered 3 times. Exiting add user function...");
		return FAILURE_EXIT;
	}
	
	uint8_t attempts_date = 0;
	while(attempts_date < 3) {
		// printf("\nPlease enter the Date of birth of the user: ");	
		printf("Date		: ");
		scanf("%hhu", &user[user_count].date_of_birth.day);		
		
		if(is_valid_day(user[user_count].date_of_birth.day, user[user_count].date_of_birth.month))	{
			break;
		} else {
			attempts_date++;
			printf("Invalid date entered.\n");
			printf("You have %hd attempt(s) left.\n", 3 - attempts_date);
		}
	}
	if(attempts_date == 3) {
		printf("ERROR : Invalid date entered 3 times. Exiting add user function...");
		return FAILURE_EXIT;
	}
	
	printf("\nName		: %s %s", user[user_count].first_name, user[user_count].last_name);
	printf("\nEmail ID	: %s", user[user_count].email_id);
	printf("\nDate of Birth	: %hhu %s, %hd", user[user_count].date_of_birth.day, 
												   get_month_name(user[user_count].date_of_birth.month),
												   user[user_count].date_of_birth.year);		
	return SUCCESS_EXIT;
}