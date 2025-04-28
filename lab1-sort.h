/* PROGRAM FOR SORTING*/

#include <cstdio>
#include <cstdlib>


int * sortlist(int len,int * list);

int * sortlist(int len,int * list){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(list[j+1]<list[j]){
                int temp=list[j+1];
                list[j+1]=list[j];
                list[j]=temp;
            }
        }
    }
    return list;
}

