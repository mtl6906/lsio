#ifndef LS_IO_API_H
#define LS_IO_API_H

#include "ls/io/Writer.h"
#include "ls/io/Reader.h"
#include "ls/Buffer.h"

#define LS_IO_READ 0x1
#define LS_IO_WRITE 0x2

namespace ls
{
	namespace io
	{
		class API
		{
			public:
				void move(Reader *reader, Writer *writer, Buffer *buffer = new Buffer(), int mode = LS_IO_READ | LS_IO_WRITE);
		};	
		extern API api;
	}
}

#endif
