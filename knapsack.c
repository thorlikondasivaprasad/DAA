#include<stdio.h>
#include<stdlib.h>
int main(){
	float wt[7]={1,3,5,4,1,3,3};
	float pf[7]={5,10,15,7,8,9,4};
	int used[7];
	int mw=15;
	int cur_w=mw,i,maxi;
	float profit=0;
	for(int i=0;i<7;i++)
	     used[i]=0;
	while(cur_w>0){
		maxi=-1;
		for(int i=0;i<7;i++){
			float pfwt=pf[i]/wt[i];
			if(used[i]==0 &&(maxi==-1||pfwt>(pf[maxi]/wt[maxi]))){
				maxi=i;
			}
	}
	//printf("%d ",maxi);
	 used[maxi]=1;
	 cur_w-=wt[maxi];
	 profit+=pf[maxi];
}
     profit+=(cur_w/wt[maxi])*pf[maxi];
	printf("%.5f",profit);
}

Oitput:

50.5000
