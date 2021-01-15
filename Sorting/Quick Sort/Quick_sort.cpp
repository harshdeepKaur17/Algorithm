#include<iostream>
using namespace std;

void display(int *arr,int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}

void swap(int &a,int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int partition(int *arr,int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;

    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

void quick_sort(int *arr, int lb, int ub)
{
    int pos;
    if(lb<ub)
    {
        pos=partition(arr,lb,ub);
        quick_sort(arr,lb,pos-1);
        quick_sort(arr,pos+1,ub);
    }
}

int main()
{
    int n;
    cout<<"\n Enter the number of elements - ";
    cin>>n;
    int arr[n];

    cout<<"\n Enter the elements - "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<i+1<<"  Element - ";
        cin>>arr[i];
        cout<<endl;
    }

    cout<<"\n Array before sorting : "<<endl;
    display(arr,n);
    quick_sort(arr,0,n-1);
    cout<<"\n \n \n Sorted array : "<<endl;
    display(arr,n);
    return 0;
}