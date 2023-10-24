#include <stdio.h>
#include <stdlib.h>
// Question 1:

int main()
{
    int id;
    float hours_worked, hourly_rate, salary;
    printf("Your Employee Id: ");
    scanf("%d", &id);
    printf("Your Hours Worked: ");
    scanf("%f", &hourly_rate);
    printf("Your Hourly Rate: ");
    scanf("%f", &hourly_rate);
    printf("Report\n\n Employee ID: %d\nSalary for the month:%f\n", id, hourly_rate * hours_worked)
}