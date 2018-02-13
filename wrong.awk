#!/usr/bin/gawk
BEGIN{
indx=0
prev=NULL
 }
{
    indx=indx+1
    if($1==NULL||length($1)!=16||prev==$1){
       print indx " Previous line is " prev
    }  
    prev=$1
}
