
// Advanced Algorithms Lab - Assignment 2 - Merge Sort

#include<iostream>
# define MAX 10

using namespace std;

int n;  //Global variable (Number of elements in original array)

void title()    //Prints ASCII art - (looks cool imo)
{
 cout<<" __  __                        _____            _   "<<endl;
 cout<<"|  \\/  |                      / ____|          | |  "<<endl;
 cout<<"| \\  / | ___ _ __ __ _  ___  | (___   ___  _ __| |_ "<<endl;
 cout<<"| |\\/| |/ _ \\ '__/ _` |/ _ \\  \\___ \\ / _ \\| '__| __|"<<endl;
 cout<<"| |  | |  __/ | | (_| |  __/  ____) | (_) | |  | |_ "<<endl;
 cout<<"|_|  |_|\\___|_|  \\__, |\\___| |_____/ \\___/|_|   \\__|"<<endl;
 cout<<"                  __/ |                             "<<endl;
 cout<<"                 |___/                       "<<endl;

}

int ifSort(int arr[MAX],int n)    //Checks if the input array is sorted (OPTIONAL FUNCTION)
{
    if(n==1 || n==0)
        return 1;
    if(arr[n-1] < arr[n-2])
        return 0;
    return ifSort(arr,n-1);         
}

void DisplayArr(int arr[MAX])   //Displays the array
{
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

void merge(int arr[MAX], int s, int mid, int e) 
{ 
    //count-keeps track of passes
    static int count=1;     
    //s-start , e-end , mid-middle
    int i = s; 
    int j = mid+1; 
    int k = s;

    int tempArr[MAX];   //temporary array stores sorted elements

    //Compares the elements in both halves and stores them in sorted order 
    while (i<=mid && j<=e) 
    { 
        if (arr[i]<=arr[j]) 
        { 
            tempArr[k] = arr[i]; 
            i++; 
        } 
        else 
        { 
            tempArr[k] = arr[j]; 
            j++; 
        } 
        k++; 
    } 

    //Stores remaining elements of the first half in the temporary array
    while (i<=mid) 
    { 
        tempArr[k] = arr[i]; 
        i++; 
        k++; 
    } 

    //Stores remaining elements of the second half in the temporary array
    while (j<=e) 
    { 
        tempArr[k] = arr[j]; 
        j++; 
        k++; 
    } 

    //Copies the elements of temporary array in original array
    for(i=s;i<=e;i++)
        arr[i]=tempArr[i];

    //Displays the passes
    cout<<"\nPass "<<count<<" => ";    
    DisplayArr(arr);  
    count++; 
} 

void MergeSort(int arr[MAX], int s, int e) 
{ 
    if (s>=e) //Stopping condition
        return;
    int mid=s + (e-s)/2; 

    // Sort first and second halves 
    MergeSort(arr,s,mid); //first half
    MergeSort(arr,mid+1,e); //second half
 
    merge(arr,s,mid,e);       //Merge the 2 halves
} 

int main()
{
    cout<<"\n\n*******************************************\n\n";
    title();
    int arr[MAX],i;
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
    if(ifSort(arr,n))       //If input array is already sorted
    {
        cout<<"\nThe array is sorted : ";
        DisplayArr(arr);   
    }
    else                    //If input array is not sorted...sorts in ascending order
    {
        cout<<"\nThe array is NOT sorted\n";
        DisplayArr(arr);
        cout<<endl;
        MergeSort(arr,0,n-1);
        cout<<"\n\nThe sorted array is : ";
        DisplayArr(arr);
    }
    cout<<"\n\n*******************************************\n\n";
    return 0;
}

// Pseudocode:
// MergeSort(A, p, r):
//     if p < r:
//         q = (p+r)/2
//         Mergesort(A, p , q)
//         Mergesort(A, q+1, r)
//         Merge(A, p, q, r)