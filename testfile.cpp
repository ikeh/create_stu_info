/******
**Copyright (c) 2012- Ikeh Shiel
**�ö���ָ�붨�����ϣ��������֡�Ȼ���������������
**������ȡ���պ�����ϡ�����Ҳ�������������������
**Ҫ��������100�ˣ���Ҫ����õĺ����ܴ��Σ�
**��ȷ������������ͨ�����θı䡣
**ÿ���� �ֱ��ǣ�ѧ�� ������ ���Ա����������
**���������޶���45�����ϡ�Ҫ�����ɵ��ļ� ѧ�� �����������ɼ���
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

char *first_name[] = {"ʷ","��","��","��","³","��","��","��","��","��",\
"��","��","��","��","��","��","��","��","��","��",\
"��","��","��","��","��","��","��","��","��","ʩ",\
"��","��","��","��","֣","��","��","��","��","��","��","Ľ��","��"};
char *last_name[] = {"ʢ","��","��","��","��","��","��","��","��","��",\
"��","��","˳��","��","��","����","��","��","��","��",\
"��","��","��","��","��","��","��","��","��","����",\
"��","ͨ","��","��","��","Ǩ","��","־","��","����","����"};

char *sexs[]={"��","Ů"};//��first_nameȡ�գ�last_nameȡ����strcat����
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
        //����stu������
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
//for(int j=0;j<80;)//���ڲ������ִ洢
//    {
//        printf("%c%c",first_name[j],first_name[j+1]);
//        j += 2;
//    }
