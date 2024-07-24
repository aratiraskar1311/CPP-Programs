//Doubly linear linked list using CPP

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyLL
{
    private:
        PNODE First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(int No);
        void InsertLast(int No);
        void InsertAtPos(int No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

    DoublyLL::DoublyLL()
    {
        cout<<"Inside Constructor\n";
        First = NULL;
        iCount = 0;
    }

    void DoublyLL::Display()
    {
        PNODE temp = First;

        printf("NULL<=>");
        while(temp != NULL)
        {
            cout<<"|"<<temp -> data<<"|<=>";
            temp = temp -> next;
        }
        printf("NULL\n");

    }

    int DoublyLL::Count()
    {
        return iCount;
    }

    void DoublyLL::InsertFirst(int No)
    {
        PNODE newn = NULL;

        newn = new NODE;

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

    void DoublyLL::InsertLast(int No)
    {
        PNODE newn = NULL;
        PNODE temp = First;

        newn = new NODE;

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

    void DoublyLL::InsertAtPos(int No, int iPos)
    {
        PNODE newn = NULL;
        PNODE temp = First;
        int i = 0;

        newn = new NODE;

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

    void DoublyLL::DeleteFirst()
    {
        PNODE temp = First;

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

    void DoublyLL::DeleteLast()
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;

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

    void DoublyLL::DeleteAtPos(int iPos)
    {
        PNODE temp1 = First;
        PNODE temp2 = NULL;

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
    DoublyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;

    /*obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;
    */

    obj.InsertAtPos(105,5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;

    obj.DeleteAtPos(5);
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of element are :"<<iRet<<endl;


    return 0;
}






