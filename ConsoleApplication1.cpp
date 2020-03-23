#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int main()
{
	char* s = (char*)malloc(256 * sizeof(char));
	int b = 0, c = 0, d = 0, e = 0;
	int code = 0, blank = 0, exp = 0, num = 0, word = 0;
	char a;
	char t;
	FILE* stream;
	errno_t err;
	if (err = fopen_s(&stream, "D:\\test.txt", "r") != 0)
	{
		printf("error\n");
	}
	else
	{
		printf("请输入功能字符:");
		scanf_s("%c", &t, 1);
		switch (t)
		{
		case 'c':
			while ((a = fgetc(stream) )!= EOF)
			{
				if ((a != ' ') && (a != '\n') && (a != '\t'))
				{
					num++;
				}
			}
			fclose(stream);
			printf("字符数：%d\n", num);
			break;
		case'w':
			while ((a = fgetc(stream)) != EOF)
			{
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
				{
					if (word == 0)
					{
						num ++;
						word = 1;
					}
				}
				else
				{
					word = 0;
				}
			}
			fclose(stream);
			printf("单词数：%d\n", num);
			break;
		case'l':

			while (fgets(s, 256, stream) != NULL)
			{
				num++;
			}
			free(s);
			fclose(stream);
			printf("行数：%d\n", num);
			break;
		case'a':
			while (fgets(s, 256, stream) != NULL)
			{
				for (int i = 0; *(s + i) != '\0'; i++)
				{
					if ((*(s + i) == '/' && *(s + i + 1) == '/') && b == 0 && c == 0)//判定是否为注释行
					{
						exp++, b = 1;//若是，则加1，并且该行若有其他“//”也不做加数
					}
					else
					{
						c = 1;//判定开头是否为“//”
					}
					if (((*(s + i) <= 'z' && *(s + i) >= 'a') || (*(s + i) <= 'Z' && *(s + i) >= 'A') )&& b == 0  && d == 0)
					{
						code++, d = 1;
					}
				}
				b = 0, c = 0, d = 0;
				num++;
			}
			free(s);
			fclose(stream);
			blank = num - code - exp;
			printf("空白行：%d\n注释行:%d\n代码行:%d", blank, exp, code);
			break;
		default:printf("无效输入"); break;
			return 0;
		}
	}
}