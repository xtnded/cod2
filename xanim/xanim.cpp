float __cdecl ShortLerpAsVec(short, short, float)
{
  UNIMPLEMENTED();
}

void __cdecl Short2LerpAsVec2(short const *const, short const *const, float,
                              float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec2MadShort2Lerp(float const *const, float, short const *const,
                               short const *const, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec4MadShort4Lerp(float const *const, float, short const *const,
                               short const *const, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec2MadShort2(float const *const, float, short const *const,
                           float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Vec4MadShort4(float const *const, float, short const *const,
                           float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Short4ScaleAsVec4(short const *const, float, float *const)
{
  UNIMPLEMENTED();
}

float __cdecl FloatLerp(float, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl Vec3MadVec3Lerp(float const *const, float, float const *const,
                             float const *const, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl Short2CopyAsVec2(short const *const, float *const)
{
  UNIMPLEMENTED();
}

struct XAnimInfo *__cdecl GetAnimInfo(int)
{
  UNIMPLEMENTED();
}

bool __cdecl XAnimNotetrackExists(struct XAnim_s const *anims,
                                  unsigned int animIndex, unsigned int name)
{
  int v3;               // eax
  unsigned __int16 *v4; // edx
  int v5;               // ebx
  unsigned __int16 *v6; // ecx
  int v7;               // edx
  int v8;               // eax

  v3 = *(_DWORD *)&a1->debugAnimNames[8 * a2 + 8];
  v4 = *(unsigned __int16 **)(v3 + 28);
    if (v4) {
      v5 = *(unsigned __int8 *)(v3 + 12);
        if (*(_BYTE *)(v3 + 12)) {
          if (a3 == *v4)
            return 1;
          v6 = v4 + 4;
          v7 = 0;
            while (++v7 != v5) {
              v8 = *v6;
              v6 += 4;
              if (a3 == v8)
                return 1;
            }
        }
    }
  return 0;
}

bool __cdecl XAnimIsLooped(struct XAnim_s const *anims, unsigned int animIndex)
{
  char *v2; // edx

  v2 = &a1->debugName[8 * a2];
  if (*((_WORD *)v2 + 6))
    return *((_WORD *)v2 + 8) & 1;
  else
    return *(unsigned __int8 *)(*((_DWORD *)v2 + 4) + 2);
}

void __cdecl XAnimSetTime(struct XAnimTree_s *tree, unsigned int animIndex,
                          float time)
{
  int *result; // eax

  result = (int *)*(unsigned __int16 *)&a1->infoArray[2 * a2];
    if ((_WORD)result) {
      result = &g_xAnimInfo[10 * (unsigned __int16)result];
      *((float *)result + 3) = a3;
      *((_WORD *)result + 10) = 0;
      *((float *)result + 4) = a3;
      *((_WORD *)result + 11) = 0;
      *((_WORD *)result + 1) = -1;
    }
  return result;
}

bool __cdecl XAnimIsPrimitive(struct XAnim_s *anims, unsigned int animIndex)
{
  return *(_WORD *)&a1->debugAnimNames[8 * a2 + 4] == 0;
}

bool __cdecl XAnimHasTime(struct XAnim_s const *, unsigned int)
{
  UNIMPLEMENTED();
}

int __cdecl DObjGetClientNotifyList(struct XAnimNotify_s **notifyList)
{
  *a1 = (XAnimNotify_s *)&g_notifyList;
  return g_notifyListSize;
}

unsigned int __cdecl XAnimGetAnimTreeSize(struct XAnim_s const *anims)
{
  return a1->size;
}

char const *__cdecl XAnimGetAnimTreeDebugName(struct XAnim_s const *anims)
{
  return *(_DWORD *)a1->debugName;
}

char const *__cdecl XAnimGetAnimName(struct XAnim_s const *anims,
                                     unsigned int animIndex)
{
  if (*(_WORD *)&a1->debugAnimNames[8 * a2 + 4])
    return &inData;
  else
    return *(const gentity_s **)(*(_DWORD *)&a1->debugAnimNames[8 * a2 + 8] +
                                 36);
}

unsigned int __cdecl XAnimGetChildAt(struct XAnim_s const *anims,
                                     unsigned int animIndex,
                                     unsigned int childIndex)
{
  return a3 + *(unsigned __int16 *)&a1->debugAnimNames[8 * a2 + 10];
}

int __cdecl XAnimGetNumChildren(struct XAnim_s const *anims,
                                unsigned int animIndex)
{
  return *(unsigned __int16 *)&a1->debugAnimNames[8 * a2 + 4];
}

bool __cdecl XAnimHasFinished(struct XAnimTree_s const *tree,
                              unsigned int animIndex)
{
  unsigned __int16 v2; // ax
  int *v3;             // eax
  float v4;            // xmm1_4
  _BOOL4 result;       // eax

  v2 = *(_WORD *)&a1->infoArray[2 * a2];
  result = 1;
    if (v2) {
      v3 = &g_xAnimInfo[10 * v2];
      v4 = *((float *)v3 + 3);
      if (*((float *)v3 + 4) <= v4 && v4 != 1.0 &&
          *((_WORD *)v3 + 10) <= *((_WORD *)v3 + 11))
        return 0;
    }
  return result;
}

float __cdecl XAnimGetWeight(struct XAnimTree_s const *tree,
                             unsigned int animIndex)
{
  unsigned __int16 v2; // ax

  v2 = *(_WORD *)&a1->infoArray[2 * a2];
  if (v2)
    return flt_3BE020[10 * v2];
  else
    return 0.0;
}

float __cdecl XAnimGetTime(struct XAnimTree_s const *tree,
                           unsigned int animIndex)
{
  unsigned __int16 v2; // ax

  v2 = *(_WORD *)&a1->infoArray[2 * a2];
  if (v2)
    return *(float *)&dword_3BE00C[10 * v2];
  else
    return 0.0;
}

float __cdecl XAnimGetLength(struct XAnim_s const *anims,
                             unsigned int animIndex)
{
  return (float)((float)**(unsigned __int16 **)&a1->debugAnimNames[8 * a2 + 8] /
                 *(float *)(*(_DWORD *)&a1->debugAnimNames[8 * a2 + 8] + 4));
}

struct XAnim_s *__cdecl XAnimGetAnims(struct XAnimTree_s const *tree)
{
  return a1->anims;
}

int __cdecl XAnimTreeSize(int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimDisableLeakCheck(void)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimAbort()
{
  g_end = 0;
}

void __cdecl XAnimSetAnimRate(struct XAnimTree_s *tree, unsigned int animIndex,
                              float rate)
{
  int result; // eax

  result = 5 * *(unsigned __int16 *)&a1->infoArray[2 * a2];
  dword_3BE024[10 * *(unsigned __int16 *)&a1->infoArray[2 * a2]] = a3;
  return result;
}

int __cdecl XAnimGetLengthMsec(struct XAnim_s const *anims, unsigned int anim)
{
  return (int)(float)((float)((float)**(unsigned __int16 **)&a1
                                  ->debugAnimNames[8 * a2 + 8] /
                              *(float *)(*(_DWORD *)&a1
                                              ->debugAnimNames[8 * a2 + 8] +
                                         4)) *
                      1000.0);
}

struct XAnimTree_s * __cdecl XAnimCreateTree(struct XAnim_s * anims, void *  Alloc)(int))
{
  UNIMPLEMENTED();
}

void __cdecl XAnimFreeList(struct XAnim_s *anims)
{
  uint32_t v1; // esi
  uint32_t v2; // eax
  _DWORD *v3;  // edx
  int v4;      // ebx
  void *v5;    // eax

    if (*(_DWORD *)a1->debugName) {
      Z_FreeInternal(*(void **)a1->debugName);
      *(_DWORD *)a1->debugName = 0;
    }
    if (*(_DWORD *)a1->debugAnimNames) {
        if (a1->size) {
          v1 = 0;
          v2 = 0;
          v3 = *(_DWORD **)a1->debugAnimNames;
            do {
              v4 = 4 * v2;
              v5 = (void *)v3[v2];
                if (v5) {
                  Z_FreeInternal(v5);
                  *(_DWORD *)(v4 + *(_DWORD *)a1->debugAnimNames) = 0;
                  v3 = *(_DWORD **)a1->debugAnimNames;
                }
              v2 = ++v1;
            }
          while (v1 < a1->size);
          Z_FreeInternal(v3);
          *(_DWORD *)a1->debugAnimNames = 0;
        }
        else {
          Z_FreeInternal(*(void **)a1->debugAnimNames);
          *(_DWORD *)a1->debugAnimNames = 0;
        }
    }
}

void __cdecl XAnimFreeAnims(struct XAnim_s *, void(__cdecl *)(void *, int))
{
  UNIMPLEMENTED();
}

char const *__cdecl XAnimGetAnimDebugName(struct XAnim_s const *anims,
                                          unsigned int animIndex)
{
  char *v2;       // edx
  int v3;         // eax
  const char *v4; // ecx

  v2 = &a1->debugName[8 * a2];
  v3 = *(_DWORD *)a1->debugAnimNames;
    if (v3) {
      v4 = *(const char **)(v3 + 4 * a2);
      if (!*((_WORD *)v2 + 6) && *(_BYTE *)(*((_DWORD *)v2 + 4) + 40))
        return va("^3%s (missing)", v4);
      return (char *)v4;
    }
  if (!*((_WORD *)v2 + 6))
    return *(char **)(*((_DWORD *)v2 + 4) + 36);
  return va("%i", a2);
}

struct XAnim_s * __cdecl XAnimCreateAnims(char const * debugName, int size, void *  Alloc)(int))
{
  UNIMPLEMENTED();
}

void __cdecl XAnimBlend(struct XAnim_s *anims, unsigned int animIndex,
                        char const *name, unsigned int children,
                        unsigned int num, unsigned int flags)
{
  char *v6;            // edx
  unsigned int result; // eax
  int i;               // edx
  char *v9;            // ebx

  v6 = &a1->debugAnimNames[8 * a2 + 4];
  *(_WORD *)v6 = a5;
  result = a6;
  *((_WORD *)v6 + 2) = a6;
  *((_WORD *)v6 + 3) = a4;
    if (a5) {
        for (i = 0; i != a5; ++i) {
          result = i + a4;
          *(_WORD *)&a1->debugAnimNames[8 * result + 6] = a2;
        }
    }
    if (*(_DWORD *)a1->debugAnimNames) {
      v9 = (char *)Z_MallocInternal(strlen(__src) + 1);
      strcpy(v9, __src);
      result = *(_DWORD *)a1->debugAnimNames;
      *(_DWORD *)(result + 4 * a2) = v9;
    }
  return result;
}

void __cdecl XAnimGetAbsDelta(struct XAnim_s const *anims,
                              unsigned int animIndex, float *const rot,
                              float *const trans, float time)
{
  char *v5;      // edx
  int v6;        // eax
  float *result; // eax
  float v8;      // xmm2_4
  float v9;      // xmm0_4
  float v10;     // xmm3_4
  float v11;     // xmm4_4
  float v12;     // xmm5_4
  float v13[3];  // [esp+Ch] [ebp-1Ch] BYREF
  float v14[4];  // [esp+18h] [ebp-10h] BYREF

  v5 = &a1->debugName[8 * a2];
    if (!*((_WORD *)v5 + 6) && (v6 = *((_DWORD *)v5 + 4), *(_BYTE *)(v6 + 3))) {
      result = XAnim_CalcDeltaForTime((__int16 *)v6, v14, v13, a5);
      v8 = (float)(v14[0] * 0.000030518509) + 0.0;
      v9 = (float)(0.000030518509 * v14[1]) + 0.0;
      v10 = v13[0] + 0.0;
      v11 = v13[1] + 0.0;
      v12 = v13[2] + 0.0;
        if (v8 == 0.0 && v9 == 0.0) {
          *a3 = 0.0;
          a3[1] = 1.0;
        }
        else {
          *a3 = v8;
          a3[1] = v9;
        }
      *a4 = v10;
      a4[1] = v11;
      a4[2] = v12;
    }
    else {
      result = 0;
      *a3 = 0.0;
      a3[1] = 1.0;
      *a4 = 0.0;
      a4[1] = 0.0;
      a4[2] = 0.0;
    }
  return result;
}

void __cdecl XAnimGetRelDelta(struct XAnim_s const *anims,
                              unsigned int animIndex, float *const rot,
                              float *const trans, float time1, float time2)
{
  char *v6;   // edx
  int v7;     // eax
  int result; // eax
  float v9;   // [esp+18h] [ebp-20h] BYREF
  float v10;  // [esp+1Ch] [ebp-1Ch]
  int v11;    // [esp+20h] [ebp-18h]
  int v12;    // [esp+24h] [ebp-14h]
  int v13;    // [esp+28h] [ebp-10h]
  int v14;    // [esp+2Ch] [ebp-Ch]

  v6 = &a1->debugName[8 * a2];
    if (!*((_WORD *)v6 + 6) && (v7 = *((_DWORD *)v6 + 4), *(_BYTE *)(v7 + 3))) {
      v9 = 0.0;
      v10 = 0.0;
      v11 = 0;
      v12 = 0;
      v13 = 0;
      v14 = 0;
      XAnimCalcRelDeltaParts(v7, &v9, 0, 1.0, a5, a6);
        if (v9 == 0.0 && v10 == 0.0) {
          *a3 = 0.0;
          a3[1] = 1.0;
        }
        else {
          *a3 = v9;
          a3[1] = v10;
        }
      *(_DWORD *)a4 = v12;
      *((_DWORD *)a4 + 1) = v13;
      result = v14;
      *((_DWORD *)a4 + 2) = v14;
    }
    else {
      result = 0;
      *a3 = 0.0;
      a3[1] = 1.0;
      *a4 = 0.0;
      a4[1] = 0.0;
      a4[2] = 0.0;
    }
  return result;
}

void __cdecl XAnimCalcAbsDelta(struct XAnimTree_s *tree, unsigned int animIndex,
                               float *const rot, float *const trans)
{
  int result;      // eax
  unsigned int v5; // [esp+18h] [ebp-20h] BYREF
  float v6;        // [esp+1Ch] [ebp-1Ch]
  int v7;          // [esp+24h] [ebp-14h]
  int v8;          // [esp+28h] [ebp-10h]
  int v9;          // [esp+2Ch] [ebp-Ch]

  a1->bAbs = 1;
  a1->bUseGoalWeight = 1;
  XAnimCalcDeltaTree((int)a1, a2, 1, 1.0, 0, (unsigned int)&v5);
    if (*(float *)&v5 == 0.0 && v6 == 0.0) {
      *a3 = 0.0;
      a3[1] = 1.0;
      *(_DWORD *)a4 = v7;
      *((_DWORD *)a4 + 1) = v8;
      result = v9;
      *((_DWORD *)a4 + 2) = v9;
    }
    else {
      *a3 = *(float *)&v5;
      a3[1] = v6;
      *(_DWORD *)a4 = v7;
      *((_DWORD *)a4 + 1) = v8;
      result = v9;
      *((_DWORD *)a4 + 2) = v9;
    }
  return result;
}

void __cdecl XAnimCalcDelta(struct XAnimTree_s *tree, unsigned int animIndex,
                            float *const rot, float *const trans,
                            bool bUseGoalWeight)
{
  int result;      // eax
  unsigned int v6; // [esp+18h] [ebp-20h] BYREF
  float v7;        // [esp+1Ch] [ebp-1Ch]
  int v8;          // [esp+24h] [ebp-14h]
  int v9;          // [esp+28h] [ebp-10h]
  int v10;         // [esp+2Ch] [ebp-Ch]

  a1->bAbs = 0;
  a1->bUseGoalWeight = a5;
  XAnimCalcDeltaTree((int)a1, a2, 1, 1.0, 0, (unsigned int)&v6);
    if (*(float *)&v6 == 0.0 || v7 == 0.0) {
      *a3 = 0.0;
      a3[1] = 1.0;
      *(_DWORD *)a4 = v8;
      *((_DWORD *)a4 + 1) = v9;
      result = v10;
      *((_DWORD *)a4 + 2) = v10;
    }
    else {
      *a3 = *(float *)&v6;
      a3[1] = v7;
      *(_DWORD *)a4 = v8;
      *((_DWORD *)a4 + 1) = v9;
      result = v10;
      *((_DWORD *)a4 + 2) = v10;
    }
  return result;
}

void __cdecl XAnimClearTreeAnimCache(struct XAnimTree_s *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimFree(struct XAnimParts_s *parts)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimShutdown()
{
  UNIMPLEMENTED();
}

void __cdecl XAnimInit()
{
  int v0;     // edx
  int *v1;    // ecx
  __int16 v2; // ax
  __int16 v3; // ax
  int result; // eax

  v0 = 0;
  v1 = g_xAnimInfo;
    do {
        while (1) {
          v3 = (v0 + 4095) & 0xFFF;
          if (v0 + 4095 >= 0)
            break;
          *((_WORD *)v1 + 4) = ((v3 - 1) | 0xF000) + 1;
          v2 = ++v0 & 0xFFF;
          if (v0 >= 0)
            goto LABEL_3;
        LABEL_6:
          *((_WORD *)v1 + 5) = ((v2 - 1) | 0xF000) + 1;
          v1 += 10;
        }
      *((_WORD *)v1 + 4) = v3;
      v2 = ++v0 & 0xFFF;
      if (v0 < 0)
        goto LABEL_6;
    LABEL_3:
      *((_WORD *)v1 + 5) = v2;
      v1 += 10;
    }
  while (v0 != 4096);
  dword_3BE00C[0] = 0;
  dword_3BE010[0] = 0;
  dword_3BE014[0] = 0;
  g_end = SL_GetString_("end", 0);
  result = *(_DWORD *)(com_developer + 8);
  g_anim_developer = result != 0;
  return result;
}

void __cdecl XAnimClearGoalWeight(struct XAnimTree_s *tree,
                                  unsigned int animIndex, float blendTime)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearChildGoalWeights(struct XAnimTree_s *, unsigned int,
                                        float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearTreeGoalWeights(struct XAnimTree_s *tree,
                                       unsigned int animIndex, float blendTime)
{
  int result;            // eax
  int *v4;               // ebx
  unsigned __int16 v5;   // ax
  int i;                 // esi
  int v7;                // esi
  unsigned __int16 v8;   // ax
  int *v9;               // ebx
  unsigned __int16 v10;  // ax
  int j;                 // esi
  int v12;               // esi
  unsigned __int16 v13;  // ax
  int *v14;              // ebx
  unsigned __int16 v15;  // ax
  int k;                 // esi
  int v17;               // esi
  unsigned __int16 v18;  // ax
  int *v19;              // ebx
  unsigned __int16 v20;  // ax
  int m;                 // esi
  int v22;               // esi
  unsigned __int16 v23;  // ax
  int *v24;              // ebx
  unsigned __int16 v25;  // ax
  int n;                 // esi
  int v27;               // esi
  unsigned __int16 v28;  // ax
  int *v29;              // ebx
  unsigned __int16 v30;  // ax
  int ii;                // esi
  int v32;               // esi
  unsigned __int16 v33;  // ax
  int *v34;              // ebx
  unsigned __int16 v35;  // ax
  int jj;                // esi
  int v37;               // esi
  unsigned __int16 v38;  // ax
  int *v39;              // ebx
  unsigned __int16 v40;  // ax
  int kk;                // esi
  unsigned __int16 *v42; // edi
  int v43;               // esi
  int v44;               // edx
  int v45;               // esi
  unsigned __int16 v46;  // ax
  int *v47;              // ebx
  unsigned __int16 v48;  // ax
  int v49;               // ebx
  int v50;               // [esp+10h] [ebp-78h]
  int v51;               // [esp+14h] [ebp-74h]
  unsigned __int16 *v52; // [esp+18h] [ebp-70h]
  int v53;               // [esp+1Ch] [ebp-6Ch]
  int v54;               // [esp+20h] [ebp-68h]
  unsigned __int16 *v55; // [esp+24h] [ebp-64h]
  int v56;               // [esp+28h] [ebp-60h]
  int v57;               // [esp+2Ch] [ebp-5Ch]
  unsigned __int16 *v58; // [esp+30h] [ebp-58h]
  int v59;               // [esp+34h] [ebp-54h]
  int v60;               // [esp+38h] [ebp-50h]
  unsigned __int16 *v61; // [esp+3Ch] [ebp-4Ch]
  int v62;               // [esp+40h] [ebp-48h]
  int v63;               // [esp+44h] [ebp-44h]
  unsigned __int16 *v64; // [esp+48h] [ebp-40h]
  int v65;               // [esp+4Ch] [ebp-3Ch]
  int v66;               // [esp+50h] [ebp-38h]
  unsigned __int16 *v67; // [esp+54h] [ebp-34h]
  int v68;               // [esp+58h] [ebp-30h]
  int v69;               // [esp+5Ch] [ebp-2Ch]
  unsigned __int16 *v70; // [esp+60h] [ebp-28h]
  int v71;               // [esp+64h] [ebp-24h]
  int v72;               // [esp+68h] [ebp-20h]
  unsigned __int16 *v73; // [esp+6Ch] [ebp-1Ch]

  result = *(unsigned __int16 *)&a1->infoArray[2 * a2];
    if ((_WORD)result) {
      v4 = &g_xAnimInfo[10 * (unsigned __int16)result];
      if (*((float *)v4 + 7) != 0.0 || *((float *)v4 + 6) > a3)
        *((float *)v4 + 6) = a3;
      v4[7] = 0;
      if (a3 == 0.0)
        v4[8] = 0;
      v5 = *((_WORD *)v4 + 2);
        if (v5) {
          SL_RemoveRefToString(a3, v5);
          *((_WORD *)v4 + 2) = 0;
        }
      *((_WORD *)v4 + 1) = -1;
      v52 = (unsigned __int16 *)(a1->anims + 8 * a2 + 12);
      result = *v52;
      v50 = result;
        if (*v52) {
          v51 = 0;
            for (i = 0;; i = v51) {
              v7 = v52[3] + i;
              v8 = *(_WORD *)&a1->infoArray[2 * v7];
                if (v8) {
                  v9 = &g_xAnimInfo[10 * v8];
                  if (*((float *)v9 + 7) != 0.0 || *((float *)v9 + 6) > a3)
                    *((float *)v9 + 6) = a3;
                  v9[7] = 0;
                  if (a3 == 0.0)
                    v9[8] = 0;
                  v10 = *((_WORD *)v9 + 2);
                    if (v10) {
                      SL_RemoveRefToString(a3, v10);
                      *((_WORD *)v9 + 2) = 0;
                    }
                  *((_WORD *)v9 + 1) = -1;
                  v55 = (unsigned __int16 *)(a1->anims + 8 * v7 + 12);
                  v53 = *v55;
                  if (*v55)
                    break;
                }
            LABEL_106:
              result = ++v51;
              if (v50 == v51)
                return result;
            }
          v54 = 0;
            for (j = 0;; j = v54) {
              v12 = v55[3] + j;
              v13 = *(_WORD *)&a1->infoArray[2 * v12];
                if (v13) {
                  v14 = &g_xAnimInfo[10 * v13];
                  if (*((float *)v14 + 7) != 0.0 || *((float *)v14 + 6) > a3)
                    *((float *)v14 + 6) = a3;
                  v14[7] = 0;
                  if (a3 == 0.0)
                    v14[8] = 0;
                  v15 = *((_WORD *)v14 + 2);
                    if (v15) {
                      SL_RemoveRefToString(a3, v15);
                      *((_WORD *)v14 + 2) = 0;
                    }
                  *((_WORD *)v14 + 1) = -1;
                  v58 = (unsigned __int16 *)(a1->anims + 8 * v12 + 12);
                  v56 = *v58;
                  if (*v58)
                    break;
                }
            LABEL_104:
              if (v53 == ++v54)
                goto LABEL_106;
            }
          v57 = 0;
            for (k = 0;; k = v57) {
              v17 = v58[3] + k;
              v18 = *(_WORD *)&a1->infoArray[2 * v17];
                if (v18) {
                  v19 = &g_xAnimInfo[10 * v18];
                  if (*((float *)v19 + 7) != 0.0 || *((float *)v19 + 6) > a3)
                    *((float *)v19 + 6) = a3;
                  v19[7] = 0;
                  if (a3 == 0.0)
                    v19[8] = 0;
                  v20 = *((_WORD *)v19 + 2);
                    if (v20) {
                      SL_RemoveRefToString(a3, v20);
                      *((_WORD *)v19 + 2) = 0;
                    }
                  *((_WORD *)v19 + 1) = -1;
                  v61 = (unsigned __int16 *)(a1->anims + 8 * v17 + 12);
                  v59 = *v61;
                  if (*v61)
                    break;
                }
            LABEL_102:
              if (v56 == ++v57)
                goto LABEL_104;
            }
          v60 = 0;
            for (m = 0;; m = v60) {
              v22 = v61[3] + m;
              v23 = *(_WORD *)&a1->infoArray[2 * v22];
                if (v23) {
                  v24 = &g_xAnimInfo[10 * v23];
                  if (*((float *)v24 + 7) != 0.0 || *((float *)v24 + 6) > a3)
                    *((float *)v24 + 6) = a3;
                  v24[7] = 0;
                  if (a3 == 0.0)
                    v24[8] = 0;
                  v25 = *((_WORD *)v24 + 2);
                    if (v25) {
                      SL_RemoveRefToString(a3, v25);
                      *((_WORD *)v24 + 2) = 0;
                    }
                  *((_WORD *)v24 + 1) = -1;
                  v64 = (unsigned __int16 *)(a1->anims + 8 * v22 + 12);
                  v62 = *v64;
                  if (*v64)
                    break;
                }
            LABEL_100:
              if (v59 == ++v60)
                goto LABEL_102;
            }
          v63 = 0;
            for (n = 0;; n = v63) {
              v27 = v64[3] + n;
              v28 = *(_WORD *)&a1->infoArray[2 * v27];
                if (v28) {
                  v29 = &g_xAnimInfo[10 * v28];
                  if (*((float *)v29 + 7) != 0.0 || *((float *)v29 + 6) > a3)
                    *((float *)v29 + 6) = a3;
                  v29[7] = 0;
                  if (a3 == 0.0)
                    v29[8] = 0;
                  v30 = *((_WORD *)v29 + 2);
                    if (v30) {
                      SL_RemoveRefToString(a3, v30);
                      *((_WORD *)v29 + 2) = 0;
                    }
                  *((_WORD *)v29 + 1) = -1;
                  v67 = (unsigned __int16 *)(a1->anims + 8 * v27 + 12);
                  v65 = *v67;
                  if (*v67)
                    break;
                }
            LABEL_98:
              if (v62 == ++v63)
                goto LABEL_100;
            }
          v66 = 0;
            for (ii = 0;; ii = v66) {
              v32 = v67[3] + ii;
              v33 = *(_WORD *)&a1->infoArray[2 * v32];
                if (v33) {
                  v34 = &g_xAnimInfo[10 * v33];
                  if (*((float *)v34 + 7) != 0.0 || *((float *)v34 + 6) > a3)
                    *((float *)v34 + 6) = a3;
                  v34[7] = 0;
                  if (a3 == 0.0)
                    v34[8] = 0;
                  v35 = *((_WORD *)v34 + 2);
                    if (v35) {
                      SL_RemoveRefToString(a3, v35);
                      *((_WORD *)v34 + 2) = 0;
                    }
                  *((_WORD *)v34 + 1) = -1;
                  v70 = (unsigned __int16 *)(a1->anims + 8 * v32 + 12);
                  v68 = *v70;
                  if (*v70)
                    break;
                }
            LABEL_96:
              if (v65 == ++v66)
                goto LABEL_98;
            }
          v69 = 0;
            for (jj = 0;; jj = v69) {
              v37 = v70[3] + jj;
              v38 = *(_WORD *)&a1->infoArray[2 * v37];
                if (v38) {
                  v39 = &g_xAnimInfo[10 * v38];
                  if (*((float *)v39 + 7) != 0.0 || *((float *)v39 + 6) > a3)
                    *((float *)v39 + 6) = a3;
                  v39[7] = 0;
                  if (a3 == 0.0)
                    v39[8] = 0;
                  v40 = *((_WORD *)v39 + 2);
                    if (v40) {
                      SL_RemoveRefToString(a3, v40);
                      *((_WORD *)v39 + 2) = 0;
                    }
                  *((_WORD *)v39 + 1) = -1;
                  v73 = (unsigned __int16 *)(a1->anims + 8 * v37 + 12);
                  v71 = *v73;
                  if (*v73)
                    break;
                }
            LABEL_94:
              if (v68 == ++v69)
                goto LABEL_96;
            }
          v72 = 0;
            for (kk = 0;; kk = v44) {
              v45 = v73[3] + kk;
              v46 = *(_WORD *)&a1->infoArray[2 * v45];
              if (!v46)
                break;
              v47 = &g_xAnimInfo[10 * v46];
              if (*((float *)v47 + 7) != 0.0 || *((float *)v47 + 6) > a3)
                *((float *)v47 + 6) = a3;
              v47[7] = 0;
              if (a3 == 0.0)
                v47[8] = 0;
              v48 = *((_WORD *)v47 + 2);
                if (v48) {
                  SL_RemoveRefToString(a3, v48);
                  *((_WORD *)v47 + 2) = 0;
                  *((_WORD *)v47 + 1) = -1;
                  v42 = (unsigned __int16 *)(a1->anims + 8 * v45 + 12);
                  v43 = *v42;
                  if (!*v42)
                    break;
                }
                else {
                  *((_WORD *)v47 + 1) = -1;
                  v42 = (unsigned __int16 *)(a1->anims + 8 * v45 + 12);
                  v43 = *v42;
                  if (!*v42)
                    break;
                }
              v49 = 0;
                do {
                  XAnimClearTreeGoalWeights(a1, v49 + v42[3], a3);
                  ++v49;
                }
              while (v43 != v49);
              v44 = ++v72;
              if (v71 == v72)
                goto LABEL_94;
            LABEL_82:;
            }
          v44 = ++v72;
          if (v71 == v72)
            goto LABEL_94;
          goto LABEL_82;
        }
    }
  return result;
}

struct XAnimParts_s *__cdecl XAnimPrecache(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearTree(struct XAnimTree_s *tree)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearTreeGoalWeightsStrict(struct XAnimTree_s *tree,
                                             unsigned int animIndex,
                                             float blendTime)
{
  int result;            // eax
  int i;                 // esi
  int v5;                // edi
  int v6;                // esi
  int v7;                // edx
  int v8;                // esi
  int *v9;               // ebx
  unsigned __int16 v10;  // ax
  int v11;               // ebx
  int v12;               // [esp+14h] [ebp-24h]
  int v13;               // [esp+18h] [ebp-20h]
  unsigned __int16 *v14; // [esp+1Ch] [ebp-1Ch]

  v14 = (unsigned __int16 *)(a1->anims + 8 * a2 + 12);
  result = *v14;
  v12 = result;
    if (*v14) {
      v13 = 0;
        for (i = 0;; i = v7) {
          v8 = v14[3] + i;
          result = *(unsigned __int16 *)&a1->infoArray[2 * v8];
          if (!(_WORD)result)
            break;
          v9 = &g_xAnimInfo[10 * (unsigned __int16)result];
          if (*((float *)v9 + 7) != 0.0 || *((float *)v9 + 6) > a3)
            *((float *)v9 + 6) = a3;
          v9[7] = 0;
          if (a3 == 0.0)
            v9[8] = 0;
          v10 = *((_WORD *)v9 + 2);
            if (v10) {
              SL_RemoveRefToString(v10);
              *((_WORD *)v9 + 2) = 0;
              *((_WORD *)v9 + 1) = -1;
              result = a1->anims + 8 * v8;
              v5 = result + 12;
              v6 = *(unsigned __int16 *)(result + 12);
              if (!*(_WORD *)(result + 12))
                break;
            }
            else {
              *((_WORD *)v9 + 1) = -1;
              result = a1->anims + 8 * v8;
              v5 = result + 12;
              v6 = *(unsigned __int16 *)(result + 12);
              if (!*(_WORD *)(result + 12))
                break;
            }
          v11 = 0;
            do {
              result = XAnimClearTreeGoalWeights(
                  a1, v11 + *(unsigned __int16 *)(v5 + 6), a3);
              ++v11;
            }
          while (v6 != v11);
          v7 = ++v13;
          if (v12 == v13)
            return result;
        LABEL_5:;
        }
      v7 = ++v13;
      if (v12 == v13)
        return result;
      goto LABEL_5;
    }
  return result;
}

void __cdecl DObjInitServerTime(struct DObj_s *obj, float dtime)
{
  int32_t result;  // eax
  int v3;          // [esp+10h] [ebp-28h] BYREF
  __int16 v4;      // [esp+18h] [ebp-20h]
  char v5;         // [esp+2Eh] [ebp-Ah] BYREF
  unsigned int v6; // [esp+2Fh] [ebp-9h] BYREF

  result = a1->tree;
    if (a1->tree) {
      v3 = 0;
      v4 = 0;
      return XAnimUpdateOldTime(a1->tree, 0, &v3, a2, (XAnimTree_s *)1, &v6,
                                (XAnimState *)&v5);
    }
  return result;
}

void __cdecl XAnimFreeTree(struct XAnimTree_s * tree, void  Free)(void *,int))
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCreate(struct XAnim_s *anims, unsigned int animIndex,
                         char const *name)
{
  int DataForFile; // edx
  char *result;    // eax
  char *v5;        // ebx

  DataForFile = Hunk_FindDataForFile(5, __src);
  if (!DataForFile)
    return (char *)Com_Error(1, "\x15Cannot find xanim '%s'", (char)__src);
  result = &a1->debugName[8 * a2];
  *((_WORD *)result + 6) = 0;
  *((_DWORD *)result + 4) = DataForFile;
    if (*(_DWORD *)a1->debugAnimNames) {
      v5 = (char *)Z_MallocInternal(strlen(__src) + 1);
      strcpy(v5, __src);
      result = *(char **)a1->debugAnimNames;
      *(_DWORD *)&result[4 * a2] = v5;
    }
  return result;
}

struct XAnimInfo *__cdecl XAnimAllocInfo(struct XAnimTree_s *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCloneClientAnimTree(struct XAnimTree_s const *,
                                      struct XAnimTree_s *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCloneAnimTree(struct XAnimTree_s const *from,
                                struct XAnimTree_s *to)
{
  UNIMPLEMENTED();
}

void __cdecl DObjTransfer(struct DObj_s const *, struct DObj_s *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimSetCompleteGoalWeight(struct XAnimTree_s *tree,
                                        unsigned int animIndex,
                                        float goalWeight, float goalTime,
                                        float rate, unsigned int notifyName,
                                        unsigned int notifyType, int bRestart)
{
  __m128 v8;             // rt1
  unsigned int v9;       // ebx
  unsigned __int16 v10;  // si
  unsigned __int16 v11;  // ax
  int result;            // eax
  int32_t anims;         // edx
  unsigned int v14;      // ecx
  int *v15;              // ebx
  unsigned int v16;      // eax
  unsigned __int16 *v17; // esi
  unsigned __int16 v18;  // ax
  int v19;               // ecx
  int *v20;              // eax
  int v21;               // ebx
  int v22;               // [esp+10h] [ebp-28h]
  int v23;               // [esp+14h] [ebp-24h]
  int v24;               // [esp+18h] [ebp-20h]
  unsigned __int16 *v25; // [esp+1Ch] [ebp-1Ch]

  v8.i32[0] = 981668463;
  XAnimSetGoalWeightInternal(
      a1, a2, 0, COERCE_FLOAT(_mm_cmpge_ss((__m128)a3, v8).u32[0] & a3), a4, a5,
      a6, a7);
    if (a2) {
      v9 = a2;
        do {
          v10 = *(_WORD *)(a1->anims + 8 * v9 + 14);
          v9 = v10;
          v11 = *(_WORD *)&a1->infoArray[2 * v10];
          if (!v11 || *(float *)&dword_3BE01C[10 * v11] == 0.0)
            XAnimSetGoalWeightInternal(a1, v10, 0, 1.0, a4, 1065353216, 0, 0);
        }
      while (v10);
    }
  result = a8;
    if (a8) {
        if (a2) {
          anims = a1->anims;
          v14 = a2;
            while (1) {
              v15 = &g_xAnimInfo[10 *
                                 *(unsigned __int16 *)&a1->infoArray[2 * v14]];
              v16 = anims + 8 * v14;
              v17 = (unsigned __int16 *)(v16 + 12);
                if (*(_WORD *)(v16 + 12)) {
                  if ((*(_BYTE *)(v16 + 16) & 4) != 0)
                    break;
                }
              v18 = *(_WORD *)(anims + 8 * v14 + 14);
              v14 = v18;
              if (!v18)
                goto LABEL_10;
            }
          result = (int)(v15 + 3);
            if (*((float *)v15 + 3) != 0.0 || *((_WORD *)v15 + 10)) {
              *(_DWORD *)result = 0;
              *((_WORD *)v15 + 10) = 0;
              v15[4] = 0;
              *((_WORD *)v15 + 11) = 0;
              *((_WORD *)v15 + 1) = -1;
              result = *v17;
              v22 = result;
                if (*v17) {
                  v23 = 0;
                    do {
                      v19 = v17[3] + v23;
                      result = *(unsigned __int16 *)&a1->infoArray[2 * v19];
                        if ((_WORD)result) {
                          v20 = &g_xAnimInfo[10 * (unsigned __int16)result];
                            if (*((float *)v20 + 3) != 0.0 ||
                                *((_WORD *)v20 + 10)) {
                              v20[3] = 0;
                              *((_WORD *)v20 + 10) = 0;
                              v20[4] = 0;
                              *((_WORD *)v20 + 11) = 0;
                              *((_WORD *)v20 + 1) = -1;
                            }
                          v25 = (unsigned __int16 *)(a1->anims + 8 * v19 + 12);
                          result = *v25;
                          v24 = result;
                            if (*v25) {
                              v21 = 0;
                                do {
                                  result = XAnimResetTime(a1, v21 + v25[3]);
                                  ++v21;
                                }
                              while (v24 != v21);
                            }
                        }
                      ++v23;
                    }
                  while (v22 != v23);
                }
            }
        }
        else {
          anims = a1->anims;
        LABEL_10:
          result = a2;
            if (!*(_WORD *)(anims + 8 * a2 + 12)) {
              result = (int)&g_xAnimInfo[10 * *(unsigned __int16 *)&a1
                                                   ->infoArray[2 * a2]];
                if (*(float *)(result + 12) != 0.0 || *(_WORD *)(result + 20)) {
                  *(_DWORD *)(result + 12) = 0;
                  *(_WORD *)(result + 20) = 0;
                  *(_DWORD *)(result + 16) = 0;
                  *(_WORD *)(result + 22) = 0;
                  *(_WORD *)(result + 2) = -1;
                }
            }
        }
    }
  return result;
}

void __cdecl XAnimSetupSyncNodes(struct XAnim_s *anims)
{
  UNIMPLEMENTED();
}

int __cdecl XAnimSetCompleteGoalWeightKnobAll(
    struct XAnimTree_s *tree, unsigned int animIndex, unsigned int rootIndex,
    float goalWeight, float goalTime, float rate, unsigned int notifyName,
    int bRestart)
{
  __m128 v8;             // rt1
  __m128 v9;             // xmm1
  float v10;             // xmm1_4
  int v11;               // eax
  int v12;               // edi
  int v13;               // ebx
  char *v14;             // edx
  int v15;               // ecx
  float v16;             // xmm1_4
  float v17;             // xmm0_4
  float v18;             // xmm0_4
  int v19;               // ebx
  XAnimTree_s *v20;      // ebx
  int32_t anims;         // ecx
  unsigned int v22;      // edx
  int *v23;              // ebx
  unsigned int v24;      // eax
  unsigned __int16 *v25; // esi
  unsigned __int16 v26;  // ax
  unsigned int v27;      // eax
  int32_t v28;           // edx
  unsigned __int16 v29;  // ax
  int v30;               // edi
  unsigned __int16 *v31; // edx
  float v32;             // xmm1_4
  float v33;             // xmm1_4
  int v34;               // esi
  int v35;               // eax
  unsigned __int16 v36;  // ax
  int *v37;              // ebx
  float v38;             // xmm0_4
  unsigned __int16 v39;  // ax
  XAnimTree_s *v40;      // ebx
  int32_t v41;           // ecx
  int v42;               // edx
  int *v43;              // ebx
  int v44;               // eax
  unsigned __int16 *v45; // esi
  unsigned __int16 v46;  // ax
  int *v47;              // edx
  int v49;               // ebx
  char *v50;             // edx
  int v51;               // ecx
  float v52;             // xmm0_4
  int *v53;              // edx
  float v54;             // xmm1_4
  int v55;               // esi
  int v56;               // eax
  unsigned __int16 v57;  // ax
  int *v58;              // ebx
  float v59;             // xmm0_4
  unsigned __int16 v60;  // ax
  XAnimTree_s *v61;      // eax
  int v62;               // ecx
  unsigned __int16 v63;  // ax
  int *v64;              // eax
  int v65;               // ebx
  int v66;               // ecx
  unsigned __int16 v67;  // ax
  int *v68;              // eax
  int v69;               // edi
  int v70;               // ebx
  int v71;               // esi
  int v72;               // eax
  unsigned __int16 v73;  // ax
  int *v74;              // ebx
  float v75;             // xmm0_4
  unsigned __int16 v76;  // ax
  int i;                 // esi
  int v78;               // eax
  unsigned __int16 v79;  // ax
  int *v80;              // ebx
  float v81;             // xmm0_4
  unsigned __int16 v82;  // ax
  int v83;               // [esp+1Ch] [ebp-4Ch]
  int v84;               // [esp+20h] [ebp-48h]
  int v85;               // [esp+28h] [ebp-40h]
  int v86;               // [esp+2Ch] [ebp-3Ch]
  unsigned __int16 *v87; // [esp+30h] [ebp-38h]
  int v88;               // [esp+34h] [ebp-34h]
  unsigned __int16 *v89; // [esp+38h] [ebp-30h]
  int v90;               // [esp+40h] [ebp-28h]
  int v91;               // [esp+44h] [ebp-24h]
  int v92;               // [esp+48h] [ebp-20h]
  unsigned __int16 *v93; // [esp+4Ch] [ebp-1Ch]
  float v94;             // [esp+7Ch] [ebp+14h]

  v8.i32[0] = 981668463;
  v9 = _mm_cmpge_ss((__m128)a4, v8);
  LODWORD(v10) = _mm_andnot_ps(v9, (__m128)0LL).u32[0] | a4 & v9.i32[0];
  v94 = v10;
    if (a2) {
      v11 = a1->anims + 8 * *(unsigned __int16 *)(a1->anims + 8 * a2 + 14);
      v84 = v11 + 12;
      v12 = *(unsigned __int16 *)(v11 + 12);
        if (*(_WORD *)(v11 + 12)) {
          v13 = *(unsigned __int16 *)(v11 + 18);
          v14 = &a1->infoArray[2 * v13];
          v15 = 0;
          v16 = 0.0;
            while (1) {
                if (*(_WORD *)v14) {
                  v17 = flt_3BE020[10 * *(unsigned __int16 *)v14];
                  if (a2 == v13 + v15)
                  LABEL_8:
                    v17 = fabs(v94 - v17);
                }
                else {
                  v17 = 0.0;
                  if (a2 == v13 + v15)
                    goto LABEL_8;
                }
              v16 = fmaxf(v17, v16);
              ++v15;
              v14 += 2;
              if (v12 == v15)
                goto LABEL_66;
            }
        }
      v16 = 0.0;
    LABEL_66:
      v54 = v16 * a5;
        if (*(_WORD *)(v11 + 12)) {
            if (v54 != 0.0) {
              v55 = 0;
                while (1) {
                    while (1) {
                      v56 = v55 + *(unsigned __int16 *)(v84 + 6);
                        if (a2 != v56) {
                          v57 = *(_WORD *)&a1->infoArray[2 * v56];
                          if (v57)
                            break;
                        }
                      if (++v55 == v12)
                        goto LABEL_77;
                    }
                  v58 = &g_xAnimInfo[10 * v57];
                  if (*((float *)v58 + 7) == 0.0)
                    break;
                  v59 = v54;
                  *((_QWORD *)v58 + 3) = LODWORD(v54);
                  v60 = *((_WORD *)v58 + 2);
                  if (v60)
                    goto LABEL_79;
                LABEL_76:
                  *((_WORD *)v58 + 1) = -1;
                  if (++v55 == v12)
                    goto LABEL_77;
                }
              v59 = *((float *)v58 + 6);
              if (v59 > v54)
                *((float *)v58 + 6) = v54;
              v58[7] = 0;
              v60 = *((_WORD *)v58 + 2);
              if (!v60)
                goto LABEL_76;
            LABEL_79:
              SL_RemoveRefToString(v59, v60);
              *((_WORD *)v58 + 2) = 0;
              goto LABEL_76;
            }
          v71 = 0;
            do {
              v72 = v71 + *(unsigned __int16 *)(v84 + 6);
                if (a2 != v72) {
                  v73 = *(_WORD *)&a1->infoArray[2 * v72];
                    if (v73) {
                      v74 = &g_xAnimInfo[10 * v73];
                      v75 = 0.0;
                        if (*((float *)v74 + 7) == 0.0) {
                          v75 = *((float *)v74 + 6);
                          if (v75 > v54)
                            *((float *)v74 + 6) = v54;
                        }
                        else {
                          *((float *)v74 + 6) = v54;
                        }
                      v74[7] = 0;
                      v74[8] = 0;
                      v76 = *((_WORD *)v74 + 2);
                        if (v76) {
                          SL_RemoveRefToString(v75, v76);
                          *((_WORD *)v74 + 2) = 0;
                        }
                      *((_WORD *)v74 + 1) = -1;
                    }
                }
              ++v71;
            }
          while (v12 != v71);
          v18 = v94;
        }
        else {
        LABEL_77:
          v18 = v94;
        }
    }
    else {
      v18 = v10;
    }
  v83 = XAnimSetGoalWeightInternal(a1, a2, 0, v18, a5, a6, a7, 0);
    if (a2) {
      v19 = *(unsigned __int16 *)(a1->anims + 8 * a2 + 14);
        if (!*(_WORD *)&a1->infoArray[2 * v19]) {
          v61 = a1;
            do {
              XAnimSetGoalWeightInternal(v61, v19, 1, 0.0, a5, 1065353216, 0,
                                         0);
              if (!v19)
                break;
              v61 = a1;
              v19 = *(unsigned __int16 *)(a1->anims + 8 * v19 + 14);
            }
          while (!*(_WORD *)&a1->infoArray[2 * v19]);
        }
    }
  if (!a8)
    goto LABEL_20;
    if (!a2) {
      v27 = 0;
      if (!*(_WORD *)(a1->anims + 12))
        goto LABEL_62;
      goto LABEL_20;
    }
  v20 = a1;
  anims = a1->anims;
  v22 = a2;
    while (1) {
      v23 = &g_xAnimInfo[10 * *(unsigned __int16 *)&v20->infoArray[2 * v22]];
      v24 = anims + 8 * v22;
      v25 = (unsigned __int16 *)(v24 + 12);
        if (*(_WORD *)(v24 + 12) && (*(_BYTE *)(v24 + 16) & 4) != 0) {
            if (*((float *)v23 + 3) != 0.0 || *((_WORD *)v23 + 10)) {
              v23[3] = 0;
              *((_WORD *)v23 + 10) = 0;
              v23[4] = 0;
              *((_WORD *)v23 + 11) = 0;
              *((_WORD *)v23 + 1) = -1;
              v85 = *v25;
                if (*v25) {
                  v86 = 0;
                    do {
                      v66 = v25[3] + v86;
                      v67 = *(_WORD *)&a1->infoArray[2 * v66];
                        if (v67) {
                          v68 = &g_xAnimInfo[10 * v67];
                            if (*((float *)v68 + 3) != 0.0 ||
                                *((_WORD *)v68 + 10)) {
                              v68[3] = 0;
                              *((_WORD *)v68 + 10) = 0;
                              v68[4] = 0;
                              *((_WORD *)v68 + 11) = 0;
                              *((_WORD *)v68 + 1) = -1;
                            }
                          v87 = (unsigned __int16 *)(a1->anims + 8 * v66 + 12);
                          v69 = *v87;
                            if (*v87) {
                              v70 = 0;
                                do {
                                  XAnimResetTime(a1, v70 + v87[3]);
                                  ++v70;
                                }
                              while (v69 != v70);
                            }
                        }
                      ++v86;
                    }
                  while (v85 != v86);
                }
            }
          goto LABEL_21;
        }
      v26 = *(_WORD *)(anims + 8 * v22 + 14);
      v22 = v26;
      if (!v26)
        break;
      v20 = a1;
    }
  v27 = a2;
  if (*(_WORD *)(anims + 8 * a2 + 12))
    goto LABEL_20;
LABEL_62:
  v53 = &g_xAnimInfo[10 * *(unsigned __int16 *)&a1->infoArray[2 * v27]];
    if (*((float *)v53 + 3) != 0.0 || *((_WORD *)v53 + 10)) {
      v53[3] = 0;
      *((_WORD *)v53 + 10) = 0;
      v53[4] = 0;
      *((_WORD *)v53 + 11) = 0;
      *((_WORD *)v53 + 1) = -1;
    }
LABEL_20:
  if (!a2)
    return 1;
LABEL_21:
  v28 = a1->anims;
  v29 = *(_WORD *)(a1->anims + 8 * a2 + 14);
  v30 = v29;
    if (a3 != v29) {
        while (1) {
          if (!v29)
            goto LABEL_36;
          v31 = (unsigned __int16 *)(v28 +
                                     8 * *(unsigned __int16 *)(v28 + 8 * v30 +
                                                               14) +
                                     12);
          v89 = v31;
          v88 = *v31;
          if (*v31)
            break;
          v32 = 0.0;
        LABEL_25:
          v33 = v32 * a5;
            if (v88 > 0) {
                if (v33 != 0.0) {
                  v34 = 0;
                    while (1) {
                        while (1) {
                          v35 = v34 + v89[3];
                            if (v30 != v35) {
                              v36 = *(_WORD *)&a1->infoArray[2 * v35];
                              if (v36)
                                break;
                            }
                          if (++v34 == v88)
                            goto LABEL_36;
                        }
                      v37 = &g_xAnimInfo[10 * v36];
                      if (*((float *)v37 + 7) == 0.0)
                        break;
                      v38 = v33;
                      *((_QWORD *)v37 + 3) = LODWORD(v33);
                      v39 = *((_WORD *)v37 + 2);
                      if (v39)
                        goto LABEL_50;
                    LABEL_35:
                      *((_WORD *)v37 + 1) = -1;
                      if (++v34 == v88)
                        goto LABEL_36;
                    }
                  v38 = *((float *)v37 + 6);
                  if (v38 > v33)
                    *((float *)v37 + 6) = v33;
                  v37[7] = 0;
                  v39 = *((_WORD *)v37 + 2);
                  if (!v39)
                    goto LABEL_35;
                LABEL_50:
                  SL_RemoveRefToString(v38, v39);
                  *((_WORD *)v37 + 2) = 0;
                  goto LABEL_35;
                }
                for (i = 0; i != v88; ++i) {
                  v78 = i + v89[3];
                    if (v30 != v78) {
                      v79 = *(_WORD *)&a1->infoArray[2 * v78];
                        if (v79) {
                          v80 = &g_xAnimInfo[10 * v79];
                          v81 = 0.0;
                            if (*((float *)v80 + 7) == 0.0) {
                              v81 = *((float *)v80 + 6);
                              if (v81 > v33)
                                *((float *)v80 + 6) = v33;
                            }
                            else {
                              *((float *)v80 + 6) = v33;
                            }
                          v80[7] = 0;
                          v80[8] = 0;
                          v82 = *((_WORD *)v80 + 2);
                            if (v82) {
                              SL_RemoveRefToString(v81, v82);
                              *((_WORD *)v80 + 2) = 0;
                            }
                          *((_WORD *)v80 + 1) = -1;
                        }
                    }
                }
            }
        LABEL_36:
          XAnimSetGoalWeightInternal(a1, v30, 0, 1.0, a5, 1065353216, 0, 0);
          if (!a8)
            goto LABEL_46;
            if (v30) {
              v40 = a1;
              v41 = a1->anims;
              v42 = v30;
                while (1) {
                  v43 = &g_xAnimInfo[10 * *(unsigned __int16 *)&v40
                                               ->infoArray[2 * v42]];
                  v44 = v41 + 8 * v42;
                  v45 = (unsigned __int16 *)(v44 + 12);
                    if (*(_WORD *)(v44 + 12)) {
                      if ((*(_BYTE *)(v44 + 16) & 4) != 0)
                        break;
                    }
                  v46 = *(_WORD *)(v41 + 8 * v42 + 14);
                  v42 = v46;
                  if (!v46)
                    goto LABEL_43;
                  v40 = a1;
                }
                if (*((float *)v43 + 3) != 0.0 || *((_WORD *)v43 + 10)) {
                  v43[3] = 0;
                  *((_WORD *)v43 + 10) = 0;
                  v43[4] = 0;
                  *((_WORD *)v43 + 11) = 0;
                  *((_WORD *)v43 + 1) = -1;
                  v90 = *v45;
                    if (*v45) {
                      v91 = 0;
                        do {
                          v62 = v45[3] + v91;
                          v63 = *(_WORD *)&a1->infoArray[2 * v62];
                            if (v63) {
                              v64 = &g_xAnimInfo[10 * v63];
                                if (*((float *)v64 + 3) != 0.0 ||
                                    *((_WORD *)v64 + 10)) {
                                  v64[3] = 0;
                                  *((_WORD *)v64 + 10) = 0;
                                  v64[4] = 0;
                                  *((_WORD *)v64 + 11) = 0;
                                  *((_WORD *)v64 + 1) = -1;
                                }
                              v93 = (unsigned __int16 *)(a1->anims + 8 * v62 +
                                                         12);
                              v92 = *v93;
                                if (*v93) {
                                  v65 = 0;
                                    do {
                                      XAnimResetTime(a1, v65 + v93[3]);
                                      ++v65;
                                    }
                                  while (v92 != v65);
                                }
                            }
                          ++v91;
                        }
                      while (v90 != v91);
                    }
                }
            }
            else {
              v41 = a1->anims;
            LABEL_43:
              if (*(_WORD *)(v41 + 8 * v30 + 12))
                goto LABEL_46;
              v47 = &g_xAnimInfo[10 *
                                 *(unsigned __int16 *)&a1->infoArray[2 * v30]];
                if (*((float *)v47 + 3) != 0.0 || *((_WORD *)v47 + 10)) {
                  v47[3] = 0;
                  *((_WORD *)v47 + 10) = 0;
                  v47[4] = 0;
                  *((_WORD *)v47 + 11) = 0;
                  *((_WORD *)v47 + 1) = -1;
                LABEL_46:
                  if (!v30)
                    return 1;
                  goto LABEL_47;
                }
              if (!v30)
                return 1;
            }
        LABEL_47:
          v28 = a1->anims;
          v29 = *(_WORD *)(a1->anims + 8 * v30 + 14);
          v30 = v29;
          if (a3 == v29)
            return v83;
        }
      v49 = v31[3];
      v50 = &a1->infoArray[2 * v49];
      v51 = 0;
      v32 = 0.0;
        while (1) {
            if (*(_WORD *)v50) {
              v52 = flt_3BE020[10 * *(unsigned __int16 *)v50];
              if (v30 == v49 + v51)
              LABEL_56:
                v52 = fabs(1.0 - v52);
            }
            else {
              v52 = 0.0;
              if (v30 == v49 + v51)
                goto LABEL_56;
            }
          v32 = fmaxf(v52, v32);
          ++v51;
          v50 += 2;
          if (v88 == v51)
            goto LABEL_25;
        }
    }
  return v83;
}

void __cdecl XAnimSetCompleteGoalWeightKnob(struct XAnimTree_s *, unsigned int,
                                            float, float, float, unsigned int,
                                            int)
{
  UNIMPLEMENTED();
}

int __cdecl XAnimSetGoalWeight(struct XAnimTree_s *tree, unsigned int animIndex,
                               float goalWeight, float goalTime, float rate,
                               unsigned int notifyName, unsigned int notifyType,
                               int bRestart)
{
  __m128 v8;             // rt1
  int i;                 // ebx
  int32_t anims;         // ecx
  int *v11;              // eax
  unsigned int v13;      // edx
  int *v14;              // ebx
  unsigned int v15;      // eax
  unsigned __int16 *v16; // esi
  unsigned __int16 v17;  // ax
  int v18;               // ecx
  unsigned __int16 v19;  // ax
  int *v20;              // eax
  int v21;               // ebx
  int v22;               // [esp+1Ch] [ebp-2Ch]
  int v23;               // [esp+20h] [ebp-28h]
  int v24;               // [esp+24h] [ebp-24h]
  int v25;               // [esp+28h] [ebp-20h]
  unsigned __int16 *v26; // [esp+2Ch] [ebp-1Ch]

  v8.i32[0] = 981668463;
  v22 = XAnimSetGoalWeightInternal(
      a1, a2, 0, COERCE_FLOAT(_mm_cmpge_ss((__m128)a3, v8).u32[0] & a3), a4, a5,
      a6, a7);
    if (a2) {
        for (i = *(unsigned __int16 *)(a1->anims + 8 * a2 + 14);
             !*(_WORD *)&a1->infoArray[2 * i];
             i = *(unsigned __int16 *)(a1->anims + 8 * i + 14)) {
          XAnimSetGoalWeightInternal(a1, i, 1, 0.0, a4, 1065353216, 0, 0);
          if (!i)
            break;
        }
    }
    if (a8) {
        if (a2) {
          anims = a1->anims;
          v13 = a2;
            while (1) {
              v14 = &g_xAnimInfo[10 *
                                 *(unsigned __int16 *)&a1->infoArray[2 * v13]];
              v15 = anims + 8 * v13;
              v16 = (unsigned __int16 *)(v15 + 12);
                if (*(_WORD *)(v15 + 12)) {
                  if ((*(_BYTE *)(v15 + 16) & 4) != 0)
                    break;
                }
              v17 = *(_WORD *)(anims + 8 * v13 + 14);
              v13 = v17;
              if (!v17)
                goto LABEL_6;
            }
            if (*((float *)v14 + 3) != 0.0 || *((_WORD *)v14 + 10)) {
              v14[3] = 0;
              *((_WORD *)v14 + 10) = 0;
              v14[4] = 0;
              *((_WORD *)v14 + 11) = 0;
              *((_WORD *)v14 + 1) = -1;
              v23 = *v16;
                if (*v16) {
                  v24 = 0;
                    do {
                      v18 = v16[3] + v24;
                      v19 = *(_WORD *)&a1->infoArray[2 * v18];
                        if (v19) {
                          v20 = &g_xAnimInfo[10 * v19];
                            if (*((float *)v20 + 3) != 0.0 ||
                                *((_WORD *)v20 + 10)) {
                              v20[3] = 0;
                              *((_WORD *)v20 + 10) = 0;
                              v20[4] = 0;
                              *((_WORD *)v20 + 11) = 0;
                              *((_WORD *)v20 + 1) = -1;
                            }
                          v26 = (unsigned __int16 *)(a1->anims + 8 * v18 + 12);
                          v25 = *v26;
                            if (*v26) {
                              v21 = 0;
                                do {
                                  XAnimResetTime(a1, v21 + v26[3]);
                                  ++v21;
                                }
                              while (v25 != v21);
                            }
                        }
                      ++v24;
                    }
                  while (v23 != v24);
                }
            }
        }
        else {
          anims = a1->anims;
        LABEL_6:
            if (!*(_WORD *)(anims + 8 * a2 + 12)) {
              v11 = &g_xAnimInfo[10 *
                                 *(unsigned __int16 *)&a1->infoArray[2 * a2]];
                if (*((float *)v11 + 3) != 0.0 || *((_WORD *)v11 + 10)) {
                  v11[3] = 0;
                  *((_WORD *)v11 + 10) = 0;
                  v11[4] = 0;
                  *((_WORD *)v11 + 11) = 0;
                  *((_WORD *)v11 + 1) = -1;
                }
            }
        }
    }
  return v22;
}

void __cdecl XAnimSetGoalWeightKnob(struct XAnimTree_s *, unsigned int, float,
                                    float, float, unsigned int, int)
{
  UNIMPLEMENTED();
}

void __cdecl DObjDisplayAnim(struct DObj_s *obj)
{
    if (a1->tree) {
      XAnimDisplay((int *)a1->tree, 0, 0);
      Com_Printf("\n");
    }
    else {
      Com_Printf("NO TREE\n");
    }
}

void __cdecl DObjCalcAnim(struct DObj_s const *obj, int *const partBits)
{
  _DWORD *v2;      // edx
  char v3;         // cl
  int v4;          // ebx
  int *v5;         // esi
  int v6;          // eax
  _DWORD *v7;      // edx
  int v8;          // esi
  int v9;          // ebx
  int v10;         // ecx
  __int16 *v11;    // edi
  __int16 v12;     // ax
  int v13;         // edx
  int v14;         // esi
  __int16 *v15;    // ecx
  int v16;         // edi
  __int16 *v17;    // edx
  __int16 v18;     // ax
  int v19;         // edx
  int32_t skel;    // [esp+1Ch] [ebp-404Ch]
  int v21;         // [esp+24h] [ebp-4044h]
  DObj_s *v22;     // [esp+28h] [ebp-4040h]
  int v23;         // [esp+2Ch] [ebp-403Ch]
  float v24[4096]; // [esp+30h] [ebp-4038h] BYREF
  _DWORD v25[7];   // [esp+4030h] [ebp-38h] BYREF
  int v26;         // [esp+404Ch] [ebp-1Ch]

  skel = a1->skel;
  v2 = (_DWORD *)skel;
  v3 = 1;
  v4 = 1;
  v5 = v25;
    do {
      v6 = *v2 | ~a2[v4 - 1];
      *v5 = v6;
      if (v6 != -1)
        v3 = 0;
      ++v4;
      ++v5;
      ++v2;
    }
  while (v4 != 5);
    if (!v3) {
      v7 = (_DWORD *)skel;
      v8 = 1;
      LOBYTE(v4) = 4;
        do {
          *v7 |= *(int *)((char *)a2 + v4 - 4);
          *(float *)((char *)&v25[3] + v4) =
              *(float *)((char *)&v24[4095] + v4);
          ++v8;
          v4 += 4;
          ++v7;
        }
      while (v8 != 5);
      v9 = skel + 48;
        if (a1->tree) {
          v26 |= 0x80000000;
          XAnimCalc((int **)a1, 0, (float *)(skel + 48), 1.0, (const DObj_s *)1,
                    0, COERCE_FLOAT(v24), 0);
        }
        if (a1->numModels) {
          v22 = a1;
          v10 = 0;
          v21 = 0;
          v11 = **(__int16 ***)a1->models;
          v12 = v11[1];
          v13 = v12;
          if (v12)
            goto LABEL_20;
        LABEL_12:
          v14 = v10;
            while (1) {
              v15 = (__int16 *)*((_DWORD *)v11 + 2);
              v23 = *v11 - v11[1];
                if (v23) {
                  v16 = 0;
                  v17 = v15;
                    do {
                        if ((((int)v25[v14 >> 5] >> (v14 & 0x1F)) & 1) == 0) {
                          *(float *)v9 = (float)*v17 * 0.000030518509;
                          *(float *)(v9 + 4) = (float)v17[1] * 0.000030518509;
                          *(float *)(v9 + 8) = (float)v17[2] * 0.000030518509;
                          *(float *)(v9 + 12) = (float)v17[3] * 0.000030518509;
                          *(_DWORD *)(v9 + 16) = 0;
                          *(_DWORD *)(v9 + 20) = 0;
                          *(_DWORD *)(v9 + 24) = 0;
                        }
                      v9 += 32;
                      ++v14;
                      ++v16;
                      v17 += 4;
                    }
                  while (v23 != v16);
                }
              ++v21;
              v22 = (DObj_s *)((char *)v22 + 4);
              if (a1->numModels <= v21)
                break;
              v10 = v14;
              v11 = **(__int16 ***)v22->models;
              v18 = v11[1];
              v13 = v18;
              if (!v18)
                goto LABEL_12;
            LABEL_20:
              v14 = v10;
              v19 = v10 + v13;
                do {
                    if ((((int)v25[v14 >> 5] >> (v14 & 0x1F)) & 1) == 0) {
                      *(_DWORD *)v9 = 0;
                      *(_DWORD *)(v9 + 4) = 0;
                      *(_DWORD *)(v9 + 8) = 0;
                      *(_DWORD *)(v9 + 12) = 1065353216;
                      *(_DWORD *)(v9 + 16) = 0;
                      *(_DWORD *)(v9 + 20) = 0;
                      *(_DWORD *)(v9 + 24) = 0;
                    }
                  v9 += 32;
                  ++v14;
                }
              while (v14 != v19);
            }
        }
    }
}

int __cdecl DObjUpdateServerInfo(struct DObj_s *obj, float dtime, int bNotify)
{
  int32_t result; // eax
  float v4;       // xmm0_4
  float v5;       // xmm0_4

  result = a1->tree;
    if (a1->tree) {
        if (a3) {
          v4 = COERCE_FLOAT(XAnimFindServerNoteTrack((_DWORD *)result, 0, a2));
            if (v4 == 1.0 || (v5 = (float)(v4 * a2) + 0.001, a2 < v5)) {
              XAnimUpdateInfoInternal((char **)a1->tree, 0, 1u, a2);
              return 0;
            }
            else {
              XAnimUpdateInfoInternal((char **)a1->tree, 0, 1u, v5);
              return 1;
            }
        }
        else {
          XAnimUpdateInfoInternal((char **)result, 0, 0, a2);
          return 0;
        }
    }
  return result;
}

void __cdecl DObjUpdateClientInfo(struct DObj_s *obj, float dtime)
{
  int v2;      // [esp+10h] [ebp-28h] BYREF
  __int16 v3;  // [esp+18h] [ebp-20h]
  float v4[2]; // [esp+2Eh] [ebp-Ah] BYREF

  g_notifyListSize = 0;
    if (a1->tree) {
      v2 = 0;
      v3 = 0;
      XAnimUpdateOldTime(a1->tree, 0, &v2, a2, (XAnimTree_s *)1,
                         (_BYTE *)v4 + 1, (XAnimState *)v4);
      XAnimUpdateInfoInternal((char **)a1->tree, 0, 1u, a2);
    }
}

int marker_xanim;

void __cdecl XAnim_GetTimeIndexCompressed<unsigned short>(
    struct XAnimTime const *, unsigned short const *, int, int *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_GetTimeIndexCompressed<unsigned char>(
    struct XAnimTime const *, unsigned char const *, int, int *, float *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_GetTimeIndex<unsigned short>(
    struct XAnimTime const *, union XAnimDynamicIndices const *, int, int *,
    float *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_GetTimeIndex<unsigned char>(
    struct XAnimTime const *, union XAnimDynamicIndices const *, int, int *,
    float *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCloneClientAnimInfo(struct XAnimInfo const *,
                                      struct XAnimInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimSetAnimRateInternal(struct XAnimTree_s *, unsigned int, float)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl XAnimGetDescendantWithGreatestWeight(
    struct XAnimTree_s const *, unsigned int)
{
  UNIMPLEMENTED();
}

bool __cdecl XAnimInitTime(struct XAnimInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimInitInfo(struct XAnimInfo *)
{
  UNIMPLEMENTED();
}

float __cdecl XAnimGetNotifyFracLeaf(struct XAnimState const *,
                                     struct XAnimState const *, float, float)
{
  UNIMPLEMENTED();
}

unsigned short __cdecl XAnimGetNextNotifyTime(struct XAnimEntry const *, float)
{
  UNIMPLEMENTED();
}

float __cdecl XAnimGetAverageRateFrequency(struct XAnimTree_s const *,
                                           unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl TransformToQuatRefFrame(float const *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_SetTime(float, int, struct XAnimTime *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaDuringInternal<unsigned short>(
    struct XAnimDeltaPartTrans const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaDuringInternal<unsigned char>(
    struct XAnimDeltaPartTrans const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaDuring<unsigned short>(
    struct XAnimDeltaPart const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaDuring<unsigned char>(
    struct XAnimDeltaPart const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimUpdateServerNotify(struct XAnimTree_s const *,
                                     struct XAnimInfo *,
                                     struct XAnimEntry const *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimResetTime(struct XAnimTree_s *, unsigned int)
{
  UNIMPLEMENTED();
}

float __cdecl XAnimGetNotifyFracServer(struct XAnimTree_s const *,
                                       struct XAnimInfo *,
                                       struct XAnimEntry const *,
                                       struct XAnimState const *,
                                       struct XAnimState const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaEntireInternal(
    struct XAnimDeltaPartTrans const *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaEntireInternal(struct XAnimDeltaPartQuat const *,
                                              float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearData(struct DObj_s const *, struct DObjAnimMat_s *,
                            struct XAnimCalcAnimInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosEnd(struct XAnimPartTrans *, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotEnd(struct XAnimPartQuat const *, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcSimpleRotEnd(struct XAnimPartQuat const *, float,
                                    float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDuring<unsigned short>(struct XAnimTime const *,
                                                 struct XAnimPartTrans const *,
                                                 float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDuring<unsigned short>(struct XAnimTime const *,
                                                 struct XAnimPartQuat const *,
                                                 float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcSimpleRotDuring<unsigned short>(
    struct XAnimTime const *, struct XAnimPartQuat const *, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDuring<unsigned char>(struct XAnimTime const *,
                                                struct XAnimPartTrans const *,
                                                float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDuring<unsigned char>(struct XAnimTime const *,
                                                struct XAnimPartQuat const *,
                                                float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcSimpleRotDuring<unsigned char>(
    struct XAnimTime const *, struct XAnimPartQuat const *, float, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaDuringInternal<unsigned short>(
    struct XAnimDeltaPartQuat const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaDuringInternal<unsigned char>(
    struct XAnimDeltaPartQuat const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcParts<unsigned short>(struct XAnimParts_s const *,
                                            unsigned char const *, float, float,
                                            struct DObjAnimMat_s *, int *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcParts<unsigned char>(struct XAnimParts_s const *,
                                           unsigned char const *, float, float,
                                           struct DObjAnimMat_s *, int *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaDuring<unsigned short>(
    struct XAnimDeltaPart const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaDuring<unsigned char>(
    struct XAnimDeltaPart const *, float, int, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCloneAnimInfo(struct XAnimInfo const *, struct XAnimInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimRestart(struct XAnimTree_s *, unsigned int)
{
  UNIMPLEMENTED();
}

bool __cdecl XAnimIsDefault(struct XAnimParts_s *)
{
  UNIMPLEMENTED();
}

float __cdecl XAnimGetServerNotifyFracSyncTotal(
    struct XAnimTree_s const *, struct XAnimInfo *, struct XAnimEntry const *,
    struct XAnimState const *, struct XAnimState const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimAddClientNotify(struct XAnimEntry const *, unsigned int,
                                  float, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcPosDeltaEntire(struct XAnimDeltaPart const *,
                                      float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcRotDeltaEntire(struct XAnimDeltaPart const *,
                                      float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcNonLoopEnd(struct XAnimParts_s const *,
                                 unsigned char const *, float,
                                 struct DObjAnimMat_s *, int *const)
{
  UNIMPLEMENTED();
}

float __cdecl XAnimFindServerNoteTrack(struct XAnimTree_s const *, unsigned int,
                                       float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimProcessClientNotify(struct XAnimInfo *,
                                      struct XAnimEntry const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnim_CalcDeltaForTime(struct XAnimParts_s const *, float,
                                    float *const, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcAbsDeltaParts(struct XAnimParts_s const *, float, float,
                                    struct XAnimSimpleRotPos *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcRelDeltaParts(struct XAnimParts_s const *, float, float,
                                    float, struct XAnimSimpleRotPos *, int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimCalcDeltaTree(struct XAnimTree_s const *, unsigned int, float,
                                bool, bool, struct XAnimSimpleRotPos *)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl XAnimSetModel(struct XAnimEntry const *,
                                   struct XModel *const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearServerNotify(struct XAnimInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimFreeInfo(struct XAnimTree_s *, unsigned int)
{
  UNIMPLEMENTED();
}

struct XAnimParts_s *__cdecl XAnimFindData(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearTreeWeights(struct XAnimTree_s *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimClearGoalWeightKnobInternal(struct XAnimTree_s *,
                                              unsigned int, float, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimUpdateOldTime(struct XAnimTree_s *, unsigned int,
                                struct XAnimState *, float, bool, bool *,
                                bool *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimFillInSyncNodes_r(struct XAnim_s *, unsigned int, bool)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimTransfer(struct XAnimTree_s const *, struct XAnimTree_s *)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimSetupSyncNodes_r(struct XAnim_s *, unsigned int)
{
  UNIMPLEMENTED();
}

int __cdecl XAnimSetGoalWeightInternal(struct XAnimTree_s *, unsigned int,
                                       float, float, float, bool, unsigned int,
                                       unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimEnsureGoalWeightParent(struct XAnimTree_s *, unsigned int,
                                         float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimDisplay(struct XAnimTree_s const *, unsigned int, int)
{
  unsigned __int16 v4;    // dx
  int v5;                 // ecx
  float *v6;              // edi
  int v7;                 // edx
  int v8;                 // ebx
  int v9;                 // eax
  float v10;              // xmm3_4
  float v11;              // xmm2_4
  const char *v12;        // ebx
  float v13;              // xmm5_4
  float v14;              // xmm1_4
  float v15;              // xmm0_4
  unsigned __int16 v16;   // ax
  const char *v17;        // eax
  unsigned __int16 v18;   // cx
  int v19;                // eax
  int v21;                // ebx
  int v22;                // eax
  int i;                  // ebx
  const char *v25;        // eax
  const XAnimTree_s *v26; // [esp+0h] [ebp-88h]
  unsigned int v27;       // [esp+4h] [ebp-84h]
  int v28;                // [esp+8h] [ebp-80h]
  __int16 v31;            // [esp+56h] [ebp-32h]
  int v32;                // [esp+58h] [ebp-30h]
  unsigned __int16 *v33;  // [esp+5Ch] [ebp-2Ch]
  int *v34;               // [esp+60h] [ebp-28h]
  char *v35;              // [esp+64h] [ebp-24h]
  double v36;             // [esp+68h] [ebp-20h]

  v4 = *((_WORD *)a1 + a2 + 4);
  if (!v4)
    return;
  v5 = *a1;
  v33 = (unsigned __int16 *)(*a1 + 8 * a2 + 12);
  v31 = *v33;
  v32 = *v33;
  v34 = &g_xAnimInfo[10 * v4];
  v6 = (float *)(v34 + 3);
    if (a3 <= 0) {
      v7 = v5 + 8 * a2;
      v8 = v7 + 12;
      v9 = *(_DWORD *)(v5 + 8);
      if (v9)
        goto LABEL_4;
    LABEL_28:
      if (*(_WORD *)(v7 + 12))
        v35 = va("%i", a2);
      else
        v35 = *(char **)(*(_DWORD *)(v8 + 4) + 36);
    LABEL_5:
      v10 = *((float *)v34 + 8);
      v11 = *((float *)v34 + 7);
      if (v11 > v10)
        goto LABEL_6;
    LABEL_13:
      v12 = "^1";
      if (v10 <= v11)
        v12 = (const char *)&inData;
        if (!v31) {
        LABEL_7:
          v13 = *((float *)v34 + 4);
          v14 = *v6 - v13;
          if (v14 < 0.0)
            v14 = v14 + 1.0;
          v15 = *(float *)(*((_DWORD *)v33 + 1) + 8);
            if (v15 == 0.0) {
              v36 = 0.0;
              v16 = *((_WORD *)v34 + 2);
                if (v16) {
                LABEL_11:
                  v17 = (const char *)SL_ConvertToString(v16);
                  Com_Printf(
                      "%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, "
                      "(realtimedelta) %.2f, '%s'\n",
                      v12, v35, *((float *)v34 + 8), *((float *)v34 + 7),
                      *((float *)v34 + 4), *((float *)v34 + 3), v36, v17);
                  return;
                }
            }
            else {
              v36 = (float)(v14 / v15);
              v16 = *((_WORD *)v34 + 2);
              if (v16)
                goto LABEL_11;
            }
          Com_Printf("%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f, "
                     "(realtimedelta) %.2f\n",
                     v12, v35, v10, v11, v13, *v6, v36);
          return;
        }
      goto LABEL_16;
    }
  v21 = 0;
    do {
      Com_Printf(" ");
      ++v21;
    }
  while (a3 != v21);
  v7 = *a1 + 8 * a2;
  v8 = v7 + 12;
  v9 = *(_DWORD *)(*a1 + 8);
  if (!v9)
    goto LABEL_28;
LABEL_4:
  v35 = *(char **)(v9 + 4 * a2);
  if (*(_WORD *)(v7 + 12) || !*(_BYTE *)(*(_DWORD *)(v8 + 4) + 40))
    goto LABEL_5;
  v35 = va("^3%s (missing)", v35);
  v10 = *((float *)v34 + 8);
  v11 = *((float *)v34 + 7);
  if (v11 <= v10)
    goto LABEL_13;
LABEL_6:
  v12 = "^4";
  if (!v31)
    goto LABEL_7;
LABEL_16:
  v18 = *((_WORD *)v34 + 2);
    if (v18) {
      v22 = *a1 + 8 * a2;
        if (!*(_WORD *)(v22 + 12) || (*(_BYTE *)(v22 + 16) & 3) != 0) {
          SL_ConvertToString(v18);
          v28 = (int)v35;
          v27 = (unsigned int)v12;
          Com_Printf((char *)&stru_2179B8);
        }
        else {
          v25 = (const char *)SL_ConvertToString(v18);
          Com_Printf("%s%s: (weight) %.2f -> %.2f, '%s'\n", v12, v35,
                     *((float *)v34 + 8), *((float *)v34 + 7), v25);
        }
    }
    else {
      v19 = *a1 + 8 * a2;
      if (!*(_WORD *)(v19 + 12) || (*(_BYTE *)(v19 + 16) & 3) != 0)
        Com_Printf("%s%s: (weight) %.2f -> %.2f, (time) %.2f -> %.2f\n", v12,
                   v35, v10, v11, *((float *)v34 + 4), *((float *)v34 + 3));
      else
        Com_Printf("%s%s: (weight) %.2f -> %.2f\n", v12, v35, v10, v11);
    }
    if (v32 > 0) {
      for (i = 0; i != v32; ++i)
        XAnimDisplay(v26, v27, v28);
    }
}

void __cdecl XAnimCalc(struct DObj_s const *, unsigned int, float,
                       struct DObjAnimMat_s *, bool, bool,
                       struct XAnimCalcAnimInfo *, int)
{
  int v8;                  // edx
  int v9;                  // edi
  int *v10;                // ecx
  _BYTE *v11;              // edx
  int v12;                 // eax
  int v13;                 // eax
  int j;                   // edx
  int v15;                 // edi
  char *v16;               // edx
  int v17;                 // ebx
  __int16 *v18;            // edx
  int v19;                 // ecx
  int v20;                 // esi
  int v21;                 // edx
  int v22;                 // ecx
  int v23;                 // ebx
  int v24;                 // eax
  unsigned int v25;        // esi
  float v26;               // edx
  _DWORD *v27;             // ecx
  int k;                   // ebx
  unsigned __int16 *v29;   // ecx
  float v30;               // xmm1_4
  unsigned __int16 v31;    // ax
  float v32;               // xmm3_4
  unsigned __int16 *v33;   // ebx
  unsigned __int16 *v34;   // ebx
  float *v35;              // edi
  unsigned __int16 *v36;   // ebx
  int v37;                 // ebx
  float *v38;              // ebx
  int v39;                 // esi
  int v40;                 // esi
  _WORD *v41;              // ebx
  int v42;                 // ecx
  int v43;                 // ebx
  int v44;                 // eax
  float v45;               // xmm1_4
  int ii;                  // esi
  unsigned __int16 *v47;   // eax
  __int16 *v48;            // edx
  unsigned __int16 *v49;   // edx
  float *v50;              // eax
  float v51;               // xmm0_4
  float *v52;              // ebx
  int v53;                 // edi
  unsigned __int16 *v54;   // eax
  __int16 *v55;            // edx
  int v56;                 // eax
  int v57;                 // eax
  int v58;                 // eax
  int i;                   // edx
  int v60;                 // edi
  char *v61;               // edx
  int v62;                 // ebx
  __int16 *v63;            // edx
  int v64;                 // ecx
  int v65;                 // esi
  int v66;                 // edx
  int v67;                 // ecx
  int v68;                 // ebx
  int v69;                 // eax
  float v70;               // xmm3_4
  unsigned __int16 *v71;   // ebx
  unsigned __int16 v72;    // ax
  unsigned __int16 *v73;   // ebx
  unsigned __int16 v74;    // ax
  float *v75;              // edi
  unsigned __int16 *v76;   // ebx
  unsigned __int16 v77;    // ax
  float v78;               // eax
  float v79;               // xmm2_4
  float *v80;              // eax
  float v81;               // xmm2_4
  float *v82;              // eax
  int v83;                 // ecx
  _WORD *v84;              // ecx
  int v85;                 // ebx
  float v86;               // xmm2_4
  float v87;               // ecx
  __int16 *v88;            // ecx
  float v89;               // xmm2_4
  int v90;                 // edx
  __int16 *v91;            // edx
  float v92;               // xmm2_4
  __int16 *v93;            // ecx
  float v94;               // xmm2_4
  __int16 *v95;            // edx
  float *v96;              // esi
  int v97;                 // ebx
  unsigned __int16 v98;    // ax
  int v99;                 // edx
  float v100;              // xmm1_4
  int v101;                // ebx
  float v102;              // xmm3_4
  float v103;              // xmm1_4
  float v104;              // xmm0_4
  int v105;                // ebx
  float v106;              // xmm3_4
  float v107;              // xmm1_4
  float v108;              // xmm0_4
  unsigned __int8 v109;    // [esp+10h] [ebp-198h]
  unsigned __int8 v110;    // [esp+10h] [ebp-198h]
  unsigned __int8 v111;    // [esp+10h] [ebp-198h]
  unsigned __int8 v112;    // [esp+14h] [ebp-194h]
  unsigned __int8 v113;    // [esp+14h] [ebp-194h]
  unsigned __int8 v114;    // [esp+14h] [ebp-194h]
  XAnimCalcAnimInfo *v115; // [esp+18h] [ebp-190h]
  XAnimCalcAnimInfo *v116; // [esp+18h] [ebp-190h]
  XAnimCalcAnimInfo *v117; // [esp+18h] [ebp-190h]
  int v118;                // [esp+1Ch] [ebp-18Ch]
  int v119;                // [esp+1Ch] [ebp-18Ch]
  int v120;                // [esp+1Ch] [ebp-18Ch]
  float *v121;             // [esp+30h] [ebp-178h]
  int v125;                // [esp+40h] [ebp-168h]
  unsigned __int16 *v126;  // [esp+44h] [ebp-164h]
  int *v127;               // [esp+48h] [ebp-160h]
  unsigned __int16 *v128;  // [esp+4Ch] [ebp-15Ch]
  int v129;                // [esp+50h] [ebp-158h]
  int v130;                // [esp+5Ch] [ebp-14Ch]
  int v131;                // [esp+60h] [ebp-148h]
  int v132;                // [esp+64h] [ebp-144h]
  int v133;                // [esp+68h] [ebp-140h]
  int v134;                // [esp+6Ch] [ebp-13Ch]
  size_t __n;              // [esp+70h] [ebp-138h]
  int v136;                // [esp+74h] [ebp-134h]
  int v137;                // [esp+78h] [ebp-130h]
  int v138;                // [esp+84h] [ebp-124h]
  int v139;                // [esp+88h] [ebp-120h]
  int v140;                // [esp+8Ch] [ebp-11Ch]
  int v141;                // [esp+90h] [ebp-118h]
  int v142;                // [esp+94h] [ebp-114h]
  size_t v143;             // [esp+98h] [ebp-110h]
  int v144;                // [esp+9Ch] [ebp-10Ch]
  unsigned int v145;       // [esp+A4h] [ebp-104h]
  int v146;                // [esp+A8h] [ebp-100h]
  int v147;                // [esp+ACh] [ebp-FCh]
  unsigned int v148;       // [esp+B4h] [ebp-F4h]
  int n;                   // [esp+B8h] [ebp-F0h]
  int v150;                // [esp+BCh] [ebp-ECh]
  int v151;                // [esp+C0h] [ebp-E8h]
  int v152;                // [esp+C4h] [ebp-E4h]
  unsigned int v153;       // [esp+CCh] [ebp-DCh]
  int m;                   // [esp+D0h] [ebp-D8h]
  unsigned __int16 **v155; // [esp+D4h] [ebp-D4h]
  int v156;                // [esp+D8h] [ebp-D0h]
  int v157;                // [esp+DCh] [ebp-CCh]
  _WORD *v158;             // [esp+E0h] [ebp-C8h]
  _WORD *v159;             // [esp+E4h] [ebp-C4h]
  int v160;                // [esp+ECh] [ebp-BCh]
  int __src;               // [esp+F8h] [ebp-B0h] BYREF
  int v162;                // [esp+FCh] [ebp-ACh]
  float v163;              // [esp+100h] [ebp-A8h]
  _DWORD v164[33];         // [esp+104h] [ebp-A4h] BYREF
  float v165;              // [esp+188h] [ebp-20h] BYREF
  int v166[7];             // [esp+18Ch] [ebp-1Ch] BYREF

  v121 = a3;
  v127 = *a1;
  v8 = **a1;
  v126 = (unsigned __int16 *)(v8 + 8 * a2 + 12);
  v9 = *v126;
    if (*v126) {
      v40 = *(unsigned __int16 *)(**a1 + 8 * a2 + 18);
      v41 = (_WORD *)v127 + v40 + 4;
      v42 = 0;
        while (!*v41 || flt_3BE020[10 * (unsigned __int16)*v41] == 0.0) {
          ++v42;
          ++v41;
            if (v9 == v42) {
                if ((_BYTE)a5 && *((_BYTE *)a1 + 25)) {
                  v37 = 0;
                    do {
                        if (((*(int *)(LODWORD(a7) + 4 * (v37 >> 5) + 16400) >>
                              (v37 & 0x1F)) &
                             1) == 0) {
                          *v121 = 0.0;
                          v121[1] = 0.0;
                          v121[2] = 0.0;
                          v121[3] = 0.0;
                          v121[7] = 0.0;
                          v121[4] = 0.0;
                          v121[5] = 0.0;
                          v121[6] = 0.0;
                        }
                      ++v37;
                      v121 += 8;
                    }
                  while (v37 < *((unsigned __int8 *)a1 + 25));
                }
              return;
            }
        }
      v83 = v42 + 1;
      v160 = v83;
        if (v9 <= v83) {
        LABEL_129:
          XAnimCalc((const DObj_s *)(unsigned __int8)a5, a6, a7, a8, v109, v112,
                    v115, v118);
          return;
        }
      v84 = (_WORD *)v127 + v40 + v83 + 4;
      v85 = v160;
        while (!*v84 || flt_3BE020[10 * (unsigned __int16)*v84] == 0.0) {
          ++v85;
          ++v84;
          if (v85 == v9)
            goto LABEL_129;
        }
        if ((_BYTE)a5) {
          v96 = v121;
        }
        else {
          v96 = (float *)(32 * (_DWORD)a8 + LODWORD(a7));
          a8 = (DObjAnimMat_s *)((char *)a8 + *((unsigned __int8 *)a1 + 25));
            if ((int)a8 > 512) {
              Com_Printf("MAX_CALC_ANIM_BUFFER exceeded\n");
              return;
            }
        }
      XAnimCalc((const DObj_s *)1, 1, a7, a8, v109, v112, v115, v118);
      XAnimCalc(0, 1, a7, a8, v110, v113, v116, v119);
        if (v9 > v85 + 1) {
          v97 = v85 + 1;
            do {
              v98 = *((_WORD *)v127 + v97 + v126[3] + 4);
              if (v98 && flt_3BE020[10 * v98] != 0.0)
                XAnimCalc(0, 1, a7, a8, v111, v114, v117, v120);
              ++v97;
            }
          while (v9 != v97);
        }
        if (a6) {
            if ((_BYTE)a5) {
                if (*((_BYTE *)a1 + 25)) {
                  v101 = 0;
                    do {
                        if (((*(int *)(LODWORD(a7) + 4 * (v101 >> 5) + 16400) >>
                              (v101 & 0x1F)) &
                             1) == 0) {
                          v102 = (float)((float)((float)(*v121 * *v121) +
                                                 (float)(v121[1] * v121[1])) +
                                         (float)(v121[2] * v121[2])) +
                                 (float)(v121[3] * v121[3]);
                            if (v102 != 0.0) {
                              v166[0] = 1597463007 - (SLODWORD(v102) >> 1);
                              v165 =
                                  (float)(1.5 -
                                          (float)((float)((float)(v102 * 0.5) *
                                                          *(float *)v166) *
                                                  *(float *)v166)) *
                                  *(float *)v166;
                              v103 = a4 * v165;
                              *v121 = (float)(a4 * v165) * *v121;
                              v121[1] = v103 * v121[1];
                              v121[2] = v103 * v121[2];
                              v121[3] = v103 * v121[3];
                            }
                          v104 = v121[7];
                            if (v104 != 0.0) {
                              v121[4] = (float)(a4 / v104) * v121[4];
                              v121[5] = (float)(a4 / v104) * v121[5];
                              v121[6] = (float)(a4 / v104) * v121[6];
                              v121[7] = a4;
                            }
                        }
                      ++v101;
                      v121 += 8;
                    }
                  while (v101 < *((unsigned __int8 *)a1 + 25));
                }
            }
            else if (*((_BYTE *)a1 + 25)) {
              v105 = 0;
                do {
                    if (((*(int *)(LODWORD(a7) + 4 * (v105 >> 5) + 16400) >>
                          (v105 & 0x1F)) &
                         1) == 0) {
                      v106 = (float)((float)((float)(*v96 * *v96) +
                                             (float)(v96[1] * v96[1])) +
                                     (float)(v96[2] * v96[2])) +
                             (float)(v96[3] * v96[3]);
                        if (v106 != 0.0) {
                          LODWORD(v165) = 1597463007 - (SLODWORD(v106) >> 1);
                          *(float *)v166 =
                              (float)(1.5 -
                                      (float)((float)((float)(v106 * 0.5) *
                                                      v165) *
                                              v165)) *
                              v165;
                          v107 = a4 * *(float *)v166;
                          *v121 = (float)((float)(a4 * *(float *)v166) * *v96) +
                                  *v121;
                          v121[1] = (float)(v107 * v96[1]) + v121[1];
                          v121[2] = (float)(v107 * v96[2]) + v121[2];
                          v121[3] = (float)(v107 * v96[3]) + v121[3];
                        }
                      v108 = v96[7];
                        if (v108 != 0.0) {
                          v121[4] =
                              (float)((float)(a4 / v108) * v96[4]) + v121[4];
                          v121[5] =
                              (float)((float)(a4 / v108) * v96[5]) + v121[5];
                          v121[6] =
                              (float)((float)(a4 / v108) * v96[6]) + v121[6];
                          v121[7] = a4 + v121[7];
                        }
                    }
                  ++v105;
                  v121 += 8;
                  v96 += 8;
                }
              while (v105 < *((unsigned __int8 *)a1 + 25));
            }
        }
        else if (*((_BYTE *)a1 + 25)) {
          v99 = 0;
            do {
                if (((*(int *)(LODWORD(a7) + 4 * (v99 >> 5) + 16400) >>
                      (v99 & 0x1F)) &
                     1) == 0) {
                  v100 = v121[7];
                    if (v100 != 0.0) {
                      *v121 = (float)(1.0 / v100) * *v121;
                      v121[1] = (float)(1.0 / v100) * v121[1];
                      v121[2] = (float)(1.0 / v100) * v121[2];
                      v121[3] = (float)(1.0 / v100) * v121[3];
                      v121[4] = (float)(1.0 / v100) * v121[4];
                      v121[5] = (float)(1.0 / v100) * v121[5];
                      v121[6] = (float)(1.0 / v100) * v121[6];
                    }
                }
              ++v99;
              v121 += 8;
            }
          while (v99 < *((unsigned __int8 *)a1 + 25));
        }
    }
    else {
        if ((_BYTE)a5 && *((_BYTE *)a1 + 25)) {
          v38 = a3;
          v39 = 0;
            do {
                if (((*(int *)(LODWORD(a7) + 4 * (v39 >> 5) + 16400) >>
                      (v39 & 0x1F)) &
                     1) == 0) {
                  *v38 = 0.0;
                  v38[1] = 0.0;
                  v38[2] = 0.0;
                  v38[3] = 0.0;
                  v38[7] = 0.0;
                  v38[4] = 0.0;
                  v38[5] = 0.0;
                  v38[6] = 0.0;
                }
              ++v39;
              v38 += 8;
            }
          while (*((unsigned __int8 *)a1 + 25) > v39);
          v8 = *v127;
        }
      v10 = a1[3];
      v11 = (char *)v10 + 2 * *(_DWORD *)(v8 + 4);
      v125 = 2 * a2;
        if (*((_WORD *)v10 + a2)) {
            if (v11[a2 + 1] != *v11) {
              v11[a2 + 1] = *v11;
              SL_RemoveRefToStringOfLen(
                  a4, *(unsigned __int16 *)((char *)a1[3] + v125),
                  *(__int16 *)(*((_DWORD *)v126 + 1) + 14) + 16);
              v158 = (_WORD *)((char *)a1[3] + v125);
              v137 = *((unsigned __int8 *)a1 + 24);
              v57 = *((_DWORD *)v126 + 1);
              v141 = *(_DWORD *)(v57 + 16);
              v58 = *(__int16 *)(v57 + 14);
              v143 = v58 + 16;
              for (i = 0; i != 4; ++i)
                *(&__src + i) = 0;
              v60 = v58 - 1;
                if (v58 - 1 >= 0) {
                  v61 = (char *)v164 + v58 + 3;
                  do
                    *v61-- = 127;
                  while ((char *)v164 + 3 != v61);
                }
                if (v137 > 0) {
                  v144 = 0;
                  v138 = 0;
                  v62 = 0;
                    do {
                      v63 = (__int16 *)*a1[v62 + 7];
                      v142 = **((_DWORD **)v63 + 1);
                      v140 = *v63;
                        if (v140 > 0) {
                          v139 = 0;
                          v64 = 0;
                            do {
                              v65 = *(unsigned __int16 *)(v142 + 2 * v64);
                                if (v60 >= 0) {
                                    if (*(unsigned __int16 *)(2 * v60 + v141) ==
                                        v65) {
                                      v67 = v60;
                                        if (*((_BYTE *)&v164[1] + v60) == 127) {
                                        LABEL_104:
                                          *((_BYTE *)&v164[1] + v67) = v138;
                                          *(&__src + (v138 >> 5)) |=
                                              1 << (v138 & 0x1F);
                                        }
                                    }
                                    else {
                                      v66 = v141 + 2 * v60;
                                      v67 = v60;
                                      v68 = 0;
                                        while (1) {
                                          --v67;
                                          if (v60 == v68)
                                            break;
                                          v69 = *(unsigned __int16 *)(v66 - 2);
                                          ++v68;
                                          v66 -= 2;
                                            if (v69 == v65) {
                                              if (*((_BYTE *)&v164[1] + v67) ==
                                                  127)
                                                goto LABEL_104;
                                              break;
                                            }
                                        }
                                    }
                                }
                              ++v139;
                              ++v138;
                              v64 = v139;
                            }
                          while (v140 != v139);
                        }
                      v62 = ++v144;
                    }
                  while (v137 != v144);
                }
              *v158 = SL_GetStringOfLen((char *)&__src, 0, v143);
              v10 = a1[3];
            }
        }
        else {
          v11[a2 + 1] = *v11;
          v159 = (_WORD *)a1[3] + a2;
          v129 = *((unsigned __int8 *)a1 + 24);
          v12 = *((_DWORD *)v126 + 1);
          v133 = *(_DWORD *)(v12 + 16);
          v13 = *(__int16 *)(v12 + 14);
          __n = v13 + 16;
          for (j = 0; j != 4; ++j)
            *(&__src + j) = 0;
          v15 = v13 - 1;
            if (v13 - 1 >= 0) {
              v16 = (char *)v164 + v13 + 3;
              do
                *v16-- = 127;
              while ((char *)v164 + 3 != v16);
            }
            if (v129 > 0) {
              v136 = 0;
              v130 = 0;
              v17 = 0;
                do {
                  v18 = (__int16 *)*a1[v17 + 7];
                  v134 = **((_DWORD **)v18 + 1);
                  v132 = *v18;
                    if (v132 > 0) {
                      v131 = 0;
                      v19 = 0;
                        do {
                          v20 = *(unsigned __int16 *)(v134 + 2 * v19);
                            if (v15 >= 0) {
                                if (*(unsigned __int16 *)(2 * v15 + v133) ==
                                    v20) {
                                  v22 = v15;
                                    if (*((_BYTE *)&v164[1] + v15) == 127) {
                                    LABEL_102:
                                      *((_BYTE *)&v164[1] + v22) = v130;
                                      *(&__src + (v130 >> 5)) |=
                                          1 << (v130 & 0x1F);
                                    }
                                }
                                else {
                                  v21 = v133 + 2 * v15;
                                  v22 = v15;
                                  v23 = 0;
                                    while (1) {
                                      --v22;
                                      if (v15 == v23)
                                        break;
                                      v24 = *(unsigned __int16 *)(v21 - 2);
                                      ++v23;
                                      v21 -= 2;
                                        if (v24 == v20) {
                                          if (*((_BYTE *)&v164[1] + v22) == 127)
                                            goto LABEL_102;
                                          break;
                                        }
                                    }
                                }
                            }
                          ++v131;
                          ++v130;
                          v19 = v131;
                        }
                      while (v132 != v131);
                    }
                  v17 = ++v136;
                }
              while (v129 != v136);
            }
          *v159 = SL_GetStringOfLen((char *)&__src, 0, __n);
          v10 = a1[3];
        }
      v25 = SL_ConvertToString(*(unsigned __int16 *)((char *)v10 + v125));
      v26 = a7;
      v27 = (_DWORD *)v25;
        for (k = 0; k != 4; ++k) {
          *(_DWORD *)(LODWORD(v26) + 0x4000) |=
              *v27 & ~*(_DWORD *)(LODWORD(v26) + 16400);
          LODWORD(v26) += 4;
          ++v27;
        }
      v29 = (unsigned __int16 *)*((_DWORD *)v126 + 1);
      v128 = v29;
      v30 = *(float *)&dword_3BE00C[10 * *((unsigned __int16 *)v127 + a2 + 4)];
        if (v30 == 1.0) {
          v43 = *((_DWORD *)v126 + 1);
          v44 = v43;
        }
        else {
          v31 = *v29;
            if (*v29) {
                if (v31 > 0xFFu) {
                  v153 = v25 + 16;
                  __src =
                      dword_3BE00C[10 * *((unsigned __int16 *)v127 + a2 + 4)];
                  v162 = v31;
                  v163 = (float)v31 * v30;
                  v164[0] = (int)v163;
                  v70 = a4 * 0.000030518509;
                  v157 = *((_DWORD *)v29 + 5);
                  v156 = (__int16)v29[7];
                    if (v156 > 0) {
                        for (m = 0; m != v156; ++m) {
                            if (((*(int *)(LODWORD(a7) + 16400 +
                                           4 * ((int)*(unsigned __int8 *)(v153 +
                                                                          m) >>
                                                5)) >>
                                  (*(_BYTE *)(v153 + m) & 0x1F)) &
                                 1) == 0) {
                              v75 = &v121[8 * *(unsigned __int8 *)(v153 + m)];
                              v155 =
                                  (unsigned __int16 **)(*((_DWORD *)v128 + 6) +
                                                        8 * m);
                                if (((*(char *)(v157 + (m >> 3)) >> (m & 7)) &
                                     1) != 0) {
                                  v71 = v155[1];
                                    if (v71) {
                                      v72 = *v71;
                                        if (*v71) {
                                            if (v72 < v162) {
                                              XAnim_GetTimeIndexCompressed<
                                                  unsigned short>(
                                                  (int)&__src, (int)(v71 + 4),
                                                  v72, v166, &v165);
                                              v89 = v165;
                                              v90 = v166[0];
                                            }
                                            else {
                                              v165 = v163 - (float)v164[0];
                                              v166[0] = v164[0];
                                              v89 = v165;
                                              v90 = v164[0];
                                            }
                                          v91 =
                                              (__int16 *)(*((_DWORD *)v71 + 1) +
                                                          4 * v90);
                                          v75[2] =
                                              (float)((float)((float)*v91 +
                                                              (float)((float)(v91[2] -
                                                                              *v91) *
                                                                      v89)) *
                                                      v70) +
                                              v75[2];
                                          v75[3] =
                                              (float)((float)((float)v91[1] +
                                                              (float)(v89 *
                                                                      (float)(v91[3] -
                                                                              v91[1]))) *
                                                      v70) +
                                              v75[3];
                                        }
                                        else {
                                          v75[2] =
                                              (float)((float)(__int16)v71[2] *
                                                      v70) +
                                              v75[2];
                                          v75[3] =
                                              (float)((float)(__int16)v71[3] *
                                                      v70) +
                                              v75[3];
                                        }
                                    }
                                    else {
                                      v75[3] = a4 + v75[3];
                                    }
                                }
                                else {
                                  v76 = v155[1];
                                  v77 = *v76;
                                    if (*v76) {
                                        if (v77 < v162) {
                                          XAnim_GetTimeIndexCompressed<
                                              unsigned short>(
                                              (int)&__src, (int)(v76 + 4), v77,
                                              (int *)&v165, (float *)v166);
                                          v86 = *(float *)v166;
                                          v87 = v165;
                                        }
                                        else {
                                          *(float *)v166 =
                                              v163 - (float)v164[0];
                                          v165 = *(float *)v164;
                                          v86 = *(float *)v166;
                                          v87 = *(float *)v164;
                                        }
                                      v88 = (__int16 *)(*((_DWORD *)v76 + 1) +
                                                        8 * LODWORD(v87));
                                      *v75 =
                                          (float)((float)((float)*v88 +
                                                          (float)((float)(v88[4] -
                                                                          *v88) *
                                                                  v86)) *
                                                  v70) +
                                          *v75;
                                      v75[1] =
                                          (float)((float)((float)v88[1] +
                                                          (float)((float)(v88[5] -
                                                                          v88[1]) *
                                                                  v86)) *
                                                  v70) +
                                          v75[1];
                                      v75[2] =
                                          (float)((float)((float)v88[2] +
                                                          (float)((float)(v88[6] -
                                                                          v88[2]) *
                                                                  v86)) *
                                                  v70) +
                                          v75[2];
                                      v75[3] =
                                          (float)((float)((float)v88[3] +
                                                          (float)(v86 *
                                                                  (float)(v88[7] -
                                                                          v88[3]))) *
                                                  v70) +
                                          v75[3];
                                    }
                                    else {
                                      *v75 = (float)((float)(__int16)v76[2] *
                                                     v70) +
                                             *v75;
                                      v75[1] = (float)((float)(__int16)v76[3] *
                                                       v70) +
                                               v75[1];
                                      v75[2] = (float)((float)(__int16)v76[4] *
                                                       v70) +
                                               v75[2];
                                      v75[3] = (float)((float)(__int16)v76[5] *
                                                       v70) +
                                               v75[3];
                                    }
                                }
                              v73 = *v155;
                                if (*v155) {
                                  v74 = *v73;
                                    if (*v73) {
                                        if (v74 < v162) {
                                          XAnim_GetTimeIndexCompressed<
                                              unsigned short>(
                                              (int)&__src, (int)(v73 + 4), v74,
                                              (int *)&v165, (float *)v166);
                                          v79 = *(float *)v166;
                                          v78 = v165;
                                        }
                                        else {
                                          *(float *)v166 =
                                              v163 - (float)v164[0];
                                          v78 = *(float *)v164;
                                          v165 = *(float *)v164;
                                          v79 = *(float *)v166;
                                        }
                                      v80 = (float *)(*((_DWORD *)v73 + 1) +
                                                      12 * LODWORD(v78));
                                      v75[4] =
                                          (float)((float)(*v80 +
                                                          (float)((float)(v80[3] -
                                                                          *v80) *
                                                                  v79)) *
                                                  a4) +
                                          v75[4];
                                      v75[5] =
                                          (float)((float)(v80[1] +
                                                          (float)((float)(v80[4] -
                                                                          v80[1]) *
                                                                  v79)) *
                                                  a4) +
                                          v75[5];
                                      v75[6] =
                                          (float)((float)(v80[2] +
                                                          (float)(v79 *
                                                                  (float)(v80[5] -
                                                                          v80[2]))) *
                                                  a4) +
                                          v75[6];
                                    }
                                    else {
                                      v75[4] =
                                          (float)(a4 * *((float *)v73 + 1)) +
                                          v75[4];
                                      v75[5] =
                                          (float)(a4 * *((float *)v73 + 2)) +
                                          v75[5];
                                      v75[6] =
                                          (float)(a4 * *((float *)v73 + 3)) +
                                          v75[6];
                                    }
                                }
                              v75[7] = a4 + v75[7];
                            }
                        }
                    }
                }
                else {
                  v148 = v25 + 16;
                  __src =
                      dword_3BE00C[10 * *((unsigned __int16 *)v127 + a2 + 4)];
                  v162 = v31;
                  v163 = (float)v31 * v30;
                  v164[0] = (int)v163;
                  v32 = a4 * 0.000030518509;
                  v152 = *((_DWORD *)v29 + 5);
                  v151 = (__int16)v29[7];
                    if (v151 > 0) {
                        for (n = 0; n != v151; ++n) {
                            if (((*(int *)(LODWORD(a7) + 16400 +
                                           4 * ((int)*(
                                                    unsigned __int8 *)(n +
                                                                       v148) >>
                                                5)) >>
                                  (*(_BYTE *)(n + v148) & 0x1F)) &
                                 1) == 0) {
                              v35 = &v121[8 * *(unsigned __int8 *)(n + v148)];
                              v150 = *((_DWORD *)v128 + 6) + 8 * n;
                                if (((*(char *)(v152 + (n >> 3)) >> (n & 7)) &
                                     1) != 0) {
                                  v33 = *(unsigned __int16 **)(v150 + 4);
                                    if (v33) {
                                        if (*v33) {
                                          XAnim_GetTimeIndex<unsigned char>(
                                              (int)&__src, (int)(v33 + 4), *v33,
                                              (int *)&v165, (float *)v166);
                                          v94 = *(float *)v166;
                                          v95 =
                                              (__int16 *)(*((_DWORD *)v33 + 1) +
                                                          4 * LODWORD(v165));
                                          v35[2] =
                                              (float)((float)((float)*v95 +
                                                              (float)((float)(v95[2] -
                                                                              *v95) *
                                                                      *(float *)
                                                                          v166)) *
                                                      v32) +
                                              v35[2];
                                          v35[3] =
                                              (float)((float)((float)v95[1] +
                                                              (float)(v94 *
                                                                      (float)(v95[3] -
                                                                              v95[1]))) *
                                                      v32) +
                                              v35[3];
                                        }
                                        else {
                                          v35[2] =
                                              (float)((float)(__int16)v33[2] *
                                                      v32) +
                                              v35[2];
                                          v35[3] =
                                              (float)((float)(__int16)v33[3] *
                                                      v32) +
                                              v35[3];
                                        }
                                    }
                                    else {
                                      v35[3] = a4 + v35[3];
                                    }
                                }
                                else {
                                  v36 = *(unsigned __int16 **)(v150 + 4);
                                    if (*v36) {
                                      XAnim_GetTimeIndex<unsigned char>(
                                          (int)&__src, (int)(v36 + 4), *v36,
                                          v166, &v165);
                                      v92 = v165;
                                      v93 = (__int16 *)(*((_DWORD *)v36 + 1) +
                                                        8 * v166[0]);
                                      *v35 =
                                          (float)((float)((float)*v93 +
                                                          (float)((float)(v93[4] -
                                                                          *v93) *
                                                                  v165)) *
                                                  v32) +
                                          *v35;
                                      v35[1] =
                                          (float)((float)((float)v93[1] +
                                                          (float)((float)(v93[5] -
                                                                          v93[1]) *
                                                                  v92)) *
                                                  v32) +
                                          v35[1];
                                      v35[2] =
                                          (float)((float)((float)v93[2] +
                                                          (float)((float)(v93[6] -
                                                                          v93[2]) *
                                                                  v92)) *
                                                  v32) +
                                          v35[2];
                                      v35[3] =
                                          (float)((float)((float)v93[3] +
                                                          (float)(v92 *
                                                                  (float)(v93[7] -
                                                                          v93[3]))) *
                                                  v32) +
                                          v35[3];
                                    }
                                    else {
                                      *v35 = (float)((float)(__int16)v36[2] *
                                                     v32) +
                                             *v35;
                                      v35[1] = (float)((float)(__int16)v36[3] *
                                                       v32) +
                                               v35[1];
                                      v35[2] = (float)((float)(__int16)v36[4] *
                                                       v32) +
                                               v35[2];
                                      v35[3] = (float)((float)(__int16)v36[5] *
                                                       v32) +
                                               v35[3];
                                    }
                                }
                              v34 = *(unsigned __int16 **)v150;
                                if (*(_DWORD *)v150) {
                                    if (*v34) {
                                      XAnim_GetTimeIndex<unsigned char>(
                                          (int)&__src, (int)(v34 + 4), *v34,
                                          (int *)&v165, (float *)v166);
                                      v81 = *(float *)v166;
                                      v82 = (float *)(*((_DWORD *)v34 + 1) +
                                                      12 * LODWORD(v165));
                                      v35[4] =
                                          (float)((float)(*v82 +
                                                          (float)((float)(v82[3] -
                                                                          *v82) *
                                                                  *(float *)
                                                                      v166)) *
                                                  a4) +
                                          v35[4];
                                      v35[5] =
                                          (float)((float)(v82[1] +
                                                          (float)((float)(v82[4] -
                                                                          v82[1]) *
                                                                  v81)) *
                                                  a4) +
                                          v35[5];
                                      v35[6] =
                                          (float)((float)(v82[2] +
                                                          (float)(v81 *
                                                                  (float)(v82[5] -
                                                                          v82[2]))) *
                                                  a4) +
                                          v35[6];
                                    }
                                    else {
                                      v35[4] =
                                          (float)(a4 * *((float *)v34 + 1)) +
                                          v35[4];
                                      v35[5] =
                                          (float)(a4 * *((float *)v34 + 2)) +
                                          v35[5];
                                      v35[6] =
                                          (float)(a4 * *((float *)v34 + 3)) +
                                          v35[6];
                                    }
                                }
                              v35[7] = a4 + v35[7];
                            }
                        }
                    }
                }
              return;
            }
          v43 = *((_DWORD *)v126 + 1);
          v44 = v43;
        }
      v145 = v25 + 16;
      v45 = a4 * 0.000030518509;
      v147 = *(_DWORD *)(v43 + 20);
      v146 = *(__int16 *)(v44 + 14);
        if (v146 > 0) {
            for (ii = 0; ii != v146; ++ii) {
                if (((*(int *)(LODWORD(a7) + 16400 +
                               4 * ((int)*(unsigned __int8 *)(v145 + ii) >>
                                    5)) >>
                      (*(_BYTE *)(v145 + ii) & 0x1F)) &
                     1) == 0) {
                  v52 = &v121[8 * *(unsigned __int8 *)(v145 + ii)];
                  v53 = *((_DWORD *)v29 + 6) + 8 * ii;
                    if (((*(char *)(v147 + (ii >> 3)) >> (ii & 7)) & 1) != 0) {
                      v47 = *(unsigned __int16 **)(v53 + 4);
                        if (v47) {
                          if (*v47)
                            v48 = (__int16 *)(*((_DWORD *)v47 + 1) + 4 * *v47);
                          else
                            v48 = (__int16 *)(v47 + 2);
                          v52[2] = (float)((float)*v48 * v45) + v52[2];
                          v52[3] = (float)((float)v48[1] * v45) + v52[3];
                        }
                        else {
                          v52[3] = a4 + v52[3];
                        }
                    }
                    else {
                      v54 = *(unsigned __int16 **)(v53 + 4);
                        if (*v54) {
                          v55 = (__int16 *)(*((_DWORD *)v54 + 1) + 8 * *v54);
                          v56 = *v55;
                        }
                        else {
                          v55 = (__int16 *)(v54 + 2);
                          v56 = (__int16)v54[2];
                        }
                      *v52 = (float)((float)v56 * v45) + *v52;
                      v52[1] = (float)((float)v55[1] * v45) + v52[1];
                      v52[2] = (float)((float)v55[2] * v45) + v52[2];
                      v52[3] = (float)((float)v55[3] * v45) + v52[3];
                    }
                  v49 = *(unsigned __int16 **)v53;
                    if (*(_DWORD *)v53) {
                        if (*v49) {
                          v50 = (float *)(*((_DWORD *)v49 + 1) + 12 * *v49);
                          v51 = a4 * *v50;
                        }
                        else {
                          v50 = (float *)(v49 + 2);
                          v51 = a4 * *((float *)v49 + 1);
                        }
                      v52[4] = v51 + v52[4];
                      v52[5] = (float)(a4 * v50[1]) + v52[5];
                      v52[6] = (float)(a4 * v50[2]) + v52[6];
                    }
                  v52[7] = a4 + v52[7];
                }
            }
        }
    }
}

void __cdecl NotifyServerNotetrack(struct XAnimTree_s const *, unsigned int,
                                   unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimProcessServerNotify(struct XAnimTree_s const *,
                                      struct XAnimInfo *,
                                      struct XAnimEntry const *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimUpdateInfoSyncInternal(struct XAnimTree_s const *,
                                         unsigned int, bool,
                                         struct XAnimState *, float)
{
  UNIMPLEMENTED();
}

void __cdecl XAnimUpdateInfoInternal(struct XAnimTree_s const *, unsigned int,
                                     float, bool)
{
  unsigned __int16 v6;        // ax
  float *v7;                  // esi
  char *v8;                   // edx
  __int16 v9;                 // ax
  int v10;                    // eax
  float v11;                  // xmm3_4
  float v12;                  // xmm2_4
  __int16 v13;                // bx
  int v14;                    // ecx
  int v15;                    // ebx
  float v16;                  // xmm3_4
  int v17;                    // edx
  unsigned __int16 v18;       // ax
  float v19;                  // xmm1_4
  float AverageRateFrequency; // xmm0_4
  int v21;                    // ebx
  __int16 v22;                // dx
  float v23;                  // xmm0_4
  float v24;                  // xmm2_4
  int v25;                    // ebx
  int v26;                    // edx
  unsigned __int16 v27;       // ax
  int *v28;                   // edi
  float *v29;                 // ebx
  unsigned __int8 v30;        // al
  float v31;                  // xmm0_4
  __int16 v32;                // ax
  int v33;                    // edi
  int v34;                    // ebx
  const XAnimTree_s *v35;     // [esp+0h] [ebp-98h]
  unsigned int v36;           // [esp+4h] [ebp-94h]
  float v37;                  // [esp+8h] [ebp-90h]
  unsigned __int8 v38;        // [esp+Ch] [ebp-8Ch]
  int i;                      // [esp+50h] [ebp-48h]
  int v42;                    // [esp+54h] [ebp-44h]
  int *v43;                   // [esp+58h] [ebp-40h]
  int v44;                    // [esp+5Ch] [ebp-3Ch]
  int *v45;                   // [esp+60h] [ebp-38h]
  float v46;                  // [esp+64h] [ebp-34h]
  unsigned __int8 v47;        // [esp+6Bh] [ebp-2Dh]
  char *v48;                  // [esp+6Ch] [ebp-2Ch]
  unsigned __int8 v49;        // [esp+77h] [ebp-21h]
  float v50;                  // [esp+7Ch] [ebp-1Ch]

  v6 = *((_WORD *)a1 + a2 + 4);
  if (!v6)
    return;
  v43 = &g_xAnimInfo[10 * v6];
  v7 = (float *)(v43 + 3);
  if (*((float *)v43 + 8) == 0.0)
    return;
  if (*((float *)v43 + 7) == 0.0)
    a3 = 0;
  v8 = &(*a1)[8 * a2 + 12];
  v44 = (int)v8;
  v9 = *(_WORD *)v8;
  v42 = *(unsigned __int16 *)v8;
    if (!*(_WORD *)v8) {
      v10 = *((_DWORD *)v8 + 1);
      v11 = (float)(*((float *)v43 + 9) * *(float *)(v10 + 8)) * a4;
      if (v11 == 0.0)
        return;
      v12 = v11 + *((float *)v43 + 4);
      v13 = *((_WORD *)v43 + 10);
        if (v12 >= 1.0) {
            if (*(_BYTE *)(v10 + 2)) {
              v22 = *((_WORD *)v43 + 10);
                do {
                  v12 = v12 - 1.0;
                  ++v22;
                }
              while (v12 >= 1.0);
              v14 = v22 - v13;
              v13 = v22;
            LABEL_11:
                if ((float)(*v7 - v12) <= (float)v14) {
                  if (a3)
                    XAnimProcessServerNotify(a1, (float *)v43, v44, v12);
                  *v7 = v12;
                  *((_WORD *)v43 + 10) = v13;
                  *((_WORD *)v43 + 1) = -1;
                  if (a3)
                    XAnimProcessClientNotify((unsigned int)v43, v44, v11);
                }
              return;
            }
          v12 = 1.0;
        }
      v14 = 0;
      goto LABEL_11;
    }
    if ((v8[4] & 3) != 0) {
      if (!v9)
        goto LABEL_63;
      v15 = 0;
      v16 = 0.0;
      v46 = 0.0;
        do {
          v17 = v15 + *(unsigned __int16 *)(v44 + 6);
          v18 = *((_WORD *)a1 + v17 + 4);
            if (v18) {
              v45 = &g_xAnimInfo[10 * v18];
              v19 = *((float *)v45 + 8);
                if (v19 != 0.0) {
                  AverageRateFrequency = XAnimGetAverageRateFrequency(a1, v17);
                    if (AverageRateFrequency != 0.0) {
                      v16 = v16 + v19;
                      v46 = (float)((float)(v19 * AverageRateFrequency) *
                                    *((float *)v45 + 9)) +
                            v46;
                    }
                }
            }
          ++v15;
        }
      while (v42 != v15);
      if (v16 == 0.0)
      LABEL_63:
        v23 = 0.0;
      else
        v23 = v46 / v16;
      v50 = a4 * (float)(v23 * *((float *)v43 + 9));
        if (v50 != 0.0) {
          v24 = v50 + *((float *)v43 + 4);
          v25 = *((unsigned __int16 *)v43 + 11);
            if (v24 >= 1.0) {
                if ((*(_BYTE *)(v44 + 4) & 2) != 0) {
                  v24 = 1.0;
                }
                else {
                    do {
                      v24 = v24 - 1.0;
                      ++v25;
                      if (v24 < 1.0)
                        break;
                      v24 = v24 - 1.0;
                      ++v25;
                    }
                  while (v24 >= 1.0);
                }
            }
            if ((float)(*((float *)v43 + 3) - v24) <=
                (float)((__int16)v25 - *((__int16 *)v43 + 10))) {
              if (a3)
                XAnimProcessServerNotify(a1, (float *)v43, v44, v24);
              *v7 = v24;
              *((_WORD *)v43 + 10) = v25;
              *((_WORD *)v43 + 1) = -1;
              if (a3)
                XAnimProcessClientNotify((unsigned int)v43, v44, v50);
                if (v42 > 0) {
                  v49 = a3;
                    for (i = 0; i != v42; ++i) {
                      v26 = *(unsigned __int16 *)(v44 + 6) + i;
                      v27 = *((_WORD *)a1 + v26 + 4);
                        if (v27) {
                          v28 = &g_xAnimInfo[10 * v27];
                          v29 = (float *)(v28 + 3);
                            if (*((float *)v28 + 8) != 0.0) {
                              v30 = 0;
                              if (*((float *)v28 + 7) != 0.0)
                                v30 = v49;
                              v47 = v30;
                              v48 = &(*a1)[8 * v26 + 12];
                              v31 = *((float *)v43 + 4);
                                if (v31 != *((float *)v28 + 4) ||
                                    *((_WORD *)v28 + 11) !=
                                        *((_WORD *)v43 + 11)) {
                                  *v29 = v31;
                                  v32 = *((_WORD *)v43 + 11);
                                  *((_WORD *)v28 + 10) = v32;
                                  *((float *)v28 + 4) = v31;
                                  *((_WORD *)v28 + 11) = v32;
                                  *((_WORD *)v28 + 1) = -1;
                                }
                              if (v47)
                                XAnimProcessServerNotify(a1, (float *)v28,
                                                         (int)v48, *v7);
                              *v29 = *v7;
                              *((_WORD *)v28 + 10) = *((_WORD *)v43 + 10);
                              *((_WORD *)v28 + 1) = -1;
                              if (v47)
                                XAnimProcessClientNotify((unsigned int)v28,
                                                         (int)v48, v50);
                              v33 = *(unsigned __int16 *)v48;
                                if (*(_WORD *)v48) {
                                  v34 = 0;
                                    do {
                                      XAnimUpdateInfoSyncInternal(
                                          a1,
                                          v34 + *((unsigned __int16 *)v48 + 3),
                                          v47, v50, (XAnimInfo *)v7);
                                      ++v34;
                                    }
                                  while (v33 != v34);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if ((float)(a4 * *((float *)v43 + 9)) != 0.0 && v9) {
      v21 = 0;
        do {
          XAnimUpdateInfoInternal(v35, v36, v37, v38);
          ++v21;
        }
      while (v42 != v21);
    }
}
