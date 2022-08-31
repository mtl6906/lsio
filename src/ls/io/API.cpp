#include "ls/io/API.h"
#include "ls/io/InputStream.h"
#include "ls/io/OutputStream.h"
#include "ls/Exception.h"
#include "ls/DefaultLogger.h"

namespace ls
{
	namespace io
	{
		API api;

		int _read(InputStream &in, int mode)
		{
			if(mode & LS_IO_READ)
				return in.read();
			return in.tryRead();
		}

		int _write(OutputStream &out, int mode)
		{
			int n;
			if(mode & LS_IO_WRITE)
				n = out.write();
			else
				n = out.tryWrite();
			if(n == Exception::LS_OK)
				out.getBuffer() -> clear();
			return n;
		}

		int API::move(Reader *reader, Writer *writer, Buffer *buffer, int mode)
		{
			io::InputStream in(reader, buffer);
			io::OutputStream out(writer, buffer);
			int n = 0;
			if(buffer -> size() > 0)
			{
				if((n = _write(out, mode)) < 0)
					return n;
			}
			for(;;)
			{
				if((n = _read(in, mode)) < 0)
					return n;
				if((n = _write(out, mode)) < 0)
					return n;
			}
			return Exception::LS_OK;
		}
	}
}
