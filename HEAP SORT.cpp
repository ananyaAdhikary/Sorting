#include<iostream>
using namespace std;

int left(int i)
{
    return 2*i+1;

}
int right(int i)
{
    return 2*i+2;

}

void max_heapify(int heaparr[],int n,int i)
{
    int l=left(i);
    int r=right(i);
    int largest=i;

    if(l<n && heaparr[l]>heaparr[i])
    largest=l;

    if(r<n&& heaparr[r]>heaparr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(heaparr[i],heaparr[largest]);
        max_heapify(heaparr,n,largest);

    }


}
void build_max_heap(int heaparr[],int n)
{
    int i;
    for(int i=n/2-1;i>=0;i--)
      max_heapify(heaparr, n, i);


}
void heapSort(int heaparr[],int n)
{
    build_max_heap(heaparr,n);
    for(int i=n-1;i>0;i--)
    {
        swap(heaparr[i],heaparr[0]);
        max_heapify(heaparr,i,0);
    }

}


int main(){

    int heaparr[7]={5,2,7,1,4,3,6};
    int n = sizeof(heaparr)/sizeof(heaparr[0]);

    cout<<"The original array is:";
    for(int i=0;i<n;i++)
        cout<<heaparr[i]<<" ";
    cout<<endl;

    heapSort(heaparr,n);
    cout<<"sorted array:";
     for(int i=0;i<n;i++)
        cout<<heaparr[i]<<" ";

}
