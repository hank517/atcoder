#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>
 
#define MOD 1000000007
#define ll long long
 
using namespace std;
 
ll N;
vector<ll> a;
 
int check(ll k){
  vector <ll> vec;
  ll inp;
  ll q,c;//商、余
  ll result=0;
  
  // copy(a.begin(), a.end(), back_inserter(vec) );
  
  for (ll i =0;i<N;i++){
    inp = a[i]+k-N+1;
    vec.push_back(inp);
  }
  for (ll i =0;i<N;i++){
    q = vec[i]/(N+1);
    c = vec[i]%(N+1);
    if(q>=0){
      result+=q;
      if(c>0) result++;
    } 
  }
  //cout << result << endl;
  //cout << k << endl;
  if(result <= k) return 1;
  else return 0;
}
 
int main(){
  ll inp;
 
  ll l=0,r=5000000000000000000;
  ll bl,br;
  ll result ;
  ll k;
  
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> N;
  for(ll i = 0;i<N;i++){
    cin >> inp;
    a.push_back(inp);
  }
 
  
  do{
    k = (l+r)/2;
    if(check(k)==1){
      r = k;
    }
    else{
      l = k;
    }
    if((l == bl)&&(r == br)){
      for(ll i = l;i<=r;i++){
	if(check(i)==1){
	  l = i;
	  break;
	}
      }
    }
    bl = l;
    br = r;
  }while(l<r);
  result = l;
 
  for(ll i =0;i<=N;i++){
    if(check(i)==1){
      l = i;
      break;
    }
  }
 
  if(result < l) l = result;


  for(ll i = N*2;i>0;i--){
    if(((result-i)>=0) && check(result-i)==1){
      cout << result-i << endl;
      return 0;
    }
  }
  
  cout << l << endl;
 
  // cout << check(1234567894858) << endl;
  return 0;
}