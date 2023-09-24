// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct s2
{
    int val;
    struct s2 * ne;
};
 struct s2 * createnode(int v)
 {
     struct s2 *h;
     h=(struct s2 *)malloc(sizeof(struct s2));
     h->val=v;
     h->ne=NULL;
     return h;
 }
 
 struct s2 * createlist(int n)
 {
     struct s2 * h=NULL,*t,*new;
     printf("Enter elements: ");
     int i,v;
     for (i=0;i<n;i++){
        scanf("%d",&v);
        new=createnode(v);
        if (h==NULL)
            h=new;
        else
            t->ne=new;
        t=new;
     }
     return h;
 }
 
 void print(struct s2 *h)
 {
     while(h){
         printf("%d->",h->val);
         h=h->ne;
     }
 }
 
 int main()
 {
     struct s2 *h;
     int n;
     printf("Enter no.of elements in list: ");
     scanf("%d",&n);
     h=createlist(n);
     print(h);
 }
 