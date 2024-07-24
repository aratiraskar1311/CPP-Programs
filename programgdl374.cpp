//Doubly linear linked list using CPP

//Generic DoublyLL

#include<iostream>
using namespace std;

template <class T>
struct nodedDL
{
    T data;
    struct nodedDL<T> *next;
    struct nodedDL<T> *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodedDL<T> * First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};
    
template <class T>
DoublyLL<T>::DoublyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodedDL<T> * temp = First;

    printf("NULL<=>");
    while(temp != NULL)
    {
        cout<<"|"<<temp -> data<<"|<=>";
        temp = temp -> next;
    }
    printf("NULL\n");

}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodedDL<T> * newn = NULL;

    newn = new nodedDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First -> prev = newn;

        First = newn;
    }
    iCount++;

}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodedDL<T> * newn = NULL;
    struct nodedDL<T> * temp = First;

    newn = new nodedDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;

        }
        temp -> next = newn;
        newn -> prev = temp;
        newn -> next = NULL;
    }
    iCount++;

}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodedDL<T> * newn = NULL;
    struct nodedDL<T> * temp = First;
    int i = 0;

    newn = new nodedDL<T>;

    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((iPos < 1) || (iPos > iCount+1))
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
        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }
            temp -> next -> prev = newn;
            newn -> next = temp -> next;
            newn -> prev = temp;
            temp -> next = newn;
            iCount++;
        }
        
    }

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodedDL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = temp -> next;
        First -> next -> prev = NULL;
        delete temp;

    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodedDL<T> * temp1 = First;
    struct nodedDL<T> * temp2 = NULL;

    if(First == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp1 -> next -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
            temp2 = temp1 -> next;
            temp1 -> next = NULL;
            delete temp2;

        }
        iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodedDL<T> * temp1 = First;
    struct nodedDL<T> * temp2 = NULL;

    int i = 0;


    if((iPos < 1) || (iPos > iCount))
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

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }
            

        temp2 = temp1 -> next; 
        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;
        delete temp2;

        iCount--;
    }
        
}


int main()
{
    DoublyLL<int> *obj = new DoublyLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of element are :"<<iRet<<endl;

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of element are :"<<iRet<<endl;


    obj->InsertAtPos(105,5);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of element are :"<<iRet<<endl;

    obj->DeleteAtPos(5);
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of element are :"<<iRet<<endl;


    return 0;
}






