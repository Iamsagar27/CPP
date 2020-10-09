#include<iostream>
using namespace std;

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

    InsertionSort(Arr,size);

    delete (Arr);

    return 0 ;
}
