#include <stdio.h>

void merging(int low, int mid, int high, int nums[]) {
    int temp[high - low + 1];
    int i = low, l1 = low, l2 = mid + 1;

    while (l1 <= mid && l2 <= high) {
        if (nums[l1] <= nums[l2])
            temp[i++] = nums[l1++];
        else
            temp[i++] = nums[l2++];
    }

    while (l1 <= mid)
        temp[i++] = nums[l1++];

    while (l2 <= high)
        temp[i++] = nums[l2++];

    for (i = low; i <= high; i++)
        nums[i] = temp[i];
}

void sort(int low, int high, int nums[]) {
    if (low < high) {
        int mid = (low + high) / 2;
        sort(low, mid, nums);
        sort(mid + 1, high, nums);
        merging(low, mid, high, nums);
    }
}

int main() {
    int nums[] = {11, 2, 4, 6, 8};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Unsorted numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    sort(0, size - 1, nums);

    printf("\nSorted numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
