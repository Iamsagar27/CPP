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

    BubbleSort(Arr,size);

    delete (Arr);

    return 0 ;
}