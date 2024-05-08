#include <stdio.h>

int binarySearch(int arr[], int size, int num) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            return mid; // Element found, return its index
        }

        if (arr[mid] < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num;

    printf("Enter the number to search: ");
    scanf("%d", &num);

    int result = binarySearch(arr, size, num);

    if (result != -1) {
        printf("Element %d found at index %d\n", num, result);
    } else {
        printf("Element %d not found in the array\n", num);
    }

    return 0;
}
