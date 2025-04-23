# Personal Library Management System

## README.md for this project is work in progress

Right now just writing down everything roughly. Will edit later when the whole structure of the project is planned and ready for implementation

## Outline

### Attributes

#### Book Attributes

- **Title**: The name of the book that identifies its content and distinguishes it from other works.
- **Author(s)**: The person or people who wrote or compiled the book's content.
- **ISBN**: A unique commercial book identifier used internationally for tracking and inventory purposes.
- **Genre**: The category or style of literature the book belongs to (fiction, mystery, biography, etc.).
- **Edition**: The version or revision of the book, often indicating updates or changes from previous releases.
- **Translator**: The person who conveys the author's work from its original language to a new audience while preserving its essence and meaning.
- **Language**: The primary language in which the book is written.
- **Page count**: The total number of pages contained in the book.
- **Publisher**: The company or entity responsible for producing and distributing the book.
- **Publication date**: When the book was officially released to the public.
- **Format**: The physical or digital form of the book (hardcover, paperback, library binding).
- **In Data Base**: Date when the book was entered in the database.
- **Issued to**: To whom the book was lent to.
- **Issued on**: Date, when it was lent.
- **Issued by**: Who lent the book.

#### Librarian Attributes

- **Add Book**:
- Delete Book
- Edit Book details
- view library database
- view user database
- view user books and details of the books issued
- issue books
- search database books
- search database users

#### User Attributes

- view database of books
- view borrowed books
- search database books

### Data Base

- Books database
  - All attributes mentioned in the Book Attributes section

- User Database
  - First Name
  - Last Name
  - user name (unique id)
  - email id
  - contact number
  - books borrowed
  - borrowed date
  - book count
  
typedef struct {
	char first_name[MAX_FIRST_NAME_LEN];
	char last_name[MAX_LAST_NAME_LEN];
	char email_id[MAX_EMAIL_ID_LEN];
	uint8_t book_count;
	Date date_of_birth;
	Credential authentication;
}User;