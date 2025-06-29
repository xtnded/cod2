void __cdecl Vec3Inverse(float *const) { UNIMPLEMENTED(); }

void __cdecl use_trigger_use(struct gentity_s *ent ent, struct gentity_s *other,
                             struct gentity_s *activator) {
  ;
}

void __cdecl G_TransposeMatrix(float (*const)[3], float (*const)[3]) {
  UNIMPLEMENTED();
}

void __cdecl G_RotatePoint(float *const, float (*const)[3]) { UNIMPLEMENTED(); }

void __cdecl G_CreateRotationMatrix(float const *const, float (*const)[3]) {
  UNIMPLEMENTED();
}

void __cdecl trigger_use_touch(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl trigger_use(struct gentity_s *) { UNIMPLEMENTED(); }

struct gentity_s *__cdecl G_TestEntityPosition(struct gentity_s *,
                                               float *const) {
  UNIMPLEMENTED();
}

int __cdecl G_TryPushingEntity(struct gentity_s *check,
                               struct gentity_s *pusher, float *const move,
                               float *const amove) {
  int v4;               // esi
  float *i;             // eax
  float *v6;            // ecx
  float *v7;            // edx
  float v8;             // xmm5_4
  float v9;             // xmm4_4
  float v10;            // xmm6_4
  uint32_t clipmask;    // eax
  float *maxs;          // esi
  float *mins;          // ebx
  double v14;           // xmm3_8
  float v15;            // xmm6_4
  float v16;            // xmm5_4
  float v17;            // xmm2_4
  float j;              // xmm1_4
  uint32_t v19;         // eax
  float v20;            // ebx
  float v21;            // ecx
  float v22;            // edx
  int32_t v23;          // edx
  float *v24;           // edx
  float v25;            // ebx
  float v26;            // ecx
  float v27;            // edx
  int32_t client;       // edx
  float *v29;           // edx
  float v31;            // xmm0_4
  uint32_t v32;         // eax
  float *currentOrigin; // [esp+50h] [ebp-D8h]
  float v34;            // [esp+5Ch] [ebp-CCh]
  float v35;            // [esp+60h] [ebp-C8h]
  float v36;            // [esp+64h] [ebp-C4h]
  float v37;            // [esp+68h] [ebp-C0h]
  float v38;            // [esp+74h] [ebp-B4h]
  float v39;            // [esp+78h] [ebp-B0h]
  float v40;            // [esp+7Ch] [ebp-ACh]
  float v41[9];         // [esp+8Ch] [ebp-9Ch] BYREF
  trace_t v42;          // [esp+B0h] [ebp-78h] BYREF
  _DWORD v43[3];        // [esp+D4h] [ebp-54h] BYREF
  int v44;              // [esp+E0h] [ebp-48h] BYREF
  int v45;              // [esp+E4h] [ebp-44h]
  float v46;            // [esp+E8h] [ebp-40h]
  char v47[12];         // [esp+ECh] [ebp-3Ch] BYREF
  float v48;            // [esp+F8h] [ebp-30h] BYREF
  float v49;            // [esp+FCh] [ebp-2Ch]
  float v50;            // [esp+100h] [ebp-28h]
  float v51;            // [esp+104h] [ebp-24h] BYREF
  float v52;            // [esp+108h] [ebp-20h]
  float v53;            // [esp+10Ch] [ebp-1Ch]

  currentOrigin = a1->r.currentOrigin;
  v51 = a1->r.currentOrigin[0] + *a3;
  v52 = a1->r.currentOrigin[1] + a3[1];
  v53 = a1->r.currentOrigin[2] + a3[2];
  AngleVectors(a4, v43, &v44, v47);
  v44 ^= 0x80000000;
  v45 ^= 0x80000000;
  v46 = -v46;
  v4 = 0;
  for (i = v41;; i += 3) {
    v6 = (float *)&v43[v4];
    v7 = i;
    do {
      *v7 = *v6;
      v6 += 3;
      ++v7;
    } while (i + 3 != v7);
    if (++v4 == 3)
      break;
  }
  v8 = v51 - a2->r.currentOrigin[0];
  v9 = v52 - a2->r.currentOrigin[1];
  v10 = v53 - a2->r.currentOrigin[2];
  v48 = (float)((float)(v8 * v41[0]) + (float)(v9 * v41[1])) +
        (float)(v10 * v41[2]);
  v49 = (float)((float)(v8 * v41[3]) + (float)(v9 * v41[4])) +
        (float)(v10 * v41[5]);
  v50 = (float)((float)(v8 * v41[6]) + (float)(v9 * v41[7])) +
        (float)(v10 * v41[8]);
  v51 = (float)(v48 - v8) + v51;
  v52 = (float)(v49 - v9) + v52;
  v53 = (float)(v50 - v10) + v53;
  clipmask = a1->clipmask;
  if (clipmask) {
    if ((a1->r.contents & 0x4000000) != 0) {
    LABEL_38:
      if (a1->s.groundEntityNum != a2->s.number)
        a1->s.groundEntityNum = 1023;
      v25 = v51;
      *currentOrigin = v51;
      v26 = v52;
      a1->r.currentOrigin[1] = v52;
      v27 = v53;
      a1->r.currentOrigin[2] = v53;
      a1->s.pos.trBase[0] = v25;
      a1->s.pos.trBase[1] = v26;
      a1->s.pos.trBase[2] = v27;
      client = a1->client;
      if (client) {
        *(_DWORD *)(client + 88) +=
            (unsigned __int16)(int)(float)(182.04445 * a4[1]);
        v29 = (float *)a1->client;
        v29[5] = v51;
        v29[6] = v52;
        v29[7] = v53;
      }
    LABEL_42:
      pushed_p += 32;
      return 1;
    }
  } else {
    LOWORD(clipmask) = 2065;
  }
  maxs = a1->r.maxs;
  mins = a1->r.mins;
  if (a1->s.eType == 4)
    G_TraceCapsule(&v42, &v51, a1->r.mins, a1->r.maxs, &v51, a1->r.ownerNum,
                   clipmask);
  else
    G_TraceCapsule(&v42, &v51, a1->r.mins, a1->r.maxs, &v51, a1->s.number,
                   clipmask);
  if (!*(_WORD *)&v42.allsolid || !(&g_entities + v42.entityNum))
    goto LABEL_38;
  v14 = a1->r.maxs[0];
  if (v14 * 0.5 > 4.0) {
    v40 = v51;
    v39 = v52;
    v38 = v53;
    if (v14 * 0.5 > 0.0) {
      v15 = 0.0;
      while (1) {
        v37 = -v15;
        if (v15 >= (float)-v15)
          break;
      LABEL_49:
        v15 = v15 + 4.0;
        if (v14 * 0.5 <= v15)
          goto LABEL_50;
      }
      v34 = v15 + v15;
      while (v14 * 0.5 <= 4.0) {
      LABEL_47:
        v31 = v37;
        if (v37 != 0.0) {
          v37 = v37 + v34;
          if (v15 >= (float)(v31 + v34))
            continue;
        }
        goto LABEL_49;
      }
      v16 = 4.0;
      while (1) {
        v35 = -v16;
        if (v16 >= (float)-v16)
          break;
      LABEL_46:
        v16 = v16 + 4.0;
        if (v14 * 0.5 <= v16)
          goto LABEL_47;
      }
      while (v14 * 0.5 <= 4.0) {
      LABEL_45:
        v35 = v35 + (float)(v16 + v16);
        if (v16 < v35)
          goto LABEL_46;
      }
      v17 = 4.0;
      while (1) {
        v36 = -v17;
        if (v17 >= (float)-v17)
          break;
      LABEL_44:
        v17 = v17 + 4.0;
        if (v14 * 0.5 <= v17)
          goto LABEL_45;
      }
      for (j = v37 + v38;; j = v37 + v38) {
        v48 = v35 + v40;
        v49 = v36 + v39;
        v50 = j;
        v19 = a1->clipmask;
        if (v19) {
          if ((a1->r.contents & 0x4000000) != 0)
            break;
        } else {
          LOWORD(v19) = 2065;
        }
        if (a1->s.eType == 4)
          G_TraceCapsule(&v42, &v48, mins, maxs, &v48, a1->r.ownerNum, v19);
        else
          G_TraceCapsule(&v42, &v48, mins, maxs, &v48, a1->s.number, v19);
        if (!*(_WORD *)&v42.allsolid || !(&g_entities + v42.entityNum))
          break;
        v36 = v36 + (float)(v17 + v17);
        if (v17 < v36) {
          v14 = a1->r.maxs[0];
          goto LABEL_44;
        }
      }
      if (a1->s.groundEntityNum != a2->s.number)
        a1->s.groundEntityNum = 1023;
      v20 = v48;
      *currentOrigin = v48;
      v21 = v49;
      a1->r.currentOrigin[1] = v49;
      v22 = v50;
      a1->r.currentOrigin[2] = v50;
      a1->s.pos.trBase[0] = v20;
      a1->s.pos.trBase[1] = v21;
      a1->s.pos.trBase[2] = v22;
      v23 = a1->client;
      if (v23) {
        *(_DWORD *)(v23 + 88) +=
            (unsigned __int16)(int)(float)(a4[1] * 182.04445);
        v24 = (float *)a1->client;
        v24[5] = v48;
        v24[6] = v49;
        v24[7] = v50;
      }
      goto LABEL_42;
    }
  }
LABEL_50:
  v32 = a1->clipmask;
  if (v32) {
    if ((a1->r.contents & 0x4000000) != 0)
      goto LABEL_59;
  } else {
    LOWORD(v32) = 2065;
  }
  if (a1->s.eType == 4)
    G_TraceCapsule(&v42, currentOrigin, mins, maxs, currentOrigin,
                   a1->r.ownerNum, v32);
  else
    G_TraceCapsule(&v42, currentOrigin, mins, maxs, currentOrigin, a1->s.number,
                   v32);
  if (*(_WORD *)&v42.allsolid && &g_entities + v42.entityNum)
    return 0;
LABEL_59:
  a1->s.groundEntityNum = 1023;
  return 1;
}

void __cdecl G_MoverTeam(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl G_RunMover(struct gentity_s *ent) { UNIMPLEMENTED(); }

char **hintStrings;
void __cdecl trigger_use_shared(struct gentity_s *) { UNIMPLEMENTED(); }

bool __cdecl G_MoverPush(struct gentity_s *, float *const, float *const,
                         struct gentity_s **) {
  UNIMPLEMENTED();
}
