#include<stdio.h>
typedef struct MAX{
    int left_idx;
    int right_idx;
    int max_sum;
}MAX;

MAX find_max_crossing_subarray(int A[],int low,int mid,int high)
{
    int max_left,max_right;

    int left_sum=-2147483647;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum=sum+A[i];
        if(sum>left_sum){
            left_sum=sum;
            max_left=i;
        }
    }

    int right_sum=-2147483647;
    sum=0;
    for(int j=mid+1;j<=high;j++)
    {
        sum=sum+A[j];
        if(sum>right_sum)
        {
            right_sum=sum;
            max_right=j;
        }
    }

    MAX tmp={max_left,max_right,left_sum+right_sum};
    return tmp;
}
MAX find_maximum_subarray(int A[],int low,int high){
    if(low==high){
        MAX tmp={low,high,A[low]};
        return tmp;
    }
    else
    {
        int mid = (low+high)/2;
        MAX left,right,cross;

        left=find_maximum_subarray(A,low,mid);
        right=find_maximum_subarray(A,mid+1,high);
        cross=find_max_crossing_subarray(A,low,mid,high);

        if(left.max_sum>=right.max_sum&&left.max_sum>=cross.max_sum)
        {
            return left;
        }
        else if(right.max_sum>=left.max_sum&&right.max_sum>=cross.max_sum)
        {
            return right;
        }
        else
        {
            return cross;
        }
    }
}
int main(){
    int A[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5-22,15,-4,7};
    MAX max_sub=find_maximum_subarray(A,0,15);
    printf("배열 A의 최대 부분 배열은 idx : %d ~ idx : %d 까지 이며 그 최대합은 %d 입니다\n",max_sub.left_idx,max_sub.right_idx,max_sub.max_sum);
    for(int i=max_sub.left_idx;i<=max_sub.right_idx;i++)
    {
        printf("%d ",A[i]);
    }
}