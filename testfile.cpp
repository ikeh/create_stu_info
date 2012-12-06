/******
**Copyright (c) 2012- Ikeh Shiel
**用二级指针定义姓氏，定义名字。然后利用随机函数从
**数组中取出姓和名组合。分数也是利用随机函数产生。
**要求：这里是100人，我要求调用的函数能传参，
**不确定人数。可以通过传参改变。
**每个人 分别是：学号 ，姓名 ，性别，五个分数，
**分数可以限定在45分以上。要求生成的文件 学号 人数可以增可减。
*****/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;
#define strcombine(x,y) (#x)##(#y)
#define ui32 unsigned int
#define num_stu 100

char *first_name[] = {"史","朱","陈","杨","鲁","李","周","林","柴","朱",\
"杜","宋","杨","索","朱","雷","刘","吴","阮","阮",\
"阮","公","白","曹","宋","宋","武","张","孙","施",\
"孔","孔","燕","王","郑","花","黄","秦","吕","郭","李","慕容","容"};
char *last_name[] = {"盛","勇","立","俊","威","猛","永","横","弘","春",\
"宗","逵","顺风","康","宣","雄起","秀","圯","振","兖",\
"徐","樊","项","李","段","进","武","达","春","智深",\
"忠","通","冲","进","贵","迁","万","志","超","梦婷","晓婷"};

char *sexs[]={"男","女"};//从first_name取姓，last_name取名用strcat连接
char fullname[10]={'\0'};
char *fn=NULL;
char *ln=NULL;
struct _stu_
{
	char *name;
	char *sex;
	int chengji[5];
	int xuehao;
};
typedef struct _stu_ stu;


void Write_Info(FILE *fd , stu *boy);

void inline Write_Info(FILE *fd , stu *boy)
{
    fprintf(fd,"%-5d %-9s %-3s %-3d %-3d %-3d %-3d %-3d\n",\
    boy->xuehao,\
    boy->name,\
    boy->sex,\
    boy->chengji[0],boy->chengji[1],boy->chengji[2],boy->chengji[3],boy->chengji[4]);

}
void get_name(ui32 fn_len,ui32 ln_len)
{
    
    fn=first_name[rand()%fn_len];
    strcpy(fullname,"\0");
    strcat(fullname,fn);
    ln=last_name[rand()%ln_len];
    strcat(fullname,ln);
}
void getfullname()
{
    char gefn[10]={"\0"};
    //strcpy(gefn,"\0");
    strcat(gefn,(first_name[41]));
    strcat(gefn,last_name[39]);
    printf("---%s-----\n",gefn);
}
void out2file(FILE *fd)
{
    stu boy;
    srand(time(NULL));
    int i=0,j;
    int fn_len=sizeof(first_name)/sizeof(*first_name);
    int ln_len=sizeof(last_name)/sizeof(*last_name);
    for(;i<num_stu;i++)//init 100 students a[i]+j
    {
        //建立stu的资料
        get_name(fn_len,ln_len);
        boy.name=fullname;
        boy.sex=sexs[rand()%2];
        boy.xuehao=i;
        int score=0;
        //score = rand()%101;
        for(int course=0;course<5;course++)
        {
            score = rand()%101;
            boy.chengji[course]=score;
        }
        
        Write_Info(fd,&boy);

    }
}

int main()
{
    getfullname();
    
	FILE *fd = fopen("name.txt","w");
        if(fd == NULL)
        {
            cout<<"File open faild.";
            exit(0);
        }
    
    out2file(fd);
    printf("ok.\n"); 
	fclose(fd);

	//system("pause");
	return 0;
}
//for(int j=0;j<80;)//用于测试名字存储
//    {
//        printf("%c%c",first_name[j],first_name[j+1]);
//        j += 2;
//    }
