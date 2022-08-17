#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAMESIZE 32
struct student_st
{
    int id;
    //若有一同学的名字是50个字符，其余同学名字为10字符一下，数组不能很好的进行数据浮动
    char name[NAMESIZE];
    int math;
    int chinese;
};
void stu_set(struct student_st *p,const struct student_st *q)
{
    *p=*q;
}
void stu_show(struct student_st *p)
{
    printf("%d %s %d %d\n",p->id,p->name,p->math,p->chinese);
}
void stu_changename(struct student_st *p,const char *newname)
{
    strcpy(p->name,newname);
}
void menu(void)
{
    printf("\n1set \n2changename \n3show\n");
    printf("enter the num:");
}
int main()
{
    struct student_st stu,tmp;
    char newname[NAMESIZE];
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
                printf("enter the infomrmation of student[id name math chinese]:");
                scanf("%d%s%d%d", &tmp.id, tmp.name, &tmp.math, &tmp.chinese);
                stu_set(&stu, &tmp);
                break;
            case 2:
                printf("enter new name:")
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