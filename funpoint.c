//用GCC 8.1 的版本编译的时候发现的...
#include <stdio.h>
#include <stdlib.h>

#define VERSION_DEF_F 0
//  #define VERSION_DEF_FF 1

#ifdef VERSION_DEF_FF
typedef int (*ff)(int,int);//  
int cal(int x,int y,ff mfun){ return mfun(x,y);}
#endif

#ifdef VERSION_DEF_F
int (*f)(int,int); //f=add; is ok!  and f=&add; also be OK! why ?
#endif

int add(int x,int y){return x+y;}
int sub(int x,int y){return x-y;}

int main()
{
#ifdef VERSION_DEF_FF
    int x=1,y=2;
    printf("%d\n",cal(x,y,add));
    printf("%d\n",cal(x,y,sub));
#endif

#ifdef VERSION_DEF_F   
    //下面这段代码，让我糊涂...只能解释编译器强大？智能？
    f = &add;//对比33行
    printf("add = %d\n",f(1,2));//对比34行

    f = sub;//对比30行
    printf("sub = %d",f(1,2));//对比31行
#endif

    return 1;
}