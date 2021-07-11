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
				void write();
				void tryWrite();
				void append(const std::string &text);
				void append(const char *data, int len);
				Buffer *getBuffer();
			protected:
				Writer *writer;
				std::unique_ptr<Buffer> buffer;
		};
	}
}

#endif
