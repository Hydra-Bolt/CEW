#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char email[50];
    char phone[15];
};

void addContact(struct Contact **addressBook, int *numContacts) {
    (*numContacts)++;
    *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

    if (*addressBook == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter name: ");
    scanf("%s", (*addressBook)[*numContacts - 1].name);

    printf("Enter email: ");
    scanf("%s", (*addressBook)[*numContacts - 1].email);

    printf("Enter phone number: ");
    scanf("%s", (*addressBook)[*numContacts - 1].phone);

    printf("Contact added successfully!\n");
}

void deleteContact(struct Contact **addressBook, int *numContacts) {
    if (*numContacts == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    char nameToDelete[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", nameToDelete);

    int found = 0;

    for (int i = 0; i < *numContacts; ++i) {
        if (strcmp((*addressBook)[i].name, nameToDelete) == 0) {
            found = 1;

            for (int j = i; j < *numContacts - 1; ++j) {
                strcpy((*addressBook)[j].name, (*addressBook)[j + 1].name);
                strcpy((*addressBook)[j].email, (*addressBook)[j + 1].email);
                strcpy((*addressBook)[j].phone, (*addressBook)[j + 1].phone);
            }

            (*numContacts)--;

            *addressBook = realloc(*addressBook, (*numContacts) * sizeof(struct Contact));

            if (*numContacts > 0 && *addressBook == NULL) {
                printf("Memory reallocation failed. Exiting.\n");
                exit(EXIT_FAILURE);
            }

            printf("Contact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void displayContacts(struct Contact *addressBook, int numContacts) {
    if (numContacts == 0) {
        printf("No contacts in the address book.\n");
        return;
    }

    printf("\nAddress Book:\n");
    for (int i = 0; i < numContacts; ++i) {
        printf("Name: %s\n", addressBook[i].name);
        printf("Email: %s\n", addressBook[i].email);
        printf("Phone: %s\n", addressBook[i].phone);
        printf("---------------\n");
    }
}

void freeAddressBook(struct Contact **addressBook) {
    free(*addressBook);
}

int main() {
    struct Contact *addressBook = NULL;
    int numContacts = 0;
    int choice;

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&addressBook, &numContacts);
                break;
            case 2:
                deleteContact(&addressBook, &numContacts);
                break;
            case 3:
                displayContacts(addressBook, numContacts);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    freeAddressBook(&addressBook);

    return 0;
}



struct Node
{
    int data;
    struct Node* next;
};

struct Node *createNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *new_node = createNode(data);
    new_node->next = head;
    return new_node;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *new_node = createNode(data);
    if (head == NULL)
    {
        return new_node; // returning the head node in actuallity
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next; // traverses to the end
    }
    temp->next = new_node; // points the end node to the new node and the node is already pointing to the NULL!
    return head;
}

struct Node *insertAfter(struct Node *head, int data, int search_value)
{
    struct Node *new_node = createNode(data);
    struct Node *temp = head;
    while (temp->next != NULL && temp->data != search_value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Item wasnt in the list");
        free(new_node); // not needed(nice)
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

struct Node *deleteNode(struct Node *head, int search_value)
{
    struct Node *prev = NULL;
    struct Node *temp = head;
    while (temp->next != NULL && temp->data != search_value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Item wasnt in the list");
        return head;
    }
    if (prev == NULL)
    {
        head = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

struct Node* printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp->next != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" %d ->", temp->data);
    printf("NULL\n");
}
// Question 2
struct Node* mergeList(struct Node* l1, struct Node* l2)
{
    struct Node* head_cursor;
    struct Node* cursor;
    if (l2->data > l1->data)
    {
        head_cursor = l1;
        cursor = l2;
    }
    else
    {
        head_cursor = l2;
        cursor = l1;
    }
    struct Node* temp = head_cursor;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp -> next  = cursor;

    return head_cursor;
    
}
// Question 3
int* convertToList(struct Node* head)
{
    int length = 0;
    struct Node* temp = head;
    while (temp-> next != NULL)
    {
        temp = temp->next;
        length++;
    }

    int* arr = (int*)malloc(length+1 * sizeof(int));
    temp = head;
    int c = 0;
    while (temp-> next != NULL)
    {
        arr[c] = temp->data;
        temp = temp->next;
        c++;
    }
    arr[c] = temp->data;
    arr[c+1] = -1;
    return arr; 
}

void printArray(int arr[])
{
    printf("Array: ");
    for (int i = 0; arr[i] != -1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Question 4

struct Node* removeOdd(struct Node* head)
{
    struct Node* temp = head;
    int c = 0;
    while (temp->next != NULL)
    {
        if (c%2 != 0)
        {
            head = deleteNode(head, temp->data);
        }
        temp = temp->next;
        c++;
    }
    return head;
}
int main()
{
    struct Node *l1 = NULL;
    struct Node *l2 = NULL;
    // Insert nodes at the beginning
    l1 = insertAtBeginning(l1, 3);
    l1 = insertAtBeginning(l1, 2);
    l1 = insertAtBeginning(l1, 1);
    // Insert nodes at the end
    l1 = insertAtEnd(l1, 4);
    l1 = insertAtEnd(l1, 5);
    // Insert a node after a specific value
    // l2 = insertAfter(l2, 6, 3);
    l2 = insertAtBeginning(l2, 8);
    l2 = insertAtBeginning(l2, 7);
    l2 = insertAtBeginning(l2, 6);
    // Insert nodes at the end
    l2 = insertAtEnd(l2, 9);
    l2 = insertAtEnd(l2, 10);
    // Insert a node after a specific value
    // Print the linked list
    printf("Linked List: ");
    printList(l1);
    printList(l2);

    l1 = mergeList(l1, l2);

    printList(l1);

    int* arr = convertToList(l1);
    printArray(arr);
    
    l1 = removeOdd(l1);
    printList(l1);
    
}