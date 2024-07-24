//Singly Circular LinkedList using CPP

//Generic SinglyCL

#include<iostream>
using namespace std;

template<class T>
struct nodeSC
{
    T data;
    struct nodeSC<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct nodeSC<T> * First;
        struct nodeSC<T> * Last;
        int iCount;

    public:
        SinglyCLL();
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
    
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"LL is empty"<<endl;
        return;
    }

    temp = First;
    do
    {
        cout<<"|"<<temp -> data<<"|->";
        temp = temp -> next;
    }while(temp != First);
    cout<<endl;
}

template<class T>
int SinglyCLL<T>::Count()
{

    return iCount;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T No)
{
    struct nodeSC<T> * newn = NULL;

    newn = new nodeSC<T>;

    newn -> data = No;
    newn -> next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last -> next = newn;
        Last = newn;
    }
    Last -> next = First;
    iCount++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeSC<T> * newn = NULL;
    struct nodeSC<T> * temp = NULL;


    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSC<T>;

        newn -> data = No;
        newn -> next = NULL;

        temp = First;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete Last -> next;
        Last -> next = First;  
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    struct nodeSC<T> * temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        while(temp -> next != Last)
        {
            temp = temp -> next;
        }
        temp -> next = First;
        delete Last;
        Last = temp;
        
    }
    iCount--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSC<T> * temp1 = NULL;
    struct nodeSC<T> * temp2 = NULL;


    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }
        temp2  = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;
        iCount--;
    }
}

int main()
{
    SinglyCLL<int> *obj = new SinglyCLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();

    cout<<"Number of elements are :"<<iRet<<endl;

    obj->InsertAtPos(105,5);
    obj->Display();
    iRet = obj->Count();

    cout<<"Number of elements are :"<<iRet<<endl;

    obj->DeleteAtPos(5);
    obj->Display();
    iRet = obj->Count();

    cout<<"Number of elements are :"<<iRet<<endl;

    return 0;
}
