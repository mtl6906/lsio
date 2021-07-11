#ifndef LS_IO_INPUTSTREAM_H
#define LS_IO_INPUTSTREAM_H

#include "ls/Buffer.h"
#include "ls/io/Reader.h"
#include "memory"

/*

	使用InputStream进行数据读取时, 确保目标协议能够在

	一页之内找到, 如果找不到则视为失败

	如file::InputStream, 通常一页的大小默认是整个文件的大小,

	net::InputStream, 一页的大小则可以设置为协议头的最大长度,

	假设一个满页内没有找到协议头, 那么说明数据有误, 抛出一个格式异常

*/

namespace ls
{
	namespace io
	{
		class InputStream
		{
			public:
				InputStream(Reader *reader, Buffer *buffer);
			/*

				read方法从目标源中读取一个满页, 当源中数据不足以

				生成一个满页是, 会生成一个不满的页

			*/
				void reset(Reader *reader);
				void read();
				void tryRead();
				std::string splitOf(const char *endMark, int len);
				std::string split(const std::string &endMark, bool with = false);
				std::string split();
				std::string split(int n);
				bool full();
			protected:
				Reader *reader;
				std::unique_ptr<Buffer> buffer;
		};
	}
}

#endif
