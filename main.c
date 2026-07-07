#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int isIssued; // 0 = available, 1 = issued
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    struct Book b;
    b.id = bookCount + 1;
    printf("Enter book title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter author name: ");
    scanf(" %[^\n]", b.author);
    b.isIssued = 0;
    library[bookCount] = b;
    bookCount++;
    printf("Book added successfully! ID: %d\n", b.id);
}

void viewBooks() {
    if (bookCount == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("\n--- Library Books ---\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
               library[i].id, library[i].title, library[i].author,
               library[i].isIssued ? "Issued" : "Available");
    }
}

void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued) {
                printf("Book already issued.\n");
            } else {
                library[i].isIssued = 1;
                printf("Book issued successfully.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            library[i].isIssued = 0;
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. View Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
