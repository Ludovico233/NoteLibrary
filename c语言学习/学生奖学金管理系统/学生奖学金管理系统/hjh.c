#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define N 20//ѧ������
void menu()
{
	printf("--------------��ѧ����ѡϵͳ--------------\n");
	printf("|              1.¼��ɼ�                 |\n");
	printf("|            2.ѧ���ɼ�����               |\n");
	printf("|           3.ѧ������(ǰ10)              |\n");
	printf("|           4.��ѧ�������              |\n");
	printf("|              5.�˳�����                 |\n");
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
 stu  s[N];//ѧ������
 stu s1[N]; //�����������ʱ����
 FILE* fp;

 void hang()//ȡ����
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
	 printf("Ҫ׷�Ӷ���λѧ���ĳɼ���");
	 scanf("%d", &j);//jΪ�������������10
	 fp = fopen("C:\\Users\\Ludovico\\Desktop\\score.txt", "a+");
	 for (i = 1; i <= j; i++)
	 {
		 printf("������������ѧ�ţ����ĳɼ�����ѧ�ɼ���Ӣ��ɼ��������ɼ��Լ�4��רҵ�γɼ���\n");
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
	 printf("����\tѧ��\t����\t\t��ѧ\t\tӢ��\t\t����\t\tרҵ��1\t\tרҵ��2\t\tרҵ��3\t\tרҵ��4\t\t�ܷ�\t\tרҵ���ܷ�\t ƽ����\n");
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
	 stu t;//�������ʱ����
	 show();
	 system("cls");
	 menu();
	 printf("�����������\n");
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
		 printf("��%d��:\t%s\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n", i + 1, s1[i].name, s1[i].id, s1[i].id, s1[i].ch, s1[i].ma, s1[i].en, s1[i].sp, s1[i].s1, s1[i].s2, s1[i].s3, s1[i].s4, s1[i].all, s1[i].all1, s1[i].ave);
	 }
 }
 void jxj()
 {
	 int i,j;
	 sort();
	 system("cls");
	 menu();
	 printf("\t����ѧ���������\n");
	 printf("\t�׵Ƚ�ѧ��%s %s\n\t�ҵȽ�ѧ��%s %s %s\n\t���Ƚ�ѧ��%s %s %s %s %s\n", s1[0].name, s1[1].name, s1[2].name, s1[3].name, s1[4].name, s1[5].name, s1[6].name, s1[7].name, s1[8].name, s1[9].name);
 }
 void over()
 {
	 printf("\n\t����������˳�\n");
	 exit(0);
 }
int main()
{
	int a;
	do
	{	
		menu();
		printf("��ѡ��˵�ѡ�");
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
			default:printf("����ˣ����ǻ�û�иù���Ŷ��������ѡ��\n");
			}		
			//printf("����������ص��˵�\n");
			system("pause");
			system("cls");
		}

	} while (a >= 1 || a <= 4);
	return 0;
}
