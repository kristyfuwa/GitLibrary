#include "Coding.h"

using namespace Text;

#pragma warning ( disable: 4333)

namespace _utf8_
{
	void encode(const wchar_t * str,unsigned long strlen ,unsigned char * buffer )
	{
		while( strlen > 0 )
		{
			if( *str < 0x80 ) //0xxxxxxx
			{
				*buffer =(unsigned char)*str;
				buffer++;
			}
			else if( *str<0x0800) //双字节模板 110xxxxx 10xxxxxx
			{
				*buffer = ( *str >> 6   | 0xc0 );
				buffer[1] = ( *str & 0x3f | 0x80 );
				buffer+=2;
			}
			else if( *str < 0x010000 ) //三字节模板 1110xxxx 10xxxxxx 10xxxxxx
			{
				*buffer = ( *str >> 12         | 0xe0);
				buffer[1] = ( *str >> 6  & 0x3f  | 0x80);
				buffer[2] = ( *str & 0x3f        | 0x80);
				buffer+=3;
			}
			else if ( *str < 0x200000 ) //四字节模板 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				*buffer = (*str >> 18        | 0xf0);
				buffer[1] = (*str >> 12 & 0x3f | 0x80);
				buffer[2] = (*str >> 6  & 0x3f | 0x80);
				buffer[3] = (*str & 0x3f       | 0x80);
				buffer+=4;
			}
			else if ( *str < 0x04000000) //五字节模板 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				*buffer = ( *str>>24  | 0xf8 );
				buffer[1] = ( *str>>18 & 0x3f | 0x80 );
				buffer[2] = ( *str>>12 & 0x3f | 0x80 );
				buffer[3] = ( *str>>6  & 0x3f | 0x80 );
				buffer[4] = ( *str &0x3f      | 0x80 );
				buffer+=5;
			}
			else                       //六字节模板 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 
			{
				*buffer = ( *str>>30  | 0xfc );
				buffer[1] = ( *str>>24 & 0x3f | 0x80 );
				buffer[2] = ( *str>>18 & 0x3f | 0x80 );
				buffer[3] = ( *str>>12 & 0x3f | 0x80 );
				buffer[4] = ( *str>>6  & 0x3f | 0x80 );
				buffer[5] = ( *str &0x3f      | 0x80 );
				buffer+=6;
			}

			strlen -- ;
			str++;
		}
	}

	bool count_force(const unsigned char * bytes ,unsigned long bytes_len,unsigned long &count)
	{
		if( bytes == 0 )
		{
			return false;
		}
		unsigned long tmpcount=0;
		while( bytes_len > 0 )
		{
			if( *bytes < 0x80 ) //0xxxxxxx
			{
				bytes++;
				bytes_len --;
			}
			else if (  ((*bytes) >> 5) ==6 ) //110xxxxx 10xxxxxx
			{
				if(bytes_len >1 && bytes[1]>>6 == 2 )
				{				
					bytes+=2;
					bytes_len -=2;
				}
			}
			else if ( ((*bytes) >> 4) == 14 ) //1110xxxx 10xxxxxx 10xxxxxx
			{
				if( bytes_len >2 &&  bytes[1]>>6==2 && bytes[2]>>6==2 )
				{
					bytes+=3;
					bytes_len -=3;
				}
			}
			else if ( ((*bytes) >> 3) == 30 ) //11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if(  bytes_len >3 && bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 )
				{					
					bytes+=4;
					bytes_len -=4;
				}
			}
			else if ( ((*bytes) >> 2) == 62 ) //111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if( bytes_len >4 &&  bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 && bytes[4]>>6==2 )
				{				
					bytes+=5;
					bytes_len -=5;
				}
			}
			else if ( ((*bytes) >> 1) == 126 ) //1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if( bytes_len >5 &&  bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 && bytes[4]>>6==2 && bytes[5]>>6==2 )
				{				
					bytes+=6;
					bytes_len -=6;
				}
			}
			else  //非正常的字节
			{
				bytes++;
				bytes_len --;	
			}
			tmpcount++;
		}
		count=tmpcount;
		return true;
	}
	bool decode(const unsigned char * bytes ,unsigned long bytes_len ,wchar_t *buffer,bool decode_force=false)
	{
		while( bytes_len > 0 )
		{
			if( *bytes < 0x80 ) //0xxxxxxx
			{
				*buffer = *bytes;

				bytes++;
				bytes_len --;
			}
			else if ( ((*bytes) >> 5) ==6 ) //110xxxxx 10xxxxxx
			{
				if( bytes_len >1 && bytes[1]>>6 == 2 )
				{
					*buffer = ((*bytes  & 0x1f ) << 6) | (bytes[1] & 0x3f);

					bytes+=2;
					bytes_len -=2;
				}
			}
			else if ( ((*bytes) >> 4) == 14 ) //1110xxxx 10xxxxxx 10xxxxxx
			{
				if(bytes_len >2 &&   bytes[1]>>6==2 && bytes[2]>>6==2 )
				{
					*buffer = ((*bytes  & 0x0f ) << 12 ) |
						((bytes[1] & 0x3f) << 6 ) |(bytes[2] & 0x3f);

					bytes+=3;
					bytes_len -=3;
				}
			}
			else if ( ((*bytes) >> 3) == 30 ) //11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if(  bytes_len >3 && bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 )
				{
					*buffer = ((*bytes  & 0x07 ) << 18 ) | 
						((bytes[1] & 0x3f) << 12 ) | ((bytes[2] & 0x3f) << 6 ) |(bytes[3] & 0x3f);

					bytes+=4;
					bytes_len -=4;
				}
			}
			else if (  ((*bytes) >> 2) == 62 ) //111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if( bytes_len >4 && bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 && bytes[4]>>6==2 )
				{
					*buffer = ((*bytes  & 0x03 ) << 24 ) | 
						((bytes[1] & 0x3f) << 18 ) | ((bytes[2] & 0x3f) << 12 ) | ((bytes[3] & 0x3f) << 6 ) |(bytes[4] & 0x3f);

					bytes+=5;
					bytes_len -=5;
				}
			}
			else if (   ((*bytes) >> 1) == 126 ) //1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
			{
				if( bytes_len >5 &&bytes[1]>>6==2 && bytes[2]>>6==2 && bytes[3]>>6==2 && bytes[4]>>6==2 && bytes[5]>>6==2 )
				{
					*buffer = ((*bytes  & 0x03 ) << 30 ) | 
						((bytes[1] & 0x3f) << 24 ) | ((bytes[2] & 0x3f) << 18 ) | ((bytes[3] & 0x3f) << 12 ) |((bytes[3] & 0x3f) << 6 ) |(bytes[5] & 0x3f);

					bytes+=6;
					bytes_len -=6;
				}
			}
			else  //非正常的字节
			{
				if( decode_force ) //强制解码，将该字节直接提升为宽字符
				{
					*buffer = *bytes;

					bytes++;
					bytes_len --;
				}
				else
				{
					return false;
				}
			}
			buffer++;
		}
		return true;
	}
}
//获取编码为多字节后多字节的长度（字节数）
bool Utf8Coding::getCount(const wchar_t * str,unsigned long strlen, unsigned long &count)
{
	if( str == 0 )
	{
		return false;
	}
	count = 0;
	while( strlen > 0)
	{
		if( *str < 0x80 )
		{
			count ++;
		}
		else if( *str<0x0800) 
		{
			count +=2;
		}
		else if( *str < 0x010000 ) 
		{
			count +=3;
		}
		else if ( *str < 0x200000 ) 
		{
			count +=4;
		}
		else if ( *str < 0x04000000) 
		{
			count +=5;
		}
		else 
		{
			count +=6;
		}
		str ++;
		strlen -- ;
	}
	return true;
}

bool Utf8Coding::getCount(const unsigned char * bytes ,unsigned long bytes_len , unsigned long &count)
{
	if( bytes == 0)
	{
		return false;
	}
	unsigned long tmpCount=0;
	while( bytes_len > 0 )
	{
		if( *bytes < 0x80 ) //0xxxxxxx
		{
			bytes++;
			bytes_len --;
		}
		else if (  ((*bytes) >> 5) ==6 ) //110xxxxx 10xxxxxx
		{
			bytes+=2;
			bytes_len -=2;
		}
		else if (  ((*bytes) >> 4) == 14 ) //1110xxxx 10xxxxxx 10xxxxxx
		{
			bytes+=3;
			bytes_len -=3;
		}
		else if (  ((*bytes) >> 3) == 30 ) //11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		{
			bytes+=4;
			bytes_len -=4;
		}
		else if (  ((*bytes) >> 2) == 62 ) //111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		{
			bytes+=5;
			bytes_len -=5;
		}
		else if (  ((*bytes) >> 1) == 126 ) //1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
		{
			bytes+=6;
			bytes_len -=6;
		}
		else  //非正常的字节
		{
			return false;
		}
		tmpCount++;
	}
	count=tmpCount;
	return true;
}

//编码为多字节
bool Utf8Coding::getBytes(const wchar_t * str,unsigned long strlen,ByteArray & output)
{
	unsigned long count;
	if ( ! getCount(str,strlen,count) )
	{
		return false;
	}

	unsigned char *buffer = new unsigned char[count];
	if( buffer == 0 )
	{
		return false;
	}

	_utf8_::encode(str,strlen,buffer);

	if( output.Size != 0 )
	{
		delete [] output.Elem;
	}
	output.Size = count;
	output.Elem = buffer;

	return true;
}

bool Utf8Coding::getString(const unsigned char * bytes ,unsigned long bytes_len ,WCharArray & output,bool forceDecode)
{
	unsigned long count;
	if(! forceDecode)
	{
		if( ! getCount(bytes,bytes_len,count) )
		{
			return false;
		}
	}
	else
	{
		if( ! _utf8_::count_force(bytes,bytes_len,count) )
		{
			return false;
		}
	}

	wchar_t *buffer= new wchar_t[count];
	if( buffer ==0)
	{
		return false;
	}

	if ( ! _utf8_::decode(bytes,bytes_len,buffer,forceDecode) )
	{
		delete [] buffer;
		return false;
	}

	if( output.Size !=0 )
	{
		delete [] output.Elem;
	}

	output.Size = count;
	output.Elem = buffer;

	return true;
}

#if USING_STL_STRING
bool Utf8Coding::getBytes(const wchar_t * str,unsigned long strlen,std::string & output)
{
	unsigned long count;
	if ( ! getCount(str,strlen,count) )
	{
		return false;
	}

	output.assign(count,0);
	_utf8_::encode(str,strlen,(unsigned char *) output.data());
	return true;
}
bool Utf8Coding::getString(const unsigned char * bytes ,unsigned long bytes_len ,std::wstring & output,bool forceDecode)
{
	unsigned long count;
	if(! forceDecode)
	{
		if( ! getCount(bytes,bytes_len,count) )
		{
			return false;
		}
	}
	else
	{
		if( ! _utf8_::count_force(bytes,bytes_len,count) )
		{
			return false;
		}
	}

	output.assign(count,0);

	return _utf8_::decode(bytes,bytes_len,(wchar_t *) output.data(),forceDecode);
}
#endif