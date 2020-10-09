#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class Doubly
{
private:                        
    PNODE Head;             
    int iSize;
    
public:                         
    Doubly();        
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

Doubly::Doubly()
{
    Head = NULL;
    iSize = 0;
}

inline void Doubly::Display()
{
    PNODE temp = Head;
    
    while(temp != NULL)
    {
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

inline int Doubly::Count()
{
    return iSize;
}

void Doubly::InsertFirst(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    iSize++;
}

void Doubly::InsertLast(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

void Doubly::InsertAtPos(int value ,int pos)
{
    if((pos < 1) || (pos > (iSize + 1)))
    {
        return;
    }

    if(pos == 1)
    {
        InsertFirst(value);
    }
    else if(pos == (iSize +1))
    {
        InsertLast(value);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;
        
        PNODE temp = Head;
        
        for(int i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
         iSize++;
    }
}

void Doubly::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        free(Head);
        Head =NULL;
    }
    else
    {   
        Head = Head->next;
        free(Head->prev);
        Head->prev = NULL;
    }
    iSize--;
}

void Doubly::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    else if(Head->next == NULL)
    {
        free(Head);
        Head =NULL;
    }
    else
    {
        PNODE temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    iSize--;
}

void Doubly::DeleteAtPos(int pos)
{
    if((pos < 1) || (pos > iSize))
    {
        return;
    }
    
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iSize)
    {
        DeleteLast();
    }
    else 
    {
        PNODE temp = Head ;

        for(int i = 1 ;i<pos-1;i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        iSize--;
        temp->next->prev = temp;
    }
}

int main()
{
    int ch ,num = 0 , i = 0 , no = 0 , pos = 0;
    int cnt ; 
    Doubly obj;
    
    do
    {
        cout<<"\n1.InsertFirst\n2.InsertLast\n3.InsertAtPos\n4.DeleteFirst\n5.DeleteLast\n6.DeleteAtPos\n7.Display\n8.Count\n9.Exit\n";
        cout<<"\nEnter the choice : \t";
        cin>>ch;

        switch(ch)
        {
            case 1 :
                cout<<"Enter number of element :\t";
                cin>>num;
                for(i = 1 ; i <=num; i++)
                {
                    cout<<"Enter the element :\t";
                    cin>>no;
                    obj.InsertFirst(no);
                }
                break;

            case 2 :
                cout<<"Enter number of element :\t";
                cin>>num;
                for(i = 1 ; i <=num; i++)
                {
                    cout<<"Enter the element :\t";
                    cin>>no;
                    obj.InsertLast(no);
                }
                break;
            
            case 3 :
                cout<<"Enter the element :\t";
                cin>>no;
                cout<<"Enter the position :\t";
                cin>>pos;
                obj.InsertAtPos(no,pos);
                break;
            
            case 4 :
                obj.DeleteFirst();
                break;

            case 5 :
                obj.DeleteLast();
                break;

            case 6 :
                cout<<"Enter the position :\t";
                cin>>pos;
                obj.DeleteAtPos(pos);
                break;
            
            case 7 :
                cout<<"Elements of list are\t\t";
                obj.Display();
                break;
            
            case 8 :
                cnt = obj.Count();
                cout<<"Number of elements in list : "<<cnt<<"\n";
                break;
        }
        
    } while (ch !=9);
    

    return 0;
}























