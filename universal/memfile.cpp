void __cdecl MemFile_Shutdown(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

char const *__cdecl MemFile_ReadCString(struct MemoryFile *memFile)
{
  int32_t bytesUsed; // ecx
  int32_t v2;        // eax
  _BYTE *buffer;     // edx

    if (!a1->memoryOverflow) {
      bytesUsed = a1->bytesUsed;
      v2 = bytesUsed;
      buffer = a1->buffer;
        do {
            if (!buffer[v2]) {
              a1->bytesUsed = v2 + 1;
              return (const gentity_s *)&buffer[bytesUsed];
            }
          a1->bytesUsed = ++v2;
        }
      while (a1->bufferSize != v2);
      if (a1->errorOnOverflow)
        Com_Error(1,
                  "End of memory file while reading string (%i bytes read)\n",
                  v2 - bytesUsed);
      a1->memoryOverflow = 1;
    }
  return &inData;
}

void __cdecl MemFile_ReadData(struct MemoryFile *memFile, int bytes, void *data)
{
  int32_t bytesUsed; // ecx
  void *result;      // eax

    if (__n && !a1->memoryOverflow) {
      bytesUsed = a1->bytesUsed;
      result = (void *)(__n + bytesUsed);
        if ((signed __int32)(__n + bytesUsed) <= (signed int)a1->bufferSize) {
          result = memcpy(__dst, (char *)a1->buffer + bytesUsed, __n);
          a1->bytesUsed += __n;
        }
        else if (a1->errorOnOverflow) {
          result = (void *)Com_Error(1,
                                     "Couldn't read %i bytes from %i-byte "
                                     "buffer (only %i bytes left)\n",
                                     __n);
          a1->memoryOverflow = 1;
        }
        else {
          a1->memoryOverflow = 1;
        }
    }
  return result;
}

void __cdecl MemFile_SkipData(struct MemoryFile *, int)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_WriteData(struct MemoryFile *memFile, int bytes,
                               void const *data)
{
  UNIMPLEMENTED();
}

bool __cdecl MemFile_IsReading(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_InitForReading(struct MemoryFile *memFile, int size,
                                    void *buffer)
{
  MemoryFile *result; // eax

  result = a1;
  a1->buffer = a3;
  a1->bufferSize = a2;
  a1->bytesUsed = 0;
  a1->errorOnOverflow = 1;
  a1->memoryOverflow = 0;
  a1->archiveProc = (int32_t)MemFile_ReadData;
  return result;
}

void __cdecl MemFile_WriteCString(struct MemoryFile *memFile,
                                  char const *string)
{
  UNIMPLEMENTED();
}

bool __cdecl MemFile_IsWriting(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_InitForWriting(struct MemoryFile *memFile, int size,
                                    void *buffer, bool errorOnOverflow)
{
  int result; // eax

  a1->buffer = a3;
  a1->bufferSize = a2;
  a1->bytesUsed = 0;
  result = a4;
  *(_WORD *)&a1->errorOnOverflow = a4;
  a1->archiveProc = (int32_t)MemFile_WriteDataForArchive;
  return result;
}

void __cdecl MemFile_CommonInit(struct MemoryFile *, int, void *, bool)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_WriteDataForArchive(struct MemoryFile *, int, void *)
{
  UNIMPLEMENTED();
}
