struct XAnim_s *__cdecl Scr_GetAnims(int index)
{
  return dword_114E22C[a1];
}

int __cdecl Scr_GetAnimsIndex(struct XAnim_s const *)
{
  UNIMPLEMENTED();
}

void __cdecl SetAnimCheck(int bAnimCheck)
{
  int result; // eax

  result = a1;
  dword_4ED208 = a1;
  return result;
}

struct scr_animtree_t __cdecl Scr_FindAnimTree(char const *filename)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FindAnim(char const *filename, char const *animName,
                          struct scr_anim_s *anim, int user)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_UsingTree(char const *filename, unsigned int sourcePos)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EmitAnimation(char *pos, unsigned int animName,
                               unsigned int sourcePos)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_LoadAnimTreeAtIndex(int, void *(__cdecl *)(int), int)
{
  UNIMPLEMENTED();
}

int marker_scr_animtree;
struct scrAnimPub_t scrAnimPub;

int __cdecl Scr_GetAnimTreeSize(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EmitAnimationInternal(char *, unsigned int, unsigned int,
                                       unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl ConnectScriptToAnim(unsigned int, int, unsigned int, unsigned int,
                                 int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_UsingTreeInternal(char const *, int *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_CreateAnimationTree(unsigned int, unsigned int,
                                    struct XAnim_s *, unsigned int,
                                    char const *, unsigned int, unsigned int,
                                    int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CheckAnimsDefined(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl AnimTreeCompileError(char *)
{
  UNIMPLEMENTED();
}

int __cdecl GetAnimTreeParseProperties(void)
{
  UNIMPLEMENTED();
}

bool __cdecl AnimTreeParseInternal(unsigned int, unsigned int, bool, bool, bool)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AnimTreeParse(char const *, unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

bool __cdecl Scr_LoadAnimTreeInternal(char const *, unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}
