void __cdecl G_InitTurrets()
{
  UNIMPLEMENTED();
}

void __cdecl SP_info_notnull(struct gentity_s *)
{
  return G_SetOrigin(a1, a1->r.currentOrigin);
}

void __cdecl turret_use(struct gentity_s *self, struct gentity_s *owner,
                        struct gentity_s *activator)
{
  int v2;           // esi
  int32_t client;   // edi
  int v4;           // eax
  int v5;           // eax
  __m128 v6;        // xmm1
  __m128 v7;        // xmm1
  __m128 v8;        // xmm2
  __m128 v9;        // xmm0
  __m128 v10;       // xmm1
  __m128 v11;       // xmm1
  __m128 v12;       // xmm2
  __m128 v13;       // xmm0
  int v14;          // eax
  int v15;          // eax
  unsigned int v16; // [esp+1Ch] [ebp-2Ch]
  unsigned int v17; // [esp+1Ch] [ebp-2Ch]
  float v18;        // [esp+1Ch] [ebp-2Ch]
  float v19;        // [esp+1Ch] [ebp-2Ch]

  v2 = *(_DWORD *)a1->pTurretInfo;
  client = a2->client;
  a2->active = 1;
  a1->active = 1;
  a1->r.ownerNum = a2->s.number;
  *(_DWORD *)(client + 1424) = 1;
  *(_DWORD *)(client + 1428) = a1->s.number;
  *(_DWORD *)(v2 + 4) |= 0x800u;
  *(float *)(v2 + 44) = a2->r.currentOrigin[0];
  *(float *)(v2 + 48) = a2->r.currentOrigin[1];
  *(float *)(v2 + 52) = a2->r.currentOrigin[2];
  a2->s.otherEntityNum = a1->s.number;
  a1->s.otherEntityNum = a2->s.number;
  v4 = *(_DWORD *)(client + 12);
    if ((v4 & 1) != 0) {
      *(_DWORD *)(v2 + 36) = 2;
      v5 = *(_DWORD *)(v2 + 32);
      if (v5 != 2)
        goto LABEL_3;
    LABEL_7:
      v14 = *(_DWORD *)(client + 160);
      BYTE1(v14) = BYTE1(v14) & 0xFC | 1;
      *(_DWORD *)(client + 160) = v14;
      goto LABEL_5;
    }
  *(_DWORD *)(v2 + 36) = (v4 & 2) != 0;
  v5 = *(_DWORD *)(v2 + 32);
  if (v5 == 2)
    goto LABEL_7;
LABEL_3:
    if (v5 == 1) {
      v15 = *(_DWORD *)(client + 160);
      BYTE1(v15) = BYTE1(v15) & 0xFC | 2;
      *(_DWORD *)(client + 160) = v15;
    }
    else {
      *(_DWORD *)(client + 160) |= 0x300u;
    }
LABEL_5:
  *(float *)&v16 =
      AngleSubtract(*(float *)(client + 232), a1->r.currentAngles[0]);
  a1->s.angles2[0] = *(float *)&v16;
  v6 = (__m128)v16;
  v6.f32[0] = *(float *)&v16 - *(float *)(v2 + 20);
  v7 = _mm_cmpge_ss(v6, (__m128)0LL);
  v8 = (__m128) * (unsigned int *)(v2 + 12);
  v8.f32[0] = v8.f32[0] - *(float *)&v16;
  v9 = _mm_cmpge_ss(v8, (__m128)0LL);
  LODWORD(a1->s.angles2[0]) =
      _mm_andnot_ps(
          v9, _mm_or_ps(_mm_andnot_ps(v7, (__m128)v16),
                        _mm_and_ps((__m128) * (unsigned int *)(v2 + 20), v7)))
          .u32[0] |
      *(_DWORD *)(v2 + 12) & v9.i32[0];
  *(float *)&v17 =
      AngleSubtract(*(float *)(client + 236), a1->r.currentAngles[1]);
  a1->s.angles2[1] = *(float *)&v17;
  v10 = (__m128)v17;
  v10.f32[0] = *(float *)&v17 - *(float *)(v2 + 24);
  v11 = _mm_cmpge_ss(v10, (__m128)0);
  v12 = (__m128) * (unsigned int *)(v2 + 16);
  v12.f32[0] = v12.f32[0] - *(float *)&v17;
  v13 = _mm_cmplt_ss(v12, (__m128)0);
  LODWORD(a1->s.angles2[1]) =
      _mm_andnot_ps(v13, (__m128) * (unsigned int *)(v2 + 16)).u32[0] |
      (_mm_andnot_ps(v11, (__m128)v17).u32[0] |
       *(_DWORD *)(v2 + 24) & v11.i32[0]) &
          v13.i32[0];
  a1->s.angles2[2] = 0.0;
  v18 = AngleSubtract(*(float *)(v2 + 20), *(float *)(v2 + 12));
  *(float *)(client + 276) = v18 * 0.5;
  v13.f32[0] = a1->r.currentAngles[0] + *(float *)(v2 + 20);
  *(_DWORD *)(client + 268) = v13.i32[0];
  *(float *)(client + 268) =
      AngleNormalize360Accurate(v13.f32[0] - *(float *)(client + 276));
  v19 = AngleSubtract(*(float *)(v2 + 24), *(float *)(v2 + 16));
  *(float *)(client + 280) = v19 * 0.5;
  v13.f32[0] = a1->r.currentAngles[1] + *(float *)(v2 + 24);
  *(_DWORD *)(client + 272) = v13.i32[0];
  *(float *)(client + 272) =
      AngleNormalize360Accurate(v13.f32[0] - *(float *)(client + 280));
}

int __cdecl G_IsTurretUsable(struct gentity_s *self, struct gentity_s *owner)
{
  int v2;         // eax
  __m128 v3;      // xmm1
  __m128 v4;      // xmm2
  __m128 v5;      // xmm2
  __m128 v6;      // xmm0
  __m128 v7;      // xmm0
  int32_t client; // eax
  float v10;      // [esp+0h] [ebp-58h]
  float v11;      // [esp+18h] [ebp-40h]
  float v12;      // [esp+1Ch] [ebp-3Ch]
  float v13[3];   // [esp+28h] [ebp-30h] BYREF
  float v14;      // [esp+34h] [ebp-24h] BYREF
  float v15;      // [esp+38h] [ebp-20h]
  float v16;      // [esp+3Ch] [ebp-1Ch]

  if (a1->active)
    return 0;
  v2 = *(_DWORD *)a1->pTurretInfo;
  if (!v2)
    return 0;
  v12 = (float)(fabs(*(float *)(v2 + 24)) + fabs(*(float *)(v2 + 16))) * 0.5;
  v10 = AngleNormalize180(
      (float)(*(float *)(v2 + 16) + a1->r.currentAngles[1]) + v12);
  YawVectors(v10, v13, 0);
  Vec3Normalize(v13);
  v14 = a1->r.currentOrigin[0] - a2->r.currentOrigin[0];
  v15 = a1->r.currentOrigin[1] - a2->r.currentOrigin[1];
  v16 = 0.0;
  Vec3Normalize(&v14);
  v3 = (__m128)LODWORD(v13[0]);
  v3.f32[0] = (float)((float)(v13[0] * v14) + (float)(v13[1] * v15)) +
              (float)(v13[2] * v16);
  v4 = v3;
  v4.f32[0] = v3.f32[0] - 1.0;
  v5 = _mm_cmpge_ss(v4, (__m128)0LL);
  v6 = (__m128)0xBF800000;
  v6.f32[0] = -1.0 - v3.f32[0];
  v7 = _mm_cmplt_ss(v6, (__m128)0LL);
  v11 = Q_acos(COERCE_FLOAT(
      _mm_andnot_ps(v7, (__m128)0xBF800000).u32[0] |
      (_mm_andnot_ps(v5, v3).u32[0] | v5.i32[0] & 0x3F800000) & v7.i32[0]));
  v7.f32[0] = v11 * 57.29577951308232;
  if (v7.f32[0] > v12)
    return 0;
  client = a2->client;
  return !*(_DWORD *)(client + 60) && *(_DWORD *)(client + 96) != 1023;
}

void __cdecl turret_controller(struct gentity_s *self, int *const partBits)
{
  DObj_s *ServerDObj; // edi
  float v4;           // [esp+14h] [ebp-24h] BYREF
  float v5;           // [esp+18h] [ebp-20h]
  int v6;             // [esp+1Ch] [ebp-1Ch]

  v5 = a1->s.angles2[1];
  v4 = a1->s.angles2[0];
  v6 = 0;
  ServerDObj = Com_GetServerDObj(a1->s.number);
  DObjSetControlTagAngles(ServerDObj, a2, (unsigned __int16)word_195B11E, &v4);
  DObjSetControlTagAngles(ServerDObj, a2, (unsigned __int16)word_195B120, &v4);
  v4 = a1->s.angles2[2];
  v5 = 0.0;
  return DObjSetControlTagAngles(ServerDObj, a2, (unsigned __int16)word_195B10C,
                                 &v4);
}

void __cdecl use_corona(struct gentity_s *, struct gentity_s *,
                        struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl TeleportPlayer(struct gentity_s *player, float *const origin,
                            float *const angles)
{
  float *client;      // edx
  int v4;             // edx
  svEntity_s *result; // eax
  int8_t linked;      // [esp+1Fh] [ebp-19h]

  linked = a1->r.linked;
  SV_UnlinkEntity(a1);
  client = (float *)a1->client;
  client[5] = *a2;
  client[6] = a2[1];
  client[7] = a2[2];
  *(float *)(a1->client + 28) = *(float *)(a1->client + 28) + 1.0;
  *(_DWORD *)(a1->client + 160) ^= 2u;
  SetClientViewAngle(a1, a3);
  BG_PlayerStateToEntityState((playerState_s *)a1->client, &a1->s, 1, 1u);
  v4 = a1->client + 20;
  a1->r.currentOrigin[0] = *(float *)v4;
  a1->r.currentOrigin[1] = *(float *)(v4 + 4);
  result = *(svEntity_s **)(v4 + 8);
  LODWORD(a1->r.currentOrigin[2]) = result;
  if (linked)
    return SV_LinkEntity(a1);
  return result;
}

void __cdecl G_ClientStopUsingTurret(struct gentity_s *self)
{
  int v1;         // esi
  gentity_s *v2;  // ebx
  int v3;         // eax
  int32_t result; // eax

  v1 = *(_DWORD *)a1->pTurretInfo;
  v2 = &g_entities + a1->r.ownerNum;
  *(_DWORD *)(v1 + 40) = 0;
  *(_DWORD *)a1->s.loopSound = 0;
  v3 = *(_DWORD *)(v1 + 36);
    if (v3 != -1) {
        if (v3 == 2) {
          G_AddEvent(v2, 142, 0);
        }
        else if (v3 == 1) {
          G_AddEvent(v2, 141, 0);
        }
        else {
          G_AddEvent(v2, 140, 0);
        }
      *(_DWORD *)(v1 + 36) = -1;
    }
  TeleportPlayer(v2, (float *)(v1 + 44), v2->r.currentAngles);
  *(_DWORD *)(v2->client + 160) &= 0xFFFFFCFF;
  *(_DWORD *)(v2->client + 1424) = 0;
  result = v2->client;
  *(_DWORD *)(result + 1428) = 1023;
  v2->active = 0;
  v2->s.otherEntityNum = 0;
  a1->active = 0;
  a1->r.ownerNum = 1023;
  *(_DWORD *)(v1 + 4) &= ~0x800u;
  return result;
}

void __cdecl G_FreeTurret(struct gentity_s *self)
{
  _DWORD *result; // eax

  if (*(&g_entities.client + 140 * a1->r.ownerNum))
    G_ClientStopUsingTurret(a1);
  a1->active = 0;
  result = *(_DWORD **)a1->pTurretInfo;
  *result = 0;
  *(_DWORD *)a1->pTurretInfo = 0;
  return result;
}

void __cdecl SP_corona(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl SP_misc_model(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl SP_light(struct gentity_s *self)
{
  UNIMPLEMENTED();
}

void __cdecl SP_info_null(struct gentity_s *self)
{
  UNIMPLEMENTED();
}

void __cdecl G_SpawnTurret(struct gentity_s *self, char const *weaponinfoname)
{
  UNIMPLEMENTED();
}

void __cdecl SP_turret(struct gentity_s *self)
{
  UNIMPLEMENTED();
}

void __cdecl turret_think(struct gentity_s *self)
{
  int v1;        // edi
  int v2;        // eax
  int v3;        // eax
  gentity_s *v4; // ebx
  float *v5;     // eax
  float v6;      // xmm0_4
  float v7;      // xmm0_4
  int v8;        // eax
  float v9;      // xmm1_4
  float v10;     // xmm0_4
  float v11;     // [esp+1Ch] [ebp-4Ch]
  float v12;     // [esp+34h] [ebp-34h]
  int i;         // [esp+38h] [ebp-30h]
  float v14;     // [esp+3Ch] [ebp-2Ch]
  float v15;     // [esp+40h] [ebp-28h] BYREF
  float v16[9];  // [esp+44h] [ebp-24h]

  a1->nextthink = dword_193466C + 50;
  if (*(_DWORD *)a1->tagInfo)
    G_GeneralLink(a1);
    if (!*(&g_entities.client + 140 * a1->r.ownerNum)) {
      v1 = *(_DWORD *)a1->pTurretInfo;
      *(_DWORD *)a1->s.loopSound = 0;
        if (*(int *)(v1 + 40) > 0) {
          *(_DWORD *)a1->s.loopSound = *(unsigned __int8 *)(v1 + 64);
          v2 = *(_DWORD *)(v1 + 40) - 50;
          *(_DWORD *)(v1 + 40) = v2;
            if (v2 <= 0 && *(_BYTE *)(v1 + 66)) {
              *(_DWORD *)a1->s.loopSound = 0;
              G_PlaySoundAlias(a1, *(_BYTE *)(v1 + 66));
              v1 = *(_DWORD *)a1->pTurretInfo;
            }
            else {
              v1 = *(_DWORD *)a1->pTurretInfo;
            }
        }
      a1->s.eFlags &= ~0x40u;
      v16[1] = *(float *)(v1 + 28);
      v16[2] = 0.0;
      v12 = a1->s.angles2[0];
      a1->s.angles2[0] = v12 + a1->s.angles2[2];
      v15 = 200.0;
      v16[0] = 200.0;
      v3 = *(_DWORD *)(v1 + 4);
      if ((v3 & 0x200) != 0 && (v3 & 0x100) != 0)
        v15 = 360.0;
      v4 = a1;
        for (i = 1; i != 3; ++i) {
          v5 = &v16[i - 1];
          v6 = *(v5 - 1) * 0.050000001;
          *(v5 - 1) = v6;
          v14 = AngleSubtract(v16[i], v4->s.angles2[0]);
          if (v14 <= v6)
            v6 = fmaxf(-v6, v14);
          v4->s.angles2[0] = v6 + v4->s.angles2[0];
          v4 = (gentity_s *)((char *)v4 + 4);
        }
      v7 = a1->s.angles2[0];
      a1->s.angles2[2] = v7;
      v8 = *(_DWORD *)(v1 + 4);
      if ((v8 & 0x200) == 0)
        goto LABEL_16;
        if ((v8 & 0x400) != 0) {
          v9 = *(float *)(v1 + 60);
          if (v9 <= a1->s.angles2[0])
            goto LABEL_15;
        }
        else {
          v9 = *(float *)(v1 + 60);
            if (v7 <= v9) {
            LABEL_15:
              BYTE1(v8) &= ~1u;
              *(_DWORD *)(v1 + 4) = v8;
            LABEL_16:
              v11 = AngleSubtract(v7, v12);
              v10 = v15;
              if (v11 <= v15)
                v10 = fmaxf(-v15, v11);
              a1->s.angles2[0] = v10 + v12;
              a1->s.angles2[2] = a1->s.angles2[2] - (float)(v10 + v12);
              return;
            }
        }
      v7 = v9;
      goto LABEL_16;
    }
}

void __cdecl turret_think_init(struct gentity_s *self)
{
  int LocalTagMatrix; // eax
  float *v2;          // ebx
  float *v3;          // esi
  int v4;             // ebx
  float *v6;          // [esp+2Ch] [ebp-ECh]
  int v7;             // [esp+30h] [ebp-E8h]
  float *v8;          // [esp+34h] [ebp-E4h]
  float *v9;          // [esp+38h] [ebp-E0h]
  float v10[12];      // [esp+4Ch] [ebp-CCh] BYREF
  float v11[9];       // [esp+7Ch] [ebp-9Ch] BYREF
  trace_t v12;        // [esp+A0h] [ebp-78h] BYREF
  float v13;          // [esp+C4h] [ebp-54h] BYREF
  float v14;          // [esp+C8h] [ebp-50h]
  float v15;          // [esp+CCh] [ebp-4Ch]
  float v16[3];       // [esp+D0h] [ebp-48h] BYREF
  float v17[3];       // [esp+DCh] [ebp-3Ch] BYREF
  float v18[3];       // [esp+E8h] [ebp-30h] BYREF
  float v19[9];       // [esp+F4h] [ebp-24h] BYREF

  v7 = *(_DWORD *)a1->pTurretInfo;
  a1->handler = 14;
  a1->nextthink = dword_193466C + 50;
  LocalTagMatrix = G_DObjGetLocalTagMatrix(a1, (unsigned __int16)word_195B11E);
  v2 = (float *)LocalTagMatrix;
    if (LocalTagMatrix) {
      LocalTagMatrix =
          G_DObjGetLocalTagMatrix(a1, (unsigned __int16)word_195B124);
      v3 = (float *)LocalTagMatrix;
        if (LocalTagMatrix) {
          AnglesToAxis(a1->r.currentAngles, v10);
          v10[9] = a1->r.currentOrigin[0];
          v10[10] = a1->r.currentOrigin[1];
          v10[11] = a1->r.currentOrigin[2];
          v6 = v2 + 4;
          v16[0] = v3[4] - v2[4];
          v8 = v2 + 5;
          v16[1] = v3[5] - v2[5];
          v9 = v2 + 6;
          v16[2] = v3[6] - v2[6];
          MatrixTransformVector43(v2 + 4, (const float(*)[3])v10, v19);
          v4 = 0;
            while (1) {
              v17[0] = (float)v4 * -3.0;
              v17[1] = 0.0;
              v17[2] = 0.0;
              AnglesToAxis(v17, v11);
              MatrixTransformVector(v16, v11, &v13);
              v13 = *v6 + v13;
              v14 = *v8 + v14;
              v15 = *v9 + v15;
              MatrixTransformVector43(&v13, (const float(*)[3])v10, v18);
              LOWORD(LocalTagMatrix) =
                  G_LocationalTrace(&v12, v19, v18, a1->s.number,
                                    (const float *)0x811, bulletPriorityMap);
              if (v12.fraction < 1.0)
                break;
              if (++v4 == 31)
                return LocalTagMatrix;
            }
          LOWORD(LocalTagMatrix) = LOWORD(v17[0]);
          *(float *)(v7 + 28) = v17[0];
        }
    }
  return LocalTagMatrix;
}

void __cdecl turret_think_client(struct gentity_s *self)
{
  UNIMPLEMENTED();
}

int __cdecl turret_UpdateTargetAngles(struct gentity_s *, float *const, int)
{
  UNIMPLEMENTED();
}

void __cdecl turret_UpdateSound(struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl turret_ReturnToDefaultPos(struct gentity_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl turret_clientaim(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl turret_behind(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Turret_FillWeaponParms(struct gentity_s *, struct gentity_s *,
                                    struct weaponParms *)
{
  UNIMPLEMENTED();
}

void __cdecl G_PlayerTurretPositionAndBlend(struct gentity_s *,
                                            struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl Fire_Lead(struct gentity_s *, struct gentity_s *, int)
{
  UNIMPLEMENTED();
}

void __cdecl turret_shoot_internal(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl turret_track(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}
