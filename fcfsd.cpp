#include<iostream>
using namespace std;
int main()
{
    int i,j,hpos;
    int arr[20];
         cout<<"enter initial head position\n";
        cin>>hpos;
        i=0;
        cout<<"enter sequence with space and press enter when completed: ";
        do
        {
            cin>>arr[i++];
        }while(cin.peek()!='\n');
        cout<<i<<endl;
    int cp,d,sd;
    sd=0;
        for(j=0;j<i;j++)
        {
            cout<<arr[j]<<" ";
            cp=arr[j];
            d=abs(cp-hpos);
            cout<<d<<"\t";
            sd+=d;
            hpos=cp;
        }
       cout<<"Seek time: "<<sd<<endl;
}
