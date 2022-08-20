#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

sqlist *sqlist_create()
{
    sqlist *me;
    me=malloc(sizeof(*me));
    if(me==NULL)
        return NULL;
    me->last=-1;//表当前线性表无任何有效内容
    return me;//利用返回值指针，把起始位置带回来
}
// void sqlist_creoate1(sqlist **ptr)//利用二级指针传参
// {
//     *ptr=malloc(sizeof(**ptr));
//     if(*ptr==NULL)
//         return ;
//     (*ptr)->last=-1;
//     return ;
// }
/*第i个下标插入data*/
int sqlist_insert(sqlist *me,int i,datatype *data) 
{
    int j;
    if(me->last==DATASIZE-1) 
        return -1;
    if(i<0||i>(me->last)+1) //插入位置错误
        return -2;
    for(j=me->last;i<=j;j--)
        me->data[j+1]=me->data[j];
    me->data[i]=*data;
    me->last++;
    return 0;
}
int sqlist_delete(sqlist *me,int i)
{
    printf("del start\n");
    if(i<0||i>me->last)
        return -1;
    int j;
    for(j=i+1;j<=me->last;j++)
        me->data[j-1]=me->data[j];
    me->last--;
    printf("del end\n");
    return 0;

}
int sqlist_find(sqlist *me,datatype *data)
{
    if(sqlist_isempty(me)==0)
            return -1;
    int i;
    for(i=0;i<=me->last;i++)
    {
        if(me->data[i]==*data)
            return i;
    }
    return -1;
}
int sqlist_isempty(sqlist *me)
{
    if(me->last==-1)
        return 0;
    return -1;
}
int sqlist_setempty(sqlist *me)
{
    me->last=-1;
    return 0;
}
int sqlist_getnum(sqlist *me)
{
    return (me->last+1);
}
void sqlist_display(sqlist *me)
{
    if(me->last==-1)
        return ;
    int i;
    for(i=0;i<=me->last;i++)
        printf("%d ",me->data[i]);
    printf("\n");
    return ;
}
int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}
int sqlist_union(sqlist *list1,sqlist *list2)
{
   int i;
   for(i=0;i<=list2->last;i++)
   if((sqlist_find(list1,&list2->data[i]))<0)
        sqlist_insert(list1,list1->last+1,&list2->data[i]); 
   return 0;
}
