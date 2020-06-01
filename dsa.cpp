#include<bits/stdc++.h>
using namespace std;
#include<string.h>
class disk
{
    public:
    int i,j,hpos;
    int arr[20];
    int dsize=200;
    disk()
    {
         cout<<"enter initial head position\n";
        cin>>hpos;
        i=0;
        cout<<"enter sequence with space and press enter when completed: ";
        do
        {
            cin>>arr[i++];
        }while(cin.peek()!='\n');
        cout<<i<<endl;
    }
    void fcfs()
    {
        int cp,d,sd, head;
        sd=0;
        head=hpos;
        for(j=0;j<i;j++)
        {
            cp=arr[j];
            d=abs(cp-head);
            sd+=d;
            head=cp;
        }
        cout<<"fcfs Seek time: "<<sd<<endl;
    }
    void scan()
    {
        string dir;
        int seektime=0, cp, d;
        vector<int> l, r, ss;
        cout<<"SCAN:\n";
        cout<<"Direction: ";cin>>dir;
        if(dir=="left")
            l.push_back(0);
        else
            r.push_back(dsize-1);

        for(j=0;j<i;j++)
        {
            if(arr[j]<hpos)
                l.push_back(arr[j]);
            else
                r.push_back(arr[j]);
        }
        //sort the request queue in both the direction
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
      //  for(auto i=r.begin();i!=r.end();++i)
        //    cout<<*i<<"\t";
        //for(auto i=l.rbegin();i!=l.rend();++i)
          //  cout<<"\n"<<*i<<" ";
        for(int t=1;t<=2;t++)
        {
            if(dir=="right")
            {
               for(int j=0;j<r.size();j++)
               {
                   cp=r[j];
                   ss.push_back(cp);
                   d=abs(cp-hpos);
                   seektime+=d;
                   hpos=cp;
               }
                dir="left";
            }
           else if(dir=="left")
            {
                for(int j=l.size()-1;j>=0;j--)
               {
                   cp=l[j];
                   ss.push_back(cp);
                   d=abs(cp-hpos);
                   seektime+=d;
                   hpos=cp;
               }
                dir="right";
            }
        }
        cout<<"Seektime : "<<seektime<<endl;
        for (int i = 0; i < ss.size(); i++)
        cout << ss[i] << endl;
    }
};
int main()
{
    disk a;
    a.fcfs();
    a.scan();
}
