#include "ls/io/Factory.h"

using namespace std;

namespace ls
{
    namespace io
    {
	    Factory factory;
      InputStream *Factory::makeInputStream(Reader *reader, Buffer *buffer)
      {
          return new InputStream(reader, buffer);
      }

      OutputStream *Factory::makeOutputStream(Writer *writer, Buffer *buffer)
      {
          return new OutputStream(writer, buffer);
      }
    }
}
