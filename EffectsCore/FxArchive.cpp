void __cdecl MemFile_WriteByte(struct MemoryFile *, unsigned char)
{
  UNIMPLEMENTED();
}

unsigned char __cdecl MemFile_ReadByte(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

public:
unsigned char __cdecl FxArchive::ReadByte(void)
{
  UNIMPLEMENTED();
}

public:
float __cdecl FxArchive::ReadFloat(void)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteByte(unsigned char)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteFloat(float)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::BeginWriting(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::BeginReading(struct MemoryFile *memFile)
{
  UNIMPLEMENTED();
}

public:
__cdecl FxArchive::FxArchive()
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteData(void const *p, int byteCount)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ReadData(void *p, int byteCount)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ArchiveData(void *, int)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteChannelInstance(struct FxChannelInstance *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteModel(struct XModel *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteMaterial(struct Material *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::WriteEffect(struct EffectTemplate const *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ReadChannelInstance(struct FxChannelInstance *)
{
  UNIMPLEMENTED();
}

public:
struct XModel *__cdecl FxArchive::ReadModel(void)
{
  UNIMPLEMENTED();
}

public:
struct Material *__cdecl FxArchive::ReadMaterial(void)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ArchiveChannelInstance(
    struct FxChannelInstance *channelInstance)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ArchiveModel(struct XModel **model)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ArchiveMaterial(struct Material **ph)
{
  UNIMPLEMENTED();
}

public:
struct EffectTemplate *__cdecl FxArchive::ReadEffect(void)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxArchive::ArchiveEffect(struct EffectTemplate const **fx)
{
  UNIMPLEMENTED();
}

int marker_FxArchive;

FxArchive::ArchiveFxBoltInfo(FxBoltInfo *bolt)
{
  UNIMPLEMENTED();
}

FxArchive::ArchiveFxGfxEntity(FxGfxEntity *entity)
{
  UNIMPLEMENTED();
}
