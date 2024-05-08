
#include<stdio.h>
int sorted(int nums[],int size)
{
  for(int i=0;i<size-1;i++)
    {
      for(int j=0;j<size-i-1;j++)
        {
          if(nums[j]>nums[j+1])
          {
            int temp=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=temp;
          }
        }
    }
}
void main()
{
  int nums[]={11,2,3,4,5},size=sizeof(nums)/sizeof(nums[0]);
  printf("The numbers without sorting\n");
  for(int i=0;i<size;i++)
    {
      printf("%d ",nums[i]);
    }
  sorted(nums,size);
  printf("\nsorted numbers\n");
  for(int i=0;i<size;i++)
    {
      printf("%d ",nums[i]);
    }
    printf("\nCoded by @anishvl\n");
}
