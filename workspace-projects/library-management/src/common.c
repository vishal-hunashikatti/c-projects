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
	bool is_input_valid = false;
	while(attempts < 3) {	
		printf("\nYear		: ");
		scanf("%hd", &year);		
		
		if(is_valid_year(year))	{
			is_input_valid = true;
			break;
		} else {
			attempts++;
			printf("Invalid year entered.\n");
			printf("You have %hd attempt(s) left.\n", 3 - attempts);
		}
	}
	
	if(attempts == 3) {
		printf("ERROR : Invalid year entered 3 times. Exiting add user function...");
		is_input_valid = false;
	}
	
	return is_input_valid ? year : year;
}

// Helper function to validate year
bool is_valid_year(uint16_t year) {
	return ((year <= CURRENT_YEAR) ? true : false); 
}

bool is_valid_month(uint8_t month) {
	return ((month >= 1 && month <=12) ? true : false);
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
