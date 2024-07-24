// Doubly Circular Linked List using CPP

//Generic DoublyCL (int, char)

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct node<T> * First;
        struct node<T> * Last;
        int iCount;

    public:
        DoublyCL(); 

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
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
} 

template<class T>
void DoublyCL<T>::Display()
{
    if((First == NULL) & (Last == NULL))
    {
        cout<<"Linked list is empty\n";
        return;
    }

    cout<<"<=>";
    do
    {
        cout<<"|"<<First -> data<<"|<=>";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
    


}

template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        
    }
    else
    {
        newn -> next = First;
        First -> prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct node<T> * newn = NULL;

    newn = new node<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
        
    }
    else
    {
        Last -> next = newn;
        newn -> prev = Last;
        Last = newn;   
    }
    Last -> next = First;
    First -> prev = Last;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct node<T> * temp = NULL;
    struct node<T> * newn = NULL;
    int i = 0;


    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new node<T>;

        newn -> data = No;
        newn -> next = NULL;
        newn -> prev = NULL;

        temp = First;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;
    
        iCount++;
    }
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)           //Empty LL
    {
        return;
    }
    else if(First == Last)          //single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        //more than one node
    {
        First = First -> next;
        delete Last -> next;
        First -> prev = Last;
        Last -> next = First;

    }
    iCount--;

}

template<class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)           //Empty LL
    {
        return;
    }
    else if(First == Last)          //single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        //more than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;

    }
    iCount--;
}

template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct node<T> * temp = NULL;
    int i = 0;


    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
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

        temp = First;

        for(i = 1; i< iPos-1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;
        
    
        iCount--;
    }
}

int main()
{
    //LL of Integer
    DoublyCL<int> *iobj = new DoublyCL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    iobj->DeleteAtPos(5);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    //LL of character
    DoublyCL<char> *cobj = new DoublyCL<char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('V');
    cobj->InsertFirst('H');

    cobj->InsertLast('I');
    cobj->InsertLast('D');
    cobj->InsertLast('Q');

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    cobj->InsertAtPos('R',5);

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    cobj->DeleteAtPos(5);

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}