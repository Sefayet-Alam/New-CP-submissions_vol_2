#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long

int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    cin>>t;

    while(t--){
      ll n;
      cin>>n;
      
      string s;
      cin>>s;
      ll idx=-1;
      for(ll i=0;i<n-2;i++){
        if(s[i]=='1'){
            idx=i;
            break;
        }
      }
     if(idx==-1){
        cout<<s<<endl;
     }
     else{
        for(ll i=idx+1;i<n;i++) s[i]='0';
        cout<<s<<endl;
     }


    }


    return 0;
}

