#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"
int main()
{
    sqlist *list=NULL,*list2=NULL;
    datatype arr[]={12,23,34,45,56};
    datatype arr2[]={89,90,78,67,56,45};
    int i,err;
    list=sqlist_create();
    // sqlist_create(list);
    if(list==NULL){
        fprintf(stderr,"sqlist_create() failed\n");
        exit(1);
    }
    list2=sqlist_create();
    // sqlist_create(list);
    if(list2==NULL){
        fprintf(stderr,"sqlist_create() failed\n");
        exit(1);
    }
    // printf("%d\n",__LINE__);//gcc提供的宏
    for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
    {
        // sqlist_insert(); 
        if((err=sqlist_insert(list,i,&arr[i]))!=0){ 
            if(err==-1)
                fprintf(stderr,"the arr is full\n");
            else if (err==-2)
                fprintf(stderr,"the pos is wrong\n");
            else
                fprintf(stderr,"Error\n");
            exit(1); 
        }
    }
    for(i=0;i<sizeof(arr2)/sizeof(*arr2);i++)
        sqlist_insert(list2,i,&arr2[i]);
    sqlist_display(list);  
    sqlist_display(list2); 
    // sqlist_delete(list,0);
    sqlist_union(list,list2);
    sqlist_display(list);
    sqlist_destroy(list);
    sqlist_destroy(list2);
    exit(0);
}