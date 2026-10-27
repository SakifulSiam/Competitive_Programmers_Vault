#include <iostream>
#include <numeric>
#include <string>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <deque>
#include <bits/stdc++.h>



#define lli long long int 
#define check(n, k) (((n)>>(k)) & 1)///check kth bit of n set or not
using namespace std;
lli mod=1000000000+7;


template <typename T>
class Fenwick
{
    int n;
    vector<T> bit;
public:
    Fenwick(int n)
    {
        this->n=n;
        bit.assign(n+1,0);
    }
    // Add val to index i
    void update(int i,T val)
    {
        while(i<=n){
            bit[i]+=val;
            i+=i&-i;
        }
    }
    // Sum from 1 to i
    T sum(int i)
    {
        T ans=0;
        while(i>0){
            ans+=bit[i];
            i-=i&-i;
        }
        return ans;
    }
    // Sum from l to r
    T rangeSum(int l,int r){
        return sum(r)-sum(l-1);
    }
};
/*lli __lcm(lli a,lli b){
    lli res;
    res=a*b;
    return (res/__gcd(a,b));
}*/

vector<string>vs; 
lli pal(string strr)
{
    int l,r;
    l=0;r=strr.size()-1;
    if(strr[l]!=strr[r])return 0;
    while(l<strr.size()-1&&r>=0&&l<=r&&strr[l]==strr[r])
    {
        if(strr[l]!=strr[r])return 0;
        l++;r--;
        
    }return 1;
}

//lli v1[4e5+1]={}
//vector<lli>vp,vp2(10000000+1,0);
lli sv[10000000]={0};//0=prime 1=not prime
void sieve()
{
    sv[0]=sv[1]=1;
    for(int i=2;i<1000000;i++)
    {
        for(int j=i+i;j<1000000;j+=i)
        {
            sv[j]=1;
        }
    }//for(int i=0;i<100000;i++)if(!arr1[i])cout<<i<<' ';
}

void dissieve()
{
    for(int i=2;i<1000000;i++)
    {
        
        for(int j=i+i;j<1000000;j+=i)
        {
            sv[j]+=1;
        }
    }
}
lli in(lli a,lli b,lli c)
{
    if(c>=a&&c<=b)return 1;
    else return 0;
} lli d2a[1002][1002]={};
lli area(int a1,int b1,int a2,int b2,int a3,int b3)
{
    //cout<<(a1*b2*a2*b3+a3*a1)<<endl<<(a2*b1+a3*b2+a1*b3)<<endl;
    return ((a1*b2+a2*b3+a3*b1)-(b1*a2+b2*a3+b3*a1));
}


int main()
{
    lli t = 1LL,test=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///START>>>>>
    
    ///<<<<<END
    //cout<<1111;
    
    
    //for(int i=0;i<10;i++)cout<<ccc[i]<<' ';
    
    cin>>t;
    //while (true)

    while(t)
    {
        t--;test++;
        lli  a=0, c,k=0, b,x=0,y=0,  d, l, counter=0, r = 0, n=0, m = 0,temp1 = 0,  temp2 = 0, temp3 = -1,ans = 1,sum = 0, z;
        lli  w, h, x1, y1, x2, y2, big, small;
        //float c;
        float dl,dla;
        vector<lli> v, v1, v2, v3, v1temp, v2temp;
        string s, ss, temp_s, temp_ss,s1,s2,s3,s4;

        char ch,ch1,ch2;
        lli ar1[200001];
        map<lli,lli> mp, mp1,mp2, mp3, mpe;
        
        //map<lli,bitset<10000>>;
        multimap<char,lli>mmp;
        set<lli>st;
        map<string, lli> mpsi;
        unordered_map<char, lli> mpci;
        map<pair<lli,string>,int>pmp,pmp1;

        
        vector<vector<int>>vsa;
        vector<tuple<lli,lli,lli,lli>>tup,tup1;

        bitset<32>bit;
        //lli arr[600000+1]={0};

        vector<pair<lli,lli>>pai,pai1;
        
        //priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq,pq1;
        priority_queue<lli,vector<lli>,greater<lli>>pq;
        priority_queue<lli,vector<lli>,greater<lli>>pq2;
        priority_queue<lli,vector<lli>>pqo,pqe;
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pqd;
        list<lli>dq,dq1,dq2,dq3;
        unordered_map<lli,list<lli>::iterator>mpit;
        //unordered_set<lli> st,st1;
        multiset<lli> mst;
        
        stack<lli>stk;
        
        
        x=0;
        z=0;

        
        // sort(v1.begin(), v1.end(), greater <int>());//to sort vector in decreasing order
        
        ///START<<<<<  %1000000000+7
        cin>>n;sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
            v.push_back(x);
        }//cout<<sum;
        for(int i=0;i<n;i++)
        {
            if((sum/100)<n*100-v[i])a=0;
            else{
                a=v[i]-(n*100-n);
            }
            cout<<a<<' '<<min(sum/100,v[i])<<endl;
        }
        ///END>>>>>
    
        //printf("%.6f",(float)ans/(n-m+1)); to ptint full float
    }
    return 0;
}