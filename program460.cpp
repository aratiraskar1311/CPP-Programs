#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
//
//Generic code of Singly Linear LL
//
/////////////////////////////////////////////////////////////////////

template<class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template<class T>
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

template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    First = NULL;
    iCount = 0;
}

template<class T>
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

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T> ;        //dynamic memory alloacte 

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

template<class T>
void SinglyLL<T>::InsertLast(T No)
{
     struct nodeSL<T> * newn = NULL;
     struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;        

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

template<class T>
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

template<class T>
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

template<class T>
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

template<class T>
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


/////////////////////////////////////////////////////////////
//
// Generic Code of Singly Circular LL
//
/////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////
//
// Generic code of Doubly Linear LL
//
/////////////////////////////////////////////////////////////

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



//////////////////////////////////////////////////////////////////////////
//
//Generic code of Doubly Circular LL
//
/////////////////////////////////////////////////////////////////////////

template<class T>
struct nodeDC
{
    T data;
    struct nodeDC<T> *next;
    struct nodeDC<T> *prev;
};

template<class T>
class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
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
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

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
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

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
    struct nodeDC<T> * temp = NULL;
    struct nodeDC<T> * newn = NULL;
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
        newn = new nodeDC<T>;

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
    struct nodeDC<T> * temp = NULL;
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




/////////////////////////////////////////////////////////////
//
// Generic Code of Stack
//
/////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

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
    
    return 0;
}