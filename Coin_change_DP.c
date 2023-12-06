#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 999999
int min(int a,int b){
	if(a<b)
	   return a;
	else
	   return b;
}
int coinchange(int ind,int tgt,int coins[] ){
	if(ind==0){
		if(tgt%coins[0]==0)
		    return tgt/coins[0];
		else
		    return -1;
	}
	int nottake=coinchange(ind-1,tgt,coins);
	int take=INT_MAX;
	if(coins[ind]<=tgt){
		take=1+coinchange(ind,tgt-coins[ind],coins);	
	}
	return min(take,nottake);
}
int main(){
	int n,tgt,res;
	printf("\n Enter no.of different denominations:");
	scanf("%d",&n);
	int coins[10];
	for(int i=0;i<n;i++){
		scanf("%d",&coins[i]);
	}
	printf("\n Enter the target:");
	scanf("%d",&tgt);
	res=coinchange(n-1,tgt,coins);
	printf("%d is solution..",res);
}



Output:

Enter no.of different denominations:4
1 5 6 9
Enter the target:11
2 is solution 
