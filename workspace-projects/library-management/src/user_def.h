/*
 * user_def.h
 *
 *  Created on: April 22, 2025
 *      Author: vishal-hunashikatti
 */

#ifndef USER_DEF_H_
#define USER_DEF_H_

/******************************************************************************
 * INCLUDES
 *****************************************************************************/
#include "common_def.h"

typedef struct {
	char first_name[MAX_FIRST_NAME_LEN];
	char last_name[MAX_LAST_NAME_LEN];
	char email_id[MAX_EMAIL_ID_LEN];
	uint8_t book_count;
	Date date_of_birth;
	Credential authentication;
}User;

uint8_t add_user();
User* delete_user(Credential);

#endif /* USER_DEF_H_ */
