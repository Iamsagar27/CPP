#include<iostream>
using namespace std;

typedef struct node 
{
    int data;
    struct node *next;
}NODE,*PNODE;

class Queue
{
private:                     
    PNODE Head;             
    int iSize;
    
public:                         
    Queue();               
    void Enqueue(int);      
    int Dequeue();          
    int Count();
    void Display();
};

Queue::Queue()
{
    Head = NULL;
    iSize = 0;
}

void Queue::Enqueue(int value)
{
    PNODE newn = new NODE;
    newn->data = value;
    newn->next = NULL;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;
        while (temp->next!= NULL)
        {
            temp= temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

int Queue::Dequeue()
{
    if(Head == NULL)
    {
        cout<<"Queue is empty";
        return -1;
    }
    else
    {
        PNODE temp = Head;
        Head = Head->next;
        int no = temp->data;
        delete temp;
        
        iSize--;
        
        return no;
    }
}

void Queue::Display()
{
    PNODE temp = Head;
    
    while(temp!= NULL)
    {
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iSize;
}

int main()
{
    int choice = 1, no = 0, pos = 0 , i = 0 , size = 0;
    Queue obj;
    
    while(choice)
    {
        cout<<"Enter choice\n";
        cout<<"1 Insert in Queue: \n";
        cout<<"2 Remove from queue: \n";
        cout<<"3 Display the elements: \n";
        cout<<"4 Count number of node: \n";
        cout<<"0 Exit the application: \n";
    
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"How many elements :\t";
                cin>>size;
                for(i = 0 ; i<size ; i++)
                {
                    cout<<"Enter number\n";
                    cin>>no;
                    obj.Enqueue(no);
                }
            break;
            
            case 2:
                no = obj.Dequeue();
                cout<<"Removed element is : "<<no<<"\n";
            break;
            
            case 3:
                cout<<"Elements are \n";
                obj.Display();
                break;
            
            case 4:
                no = obj.Count();
                cout<<"Number of elements are : "<<no<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
                break;
        }
    }
    return 0;
}

