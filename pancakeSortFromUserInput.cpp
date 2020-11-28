#include <bits/stdc++.h>

using namespace std;

//int findMax(int arr[],int endpoint) fonksiyonu verilen arrayde 0.indexinden endpoint-1 indexine kadar olan maksimum integer değerinin bulunduğu indexi dönüyor
int findIndexOfMax(int arr[],int endpoint)  
{
    int index=0; //en başta max olan index 0 olarak atanıyor
    for(int i=0;i<endpoint;i++) //arrayin elemanları üstünde geziniyoruz
    {
        if(arr[index]<arr[i]) //eğer i indexindeki değer daha büyükse indexi i yapıyoruz
            index=i;
    }
    return index;
}

//void flip(int arr[],int endpoint) fonksiyonu verilen arrayde 0 indexiyle endpoint indexine kadar olan subarrayi ters çeviriyor
void flip(int arr[],int endpoint)
{
    int curr=0; //curr şuan bulunduğumuz indexi belirtiyor
    while(curr<endpoint) //two pointer şeklinde ilerlediğimizden pointerların karşılaşıp birbirlerini geçmemesini kontrol ediyoruz
    {
        int temp=arr[curr]; //ek bir integer oluşturuyoruz arr[curr] ile arr[endpoint] in yerlerini değiştirirken işimize yarıyor
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
        int maxIndex=findIndexOfMax(arr,curr); //"curr" e kadar olan maksimum değerin indexini buluyoruz
        flip(arr,maxIndex); //çeviriyoruz
        flip(arr,curr-1); //bir daha çeviriyoruz
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