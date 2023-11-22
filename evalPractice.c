#include <stdio.h>
#include <stdlib.h>

// struct Student {
//     int id;
//     char* name[50];
//     float cgpa;
// };

// void setStudent(struct Student* student)
// {
//     printf("Id: ");
//     scanf("%d", &student->id);
//     printf("First Name: ");
//     scanf("%s", &student->name);
//     printf("CGPA: ");
//     scanf("%f", &student->cgpa);
// }

// void printStudent(struct Student* student)
// {
//     printf("%s with assigned id of %d has the CPGA of %.2f", student->name, student->id, student->cgpa);
// };
// int main()
// {
//     struct Student muneeb;

//     setStudent(&muneeb);
//     printStudent(&muneeb);

// }

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