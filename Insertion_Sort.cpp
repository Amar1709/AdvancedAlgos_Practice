
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

void InsertionSort(int arr[MAX], int n)     //Sort Function
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
        cout<<"\nThe array is NOT sorted\n";
        DisplayArr(arr,n);
        cout<<endl;
        InsertionSort(arr,n);   //Calls sort function for sorting
        cout<<"\n\nThe sorted array is : ";
        DisplayArr(arr,n);
    }
    cout<<"\n\n*******************************************\n\n";
    return 0;
}