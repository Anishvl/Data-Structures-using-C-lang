#include<stdio.h>
int sort(int nums[],int size)
{
  printf("\nsorted numbers");
  int temp;
  for(int i=0;i<size;i++)
    {
      for(int j=i+1;j<size;j++)
        {
          if(nums[i]>nums[j])
          {
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
          }
        }
    }
}
void main()
{
  int nums[]={4,1,6,8,2},size=sizeof(nums)/sizeof(nums[0]);
  printf("unsorted numbers");
  for(int i=0;i<size;i++)
    {
      printf("\n%d",nums[i]);
    }
  sort(nums,size);
  for(int i=0;i<size;i++)
    {
      printf("\n%d",nums[i]);
    }
}