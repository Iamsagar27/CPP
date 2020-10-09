#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
}NODE,*PNODE;

class DoublyC
{
private:                        
    PNODE Head;
    PNODE Tail;             
    int iSize;
    
public:                             
    DoublyC();         
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};

DoublyC::DoublyC()
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}

void DoublyC::Display()
{
    if((Head == NULL) || (Tail == NULL))
    {
        return ;
    }   

    do
    {
        cout<<"| "<< Head->data<<" |"<<"<->";
        Head = Head->next;
    } while (Head != Tail->next);
}

int DoublyC::Count()
{
    return iSize;
}

void DoublyC::InsertFirst(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = Head->prev;
    }
    Tail->next = Head;
    Head->prev = Tail;
    iSize++;
}

void DoublyC::InsertLast(int value)
{
    PNODE newn = new NODE;
    
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = Tail->next; 
    }
    iSize++;
    Tail->next = Head;
    Head->prev = Tail;
}

void DoublyC::InsertAtPos(int value ,int pos)
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

void DoublyC::DeleteFirst()
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if(Head== Tail)
    {
        free(Head);
        Head =NULL;
        Tail = NULL;
        return;
    }
    else
    {   
        Head = Head->next;
        free(Tail->next);
        Tail->next = Head;
        Head->prev = Tail;
    }
    iSize--;
}

void DoublyC::DeleteLast()
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if(Head== Tail)
    {
        free(Head);
        Head =NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        free(Tail->next);
        Tail->next = Head;
        Head->prev = Tail;
    }
    iSize--;
}

void DoublyC::DeleteAtPos(int pos)
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
    DoublyC obj;
    
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


