#include <iostream>

using namespace std;

int binary_interval (int arr[20], int length, int minInterval, int maxInterval)
{
    int left=0;
    int right=length-1;
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(arr[mid]>=minInterval&&arr[mid]<=maxInterval)
            return 1;
        else
            if(arr[mid]<minInterval)
                left = mid+1;
            else
                if(arr[mid]>maxInterval)
                    right = mid-1;
    }
    return 0;
}

void insertion_sort(int arr[20], int length)
{
    for (int i=0;i<length;i++)
    {
        int key = arr[i];
        int j=i;
        while(j>0 && arr[j-1]>key)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=key;
    }
}

int main()
{
    int length, minimum, maximum;
    int arr[20];
    cout<<"Enter the number of elements of the array: ";
    cin>>length;

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<length;i++)
        cin>>arr[i];
    insertion_sort(arr, length);

    cout<<"Please insert the interval: ";
    cin>>minimum>>maximum;

    if(binary_interval(arr, length, minimum, maximum))
        cout<<"There is an element in this interval";
    else
        cout<<"There is no element in this interval";

    return 0;
}
