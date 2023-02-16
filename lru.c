#include <stdio.h>

int lru(int time[],int fn){
    int min=time[0],pos,i;
    for(i=1;i<fn;i++){
        if(min>time[i]){
            min=time[i];
            pos=i;


        }
        
    
}
return pos;}
int main(){
    int pn,fn,frame[10],page[30],avail,count=0,i,k,j=0,flag1,flag2,time[10],fault=0,pos=0;
    printf("Enter the number of frames: ");
    scanf("%d",&fn);
    printf("Enter the number of pages: ");
    scanf("%d",&pn);
    printf("Enter the page reference string: ");
    for(int i=0;i<pn;i++){
        scanf("%d",&page[i]);
    }
    for(int i=0;i<fn;i++){
        frame[i]=-1;
    }

    for(int i=0;i<pn;i++){
        flag1=0;
        flag2=0;
        for(int j=0;j<fn;j++){
            if(frame[j]==page[i]){
                flag1=1;
                flag2=1;
                count++;
                time[j]=count;
                break;
            }}
            if(flag1==0){
        for(j=0;j<fn;j++){
            if(frame[j]==-1){
                frame[j]=page[i];
                count++;
                fault++;
                time[j]=count;
                flag2=1;
                break;
            }
        }
     }
            if(flag2==0){
                pos=lru(time,fn);
                frame[pos]=page[i];
                fault++;
                count++;
                time[pos]=count;
            }
            for(k=0;k<fn;k++)
            printf("%d",frame[k]);

            printf("\n");

        }
    
    printf("Fault : %d",fault);
    }