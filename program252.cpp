//Source : HEllo WorLd
//Destination : HEW

#include<iostream>

using namespace std;

void strcpyCapitalX(char *Dest, char *src)
{
    while(*src != '\0')
    {
        if((*src >= 'A') && (*src <= 'Z'))
        {
            *Dest = *src;
             Dest++;
            
        }
        src++;
       
        
    }
    *Dest = '\0';
}

int main()
{
    int iRet = 0;
    char Arr[30];
    char Brr[30];
    
    cout<<"Enter the source string : "<<endl;
    cin.getline(Arr,30);

    strcpyCapitalX(Brr, Arr);          //strcpy(200,100)

    cout<<"Destination string is : "<<Brr<<endl;

    return 0;
}

