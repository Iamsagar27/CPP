#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n) 
{     
    int i = 0, j = 0, temp = 0 ; 

    for(i = 0; i < n; i++)     
    {         
        for(j = 0; j < n-i-1; j++)         
        {             
            if( arr[j] > arr[j+1])             
            {                 
                temp = arr[j];                 
                arr[j] = arr[j+1];                
                arr[j+1] = temp;             
            }          
        } 
    } 

    cout<<"\nAfter sorting :\n";
    for(i = 0; i < n; i++)     
    { 
        cout<<arr[i]<<" ";
    }
}

void SelectionSort(int arr[], int n) 
{     
    int index_of_min = 0; 
    int  i = 0 , j = 0;
    
    for( i = 0; i < n ; i++)  
    {       
        index_of_min = i;       
        for(int j = i; j < n; j++)       
        {             
            if(arr[index_of_min] > arr[j])            
            {                
                index_of_min = j;            
            }       
        }       
        int temp = arr[i];       
        arr[i] = arr[index_of_min];       
        arr[index_of_min] = temp;  
    }

    cout<<"\nAfter sorting :\n";
    for(i = 0; i < n; i++)     
    { 
        cout<<arr[i]<<" ";
    }
}

void InsertionSort(int arr[], int n) 
{     
    int i = 0, key = 0, j = 0; 
   
    for (i = 1; i < n; i++)     
    {         
        key = arr[i];         
        j = i-1; 
        
        while (j >= 0 && arr[j] > key)         
        {             
            arr[j+1] = arr[j];             
            j = j-1;         
        }         
        arr[j+1] = key;     
    } 

    cout<<"\nAfter sorting :\n";
    for(i = 0; i < n; i++)     
    { 
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int size = 0 , i = 0 , ch = 0;
    int *Arr = NULL;

    do
    {
        cout<<"\n1.BubbleSort";
        cout<<"\n2.SelectionSort";
        cout<<"\n3.InsertionSort";
        cout<<"\n4.Exit";
        
        cout<<"\nEnter your choice :\t";
        cin>>ch; 

        switch(ch)
        {
                case 1:
                        cout<<"How many elements in an array:\t";
                        cin>>size;

                        Arr = new int[size];

                        cout<<"Enter the elements :";
                        for(i = 0 ; i < size ; i++)
                        {
                            cin>>Arr[i];
                        }

                        printf("The elements in array:\n");
                        for(i = 0 ; i < size ; i++)
                        {
                            cout<<Arr[i]<<" ";
                        }

                        BubbleSort(Arr,size);

                        delete (Arr);
                    
                        break;

                case 2:
                        cout<<"How many elements in an array:\t";
                        cin>>size;

                        Arr = new int[size];

                        cout<<"Enter the elements :";
                        for(i = 0 ; i < size ; i++)
                        {
                            cin>>Arr[i];
                        }

                        printf("The elements in array:\n");
                        for(i = 0 ; i < size ; i++)
                        {
                            cout<<Arr[i]<<" ";
                        }

                        SelectionSort(Arr,size);

                        delete (Arr);
                    
                        break;
                
                case 3:
                        cout<<"How many elements in an array:\t";
                        cin>>size;

                        Arr = new int[size];

                        cout<<"Enter the elements :";
                        for(i = 0 ; i < size ; i++)
                        {
                            cin>>Arr[i];
                        }

                        printf("The elements in array:\n");
                        for(i = 0 ; i < size ; i++)
                        {
                            cout<<Arr[i]<<" ";
                        }

                        InsertionSort(Arr,size);

                        delete (Arr);
                    
                        break;
            }
            
    }while(ch != 4);
    
    return 0 ;
}