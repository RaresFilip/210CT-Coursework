#include <iostream>

using namespace std;

int main()
{
    int n, a[20], indc, lengMax, currLeng;
    cout<<"Insert the number of elements: ";
    cin>>n;
    cout<<"Insert the elements: \n";

    currLeng = 0;
    lengMax = 0;

    //reading the array
    for(int i=1;i<=n;i++)
        cin>>a[i];

    //finding and counting sub-sequences
    for(int i=1;i<=n;i++)
        if(a[i]<a[i+1])
            {
                currLeng++;
                if(i==n)        // this condition tests if the last subsequence is the biggest one and if it is, make sure that the "currLeng" variable
                {               // is updating properly in order to correctly compare it with "lengMax"
                    if(currLeng>lengMax)
                    {
                        lengMax = currLeng;
                        indc = i - lengMax + 1;
                    }
                }
            }
        else
        {
            currLeng++;
            if(currLeng>lengMax)
            {
                lengMax = currLeng;
                indc = i - lengMax + 1;
                currLeng = 0;
            }
            else
                currLeng = 0;
        }

    for(int i=indc;i<lengMax+indc;i++)
        cout<<a[i]<<" ";

    return 0;
}
