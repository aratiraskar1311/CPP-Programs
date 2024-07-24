//Source : HEllo WorLd
//Destination : lloord

#include<iostream>

using namespace std;

void strcpySmallX(char *Dest, char *src)
{
    while(*src != '\0')
    {
        if((*src >= 'a') && (*src <= 'z'))
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

    strcpySmallX(Brr, Arr);          //strcpy(200,100)

    cout<<"Destination string is : "<<Brr<<endl;

    return 0;
}

