#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node* PNODE;

class Stack
{
    public :
        PNODE Head;

    Stack()
    {
        Head = NULL;
    }

    void Push(int value)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = value;
        newn->next = NULL;

        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }

    int Pop()
    {
        if(Head == NULL)
        {
            return -1;
        }
        else
        {
            int no = 0;
            no = Head->data;
            PNODE temp = Head;
            Head = Head->next;
            delete temp;
            return no;
        }
    }

    void Display()
    {
        PNODE temp = Head;
        
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
};

int main()
{
    PNODE First = NULL;
    int ch ,num = 0 , i = 0 , no = 0;
    Stack obj;

    do
    {
        cout<<"\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
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
                    obj.Push(no);
                }
            break;

            case 2 :
                no = obj.Pop();
                cout<<"Poped element :\t"<<no<<"\n" ;
                break;

            case 3 :
                cout<<"Elements of stack are\n";
                obj.Display();
                break;
        }
        
    } while (ch !=4);
    

    return 0;
}
