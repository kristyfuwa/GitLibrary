//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//int main()
//{
//	unsigned char temp[2];
//	cin >> temp;
//	while (temp[1])
//	{
//		cout << setw(2) << setfill('0') << temp[0] - 160;
//		cout << setw(2) << setfill('0') << temp[1] - 160 << endl;
//		temp[1] = 0;
//		cin >> temp;
//	}
//	return 0;
//}
//
////#include <windows.h>
////#include  <iostream>
////#include <stdlib.h>
////#include  <string>
////using  namespace  std;
////
////static  char  convert(wchar_t  n);
////static  bool  In(wchar_t  start, wchar_t  end, wchar_t  code);
////void DeCode(DWORD &w, WORD &w1, WORD &w2)
////{
////	w1 = w1 & 0x3FF;
////	w2 = w2 & 0x3FF;
////
////	w = w1 << 10;
////	w = w | w2;
////	w += 0x10000;
////}
////int  main(int  argc, char*  argv[])
////
////{
////	FILE *file = fopen("Unicode.txt", "rb");
////	if (!file)
////	{
////		cout << "文件加载失败" << endl;
////	}
////	char FileData[100] = {0};
////
////	fread(FileData, 100, 1, file);
////
////	string chstring = FileData;
////	char  chr[3];
////
////	//wchar_t  wchr = 0;
////
////	//DWORD dw = 0;
////
////	//char*  buff = new  char[chstring.size()];
////	//
////	//memset(buff,0x00,sizeof(buff));
////
////	for (int i = 0, j = 0; i < 50; ++i)
////
////	{
////		DWORD dw = 0;
////		WORD w1, w2;
////		w1 = chstring[j++];
////		w2 = chstring[j++];         //w2!=0  否则即为BMP之内的码  
////
////		DeCode(dw, w1, w2);
////
////		//memset(chr, 0x00, sizeof(chr));
////
////		//chr[0] = FileData[j++];
////
////		//chr[1] = FileData[j++];
////
////		//chr[2] = '\0';
////
////		////  单个字符的编码  如：'我'  =  0xced2
////
////		//wchr = 0;
////
////		//wchr = (chr[0] & 0xff) << 8;
////
////		//wchr |= (chr[1] & 0xff);
////		
////		cout << "pin  yin  =  [" << convert(dw) << "]" << endl;
////
////	}
////
////	
////
////	return  0;
////
////}
////
////char  convert(wchar_t  n)
////
////{
////
////	if (In(0xB0A1, 0xB0C4, n))  return  'a';
////
////	if (In(0XB0C5, 0XB2C0, n))  return  'b';
////
////	if (In(0xB2C1, 0xB4ED, n))  return  'c';
////
////	if (In(0xB4EE, 0xB6E9, n))  return  'd';
////
////	if (In(0xB6EA, 0xB7A1, n))  return  'e';
////
////	if (In(0xB7A2, 0xB8c0, n))  return  'f';
////
////	if (In(0xB8C1, 0xB9FD, n))  return  'g';
////
////	if (In(0xB9FE, 0xBBF6, n))  return  'h';
////
////	if (In(0xBBF7, 0xBFA5, n))  return  'j';
////
////	if (In(0xBFA6, 0xC0AB, n))  return  'k';
////
////	if (In(0xC0AC, 0xC2E7, n))  return  'l';
////
////	if (In(0xC2E8, 0xC4C2, n))  return  'm';
////
////	if (In(0xC4C3, 0xC5B5, n))  return  'n';
////
////	if (In(0xC5B6, 0xC5BD, n))  return  'o';
////
////	if (In(0xC5BE, 0xC6D9, n))  return  'p';
////
////	if (In(0xC6DA, 0xC8BA, n))  return  'q';
////
////	if (In(0xC8BB, 0xC8F5, n))  return  'r';
////
////	if (In(0xC8F6, 0xCBF0, n))  return  's';
////
////	if (In(0xCBFA, 0xCDD9, n))  return  't';
////
////	if (In(0xCDDA, 0xCEF3, n))  return  'w';
////
////	if (In(0xCEF4, 0xD188, n))  return  'x';
////
////	if (In(0xD1B9, 0xD4D0, n))  return  'y';
////
////	if (In(0xD4D1, 0xD7F9, n))  return  'z';
////
////	return  '\0';
////
////}
////
////bool  In(wchar_t  start, wchar_t  end, wchar_t  code)
////
////{
////
////	if (code >= start  &&  code <= end)
////
////	{
////
////		return  true;
////
////	}
////
////	return  false;
////
////}
////

	//while (1)
	//{
	//	char ch[4] = {0};
	//	scanf("%s", ch);
	//	k_String out1 = ConvertGBKToUtf8(ch);
	//	char* dest = strstr(tmp, out1.c_str());
	//	if (dest == NULL)
	//	{
	//		printf("Not find!\n");
	//		return -1;
	//	}

	//	printf("%c\t", *(dest + strlen(out1.c_str()) + 1));
	//	endtime = timeGetTime();
	//	fps = endtime - begin;
	//	printf("%d\d", fps);
	//	printf("\n");
	//}



	//while (1)
	//{
	//	char str[8] = {};
	//	scanf("%s", str);
	//	char* dest = strstr(tmp, str);
	//	if (dest == NULL)
	//	{
	//		printf("Not find!\n");
	//		return -1;
	//	}

	//	printf("%c\n", *(dest + strlen(str) + 1));
	//}

	//char ch[] = "中";
	//k_String out1 = ConvertGBKToUtf8(ch);
	//
	//UTF8 *ou = (UTF8 *)(out1.c_str());
	//int num = GetUTF8Length(ou);
	//UTF16 *out2 = new UTF16[4];
	//u2w(ou, out2);
	//int a = out2[0];
	//char n=convert(*out2);

	//printf("%c\n", n);
	//FILE *out;
	//long sour[] = { '中'/*0xFEFF4E2D*/ };
	////由两个UTF-16字符，一个是XFFEF,一个是xd808 , 0xdf45
	//long i = 0;
	//long len = 1;
	//out = fopen("out2.txt", "wb");
	//while (i < len)
	//{
	//	if (sour[i]<0xD800 || sour[i]>0xDFFF)
	//	{
	//		printf("%x\n", sour[i], sour[i]);
	//		i = i + 1;
	//	}
	//	if (sour[i]>0xd800 && sour[i] < 0xdbff)
	//	{
	//		sour[i] = sour[i] - 0xD800;
	//		long h = sour[i];
	//		i = i + 1;
	//		if (i > len)
	//		{
	//			printf("not have W2 error!\n");
	//		}
	//		else if (sour[i] > 0xDC00 && sour[i] < 0xdfff)
	//		{
	//			sour[i] = sour[i] - 0xDC00;
	//			long l = sour[i];
	//			i = i + 1;
	//			long unicode = (h << 10) | l + 0x10000;
	//			printf("%x", unicode);
	//		}
	//		else
	//		{
	//			printf("error W2\n");
	//		}
	//	}
	//	else
	//	{
	//		printf("error w1 \n");
	//	}
	//}
	
}
////#include <iostream>
////#include <set>
////using namespace std;
////
////size_t utf8_to_charset(const string &input, set<string> &output)
////{
////	string ch;
////	for (size_t i = 0, len = 0; i != input.length();i+=len)
////	{
////		unsigned char byte = (unsigned)input[i];
////		if (byte >= 0xFC)
////			len = 6;
////		else if (byte >= 0xF8)
////			len = 5;
////		else if (byte >= 0xF0)
////			len = 4;
////		else if (byte >= 0xE0)
////			len = 3;
////		else if (byte >= 0xC0)
////			len = 2;
////		else
////			len = 1;
////		ch = input.substr(i, len);
////		output.insert(ch);
////	}
////	return output.size();
////}
////


//
//#include <stdio.h>
//#include <stdlib.h>
//#include <windows.h>
//#include  <iostream>
//
//#include "k_ScriptPrecompiled.h"
//
//#ifdef _DEBUG
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatBase_d.lib" )
//#else
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatBase.lib" )
//#endif
//
//#ifdef _DEBUG
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatGraphics_d.lib" )
//#else
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatGraphics.lib" )
//#endif
//
//#ifdef _DEBUG
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatCore_d.lib" )
//#else
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatCore.lib" )
//#endif
//
//#ifdef _DEBUG
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatScript_d.lib" )
//#else
//#	pragma comment( lib, "D:\\Technology\\InverseMatrix\\Development\\Library\\Window\\InvMatScript.lib" )
//#endif
//using namespace InverseMatrix;
//
//using  namespace  std;
//
//static  char  convert(wchar_t  n);
//
//static  bool  In(wchar_t  start, wchar_t  end, wchar_t  code);
//
//bool decode(const unsigned char * bytes, unsigned long bytes_len, wchar_t *buffer, bool decode_force = false)
//{
//	while (bytes_len > 0)
//	{
//		if (*bytes < 0x80) //0xxxxxxx
//		{
//			*buffer = *bytes;
//
//			bytes++;
//			bytes_len--;
//		}
//		else if (((*bytes) >> 5) == 6) //110xxxxx 10xxxxxx
//		{
//			if (bytes_len >1 && bytes[1] >> 6 == 2)
//			{
//				*buffer = ((*bytes & 0x1f) << 6) | (bytes[1] & 0x3f);
//
//				bytes += 2;
//				bytes_len -= 2;
//			}
//		}
//		else if (((*bytes) >> 4) == 14) //1110xxxx 10xxxxxx 10xxxxxx
//		{
//			if (bytes_len > 2 && bytes[1] >> 6 == 2 && bytes[2] >> 6 == 2)
//			{
//				*buffer = ((*bytes & 0x0f) << 12) |
//					((bytes[1] & 0x3f) << 6) | (bytes[2] & 0x3f);
//
//				bytes += 3;
//				bytes_len -= 3;
//			}
//
//		}
//		else if (((*bytes) >> 3) == 30) //11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
//		{
//			if (bytes_len > 3 && bytes[1] >> 6 == 2 && bytes[2] >> 6 == 2 && bytes[3] >> 6 == 2)
//			{
//				*buffer = ((*bytes & 0x07) << 18) |
//					((bytes[1] & 0x3f) << 12) | ((bytes[2] & 0x3f) << 6) | (bytes[3] & 0x3f);
//
//				bytes += 4;
//				bytes_len -= 4;
//			}
//		}
//		else if (((*bytes) >> 2) == 62) //111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
//		{
//			if (bytes_len > 4 && bytes[1] >> 6 == 2 && bytes[2] >> 6 == 2 && bytes[3] >> 6 == 2 && bytes[4] >> 6 == 2)
//			{
//				*buffer = ((*bytes & 0x03) << 24) |
//					((bytes[1] & 0x3f) << 18) | ((bytes[2] & 0x3f) << 12) | ((bytes[3] & 0x3f) << 6) | (bytes[4] & 0x3f);
//
//				bytes += 5;
//				bytes_len -= 5;
//			}
//		}
//		else if (((*bytes) >> 1) == 126) //1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
//		{
//			if (bytes_len > 5 && bytes[1] >> 6 == 2 && bytes[2] >> 6 == 2 && bytes[3] >> 6 == 2 && bytes[4] >> 6 == 2 && bytes[5] >> 6 == 2)
//			{
//				*buffer = ((*bytes & 0x03) << 30) |
//					((bytes[1] & 0x3f) << 24) | ((bytes[2] & 0x3f) << 18) | ((bytes[3] & 0x3f) << 12) | ((bytes[3] & 0x3f) << 6) | (bytes[5] & 0x3f);
//
//				bytes += 6;
//				bytes_len -= 6;
//			}
//		}
//		else  //非正常的字节
//		{
//			if (decode_force) //强制解码，将该字节直接提升为宽字符
//			{
//				*buffer = *bytes;
//
//				bytes++;
//				bytes_len--;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		buffer++;
//	}
//	return true;
//}
//
//int main(int argc, char* argv[])
//{
//
//	unsigned char ch[]= "涓崕浜烘皯鍏卞拰鍥藉拰宸村熀鏂潶浼婃柉鍏板叡鍜屽浗";
//
//	wchar_t out[100];
//
//	decode(ch, sizeof(ch), out);
//
//	char  chr[3];
//
//	wchar_t  wchr = 0;
//	char buff = '\0';
//	
//	k_String ds=ConvertUtf8ToGBK("涓崕浜烘皯鍏卞拰鍥藉拰宸村熀鏂潶浼婃柉鍏板叡鍜屽浗");
//
//	printf("%s\n", ds.c_str());
//
//	//string chstring;
//	for (int i = 0, j = 0; i < wcslen(out);++i)
//	{
//		cout << hex<< out[i] << endl;
//
//		//memset(chr, 0x00, sizeof(chr));
//
//		//chr[0] = out[j++];
//
//		//chr[1] = out[j++];
//
//		//chr[2] = '\0';
//
//		////  单个字符的编码  如：'我'  =  0xced2
//
//		//wchr = 0;
//
//		//wchr = (chr[0] & 0xff) << 8;
//
//		//wchr |= (chr[1] & 0xff);
//
//		//buff = convert(out[j++]);
//		//cout << "pin  yin  =  [" << buff << "]" << endl;
//	}
//
//	//cout << chstring << endl;
//	//string  sChinese = "中华人民共和国和巴基斯坦伊斯兰共和国";  //  输入的字符串
//
//	//char  chr[3];
//
//	//wchar_t  wchr = 0;
//
//
//
//	////char*  buff = new  char[sChinese.length() / 2];
//
//	////memset(buff, 0x00, sizeof(char)*sChinese.length() / 2 + 1);
//	//char buff = '\0';
//
//	//for (int i = 0, j = 0; i < (sChinese.length() / 2); ++i)
//
//	//{
//
//	//	memset(chr, 0x00, sizeof(chr));
//
//	//	chr[0] = sChinese[j++];
//
//	//	chr[1] = sChinese[j++];
//
//	//	chr[2] = '\0';
//
//	//	//  单个字符的编码  如：'我'  =  0xced2
//
//	//	wchr = 0;
//
//	//	wchr = (chr[0] & 0xff) << 8;
//
//	//	wchr |= (chr[1] & 0xff);
//
//	//	buff = convert(wchr);
//	//	cout << "pin  yin  =  [" << buff << "]" << endl;
//
//	//}
//	getchar();
//	return  0;
//}
////
//char  convert(wchar_t  n)
//
//{
//
//	if (In(0xB0A1, 0xB0C4, n))  return  'a';
//
//	if (In(0XB0C5, 0XB2C0, n))  return  'b';
//
//	if (In(0xB2C1, 0xB4ED, n))  return  'c';
//
//	if (In(0xB4EE, 0xB6E9, n))  return  'd';
//
//	if (In(0xB6EA, 0xB7A1, n))  return  'e';
//
//	if (In(0xB7A2, 0xB8c0, n))  return  'f';
//
//	if (In(0xB8C1, 0xB9FD, n))  return  'g';
//
//	if (In(0xB9FE, 0xBBF6, n))  return  'h';
//
//	if (In(0xBBF7, 0xBFA5, n))  return  'j';
//
//	if (In(0xBFA6, 0xC0AB, n))  return  'k';
//
//	if (In(0xC0AC, 0xC2E7, n))  return  'l';
//
//	if (In(0xC2E8, 0xC4C2, n))  return  'm';
//
//	if (In(0xC4C3, 0xC5B5, n))  return  'n';
//
//	if (In(0xC5B6, 0xC5BD, n))  return  'o';
//
//	if (In(0xC5BE, 0xC6D9, n))  return  'p';
//
//	if (In(0xC6DA, 0xC8BA, n))  return  'q';
//
//	if (In(0xC8BB, 0xC8F5, n))  return  'r';
//
//	if (In(0xC8F6, 0xCBF0, n))  return  's';
//
//	if (In(0xCBFA, 0xCDD9, n))  return  't';
//
//	if (In(0xCDDA, 0xCEF3, n))  return  'w';
//
//	if (In(0xCEF4, 0xD188, n))  return  'x';
//
//	if (In(0xD1B9, 0xD4D0, n))  return  'y';
//
//	if (In(0xD4D1, 0xD7F9, n))  return  'z';
//
//	return  '\0';
//
//}
//
//bool  In(wchar_t  start, wchar_t  end, wchar_t  code)
//
//{
//
//	if (code >= start  &&  code <= end)
//
//	{
//
//		return  true;
//
//	}
//
//	return  false;
//}