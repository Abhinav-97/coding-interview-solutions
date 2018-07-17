#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/*void swapa(char *x,char *y)
{
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}*/
void permute(string a,int l,int r)
{
    if(l==r){
        cout<<a<<endl;
    }
    else{
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);
            permute(a,l+1,r);
            swap(a[l],a[i]);
        }
    }
}
int main()
{
    string s;
    cin>>s;
    permute(s,0,s.length()-1);
    return 0;
}
