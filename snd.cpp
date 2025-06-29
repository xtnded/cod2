void __cdecl MemFile_WriteShort(struct MemoryFile *, short)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_WriteInt(struct MemoryFile *, int)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_WriteFloat(struct MemoryFile *, float)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_WriteVec3(struct MemoryFile *, float const *const)
{
  UNIMPLEMENTED();
}

short __cdecl MemFile_ReadShort(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

int __cdecl MemFile_ReadInt(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

float __cdecl MemFile_ReadFloat(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl MemFile_ReadVec3(struct MemoryFile *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl SND_ErrorCleanup()
{
    if (dword_FFD81C) {
      Z_FreeInternal(dword_FFD81C);
      dword_FFD81C = 0;
    }
}

void __cdecl SND_ResetPauseSettingsToDefaults(void)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SetPauseSettings(bool const *const)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_IsAliasChannel3D(int)
{
  return a1 > 0xA || ((1 << a1) & 0x786) == 0;
}

float __cdecl SND_GetLerpedSlavePercentage(float baseSlavePercentage)
{
  return (float)(1.0 - (float)((float)(1.0 - a1) * *(float *)&dword_FFDA74));
}

void __cdecl SND_RestoreListeners(struct snd_listener *)
{
  int32_t result; // eax

  *(float *)stru_FFDAF4.pszAliasName = a1->orient.origin[0];
  stru_FFDAF4.pszSubtitle = LODWORD(a1->orient.origin[1]);
  *(float *)stru_FFDAF4.pszSecondaryAliasName = a1->orient.origin[2];
  *(_QWORD *)stru_FFDAF4.soundFile = *(_QWORD *)&a1->orient.axis[0][0];
  stru_FFDAF4.fVolMin = LODWORD(a1->orient.axis[0][2]);
  *(_QWORD *)&stru_FFDAF4.fVolMax = *(_QWORD *)&a1->orient.axis[1][0];
  stru_FFDAF4.fPitchMax = LODWORD(a1->orient.axis[1][2]);
  *(_QWORD *)&stru_FFDAF4.fDistMin = *(_QWORD *)&a1->orient.axis[2][0];
  stru_FFDAF4.flags = LODWORD(a1->orient.axis[2][2]);
  stru_FFDAF4.fSlavePercentage = a1->entnum;
  result = *(_DWORD *)&a1->active;
  stru_FFDAF4.fProbability = result;
  return result;
}

void __cdecl SND_SaveListeners(struct snd_listener *listeners)
{
  int32_t result; // eax

  a1->orient.origin[0] = *(float *)stru_FFDAF4.pszAliasName;
  LODWORD(a1->orient.origin[1]) = stru_FFDAF4.pszSubtitle;
  a1->orient.origin[2] = *(float *)stru_FFDAF4.pszSecondaryAliasName;
  *(_QWORD *)&a1->orient.axis[0][0] = *(_QWORD *)stru_FFDAF4.soundFile;
  LODWORD(a1->orient.axis[0][2]) = stru_FFDAF4.fVolMin;
  *(_QWORD *)&a1->orient.axis[1][0] = *(_QWORD *)&stru_FFDAF4.fVolMax;
  LODWORD(a1->orient.axis[1][2]) = stru_FFDAF4.fPitchMax;
  *(_QWORD *)&a1->orient.axis[2][0] = *(_QWORD *)&stru_FFDAF4.fDistMin;
  LODWORD(a1->orient.axis[2][2]) = stru_FFDAF4.flags;
  a1->entnum = stru_FFDAF4.fSlavePercentage;
  result = stru_FFDAF4.fProbability;
  *(_DWORD *)&a1->active = stru_FFDAF4.fProbability;
  return result;
}

bool __cdecl SND_AnyActiveListeners(void)
{
  UNIMPLEMENTED();
}

void __cdecl SND_DeactivateChannelVolumes(int priority, int fademsec)
{
  int result; // eax
  char *v3;   // edi
  int v4;     // edx
  int v5;     // esi
  float v6;   // xmm1_4
  char *v7;   // eax
  _DWORD *v8; // ecx
  int v9;     // esi
  int v10;    // ebx
  int v11;    // ebx
  int v12;    // ecx
  char v13;   // al

  result = a1 << 7;
  v3 = (char *)&unk_FFD834 + 136 * a1;
  v3[132] = 0;
    if (v3 == (char *)dword_FFDA54) {
      v4 = a1 - 1;
        if (a1 - 1 < 0 || byte_FFD8B8[136 * v4]) {
          v5 = a1 - 1;
        }
        else {
          v11 = 136 * a1 + 16766756;
          v5 = a1 - 1;
          v12 = 0;
            do {
              --v5;
              if (v12 == v4)
                break;
              v13 = *(_BYTE *)(v11 + 132);
              ++v12;
              v11 -= 136;
            }
          while (!v13);
        }
      if (a2 <= 0)
        v6 = 1.0;
      else
        v6 = (float)a2;
      v7 = (char *)&unk_FFD834 + 136 * v5;
      dword_FFDA54 = (int)v7;
      v8 = (_DWORD *)((char *)&unk_FFD834 + 136 * a1);
      v9 = 0;
      v10 = 0;
        while (1) {
          *(_DWORD *)&v7[v10] = *v8;
          result = dword_FFDA54 + v10;
          *(float *)(dword_FFDA54 + v10 + 8) =
              (float)(*(float *)(dword_FFDA54 + v10 + 4) - *(float *)v8) / v6;
          ++v9;
          v10 += 12;
          v8 += 3;
          if (v9 == 11)
            break;
          v7 = (char *)dword_FFDA54;
        }
    }
  return result;
}

void __cdecl SND_SetChannelVolumes(int priority,
                                   float const *const channelvolume,
                                   int fademsec)
{
  char *v3;   // edi
  float v4;   // xmm2_4
  float *v5;  // edx
  int v6;     // esi
  int v7;     // ebx
  int result; // eax
  float v10;  // xmm1_4
  int v11;    // ecx
  char *v12;  // edx

  v3 = (char *)&unk_FFD834 + 136 * a1;
  v3[132] = 1;
  if (a3 <= 0)
    v4 = 1.0;
  else
    v4 = (float)a3;
  v5 = (float *)((char *)&unk_FFD834 + 136 * a1);
  v6 = 0;
  v7 = 0;
    do {
      v5[1] = *a2;
      result = dword_FFDA54;
      v10 = *(float *)(v7 + dword_FFDA54);
      *v5 = v10;
      v5[2] = (float)(*a2 - v10) / v4;
      ++v6;
      ++a2;
      v7 += 12;
      v5 += 3;
    }
  while (v6 != 11);
    if (v3 != (char *)dword_FFDA54) {
      v11 = a1 + 1;
        if (a1 + 1 > 3) {
        LABEL_12:
          dword_FFDA54 = (int)&unk_FFD834 + 136 * a1;
          return result;
        }
      result = v11 << 7;
        if (!byte_FFD8B8[136 * v11]) {
          result = a1 << 7;
          v12 = (char *)&unk_FFD944 + 136 * a1;
            while (++v11 != 4) {
              result = (unsigned __int8)v12[132];
              v12 += 136;
              if ((_BYTE)result)
                return result;
            }
          goto LABEL_12;
        }
    }
  return result;
}

float __cdecl SND_Attenuate(struct SndCurve *volumeFalloffCurve, float radius,
                            float mindist, float maxdist)
{
  float v4;           // xmm1_4
  long double result; // fst7

  v4 = a2 - a3;
  result = 0.0;
  if ((float)(a2 - a3) <= 0.0)
    return 1.0;
  if (a3 != a4 && (float)(v4 / (float)(a4 - a3)) < 1.0)
    Com_GetVolumeFalloffCurveValue(a1, v4 / (float)(a4 - a3));
  return result;
}

int __cdecl SND_GetListenerIndexNearestToOrigin(float const *const origin)
{
  return 0;
}

int __cdecl SND_GetLocalListenerIndex(void)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SetListener(int entnum, float const * const origin, float const  axis)[3])
{
  UNIMPLEMENTED();
}

void __cdecl SND_DisconnectListener()
{
  int result; // eax

  result = 0;
  memset(&stru_FFDAF4, 0, 0x38u);
  return result;
}

void __cdecl SND_UpdateReverbs()
{
  int result; // eax
  int v1;     // ebx
  int v2;     // ebx
  int v3;     // ebx

    if (dword_FFEBC8 > 0) {
      v1 = 0;
        do {
          if (!SND_Is3DChannelFree(v1))
            SND_Update3DChannelReverb(v1);
          ++v1;
        }
      while (v1 < dword_FFEBC8);
    }
    if (dword_FFEBC4 + 45 > 45) {
      v3 = 45;
        do {
          if (!SND_Is2DChannelFree(v3))
            SND_Update2DChannelReverb(v3);
          ++v3;
        }
      while (v3 < dword_FFEBC4 + 45);
    }
  result = dword_FFEBCC + 32;
    if (dword_FFEBCC + 32 > 32) {
      v2 = 32;
        do {
          if (!(unsigned __int8)SND_IsStreamChannelFree(v2))
            SND_UpdateStreamChannelReverb(v2);
          ++v2;
          result = dword_FFEBCC + 32;
        }
      while (v2 < dword_FFEBCC + 32);
    }
  return result;
}

void __cdecl SND_DeactivateEnvironmentEffects(int priority, int fademsec)
{
  int *v2;    // edi
  int v3;     // esi
  int v4;     // ebx
  int result; // eax
  int v6;     // edx
  int v7;     // ecx
  char v8;    // al
  float v9;   // [esp+1Ch] [ebp-1Ch]

  v2 = &dword_FFDA78[8 * a1];
  *((_BYTE *)v2 + 28) = 0;
    if (v2 == (int *)dword_FFDAD8) {
      v3 = a1 - 1;
        if (a1 - 1 < 0 || byte_FFDA94[32 * v3]) {
          v4 = a1 - 1;
        }
        else {
          v6 = 32 * a1 + 16767544;
          v4 = a1 - 1;
          v7 = 0;
            do {
              --v4;
              if (v7 == v3)
                break;
              v8 = *(_BYTE *)(v6 + 28);
              ++v7;
              v6 -= 32;
            }
          while (!v8);
        }
      if (a2 <= 0)
        v9 = 1.0;
      else
        v9 = (float)a2;
      dword_FFDAD8 = (int)&dword_FFDA70[8 * v4 + 2];
      SND_SetRoomtype(*(_DWORD *)dword_FFDAD8);
      *(_DWORD *)(dword_FFDAD8 + 4) = v2[1];
      *(float *)(dword_FFDAD8 + 12) =
          (float)(*(float *)(dword_FFDAD8 + 8) - *((float *)v2 + 1)) / v9;
      *(_DWORD *)(dword_FFDAD8 + 16) = v2[4];
      result = dword_FFDAD8;
      *(float *)(dword_FFDAD8 + 24) =
          (float)(*(float *)(dword_FFDAD8 + 20) - *((float *)v2 + 4)) / v9;
    }
  return result;
}

bool __cdecl SND_UpdateBackgroundVolume(int track, int frametime)
{
  int v2;   // edx
  float v3; // xmm0_4
  float v4; // xmm1_4
  int v5;   // xmm0_4
  int v6;   // eax
  int v8;   // eax

  v2 = a1 + 32;
  v3 = dword_FFDA5C[2 * a1];
  v4 = (float)((float)a2 * v3) + *(float *)&dword_FFDB48[20 * a1 + 640];
    if (v3 > 0.0) {
      v5 = dword_FFDA58[2 * a1];
        if (v4 <= *(float *)&v5) {
        LABEL_3:
          v6 = 20 * v2;
          dword_FFDB40[v6] = stru_FFDAF4.startDelay;
          *(float *)&dword_FFDB40[v6 + 2] = v4;
          return 1;
        }
    LABEL_6:
      v8 = 20 * v2;
      dword_FFDB40[v8] = stru_FFDAF4.startDelay;
      dword_FFDB40[v8 + 2] = v5;
      return 1;
    }
  v5 = dword_FFDA58[2 * a1];
  if (*(float *)&v5 <= v4)
    goto LABEL_3;
  if (*(float *)&v5 != 0.0)
    goto LABEL_6;
  SND_StopStreamChannel(a1 + 32);
  return 0;
}

void __cdecl SND_UpdateLoopingSounds()
{
  int v0;   // ebx
  char *v1; // esi
  int v2;   // ebx
  char *v3; // esi
  int v4;   // ebx
  char *v5; // esi

    if (g_snd[0] && !byte_FFD802) {
        if (dword_FFEBC8 > 0) {
          v0 = 0;
          v1 = g_snd;
            do {
                if (!SND_Is3DChannelFree(v0) &&
                    (*(_BYTE *)(*((_DWORD *)v1 + 214) + 44) & 1) != 0 &&
                    *((_DWORD *)v1 + 208) != stru_FFDAF4.startDelay) {
                  SND_Stop3DChannel(v0);
                }
              ++v0;
              v1 += 80;
            }
          while (v0 < dword_FFEBC8);
            if (dword_FFEBC4 + 45 <= 45) {
            LABEL_5:
                if (dword_FFEBCC + 32 <= 32) {
                LABEL_6:
                  stru_FFDAF4.startDelay = stru_FFDAF4.fLfePercentage;
                  return;
                }
            LABEL_22:
              v4 = 32;
              v5 = g_snd;
                do {
                    if (!(unsigned __int8)SND_IsStreamChannelFree(v4) &&
                        (*(_BYTE *)(*((_DWORD *)v5 + 854) + 44) & 1) != 0 &&
                        *((_DWORD *)v5 + 848) != stru_FFDAF4.startDelay) {
                      SND_StopStreamChannel(v4);
                    }
                  ++v4;
                  v5 += 80;
                }
              while (v4 < dword_FFEBCC + 32);
              goto LABEL_6;
            }
        }
        else if (dword_FFEBC4 + 45 <= 45) {
          goto LABEL_5;
        }
      v2 = 45;
      v3 = g_snd;
        do {
            if (!SND_Is2DChannelFree(v2) &&
                (*(_BYTE *)(*((_DWORD *)v3 + 1114) + 44) & 1) != 0 &&
                *((_DWORD *)v3 + 1108) != stru_FFDAF4.startDelay) {
              SND_Stop2DChannel(v2);
            }
          ++v2;
          v3 += 80;
        }
      while (v2 < dword_FFEBC4 + 45);
      if (dword_FFEBCC + 32 <= 32)
        goto LABEL_6;
      goto LABEL_22;
    }
}

int __cdecl SND_FindFree3DChannel(int entnum, int entchannel)
{
  int v2;    // ebx
  int v4;    // eax
  int v5;    // edi
  int v6;    // ecx
  int v7;    // ecx
  int v8;    // eax
  int v9;    // ecx
  int v10;   // eax
  int v11;   // [esp+18h] [ebp-20h]
  char *v12; // [esp+1Ch] [ebp-1Ch]

  if (dword_FFEBC8 <= 0)
    return -1;
  v2 = 0;
    do {
      if (SND_Is3DChannelFree(v2))
        return v2;
      ++v2;
    }
  while (dword_FFEBC8 > v2);
  if (dword_FFEBC8 <= 0)
    return -1;
  v11 = 0;
  v2 = -1;
  v12 = g_snd;
    do {
      v4 = *((_DWORD *)v12 + 206);
      if (a2 < v4)
        goto LABEL_17;
      if (v2 < 0)
        goto LABEL_20;
      v5 = *((_DWORD *)v12 + 205);
      v6 = *(&stru_FFDAF4.volumeFalloffCurve + 20 * v2);
        if (v5 != v6) {
          if (a1 == v5)
            goto LABEL_20;
          if (a1 == v6)
            goto LABEL_17;
        }
      v7 = dword_FFDB38[20 * v2];
        if (v4 != v7) {
          v8 = v4 - v7;
          goto LABEL_16;
        }
      v9 = *((_DWORD *)v12 + 209);
      v10 = dword_FFDB44[20 * v2];
        if (v9 != v10) {
          v8 = v9 - v10;
        LABEL_16:
          if (v8 >= 0)
            goto LABEL_17;
        LABEL_20:
          v2 = v11;
        }
    LABEL_17:
      ++v11;
      v12 += 80;
    }
  while (v11 != dword_FFEBC8);
  if (v2 < 0)
    return v2;
  SND_Stop3DChannel(v2);
  return v2;
}

int __cdecl SND_FindFree2DChannel(int entnum, int entchannel)
{
  int v2;   // eax
  int v3;   // ebx
  char *v4; // edi
  int v5;   // eax
  int v6;   // esi
  int v7;   // ecx
  int v8;   // ecx
  int v9;   // eax
  int v11;  // ecx
  int v12;  // eax
  int v13;  // esi
  int v14;  // [esp+18h] [ebp-20h]
  int v15;  // [esp+1Ch] [ebp-1Ch]

  v2 = dword_FFEBC4;
    if (dword_FFEBC4 > 0) {
      v13 = 0;
        do {
          v3 = v13 + 45;
          if (SND_Is2DChannelFree(v13 + 45))
            return v3;
          ++v13;
          v2 = dword_FFEBC4;
        }
      while (dword_FFEBC4 > v13);
    }
  v14 = v2 + 45;
  if (v2 + 45 <= 45)
    return -1;
  v15 = 45;
  v3 = -1;
  v4 = g_snd;
    do {
      v5 = *((_DWORD *)v4 + 1106);
      if (a2 < v5)
        goto LABEL_12;
      if (v3 < 0)
        goto LABEL_17;
      v6 = *((_DWORD *)v4 + 1105);
      v7 = *(&stru_FFDAF4.volumeFalloffCurve + 20 * v3);
        if (v6 != v7) {
          if (a1 == v6)
            goto LABEL_17;
          if (a1 == v7)
            goto LABEL_12;
        }
      v8 = dword_FFDB38[20 * v3];
        if (v5 != v8) {
          v9 = v5 - v8;
          goto LABEL_11;
        }
      v11 = *((_DWORD *)v4 + 1109);
      v12 = dword_FFDB44[20 * v3];
        if (v11 != v12) {
          v9 = v11 - v12;
        LABEL_11:
          if (v9 >= 0)
            goto LABEL_12;
        LABEL_17:
          v3 = v15;
        }
    LABEL_12:
      ++v15;
      v4 += 80;
    }
  while (v15 != v14);
    if (v3 >= 0) {
      SND_Stop2DChannel(v3);
      return v3;
    }
  return v3;
}

void __cdecl SND_StopSounds(enum snd_stopsounds_arg_t which)
{
  int v1;           // esi
  int *v2;          // ebx
  int v3;           // edx
  int *v4;          // ecx
  int v5;           // edi
  char v6;          // al
  int v7;           // ebx
  int v8;           // edi
  char *v9;         // edx
  int v10;          // esi
  char *v11;        // eax
  char *v12;        // ecx
  int v13;          // esi
  int v14;          // ebx
  unsigned int v15; // eax
  int v16;          // ebx
  int *v17;         // ecx
  char v18;         // al
  int v19;          // ebx
  int v20;          // ebx
  int v21;          // ebx
  int v22;          // ebx
  int v23;          // ebx
  int v24;          // [esp+10h] [ebp-28h]
  char *v25;        // [esp+14h] [ebp-24h]
  int v26;          // [esp+18h] [ebp-20h]
  char *v27;        // [esp+1Ch] [ebp-1Ch]

  if (!g_snd[0])
    return;
    if ((a1 & 8) == 0) {
        if (dword_FFEBC4 + 45 > 45) {
          v20 = 45;
            do {
              if (!SND_Is2DChannelFree(v20))
                SND_Stop2DChannel(v20);
              ++v20;
            }
          while (dword_FFEBC4 + 45 > v20);
        }
        if (dword_FFEBC8 > 0) {
          v19 = 0;
            do {
              if (!SND_Is3DChannelFree(v19))
                SND_Stop3DChannel(v19);
              ++v19;
            }
          while (dword_FFEBC8 > v19);
        }
    }
    if (dword_FFEBCC + 32 > 32) {
      v15 = ((unsigned int)a1 >> 1) & 1;
        if ((a1 & 4) != 0) {
            if (v15) {
              v23 = 32;
                do {
                  if (!(unsigned __int8)SND_IsStreamChannelFree(v23) &&
                      v23 != 32 && (unsigned int)(v23 - 33) > 1)
                    SND_StopStreamChannel(v23);
                  ++v23;
                }
              while (dword_FFEBCC + 32 > v23);
            }
            else {
              v22 = 32;
                do {
                  if (!(unsigned __int8)SND_IsStreamChannelFree(v22) &&
                      (unsigned int)(v22 - 33) > 1)
                    SND_StopStreamChannel(v22);
                  ++v22;
                }
              while (dword_FFEBCC + 32 > v22);
            }
        }
        else {
            if (!v15) {
              v16 = 32;
                do {
                  if (!(unsigned __int8)SND_IsStreamChannelFree(v16))
                    SND_StopStreamChannel(v16);
                  ++v16;
                }
              while (v16 < dword_FFEBCC + 32);
              if ((a1 & 1) == 0)
                goto LABEL_7;
              goto LABEL_16;
            }
          v21 = 32;
            do {
              if (!(unsigned __int8)SND_IsStreamChannelFree(v21) && v21 != 32)
                SND_StopStreamChannel(v21);
              ++v21;
            }
          while (dword_FFEBCC + 32 > v21);
        }
    }
    if ((a1 & 1) == 0) {
    LABEL_7:
      v26 = 0;
      v27 = g_snd;
      v1 = 1;
      v2 = (int *)&unk_FFDA98;
      unk_FFDAB4 = 0;
      if (&unk_FFDA98 == (_UNKNOWN *)dword_FFDAD8)
        goto LABEL_10;
        while (1) {
          v27 += 32;
          if (v1 == 2)
            break;
            while (1) {
              v26 = v1++;
              v2 = &dword_FFDA78[8 * v1];
              *((_BYTE *)v2 + 28) = 0;
              if (v2 != (int *)dword_FFDAD8)
                break;
            LABEL_10:
              v3 = v26;
                if (v26 >= 0 && !v27[660]) {
                  v4 = &dword_FFDA58[8 * v26];
                  v5 = 0;
                    do {
                      --v3;
                      if (v5 == v26)
                        break;
                      v6 = *((_BYTE *)v4 + 28);
                      ++v5;
                      v4 -= 8;
                    }
                  while (!v6);
                }
              dword_FFDAD8 = 32 * v3 + 16767608;
              SND_SetRoomtype(dword_FFDA78[8 * v3]);
              *(_DWORD *)(dword_FFDAD8 + 4) = v2[1];
              *(float *)(dword_FFDAD8 + 12) =
                  *(float *)(dword_FFDAD8 + 8) - *((float *)v2 + 1);
              *(_DWORD *)(dword_FFDAD8 + 16) = v2[4];
              *(float *)(dword_FFDAD8 + 24) =
                  *(float *)(dword_FFDAD8 + 20) - *((float *)v2 + 4);
              v27 += 32;
              if (v1 == 2)
                goto LABEL_16;
            }
        }
    }
LABEL_16:
    if ((a1 & 0x10) == 0) {
      v7 = 0;
      v25 = g_snd;
      v8 = 1;
      v9 = (char *)&unk_FFD8BC;
      unk_FFD940 = 0;
      if (&unk_FFD8BC == (_UNKNOWN *)dword_FFDA54)
        goto LABEL_20;
        while (1) {
          v25 += 136;
          if (v8 == 3)
            break;
            while (1) {
              v7 = v8++;
              v9 = (char *)&unk_FFD834 + 136 * v8;
              v9[132] = 0;
              if (v9 != (char *)dword_FFDA54)
                break;
            LABEL_20:
              v10 = v7;
                if (v7 >= 0 && !v25[184]) {
                  v17 = &snd_errorOnMissing[34 * v7];
                  v24 = 0;
                    do {
                      --v10;
                      if (v24 == v7)
                        break;
                      v18 = *((_BYTE *)v17 + 132);
                      ++v24;
                      v17 -= 34;
                    }
                  while (!v18);
                }
              v11 = (char *)&unk_FFD834 + 136 * v10;
              dword_FFDA54 = (int)v11;
              v12 = v9;
              v13 = 0;
              v14 = 0;
                while (1) {
                  *(_DWORD *)&v11[v14] = *(_DWORD *)v12;
                  *(float *)(dword_FFDA54 + v14 + 8) =
                      *(float *)(dword_FFDA54 + v14 + 4) - *(float *)v12;
                  ++v13;
                  v14 += 12;
                  v12 += 12;
                  if (v13 == 11)
                    break;
                  v11 = (char *)dword_FFDA54;
                }
              v25 += 136;
              if (v8 == 3)
                return;
            }
        }
    }
}

void __cdecl SND_FadeAllSounds(float volume, int fadetime)
{
  dword_FFD82C = a1;
  *(float *)&dword_FFD830 = *(float *)&a1 - *(float *)&dword_FFD828;
    if (a2) {
      *(float *)&dword_FFD830 =
          (float)(*(float *)&a1 - *(float *)&dword_FFD828) / (float)a2;
    }
    else if (*(float *)&a1 == 0.0) {
      SND_StopSounds(SND_STOP_ALL);
    }
}

void __cdecl SND_StopMusic(int fadetime)
{
    if (!(unsigned __int8)SND_IsStreamChannelFree(32)) {
        if (a1) {
            if (*(float *)dword_FFDA58 > 0.0) {
              dword_FFDA5C[0] = (float)-*(float *)dword_FFDA58 / (float)a1;
              dword_FFDA58[0] = 0;
            }
        }
        else {
          SND_StopStreamChannel(32);
        }
    }
}

void __cdecl SND_RestoreEventually(void const *, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_ShutdownChannels()
{
  UNIMPLEMENTED();
}

void __cdecl SND_SetChannelInfo(int index, int entnum,
                                struct snd_alias_t const *pAlias0,
                                struct snd_alias_t const *pAlias1, float lerp,
                                float const *const origin, float volume,
                                float pitch, int srcChannelCount, int baserate,
                                int total_msec, int start_msec, int startDelay,
                                bool master, enum snd_alias_system_t system)
{
  unsigned int v15; // ecx
  float v16;        // xmm2_4
  float v17;        // xmm3_4
  float v18;        // xmm4_4
  int v19;          // eax
  int v20;          // ecx
  _DWORD *v21;      // eax
  int v22;          // edx
  bool v23;         // cl
  int *result;      // eax
  int v25;          // edx
  float v26[9];     // [esp+20h] [ebp-48h] BYREF
  float v27[9];     // [esp+44h] [ebp-24h] BYREF

    if (a2 > 0x3FF ||
        (v15 = (signed int)(a3->flags & 0x780) >> 7, v15 <= 0xA) &&
            ((1 << v15) & 0x786) != 0) {
      v21 = (_DWORD *)(80 * a1 + 16767840);
      v21[4] = 0;
      v21[5] = 0;
      v21[6] = 0;
      v20 = a1;
    }
    else {
      CG_GetEntityOrientation(a2, v27, (float(*)[3])v26);
      v16 = *a6 - v27[0];
      v17 = a6[1] - v27[1];
      v18 = a6[2] - v27[2];
      v19 = 20 * a1;
      *(float *)&dword_FFDB70[v19] =
          (float)((float)(v16 * v26[0]) + (float)(v17 * v26[1])) +
          (float)(v18 * v26[2]);
      *(float *)&dword_FFDB74[v19] =
          (float)((float)(v16 * v26[3]) + (float)(v17 * v26[4])) +
          (float)(v18 * v26[5]);
      *(float *)&dword_FFDB78[v19] =
          (float)((float)(v16 * v26[6]) + (float)(v17 * v26[7])) +
          (float)(v18 * v26[8]);
      v20 = a1;
    }
  v22 = 20 * v20;
  *(int32_t *)((char *)&stru_FFDAF4.volumeFalloffCurve + v22 * 4) = a2;
  *(_DWORD *)((char *)&stru_FFDAF4 + v22 * 4 + 68) =
      (signed int)(a3->flags & 0x780) >> 7;
  dword_FFDB40[v22 + 2] = a7;
  dword_FFDB40[v22 + 4] = a8;
  dword_FFDB50[v22 + 1] = a9;
  dword_FFDB40[v22 + 3] = a10;
  dword_FFDB50[v22 + 2] = (int)a3;
  dword_FFDB50[v22 + 3] = (int)a4;
  dword_FFDB50[v22 + 4] = a5;
  *(_DWORD *)((char *)&stru_FFDAF4 + v22 * 4 + 72) = a13;
  *(_DWORD *)((char *)&stru_FFDAF4 + v22 * 4 + 76) = stru_FFDAF4.startDelay;
  dword_FFDB40[v22 + 1] = stru_FFDAF4.fLfePercentage + a11 - a12;
  v23 = byte_FFD802 && byte_FFDAE7[(signed int)(a3->flags & 0x780) >> 7];
  result = dword_FFDB70;
  v25 = 20 * a1;
  LOBYTE(dword_FFDB70[v25 + 3]) = v23;
  BYTE1(dword_FFDB70[v25 + 3]) = a14;
  dword_FFDB70[v25 + 4] = a15;
  return result;
}

void __cdecl SND_GetCurrent3DPosition(int entnum, float const *const offset,
                                      float *const pos_out)
{
  float *result; // eax
  float v4;      // xmm1_4
  float v5;      // xmm1_4
  float v6;      // xmm1_4
  float v7;      // xmm0_4
  float v8[9];   // [esp+10h] [ebp-38h] BYREF
  float v9;      // [esp+34h] [ebp-14h] BYREF
  float v10;     // [esp+38h] [ebp-10h]
  float v11;     // [esp+3Ch] [ebp-Ch]

  result = CG_GetEntityOrientation(a1, &v9, (float(*)[3])v8);
  v4 = *a2;
  v9 = (float)(*a2 * v8[0]) + v9;
  v10 = (float)(v4 * v8[1]) + v10;
  v11 = (float)(v4 * v8[2]) + v11;
  v5 = a2[1];
  v9 = (float)(v5 * v8[3]) + v9;
  v10 = (float)(v5 * v8[4]) + v10;
  v11 = (float)(v5 * v8[5]) + v11;
  v6 = (float)(a2[2] * v8[7]) + v10;
  v7 = (float)(a2[2] * v8[8]) + v11;
  *a3 = (float)(a2[2] * v8[6]) + v9;
  a3[1] = v6;
  a3[2] = v7;
  return result;
}

int __cdecl SND_GetSoundOverlay(enum snd_overlay_type_t type,
                                struct snd_overlay_info_t *const info,
                                int maxcount, int *cpu)
{
  int v4;                    // edi
  snd_overlay_info_t *v6;    // esi
  int v7;                    // ebx
  unsigned int v8;           // ecx
  snd_overlay_info_t *v9;    // ebx
  char *v10;                 // esi
  bool i;                    // al
  int32_t v12;               // eax
  snd_overlay_info_t *v13;   // ebx
  int v14;                   // esi
  int32_t v15;               // eax
  float *v16;                // [esp+1Ch] [ebp-5Ch]
  float *v17;                // [esp+20h] [ebp-58h]
  float v18;                 // [esp+24h] [ebp-54h]
  int v19;                   // [esp+28h] [ebp-50h]
  float v20;                 // [esp+2Ch] [ebp-4Ch]
  int v21;                   // [esp+30h] [ebp-48h]
  float v22;                 // [esp+34h] [ebp-44h]
  float StreamChannelVolume; // [esp+38h] [ebp-40h]
  int v24;                   // [esp+3Ch] [ebp-3Ch]
  float v25;                 // [esp+40h] [ebp-38h]
  char *v26;                 // [esp+44h] [ebp-34h]
  char *v27;                 // [esp+4Ch] [ebp-2Ch]
  float v28[9];              // [esp+54h] [ebp-24h] BYREF

  v4 = a3;
  if (!g_snd[0])
    return 0;
  if (a4)
    *a4 = dword_FFD818;
    switch (a1) {
    case SND_OVERLAY_STREAM:
      if (a3 > dword_FFEBCC)
        v4 = dword_FFEBCC;
        if (v4 > 0) {
          v6 = a2;
          v24 = 0;
          v26 = g_snd;
          v17 = (float *)&unk_FFE570;
            do {
              v7 = v24 + 32;
                if ((unsigned __int8)SND_IsStreamChannelFree(v24 + 32)) {
                  *(_DWORD *)v6->pszSampleName = 0;
                }
                else {
                  *(_DWORD *)v6->pszSampleName =
                      Com_GetSoundFileName(*((const snd_alias_t **)v26 + 854));
                  *(float *)&v6->fPitch =
                      (float)SND_GetStreamChannelPlaybackRate(v7) /
                      (float)*((int *)v26 + 851);
                  v6->fBaseVolume = *((_DWORD *)v26 + 850);
                  StreamChannelVolume = SND_GetStreamChannelVolume(v7);
                  *(float *)&v6->fCurVolume = StreamChannelVolume;
                  if (*(float *)&dword_FFD824 != 0.0)
                    *(float *)&v6->fCurVolume =
                        StreamChannelVolume / *(float *)&dword_FFD824;
                  v8 = (*(_DWORD *)(*((_DWORD *)v26 + 854) + 44) & 0x780) >> 7;
                    if (v8 <= 0xA && ((1 << v8) & 0x786) != 0) {
                      v6->dist = -1;
                    }
                    else {
                      SND_GetCurrent3DPosition(*((_DWORD *)v26 + 845), v17,
                                               v28);
                      v25 =
                          Vec3Distance(v28, (float *)stru_FFDAF4.pszAliasName);
                      v6->dist = (int)v25;
                    }
                }
              ++v24;
              v17 += 20;
              ++v6;
              v26 += 80;
            }
          while (v4 != v24);
        }
      break;
    case SND_OVERLAY_2D:
      if (a3 > dword_FFEBC4)
        v4 = dword_FFEBC4;
        if (v4 > 0) {
          v13 = a2;
          v19 = 0;
          v27 = g_snd;
            do {
              v14 = v19 + 45;
                if (SND_Is2DChannelFree(v19 + 45)) {
                  *(_DWORD *)v13->pszSampleName = 0;
                }
                else {
                  *(_DWORD *)v13->pszSampleName =
                      Com_GetSoundFileName(*((const snd_alias_t **)v27 + 1114));
                  v15 = SND_Get2DChannelPlaybackRate(v14);
                  if (!v15)
                    v15 = *((_DWORD *)v27 + 1111);
                  *(float *)&v13->fPitch =
                      (float)v15 / (float)*((int *)v27 + 1111);
                  v13->fBaseVolume = *((_DWORD *)v27 + 1110);
                  v18 = SND_Get2DChannelVolume(v14);
                  *(float *)&v13->fCurVolume = v18;
                  if (*(float *)&dword_FFD824 != 0.0)
                    *(float *)&v13->fCurVolume = v18 / *(float *)&dword_FFD824;
                  v13->dist = -1;
                }
              ++v19;
              ++v13;
              v27 += 80;
            }
          while (v4 != v19);
        }
      break;
    case SND_OVERLAY_3D:
      if (a3 > dword_FFEBC8)
        v4 = dword_FFEBC8;
        if (v4 > 0) {
          v9 = a2;
          v21 = 0;
          v10 = g_snd;
          v16 = (float *)dword_FFDB70;
            for (i = SND_Is3DChannelFree(0);; i = SND_Is3DChannelFree(v21)) {
                if (i) {
                  *(_DWORD *)v9->pszSampleName = 0;
                }
                else {
                  *(_DWORD *)v9->pszSampleName =
                      Com_GetSoundFileName(*((const snd_alias_t **)v10 + 214));
                  v12 = SND_Get3DChannelPlaybackRate(v21);
                  if (!v12)
                    v12 = *((_DWORD *)v10 + 211);
                  *(float *)&v9->fPitch =
                      (float)v12 / (float)*((int *)v10 + 211);
                  v9->fBaseVolume = *((_DWORD *)v10 + 210);
                  v20 = SND_Get3DChannelVolume(v21);
                  *(float *)&v9->fCurVolume = v20;
                  if (*(float *)&dword_FFD824 != 0.0)
                    *(float *)&v9->fCurVolume = v20 / *(float *)&dword_FFD824;
                  SND_GetCurrent3DPosition(*((_DWORD *)v10 + 205), v16, v28);
                  v22 = Vec3Distance(v28, (float *)stru_FFDAF4.pszAliasName);
                  v9->dist = (int)v22;
                }
              ++v21;
              v16 += 20;
              ++v9;
              v10 += 80;
              if (v4 == v21)
                break;
            }
        }
      break;
    default:
      return 0;
    }
  return v4;
}

int __cdecl SND_PlayLocalSoundAliasByName(char const *aliasname,
                                          enum snd_alias_system_t system)
{
  float *v2; // eax

  if (a1 && (v2 = Com_PickSoundAlias(a1)) != 0)
    return SND_PlaySoundAlias_Internal((snd_alias_t *)v2, (unsigned int)v2,
                                       (float *)stru_FFDAF4.fSlavePercentage, 0,
                                       &stru_FFDAF4, 0, 0, 0, a2);
  else
    return 0;
}

int __cdecl SND_PlayLocalSoundAlias(struct snd_alias_list_t *aliasList,
                                    enum snd_alias_system_t system)
{
  snd_alias_t *v2; // eax

  if (a1 && (v2 = (snd_alias_t *)Com_PickSoundAliasFromList(a1)) != 0)
    return SND_PlaySoundAlias_Internal(v2, (unsigned int)v2,
                                       (float *)stru_FFDAF4.fSlavePercentage, 0,
                                       &stru_FFDAF4, 0, 0, 0, a2);
  else
    return 0;
}

int __cdecl SND_PlaySoundAliasAsMaster(struct snd_alias_t const *pAlias,
                                       int entnum, float const *const org,
                                       int timeshift,
                                       enum snd_alias_system_t system)
{
  if (a1)
    return SND_PlaySoundAlias_Internal(a1, (unsigned int)a1, a2, 0,
                                       (const snd_alias_t *)a3, 0, a4, 1u, a5);
  else
    return 0;
}

int __cdecl SND_PlaySoundAlias(struct snd_alias_t const *pAlias, int entnum,
                               float const *const org, int timeshift,
                               enum snd_alias_system_t system)
{
  if (a1)
    return SND_PlaySoundAlias_Internal(a1, (unsigned int)a1, a2, 0,
                                       (const snd_alias_t *)a3, 0, a4, 0, a5);
  else
    return 0;
}

void *__cdecl DB_LoadSounds(void *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_PlayAmbientAlias(struct snd_alias_t const *pAlias,
                                  int fadetime, enum snd_alias_system_t system)
{
  int result;        // eax
  int v4;            // ebx
  int v5;            // edi
  int *v6;           // edx
  int SoundFileName; // ebx
  int v8;            // ebx
  int v9;            // edi
  float v10;         // xmm1_4
  int v11;           // ecx
  uint32_t flags;    // ebx
  float v13;         // xmm2_4
  float v14;         // [esp+1Ch] [ebp-3Ch]
  float *v15;        // [esp+24h] [ebp-34h]
  int v16;           // [esp+30h] [ebp-28h]
  float v17;         // [esp+34h] [ebp-24h]
  float v18;         // [esp+38h] [ebp-20h]

  result = a2;
    if (g_snd[0] && a1) {
      v4 = dword_FFDA70[0] + 32;
      v15 = (float *)((char *)&unk_FFDA50 + 8 * dword_FFDA70[0]);
      if ((unsigned __int8)SND_IsStreamChannelFree(dword_FFDA70[0] + 32))
        goto LABEL_6;
      v5 = 20 * v4;
      v6 = (int *)dword_FFDB58[20 * v4];
      result = *v6;
      if (*v6 == *(_DWORD *)a1->pszAliasName)
        return result;
      SoundFileName =
          Com_GetSoundFileName((const snd_alias_t *)dword_FFDB58[20 * v4]);
        if (SoundFileName == Com_GetSoundFileName(a1) &&
            (v11 = dword_FFDB58[v5], v16 = *(_DWORD *)(v11 + 44),
             flags = a1->flags, (v16 & 1) == (flags & 1)) &&
            *(float *)(v11 + 28) == *(float *)&a1->fPitchMin &&
            *(float *)(v11 + 32) == *(float *)&a1->fPitchMax &&
            (flags & 0x780) == (v16 & 0x780)) {
          dword_FFDB58[v5] = (int)a1;
          dword_FFDB5C[v5] = (int)a1;
          v17 = *(float *)&a1->fVolMin;
          v18 = *(float *)&a1->fVolMax - v17;
          v14 = randomf();
          v13 = (float)(v14 * v18) + v17;
            if (a2) {
              result = (int)v15;
              v15[3] = (float)(v13 - v15[2]) / (float)a2;
            }
            else {
              result = (int)(v15 + 2);
              v15[3] = 0.0;
            }
          v15[2] = v13;
        }
        else {
        LABEL_6:
          v8 = dword_FFDA70[0];
          v9 = dword_FFDA70[0] + 32;
            if (!(unsigned __int8)SND_IsStreamChannelFree(dword_FFDA70[0] +
                                                          32)) {
                if (a2) {
                  v10 = *(float *)&dword_FFDA58[2 * v8];
                    if (v10 > 0.0) {
                      *((float *)&unk_FFDA50 + 2 * v8 + 3) =
                          (float)-v10 / (float)a2;
                      *((_DWORD *)&unk_FFDA50 + 2 * v8 + 2) = 0;
                    }
                }
                else {
                  SND_StopStreamChannel(v9);
                }
            }
          dword_FFDA70[0] = 3 - dword_FFDA70[0];
          return SND_StartBackground(dword_FFDA70[0], (int)a1, a2, a3);
        }
    }
  return result;
}

void __cdecl SND_PlayMusicAlias(struct snd_alias_t const *pAlias,
                                enum snd_alias_system_t system)
{
    if (g_snd[0] && a1) {
      if ((unsigned __int8)SND_IsStreamChannelFree(32))
        SND_StartBackground(0, (int)a1, 0, a2);
    }
}

int __cdecl SND_PlayBlendedSoundAliases(struct snd_alias_t const *,
                                        struct snd_alias_t const *, float, int,
                                        float const *const, int,
                                        enum snd_alias_system_t)
{
  if (!a1 || !a2)
    return 0;
  SND_ValidateSoundAliasBlend((int)a1, (int)a2, 1);
  return SND_PlaySoundAlias_Internal(a1, (unsigned int)a2, a4, a3,
                                     (const snd_alias_t *)a5, 0, a6, 0, a7);
}

void __cdecl SND_Save(struct MemoryFile *memFile)
{
  UNIMPLEMENTED();
}

void __cdecl SND_Restore(struct MemoryFile *memFile)
{
  int v1;                             // esi
  char *v2;                           // ebx
  int v3;                             // ebx
  char *v4;                           // ecx
  char *v5;                           // edx
  int v6;                             // eax
  int v7;                             // esi
  char *v8;                           // ebx
  int v9;                             // ebx
  char *v10;                          // ecx
  int *v11;                           // edx
  int *v12;                           // eax
  char *CString;                      // ebx
  char *v14;                          // ebx
  unsigned int v15;                   // ebx
  const snd_alias_t *v16;             // esi
  char *v17;                          // ebx
  int v18;                            // ebx
  _DWORD *v19;                        // ecx
  const snd_alias_t *AliasWithOffset; // esi
  char *v21;                          // ebx
  int SoundFileMem;                   // ebx
  int v23;                            // eax
  snd_alias_t *v24;                   // [esp+48h] [ebp-90h]
  snd_alias_t *v25;                   // [esp+4Ch] [ebp-8Ch]
  int v26[2];                         // [esp+50h] [ebp-88h] BYREF
  int v27;                            // [esp+58h] [ebp-80h]
  int v28;                            // [esp+7Ch] [ebp-5Ch]
  int v29;                            // [esp+8Ch] [ebp-4Ch]
  int v30;                            // [esp+90h] [ebp-48h]
  int v31;                            // [esp+94h] [ebp-44h]
  char v32;                           // [esp+99h] [ebp-3Fh]
  snd_save_2D_sample_t v33;           // [esp+A0h] [ebp-38h] BYREF
  int v34;                            // [esp+B8h] [ebp-20h] BYREF
  _WORD __dst[13];                    // [esp+BEh] [ebp-1Ah] BYREF

    if (g_snd[0]) {
      v1 = 1;
      v2 = (char *)&unk_FFD8BC;
        do {
          MemFile_ReadData(a1, 0x88u, v2);
          ++v1;
          v2 += 136;
        }
      while (v1 != 4);
      v3 = 0;
      v4 = g_snd;
      v5 = (char *)&unk_FFD834;
      v6 = dword_FFDA54;
        do {
          if (v4[184])
            v6 = (int)v5;
          dword_FFDA54 = v6;
          ++v3;
          v5 += 136;
          v4 += 136;
        }
      while (v3 != 4);
      v7 = 1;
      v8 = (char *)&unk_FFDA98;
        do {
          MemFile_ReadData(a1, 0x20u, v8);
          ++v7;
          v8 += 32;
        }
      while (v7 != 3);
      v9 = 0;
      v10 = g_snd;
      v11 = dword_FFDA78;
      v12 = (int *)dword_FFDAD8;
        do {
          if (v10[660])
            v12 = v11;
          dword_FFDAD8 = (int)v12;
          ++v9;
          v11 += 8;
          v10 += 32;
        }
      while (v9 != 3);
      SND_SetRoomtype(*v12);
      MemFile_ReadData(a1, 8u, dword_FFDA58);
        while (1) {
          CString = (char *)MemFile_ReadCString(a1);
          if (!*CString)
            break;
          MemFile_ReadData(a1, 2u, __dst);
          AliasWithOffset =
              (const snd_alias_t *)SND_GetAliasWithOffset(CString, __dst[0]);
          if (!AliasWithOffset)
            break;
          v21 = (char *)MemFile_ReadCString(a1);
            if (*v21) {
              MemFile_ReadData(a1, 2u, __dst);
              v24 = (snd_alias_t *)SND_GetAliasWithOffset(v21, __dst[0]);
            }
            else {
              v24 = 0;
            }
          SND_RestoreChanInfo(v26, a1);
          MemFile_ReadData(a1, 0x18u, &v33);
            if ((AliasWithOffset->flags & 0x60) == 0x20 &&
                (v24->flags & 0x60) == 0x20) {
                if (Com_GetSoundFileMem(AliasWithOffset)) {
                  SoundFileMem = Com_GetSoundFileMem(v24);
                    if (SoundFileMem == Com_GetSoundFileMem(AliasWithOffset)) {
                        if ((unsigned __int8)SND_ValidateSoundAliasBlend(
                                (int)AliasWithOffset, (int)v24, 0)) {
                            if (*(_BYTE *)(snd_enable3D + 8)) {
                              SND_StartAlias3DSample(
                                  __SPAIR64__((unsigned int)v24,
                                              (unsigned int)AliasWithOffset),
                                  v28, v26[0], (float *)&v33.pan, v33.volume,
                                  v33.pitch, 0, v33.fraction, v27, v32, &v34,
                                  SASYS_CGAME);
                                if (v34 >= 0) {
                                  v23 = 80 * v34;
                                  *(_DWORD *)(v23 + 16767856) = v29;
                                  *(_DWORD *)(v23 + 16767860) = v30;
                                  *(_DWORD *)(v23 + 16767864) = v31;
                                }
                            }
                        }
                    }
                }
            }
        }
        while (1) {
          v14 = (char *)MemFile_ReadCString(a1);
          if (!*v14)
            break;
          MemFile_ReadData(a1, 2u, __dst);
          v16 = (const snd_alias_t *)SND_GetAliasWithOffset(v14, __dst[0]);
          if (!v16)
            break;
          v17 = (char *)MemFile_ReadCString(a1);
            if (*v17) {
              MemFile_ReadData(a1, 2u, __dst);
              v25 = (snd_alias_t *)SND_GetAliasWithOffset(v17, __dst[0]);
            }
            else {
              v25 = 0;
            }
          SND_RestoreChanInfo(v26, a1);
          MemFile_ReadData(a1, 0x10u, &v33);
            if ((v16->flags & 0x60) == 0x20 && (v25->flags & 0x60) == 0x20) {
                if (Com_GetSoundFileMem(v16)) {
                  v18 = Com_GetSoundFileMem(v25);
                    if (v18 == Com_GetSoundFileMem(v16)) {
                        if ((unsigned __int8)SND_ValidateSoundAliasBlend(
                                (int)v16, (int)v25, 0)) {
                            if (*(_BYTE *)(snd_enable2D + 8)) {
                              SND_StartAlias2DSample(
                                  v16, v25, v28, v26[0], v33.volume, v33.pitch,
                                  0, v33.fraction, v27, v32, &v34, SASYS_CGAME);
                                if (v34 >= 0) {
                                  SND_Set2DChannelFromSaveInfo(v34, &v33);
                                  v19 = (_DWORD *)(80 * v34 + 16767856);
                                  *v19 = v29;
                                  v19[1] = v30;
                                  v19[2] = v31;
                                }
                            }
                        }
                    }
                }
            }
        }
      v15 = -1;
        while (1) {
          SND_RestoreStreamChannel(v15 + 33, a1);
          if (++v15 == 2)
            break;
            while (v15 <= 1) {
              if (++v15 == 2)
                goto LABEL_22;
            }
        }
    LABEL_22:
      while ((unsigned __int8)SND_RestoreStreamChannel(-1, a1) &&
             (unsigned __int8)SND_RestoreStreamChannel(-1, a1))
        ;
    }
}

void __cdecl SND_Shutdown()
{
  Voice_Shutdown();
  if (dword_FFD81C)
    Z_FreeInternal(dword_FFD81C);
    if (g_snd[0]) {
      SND_StopSounds(SND_STOP_ALL);
      Com_UnloadSoundAliases(SASYS_CGAME);
      Com_UnloadSoundAliases(SASYS_UI);
      SND_ShutdownDriver();
      memset(g_snd, 0, 0x13D0u);
      Cmd_RemoveCommand("snd_setEnvironmentEffects");
      Cmd_RemoveCommand("snd_deactivateEnvironmentEffects");
    }
}

void *__cdecl DB_SaveSounds(void *)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_ValidateEnvEffectsPriorityValue(char const *, int *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_Update()
{
  int DriverCPUPercentage;           // edx
  int32_t v1;                        // eax
  int v2;                            // edi
  float v3;                          // xmm0_4
  int v4;                            // ecx
  int v5;                            // edx
  float v6;                          // xmm1_4
  float *v7;                         // eax
  float v8;                          // xmm0_4
  const dvar_s *v9;                  // eax
  __m128 v10;                        // xmm1
  float v11;                         // xmm1_4
  int v12;                           // eax
  float v13;                         // xmm0_4
  float v14;                         // xmm0_4
  int v15;                           // ebx
  char *v16;                         // esi
  int v17;                           // eax
  float v18;                         // xmm0_4
  int v19;                           // xmm1_4
  char i;                            // dl
  __m128 v21;                        // xmm1
  __m128 v22;                        // xmm0
  __m128 v23;                        // xmm1
  __m128 v24;                        // xmm1
  __m128 v25;                        // xmm2
  __m128 v26;                        // xmm0
  int v27;                           // ebx
  float v28;                         // xmm1_4
  float v29;                         // xmm1_4
  int v30;                           // ebx
  int v31;                           // ebx
  int v32;                           // ebx
  char *v33;                         // esi
  int v34;                           // ebx
  int32_t v35;                       // eax
  int v36;                           // ebx
  char *v37;                         // esi
  int v38;                           // ebx
  int32_t StreamChannelPlaybackRate; // eax
  int v40;                           // ebx
  int32_t v41;                       // eax
  float v42;                         // xmm0_4
  float v43;                         // xmm0_4
  unsigned int v44;                  // [esp+1Ch] [ebp-5Ch]
  float v45;                         // [esp+2Ch] [ebp-4Ch]
  float v46;                         // [esp+30h] [ebp-48h]
  float v47;                         // [esp+34h] [ebp-44h]
  float v48;                         // [esp+38h] [ebp-40h]
  float v49;                         // [esp+3Ch] [ebp-3Ch]
  MemoryFile v50;                    // [esp+4Ch] [ebp-2Ch] BYREF

  if (!g_snd[0])
    return;
  DriverCPUPercentage = SND_GetDriverCPUPercentage();
  dword_FFD818 = DriverCPUPercentage;
  if (*(_BYTE *)(com_statmon + 8) && DriverCPUPercentage > 2)
    StatMon_Warning(2u, 3000, "gfx/2d/warning@soundcpu.jpg");
  v1 = Sys_Milliseconds();
  v2 = v1 - stru_FFDAF4.fLfePercentage;
  stru_FFDAF4.fLfePercentage = v1;
  SND_DriverPreUpdate();
    if ((*(_DWORD *)(cl_paused + 8) != 0) != byte_FFD802) {
      if (*(_DWORD *)(cl_paused + 8))
        SND_PauseSounds();
      else
        SND_UnpauseSounds();
    }
  v3 = (float)v2;
  v49 = (float)v2;
  v4 = 0;
  v5 = 0;
    while (1) {
      v7 = (float *)(dword_FFDA54 + v5);
      v8 = (float)(v3 * *(float *)(dword_FFDA54 + v5 + 8)) +
           *(float *)(dword_FFDA54 + v5);
      *v7 = v8;
        if (v7[2] >= 0.0) {
          v6 = v7[1];
          if (v8 <= v6)
            goto LABEL_11;
          goto LABEL_10;
        }
      v6 = v7[1];
      if (v6 <= v8)
        break;
    LABEL_10:
      *v7 = v6;
      v7[2] = 0.0;
    LABEL_11:
      ++v4;
      v5 += 12;
      if (v4 == 11)
        goto LABEL_16;
    LABEL_12:
      v3 = (float)v2;
    }
  ++v4;
  v5 += 12;
  if (v4 != 11)
    goto LABEL_12;
LABEL_16:
    if (*(float *)&dword_FFD830 == 0.0) {
      v9 = snd_volume;
      if (!snd_volume->modified)
        goto LABEL_18;
      goto LABEL_43;
    }
  v18 = (float)(*(float *)&dword_FFD830 * v49) + *(float *)&dword_FFD828;
  *(float *)&dword_FFD828 = v18;
    if (*(float *)&dword_FFD830 < 0.0) {
      v19 = dword_FFD82C;
        if (*(float *)&dword_FFD82C > v18) {
        LABEL_39:
          dword_FFD828 = v19;
          dword_FFD830 = 0;
        }
    }
    else {
      v19 = dword_FFD82C;
      if (v18 > *(float *)&dword_FFD82C)
        goto LABEL_39;
    }
    if (*(float *)&dword_FFD828 == 0.0 && *(float *)&dword_FFD830 == 0.0) {
      SND_StopSounds(SND_STOP_ALL);
      v9 = snd_volume;
    }
    else {
      v9 = snd_volume;
    }
LABEL_43:
  Dvar_ClearModified(v9);
  *(float *)&dword_FFD824 = (float)(*(float *)&dword_FFD828 *
                                    *(float *)&snd_volume->current.integer) *
                            0.75;
LABEL_18:
    if (!byte_FFD802) {
        if (dword_FFD81C) {
          MemFile_InitForReading(&v50, dword_FFD820, dword_FFD81C);
          SND_Restore(&v50);
          Z_FreeInternal(dword_FFD81C);
          dword_FFD81C = 0;
          dword_FFD820 = 0;
        }
      *(float *)&v44 = Com_GetTimescaleForSnd();
      v10 = _mm_cmpgt_ss((__m128)v44, (__m128)0LL);
      LODWORD(v11) =
          _mm_andnot_ps(v10, (__m128)0x3F800000u).u32[0] | v44 & v10.i32[0];
        if (v11 != *(float *)&dword_FFD810) {
          v48 = v11 / *(float *)&dword_FFD810;
          dword_FFD810 = LODWORD(v11);
            if (dword_FFEBC8 > 0) {
              v40 = 0;
                do {
                    if (!SND_Is3DChannelFree(v40)) {
                      v41 = SND_Get3DChannelPlaybackRate(v40);
                      v47 = floorf((float)((float)v41 * v48) + 0.5);
                      SND_Set3DChannelPlaybackRate(v40, (int)v47);
                    }
                  ++v40;
                }
              while (v40 < dword_FFEBC8);
            }
            if (dword_FFEBCC + 32 > 32) {
              v38 = 32;
                do {
                    if (!(unsigned __int8)SND_IsStreamChannelFree(v38)) {
                      StreamChannelPlaybackRate =
                          SND_GetStreamChannelPlaybackRate(v38);
                      v46 = floorf(
                          (float)((float)StreamChannelPlaybackRate * v48) +
                          0.5);
                      SND_SetStreamChannelPlaybackRate(v38, (int)v46);
                    }
                  ++v38;
                }
              while (v38 < dword_FFEBCC + 32);
            }
            if (dword_FFEBC4 + 45 > 45) {
              v34 = 45;
                do {
                    if (!SND_Is2DChannelFree(v34)) {
                      v35 = SND_Get2DChannelPlaybackRate(v34);
                      v45 = floorf((float)((float)v35 * v48) + 0.5);
                      SND_Set2DChannelPlaybackRate(v34, (int)v45);
                    }
                  ++v34;
                }
              while (v34 < dword_FFEBC4 + 45);
            }
        }
      v12 = dword_FFDAD8;
      v13 = *(float *)(dword_FFDAD8 + 12);
        if (v13 == 0.0) {
          v14 = *(float *)(dword_FFDAD8 + 24);
          if (v14 == 0.0)
            goto LABEL_27;
        LABEL_65:
          *(float *)(v12 + 16) = (float)(v14 * v49) + *(float *)(v12 + 16);
            if (*(float *)(dword_FFDAD8 + 24) < 0.0) {
              v43 = *(float *)(dword_FFDAD8 + 20);
                if (v43 >= *(float *)(dword_FFDAD8 + 16)) {
                  *(float *)(dword_FFDAD8 + 16) = v43;
                  *(_DWORD *)(dword_FFDAD8 + 24) = 0;
                  SND_UpdateReverbs();
                  goto LABEL_27;
                }
            }
            else {
              v29 = *(float *)(dword_FFDAD8 + 20);
                if (*(float *)(dword_FFDAD8 + 16) >= v29) {
                  *(float *)(dword_FFDAD8 + 16) = v29;
                  *(_DWORD *)(dword_FFDAD8 + 24) = 0;
                  SND_UpdateReverbs();
                  goto LABEL_27;
                }
            }
        }
        else {
          *(float *)(dword_FFDAD8 + 4) =
              (float)(v13 * v49) + *(float *)(dword_FFDAD8 + 4);
          v12 = dword_FFDAD8;
            if (*(float *)(dword_FFDAD8 + 12) < 0.0) {
              v42 = *(float *)(dword_FFDAD8 + 8);
                if (v42 >= *(float *)(dword_FFDAD8 + 4)) {
                  *(float *)(dword_FFDAD8 + 4) = v42;
                  *(_DWORD *)(dword_FFDAD8 + 12) = 0;
                  v12 = dword_FFDAD8;
                }
            }
            else {
              v28 = *(float *)(dword_FFDAD8 + 8);
                if (*(float *)(dword_FFDAD8 + 4) >= v28) {
                  *(float *)(dword_FFDAD8 + 4) = v28;
                  *(_DWORD *)(dword_FFDAD8 + 12) = 0;
                  v12 = dword_FFDAD8;
                }
            }
          v14 = *(float *)(v12 + 24);
          if (v14 != 0.0)
            goto LABEL_65;
        }
      SND_UpdateReverbs();
    }
LABEL_27:
  v15 = 0;
  v16 = g_snd;
    while (dword_FFEBC8 > v15) {
        if (!SND_Is3DChannelFree(v15) && !*((_DWORD *)v16 + 207) && v16[893]) {
          i = 1;
          goto LABEL_31;
        }
      ++v15;
      v16 += 80;
    }
    if (dword_FFEBCC + 32 > 32) {
      v36 = 32;
      v37 = g_snd;
      if (!(unsigned __int8)SND_IsStreamChannelFree(32))
        goto LABEL_96;
    LABEL_92:
        for (i = 0;; i = 1) {
          ++v36;
          if (i)
            break;
          v37 += 80;
          if (v36 >= dword_FFEBCC + 32)
            goto LABEL_48;
          if ((unsigned __int8)SND_IsStreamChannelFree(v36))
            goto LABEL_92;
        LABEL_96:
          if (*((_DWORD *)v37 + 847) || !v37[3453])
            goto LABEL_92;
        }
    LABEL_31:
      v17 = *(_DWORD *)(snd_slaveFadeTime + 8);
      if (v17)
        goto LABEL_50;
    LABEL_32:
        if (i) {
          dword_FFDA74 = 1065353216;
          if (dword_FFEBC8 <= 0)
            goto LABEL_34;
        }
        else {
          dword_FFDA74 = 0;
          if (dword_FFEBC8 <= 0)
            goto LABEL_34;
        }
      goto LABEL_53;
    }
LABEL_48:
    if (dword_FFEBC4 + 45 > 45) {
      v32 = 45;
      v33 = g_snd;
      if (!SND_Is2DChannelFree(45))
        goto LABEL_84;
    LABEL_80:
        for (i = 0;; i = 1) {
          ++v32;
          if (i)
            break;
          v33 += 80;
          if (v32 >= dword_FFEBC4 + 45)
            goto LABEL_49;
          if (SND_Is2DChannelFree(v32))
            goto LABEL_80;
        LABEL_84:
          if (*((_DWORD *)v33 + 1107) || !v33[4493])
            goto LABEL_80;
        }
      goto LABEL_31;
    }
LABEL_49:
  i = 0;
  v17 = *(_DWORD *)(snd_slaveFadeTime + 8);
  if (!v17)
    goto LABEL_32;
LABEL_50:
    if (i) {
      v21 = (__m128)LODWORD(v49);
      *(float *)&dword_FFDA74 =
          (float)(v49 / (float)v17) + *(float *)&dword_FFDA74;
      v21.f32[0] = *(float *)&dword_FFDA74;
      v22 = v21;
    }
    else {
      v22 = (__m128)(unsigned int)dword_FFDA74;
      v22.f32[0] = *(float *)&dword_FFDA74 - (float)(v49 / (float)v17);
      dword_FFDA74 = v22.i32[0];
    }
  v23 = v22;
  v23.f32[0] = v22.f32[0] - 1.0;
  v24 = _mm_cmpge_ss(v23, (__m128)0LL);
  v24.i32[0] = _mm_andnot_ps(v24, v22).u32[0] | v24.i32[0] & 0x3F800000;
  v25 = 0;
  v25.f32[0] = 0.0 - v22.f32[0];
  v26 = _mm_cmplt_ss(v25, (__m128)0LL);
  dword_FFDA74 =
      _mm_andnot_ps(v26, (__m128)0LL).u32[0] | v24.i32[0] & v26.i32[0];
  if (dword_FFEBC8 <= 0)
    goto LABEL_34;
LABEL_53:
  v27 = 0;
    do {
      if (!SND_Is3DChannelFree(v27))
        SND_Update3DChannel(v27, v2);
      ++v27;
    }
  while (v27 < dword_FFEBC8);
LABEL_34:
    if (dword_FFEBCC + 32 > 32) {
      v31 = 32;
        do {
          if (!(unsigned __int8)SND_IsStreamChannelFree(v31))
            SND_UpdateStreamChannel(v31, v2);
          ++v31;
        }
      while (v31 < dword_FFEBCC + 32);
    }
    if (dword_FFEBC4 + 45 > 45) {
      v30 = 45;
        do {
          if (!SND_Is2DChannelFree(v30))
            SND_Update2DChannel(v30, v2);
          ++v30;
        }
      while (dword_FFEBC4 + 45 > v30);
    }
  SND_DriverPostUpdate();
}

void __cdecl SND_SetEnvironmentEffects(int priority, char const *roomstring,
                                       float drylevel, float wetlevel,
                                       int fademsec)
{
  int result;     // eax
  int *v6;        // esi
  const char *v7; // eax
  char *v8;       // ebx
  _BYTE *v9;      // eax
  _DWORD *v10;    // ebx
  float v11;      // xmm0_4
  int v12;        // ecx
  int v13;        // edx
  int v14;        // [esp+2Ch] [ebp-1Ch]

  result = a5;
    if (g_snd[0]) {
      v6 = &dword_FFDA78[8 * a1];
      *((_BYTE *)v6 + 28) = 1;
      v7 = (const char *)snd_roomStrings[0];
        if (snd_roomStrings[0]) {
          v14 = 0;
          v8 = (char *)snd_roomStrings;
            while (stricmp(a2, v7)) {
              ++v14;
              v7 = (const char *)*((_DWORD *)v8 + 1);
              v8 += 4;
              if (!v7)
                goto LABEL_6;
            }
        }
        else {
        LABEL_6:
          Com_Printf("invalid roomtype string '%s', it must be one of the "
                     "following strings:\n",
                     a2);
          v9 = (_BYTE *)snd_roomStrings[0];
            if (snd_roomStrings[0]) {
              v10 = snd_roomStrings;
                do {
                    while (!*v9) {
                      v9 = (_BYTE *)v10[1];
                      ++v10;
                      if (!v9)
                        goto LABEL_11;
                    }
                  Com_Printf(stru_2182FC.name, v9);
                  v9 = (_BYTE *)v10[1];
                  ++v10;
                }
              while (v9);
            }
        LABEL_11:
          v14 = 0;
        }
      *v6 = v14;
      if (a5 <= 0)
        v11 = 1.0;
      else
        v11 = (float)a5;
      *((float *)v6 + 2) = a3;
      v6[1] = *(_DWORD *)(dword_FFDAD8 + 4);
      *((float *)v6 + 3) = (float)(a3 - *(float *)(dword_FFDAD8 + 4)) / v11;
      *((float *)v6 + 5) = a4;
      v6[4] = *(_DWORD *)(dword_FFDAD8 + 16);
      *((float *)v6 + 6) = (float)(a4 - *(float *)(dword_FFDAD8 + 16)) / v11;
      if (v6 == (int *)dword_FFDAD8)
        return (int)SND_SetRoomtype(v14);
      v12 = a1 + 1;
        if (a1 + 1 > 2) {
        LABEL_21:
          dword_FFDAD8 = (int)&dword_FFDA78[8 * a1];
          return (int)SND_SetRoomtype(v14);
        }
      result = 32 * v12;
        if (!byte_FFDA94[32 * v12]) {
          v13 = 32 * a1 + 16767672;
            while (++v12 != 3) {
              result = *(unsigned __int8 *)(v13 + 28);
              v13 += 32;
              if ((_BYTE)result)
                return result;
            }
          goto LABEL_21;
        }
    }
  return result;
}

void __cdecl SND_DeactivateEnvironmentEffects_f()
{
  const char *v0; // edi
  int v1;         // esi
  const char **i; // ebx
  _DWORD *v3;     // ebx
  const char *v4; // eax
  int v5;         // eax
  int v6;         // edi
  int v7;         // edx
  int v8;         // esi
  char *v9;       // ebx
  int v10;        // edx
  int v11;        // ecx
  char v12;       // al
  int *v13;       // [esp+18h] [ebp-30h]
  float v14;      // [esp+1Ch] [ebp-2Ch]
  _DWORD v15[8];  // [esp+28h] [ebp-20h] BYREF

    if (Cmd_Argc() == 3) {
      v0 = (const char *)Cmd_Argv(1);
      v15[0] = "level";
      v15[1] = "shellshock";
      v1 = 1;
        for (i = (const char **)v15; stricmp(v0, *i); ++i) {
            if (++v1 == 3) {
              Com_Printf("invalid priority string '%s', it must be one of the "
                         "following strings:\n",
                         v0);
              LOWORD(v1) = 0;
              v3 = v15;
                do {
                  Com_Printf(stru_2182FC.name, *v3);
                  ++v1;
                  ++v3;
                }
              while (v1 != 2);
              return;
            }
        }
      v4 = (const char *)Cmd_Argv(2);
      v5 = atoi(v4);
      v6 = v5;
        if (v5 < 0) {
          Com_Printf(
              "invalid 'fademsec' %i, must be greater than or equal to zero\n",
              v5);
        }
        else {
          v7 = 32 * v1;
          v13 = &dword_FFDA78[8 * v1];
          *((_BYTE *)v13 + 28) = 0;
            if (v13 == (int *)dword_FFDAD8) {
              v8 = v1 - 1;
                if (v8 < 0 || byte_FFDA94[32 * v8]) {
                  v10 = v8;
                }
                else {
                  v9 = (char *)&unk_FFDA38 + v7;
                  v10 = v8;
                  v11 = 0;
                    do {
                      --v10;
                      if (v11 == v8)
                        break;
                      v12 = v9[28];
                      ++v11;
                      v9 -= 32;
                    }
                  while (!v12);
                }
              if (v6)
                v14 = (float)v6;
              else
                v14 = 1.0;
              dword_FFDAD8 = 32 * v10 + 16767608;
              SND_SetRoomtype(dword_FFDA78[8 * v10]);
              *(_DWORD *)(dword_FFDAD8 + 4) = v13[1];
              *(float *)(dword_FFDAD8 + 12) =
                  (float)(*(float *)(dword_FFDAD8 + 8) - *((float *)v13 + 1)) /
                  v14;
              *(_DWORD *)(dword_FFDAD8 + 16) = v13[4];
              *(float *)(dword_FFDAD8 + 24) =
                  (float)(*(float *)(dword_FFDAD8 + 20) - *((float *)v13 + 4)) /
                  v14;
            }
        }
    }
    else {
      Com_Printf("USAGE: snd_deactivateEnvironmentEffects <int priority> <int "
                 "fademsec>\n");
    }
}

void __cdecl SND_SetEnvironmentEffects_f()
{
  const char *v0;  // edi
  int v1;          // esi
  const char **i;  // ebx
  _DWORD *v3;      // ebx
  char *v4;        // edi
  const char *v5;  // eax
  int v6;          // esi
  _DWORD *v7;      // ebx
  _BYTE *v8;       // edx
  _DWORD *v9;      // ebx
  const char *v10; // eax
  const char *v11; // eax
  float v12;       // xmm0_4
  const char *v13; // eax
  float v14;       // xmm0_4
  const char *v15; // eax
  int v16;         // eax
  int v17;         // [esp+34h] [ebp-34h]
  float v18;       // [esp+38h] [ebp-30h]
  _DWORD v19[8];   // [esp+48h] [ebp-20h] BYREF

    if (Cmd_Argc() != 6) {
      Com_Printf(
          "USAGE: snd_setEnvironmentEffects <const char *priority> <const "
          "char *roomstring> <float drylevel> <float "
          "wetlevel> <int fademsec>\n");
      return;
    }
  v0 = (const char *)Cmd_Argv(1);
  v19[0] = "level";
  v19[1] = "shellshock";
  v1 = 1;
    for (i = (const char **)v19; stricmp(v0, *i); ++i) {
        if (++v1 == 3) {
          Com_Printf("invalid priority string '%s', it must be one of the "
                     "following strings:\n",
                     v0);
          LOWORD(v1) = 0;
          v3 = v19;
            do {
              Com_Printf(stru_2182FC.name, *v3);
              ++v1;
              ++v3;
            }
          while (v1 != 2);
          return;
        }
    }
  v17 = v1;
  v4 = (char *)Cmd_Argv(2);
  v5 = (const char *)snd_roomStrings[0];
    if (!snd_roomStrings[0]) {
    LABEL_14:
      Com_Printf(
          "invalid roomtype string '%s', it must be one of the following "
          "strings:\n",
          v4);
      v8 = (_BYTE *)snd_roomStrings[0];
        if (!snd_roomStrings[0]) {
          v10 = 0;
        LABEL_21:
          if (stricmp(v4, v10))
            return;
          goto LABEL_22;
        }
      v9 = snd_roomStrings;
        do {
          if (*v8)
            Com_Printf(stru_2182FC.name, v8);
          v8 = (_BYTE *)v9[1];
          ++v9;
        }
      while (v8);
    LABEL_20:
      v10 = (const char *)snd_roomStrings[0];
      goto LABEL_21;
    }
  v6 = 0;
  v7 = snd_roomStrings;
    while (stricmp(v4, v5)) {
      ++v6;
      v5 = (const char *)v7[1];
      ++v7;
      if (!v5)
        goto LABEL_14;
    }
  if (!v6)
    goto LABEL_20;
LABEL_22:
  v11 = (const char *)Cmd_Argv(3);
  v12 = atof(v11);
  v18 = v12;
    if (v12 >= 0.0 && v12 <= 1.0) {
      v13 = (const char *)Cmd_Argv(4);
      v14 = atof(v13);
        if (v14 >= 0.0 && v14 <= 1.0) {
          v15 = (const char *)Cmd_Argv(5);
          v16 = atoi(v15);
          if (v16 < 0)
            Com_Printf("invalid 'fademsec' %i, must be greater than or equal "
                       "to zero\n",
                       v16);
          else
            SND_SetEnvironmentEffects(v17, v4, v18, v14, v16);
        }
        else {
          Com_Printf("invalid 'wetlevel' %g, must be in the range of 0.0-1.0\n",
                     v14);
        }
    }
    else {
      Com_Printf("invalid 'drylevel' %g, must be in the range of 0.0-1.0\n",
                 v12);
    }
}

void __cdecl SND_Init()
{
  UNIMPLEMENTED();
}

struct dvar_s const *const snd_enable3D;
struct dvar_s const *const snd_enable2D;
struct dvar_s const *const snd_khz;
struct dvar_s const *const snd_volume;
int marker_snd;
struct dvar_s const *const snd_errorOnMissing;
struct dvar_s const *const snd_stereo;
struct dvar_s const *const snd_enableReverb;
struct dvar_s const *const snd_bits;
struct dvar_s const *const snd_slaveFadeTime;
struct dvar_s const *const snd_enableStream;
struct snd_local_t g_snd;

void __cdecl SND_UpdateRoomEffects(int)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_IsStreamChannelPlaying(int)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_Is3DChannelPlaying(int)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_Is2DChannelPlaying(int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UpdateVolume(struct snd_volume_info_t *, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_ChoosePitchAndVolume(struct snd_alias_t const *,
                                      struct snd_alias_t const *, float,
                                      float *, float *)
{
  UNIMPLEMENTED();
}

int __cdecl SND_FindFreeStreamChannel(int, int)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_IsChannelReplacable(int, int, int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_CompareReplacableChannels(int, int, int, int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_FindReplacableChannel(int, int, int, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UpdateSlaveLerp(int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_GetSoundOverlay2D(struct snd_overlay_info_t *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UpdateTimeScale(void)
{
  UNIMPLEMENTED();
}

void __cdecl SND_StopBackground(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_PauseSounds(void)
{
  int v0;   // ebx
  char *v1; // esi
  int v2;   // ebx
  char *v3; // esi
  int v4;   // ebx
  char *v5; // esi

    if (g_snd[0] && !byte_FFD802) {
        if (dword_FFEBC4 + 45 > 45) {
          v0 = 45;
          v1 = g_snd;
            do {
              if (!SND_Is2DChannelFree(v0) &&
                  byte_FFDAE7
                      [(*(_DWORD *)(*((_DWORD *)v1 + 1114) + 44) & 0x780) >> 7])
                SND_Pause2DChannel(v0);
              ++v0;
              v1 += 80;
            }
          while (v0 < dword_FFEBC4 + 45);
        }
        if (dword_FFEBC8 > 0) {
          v4 = 0;
          v5 = g_snd;
            do {
              if (!SND_Is3DChannelFree(v4) &&
                  byte_FFDAE7
                      [(*(_DWORD *)(*((_DWORD *)v5 + 214) + 44) & 0x780) >> 7])
                SND_Pause3DChannel(v4);
              ++v4;
              v5 += 80;
            }
          while (dword_FFEBC8 > v4);
        }
        if (dword_FFEBCC + 32 > 32) {
          v2 = 32;
          v3 = g_snd;
            do {
                if (!(unsigned __int8)SND_IsStreamChannelFree(v2)) {
                  if (byte_FFDAE7[(*(_DWORD *)(*((_DWORD *)v3 + 854) + 44) &
                                   0x780) >>
                                  7])
                    SND_PauseStreamChannel(v2);
                }
              ++v2;
              v3 += 80;
            }
          while (v2 < dword_FFEBCC + 32);
        }
      byte_FFD802 = 1;
      dword_FFD814 = stru_FFDAF4.fLfePercentage;
    }
}

bool __cdecl SND_ContinueLoopingSound(struct snd_alias_t const *,
                                      struct snd_alias_t const *, float, int,
                                      float const *const, int *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_StopEntityChannel(int, int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UpdateMasterVolumes(int)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UnpauseSounds(void)
{
  int v0;   // edi
  int v1;   // ebx
  char *v2; // esi
  int v3;   // ebx
  char *v4; // esi
  int v5;   // ebx
  char *v6; // esi

    if (g_snd[0] && byte_FFD802) {
      v0 = stru_FFDAF4.fLfePercentage - dword_FFD814;
        if (dword_FFEBC4 + 45 > 45) {
          v1 = 45;
          v2 = g_snd;
            do {
              if (!SND_Is2DChannelFree(v1) && v2[4492])
                SND_Unpause2DChannel(v1, v0);
              ++v1;
              v2 += 80;
            }
          while (v1 < dword_FFEBC4 + 45);
        }
        if (dword_FFEBC8 > 0) {
          v5 = 0;
          v6 = g_snd;
            do {
              if (!SND_Is3DChannelFree(v5) && v6[892])
                SND_Unpause3DChannel(v5, v0);
              ++v5;
              v6 += 80;
            }
          while (dword_FFEBC8 > v5);
        }
        if (dword_FFEBCC + 32 > 32) {
          v3 = 32;
          v4 = g_snd;
            do {
                if (!(unsigned __int8)SND_IsStreamChannelFree(v3)) {
                  if (v4[3452])
                    SND_UnpauseStreamChannel(v3, v0);
                }
              ++v3;
              v4 += 80;
            }
          while (v3 < dword_FFEBCC + 32);
        }
      byte_FFD802 = 0;
      dword_FFD814 = 0;
    }
}

void __cdecl SND_UpdatePause(void)
{
  UNIMPLEMENTED();
}

int __cdecl SND_GetSoundOverlayStream(struct snd_overlay_info_t *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_GetSoundOverlay3D(struct snd_overlay_info_t *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_StartAliasStream(struct snd_alias_t const *,
                                 struct snd_alias_t const *, float, int,
                                 float const *const, float, float, int, float,
                                 bool, int *, enum snd_alias_system_t)
{
  UNIMPLEMENTED();
}

int __cdecl SND_StartAliasSample(struct snd_alias_t const *,
                                 struct snd_alias_t const *, float, int,
                                 float const *const, float, float, int, bool,
                                 int *, enum snd_alias_system_t)
{
  UNIMPLEMENTED();
}

int __cdecl SND_PlaySoundAlias_Internal(struct snd_alias_t const *,
                                        struct snd_alias_t const *, float, int,
                                        float const *const, int *, int, bool,
                                        enum snd_alias_system_t)
{
  UNIMPLEMENTED();
}

void __cdecl SND_StartBackground(int, struct snd_alias_t const *, int,
                                 enum snd_alias_system_t)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_ValidateSoundAliasBlend(struct snd_alias_t const *,
                                         struct snd_alias_t const *, bool)
{
  UNIMPLEMENTED();
}

struct snd_alias_t *__cdecl SND_RestoreSoundAlias(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SaveSoundAlias(struct snd_alias_t const *, struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SaveChanInfo(struct snd_channel_info_t const *,
                              struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SaveStreamChannel(int, struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_Save2DChannel(int, struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_Save3DChannel(int, struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_RestoreChanInfo(struct snd_channel_info_t *,
                                 struct MemoryFile *)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_RestoreStreamChannel(int, struct MemoryFile *)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_Restore2DChannel(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_Restore3DChannel(struct MemoryFile *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_UpdateAllChannels(int)
{
  UNIMPLEMENTED();
}

int __cdecl SND_RoomtypeFromString(char const *)
{
  UNIMPLEMENTED();
}
