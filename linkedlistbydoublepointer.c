#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;

};
struct node * getNode(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}

void insBeg(struct node **list,int x){
    struct node* n;
    n=getNode();
    n->info=x;
   n->next=*list;
   *list=n;
}

void insEnd(struct node **list,int x){
    struct node *p,*n;
    p=*list;

    while(p->next!=NULL){
        p=p->next;
    }
     n=getNode();
     n->info=x;
     p->next=n;
     n->next=NULL;
     printf("\n");
}

void insPos(struct node **list,int pos,int x){
    struct node *p,*n;
    p=*list;
    n=getNode();

    int curr_pos=0;
    while(curr_pos!=pos-1){
        p=p->next;
        curr_pos++;
    }
    n->info=x;
    n->next=p->next;
    p->next=n;
    printf("\n");

}

void delBeg(struct node **list){
    struct node *p,*q;
    p=*list;
    q=p->next;
    *list=q;
    free(p);
    printf("\n");

}

void delEnd(struct node **list){
    struct node *p,*q;
    p=*list;
    while(p->next->next!=NULL){
        p=p->next;
    }
    q=p->next;
    p->next=NULL;
    free(q);
    printf("\n");
}


void delPos(struct node **list,int pos){
    struct node *p,*q;
    p=*list;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        p=p->next;
        curr_pos++;
    }
    q=p->next;
    p->next=p->next->next;
    free(q);
    printf("\n");


}
void display(struct node *list){
    struct node *p;
    p=list;
    while(p!=NULL){
        printf("%d ->",p->info);
        p=p->next;
    }
    printf("NULL");
}
struct node *merge(struct node **start1,struct node **start2)
{
    struct node *p=(*start1);
    struct node *q=(*start2);
    struct node *start3;
    start3=getNode();
    start3=NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->info<q->info)
        {
            insBeg(&start3,p->info);
            p=p->next;
        }
        else
        {
            insBeg(&start3,q->info);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insBeg(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        insBeg(&start3,q->info);
        q=q->next;
    }
    return start3;
}
struct node *reverse(struct node **start)
{
    struct node *curr=(*start);
    struct node *prev=NULL;
    struct node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
    return start;
}
struct node *intersection(struct node **start1,struct node **start2)
{
    struct node *p=(*start1);
    struct node *q=(*start2);
    struct node *start3;
    start3=getNode();
    start3=NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->info<q->info)
        {
            p=p->next;
        }
        else if(q->info<p->info)
        {
            q=q->next;
        }
        else
        {
            insBeg(&start3,p->info);
            p=p->next;
            q=q->next;
        }
    }
    return start3;
}
struct node *unionn(struct node **start1,struct node **start2)
{
    struct node *p=(*start1);
    struct node *q=(*start2);
    struct node *start3;
    start3=getNode();
    start3=NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->info<q->info)
        {
            insBeg(&start3,p->info);
            p=p->next;
        }
        else if(q->info<p->info)
        {
            insBeg(&start3,q->info);
            q=q->next;
        }
        else
        {
            insBeg(&start3,p->info);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insBeg(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        insBeg(&start3,q->info);
        q=q->next;
    }
    return start3;
}
struct node *difference(struct node **start1,struct node **start2)
{
    struct node *p=(*start1);
    struct node *q=(*start2);
    struct node *start3;
    start3=getNode();
    start3=NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->info<q->info)
        {
            insBeg(&start3,p->info);
            p=p->next;
        }
        else if(q->info<p->info)
        {
            q=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insBeg(&start3,p->info);
        p=p->next;
    }
    return start3;
}
struct node *symmeticdifference(struct node **start1,struct node **start2)
{
    struct node *p=(*start1);
    struct node *q=(*start2);
    struct node *start3;
    start3=getNode();
    start3=NULL;
    while(p!=NULL&&q!=NULL)
    {
        if(p->info<q->info)
        {
            insBeg(&start3,p->info);
            p=p->next;
        }
        else if(q->info<p->info)
        {
            insBeg(&start3,q->info);
            q=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        insBeg(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL)
    {
        insBeg(&start3,q->info);
        q=q->next;
    }
    return start3;
}
int main(){
    struct node *start1;
    struct node *start2;
    start1=NULL;
    start2=NULL;
    insBeg(&start1,6);
    insBeg(&start1,5);
    insBeg(&start1,4);
    insBeg(&start1,2);
    insBeg(&start1,1);
    display(start1);
    printf("\n");
    insBeg(&start2,9);
    insBeg(&start2,8);
    insBeg(&start2,5);
    insBeg(&start2,4);
    insBeg(&start2,3);
    display(start2);
    printf("\n");
    struct node *start3=symmeticdifference(&start1,&start2);
    start3=reverse(&start3);
    display(start3);
    return 0;
}
