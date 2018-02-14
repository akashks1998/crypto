#include <bits/stdc++.h>
using namespace std;
#define _N 5
#define _M 64
void key_maker(int add[_N][_M],int snum,long long int key){
  if(snum==_N){
    cout<<key<<endl;
  }else{
    for(long long int i=0;i<_M;i++){
      if(add[snum][i]==1){
        long long int temp=(key<<6)|i;
        key_maker(add,snum+1,temp);
      }
    }
  }
}
int main(){
  int add[_N][_M];
  cout<<"This is add\n";
  for(int i=0;i<_N;i++){
    for(int j=0;j<_M;j++){
      add[i][j]=(!(j-5));
      cout<<add[i][j]<<" ";
    }
    add[0][10]=1;
    add[_N-1][10]=1;
    cout<<endl;
  }
  cout<<"-------------------------\n";
  key_maker(add,0,0);
  return 0;
}
