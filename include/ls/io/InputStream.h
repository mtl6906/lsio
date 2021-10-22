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
				void read();
				void tryRead();
				std::string splitOf(const char *endMark, int len);
				std::string split(const std::string &endMark, bool with = false);
				std::string split();
				std::string split(int n);
				Buffer *getBuffer();
				bool full();
			protected:
				Reader *reader;
				Buffer *buffer;
		};
	}
}

#endif
