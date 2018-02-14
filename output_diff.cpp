#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int IP[] = {
  58,50,42, 34,26,18,10,2,
  60,52,44,36,28,20,12,4,
  62,54, 46, 38, 30, 22, 14,6,
  64, 56, 48, 40,32,24, 16, 8,
  57, 49, 41, 33,25,17, 9,1,
  59, 51,43,35,27,19,11,3,
  61,53,45,37,29,21,13, 5,
  63,55, 47,39,31,23,15,7
};

int main(){
	ifstream infile;
	infile.open("output_1.txt");
	string s1;
	string s2;
	while(infile>>s1>>s2){
		int D[64],d[64];
		for(int i=0;i<16;i++){
			int a=s1[i]-'f';
			int b=s2[i]-'f';
			int c=(int)a^(int)b;
			D[4*i+3]=c%2;
			c=c/2;
                        D[4*i+2]=c%2;
			c=c/2;
                        D[4*i+1]=c%2;
			c=c/2;
                        D[4*i+0]=c%2;
		}
		for(int i=0;i<64;i++){
			d[i]=D[IP[i]-1];
		}
		if(s1.length()!=16 || s2.length()!=16){
			cout<<s1<<" "<<s2<<" Not_a_16_letter!!"<<endl;
		}else{
			cout<<s1<<" "<<s2<<" ";
			for(int i=0;i<31;i++){
				cout<<d[i];
				// cout<<'1';
			}
			cout<<" ";
			for(int i=31;i<64;i++){
				cout<<d[i];
				// cout<<'0';
			}
			cout<<endl;
		}
	}
	return 0;
}
