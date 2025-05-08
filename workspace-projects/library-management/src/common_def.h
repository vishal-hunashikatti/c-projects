/*
 * common_def.h
 *
 *  Created on: April 22, 2025
 *      Author: vishal-hunashikatti
 */

#ifndef COMMON_DEF_H_
#define COMMON_DEF_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "constants.h"

typedef struct {
	char user_uid[MAX_USER_UID_LEN];
	char user_password[MAX_PASSWORD_LEN];
	bool is_admin;
}Credential;

typedef enum {
	January = 1, February, March, April, May, June, 
	July, August, September, October, November, December
}Month;

typedef struct {
	uint16_t 	year;
	Month 		month;
	uint8_t 	date;	
}Date;

// Common function declarations
uint16_t get_input_year();
bool is_valid_year(uint16_t);
uint8_t get_input_month();
bool is_valid_month(uint8_t);
uint8_t get_input_date(uint16_t, Month);
bool is_valid_day(uint16_t, Month, uint8_t);
const char *get_month_name(Month);
void exit_wait_function();

#endif /* COMMON_DEF_H_ */
