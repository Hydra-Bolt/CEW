#include <stdio.h>
#include <string.h>

// Function prototypes
void swapElements();
void reverseString();
void inputAndPrintArray();
void searchElement();
void addMatrices();

int main() {
    int choice;

    do {
        printf("\n*** Menu ***\n");
        printf("1. Swap elements using call by reference\n");
        printf("2. Print a string in reverse using pointers\n");
        printf("3. Input and print array elements using pointers\n");
        printf("4. Search for an element in an array using pointers\n");
        printf("5. Add two matrices using pointers\n");
        printf("0. Exit\n");

        printf("\nEnter your choice (0-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                swapElements();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                inputAndPrintArray();
                break;
            case 4:
                searchElement();
                break;
            case 5:
                addMatrices();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 0 and 5.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Function definitions
void swapElements() {
    #include <stdio.h>

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int num1 = 10, num2 = 20;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
}

void reverseString() {
    #include <stdio.h>
    #include <string.h>

    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Reversed string: ");

    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
}

void inputAndPrintArray() {
    #include <stdio.h>

    int arr[5];

    printf("Enter 5 elements:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", arr + i);
    }

    printf("Elements in the array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }

    printf("\n");
}

void searchElement() {
    #include <stdio.h>

    int arr[5] = {10, 20, 30, 40, 50};
    int searchElement, *ptr;

    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    for (ptr = arr; ptr < arr + 5; ptr++) {
        if (*ptr == searchElement) {
            printf("Element found in the array.\n");
            break;
        }
    }

    if (ptr == arr + 5) {
        printf("Element not found in the array.\n");
    }
}

void addMatrices() {
    #include <stdio.h>

    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3], i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            *(*(result + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }

    printf("Resultant Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", *(*(result + i) + j));
        }
        printf("\n");
    }
}
