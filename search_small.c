#include <stdio.h>

int search(int nums[], int size, int temp) {for (int i = 0; i < size; i++) {
if (nums[i] == temp) {return i;}}
return -1;}
int main() {
int nums[] = {4, 5, 6, 2, 1, 7, 8, 45, 72, 634, 12},size = sizeof(nums) / sizeof(nums[0]),temp;
printf("Enter a number to search: ");scanf("%d", &temp);
int result = search(nums, size, temp);if (result != -1) {printf("The number is found at index %d\n", result);}
else {printf("Number not found\n");}}
