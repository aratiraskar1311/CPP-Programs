//Linear LinkedList - Stack using CPP

/*

Elements of stack are :
40
30
20
10

Number of elements in the stack are : 4
Poped element is : 40
Poped element is : 30
Elements of stack are :
20
10

Number of elements in the stack are : 2

*/


#include<iostream>
using namespace std;

template <class T>
struct nodeSTACK
{
    T data;
    struct nodeSTACK *next;
};

template <class T>
class Stack
{
    private:
        struct nodeSTACK<T> * First;
        int iCount;

    public:
        Stack();
        void Display();
        int Count();
        void Push(T No);          //InsertFirst()
        int Pop();                  //DeleteFirst()

};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeSTACK<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeSTACK<T> * newn = NULL;

    newn = new nodeSTACK<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    iCount++;
}   

template <class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeSTACK<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First -> data;
        First = First -> next;
        delete temp;

        iCount--;
    }
    return iValue;
}

int main()
{
    Stack<int> *obj = new Stack<int>();
    int iRet = 0;

    obj->Push(10);
    obj->Push(20);
    obj->Push(30);
    obj->Push(40);

    obj->Display();

    iRet = obj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iRet = obj->Pop();
    cout<<"Poped element is : "<<iRet<<"\n";

    iRet = obj->Pop();
    cout<<"Poped element is : "<<iRet<<"\n";

    obj->Display();

    iRet = obj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";



    return 0;
}