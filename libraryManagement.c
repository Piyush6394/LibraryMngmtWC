#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to represent a book
struct Book
{
  int id;
  char title[50];
  char author[50];
  int isIssued;
};

struct Book library[MAX];
int count = 0;

// Function to add a new book
void addBook()
{
  if (count >= MAX)
  {
    printf("Library is full!\n");
    return;
  }

  printf("Enter book id: ");
  scanf("%d", &library[count].id);

  printf("Enter book title: ");
  scanf(" %[^\n]s", library[count].title);

  printf("Enter author name: ");
  scanf(" %[^\n]s", library[count].author);

  library[count].isIssued = 0; // Book is not issued initially
  count++;

  printf("Book added successfully!\n");
}

// Function to search a book by its id
void searchBook()
{
  int id;
  printf("Enter book id to search: ");
  scanf("%d", &id);

  for (int i = 0; i < count; i++)
  {
    if (library[i].id == id)
    {
      printf("Book found:\n");
      printf("ID: %d\n", library[i].id);
      printf("Title: %s\n", library[i].title);
      printf("Author: %s\n", library[i].author);
      printf("Issued: %s\n", library[i].isIssued ? "Yes" : "No");
      return;
    }
  }
  printf("Book not found.\n");
}

// Function to display all books
void displayBooks()
{
  if (count == 0)
  {
    printf("No books in the library.\n");
    return;
  }

  printf("Books in the library:\n");
  for (int i = 0; i < count; i++)
  {
    printf("\nID: %d\n", library[i].id);
    printf("Title: %s\n", library[i].title);
    printf("Author: %s\n", library[i].author);
    printf("Issued: %s\n", library[i].isIssued ? "Yes" : "No");
  }
}

// Function to issue a book
void issueBook()
{
  int id;
  printf("Enter book id to issue: ");
  scanf("%d", &id);

  for (int i = 0; i < count; i++)
  {
    if (library[i].id == id)
    {
      if (library[i].isIssued == 1)
      {
        printf("Book is already issued.\n");
      }
      else
      {
        library[i].isIssued = 1;
        printf("Book issued successfully.\n");
      }
      return;
    }
  }
  printf("Book not found.\n");
}

// Function to return a book
void returnBook()
{
  int id;
  printf("Enter book id to return: ");
  scanf("%d", &id);

  for (int i = 0; i < count; i++)
  {
    if (library[i].id == id)
    {
      if (library[i].isIssued == 0)
      {
        printf("Book is not issued.\n");
      }
      else
      {
        library[i].isIssued = 0;
        printf("Book returned successfully.\n");
      }
      return;
    }
  }
  printf("Book not found.\n");
}

// Main menu
int main()
{
  int choice;

  while (1)
  {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Search Book\n");
    printf("3. Display Books\n");
    printf("4. Issue Book\n");
    printf("5. Return Book\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      addBook();
      break;
    case 2:
      searchBook();
      break;
    case 3:
      displayBooks();
      break;
    case 4:
      issueBook();
      break;
    case 5:
      returnBook();
      break;
    case 6:
      exit(0);
      break;
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}