#include <stdlib.h>
#include <stdio.h>


// Question 1:

// int main()
// {
//     int nums;
//     printf("How many integers: "); scanf("%d", &nums);
//     printf("Using For Loop\n");

//     for (int i=1; i<nums; i+=2)
//     {
//         printf("%d,", i);
//     }
//     printf("\nUsing While Loop\n");

//     int i = 1;

//     while (i<nums)
//     {
//         printf("%d,", i);
//         i+=2;
//     }

//     printf("\nUsing Do While Loop\n");
//     i = 1;

//     do {
//         printf("%d,", i);
//         i+=2;
//     }
//     while (i<nums);

    
// }

// Question 2:
// This one refractors your orignal solution because it can be optimized to use less variables and less memory to run, It uses sliding window approach with conditional statments
// int main()
// {
//     int num;
//     printf("Length of the pyrmid: ");
//     scanf("%d", &num);
//     for (int i = 0; i<num; i++)
//     {
//         for (int j = 0; j<num; j++)
//         {
//             if (i+j>num-2){
//                 printf("* ");
//             }
//             else{
//                 printf(" ");
//             }
//         }
//         printf("\n");
//     }
// }

// Question 2:
// custom function for string length uses the 
// int stringLength(const char *str) {
//     int length = 0;

//     while (str[length] != '\0') {
//         length++;
//     }

//     return length;
// }

// int main()
// {
//     char string1[100];
//     char string2[100];

//     printf("Write first string: ");
//     scanf("%s", string1);
//     printf("Write second string: ");
//     scanf("%s", string2);

//     int len_str1 = stringLength(string1);
//     int len_str2 = stringLength(string2);

//     printf("Common characters in both strings are: ");
//     int count = 0;
//     for (int i = 0; i<len_str1; i++)
//     {
//         for (int j = 0; j<len_str2; j++)
//         {
//             if (string1[i] == string2[j])
//             {
//                 printf("%c, ", string1[i]);
//                 count++;
//             }
//         }
//     }
//     if (count == 0)
//     {
//         printf("No similarity in the strings");
//     }
//     else 
//     {
//         printf("Number of similar characters: %d", count);
//     }

// }