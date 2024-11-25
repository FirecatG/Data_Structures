#include <iostream>
#include<vector>

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void quicksort(int* times,int left,int right,int* nums)
{
    if(left>=right)
        return;
    int i=left,j=right;
    while(i<j)
    {
        while((i<j)&&(times[j]>times[left]||(times[j]==times[left] &&nums[j]>=nums[left])))
            j--;
        while((i<j)&&(times[i]<times[left]||(times[i]==times[left] &&nums[i]<=nums[left])))
            i++;
        swap(times[i],times[j]);
        swap(nums[i],nums[j]);
    }
    swap(times[i],times[left]);
    swap(nums[i],nums[left]);
    quicksort(times,left,i-1,nums);
    quicksort(times,i+1,right,nums);
}

int main()
{
    int n,k,time;
    scanf("%d %d\n",&n,&k);
    int times[n];
    int numbers[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&time);
        times[i]=time%k?1+time/k:time/k;
        numbers[i]=i;
    }
    quicksort(times,0,n-1,numbers);
    for(int i=0;i<n;i++)
        printf("%d ",numbers[i]);
    return 0;

}