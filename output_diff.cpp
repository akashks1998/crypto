#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
	ifstream infile;
	infile.open("output.txt");
	string s1;
	string s2;
	while(infile>>s1>>s2){
		int d[64];
		for(int i=0;i<16;i++){
			int a=s1[i]-'f';
			int b=s2[i]-'f';
			int c=(int)a^(int)b;
			d[4*i+3]=c%2;
			c=c/2;
                        d[4*i+2]=c%2;
			c=c/2;
                        d[4*i+1]=c%2;
			c=c/2;
                        d[4*i+0]=c%2;
		}
		if(s1.length()!=16 || s2.length()!=16){
			cout<<s1<<" "<<s2<<" Not_a_16_letter!!"<<endl;
		}else{
			cout<<s1<<" "<<s2<<" ";
			for(int i=0;i<64;i++){
				cout<<d[i];
			}
			cout<<endl;
		}
	}
	return 0;
}
