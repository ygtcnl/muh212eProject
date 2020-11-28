#include <bits/stdc++.h>

using namespace std;

//int findMax(int arr[],int endpoint) fonksiyonu verilen arrayde 0.indexinden endpoint-1 indexine kadar olan maksimum integer değerinin bulunduğu indexi dönüyor
int findIndexOfMax(int arr[],int endpoint)  
{
    int index=0;
    for(int i=0;i<endpoint;i++)
    {
        if(arr[index]<arr[i])
            index=i;
    }
    return index;
}

//void flip(int arr[],int endpoint) fonksiyonu verilen arrayde 0 indexiyle endpoint indexine kadar olan subarrayi ters çeviriyor
void flip(int arr[],int endpoint)
{
    int curr=0;
    while(curr<endpoint)
    {
        int temp=arr[curr];
        arr[curr]=arr[endpoint];
        arr[endpoint]=temp;
        curr++;
        endpoint--;
    }
}

//bildiğimiz pancake sort
void pancakeSort(int arr[],int size)
{
    for(int curr=size;curr>1;curr--)
    {
        int maxIndex=findIndexOfMax(arr,curr);
        flip(arr,maxIndex);
        flip(arr,curr-1);
    }
}

int main()
{
    int arr[]={1,5,4,3,2,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    pancakeSort(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
}