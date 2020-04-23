#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define MAX 60013
const int mod1=60013;
const int mult1=1013;
const long mod2=1000000007;
const long mult2=1000007;

typedef struct node
{
    int val1;
    int val2;
    struct node *next;
}HashTable;

char ch,s[100];
int repeat;
int flag,k;
HashTable *Hash[MAX],*vis;

int FirstHash(char s[]);
int SecondHash(char s[]);
void insert(HashTable **Hash,int repeat,char s[]);
int find(HashTable **Hash,int repeat[],char s[]);

int main()
{
	int j=1;
	for(int i=0;i<mod1;i++)
		Hash[i]=NULL;
    while(~(ch=getchar()))
	{
        if(!isalpha(ch))
		{
            if(!flag)
            {
                s[k]='\0';
                repeat=0;
                if(find(Hash,&repeat,s))
					printf("%d",repeat);
                else
                {
                    insert(Hash,j++,s);
                    printf("%s",s);
                }
				putchar(ch);
                flag=1;
                k=0;
            }
            else
			{
				putchar(ch);
                flag=1;
            }
        }
        else
        {
            flag=0;
            s[k++]=ch;
        }
    }
}

int FirstHash(char s[])
{
    int ans=0;
    for(int i=0;i<strlen(s);i++)
        ans=(ans*mult1+s[i]-'A'+1)%mod1;
    return ans;
}
int SecondHash(char s[])
{
    int ans=0;
    for(int i=0;i<strlen(s);i++)
        ans=(ans*mult2+s[i]-'A'+1)%mod2;
    return ans;
}
void insert(HashTable **Hash,int repeat,char s[])
{
    int key=FirstHash(s);
    HashTable *q=(HashTable*)malloc(sizeof(HashTable));
    q->val1=repeat;
    q->next=NULL;
    q->val2=SecondHash(s);
    if(Hash[key]!=NULL)
		vis->next=q;
    else
		Hash[key]=q;
}
int find(HashTable **Hash,int repeat[],char s[])
{
    int key2=FirstHash(s);
    HashTable *p=Hash[key2];
    int val2=SecondHash(s);
    if(p==NULL)
        return 0;
    while(p->next!=NULL)
	{
        if(p->val2==val2)
		{
            *repeat=p->val1;
            return 1;
        }
        p=p->next;
    }
    if(p->val2==val2)
	{
        *repeat=p->val1;
        return 1;
    }
    vis=p;
    return 0;
}
