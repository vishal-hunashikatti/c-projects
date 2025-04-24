/*
 * common.c
 *
 *  Created on: April 23, 2025
 *      Author: vishal-hunashikatti
 */

#include "common_def.h"
#include "constants.h"

uint16_t get_input_year()	{
	uint8_t attempts = 0;
	uint16_t year = 0;
	while(attempts < 3) {	
		printf("\nYear		: ");
		scanf("%hd", &year);		
		
		if(is_valid_year(year))	{
			break;
		} else {
			attempts++;
			printf("Invalid year entered.\n");
			printf("You have %hd attempt(s) left.\n", 3 - attempts);
		}
	}
	if(attempts == 3) {
		printf("ERROR : Invalid year entered 3 times. Exiting add user function...");
		exit_wait_function();
		exit(1);
	}
	return year;
}

// Helper function to validate year
bool is_valid_year(uint16_t year) {
	return ((year <= CURRENT_YEAR) ? true : false); 
}

uint8_t get_input_month() {
	uint8_t attempts = 0;
	uint8_t month = 0;
	while(attempts < 3) {	
		printf("Month		: ");
		scanf("%hhu", &month);		
		
		if(is_valid_month(month)) {
			break;
		} else {
			attempts++;
			printf("Invalid month entered.\n");
			printf("You have %hhu attempt(s) left.\n", 3 - attempts);
		}
	}
	if(attempts == 3) {
		printf("ERROR : Invalid month entered 3 times. Exiting add user function...");
		exit_wait_function();
		exit(1);
	}
	return month;	
}

bool is_valid_month(uint8_t month) {
	return ((month >= 1 && month <=12) ? true : false);
}

uint8_t get_input_date(Month month) {
	uint8_t attempts = 0;
	uint8_t date = 0;
	while(attempts < 3) {	
		printf("Day		: ");
		scanf("%hhu", &date);		
		
		if(is_valid_day(date, month)) {
			break;
		} else {
			attempts++;
			printf("Invalid date entered.\n");
			printf("You have %hhu attempt(s) left.\n", 3 - attempts);
		}
	}
	if(attempts == 3) {
		printf("ERROR : Invalid date entered 3 times. Exiting add user function...");
		exit_wait_function();
		exit(1);
	}
	return date;
}
bool is_valid_day(uint8_t day, Month month) {	
	uint8_t days_in_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	 if (day < 1 && day > days_in_month[month - 1]) {
        return false;
    }
    return true;
}

// Helper function to convert Month enum to month name
const char* get_month_name(Month month) {
    switch(month) {
        case January: 
        	return "January";
        case February: 
        	return "February";
        case March: 
        	return "March";
        case April: 
        	return "April";
        case May: 
        	return "May";
        case June: 
        	return "June";
        case July: 
        	return "July";
        case August: 
        	return "August";
        case September: 
        	return "September";
        case October: 
        	return "October";
        case November: 
        	return "November";
        case December: 
        	return "December";
        default: return "Invalid Month";
    }
}

void exit_wait_function() {
	printf("\n\nPress Enter to exit the application");
	while (getchar() != '\n')	{}
	getchar();
}
