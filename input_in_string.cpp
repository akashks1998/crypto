#include<bits/stdc++.h>
using namespace std;



int main(){
    int block1[64];
    int block2[64];
    int diff[64]=
        {0,0,1,0, 0,0,0,0
        ,0,0,0,0 ,0,1,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,1,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
    };
    for(int k=0;k<100000;k++){
        for(int i=0;i<64;i++){
            block1[i]=rand()%2;
            block2[i]=block1[i]^diff[i];
        }
        int RFP[] = {
            8,40,16,48,24,56,32,64,
            7, 39,15,47,23,55,31,63,
            6,38,14,46,22,54,30,62,
            5,37,13,45, 21,53,29,61,
            4,36,12,44,20,52,28,60,
            3, 35, 11,43,19,51,27,59,
            2, 34, 10, 42,18, 50,26,58,
            1,33,9,41, 17, 49, 25,57
        };
        int LR1[64],LR2[64];
        for (int j =0; j<64 ; j++){
            LR1[j] = block1[RFP[j] -1];
            LR2[j] = block2[RFP[j]-1];
        }
        int num=0;
        for(int i=0;i<16;i++){
          num=0;
            for(int j=0;j<4;j++){
              num=num*2+LR1[i*4+j];
            }
            cout<<(char)('f'+num);
        }
        cout<<endl;
        for(int i=0;i<16;i++){
          num=0;
            for(int j=0;j<4;j++){
              num=num*2+LR2[i*4+j];
            }
            cout<<(char)('f'+num);
        }
        cout<<endl;
    }
    return 0;
}