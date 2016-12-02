#include <iostream>

using namespace std;

int main()
{
    int number, zeros;
    zeros = 0;
    cout<<"Insert the number: ";
    cin>>number;

    for(int powers=5; number/powers>=1; powers*=5)
        zeros += number/powers;
    cout<<"Trailing zeros: "<<zeros;

    return 0;
}
