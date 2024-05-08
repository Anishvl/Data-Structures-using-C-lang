#include <stdio.h>

void sort(int len, int num[]) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}

int search(int num[], int len, int number) {
    for (int i = 0; i < len; i++) {
        if (num[i] == number) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int len;
    char ans[10];
    printf("Enter the size of the array: ");
    scanf("%d", &len);
    int num[len];
    printf("Enter %d elements:\n", len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &num[i]);
    }
    printf("\nEnter 'sort' or 'search': ");
    scanf("%s", ans);
    if (strcmp(ans, "sort") == 0) {
        sort(len, num);
        printf("\nSorted list: ");
        for (int i = 0; i < len; i++) {
            printf("%d ", num[i]);
        }
    } else if (strcmp(ans, "search") == 0) {
        int number;
        printf("\nEnter the number to search: ");
        scanf("%d", &number);
        int index = search(num, len, number);
        if (index != -1) {
            printf("\nThe number %d found at index %d", number, index);
        } else {
            printf("\nNumber not found in the given list");
        }
    } else {
        printf("\nInvalid option");
    }
    
    return 0;
}
