#include<stdio.h>
#include<stdlib.h>

struct list
{
    int c;
    int e;
    struct list *next;
};
typedef struct list node;
node *addpoly(node *s1,node *s2);
node *create();
node *insertatend(node *,int,int);
void display(node *);
main()
{
    node *s1,*s2,*s3 = NULL;
    printf("Polynomial 1:\n");
    s1 = create();
    printf("Polynomial 2:\n");
    s2 = create();
    s3 = addpoly(s1,s2);
    display(s3);
}
node *addpoly(node *s1,node *s2)
{
    node *tempx,*tempy;
    node *s = NULL;
    int c,e;
    tempx = s1;
    tempy = s2;
    while(tempx != NULL && tempy != NULL)
    {
        if(tempx->e == tempy->e)
        {
            c = tempx->c + tempy->c;
            tempx = tempx->next;
            tempy = tempy->next;
        }
        else{
            if (tempx->e>tempy->e){
                c = tempx -> c;
                e = tempx ->e;
                tempx = tempx->next;

            }
            else{
                c = tempy -> c;
                e = tempy -> e;
                tempy = tempy -> next;
            }
        }
        s = insertatend(s,c,e);
    }
    if(tempy == NULL && tempx != NULL)
    {
        while(tempx!=NULL){
            c = tempx -> c;
            e = tempx-> e;
            s = insertatend(s,c,e);
            tempx = tempx -> next;
        }

    }
    if (tempy != NULL && tempx == NULL)
    {
        while(tempy != NULL)
        {
            c = tempy -> c;
            e = tempy-> e;
            s = insertatend(s,c,e);
            tempy = tempy->next;
        }

    }
    return s;

}
node *create()
{
	node *s=NULL,*p,*nn;
	int n;
	int c,e;
	char ano = 'y';
	while(ano == 'y')
	{
		printf("Enter the number:");
		scanf("%d %d",&c,&e);

		nn = (node * )malloc(sizeof(node));
		nn -> c = c;
		nn -> e = e;
		nn -> next = NULL;
		if(s == NULL)
		{
			s = nn;
		}
		else
		{
			p->next = nn;
		}
		p = nn;
		printf("Continue?[y/n]");
		fflush(stdin);
		scanf("%c",&ano);
	}
	return (s);
}
node *insertatend(node *s,int c,int e)
{
    node *nn,*t;
    nn = (node *)malloc(sizeof(node));
    nn -> c= c;
    nn -> e = e;
    nn ->next = NULL;
    if(s == NULL)
    {
        s = nn;
    }
    else{
        t = s;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t -> next = nn;
    }
    return(s);
}
void display(node *s)
{
    node *t;
    t = s;
    while(t!=NULL)
    {
        printf("%d %d\n",t->c,t->e);
        t = t->next;
    }

}
