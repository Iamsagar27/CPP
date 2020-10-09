#include<iostream>
using namespace std;

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

int main()
{
    int size = 0 , i = 0;
    int *Arr = NULL;

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

    return 0 ;
}
