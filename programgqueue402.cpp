//Singly Linear LL- Queue using CPP

/*
Elements of stack are :
10      20      30      40
Number of elements in the stack are : 4
Poped element is : 10
Poped element is : 20
Elements of stack are :
30      40
Number of elements in the stack are : 2
Elements of stack are :
30      40      50
Number of elements in the stack are : 3
*/

#include<iostream>
using namespace std;

template <class T>
struct nodeQUEUE
{
    T data;
    struct nodeQUEUE<T> *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQUEUE<T> * First;
        int iCount;

    public:
        Queue();
        void Display();
        int Count();
        void EnQueue(T No);               //InsertLast()
        int DeQueue();                  //DeleteFirst()

};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeQUEUE<T> * temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQUEUE<T> * newn = NULL;
    struct nodeQUEUE<T> * temp = NULL;

    newn = new nodeQUEUE<T>;

    newn -> data = No;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}   

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQUEUE<T> * temp = NULL;

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
    Queue<int> *obj = new Queue<int>();
    int iRet = 0;

    obj->EnQueue(10);
    obj->EnQueue(20);
    obj->EnQueue(30);
    obj->EnQueue(40);

    obj->Display();

    iRet = obj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    iRet = obj->DeQueue();
    cout<<"Poped element is : "<<iRet<<"\n";

    iRet = obj->DeQueue();
    cout<<"Poped element is : "<<iRet<<"\n";

    obj->Display();

    iRet = obj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";

    obj->EnQueue(50);

    obj->Display();

    iRet = obj->Count();

    cout<<"Number of elements in the stack are : "<<iRet<<"\n";


    return 0;
}