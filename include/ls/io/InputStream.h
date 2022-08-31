#ifndef LS_IO_INPUTSTREAM_H
#define LS_IO_INPUTSTREAM_H

#include "ls/Buffer.h"
#include "ls/io/Reader.h"
#include "memory"

namespace ls
{
	namespace io
	{
		class InputStream
		{
			public:
				InputStream(Reader *reader, Buffer *buffer);
				void reset(Reader *reader);
				void reset(Buffer *buffer);
				int read();
				int tryRead();
				std::string splitOf(int &ec, const char *endMark, int len);
				std::string split(int &ec, const std::string &endMark, bool with = false);
				std::string split();
				std::string split(int &ec, int n);
				Buffer *getBuffer();
				bool full();
			protected:
				Reader *reader;
				Buffer *buffer;
		};
	}
}

#endif
