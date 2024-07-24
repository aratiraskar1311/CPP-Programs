/*
I/P  -   Enter the source string : mrvellous multi

O/P  -   Destination string is : Hello mrvellous multi
*/

#include<iostream>

using namespace std;

void strcatX(char *Dest, char *src)
{
    while(*Dest != '\0')
    {
        Dest++;
    }
    while(*src != '\0')
    {
        *Dest = *src;
        src++;
        Dest++;
        
    }

    *Dest = '\0';
}

int main()
{
    int iRet = 0;
    char Arr[30];
    char Brr[30] = "Hello ";
    
    cout<<"Enter the source string : "<<endl;
    cin.getline(Arr,30);

    strcatX(Brr, Arr);          //strcpy(200,100)

    cout<<"Destination string is : "<<Brr<<endl;

    return 0;
}

