/*
I/P : no i/p
O/P :    * 
         *  
         *  
         *
*/

#include<iostream>
using namespace std;

//Approach 2 : using while loop
void Display()
{
    int i = 1;
    while(i <= 4)
    {
        cout<<"*"<<endl;
        i++;
    }
}

int main()
{
    Display();

    return 0;
}