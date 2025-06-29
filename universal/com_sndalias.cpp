void __cdecl Com_SetSoundAliasSeed(int) { UNIMPLEMENTED(); }

int __cdecl Com_GetSoundAliasSeed(void) { UNIMPLEMENTED(); }

void *__cdecl Com_GetSoundFileMem(struct snd_alias_t const *) {
  return *(_DWORD *)(*(_DWORD *)a1->soundFile + 4);
}

char const *__cdecl Com_GetSoundFileName(struct snd_alias_t const *pAlias) {
  return **(_DWORD **)a1->soundFile;
}

struct XAUDIOCHANNELMAP *__cdecl Com_GetSpeakerMap(struct SpeakerMap *, int) {
  UNIMPLEMENTED();
}

int __cdecl Com_GetVolumeFalloffCurve(struct SndCurve *, float const (**)[2]) {
  UNIMPLEMENTED();
}

struct snd_alias_t *__cdecl Com_PickSoundAliasFromList(
    struct snd_alias_list_t *aliasList) {
  float v1;         // xmm2_4
  int v2;           // ecx
  int32_t v3;       // edi
  int32_t v4;       // ebx
  int v5;           // esi
  signed int count; // eax
  int v8;           // esi
  int32_t v9;       // ecx
  float v10;        // xmm2_4
  signed int v11;   // ebx
  int32_t head;     // [esp+0h] [ebp-14h]
  int v13;          // [esp+4h] [ebp-10h]

  if (!a1)
    return 0;
  head = a1->head;
  v1 = *(float *)(head + 52);
  v13 = *(_DWORD *)(head + 16);
  v2 = head + 84;
  v3 = head;
  v4 = head;
  v5 = 1;
  count = a1->count;
  if (count != 1) {
    do {
      v4 += 68;
      v1 = v1 + *(float *)(v2 + 36);
      dword_114E4A4 = 214013 * dword_114E4A4 + 2531011;
      if ((float)(*(float *)(v2 + 36) * 32768.0) >
          (float)((float)((dword_114E4A4 >> 16) & 0x7FFF) * v1))
        v3 = v4;
      if (*(_DWORD *)v2 > v13)
        v13 = *(_DWORD *)v2;
      v2 += 68;
      ++v5;
      count = a1->count;
    } while (count != v5);
  }
  if (v5 > 2) {
    v8 = *(_DWORD *)(v3 + 16);
    if (v8 == v13 && count > 0) {
      v9 = head;
      v10 = 0.0;
      v11 = 0;
      do {
        if (v8 != *(_DWORD *)(v9 + 16)) {
          v10 = v10 + *(float *)(v9 + 52);
          dword_114E4A4 = 214013 * dword_114E4A4 + 2531011;
          if ((float)(32768.0 * *(float *)(v9 + 52)) >
              (float)((float)((dword_114E4A4 >> 16) & 0x7FFF) * v10))
            v3 = v9;
        }
        v9 += 68;
        ++v11;
      } while ((signed int)a1->count > v11);
    }
  }
  *(_DWORD *)(v3 + 16) = v13 + 1;
  return v3;
}

float __cdecl Com_GetVolumeFalloffCurveValue(
    struct SndCurve *volumeFalloffCurve, float fraction) {
  GraphGetValueFromFraction(a1->knotCount, (const float(*)[2])a1->knots, a2);
}

int __cdecl SND_GetAliasOffset(struct snd_alias_t const *alias) {
  char *v1;              // edi
  char v2;               // al
  int v3;                // eax
  int v4;                // ebx
  const snd_alias_t *v5; // ecx
  int v6;                // edx
  int result;            // eax
  int v8;                // esi
  int v9;                // ebx

  v1 = *(char **)a1->pszAliasName;
  if (!*(_DWORD *)a1->pszAliasName)
    goto LABEL_7;
  v2 = *v1;
  if (*v1) {
    v8 = *(_DWORD *)a1->pszAliasName;
    v9 = 0;
    do {
      v9 = 31337 * v9 + __tolower(v2);
      v2 = *(_BYTE *)++v8;
    } while (v2);
    v3 = v9 & 0x3FF;
  } else {
    v3 = 0;
  }
  v4 = dword_114E4A8[v3];
  if (v4) {
    while (I_stricmp(v1, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 12);
      if (!v4)
        goto LABEL_7;
    }
  } else {
  LABEL_7:
    v4 = 0;
  }
  v5 = *(const snd_alias_t **)(v4 + 4);
  v6 = *(_DWORD *)(v4 + 8);
  if (v6 > 0 && a1 != v5) {
    result = 0;
    while (1) {
      ++v5;
      if (++result == v6)
        break;
      if (a1 == v5)
        return result;
    }
  }
  return 0;
}

struct snd_alias_list_t *__cdecl Com_FindSoundAlias(char const *name) {
  int v1;   // ebx
  char v3;  // al
  int v4;   // eax
  char *v5; // esi
  int v6;   // ebx

  if (!a1)
    return 0;
  v3 = *a1;
  if (*a1) {
    v5 = a1;
    v6 = 0;
    do {
      v6 = 31337 * v6 + __tolower(v3);
      v3 = *++v5;
    } while (v3);
    v4 = v6 & 0x3FF;
  } else {
    v4 = 0;
  }
  v1 = dword_114E4A8[v4];
  if (!v1)
    return 0;
  while (I_stricmp(a1, *(char **)v1)) {
    v1 = *(_DWORD *)(v1 + 12);
    if (!v1)
      return 0;
  }
  return v1;
}

struct snd_alias_t *__cdecl Com_PickSoundAlias(char const *aliasname) {
  char v1;    // al
  int v2;     // eax
  int v3;     // ebx
  char *v5;   // esi
  int v6;     // ebx
  float v7;   // xmm2_4
  float *v8;  // ecx
  float *v9;  // edi
  int v10;    // esi
  int v11;    // eax
  float *v12; // eax
  float *v13; // edx
  int v14;    // esi
  float v15;  // xmm2_4
  int v16;    // ecx
  float *v17; // edx
  float v18;  // [esp+14h] [ebp-24h]
  float *v19; // [esp+18h] [ebp-20h]
  float *v20; // [esp+1Ch] [ebp-1Ch]

  if (!a1)
    return 0;
  v1 = *a1;
  if (*a1) {
    v5 = a1;
    v6 = 0;
    do {
      v6 = 31337 * v6 + __tolower(v1);
      v1 = *++v5;
    } while (v1);
    v2 = v6 & 0x3FF;
  } else {
    v2 = 0;
  }
  v3 = dword_114E4A8[v2];
  if (!v3)
    return 0;
  while (I_stricmp(a1, *(char **)v3)) {
    v3 = *(_DWORD *)(v3 + 12);
    if (!v3)
      return 0;
  }
  v20 = *(float **)(v3 + 4);
  v7 = v20[13];
  v18 = v20[4];
  v8 = v20 + 21;
  v19 = v20;
  v9 = v20;
  v10 = 1;
  v11 = *(_DWORD *)(v3 + 8);
  if (v11 != 1) {
    do {
      v9 += 17;
      v7 = v7 + v8[9];
      dword_114E4A4 = 214013 * dword_114E4A4 + 2531011;
      v12 = v19;
      if ((float)(32768.0 * v8[9]) >
          (float)((float)((dword_114E4A4 >> 16) & 0x7FFF) * v7))
        v12 = v9;
      v19 = v12;
      if (SLODWORD(v18) < *(_DWORD *)v8)
        v18 = *v8;
      v8 += 17;
      ++v10;
      v11 = *(_DWORD *)(v3 + 8);
    } while (v11 != v10);
  }
  if (v10 <= 2)
    goto LABEL_27;
  v13 = v19;
  v14 = *((_DWORD *)v19 + 4);
  if (v14 == LODWORD(v18)) {
    if (v11 > 0) {
      v15 = 0.0;
      v16 = 0;
      do {
        if (v14 != *((_DWORD *)v20 + 4)) {
          v15 = v15 + v20[13];
          dword_114E4A4 = 214013 * dword_114E4A4 + 2531011;
          v17 = v20;
          if ((float)(32768.0 * v20[13]) <=
              (float)((float)((dword_114E4A4 >> 16) & 0x7FFF) * v15))
            v17 = v19;
          v19 = v17;
        }
        v20 += 17;
        ++v16;
      } while (v16 < *(_DWORD *)(v3 + 8));
    }
  LABEL_27:
    v13 = v19;
  }
  *((_DWORD *)v13 + 4) = LODWORD(v18) + 1;
  return v19;
}

char const *__cdecl Com_SoundAliasString(char const *) { UNIMPLEMENTED(); }

struct snd_alias_t *__cdecl SV_PickSoundAlias(char const *) {
  UNIMPLEMENTED();
}

struct snd_alias_t *__cdecl SND_GetAliasWithOffset(char const *name,
                                                   int offset) {
  char v2;   // al
  int v3;    // eax
  int v4;    // ebx
  int v5;    // esi
  int v6;    // edx
  int v7;    // eax
  int v8;    // ecx
  char *v10; // esi
  int v11;   // ebx

  if (!a1)
    goto LABEL_7;
  v2 = *a1;
  if (*a1) {
    v10 = a1;
    v11 = 0;
    do {
      v11 = 31337 * v11 + __tolower(v2);
      v2 = *++v10;
    } while (v2);
    v3 = v11 & 0x3FF;
  } else {
    v3 = 0;
  }
  v4 = dword_114E4A8[v3];
  if (v4) {
    while (I_stricmp(a1, *(char **)v4)) {
      v4 = *(_DWORD *)(v4 + 12);
      if (!v4)
        goto LABEL_7;
    }
  } else {
  LABEL_7:
    v4 = 0;
  }
  v5 = *(_DWORD *)(v4 + 4);
  v6 = *(_DWORD *)(v4 + 8);
  if (v6 > 0) {
    if (a2) {
      v7 = *(_DWORD *)(v4 + 4);
      v8 = 0;
      while (1) {
        v7 += 68;
        if (++v8 == v6)
          break;
        if (a2 == v8)
          return v7;
      }
    }
    return v5;
  }
  if (v6)
    return v5;
  Com_Error(
      1,
      "SND_GetAliasWithOffset: could not find sound alias '%s' with offset %d",
      (char)a1);
  return 0;
}

struct<unnamed - tag> g_sa;
int marker_com_sndalias;
int __cdecl Com_SoundAliasRand(void) { UNIMPLEMENTED(); }

Com_LoadSoundAliases(char const *loadspec, char const *loadspecCurGame,
                     snd_alias_system_t system) {
  UNIMPLEMENTED();
}

Com_RegisterSoundAliasVolumeFalloffCurve(char const *filename,
                                         char const *sourceFile) {
  UNIMPLEMENTED();
}

Com_GetDefaultSoundAliasVolumeFalloffCurve() { UNIMPLEMENTED(); }

Com_AllocateTempSoundMemory(int size, char const *name) { UNIMPLEMENTED(); }

Com_AllocSoundMemory(int size, char const *name, int type) { UNIMPLEMENTED(); }

Com_UnloadSoundAliasSounds(snd_alias_system_t system) { UNIMPLEMENTED(); }

Com_UnloadSoundAliases(snd_alias_system_t system) { UNIMPLEMENTED(); }

Com_AddAliasList(char const *name, snd_alias_list_t *aliasList) {
  UNIMPLEMENTED();
}

Com_DuplicateSoundAlias(snd_alias_list_t *aliasCopy, char const *name) {
  UNIMPLEMENTED();
}
