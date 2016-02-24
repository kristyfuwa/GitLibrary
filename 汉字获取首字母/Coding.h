#pragma once

//�ͷ����� gm958spanda@163.com
//����������⣬��ӭָ��

//utf-8��������C++���룬��������C++�ı�׼��
//USING_STL_STRINGָʾ�Ƿ�ʹ��C++��string�ַ�����

//��utf8�ֽ�������Ϊ���ַ���wchar_t��ʱ���������ȷ��������sizeof(wchar_t)
//������˵����wchar_t�Ƿ����㹻�Ŀռ����� UNICODE��

#define USING_STL_STRING 1

#if USING_STL_STRING
#include <string>
#endif

namespace Text
{
	template<typename T>
	struct Buffer
	{
		typedef T  ElemType;
		Buffer() : Size(0),Elem(0){}
		Buffer(unsigned long size)
		{
			this->Size=size;
			this->Elem=new T[size];
		}
		~Buffer(){delete [] this->Elem;}
		T * Elem;
		unsigned long Size;
	};

	typedef Buffer<unsigned char>     ByteArray;  //�ֽ�����
	typedef Buffer<wchar_t>			  WCharArray;  //���ַ�����

	class Utf8Coding
	{
	public:
		//��ȡ����Ϊ���ַ�����ĳ��ȣ����ַ�����
		static bool getCount(const unsigned char * bytes ,unsigned long bytes_len , unsigned long &count);
		//��ȡ����Ϊ���ֽں��ĳ��ȣ��ֽ�����
		static bool getCount(const wchar_t * str,unsigned long strlen, unsigned long &count);
		//����Ϊ���ֽ�
		static bool getBytes(const wchar_t * str,unsigned long strlen,ByteArray & output);
		//����Ϊ���ַ���
		//forceDecode��Ĭ��false�����Ϊtrue������ζ�Ż�ѷ�utf8���ֽ�����Ϊ���ַ�
		//forceDecodeΪtrueʱ���ú��������ܻή��
		static bool getString(const unsigned char * bytes ,unsigned long bytes_len ,WCharArray & output,bool forceDecode=false);

#if USING_STL_STRING
		inline static bool getCount(const std::string & bytes , unsigned long &count)
		{
			return getCount( (const unsigned char *)bytes.data(), (unsigned long) bytes.size(),count);
		}
		inline static bool getCount(const std::wstring &str, unsigned long &count)
		{
			return getCount( (const wchar_t *) str.data() ,(unsigned long) str.size() ,count);
		}


		static bool getBytes(const wchar_t * str,unsigned long strlen,std::string & output);
		inline static bool getBytes(const std::wstring & str, std::string & output)
		{
			return getBytes( (const wchar_t *) str.data(),(unsigned long) str.size(),output);
		}

		static bool getString(const unsigned char * bytes ,unsigned long bytes_len ,std::wstring & output,bool forceDecode=false);
		inline static bool getString(const std::string & bytes,std::wstring & output,bool forceDecode=false)
		{
			return getString((const unsigned char *)bytes.data(),(unsigned long)bytes.size(),output,forceDecode);
		}
#endif
	};
};