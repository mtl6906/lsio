#ifndef LS_IO_FACTORY_H
#define LS_IO_FACTORY_H

#include "ls/io/InputStream.h"
#include "ls/io/OutputStream.h"

namespace ls
{
	namespace io
	{
		class Factory
		{
			public:
				InputStream *makeInputStream(Reader *reader = nullptr, Buffer *buffer = new Buffer());
				OutputStream *makeOutputStream(Writer *writer = nullptr, Buffer *buffer = new Buffer());
		};
		extern Factory factory;
	}
}

#endif
