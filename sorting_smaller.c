#include <stdio.h> 
void sort(int nums[], int size){int temp; for(int i=0;i<size-1;i++){for(int j=0;j<size-i-1;j++)
{if(nums[j]>nums[j+1]){temp = nums[j];nums[j] = nums[j + 1];nums[j + 1] = temp;}}}
}
int main() { int nums[]={5,4,3,2,1},size=sizeof(nums)/sizeof(nums[0]);
for(int i=0;i<size;printf("\n%d",nums[i++]));
sort(nums, size);printf("\nsorted numbers");for(int i = 0; i < size; printf("\n%d", nums[i++]));
}