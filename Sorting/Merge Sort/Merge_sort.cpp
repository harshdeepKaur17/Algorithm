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

void merge(int *arr,int lb,int mid,int ub)
{
    int b[ub];
    int i=lb, j=mid+1,k=lb;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
            k++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    for(int i=lb;i<=ub;i++)
    {
        arr[i]=b[i];
    }
}

void merge_sort(int *arr, int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
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
    merge_sort(arr,0,n-1);
    cout<<"\n \n \n Sorted array : "<<endl;
    display(arr,n);
    return 0;
}