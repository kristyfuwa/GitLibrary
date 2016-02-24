#pragma once

//缤纷冷泪 gm958spanda@163.com
//如果发现问题，欢迎指正

//utf-8编码解码的C++代码，仅依赖于C++的标准库
//USING_STL_STRING指示是否使用C++的string字符串类

//将utf8字节流解码为宽字符（wchar_t）时，结果的正确性依赖于sizeof(wchar_t)
//具体来说就是wchar_t是否有足够的空间容纳 UNICODE码

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

	typedef Buffer<unsigned char>     ByteArray;  //字节数组
	typedef Buffer<wchar_t>			  WCharArray;  //宽字符数组

	class Utf8Coding
	{
	public:
		//获取编码为宽字符串后的长度（宽字符数）
		static bool getCount(const unsigned char * bytes ,unsigned long bytes_len , unsigned long &count);
		//获取编码为多字节后多的长度（字节数）
		static bool getCount(const wchar_t * str,unsigned long strlen, unsigned long &count);
		//编码为多字节
		static bool getBytes(const wchar_t * str,unsigned long strlen,ByteArray & output);
		//编码为宽字符串
		//forceDecode，默认false；如果为true，则意味着会把非utf8的字节提升为宽字符
		//forceDecode为true时，该函数的性能会降低
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