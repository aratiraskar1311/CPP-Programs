#include<iostream>

using namespace std;

void strcpyX(char *Dest, char *src)
{
    while(*src != '\0')
    {
        *Dest = *src;

        src++;
        Dest++;
    }
    *Dest = '\0';           //\0 pn copy honyasathi
}

int main()
{
    int iRet = 0;
    char Arr[30] = "Hello";
    char Brr[30];
    
    strcpyX(Brr, Arr);          //strcpy(200,100)

    cout<<"copied string is : "<<Brr<<endl;

    return 0;
}

