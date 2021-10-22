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

		void _read(InputStream &in, int mode)
		{
			if(mode & LS_IO_READ)
				in.read();
			else
				in.tryRead();
		}

		void _write(OutputStream &out, int mode)
		{
			if(mode & LS_IO_WRITE)
				out.write();
			else
				out.tryWrite();
			out.getBuffer() -> clear();
		}

		void API::move(Reader *reader, Writer *writer, Buffer *buffer, int mode)
		{
			io::InputStream in(reader, buffer);
			io::OutputStream out(writer, buffer);
			if(buffer -> size() > 0)
			{
				_write(out, mode);
			}
			for(;;)
			{
				_read(in, mode);
				_write(out, mode);
			}
		}
	}
}
