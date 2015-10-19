/*
    AUTHOR:    RAJ RANJAN
    DATE:       19.10.2015
*/


#include<bits/stdc++.h>
using namespace std;
/*
update function takes position and value and update the required index in BIT o(logn)
*/
void update(int j,int val,vector<int> &arr)
{
    while(j<arr.size())
    {
        arr[j]+=val;
        j=j+(j&(-j));
    }
}

int query(int j,vector<int> &arr)
{
    int sum=0;
    while(j>0)
    {
        sum+=arr[j];
        j=j-(j&(-j));
    }
    return sum;
}
int main()
{

    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        update(i,a,arr);
    }
int b,c;
cin>>b>>c;  //sum of range a->b ( 0 based indexing)
cout<<query(c+1,arr)-query(b,arr);
    return 0;
}
