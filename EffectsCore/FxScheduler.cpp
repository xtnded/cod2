public:
static void *__cdecl ScheduledEffect::operator new(unsigned int)
{
  UNIMPLEMENTED();
}

public:
static void __cdecl ScheduledEffect::operator delete(void *)
{
  UNIMPLEMENTED();
}

public:
__cdecl EffectPrimitive::EffectPrimitive(void)
{
  UNIMPLEMENTED();
}

public:
__cdecl EffectPrimitive::~EffectPrimitive(void)
{
  UNIMPLEMENTED();
}

public:
__cdecl FxMemMgr<struct ScheduledEffect>::FxMemMgr<struct ScheduledEffect>(void)
{
  UNIMPLEMENTED();
}

public:
void *__cdecl FxMemMgr<struct ScheduledEffect>::Alloc(unsigned int)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxMemMgr<struct ScheduledEffect>::Free(void *)
{
  UNIMPLEMENTED();
}

private:
void __cdecl FxMemMgr<struct ScheduledEffect>::MakeFirstBlock(
    struct FxMemBlock *)
{
  UNIMPLEMENTED();
}

public:
float __cdecl FxScheduler::GetEffectLength(struct EffectTemplate *fx)
{
  UNIMPLEMENTED();
}

public:
union TMediaElement __cdecl MediaHandles::GetHandle() const
{
  UNIMPLEMENTED();
}

public:
struct EffectTemplate *__cdecl MediaHandles::GetEffect() const
{
  UNIMPLEMENTED();
}

public:
void __cdecl MediaHandles::operator=(class MediaHandles const &)
{
  UNIMPLEMENTED();
}

public:
float __cdecl FxScheduler::GetDecalSize(
    class PrimitiveTemplate const *primTemp) const
{
  UNIMPLEMENTED();
}

public:
float __cdecl FxScheduler::GetDecalAlpha(
    class PrimitiveTemplate const *primTemp) const
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::Clean(bool bRemoveTemplates,
                                struct EffectTemplate *fxToPreserve)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::GetDecalColor(class PrimitiveTemplate const *primTemp,
                                        float *const rgba) const
{
  UNIMPLEMENTED();
}

struct EffectTemplate *__cdecl FX_TryRegisterEffect(char const *name)
{
  UNIMPLEMENTED();
}

public: void __cdecl FxScheduler::CreateDecalEffect(class PrimitiveTemplate const * primTemp, float * const org, float  ax)[3])
{
  UNIMPLEMENTED();
}

struct EffectTemplate *__cdecl FX_RegisterEffect(char const *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl ScheduledEffect::Archive(class FxArchive &arch)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::Archive(class FxArchive &arch)
{
  UNIMPLEMENTED();
}

bool __cdecl FX_GetBoltingFrame(class PrimitiveTemplate const *primTemp,
                                struct FxBoltInfo const *bolt,
                                class FxBoltFramePtr *boltFrame)
{
  FxBoltFrame *mFramePtr; // eax
  FxBoltFrame *v5;        // [esp+1Ch] [ebp-Ch] BYREF

  if ((a1->mAttributeFlags & 2) == 0 || !a2 ||
      (a2->dobjHandle & 0x80000000) != 0)
    return 1;
  FxBoltFrame::Acquire((FxBoltFrame *)&v5, a2);
  mFramePtr = (FxBoltFrame *)a3->mFramePtr;
    if (a3->mFramePtr != v5) {
        if (mFramePtr) {
          FxBoltFrame::Release((FxBoltFrame *)a3->mFramePtr);
          a3->mFramePtr = 0;
        }
      mFramePtr = v5;
        if (v5) {
          ++v5->mRefCount;
          a3->mFramePtr = mFramePtr;
          mFramePtr = v5;
        }
    }
  if (mFramePtr)
    FxBoltFrame::Release(mFramePtr);
  return a3->mFramePtr &&
         FxBoltFrame::GetOrientation((FxBoltFrame *)a3->mFramePtr);
}

public: void __cdecl FxScheduler::CreateEffect(struct EffectTemplate const *, class PrimitiveTemplate const *, struct FxBoltInfo const *, float const * const, float const )[3],int,int)
{
  UNIMPLEMENTED();
}

public: void __cdecl FxScheduler::PlayEffect(struct EffectTemplate const * fx fx,  float const * const origin origin,  float const  forward)[3],struct FxBoltInfo const *)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::PlayEffect(struct EffectTemplate const *,
                                     float const *const, float const *const,
                                     float const *const)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::PlayEffect(struct EffectTemplate const *,
                                     float const *const, float const *const)
{
  UNIMPLEMENTED();
}

public:
void __cdecl FxScheduler::PlayEffect(struct EffectTemplate const *,
                                     float const *const)
{
  UNIMPLEMENTED();
}

private:
static class FxMemMgr<struct ScheduledEffect> ScheduledEffect::gmMemMgr;
class FxScheduler **fxSchedulers;
int marker_FxScheduler;

bool __cdecl FxInSpawnRange(class PrimitiveTemplate const *, float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl FX_RotateAroundForward(class PrimitiveTemplate const *,
                                    float (*const)[3], float const (*const)[3])
{
  UNIMPLEMENTED();
}

void __cdecl ReportPlayEffectError(void)
{
  UNIMPLEMENTED();
}

void __cdecl FX_AddEffect(struct EffectPrimitive *, float (*const)[3],
                          float const *const, int, int)
{
  UNIMPLEMENTED();
}

FxScheduler::FxScheduler()
{
  UNIMPLEMENTED();
}

FX_InitTemplates()
{
  UNIMPLEMENTED();
}
