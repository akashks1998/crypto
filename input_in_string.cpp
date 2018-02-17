#include<bits/stdc++.h>
using namespace std;



int main(){
    int block1[64];
    int block2[64];
    int diff[64]= //40 08 00 00 04 00 00 00
        {0,0,0,0, 0,1,0,0
        ,0,0,0,0 ,1,0,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,1,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
        ,0,0,0,0 ,0,0,0,0
    };
    for(int k=0;k<1000;k++){
        for(int i=0;i<64;i++){
            block1[i]=rand()%2;
            block2[i]=block1[i]^diff[i];
        }
        int RFP[] = {
        40,	8,	48,	16,	56,	24,	64,	32,
        39,	7,	47,	15,	55,	23,	63,	31,
        38,	6,	46,	14,	54,	22,	62,	30,
        37,	5,	45,	13,	53,	21,	61,	29,
        36,	4,	44,	12,	52,	20,	60,	28,
        35,	3,	43,	11,	51,	19,	59,	27,
        34,	2,	42,	10,	50,	18,	58,	26,
        33,	1,	41,	9,	49,	17,	57,	25
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
