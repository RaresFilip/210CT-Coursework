#include <iostream>

using namespace std;

bool prime (int number, int div)
{
    if(number==div)
        return true;
    if(number%div==0)
        return false;
    prime(number, div+1);
}

int main()
{
    int n;
    cout<<"Please give the number: ";
    cin>>n;

    if(prime(n,2))
        cout<<"Your number is a prime number";
    else
        cout<<"Your number is not a prime number";
    return 0;
}
