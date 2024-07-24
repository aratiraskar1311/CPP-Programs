/*
I/P - Enter string : marvellous
O/P - Display string is :marvellous
*/

#include<iostream>
using namespace std;

int main()
{
    char Arr[30];

    cout<<"Enter string : "<<endl;
    cin.getline(Arr,30);

    cout<<"Display string is :"<<Arr<<endl;

    return 0;
}