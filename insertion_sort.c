//Insertion Sort
#include<stdio.h>
int sorted(int nums[], int size) {
  int j = 0, i = 0, key = 0;
  for (int i = 0; i < size; i++) {
    key = nums[i];
    j = i - 1;
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
  }
}

void main()
{
  int nums[]={7,3,2,1,6,4},size=sizeof(nums)/sizeof(nums[0]);
  printf("The unsorted numbers\n");
  for(int i=0;i<size;i++)
    {
      printf("%d ",nums[i]);
    }
  sorted(nums,size);
  printf("\nSorted numbers\n");
  for(int i=0;i<size;i++)
    {
      printf("%d ",nums[i]);
    }
  printf("\nCoded by @anishvl\n");
}