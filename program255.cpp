#include<iostream>
#include<string.h>
using namespace std;



int main()
{
    char Arr[30] = "Hello World";
    char Brr[30] = "India";
    
    strcat(Brr,Arr);                            //inbuilt function concatenate hota

    cout<<"Detination string : "<<Brr<<endl;

    return 0;
}

