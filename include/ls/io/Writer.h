#ifndef LS_IO_WRITER_H
#define LS_IO_WRITER_H

namespace ls
{
    namespace io
    {
        class Writer
        {
            public:
                virtual int write(void *data, int len) = 0;
                virtual int tryWrite(void *data, int len) = 0;
        };
    }
}

#endif
