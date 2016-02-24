// control1.cpp : 定义控制台应用程序的入口点�?
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	FILE* file;
	file = fopen("pinyin.txt", "rb");
	if (file == NULL)
	{
		printf("Open file error!\n");
		return -1;
	}
	fseek(file, 0, SEEK_END);
	int file_size;
	file_size = ftell(file);
	//printf("%d", file_size);
	char *tmp;
	fseek(file, 0, SEEK_SET);
	tmp = (char *)malloc(file_size * sizeof(char)+1);
	memset(tmp, 0, file_size * sizeof(char)+1);
	fread(tmp, file_size, sizeof(char), file);
	fclose(file);
	//printf("%s",tmp);
	printf("------------------------------------------------\n");


	while (1)
	{
		char str[8] = {};
		scanf("%s",str);
		char* dest = strstr(tmp, str);
		if (dest == NULL)
		{
			printf("Not find!\n");
			return -1;
		}

		printf("%c\n", *(dest + strlen(str) + 1));
	}
	


	getchar();
	return 0;
}

