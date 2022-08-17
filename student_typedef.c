#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAMEMAX 1024
typedef struct student_st
{
    int id;
    //若有一同学的名字是50个字符，其余同学名字为10字符一下，数组不能很好的进行数据浮动
    char *name;
    int math;
    int chinese;
}STU;
void stu_set(STU *p,const STU *q)
{
    // *p=*q;
    // p->name=q->name;这样写是错误的.一旦q->name指向内容改变，p->name内容也改变
    p->id=q->id;
    p->name=malloc(strlen(q->name)+1);//+1存放\0
    if(p->name==NULL)
        exit(1);
    strcpy(p->name,q->name);
    p->math=q->math;
    p->chinese=q->chinese;

}
void stu_show(STU *p)
{
    printf("%d %s %d %d\n",p->id,p->name,p->math,p->chinese);
}
void stu_changename(STU *p,const char *newname)
{
    free(p->name);
    p->name=malloc(strlen(newname)+1);
    strcpy(p->name,newname);


}
void menu(void)
{
    printf("\n1set \n2changename \n3show\n");
    printf("enter the num:");
}
int main()
{
    STU stu,tmp;
    char newname[NAMEMAX];
    int choice;
    int ret;
    do
    {
        menu();
        ret = scanf("%d", &choice);
        if (ret != 1)
            break;
            switch (choice)
            {
            case 1:
                tmp.name=malloc(NAMEMAX);
                printf("enter the infomrmation of student[id name math chinese]:");
                scanf("%d%s%d%d", &tmp.id, tmp.name, &tmp.math, &tmp.chinese);
                stu_set(&stu, &tmp);
                break;
            case 2:
                printf("enter new name:");
                scanf("%s", newname);
                stu_changename(&stu, newname);
                break;
            case 3:
                stu_show(&stu);
                break;
            default:
                exit(1);
            }
    } while (1);
    exit(1);
}