#include <iostream>
#include <string.h>

using namespace std;

char* removeVowels(char s[50], int i)
{
    //the string "s" is the word/phrase parameter
    //the integer "i" is the current letter of the word/phrase
    if(i==strlen(s)||i==strlen(s)+1) // the condition "i==strlen(s)+1 is there in case that the last letter from the string is a vowel and it is removed"
        return s;

    //a while loop is necessary here in order to remove consecutive vowels if there are any
    while(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
        strcpy(s+i,s+i+1);  //the "strcpy" is a function from the "string.h" library which is used when copying one string to another, the attribution operator ("=") is not allowed on strings

    removeVowels(s,i+1);
}

int main()
{
    char inputedString[50];
    cout<<"Please insert a word or a phrase: ";
    cin.getline(inputedString,50);

    cout<<endl<<removeVowels(inputedString, 0);

    return 0;
}
