#include<stdio.h>
#include<stdlib.h>
#define maxn 100010
#define TRUE 1
#define FALSE 0
int beg,end,pointNum,edgeNum;
int indegree[maxn];
typedef struct EdgeNode EdgeNode;
typedef struct EdgeNode * PEdgeNode;
typedef struct EdgeNode * EdgeList;

struct EdgeNode
{
    int endvex;		
    PEdgeNode nextedge;	
};				

typedef struct
{
    EdgeList edgelist;		
} VexNode;
				
typedef struct
{
    int n;			
    VexNode vexs[maxn];
} GraphList;

typedef struct
{
    int vexsno[maxn];
} Topo;

void findInDegree(GraphList* g,int *inDegree)
{
    int i;
	PEdgeNode p;
    for(i=0;i<g->n;i++)
        inDegree[i]=0;
    for(i=0;i<g->n;i++)
	{
        p=g->vexs[i].edgelist;
        while(p)
		{
            ++inDegree[p->endvex];
            p=p->nextedge;
        }
    }
}

int topoSort(GraphList * paov,Topo * ptopo)
{
    EdgeList p;
    int i,j,k,nodeno=0,top=-1;
    findInDegree(paov, indegree); 
    for(i=0;i<paov->n;i++)
        if(indegree[i]==0)
		{         
            indegree[i]=top;
			top=i;
        }
        while(top!=-1)
		{                          
            j=top;
            top=indegree[top];
            ptopo->vexsno[nodeno++]=j;
            p=paov->vexs[j].edgelist;
			while(p)
			{                      
				k=p->endvex;
				indegree[k]--;
				if(indegree[k]==0)
				{        
					indegree[k]=top;
					top=k;
				}
				p=p->nextedge;
			}
        }
        if(nodeno<paov->n)
		{
            printf("RECURSIVE_DEPENDENCY\n");
            return FALSE;
        }
		return TRUE;
}

void insert(GraphList* p,int a,int b)
{
    EdgeList pp;
    PEdgeNode temp;
    temp=(PEdgeNode)malloc(sizeof(EdgeNode));
    temp->endvex=b;
    temp->nextedge=NULL;
    pp=p->vexs[a].edgelist;
    if(pp==NULL)
		p->vexs[a].edgelist=temp;
    else
	{
        while(pp->nextedge!=NULL)
            pp=pp->nextedge;
        pp->nextedge=temp;
    }
}

GraphList *makeList()
{
    GraphList* p;
    int i;
    p=(GraphList*)malloc(sizeof(GraphList));
    scanf("%d%d",&pointNum,&edgeNum);
    p->n=pointNum+1;
    for(i=0;i<p->n;i++)
        p->vexs[i].edgelist=NULL;
    for(i=0;i<edgeNum;i++)
    {
    	scanf("%d%d",&beg,&end);
    	insert(p,beg,end);
	}
    return p;
}
int main()
{
    GraphList *p;
	Topo topo;
    int i;
    p=makeList();
    if(topoSort(p, &topo)==TRUE)
	{
		printf("%d",topo.vexsno[p->n-2]);
        for(i=p->n-3;i>=0;i--)
            printf(" %d",topo.vexsno[i]);
	}
	printf("\n");
}
