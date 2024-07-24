//Singly Linear LinkedList using cpp 
       
//Generic SinglyLL

#include<iostream>
using namespace std;

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

public:
    SinglyLL();

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
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;

    }
    printf("NULL\n");
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T> ;        //malloc--dynamic memory alloacte in cpp

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;

}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
     struct nodeSL<T> * newn = NULL;
     struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;        //struct node chya tithe node  //malloc--dynamic memory alloacte in cpp

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
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
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;


    if((iPos < 1)||(iPos > iCount))
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
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

int main()
{
    //LL of Integer
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);
    
    iobj->Display();
    iRet = iobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;


    //LL of Character
    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    cobj->InsertLast('H');
    cobj->InsertLast('I');
    cobj->InsertLast('J');

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    cobj->InsertAtPos('N',5);

    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    cobj->DeleteAtPos(5);
    
    cobj->Display();
    iRet = cobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;


    //LL of float
    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(10.56f);
    fobj->InsertFirst(34.56f);
    fobj->InsertFirst(13.67f);

    fobj->Display();
    iRet = fobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    fobj->InsertLast(23.5f);
    fobj->InsertLast(56.78f);
    fobj->InsertLast(57.0f);

    fobj->Display();
    iRet = fobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    fobj->InsertAtPos(12.67f,5);

    fobj->Display();
    iRet = fobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    fobj->DeleteAtPos(5);
    
    fobj->Display();
    iRet = fobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    //LL of double
    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(10.56f);
    dobj->InsertFirst(34.56f);
    dobj->InsertFirst(13.67f);

    dobj->Display();
    iRet = dobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj->InsertLast(23.5f);
    dobj->InsertLast(56.78f);
    dobj->InsertLast(57.0f);

    dobj->Display();
    iRet = dobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj->InsertAtPos(12.67f,5);

    dobj->Display();
    iRet = dobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;

    dobj->DeleteAtPos(5);
    
    dobj->Display();
    iRet = dobj->Count();

    cout<<"Number of elements are : "<<iRet<<endl;


    return 0;
}