#include <stdio.h>

#define MaxSize 50 //符号常量
typedef int ElemType;//让顺序表存储其他类型元素时，可以快速完成代码的修改
//静态分配
typedef struct {
    ElemType data[MaxSize];
    int length;//顺序表长度
}SqList;
//动态分配
//#define InitSize 100
//typedef struct {
//    ElemType *data;
//    int capacity;//动态数组的最大容量
//    int length;
//}SeqList;

//顺序表的插入，因为L会改变，因此这里要使用引用，i是插入的位置
bool ListInsert(SqList &L,int i,ElemType e){//i代表插入的位置，从1开始，e代表插入的元素
    //判断i是否合法
    if(i<1||i>=L.length+1){//判断要插入的位置是否合法
        return false;//未插入返回false
    }
    //如果存储空间满了，不能插入
    if(L.length>=MaxSize){//超出空间了
        return false;//未插入返回false
    }
    //把i后面的元素依次往后移动，空出位置，来存放要插入的元素
    for(int j=L.length;j>=i;j--){//移动顺序表中的元素
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;//存放要插入的元素 //数组下标从零开始，插入第一个位置，访问的下标为0
    L.length++;//顺序表长度加1
    return true;//插入成功返回true
}

//打印顺序表元素
void PrintList(SqList L){
    int i=0;
    for(i=0;i<L.length;i++){
        printf("%3d",L.data[i]);//为了打印到同一行
    }
    printf("\n");
}

//删除顺序表中的元素，i是要删除的元素的位置，e用来存储获取被删除的元素的值
bool ListDelete(SqList &L,int i,ElemType &e){//使用元素e的引用的目的是拿出对应的值
    //判断删除的元素的位置是否合法
    if(i<1||i>L.length){//如果删除的位置是不合法
        return false;//一旦走到return函数就结束了
    }
    e=L.data[i-1];//首先保存要删除元素的值 获取顺序表中对应的元素，赋值给e
    int j;
    for(j=i;j<L.length;j++){//往前移动元素
        L.data[j-1]=L.data[j];
    }
    L.length--;//删除一个元素，顺序表长度减1
    return true;
}

//查找某个元素的位置，查找成功，返回位置，位置从1开始，查找失败，返回0
int LocateElem(SqList L,ElemType e){
    int i;
    for(i=0;i<L.length;i++){
        if(e==L.data[i]){
            return i+1;//因为i是数组的下标，加1以后才是元素在顺序表中的位置
        }
    }
    return 0;//循环结束没找到
}

//顺序表的初始化及插入操作实战
int main() {
    SqList L;//定义一个顺序表，变量L
    bool ret;//ret用来存放函数的返回值，布尔型是True，或者False
    //手动在顺序表中赋值
    L.data[0]=1;//放置元素
    L.data[1]=2;
    L.data[2]=3;
    L.length=3;//设置长度
    //插入操作
    ret=ListInsert(L,2,60);
    if(ret){
        printf("insert sqList success\n");
        PrintList(L);
    }else{
        printf("insert sqList failed\n");
    }
    ElemType del;//删除的元素存放在del中
    //删除操作
    ret=ListDelete(L,2,del);
    if(ret){
        printf("delete sqList success\n");
        printf("del element=%d\n",del);
        PrintList(L);//打印顺序表
    }else{
        printf("delete sqList failed\n");
    }
    //查询元素
    int pos;//存储元素的位置
    pos= LocateElem(L,60);
    if(pos){
        printf("find this element\n");
        printf("element pos=%d\n",pos);
    }else{
        printf("don't find this element\n");
    }
    return 0;
}

