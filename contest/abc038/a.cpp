#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int main(){
  string S;
  cin >> S;
 
  long long s = S.size();
  if(S[s-1]=='T') cout << "YES" << endl; 
  else cout << "NO" << endl;
 
  return 0;
}