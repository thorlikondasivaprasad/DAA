#include <stdio.h>
#include<limits.h>
#define verti 5

int min_key(int k[],int mst[])  /* k[] is selecting edge having min weight */
{
    int mini=INT_MAX,min,i;  /* INT_MAX=infinity*/
    
    for (i=0;i<verti;i++)
    {
        if (mst[i]==0 && k[i] < mini)    /* ! visited = True and (0 < infinity) */
        {
            mini=k[i];
            min=i;
        }
    }
    return min;
}

void prim(int g[verti][verti])
{
    int parent[verti],k[verti],mst[verti];  /* parent[0]=-1 ,i.e,parent[0] is rootnode*/
    int i ,count,edge,v;
    
    for(i=0;i<verti;i++)
    {
        k[i]=INT_MAX; 
        mst[i]=0; 
    }
    k[0]=0;
    parent[0]=-1;
    
    for (count=0;count < verti-1 ;count++)
    {
        edge=min_key(k,mst); 
        mst[edge]= 1;
        
        for(v=0; v< verti ;v++)
        {
            if (g[edge][v] && mst[v]==0 && g[edge][v] < k[v])   /* g[0][0,1,2,3,4] check every ele in all Vth row */
            {    
                parent[v]= edge; 
                k[v]=g[edge][v];
            }
            
        }
    }
    
    printf("\n Edge  \t weight\n");
    for (i=1;i<verti;i++)
    {
        printf("%d --- %d  %d\n",parent[i],i,g[i][parent[i]]);
    }
}

int main()
{
    int g[verti][verti]= {{0, 0, 3, 0, 0},    
                            {0, 0, 10, 4, 0},    
                            {3, 10, 0, 2, 6},    
                            {0, 4, 2, 0, 1},    
                            {0, 0, 6, 1, 0},    
                         };
                         
    prim(g);
    return 0;
}




