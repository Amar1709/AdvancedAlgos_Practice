
// Advanced Algorithms Lab - Assignment 1 - Insertion Sort

#include<iostream>

using namespace std;

# define MAX 10  //Done using arrays

void title()    //Prints ASCII art - (looks cool imo)
{
    cout<<"  ___                  _   _            ___          _   "<<endl;
    cout<<" |_ _|_ _  ___ ___ _ _| |_(_)___ _ _   / __| ___ _ _| |_ "<<endl;
    cout<<"  | || ' \\(_-</ -_) '_|  _| / _ \\ ' \\  \\__ \\/ _ \\ '_|  _|"<<endl;
    cout<<" |___|_||_/__/\\___|_|  \\__|_\\___/_||_| |___/\\___/_|  \\__|"<<endl;

}

int ifSort(int arr[MAX],int n)      //Checks if the input array is sorted
{
    if(n==1 || n==0)
        return 1;
    if(arr[n-1] < arr[n-2])
        return 0;
    return ifSort(arr,n-1);         
}

void DisplayArr(int arr[MAX],int n)     //Displays the array
{
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

void InsertionSort_Iter(int arr[MAX], int n)     //Sort Function (Iterative)
{ 
    int i,key,j;
    int count=1; 
    for (i=1;i<n;i++) 
    { 
        key=arr[i]; 
        j=i-1; 
        while(j>=0 && arr[j]>key) 
        { 
            arr[j+1]=arr[j]; 
            j--; 
        } 
        arr[j+1]=key;
        cout<<"\nPASS "<<count<<" => ";       //Prints the Passes
        DisplayArr(arr,n);
        count++; 
    } 
} 

void InsertionSort_Rec(int arr[MAX], int n)     //Sort Function (Recursive)
{ 
    int i,key,j;
    static int count=1; 
    if(n==1 || n==0)
        return;
    key=arr[n-1]; 
    j=n-2; 
    while(j>=0 && arr[j]>key) 
    { 
        arr[j+1]=arr[j]; 
        j--; 
    } 
    arr[j+1]=key;
    cout<<"\nPASS "<<count<<" => ";       //Prints the Passes
    DisplayArr(arr,n);
    count++;
    InsertionSort_Rec(arr,n-1); 
}


int main()
{
    cout<<"\n\n*******************************************\n\n";
    title();
    int arr[MAX],n,i;
    NumberOfElements:
        cout<<"\nEnter the number of elements in the array : ";
        cin>>n;
    if(n<=0||n>MAX)
    {
        cout<<"\nNumber of elements should be between 1-"<<MAX<<"...please try again\n";
        goto NumberOfElements;
    }    
    cout<<"\nEnter the elements of the array\n";
    for(i=0;i<n;i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    if(ifSort(arr,n))
    {
        cout<<"\nThe array is sorted\n\n";
        DisplayArr(arr,n);   
    }
    else
    {
        int choice;
        cout<<"\nThe array is NOT sorted\n";
        DisplayArr(arr,n);
        cout<<endl;
        cout<<"\nWhich sorting algorithm do you want to use? - (1)Iterative or (2)Recursive - ";
        cin>>choice;
        //Calls appropriate sort function for sorting the array
        switch (choice)
        {
            case 1:
                cout<<"\n*** Iterative Insertion Sort ***\n";
                InsertionSort_Iter(arr,n);
                break;
            case 2:
                cout<<"\n*** Recursive Insertion Sort ***\n";
                InsertionSort_Rec(arr,n);
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
        cout<<"\n\nThe sorted array is : ";
        DisplayArr(arr,n);
    }
    cout<<"\n\n*******************************************\n\n";
    return 0;
}

//Pseudo Code
// INSERTION-SORT(A)

// for i = 1 to n
//     key ← A [i]
//     j ← i – 1
//     while j > = 0 and A[j] > key
//         A[j+1] ← A[j]
//         j ← j – 1
//     End while
//     A[j+1] ← key
// End for