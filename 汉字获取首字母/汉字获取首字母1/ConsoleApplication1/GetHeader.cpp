#include <stdio.h>
#include <stdlib.h>

#include "k_ScriptPrecompiled.h"

#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatBase_d.lib" )
#else
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatBase.lib" )
#endif

#ifdef _DEBUG
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatGraphics_d.lib" )
#else
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatGraphics.lib" )
#endif

#ifdef _DEBUG
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatCore_d.lib" )
#else
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatCore.lib" )
#endif

#ifdef _DEBUG
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatScript_d.lib" )
#else
#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatScript.lib" )
#endif
using namespace InverseMatrix;

static  char  convert(wchar_t  n);
static  bool  In(wchar_t  start, wchar_t  end, wchar_t  code);

int main()
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
	printf("---------------ºº×Ö»ñÈ¡Ê××ÖÄ¸----------------\n");
	while (1)
	{
		char ch[4] = "";
		scanf("%s", ch);
		k_String out1 = ConvertGBKToUtf8(ch);
		char* dest = strstr(tmp, out1.c_str());
		if (dest == NULL)
		{
			printf("Not find!\n");
			return -1;
		}
		printf("%c\t", *(dest + strlen(out1.c_str()) + 1));
		printf("\n");
	}
	return 0;
}