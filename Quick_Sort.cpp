
//ADV ALGO LAB ASSIGNMENT 3 - QUICK SORT

#include<iostream>
# define MAX 10
using namespace std;

//Global variables 
int n;      //(Number of elements in original array)
int arr[MAX];   //Array to store the elements

void title()    //Prints ASCII art - (looks cool imo)
{
    cout<<"  ____        _      _       _____            _    "<<endl;
    cout<<" / __ \\      (_)    | |     / ____|          | |   "<<endl;
    cout<<"| |  | |_   _ _  ___| | __ | (___   ___  _ __| |_  "<<endl;
    cout<<"| |  | | | | | |/ __| |/ /  \\___ \\ / _ \\| '__| __| "<<endl;
    cout<<"| |__| | |_| | | (__|   <   ____) | (_) | |  | |_  "<<endl;
    cout<<" \\___\\_\\\\__,_|_|\\___|_|\\_\\ |_____/ \\___/|_|   \\__|"<<endl;

}

int ifSort(int n)  //Checks if the input array is sorted
{
    if(n==1 || n==0)
        return 1;
    if(arr[n-1] < arr[n-2])
        return 0;
    return ifSort(n-1);         
}

void swap(int a,int b)  //Swaps 2 numbers
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void DisplayArr()   //Displays the array
{
    int i;
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int Divide(int s,int e)     //For dividing the array into 2 parts and return the position of pivot element
{
    //count-keeps track of passes
    static int count=1;
    //s-start, e-end
    int i=s-1;
    int j=s;
    int pivot=arr[e];   //pivot-stores last element of array (OPTIONAL variable)
    while(j<e)
    {
        //Compares all the elements of array with pivot
        if(arr[j]<=pivot) 
        {
            i++;
            swap(i,j);
        }
        j++;
    }
    swap(i+1,e);

    //Displays the passes
    cout<<"\nPass "<<count++<<": ";    //count++-increments the pass number
    DisplayArr();  

    return i+1; //returns the index of pivot element
}

void QuickSort_Recursive(int s,int e) //Recursive    
{
    if(s<e)
    {
        int p=Divide(s,e);
        QuickSort_Recursive(s,p-1);   //Sort 1st half
        QuickSort_Recursive(p+1,e);   //Sort 2nd half
    }
}

void QuickSort_Iterative(int s,int e) //Iterative
{
    //Stack to store the indexes of array
    int stack[MAX];
    int top=-1;
    stack[++top]=s;
    stack[++top]=e;

    while(top>=0)
    {
        e=stack[top--];
        s=stack[top--];

        if(s<e)
        {
            int p=Divide(s,e);
            stack[++top]=s;
            stack[++top]=p-1;
            stack[++top]=p+1;
            stack[++top]=e;
        }
    }
}

int main()
{
    cout<<"\n\n*******************************************\n\n";
    title();
    int i;
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
    if(ifSort(n))        //If input array is already sorted
    {
        cout<<"\nThe array is sorted : ";
        DisplayArr();   
    }
    else
    {
        int choice;
        cout<<"\nThe array is NOT sorted\n";
        DisplayArr();
        cout<<endl;
        cout<<"\nWhich sorting algorithm do you want to use? - (1)Iterative or (2)Recursive - ";
        cin>>choice;
        //Calls appropriate sort function for sorting the array
        switch (choice)
        {
            case 1:
                cout<<"\n*** Iterative Quick Sort ***\n";
                QuickSort_Iterative(0,n-1);
                break;
            case 2:
                cout<<"\n*** Recursive Quick Sort ***\n";
                QuickSort_Recursive(0,n-1);
                break;
            default:
                cout<<"\nInvalid Choice\n";
                break;
        }
        cout<<"\n\nThe sorted array is : ";
        DisplayArr();
    }
    cout<<"\n\n*******************************************\n\n";
    return 0;
}

// Pseudo Code
// quick_sort(array, start, end)
// {
//   if(start<end)
//   {
//     pivot_index = partition(array, start, end);
//     quick_sort(array, start, pivot_index-1);
//     quick_sort(array, pivot_index+1, end);
//   }
// }