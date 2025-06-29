public:
float __cdecl FxRange::GetValPct(float) const
{
  UNIMPLEMENTED();
}

public:
float __cdecl FxRange::GetVal() const
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxRange::SetRange(float min, float max)
{
  UNIMPLEMENTED();
}

enum EMediaTypes __cdecl FX_GetPrimMediaType(enum PrimType)
{
  UNIMPLEMENTED();
}

struct Material *__cdecl FX_RegisterMaterial(char const *material)
{
  return Material_RegisterHandle(a1, 3, 6);
}

struct XModel *__cdecl FX_ModelRegister(char const *name)
{
  UNIMPLEMENTED();
}

void __cdecl FX_Print(char const *msg, ...)
{
  char __str[1024]; // [esp+1Ch] [ebp-40Ch] BYREF
  va_list v2;       // [esp+41Ch] [ebp-Ch]
  va_list va;       // [esp+434h] [ebp+Ch] BYREF

  va_start(va, __format);
  va_copy(v2, va);
  vsnprintf(__str, 0x400u, __format, va);
  Com_Printf(__str);
}

bool g_rendererExists;
int marker_FxTemplate;

PrimitiveTemplate::Shutdown()
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseGroupFlags(char const *val, int *groupFlags)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::Init()
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseChannelCurve(GPValue *pairs, FxChannelId channel)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseImpactFxStrings(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseDeathFxStrings(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseEmitterFxStrings(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParsePlayFxStrings(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseChannelRgbCurve(GPValue *pairs, FxChannelId channel)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::CreateBackCompatibleRotationDeltaCurve(float initialValue,
                                                          float keyScale,
                                                          float lifetime,
                                                          int channelId,
                                                          float graphScale)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseMaterials(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseFlags(char const *line, FxFlagEntry const *flagEntries,
                              int flagEntryCount)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseModels(GPValue *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseRotationDelta(char const *val)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseChannel(
    BackCompatibleParameters *backCompatibleParameters, GPGroup *grp,
    FxChannelId channelId)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseVelocity(char const *val)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParseAcceleration(char const *val)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParsePrimitiveInternal(
    BackCompatibleParameters *backCompatibleParameters, GPGroup *grp)
{
  UNIMPLEMENTED();
}

PrimitiveTemplate::ParsePrimitive(GPGroup *grp)
{
  UNIMPLEMENTED();
}
