#include <bits/stdc++.h>
#include <algorithm>

using namespace std;
using namespace std::chrono; 

int temp; //we created global integer, we will use it while flipping the arrays

//int findMax(int arr[],int endpoint) returns the index of maximum value between indexes 0 and endpoint
int findIndexOfMax(int arr[],int endpoint)  
{
    int index=0; //we set index as 0
    for(int i=0;i<endpoint;i++) //we visit all integers between 0 and endpoint
    {
        if(arr[index]<arr[i]) //if the value of i.th index is higher we change index by i
            index=i;
    }
    return index; // the iteration is over now we return the index of maximum value in given range
}

//void flip(int arr[],int endpoint) flips the subarray between arr[0] and arr[endpoint]
void flip(int arr[],int endpoint)
{
    int curr=0; //curr represents our starting index
    while(curr<endpoint) //we are using two pointer technique and on here loop needs to stop when these two pointers cross each other
    {
        temp=arr[curr]; //temp helps to store arr[curr] value temporary on here temp is declared as global so the space complexity is O(1)
        arr[curr]=arr[endpoint];//on that two line we change values
        arr[endpoint]=temp;
        curr++;
        endpoint--;
    }
}

//main function for sorting the algorithm
void pancakeSort(int arr[],int size)
{
    for(int curr=size;curr>1;curr--)
    {
        int maxIndex=findIndexOfMax(arr,curr); //we find the index of maximum value between indexes 0 and "curr"
        flip(arr,maxIndex); //we flip subarray between 0 and "maxIndex"
        flip(arr,curr-1); //we flip again but now we flip subarray between 0 and "curr"-1
    }
}

//that function unrelated to the algorithm, if the user wants to see changes on screen she/he can use that function
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int m=arr[i];
        cout<<(int)m<<" ";
    }
    cout<<endl;
}

//that function is unrelated to algorithm too, it helps to create a random array with given size
void generateRandomArray(int arr[],int size) {
    srand( (unsigned)time( NULL ) );
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
}

int main()
{
    int size=50000;
    int arr[size];
    generateRandomArray(arr,size);
    int arr2[size];
    generateRandomArray(arr2,size);
    auto start = high_resolution_clock::now(); 
    pancakeSort(arr,size);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"our execution time" << duration.count() << endl;   
    auto start1 = high_resolution_clock::now(); 
    sort(arr2,size+arr2);
    auto stop1 = high_resolution_clock::now(); 
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout<<"built-in execution time" << duration1.count() << endl;  
}