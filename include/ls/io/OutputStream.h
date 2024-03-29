#ifndef LS_IO_OUTPUTSTREAM_H
#define LS_IO_OUTPUTSTREAM_H

#include "ls/Buffer.h"
#include "ls/io/Writer.h"
#include "memory"

namespace ls
{
	namespace io
	{
		class OutputStream
		{
			public:
				OutputStream(Writer *writer, Buffer *buffer);
				void reset(Writer *writer);
				void reset(Buffer *buffer);
				int write();
				int tryWrite();
				int append(const std::string &text);
				int append(const char *data, int len);
				Buffer *getBuffer();
			protected:
				Writer *writer;
				Buffer *buffer;
		};
	}
}

#endif
