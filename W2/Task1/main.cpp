#include <iostream>

using namespace std;

int PERFECT (int n)
{
    int m=2;
    while(n > (m-1)*(m-1))
    {
        if(n == m*m)
            return m*m;
        if(n < m*m)
            return (m-1)*(m-1);
        m++;
    }
}

int main()
{
    int number;
    cout<<"Insert parameter: ";
    cin>>number;
    cout<<"The less or equal perfect square is: "<<PERFECT(number);

    return 0;
}
