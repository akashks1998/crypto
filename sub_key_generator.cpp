#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int possible_keys[5][64];//2,5,6,7,8

int RFP[] = {
  8,40,16,48,24,56,32,64,
  7, 39,15,47,23,55,31,63,
  6,38,14,46,22,54,30,62,
  5,37,13,45, 21,53,29,61,
  4,36,12,44,20,52,28,60,
  3, 35, 11,43,19,51,27,59,
  2, 34, 10, 42,18, 50,26,58,
  1,33,9,41, 17, 49, 25,57,
};

int S[8][64]=
{
 14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
 4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
 15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13 ,

 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
 0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
 13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9,

 10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,

 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
 10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4,
 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,


 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
 14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,



 12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11,
 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
 9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,

 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,

 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7,
 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };

int P[] = {
  16, 7, 20, 21,
  29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31,10,
  2, 8, 24, 14,
  32, 27, 3, 9,
  19, 13, 30, 6,
  22, 11, 4, 25,
};

int E[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};

int INV_P[] = {
	9, 17, 23, 31,
	13, 28, 2, 18,
	24, 16, 30, 6,
	26, 20, 10, 1,
	8, 14, 25, 3,
	4, 29, 11, 19,
	32, 12, 22, 7,
	5, 27, 15, 21,
};

void key_gen(int* T_r1,int* T_r2,int* S_box_output){
  int Add[5][64];

  int T_r1_expand[48];
  int T_r2_expand[48];
  for(int i=0;i<48;i++){
    T_r1_expand[i]=T_r1[E[i]-1];
    T_r2_expand[i]=T_r2[E[i]-1];
  }
  int T_r1_pack[8];
  int T_r2_pack[8];
  int S_box_output_pack[8];
  cout<<"output_pack-<><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
  for(int i=0;i<8;i++){
    int temp1=0;
    int temp2=0;
    int mult=1;
    for(int j=5;j>=0;j--){
      temp1=temp1+T_r1_expand[j+(i*6)]*mult;
      temp2=temp2+T_r2_expand[j+(i*6)]*mult;
      mult=mult*2;
    }
    T_r1_pack[i]=temp1;
    T_r2_pack[i]=temp2;

    cout<<"output_pack-"<<i<<endl;
    cout<<S_box_output[0+i*4]<<S_box_output[1+i*4]<<S_box_output[2+i*4]<<S_box_output[3+i*4]<<endl;

    if(S_box_output[i*4]==-1){
      S_box_output_pack[i]=-1;
    }else{
      int temp=0;
      int mult=1;
      for(int j=3;j>=0;j--){
        temp=temp+S_box_output[j+(i*4)]*mult;
        mult=mult*2;
      }
      S_box_output_pack[i]=temp;
    }
  }

  for(int i=0;i<5;i++){
    for(int j=0;j<64;j++){
      Add[i][j]=0;
    }
  }
  int index[]={1,4,5,6,7};
  for(int i=0;i<5;i++){
    int idx=index[i];
    int flag=0;
    for(int key=0;key<64;key++){
      cout<<"display-<><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl;
      cout<<"idx "<<idx<<endl;
      cout<<"T_r1_pack[idx] "<<T_r1_pack[idx]<<endl;
      cout<<"key "<<key<<endl;
      int y=T_r1_pack[idx]^key;
      cout<<"T_r1_pack[idx]^key "<<y<<endl;
      cout<<"T_r2_pack[idx] "<<T_r2_pack[idx]<<endl;
      cout<<"S[idx][T_r2_pack[idx]^key] "<<S[idx][T_r2_pack[idx]^key]<<endl;
      cout<<"S[idx][T_r1_pack[idx]^key] "<<S[idx][T_r1_pack[idx]^key]<<endl;
      cout<<"S_box_output_pack[idx] "<<S_box_output_pack[idx]<<endl;
      int temp=S[idx][T_r1_pack[idx]^key]^S[idx][T_r2_pack[idx]^key];
      if(temp==S_box_output_pack[idx]){
        Add[i][key]++;
        flag=1;
      }
    }
    if(flag==0){
      return;
    }
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<64;j++){
      possible_keys[i][j]+=Add[i][j];
    }
  }
}

void binary(string inp1, int* T_l1, int mode){
  for(int i=0+8*mode;i<8+8*mode;i++){
    int k=(int)(inp1[i]-'f');
    T_l1[4*i+3-32*mode]=k&01;
    k=k>>1;
    T_l1[4*i+2-32*mode]=k&01;
    k=k>>1;
    T_l1[4*i+1-32*mode]=k&01;
    k=k>>1;
    T_l1[4*i+0-32*mode]=k&01;
  }
  return;
}

void cupy(string s, int* d){
  for(int i=0;i<32;i++){
    d[i]=(int)s[i];
  }
  return;
}

int main(){
  ifstream infile;
  infile.open("differential_1.txt");
  string inp1,inp2,diff_l,diff_r;
  for(int i=0;i<5;i++){
    for(int j=0;j<64;j++){
      possible_keys[i][j]=0;
    }
  }
  while(infile>>inp1>>inp2>>diff_l>>diff_r){
    int T_l1[32],T_r1[32],T_l2[32],T_r2[32],T_L1[32],T_L2[32],T_R1[32],T_R2[32];
    int diffr_r[32],diffr_l[32];
    binary(inp1,T_L1,0);
    binary(inp2,T_L2,0);
    binary(inp1,T_R1,1);
    binary(inp2,T_R2,1);
    cupy(diff_l,diffr_l);
    cupy(diff_r,diffr_r);

    for(int i=0;i<64;i++){
      int idx=RFP[i]-1;
      if(i<=31){
        T_l1[i]=T_L1[idx];
        T_l2[i]=T_L2[idx];
      }else{
        T_l1[i]=T_R1[idx-32];
        T_l2[i]=T_L2[idx-32];
      }
    }

    int c_dash[32]={0,0,0,0,
                    0,1,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0,
                    0,0,0,0};
    int D_dash[32];
    for(int i=0;i<4;i++){
      D_dash[i]=-1;
    }
    for(int i=4;i<8;i++){
      D_dash[i]=0;
    }
    for(int i=8;i<16;i++){
      D_dash[i]=-1;
    }
    for(int i=16;i<32;i++){
      D_dash[i]=0;
    }

    int reverse_c_dash[32], reverse_Tl_dash[32];

    for(int i=0;i<32;i++){
        reverse_c_dash[i]=c_dash[INV_P[i]-1];
        reverse_Tl_dash[i]=T_l1[INV_P[i]-1]^T_l2[INV_P[i]-1];
    }


    int S_box_output[32];
    for(int i=0;i<32;i++){
      if(D_dash[i]==-1){
        S_box_output[i]=-1;
      }else{
        S_box_output[i]=reverse_Tl_dash[i]^reverse_c_dash[i];
      }
    }

    key_gen(T_r1,T_r2,S_box_output);

    for(int i=0;i<5;i++){
      for(int j=0;j<63;j++){
        // cout<<possible_keys[i][j]<<" ";
      }cout<<endl;
    }cout<<"____________________________________"<<endl;

  }
}
