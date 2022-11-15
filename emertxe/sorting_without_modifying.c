#include <stdio.h>

void print_sort(int [], int);       //function declration

int main()
{
    int size, iter;

    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the %d elements\n", size);  //elements of array are read
    for (iter = 0; iter < size; iter++)
    {
  scanf("%d", &arr[iter]);
    }

    print_sort(arr, size);         //function call
}
void print_sort(int arr[],int size)     //function defenition
{
    int i,j,small,sec_small,lar;
    printf("After sorting: ");
    small=arr[0];         //small and large values are assigned to 0th index of array
    lar=arr[0]; 
    for(i=0;i<size;i++)  //smallest and largest values in arrays are found
    {
  if(arr[i]<small)
  {
      small=arr[i];
  }
  if(arr[i]>lar)
  {
      lar=arr[i];
  }
    }

    printf("%d ", small);     //smallest value is printed

    sec_small=lar;      //largest value is assigned to sec_small
    for(j=0;j<size-1;j++)
    {
  for(i=0;i<size;i++)
  {
      if(arr[i]>small && arr[i]<sec_small)     //condition to find next just largest to the last value printed
      {
    sec_small=arr[i];
      }
  }
  small=sec_small;
  sec_small=lar;
  printf("%d " , small);       //each time smallest values are printed
    }
    printf("\n");
    printf("Original array values ");
    for(i=0;i<size;i++)       //original array values are printed
    {
  printf("%d ", arr[i]);
    }
    printf("\n");
}
