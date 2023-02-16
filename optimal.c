#include <stdio.h>
int main(){
    int frame[20],page[20],fn,pn,flag1,flag2,flag3,pos,temp[10],i,j,k,fault=0,max;
    printf("Enter the no of pages");
    scanf("%d",&pn);
    printf("Enter the no of frames : ");
    scanf("%d",&fn);
    printf("Enter the pages ");
    for(i=0;i<pn;++i){
        scanf("%d",&page[i]);

    }
    for(i=0;i<fn;++i){
        frame[i]=-1;
    }
    for(i=0;i<pn;++i){
        flag1=flag2=0;
        for(j=0;j<fn;j++){
            if(frame[j]==page[i]){
                flag1=flag2=1;
                break;
            }
        }

        if(flag1==0){
            for(j=0;j<fn;j++){
                if(frame[j]==-1){
                    frame[j]=page[i];
                    flag2=1;
                    fault++;
                    break;

                }
            }
        }
       if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < fn; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < pn; ++k){
            		if(frame[j] == page[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < fn; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }

        
         if(flag3==0){
            max=temp[0],pos=0;
            for(j=1;j<fn;++j){
                if(temp[j]>max){
                    max=temp[j];
                    pos=j;
                }

            }}
        frame[pos]=page[i];
        fault++;

        }
        for(j=0;j<fn;j++){
            printf("%d\t",frame[j]);
        }

   
    printf("\n");


}
printf("The no of page faults are %d",fault);
return 0;
}