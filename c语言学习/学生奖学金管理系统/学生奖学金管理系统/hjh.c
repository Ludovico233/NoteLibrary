#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 20//学生人数
void menu()
{
	printf("--------------奖学金评选系统--------------\n");
	printf("|              1.录入成绩                 |\n");
	printf("|            2.学生成绩汇总               |\n");
	printf("|           3.学生排名(前10)              |\n");
	printf("|           4.奖学金获得情况              |\n");
	printf("|              5.退出程序                 |\n");
	printf("------------------------------------------\n");

}
typedef struct Stu
{
	char name[20];
	int id;
	float ch;
	float ma;
	float en;
	float sp;
	float s1;
	float s2;
	float s3;
	float s4;
	float all;
	float all1;
	float ave;
}stu;
 int stucount;
 stu  s[N];//学生数组
 stu s1[N]; //用来排序的临时数组
 FILE* fp;

 void hang()//取行数
 {	
	 int j = 1;
	 char c;
	 fp = fopen("C:\\Users\\Ludovico\\Desktop\\score.txt", "r");
	 while (1)
	 {
		 c = fgetc(fp);
		 if (c == '\n')j++;
		 if (c == EOF)break;
	 }
	 stucount = j;
	 fclose(fp);
	 fp = NULL;
 }
 void add()
 {
	 int i, j;
	 hang();
	 printf("要追加多少位学生的成绩：");
	 scanf("%d", &j);//j为添加人数不超过10
	 fp = fopen("C:\\Users\\Ludovico\\Desktop\\score.txt", "a+");
	 for (i = 1; i <= j; i++)
	 {
		 printf("请输入姓名，学号，语文成绩，数学成绩，英语成绩，体育成绩以及4门专业课成绩：\n");
		 scanf("%s %d %f %f %f %f %f %f %f %f", s1[i].name, &s1[1].id, &s1[i].ch, &s1[i].ma, &s1[i].en, &s1[i].sp, &s1[i].s1, &s1[i].s2, &s1[i].s3, &s1[i].s4);
		 s[i] = s1[i];
		 s[i].all = s[i].ch + s[i].ma + s[i].en + s[i].sp + s[i].s1 + s[i].s2 + s[i].s3 + s[i].s4;
		 s[i].all1 = s[i].s1 + s[i].s2 + s[i].s3 + s[i].s4;
		 s[i].ave = s[i].all / 8;
		 fprintf(fp, "%s %d %f %f %f %f %f %f %f %f %f %f %f\n", s[i].name, s[i].id, s[i].ch, s[i].ma, s[i].en, s[i].sp, s[i].s1, s[i].s2, s[i].s3, s[i].s4, s[i].all, s[i].all1, s[i].ave);
	 }
	 fclose(fp);
	 fp = NULL;
 }
 void show()
 {
	
	 int i;
	 hang();
 printf("\n%d", stucount);
	 fp = fopen("C:\\Users\\Ludovico\\Desktop\\score.txt", "r");
	 printf("姓名\t学号\t语文\t\t数学\t\t英语\t\t体育\t\t专业课1\t\t专业课2\t\t专业课3\t\t专业课4\t\t总分\t\t专业课总分\t 平均分\n");
	 for (i = 0; i < stucount-1; i++)
	 {



		 fscanf(fp, "%s %d %f %f %f %f %f %f %f %f %f %f %f", s[i].name, &s[i].id, &s[i].ch, &s[i].ma, &s[i].en, &s[i].sp, &s[i].s1, &s[i].s2, &s[i].s3, &s[i].s4, &s[i].all, &s[i].all1, &s[i].ave);
		 printf("%s\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", s[i].name, s[i].id, s[i].ch, s[i].ma, s[i].en, s[i].sp, s[i].s1, s[i].s2, s[i].s3, s[i].s4, s[i].all, s[i].all1, s[i].ave);
	 }
	 fclose(fp);
	 fp = NULL;
 }

 
 void sort()
 {
	 int i, j = 0;
	 stu t;//排序的临时变量
	 show();
	 system("cls");
	 menu();
	 printf("《排名情况表》\n");
	 for (i = 0; i < stucount; i++)s1[i] = s[i];
	 for (i = 0; i < stucount; i++)
		 for (j = 0; j < stucount - i - 1; j++)
		 {
			 if (s1[j].all < s1[j + 1].all)
			 {
				 t = s1[j];
				 s1[j] = s1[j + 1];
				 s1[j + 1] = t;

			 }
			 else if (s1[j].all == s1[j + 1].all)
			 {
				 if (s1[j].all1 < s1[j + 1].all1)
				 {
					 t = s1[j];
					 s1[j] = s1[j + 1];
					 s1[j + 1] = t;
				 }
			 }
		 }
	 for (i = 0; i < 10; i++)
	 {
		 printf("第%d名:\t%s\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", i + 1, s1[i].name, s1[i].id, s1[i].id, s1[i].ch, s1[i].ma, s1[i].en, s1[i].sp, s1[i].s1, s1[i].s2, s1[i].s3, s1[i].s4, s1[i].all, s1[i].all1, s1[i].ave);
	 }
 }
 void jxj()
 {
	 int i,j;
	 sort();
	 system("cls");
	 menu();
	 printf("\t《奖学金获得情况》\n");
	 printf("\t甲等奖学金：%s %s\n\t乙等奖学金：%s %s %s\n\t丙等奖学金：%s %s %s %s %s\n", s1[0].name, s1[1].name, s1[2].name, s1[3].name, s1[4].name, s1[5].name, s1[6].name, s1[7].name, s1[8].name, s1[9].name);
 }
 void over()
 {
	 printf("\n\t输入任意键退出\n");
	 exit(0);
 }
int main()
{
	int a;
	do
	{	
		menu();
		printf("请选择菜单选项：");
	    scanf("%d", &a);
		if (a >= 1 || a <= 4)
		{
			switch (a)
			{
			case 1:add(); break;
			case 2:show(); break;
			case 3:sort(); break;
			case 4:jxj(); break;
			case 5:over(); continue;
			default:printf("输错了，我们还没有该功能哦！请重新选择\n");
			}		
			//printf("输入任意键回到菜单\n");
			system("pause");
			system("cls");
		}

	} while (a >= 1 || a <= 4);
	return 0;
}
