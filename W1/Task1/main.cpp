#include <iostream>

using namespace std;

int main()
{
    int arr[15],n;

    cout<<"Insert the number of elements:";
    cin>>n;

    cout<<"Give the elements \n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //"shuffle" loop
    for(int i=0;i<n;i++)
    {
        //even numbers go to the right side of the array
        if(arr[i]%2==0&&i!=n-1)
        {
            int pop = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = pop;
        }
        //odd numbers go to the left side of the array
        if(arr[i]%2!=0&&i!=0)
        {
            int pop = arr[i];
            arr[i]=arr[i-1];
            arr[i-1] = pop;
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
