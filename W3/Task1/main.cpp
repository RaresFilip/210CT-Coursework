#include <iostream>
#include <string.h>

using namespace std;

void reverse_string (char sentence[50])
{
    char listOfWords[20][20]; // stores the separate words
    int wordCount = 0; // stores the number of separated words

    //separating the words from the string with the help of the space (" ") delimiter
    //and the storing every word in the listOfWords matrix
    char * word;
    word = strtok (sentence," ");
    while (word != NULL)
    {
        strcpy(listOfWords[wordCount], word);
        wordCount++;
        word = strtok (NULL, " ");
    }

    // printing the words in the list in descending order
    // "i" begins from "wordCount-1" because before the word pointer gets NULL it gets and "extra word" in
    for(int i=wordCount-1;i>=0;i--)
        cout<<listOfWords[i]<<" ";
}

int main()
{
    char theString[50];
    cout<<"Please write a sentence: ";
    cin.getline(theString, 50);
    reverse_string(theString);

    return 0;
}
