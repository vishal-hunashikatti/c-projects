/*
 * user_def.h
 *
 *  Created on: Apr 22, 2025
 *      Author: vishal-hunashikatti
 */

#ifndef USER_DEF_H_
#define USER_DEF_H_

#include "common_def.h"

#define MAX_FIRST_NAME_LEN 50
#define MAX_LAST_NAME_LEN 50
#define MAX_EMAIL_ID_LEN 75
#define MAX_UNIQUE_UID_LEN 6

typedef struct {
	char first_name[MAX_FIRST_NAME_LEN];
	char last_name[MAX_LAST_NAME_LEN];
	char user_name[MAX_UNIQUE_UID_LEN];
	char email_id[MAX_EMAIL_ID_LEN];
	Date date_of_birth;
	Date borrow_date;
	uint8_t book_count;
}User;


#endif /* USER_DEF_H_ */
