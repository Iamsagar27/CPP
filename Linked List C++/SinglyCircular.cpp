#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE;

class SinglyC
{
    private:
        PNODE Head;
        PNODE Tail;
        int iSize;

    public:
        SinglyC();
        int Count();
        void Display();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int); 
};

SinglyC::SinglyC()               
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}

int SinglyC::Count()
{
    return iSize;
}

void SinglyC::Display()
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
void SinglyC::InsertFirst(int value)
{
    PNODE newn = NULL;
    newn = new NODE;        
    newn->data = value;
    newn->next = NULL;
            
    if(Head == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    iSize++;        
}
        
void SinglyC::InsertLast(int value)
{   
    PNODE newn = NULL;

    if(Head == NULL)  
    {
        Head = newn;
        Tail = newn;
    }        
    else                
    {
        newn = new NODE;
        newn->data = value;
        newn->next = NULL;

        PNODE temp = Head; 
            
        Tail->next = newn;
        Tail = newn;
    }
    iSize++;
    Tail->next = Head;
}

void SinglyC::InsertAtPos(int value ,int pos)
{
    if((pos < 1) || (pos > (iSize+1)))
    {
        return;
    }
            
	if(pos == 1)
    {
        InsertFirst(value);
    }
    else if(pos == (iSize + 1))
    {
        InsertLast(value);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = value;
        newn->next = NULL;

        PNODE temp = Head;

        for(int i = 1 ; i< pos-1 ;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next=newn;

        iSize++;
    }
}

void SinglyC::DeleteFirst()
{
    if((Head == NULL) || (Tail == NULL))
    {
        return ;
    }
    
    if(Head == Tail)
    {
        free(Head);
        Head =NULL;
        Tail = NULL;
        return;
    }
    else 
    {
        Head = Head ->next;
        free(Tail->next);
        Tail->next = Head; 
    }
    iSize--;
}

void SinglyC::DeleteLast()
{
    if((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    
    if(Head==Tail)
    {
        free(Head);
        Head = NULL;
        Tail = NULL;
        return;
    }
    else
    {
        PNODE temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        
        free(Tail);
        Tail = temp;
        Tail->next = Head;
    }
    iSize--;
}

void SinglyC::DeleteAtPos(int pos)
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
        PNODE temp2 = NULL;

        for(int i = 1 ;i<pos-1;i++)
        {
            temp = temp->next;
        }
        temp2=temp->next;
        temp->next = temp2->next;
        free(temp2);
        iSize--;
    }
}

int main()
{
    int ch ,num = 0 , i = 0 , no = 0 , pos = 0;
    int cnt ; 
    SinglyC obj;
    
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

























