#include "qcommon.h"

size_t FS_FileRead(void *buffer, size_t size, size_t count, FILE *stream)
{
  return fread(buffer, size, count, stream);
}

size_t FS_FileWrite(const void *buffer, size_t size, size_t count, FILE *stream)
{
  return fwrite(buffer, size, count, stream);
}

FILE *FS_FileOpen(const char *filename, const char *mode)
{
  return fopen(filename, mode);
}

int FS_FileClose(FILE *stream)
{
  return fclose(stream);
}

int FS_FileSeek(FILE *stream, long offset, int origin)
{
  return fseek(stream, offset, origin);
}