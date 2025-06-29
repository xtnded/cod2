int __cdecl Scr_GetClassnumForCharId(char charId)
{
  int result; // eax
  __int16 *i; // edx

  result = 0;
    for (i = &g_classMap; *((_BYTE *)i + 4) != a1; i += 6) {
      if (++result == 4)
        return -1;
    }
  return result;
}

void __cdecl Scr_GetChecksum(int *const)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_FindField(char const *, int *)
{
  const char *v2;  // esi
  int v3;          // edx
  unsigned int v5; // ebx

  v2 = scrVarPub;
  if (!*scrVarPub)
    return 0;
    while (1) {
      v5 = strlen(v2) + 1;
      if (!stricmp(a1, v2))
        break;
      v2 += v5 + 3;
      if (!*v2)
        return 0;
    }
  v3 = *(unsigned __int16 *)&v2[v5];
  *a2 = v2[v5 + 2];
  return v3;
}

struct scr_entref_t __cdecl Scr_GetEntityIdRef(unsigned int entId)
{
  unsigned __int16 v1; // cx
  int v2;              // ecx

  v2 = (*(unsigned __int16 *)((char *)&dword_104CF08[4 * a1] + 1) << 16) | v1;
  LOWORD(v2) = HIWORD(dword_104CF04[4 * a1]);
  return v2;
}

int __cdecl GetVarType(unsigned int)
{
  return dword_104CF08[4 * a1] & 0x1F;
}

bool __cdecl IsVarFree(unsigned int id)
{
  return (dword_104CF08[4 * a1] & 0x60) == 0;
}

int __cdecl Scr_GetEntNum(unsigned int)
{
  UNIMPLEMENTED();
}

char __cdecl Scr_GetEntClassId(unsigned int)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_IsThreadAlive(unsigned int)
{
  UNIMPLEMENTED();
}

bool __cdecl IsFieldObject(unsigned int id)
{
  return (dword_104CF08[4 * a1] & 0x1Fu) <= 0x15;
}

unsigned int __cdecl FindObject(unsigned int id)
{
  return dword_104CF04[4 * a1];
}

unsigned int __cdecl GetVariableName(unsigned int id)
{
  return (unsigned int)dword_104CF08[4 * a1] >> 8;
}

unsigned int __cdecl FindPrevSibling(unsigned int id)
{
  int result; // eax

  result = LOWORD(
      scrVarGlob
          [4 *
           HIWORD(scrVarGlob
                      [4 * HIWORD(scrVarGlob[4 * (unsigned __int16)
                                                     word_104CF0E[8 * a1]])])]);
  if ((dword_104CF08[4 * result] & 0x1Fu) >= 0xF)
    return 0;
  return result;
}

unsigned int __cdecl FindNextSibling(unsigned int id)
{
  int v1; // ecx

  v1 = LOWORD(scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * a1]]);
  if (a1 == v1 || (dword_104CF08[4 * v1] & 0x1Fu) > 0xE)
    return 0;
  else
    return LOWORD(scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * a1]]);
}

unsigned int __cdecl GetArraySize(unsigned int id)
{
  return HIWORD(dword_104CF04[4 * a1]);
}

union VariableUnion *__cdecl GetVariableValueAddress(unsigned int id)
{
  return 16 * a1 + 17092356;
}

void __cdecl SetNewVariableValue(unsigned int id, struct VariableValue_s *value)
{
  unsigned int v2;      // edx
  VariableUnion result; // eax

  v2 = 16 * a1 + 17092352;
  *(_DWORD *)(v2 + 8) = a2->type | dword_104CF08[4 * a1];
  result.intValue = (int32_t)a2->u;
  *(_DWORD *)(v2 + 4) = a2->u.intValue;
  return result;
}

struct VariableValue_s __cdecl Scr_GetArrayIndexValue(unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetInternalVariableIndex(unsigned int unsignedValue)
{
  return (a1 + 0x800000) & 0xFFFFFF;
}

bool __cdecl IsValidArrayIndex(unsigned int unsignedValue)
{
  return a1 + 8257538 <= (unsigned int)&unk_FE0001;
}

void __cdecl AddRefToVector(float const *)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_GetRefCountToObject(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl AddRefToObject(unsigned int id)
{
  unsigned int result; // eax

  result = 16 * a1;
  ++LOWORD(dword_104CF04[4 * a1]);
  return result;
}

unsigned int __cdecl Scr_GetSelf(unsigned int threadId)
{
  return HIWORD(dword_104CF04[4 * a1]);
}

unsigned int __cdecl GetStartLocalId(unsigned int threadId)
{
  unsigned int i; // edx

    for (i = a1; (dword_104CF08[4 * i] & 0x1F) == 0x12;
         i = (unsigned int)dword_104CF08[4 * i] >> 8) {
      i = (unsigned int)dword_104CF08[4 * i] >> 8;
      if ((dword_104CF08[4 * i] & 0x1F) != 0x12)
        break;
    }
  return i;
}

unsigned int __cdecl GetSafeParentLocalId(unsigned int threadId)
{
  if ((dword_104CF08[4 * a1] & 0x1F) == 0x12)
    return (unsigned int)dword_104CF08[4 * a1] >> 8;
  else
    return 0;
}

unsigned int __cdecl GetParentLocalId(unsigned int threadId)
{
  return (unsigned int)dword_104CF08[4 * a1] >> 8;
}

unsigned int __cdecl Scr_GetThreadWaitTime(unsigned int startLocalId)
{
  return (unsigned int)dword_104CF08[4 * a1] >> 8;
}

void __cdecl Scr_ClearWaitTime(unsigned int startLocalId)
{
  unsigned int result; // eax

  result = dword_104CF08[4 * a1] & 0xFFFFFFE0 | 0xF;
  dword_104CF08[4 * a1] = result;
  return result;
}

void __cdecl Scr_SetThreadWaitTime(unsigned int startLocalId,
                                   unsigned int waitTime)
{
  int *v2;    // ebx
  int result; // eax

  v2 = &scrVarGlob[4 * a1];
  result = v2[2] & 0xE0 | 0x11;
  v2[2] = result;
  dword_104CF08[4 * a1] |= a2 << 8;
  return result;
}

unsigned short __cdecl Scr_GetThreadNotifyName(unsigned int startLocalId)
{
  return *(unsigned __int16 *)((char *)&dword_104CF08[4 * a1] + 1);
}

void __cdecl Scr_RemoveThreadEmptyNotifyName(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_SetThreadNotifyName(unsigned int startLocalId,
                                     unsigned int stringValue)
{
  unsigned int result; // eax

  result = 16 * a1 + 17092352;
  dword_104CF08[4 * a1] = dword_104CF08[4 * a1] & 0xE0 | 0x10 | (a2 << 8);
  return result;
}

unsigned int __cdecl GetVariableKeyObject(unsigned int id)
{
  return ((unsigned int)dword_104CF08[4 * a1] >> 8) - 0x10000;
}

unsigned int __cdecl Scr_GetNumScriptVars()
{
  return 0;
}

void __cdecl Scr_DumpScriptVariables()
{
  ;
}

bool __cdecl IsObjectId(unsigned int)
{
  UNIMPLEMENTED();
}

bool __cdecl IsObject(struct VariableValueInternal *)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_EvalVariableObject(unsigned int id)
{
  unsigned int v1; // edx
  char *v2;        // eax

  v1 = dword_104CF08[4 * a1] & 0x1F;
    if (v1 == 1) {
      v1 = dword_104CF08[4 * dword_104CF04[4 * a1]] & 0x1F;
      if (v1 <= 0x15)
        return dword_104CF04[4 * a1];
    }
  v2 = va("%s is not a field object", *(const char **)&var_typename[4 * v1]);
  Scr_Error(v2);
  return 0;
}

void __cdecl RemoveRefToEmptyObject(unsigned int id)
{
  int *v1;             // edi
  int v2;              // eax
  int result;          // eax
  unsigned __int16 v4; // bx
  int v5;              // edx
  unsigned __int16 v6; // si

  v1 = &scrVarGlob[4 * a1];
  v2 = *((unsigned __int16 *)v1 + 2);
    if ((_WORD)v2) {
      result = v2 - 1;
      *((_WORD *)v1 + 2) = result;
    }
    else {
      v4 = *((_WORD *)v1 + 6);
      v5 = HIWORD(scrVarGlob[4 * v4]);
      v6 = *((_WORD *)v1 + 7);
      HIWORD(scrVarGlob[4 * v6]) = v5;
      word_104CF0E[8 * LOWORD(scrVarGlob[4 * v5])] = v6;
      v1[2] = 0;
      *((_WORD *)v1 + 2) = dword_104CF04[0];
      HIWORD(scrVarGlob[4 * v4]) = 0;
      result = 16 * LOWORD(dword_104CF04[0]);
      *(_WORD *)((char *)scrVarGlob + result + 2) = v4;
      LOWORD(dword_104CF04[0]) = v4;
    }
  return result;
}

void __cdecl Var_Init()
{
  UNIMPLEMENTED();
}

unsigned int __cdecl FindObjectVariable(unsigned int parentId, unsigned int id)
{
  int v2;  // esi
  int i;   // ecx
  int *v4; // edi
  int *v5; // ebx
  int *v7; // edx

  v2 = a2 + 0x10000;
  i = (unsigned __int16)((a1 + a2 + 0x10000) % 0xFFFD + 1);
  v4 = &scrVarGlob[4 * i];
  v5 = &scrVarGlob[4 * *(unsigned __int16 *)v4];
    if ((v5[2] & 0x60) == 0x40) {
      if (v2 == (unsigned int)v5[2] >> 8)
        return LOWORD(scrVarGlob[4 * i]);
        for (i = *((unsigned __int16 *)v5 + 6); v4 != &scrVarGlob[4 * i];
             i = *((unsigned __int16 *)v7 + 6)) {
          v7 = &scrVarGlob[4 * LOWORD(scrVarGlob[4 * i])];
          if (v2 == (unsigned int)v7[2] >> 8)
            return LOWORD(scrVarGlob[4 * i]);
        }
    }
  i = 0;
  return LOWORD(scrVarGlob[4 * i]);
}

unsigned int __cdecl FindVariable(unsigned int parentId,
                                  unsigned int unsignedValue)
{
  int i;   // ecx
  int *v3; // edi
  int *v4; // ebx
  int *v6; // edx

  i = (unsigned __int16)((a2 + a1) % 0xFFFD + 1);
  v3 = &scrVarGlob[4 * i];
  v4 = &scrVarGlob[4 * *(unsigned __int16 *)v3];
    if ((v4[2] & 0x60) == 0x40) {
      if (a2 == (unsigned int)v4[2] >> 8)
        return LOWORD(scrVarGlob[4 * i]);
        for (i = *((unsigned __int16 *)v4 + 6); v3 != &scrVarGlob[4 * i];
             i = *((unsigned __int16 *)v6 + 6)) {
          v6 = &scrVarGlob[4 * LOWORD(scrVarGlob[4 * i])];
          if (a2 == (unsigned int)v6[2] >> 8)
            return LOWORD(scrVarGlob[4 * i]);
        }
    }
  i = 0;
  return LOWORD(scrVarGlob[4 * i]);
}

void __cdecl AddRefToValue(int type, union VariableUnion u)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_GetOffset(int classnum, char const *name)
{
  int v2;              // ebx
  int v3;              // esi
  int v4;              // ecx
  int *v5;             // edi
  int *v6;             // ebx
  unsigned __int16 v7; // ax
  int v9;              // edx
  int *v10;            // edx

  v2 = (unsigned __int16)g_classMap[6 * a1];
  v3 = SL_ConvertFromString(a2);
  v4 = (unsigned __int16)((v3 + v2) % 0xFFFDu + 1);
  v5 = &scrVarGlob[4 * v4];
  v6 = &scrVarGlob[4 * *(unsigned __int16 *)v5];
  if ((v6[2] & 0x60) != 0x40)
    goto LABEL_2;
    if (v3 != (unsigned int)v6[2] >> 8) {
      v4 = *((unsigned __int16 *)v6 + 6);
      v9 = 4 * v4;
        if (v5 == &scrVarGlob[4 * v4]) {
        LABEL_2:
          v4 = 0;
          goto LABEL_3;
        }
        while (1) {
          v10 = &scrVarGlob[4 * LOWORD(scrVarGlob[v9])];
          if (v3 == (unsigned int)v10[2] >> 8)
            break;
          v4 = *((unsigned __int16 *)v10 + 6);
          v9 = 4 * v4;
          if (v5 == &scrVarGlob[4 * v4])
            goto LABEL_2;
        }
    }
LABEL_3:
  v7 = scrVarGlob[4 * v4];
  if (v7)
    return dword_104CF04[4 * v7];
  else
    return -1;
}

struct VariableValue_s __cdecl Scr_EvalVariable(unsigned int id)
{
  unsigned int v1; // edi
  int v4;          // [esp+1Ch] [ebp-1Ch]

  v1 = dword_104CF08[4 * a1] & 0x1F;
  v4 = dword_104CF04[4 * a1];
    if (v1 > 3) {
        if (v1 == 4) {
          if (!*(_BYTE *)(v4 - 1))
            ++*(_WORD *)(v4 - 4);
          return v4;
        }
    }
    else {
        if ((dword_104CF08[4 * a1] & 0x1Fu) >= 2) {
          SL_AddRefToString(v4);
          return v4;
        }
        if (v1 == 1) {
          ++LOWORD(dword_104CF04[4 * v4]);
          return v4;
        }
    }
  return dword_104CF04[4 * a1];
}

int __cdecl Scr_FindAllVariableField(unsigned int, unsigned int *)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl FindArrayVariable(unsigned int parentId, int intValue)
{
  int v2;  // esi
  int i;   // ecx
  int *v4; // edi
  int *v5; // ebx
  int *v7; // edx

  v2 = (a2 + 0x800000) & 0xFFFFFF;
  i = (unsigned __int16)((v2 + a1) % 0xFFFD + 1);
  v4 = &scrVarGlob[4 * i];
  v5 = &scrVarGlob[4 * *(unsigned __int16 *)v4];
    if ((v5[2] & 0x60) == 0x40) {
      if (v2 == (unsigned int)v5[2] >> 8)
        return LOWORD(scrVarGlob[4 * i]);
        for (i = *((unsigned __int16 *)v5 + 6); v4 != &scrVarGlob[4 * i];
             i = *((unsigned __int16 *)v7 + 6)) {
          v7 = &scrVarGlob[4 * LOWORD(scrVarGlob[4 * i])];
          if (v2 == (unsigned int)v7[2] >> 8)
            return LOWORD(scrVarGlob[4 * i]);
        }
    }
  i = 0;
  return LOWORD(scrVarGlob[4 * i]);
}

unsigned int __cdecl FindEntityId(int entnum, int classnum)
{
  int v2;              // esi
  int v3;              // ecx
  int *v4;             // edi
  int *v5;             // ebx
  unsigned __int16 v6; // ax
  int v8;              // edx
  int *v9;             // edx

  v2 = (a1 + 0x800000) & 0xFFFFFF;
  v3 =
      (unsigned __int16)((v2 +
                          (unsigned int)(unsigned __int16)word_30AA42[6 * a2]) %
                             0xFFFD +
                         1);
  v4 = &scrVarGlob[4 * v3];
  v5 = &scrVarGlob[4 * *(unsigned __int16 *)v4];
  if ((v5[2] & 0x60) != 0x40)
    goto LABEL_2;
    if (v2 != (unsigned int)v5[2] >> 8) {
      v3 = *((unsigned __int16 *)v5 + 6);
      v8 = 4 * v3;
        if (v4 == &scrVarGlob[4 * v3]) {
        LABEL_2:
          v3 = 0;
          goto LABEL_3;
        }
        while (1) {
          v9 = &scrVarGlob[4 * LOWORD(scrVarGlob[v8])];
          if (v2 == (unsigned int)v9[2] >> 8)
            break;
          v3 = *((unsigned __int16 *)v9 + 6);
          v8 = 4 * v3;
          if (v4 == &scrVarGlob[4 * v3])
            goto LABEL_2;
        }
    }
LABEL_3:
  v6 = scrVarGlob[4 * v3];
  if (v6)
    return dword_104CF04[4 * v6];
  else
    return 0;
}

void __cdecl Scr_DumpScriptThreads()
{
  int v1;               // esi
  int v2;               // edx
  unsigned __int16 v3;  // cx
  int v4;               // ebx
  int v5;               // edx
  float v6;             // xmm0_4
  unsigned __int16 v7;  // cx
  int *v8;              // esi
  int v9;               // esi
  int v10;              // ecx
  int *v11;             // edi
  int *v12;             // ebx
  unsigned __int16 v13; // ax
  float v14;            // xmm2_4
  int v15;              // edx
  unsigned __int16 v16; // cx
  int v17;              // ebx
  int v18;              // edx
  unsigned __int16 v19; // cx
  int v20;              // edx
  int v21;              // eax
  int *v22;             // esi
  unsigned int v23;     // edi
  int v24;              // ecx
  float v25;            // xmm0_4
  float *v26;           // ecx
  float *v27;           // edx
  int j;                // ebx
  char *v29;            // edi
  float v30;            // xmm0_4
  float v31;            // xmm1_4
  float *v32;           // eax
  int v33;              // esi
  char *v34;            // edx
  char *v35;            // eax
  int v36;              // edx
  int *v37;             // edx
  int *v38;             // esi
  unsigned __int16 v39; // dx
  int v40;              // ebx
  float v41;            // xmm2_4
  int v42;              // edx
  unsigned __int16 v43; // cx
  int v44;              // edx
  int v45;              // eax
  unsigned __int16 v46; // dx
  int v47;              // ebx
  float v48;            // xmm2_4
  int v49;              // edx
  unsigned __int16 v50; // cx
  int v51;              // edx
  int v52;              // eax
  int *v53;             // esi
  unsigned int v54;     // esi
  int v55;              // ecx
  int *v56;             // ebx
  unsigned __int16 v57; // ax
  float v58;            // xmm2_4
  int v59;              // edx
  unsigned __int16 v60; // cx
  int v61;              // ebx
  int v62;              // edx
  unsigned __int16 v63; // cx
  int v64;              // edx
  int v65;              // eax
  int *v66;             // esi
  int v67;              // edx
  int *v68;             // edx
  char *v69;            // edx
  int i;                // ecx
  char v71;             // al
  int v72;              // ebx
  char *v73;            // ebx
  char *v74;            // ecx
  int v75;              // eax
  unsigned __int16 v76; // ax
  unsigned __int16 v77; // cx
  int v78;              // edi
  float v79;            // xmm0_4
  unsigned __int16 v80; // cx
  char **v81;           // esi
  int v82;              // ebx
  int v83;              // edx
  unsigned __int16 v84; // cx
  int v85;              // esi
  float v86;            // xmm2_4
  unsigned __int16 v87; // cx
  int *v88;             // ebx
  float *v89;           // [esp+30h] [ebp-118h]
  _DWORD *v90;          // [esp+34h] [ebp-114h]
  unsigned __int16 v91; // [esp+3Ah] [ebp-10Eh]
  int v92;              // [esp+3Ch] [ebp-10Ch]
  float *__base;        // [esp+40h] [ebp-108h]
  int __nel;            // [esp+44h] [ebp-104h]
  int v95;              // [esp+48h] [ebp-100h]
  int v96;              // [esp+4Ch] [ebp-FCh]
  int *v97;             // [esp+50h] [ebp-F8h]
  int v98;              // [esp+58h] [ebp-F0h]
  float *v99;           // [esp+5Ch] [ebp-ECh]
  float v100;           // [esp+60h] [ebp-E8h]
  _BYTE *v101;          // [esp+64h] [ebp-E4h]
  float v102;           // [esp+68h] [ebp-E0h]
  int *v103;            // [esp+70h] [ebp-D8h]
  int v104;             // [esp+74h] [ebp-D4h]
  int v105;             // [esp+78h] [ebp-D0h]
  __int16 *v106;        // [esp+7Ch] [ebp-CCh]
  float *v107;          // [esp+80h] [ebp-C8h]
  char *v108;           // [esp+84h] [ebp-C4h]
  char **v109;          // [esp+88h] [ebp-C0h]
  int v110;             // [esp+8Ch] [ebp-BCh]
  float v111;           // [esp+90h] [ebp-B8h]
  float *v112;          // [esp+94h] [ebp-B4h]
  int v113;             // [esp+98h] [ebp-B0h]
  int v114;             // [esp+9Ch] [ebp-ACh]
  _DWORD v115[41];      // [esp+A4h] [ebp-A4h] BYREF

  __base = (float *)Z_TryMallocInternal((size_t)&unk_8BFEE8);
    if (!__base) {
      Com_Printf("Cannot dump script threads: out of memory\n");
      return;
    }
  __nel = 0;
  v92 = 1;
  v90 = &unk_104CF10;
  v89 = __base;
    do {
        while (1) {
          if ((v90[2] & 0x60) == 0 || (v90[2] & 0x1F) != 0xA)
            goto LABEL_3;
          v112 = v89;
          ++__nel;
          v89 += 35;
          v97 = (int *)v90[1];
          v91 = *((_WORD *)v97 + 2);
          v98 = *v97;
            if (v91) {
              v69 = (char *)v97 + 11;
              v1 = 0;
                for (i = 0; i != v91; ++i) {
                    while (1) {
                      v71 = *v69;
                      v72 = *(_DWORD *)(v69 + 1);
                      v69 += 5;
                      if (v71 == 7)
                        break;
                      if (v91 == ++i)
                        goto LABEL_104;
                    }
                  v115[v1++] = v72;
                }
            LABEL_104:
              v105 = v1 + 1;
            }
            else {
              v1 = 0;
              v105 = 1;
            }
          v115[v1] = v98;
          v99 = v112 + 34;
          v101 = (char *)v97 + 5 * v91 + 11;
          v2 = *((unsigned __int16 *)v97 + 4);
          v3 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v2]];
          v4 = v3;
            if (v2 == v3 || (dword_104CF08[4 * v3] & 0x1Fu) > 0xE || !v3) {
              v102 = 1.0;
            }
            else {
              v102 = 1.0;
              v5 = dword_104CF04[4 * v3];
              if ((dword_104CF08[4 * v3] & 0x1F) != 1)
                goto LABEL_12;
                while (1) {
                  v8 = &scrVarGlob[4 * v5];
                    if ((v8[2] & 0x1F) != 0x16) {
                    LABEL_12:
                      v6 = 1.0;
                      goto LABEL_13;
                    }
                  v6 = (float)(COERCE_FLOAT(Scr_GetObjectUsage(v5, a1)) /
                               (float)((float)*((unsigned __int16 *)v8 + 2) +
                                       1.0)) +
                       1.0;
                LABEL_13:
                  a1 = v6 + v102;
                  v102 = a1;
                  v7 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v4]];
                  if (v4 == v7)
                    break;
                    if ((dword_104CF08[4 * v7] & 0x1Fu) > 0xE) {
                      v2 = *((unsigned __int16 *)v97 + 4);
                      goto LABEL_20;
                    }
                  if (!v7)
                    break;
                  v4 = v7;
                  v5 = dword_104CF04[4 * v7];
                  if ((dword_104CF08[4 * v7] & 0x1F) != 1)
                    goto LABEL_12;
                }
              v2 = *((unsigned __int16 *)v97 + 4);
            }
        LABEL_20:
          v9 = v2 + 0x10000;
          v10 = (unsigned __int16)((dword_100CEC0 + v2 + 0x10000) % 0xFFFD + 1);
          v11 = &scrVarGlob[4 * v10];
          v12 = &scrVarGlob[4 * *(unsigned __int16 *)v11];
            if ((v12[2] & 0x60) != 0x40) {
            LABEL_21:
              v10 = 0;
              goto LABEL_22;
            }
            if (v9 != (unsigned int)v12[2] >> 8) {
              v10 = *((unsigned __int16 *)v12 + 6);
              v36 = 4 * v10;
              if (v11 == &scrVarGlob[4 * v10])
                goto LABEL_21;
                while (1) {
                  v37 = &scrVarGlob[4 * LOWORD(scrVarGlob[v36])];
                  if ((unsigned int)v37[2] >> 8 == v9)
                    break;
                  v10 = *((unsigned __int16 *)v37 + 6);
                  v36 = 4 * v10;
                  if (v11 == &scrVarGlob[4 * v10])
                    goto LABEL_21;
                }
            }
        LABEL_22:
          v13 = scrVarGlob[4 * v10];
          v14 = 0.0;
          if (!v13)
            goto LABEL_33;
          v15 = dword_104CF04[4 * v13];
          v16 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v15]];
          v17 = v16;
            if (v15 != v16 && (dword_104CF08[4 * v16] & 0x1Fu) <= 0xE && v16) {
              v14 = 1.0;
              v18 = dword_104CF04[4 * v16];
                if ((dword_104CF08[4 * v16] & 0x1F) == 1) {
                    do {
                      v22 = &scrVarGlob[4 * v18];
                      if ((v22[2] & 0x1F) != 0x16)
                        break;
                      a1 = (float)(COERCE_FLOAT(Scr_GetObjectUsage(v18, a1)) /
                                   (float)((float)*((unsigned __int16 *)v22 +
                                                    2) +
                                           1.0)) +
                           1.0;
                      v14 = v14 + a1;
                      v19 = scrVarGlob[4 *
                                       (unsigned __int16)word_104CF0E[8 * v17]];
                      v20 = v19;
                      if (v17 == v19)
                        goto LABEL_33;
                    LABEL_28:
                      if ((dword_104CF08[4 * v20] & 0x1Fu) > 0xE || !v19)
                        goto LABEL_33;
                      v17 = v20;
                      v21 = 16 * v20 + 17092352;
                      v18 = dword_104CF04[4 * v20];
                    }
                  while ((*(_DWORD *)(v21 + 8) & 0x1F) == 1);
                }
              a1 = 1.0;
              v14 = v14 + 1.0;
              v19 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v17]];
              v20 = v19;
              if (v17 == v19)
                goto LABEL_33;
              goto LABEL_28;
            }
          v14 = 1.0;
        LABEL_33:
          *v99 = v14;
          v23 = *((unsigned __int16 *)v97 + 4);
            if (v91) {
              v110 = 0;
                while (1) {
                  v24 = *((_DWORD *)v101 - 1);
                  v101 -= 5;
                    if (*v101 == 7) {
                      v23 = (unsigned int)dword_104CF08[4 * v23] >> 8;
                      v46 = scrVarGlob[4 *
                                       (unsigned __int16)word_104CF0E[8 * v23]];
                      v47 = v46;
                        if (v23 == v46 ||
                            (dword_104CF08[4 * v46] & 0x1Fu) > 0xE || !v46) {
                          v48 = 1.0;
                        }
                        else {
                          v48 = 1.0;
                          v49 = dword_104CF04[4 * v46];
                          if ((dword_104CF08[4 * v47] & 0x1F) != 1)
                            goto LABEL_74;
                            while (2) {
                              v53 = &scrVarGlob[4 * v49];
                                if ((v53[2] & 0x1F) != 0x16) {
                                LABEL_74:
                                  a1 = 1.0;
                                  v48 = v48 + 1.0;
                                  v50 =
                                      scrVarGlob[4 * (unsigned __int16)
                                                         word_104CF0E[8 * v47]];
                                  v51 = v50;
                                  if (v47 == v50)
                                    break;
                                  goto LABEL_75;
                                }
                              a1 = (float)(COERCE_FLOAT(
                                               Scr_GetObjectUsage(v49, a1)) /
                                           (float)((float)*(
                                                       (unsigned __int16 *)v53 +
                                                       2) +
                                                   1.0)) +
                                   1.0;
                              v48 = v48 + a1;
                              v50 = scrVarGlob[4 * (unsigned __int16)
                                                       word_104CF0E[8 * v47]];
                              v51 = v50;
                              if (v47 == v50)
                                break;
                            LABEL_75:
                                if ((dword_104CF08[4 * v51] & 0x1Fu) <= 0xE &&
                                    v50) {
                                  v47 = v51;
                                  v52 = 16 * v51 + 17092352;
                                  v49 = dword_104CF04[4 * v51];
                                  if ((*(_DWORD *)(v52 + 8) & 0x1F) == 1)
                                    continue;
                                  goto LABEL_74;
                                }
                              break;
                            }
                        }
                      v102 = v48 + v102;
                      a1 = *v99;
                      v100 = *v99;
                      v54 = v23 + 0x10000;
                      v55 = (unsigned __int16)((dword_100CEC0 + v23 + 0x10000) %
                                                   0xFFFD +
                                               1);
                      v103 = &scrVarGlob[4 * v55];
                      v56 = &scrVarGlob[4 * *(unsigned __int16 *)v103];
                        if ((v56[2] & 0x60) == 0x40) {
                            if (v54 != (unsigned int)v56[2] >> 8) {
                              v55 = *((unsigned __int16 *)v56 + 6);
                              v67 = 4 * v55;
                              if (v103 == &scrVarGlob[4 * v55])
                                goto LABEL_81;
                                while (1) {
                                  v68 =
                                      &scrVarGlob[4 * LOWORD(scrVarGlob[v67])];
                                  if (v54 == (unsigned int)v68[2] >> 8)
                                    break;
                                  v55 = *((unsigned __int16 *)v68 + 6);
                                  v67 = 4 * v55;
                                  if (v103 == &scrVarGlob[4 * v55])
                                    goto LABEL_81;
                                }
                            }
                        }
                        else {
                        LABEL_81:
                          v55 = 0;
                        }
                      v57 = scrVarGlob[4 * v55];
                      v58 = 0.0;
                        if (v57) {
                          v59 = dword_104CF04[4 * v57];
                          v60 = scrVarGlob[4 * (unsigned __int16)
                                                   word_104CF0E[8 * v59]];
                          v61 = v60;
                            if (v59 == v60 ||
                                (dword_104CF08[4 * v60] & 0x1Fu) > 0xE ||
                                !v60) {
                              *v99 = v100 + 1.0;
                              goto LABEL_39;
                            }
                          v58 = 1.0;
                          v62 = dword_104CF04[4 * v60];
                            if ((dword_104CF08[4 * v60] & 0x1F) == 1) {
                                while (1) {
                                  v66 = &scrVarGlob[4 * v62];
                                  if ((v66[2] & 0x1F) != 0x16)
                                    goto LABEL_87;
                                  a1 = (float)(COERCE_FLOAT(Scr_GetObjectUsage(
                                                   v62, a1)) /
                                               (float)((float)*(
                                                           (unsigned __int16 *)
                                                               v66 +
                                                           2) +
                                                       1.0)) +
                                       1.0;
                                  v58 = v58 + a1;
                                  v63 =
                                      scrVarGlob[4 * (unsigned __int16)
                                                         word_104CF0E[8 * v61]];
                                  v64 = v63;
                                  if (v61 == v63)
                                    break;
                                LABEL_88:
                                  if ((dword_104CF08[4 * v64] & 0x1Fu) > 0xE ||
                                      !v63)
                                    break;
                                  v61 = v64;
                                  v65 = 16 * v64 + 17092352;
                                  v62 = dword_104CF04[4 * v64];
                                  if ((*(_DWORD *)(v65 + 8) & 0x1F) != 1)
                                    goto LABEL_87;
                                }
                            }
                            else {
                            LABEL_87:
                              a1 = 1.0;
                              v58 = v58 + 1.0;
                              v63 = scrVarGlob[4 * (unsigned __int16)
                                                       word_104CF0E[8 * v61]];
                              v64 = v63;
                              if (v61 != v63)
                                goto LABEL_88;
                            }
                        }
                      *v99 = v58 + v100;
                      goto LABEL_39;
                    }
                    if (*v101 == 1) {
                      v38 = &scrVarGlob[4 * v24];
                      if ((v38[2] & 0x1F) == 0x16)
                        break;
                    }
                  v25 = 0.0;
                LABEL_38:
                  a1 = v25 + v102;
                  v102 = a1;
                LABEL_39:
                  if (v91 == ++v110)
                    goto LABEL_40;
                }
              v39 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v24]];
              v40 = v39;
                if (v24 == v39 || (dword_104CF08[4 * v39] & 0x1Fu) > 0xE ||
                    !v39) {
                  v25 = 1.0 /
                        (float)((float)*((unsigned __int16 *)v38 + 2) + 1.0);
                  goto LABEL_38;
                }
              v41 = 1.0;
              v42 = dword_104CF04[4 * v39];
              if ((dword_104CF08[4 * v40] & 0x1F) == 1)
                goto LABEL_67;
            LABEL_63:
              a1 = 1.0;
              v41 = v41 + 1.0;
              v43 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v40]];
              v44 = v43;
                if (v40 != v43) {
                    while ((dword_104CF08[4 * v44] & 0x1Fu) <= 0xE && v43) {
                      v40 = v44;
                      v45 = 16 * v44 + 17092352;
                      v42 = dword_104CF04[4 * v44];
                      if ((*(_DWORD *)(v45 + 8) & 0x1F) != 1)
                        goto LABEL_63;
                    LABEL_67:
                      if ((dword_104CF08[4 * v42] & 0x1F) != 0x16)
                        goto LABEL_63;
                      a1 = (float)(COERCE_FLOAT(Scr_GetObjectUsage(v42, a1)) /
                                   (float)((float)LOWORD(
                                               dword_104CF04[4 * v42]) +
                                           1.0)) +
                           1.0;
                      v41 = v41 + a1;
                      v43 = scrVarGlob[4 *
                                       (unsigned __int16)word_104CF0E[8 * v40]];
                      v44 = v43;
                      if (v40 == v43)
                        break;
                    }
                }
              v25 = v41 / (float)((float)*((unsigned __int16 *)v38 + 2) + 1.0);
              goto LABEL_38;
            }
        LABEL_40:
          a1 = v102;
          v112[33] = v102;
          *((_DWORD *)v112 + 32) = v105;
          if (v105 > 0)
            break;
        LABEL_3:
          ++v92;
          v90 += 4;
          if (v92 == 65534)
            goto LABEL_44;
        }
      v26 = (float *)&v115[v105 - 1];
      v27 = v112;
      for (j = 0; j < v105; ++j)
        *v27++ = *v26--;
      ++v92;
      v90 += 4;
    }
  while (v92 != 65534);
LABEL_44:
  qsort(__base, __nel, 0x8Cu,
        (int(__cdecl *)(const void *, const void *))ThreadInfoCompare);
  Com_Printf("********************************\n");
  if (__nel <= 0)
    goto LABEL_118;
  v95 = 0;
    while (2) {
      v29 = (char *)&__base[35 * v95];
      v107 = (float *)v29;
      v108 = v29 + 140;
      v109 = (char **)(v29 + 140);
      v96 = 0;
      v30 = 0.0;
      v31 = 0.0;
      v32 = (float *)v29;
        while (2) {
          ++v96;
          v30 = v30 + v32[33];
          v31 = v31 + v32[34];
            if (__nel > ++v95) {
              v33 = *((_DWORD *)v29 + 32);
                if (v33 > 0) {
                  v113 = (int)v109[32];
                    if (v113 > 0) {
                      v34 = *(char **)v29;
                      v35 = *v109;
                        if (*(char **)v29 != *v109) {
                        LABEL_51:
                          v107 += 35;
                          v108 += 140;
                          v109 += 35;
                          if (v34 != v35)
                            break;
                        LABEL_52:
                          v32 = v107;
                          continue;
                        }
                      v73 = v29;
                      v74 = v108;
                      v104 = 0;
                        while (++v104 != v33 && v104 != v113) {
                          v34 = (char *)*((_DWORD *)v73 + 1);
                          v35 = (char *)*((_DWORD *)v74 + 1);
                          v73 += 4;
                          v74 += 4;
                          if (v35 != v34)
                            goto LABEL_51;
                        }
                    }
                }
              v75 = v33 - *((_DWORD *)v108 + 32);
              v107 += 35;
              v108 += 140;
              v109 += 35;
              if (v75)
                break;
              goto LABEL_52;
            }
          break;
        }
      Com_Printf("count: %d, var usage: %d, endon usage: %d\n", v96, (int)v30,
                 (int)v31);
      Scr_PrintPrevCodePos(PMSG_CONSOLE, *(char **)v29, 0);
        if (*((int *)v29 + 32) > 1) {
          v81 = (char **)v29;
          v82 = 1;
            do {
              Com_Printf("called from:\n");
              Scr_PrintPrevCodePos(PMSG_CONSOLE, v81[1], 0);
              ++v82;
              ++v81;
            }
          while (v82 < *((_DWORD *)v29 + 32));
        }
      if (__nel > v95)
        continue;
      break;
    }
LABEL_118:
  Z_FreeInternal(__base);
  Com_Printf("********************************\n");
  v106 = &g_classMap;
    do {
      v76 = v106[1];
        if (v76) {
          v77 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v76]];
          v78 = v77;
            if (v76 == v77 || (dword_104CF08[4 * v77] & 0x1Fu) > 0xE || !v77) {
              Com_Printf("ent type '%s'... count: %d, var usage: %d\n",
                         *((const char **)v106 + 2), 0, 0);
            }
            else {
              v114 = 0;
              v79 = 0.0;
              v111 = 0.0;
                while (1) {
                  ++v114;
                    if ((dword_104CF08[4 * v78] & 0x1F) == 1) {
                      v83 = dword_104CF04[4 * v78];
                      v84 = scrVarGlob[4 *
                                       (unsigned __int16)word_104CF0E[8 * v83]];
                      v85 = v84;
                        if (v83 == v84 ||
                            (dword_104CF08[4 * v84] & 0x1Fu) > 0xE || !v84) {
                          v86 = 1.0;
                        }
                        else {
                          v86 = 1.0;
                            while (1) {
                                if ((dword_104CF08[4 * v85] & 0x1F) == 1 &&
                                    (v88 = &scrVarGlob[4 *
                                                       dword_104CF04[4 * v85]],
                                     (v88[2] & 0x1F) == 0x16)) {
                                  v79 = (float)(COERCE_FLOAT(Scr_GetObjectUsage(
                                                    dword_104CF04[4 * v85],
                                                    v79)) /
                                                (float)((float)*(
                                                            (unsigned __int16 *)
                                                                v88 +
                                                            2) +
                                                        1.0)) +
                                        1.0;
                                }
                                else {
                                  v79 = 1.0;
                                }
                              v86 = v86 + v79;
                              v87 = scrVarGlob[4 * (unsigned __int16)
                                                       word_104CF0E[8 * v85]];
                              if (v85 == v87 ||
                                  (dword_104CF08[4 * v87] & 0x1Fu) > 0xE ||
                                  !v87)
                                break;
                              v85 = v87;
                            }
                        }
                      v111 = v86 + v111;
                    }
                  v80 = scrVarGlob[4 * (unsigned __int16)word_104CF0E[8 * v78]];
                  if (v78 == v80 || (dword_104CF08[4 * v80] & 0x1Fu) > 0xE ||
                      !v80)
                    break;
                  v78 = v80;
                }
              Com_Printf("ent type '%s'... count: %d, var usage: %d\n",
                         *((const char **)v106 + 2), v114, (int)v111);
            }
        }
      v106 += 6;
    }
  while (&unk_30AA70 != (_UNKNOWN *)v106);
  Com_Printf("********************************\n");
}

unsigned int __cdecl AllocChildThread(unsigned int self,
                                      unsigned int parentLocalId)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl AllocThread(unsigned int self)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_AllocArray()
{
  UNIMPLEMENTED();
}

unsigned int __cdecl AllocObject()
{
  UNIMPLEMENTED();
}

unsigned int __cdecl AllocValue()
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_InitStringSet(void)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_SetClassMap(int classnum)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetArray(unsigned int id)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetObject(unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewObjectVariableReverse(unsigned int parentId,
                                                 unsigned int id)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewObjectVariable(unsigned int parentId,
                                          unsigned int id)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetObjectVariable(unsigned int parentId, unsigned int id)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariable(unsigned int parentId,
                                    unsigned int unsignedValue)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetVariable(unsigned int parentId,
                                 unsigned int unsignedValue)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetVariableField(unsigned int parentId,
                                          unsigned int name)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewArrayVariable(unsigned int parentId,
                                         unsigned int unsignedValue)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetArrayVariable(unsigned int parentId,
                                      unsigned int unsignedValue)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveRefToVector(float const *vectorValue)
{
  __int16 v1; // ax

    if (!*((_BYTE *)a1 - 1)) {
      v1 = *((_WORD *)a1 - 2);
      if (v1)
        *((_WORD *)a1 - 2) = v1 - 1;
      else
        MT_Free((_BYTE *)a1 - 4, 16);
    }
}

unsigned int __cdecl Scr_EvalArrayIndex(unsigned int parentId,
                                        struct VariableValue_s *index)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetEntityId(int entnum, int classnum)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AddClassField(int classnum, char const *name,
                               unsigned int offset)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveRefToValue(int type, union VariableUnion u)
{
  UNIMPLEMENTED();
}

float const *__cdecl Scr_AllocVector(float const *v)
{
  UNIMPLEMENTED();
}

void __cdecl FreeValue(unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_RemoveThreadNotifyName(unsigned int startLocalId)
{
  UNIMPLEMENTED();
}

void __cdecl Var_Shutdown()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CopyEntityNum(int, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_ClearVector(struct VariableValue_s *)
{
  UNIMPLEMENTED();
}

bool __cdecl Scr_CastString(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CastBool(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalBoolComplement(struct VariableValue_s *value)
{
  int32_t type;     // ebx
  VariableUnion v3; // edx
  char *v4;         // eax
  __int16 v5;       // ax

  type = a2->type;
    if (type == 6) {
      a2->u.intValue = ~a2->u.intValue;
    }
    else {
      v3.intValue = (int32_t)a2->u;
        if (type > 3) {
            if (type == 4 && !*(_BYTE *)(v3.intValue - 1)) {
              v5 = *(_WORD *)(v3.intValue - 4);
              if (v5)
                *(_WORD *)(v3.intValue - 4) = v5 - 1;
              else
                MT_Free((_BYTE *)(v3.intValue - 4), 16);
            }
        }
        else if (type < 2) {
          if (type == 1)
            RemoveRefToObject(a1, a2->u.intValue);
        }
        else {
          SL_RemoveRefToString(a1, a2->u.intValue);
        }
      a2->type = 0;
      v4 = va("~ cannot be applied to \"%s\"",
              *(const char **)&var_typename[4 * type]);
      Scr_Error(v4);
    }
}

void __cdecl Scr_EvalBoolNot(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl ClearVariableValue(unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl SetVariableValue(unsigned int id, struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl SetEmptyArray(unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_EvalFieldObject(unsigned int tempVariable,
                                         struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CastVector(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CastDebugString(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl SafeRemoveVariable(unsigned int parentId parentId,
                                unsigned int unsignedValue unsignedValue)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveNextVariable(unsigned int parentId)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveVariable(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AllocGameVariable()
{
  int v1;               // esi
  int *v2;              // ebx
  int *v3;              // ecx
  unsigned __int16 v4;  // di
  int v5;               // esi
  int v6;               // edx
  int *v7;              // ebx
  int *v8;              // ecx
  unsigned __int16 v9;  // ax
  int v10;              // edx
  int v11;              // eax
  int v12;              // ecx
  int v13;              // eax
  unsigned int v14;     // edx
  int v15;              // edx
  __int16 v16;          // ax
  int v17;              // [esp+18h] [ebp-30h]
  int v18;              // [esp+24h] [ebp-24h]
  unsigned __int16 v19; // [esp+28h] [ebp-20h]
  unsigned __int16 v20; // [esp+2Ah] [ebp-1Eh]
  unsigned __int16 v21; // [esp+2Ch] [ebp-1Ch]
  unsigned __int16 v22; // [esp+2Eh] [ebp-1Ah]

    if (!dword_100CEC8) {
      v20 = dword_104CF04[0];
      if (!LOWORD(dword_104CF04[0]))
        Scr_TerminalError(a1, "exceeded maximum number of script variables");
      v1 = 4 * v20;
      v2 = &scrVarGlob[v1];
      v19 = scrVarGlob[v1];
      v3 = &scrVarGlob[4 * v19];
      v4 = *((_WORD *)v3 + 2);
        if (&scrVarGlob[v1] != v3 && (v2[2] & 0x60) == 0) {
          LOWORD(scrVarGlob[4 * *((unsigned __int16 *)v2 + 6)]) = v19;
          LOWORD(scrVarGlob[4 * v20]) = v20;
          *((_WORD *)v3 + 6) = *((_WORD *)v2 + 6);
          *((_WORD *)v3 + 2) = *((_WORD *)v2 + 2);
          v3 = &scrVarGlob[v1];
        }
      LOWORD(dword_104CF04[0]) = v4;
      v5 = 4 * v4;
      HIWORD(scrVarGlob[v5]) = 0;
      *((_WORD *)v3 + 6) = v20;
      *((_WORD *)v3 + 7) = v20;
      *((_WORD *)v2 + 1) = v20;
      v6 = *(unsigned __int16 *)v2;
      v18 = 16 * v6 + 17092352;
      dword_104CF08[4 * v6] = 96;
      dword_100CEC8 = v6;
      if (!v4)
        Scr_TerminalError(a1, "exceeded maximum number of script variables");
      v7 = &scrVarGlob[v5];
      v21 = scrVarGlob[4 * v4];
      v8 = &scrVarGlob[4 * v21];
      v22 = *((_WORD *)v8 + 2);
        if (&scrVarGlob[v5] == v8) {
          v9 = *((_WORD *)v8 + 2);
        }
        else {
            if ((v7[2] & 0x60) == 0) {
              LOWORD(scrVarGlob[4 * *((unsigned __int16 *)v7 + 6)]) = v21;
              LOWORD(scrVarGlob[4 * v4]) = v4;
              *((_WORD *)v8 + 6) = *((_WORD *)v7 + 6);
              *((_WORD *)v8 + 2) = *((_WORD *)v7 + 2);
              v8 = &scrVarGlob[v5];
            }
          v9 = v22;
        }
      LOWORD(dword_104CF04[0]) = v9;
      HIWORD(scrVarGlob[4 * v9]) = 0;
      *((_WORD *)v8 + 6) = v4;
      *((_WORD *)v8 + 7) = v4;
      *((_WORD *)v7 + 1) = v4;
      v10 = *(unsigned __int16 *)v7;
      v11 = 16 * v10 + 17092352;
      *(_DWORD *)(v11 + 8) = 118;
      *(_WORD *)(v11 + 4) = 0;
      *(_WORD *)(v11 + 6) = 0;
      v17 = v10;
      v12 = *(_DWORD *)(v18 + 4);
      v13 = *(_DWORD *)(v18 + 8);
      v14 = v13 & 0x1F;
        if (v14 > 3) {
            if (v14 == 4 && !*(_BYTE *)(v12 - 1)) {
              v16 = *(_WORD *)(v12 - 4);
              if (v16)
                *(_WORD *)(v12 - 4) = v16 - 1;
              else
                MT_Free((_BYTE *)(v12 - 4), 16);
              v15 = v18;
              v13 = *(_DWORD *)(v18 + 8);
              goto LABEL_16;
            }
        }
        else {
            if ((*(_DWORD *)(v18 + 8) & 0x1Fu) >= 2) {
              SL_RemoveRefToString(a1, *(_DWORD *)(v18 + 4));
              v15 = v18;
              v13 = *(_DWORD *)(v18 + 8);
            LABEL_16:
              *(_DWORD *)(v15 + 8) = v13 & 0xFFFFFFE0 | 1;
              *(_DWORD *)(v15 + 4) = v17;
              return;
            }
            if (v14 == 1) {
              RemoveRefToObject(a1, *(_DWORD *)(v18 + 4));
              v15 = v18;
              v13 = *(_DWORD *)(v18 + 8);
              goto LABEL_16;
            }
        }
      v15 = v18;
      goto LABEL_16;
    }
}

void __cdecl Scr_UnmatchingTypesError(struct VariableValue_s *value1,
                                      struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveObjectVariable(unsigned int parentId, unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl ClearObject(unsigned int parentId)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeGameVariable(int bComplete)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeEntityNum(int entnum, int classnum)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalMod(struct VariableValue_s *value1,
                         struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalShiftRight(struct VariableValue_s *value1,
                                struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalShiftLeft(struct VariableValue_s *value1,
                               struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalAnd(struct VariableValue_s *value1,
                         struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalExOr(struct VariableValue_s *value1,
                          struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalOr(struct VariableValue_s *value1,
                        struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveRefToObject(unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_KillEndonThread(unsigned int threadId)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_ShutdownStringSet(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeValue(unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalArray(struct VariableValue_s *value,
                           struct VariableValue_s *index)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_RemoveClassMap(int classnum)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalDivide(struct VariableValue_s *value1,
                            struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalMultiply(struct VariableValue_s *value1,
                              struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalMinus(struct VariableValue_s *value1,
                           struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalPlus(struct VariableValue_s *value1,
                          struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalGreater(struct VariableValue_s *value1,
                             struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalLess(struct VariableValue_s *value1,
                          struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalEquality(struct VariableValue_s *value1,
                              struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalSizeValue(struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_KillThread(unsigned int parentId)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_StopThread(unsigned int threadId)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalLessEqual(struct VariableValue_s *value1,
                               struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalGreaterEqual(struct VariableValue_s *value1,
                                  struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalInequality(struct VariableValue_s *value1,
                                struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl SetVariableEntityFieldValue(unsigned int entId,
                                         unsigned int fieldName,
                                         struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl ClearVariableField(unsigned int parentId, unsigned int name,
                                struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeObjects()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeEntityList()
{
  UNIMPLEMENTED();
}

void __cdecl Scr_EvalBinaryOperator(int op, struct VariableValue_s *value1,
                                    struct VariableValue_s *value2)
{
  UNIMPLEMENTED();
}

void __cdecl SetVariableFieldValue(unsigned int id,
                                   struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

bool __cdecl Scr_AddStringSet(unsigned int, char const *)
{
  UNIMPLEMENTED();
}

void __cdecl ClearArray(unsigned int parentId, struct VariableValue_s *value)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_EvalArrayRef(unsigned int parentId)
{
  UNIMPLEMENTED();
}

struct VariableValue_s __cdecl Scr_FindVariableField(unsigned int parentId,
                                                     unsigned int name)
{
  UNIMPLEMENTED();
}

struct VariableValue_s __cdecl Scr_EvalVariableField(unsigned int id)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AddFields(char const *path, char const *extension)
{
  UNIMPLEMENTED();
}

struct scr_classStruct_t *g_classMap;
char const **var_typename;
int marker_scr_variable;
struct scrVarGlob_t scrVarGlob;
struct scrVarDebugPub_t scrVarDebugPub;
struct scrVarPub_t scrVarPub;

float __cdecl Scr_GetEntryUsage(unsigned int, union VariableUnion)
{
  UNIMPLEMENTED();
}

void __cdecl FreeVariable(unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl FindVariableIndexInternal2(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl InitVariables(void)
{
  UNIMPLEMENTED();
}

int __cdecl ThreadInfoCompare(void const *, void const *)
{
  _DWORD *v2; // edi
  int v3;     // ecx
  int v4;     // ebx
  int v6;     // esi
  int v7;     // edx
  int v8;     // eax
  _DWORD *v9; // [esp+0h] [ebp-10h]

  v2 = a2;
  v3 = a1[32];
    if (v3 <= 0) {
      v4 = a2[32];
      return v3 - v4;
    }
  v4 = a2[32];
  if (v4 <= 0)
    return v3 - v4;
    if (*a2 == *a1) {
      v9 = a1;
      v6 = 0;
        while (++v6 != v3 && v6 != v4) {
          v7 = v9[1];
          v8 = v2[1];
          ++v9;
          ++v2;
          if (v8 != v7)
            return v7 - v8;
        }
      return v3 - v4;
    }
  return *a1 - *a2;
}

float __cdecl Scr_GetEntryUsage(struct VariableValueInternal *)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl FindVariableIndexInternal(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

float __cdecl Scr_GetObjectUsage(unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl FindArrayVariableIndex(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

float __cdecl Scr_GetEndonUsage(unsigned int)
{
  UNIMPLEMENTED();
}

float __cdecl Scr_GetThreadUsage(class VariableStackBuffer const *, float *)
{
  UNIMPLEMENTED();
}

unsigned short __cdecl AllocVariable(void)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariableIndexInternal3(unsigned int, unsigned int,
                                                  unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl AllocEntity(int, unsigned short)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariableIndexReverseInternal2(unsigned int,
                                                         unsigned int,
                                                         unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariableIndexInternal2(unsigned int, unsigned int,
                                                  unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetVariableIndexInternal(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariableIndexReverseInternal(unsigned int,
                                                        unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewVariableIndexInternal(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl CopyArray(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetNewArrayVariableIndex(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

unsigned int __cdecl GetArrayVariableIndex(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl CopyEntity(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

float *__cdecl Scr_AllocVector(void)
{
  float *result; // eax

  result = (float *)(MT_Alloc(16, 2) + 1);
  *(result - 1) = 0.0;
  *result = *a1;
  result[1] = a1[1];
  result[2] = a1[2];
  return result;
}

unsigned int __cdecl Scr_FindArrayIndex(unsigned int, struct VariableValue_s *)
{
  UNIMPLEMENTED();
}

void __cdecl MakeVariableExternal(struct VariableValueInternal *,
                                  struct VariableValueInternal *)
{
  UNIMPLEMENTED();
}

void __cdecl SafeRemoveArrayVariable(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl ClearObjectInternal(unsigned int)
{
  UNIMPLEMENTED();
}

int __cdecl Scr_MakeValuePrimitive(unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl RemoveArrayVariable(unsigned int, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CastWeakerStringPair(struct VariableValue_s *,
                                      struct VariableValue_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_CastWeakerPair(struct VariableValue_s *,
                                struct VariableValue_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_ClearThread(unsigned int)
{
  UNIMPLEMENTED();
}

struct VariableValue_s __cdecl Scr_EvalVariableEntityField(unsigned int,
                                                           unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Scr_AddFieldsForFile(char const *)
{
  UNIMPLEMENTED();
}

GetObjectA(unsigned int id)
{
  UNIMPLEMENTED();
}
