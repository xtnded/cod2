void __cdecl CG_InitLocalEntities() {
  char *v0;   // eax
  int v1;     // ecx
  char *v2;   // edx
  int result; // eax

  memset(cg_localEntities, 0, 0x5E00u);
  *((_DWORD *)cg_activeLocalEntities + 1) = cg_activeLocalEntities;
  *(_DWORD *)cg_activeLocalEntities = cg_activeLocalEntities;
  v0 = (char *)cg_localEntities;
  cg_freeLocalEntities = cg_localEntities;
  v1 = 0;
  while (1) {
    v2 = &v0[v1];
    result = (int)&v0[v1 + 188];
    *((_DWORD *)v2 + 1) = result;
    v1 += 188;
    if (v1 == 23876)
      break;
    v0 = (char *)cg_localEntities;
  }
  return result;
}

void __cdecl CG_LocalEntities_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl CG_FreeLocalEntity(struct localEntity_s *) { UNIMPLEMENTED(); }

void __cdecl CG_AddMovingTracer(struct localEntity_s *) {
  float v1;    // xmm2_4
  float v3;    // [esp+1Ch] [ebp-2Ch] BYREF
  float v4;    // [esp+20h] [ebp-28h]
  float v5;    // [esp+24h] [ebp-24h]
  float v6[3]; // [esp+28h] [ebp-20h] BYREF
  float v7;    // [esp+34h] [ebp-14h] BYREF
  float v8;    // [esp+38h] [ebp-10h]
  float v9;    // [esp+3Ch] [ebp-Ch]

  BG_EvaluateTrajectory(&a1->pos, *(_DWORD *)((char *)&loc_25BB0 + (_DWORD)cg),
                        &v7);
  Vec3NormalizeTo(a1->pos.trDelta, &v3);
  v1 =
      fminf(*(float *)&a1->tracerClipDist -
                (float)((float)((float)((float)(v7 - a1->pos.trBase[0]) * v3) +
                                (float)((float)(v8 - a1->pos.trBase[1]) * v4)) +
                        (float)((float)(v9 - a1->pos.trBase[2]) * v5)),
            *(float *)(cg_tracerLength + 8));
  v6[0] = v7 + (float)(v3 * v1);
  v6[1] = v8 + (float)(v4 * v1);
  v6[2] = v9 + (float)(v1 * v5);
  return CG_DrawTracer(&v7, v6);
}

struct localEntity_s *__cdecl CG_AllocLocalEntity() {
  UNIMPLEMENTED();
}

void __cdecl CG_AddLocalEntities() { UNIMPLEMENTED(); }

struct localEntity_s *cg_localEntities;
struct localEntity_s *cg_activeLocalEntities;
struct localEntity_s **cg_eachClientFreeLocalEntities;
struct localEntity_s *cg_eachClientActiveLocalEntities;
struct localEntity_s *cg_freeLocalEntities;
void __cdecl `dynamic initializer for 'cg_freeLocalEntities''(void)
{
  UNIMPLEMENTED();
}
