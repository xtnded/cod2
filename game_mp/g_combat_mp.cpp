enum hitLocation_t __cdecl G_GetHitLocationIndexFromString(
    unsigned short sString) {
  int v1;     // eax
  __int16 *i; // edx

  v1 = 0;
  for (i = g_HitLocConstNames; *i != a1; ++i) {
    if (++v1 == 19) {
      LOBYTE(v1) = 0;
      return v1;
    }
  }
  return v1;
}

unsigned short __cdecl G_GetHitLocationString(enum hitLocation_t hitLoc) {
  return (unsigned __int16)g_HitLocConstNames[a1];
}

void __cdecl AddScore(struct gentity_s *, int) { UNIMPLEMENTED(); }

float __cdecl G_GetWeaponHitLocationMultiplier(enum hitLocation_t, int) {
  UNIMPLEMENTED();
}

void __cdecl LookAtKiller(struct gentity_s *, struct gentity_s *,
                          struct gentity_s *) {
  UNIMPLEMENTED();
}

void __cdecl G_ParseHitLocDmgTable() { UNIMPLEMENTED(); }

int __cdecl G_IndexForMeansOfDeath(char const *) {
  int v1;   // esi
  char **i; // ebx

  v1 = 0;
  for (i = (char **)&modNames; I_stricmp(a1, *i); ++i) {
    if (++v1 == 15) {
      Com_Printf("Unknown means of death string '%s'\n", a1);
      LOWORD(v1) = 0;
      return v1;
    }
  }
  return v1;
}

void __cdecl G_DamageClient(struct gentity_s *, struct gentity_s *,
                            struct gentity_s *, float const *const,
                            float const *const, int, int, int,
                            enum hitLocation_t, int) {
  UNIMPLEMENTED();
}

void __cdecl player_die(struct gentity_s *self, struct gentity_s *inflictor,
                        struct gentity_s *attacker, int damage,
                        int meansOfDeath, int iWeapon, float const *const vDir,
                        enum hitLocation_t hitLoc, int psTimeOffset) {
  UNIMPLEMENTED();
}

float __cdecl CanDamage(struct gentity_s *targ, float const *const origin) {
  float v2;     // xmm6_4
  float v3;     // xmm1_4
  float v4;     // xmm2_4
  float v5;     // xmm0_4
  float v6;     // xmm0_4
  int v7;       // edi
  int v8;       // esi
  float *v9;    // ebx
  gentity_s *i; // ecx
  float v12;    // xmm2_4
  float v13;    // xmm1_4
  int v14;      // esi
  float *v15;   // ebx
  float v16;    // [esp+4Ch] [ebp-6Ch] BYREF
  float v17;    // [esp+50h] [ebp-68h]
  float v18;    // [esp+54h] [ebp-64h]
  float v19;    // [esp+58h] [ebp-60h]
  float v20;    // [esp+5Ch] [ebp-5Ch]
  float v21;    // [esp+60h] [ebp-58h]
  float v22;    // [esp+64h] [ebp-54h]
  float v23;    // [esp+68h] [ebp-50h]
  float v24;    // [esp+6Ch] [ebp-4Ch]
  float v25;    // [esp+70h] [ebp-48h]
  float v26;    // [esp+74h] [ebp-44h]
  float v27;    // [esp+78h] [ebp-40h]
  float v28;    // [esp+7Ch] [ebp-3Ch]
  float v29;    // [esp+80h] [ebp-38h]
  float v30;    // [esp+84h] [ebp-34h]
  float v31[2]; // [esp+88h] [ebp-30h] BYREF
  float v32;    // [esp+90h] [ebp-28h]
  float v33;    // [esp+94h] [ebp-24h] BYREF
  float v34;    // [esp+98h] [ebp-20h]
  float v35;    // [esp+9Ch] [ebp-1Ch]

  if (a1->client) {
    G_GetPlayerViewOrigin(a1, v31);
    v2 = (float)(v32 - a1->r.currentOrigin[2]) * 0.5;
    v33 = *a2 - a1->r.currentOrigin[0];
    v34 = a2[1] - a1->r.currentOrigin[1];
    v35 = 0.0;
    Vec3Normalize(&v33);
    v3 = v31[1] + a1->r.currentOrigin[1];
    v4 = v32 + a1->r.currentOrigin[2];
    v16 = (float)(v31[0] + a1->r.currentOrigin[0]) * 0.5;
    v17 = v3 * 0.5;
    v18 = v4 * 0.5;
    v19 = (float)((float)-v34 * 15.0) + v16;
    v20 = (float)(v33 * 15.0) + (float)(v3 * 0.5);
    v5 = (float)(15.0 * v35) + (float)(v4 * 0.5);
    v21 = v2 + v5;
    v22 = v19;
    v23 = v20;
    v24 = v5 - v2;
    v25 = (float)((float)-v34 * -15.0) + v16;
    v26 = (float)(v33 * -15.0) + (float)(v3 * 0.5);
    v6 = (float)(-15.0 * v35) + (float)(v4 * 0.5);
    v27 = v2 + v6;
    v28 = v25;
    v29 = v26;
    v30 = v6 - v2;
    v7 = 0;
    v8 = 0;
    v9 = &v16;
    for (i = a1;; i = a1) {
      v7 -= (G_LocationalTracePassed(a2, v9, i->s.number, (int)&unk_802891) ==
             0) -
            1;
      ++v8;
      v9 += 3;
      if (v8 == 5)
        break;
    }
    if (v7) {
      if (v7 <= 3)
        return (float)((float)v7 / 3.0);
      return 1.0;
    }
    return 0.0;
  }
  v12 = a1->r.absmin[1] + a1->r.absmax[1];
  v13 = a1->r.absmin[2] + a1->r.absmax[2];
  v16 = (float)(a1->r.absmin[0] + a1->r.absmax[0]) * 0.5;
  v17 = v12 * 0.5;
  v18 = v13 * 0.5;
  v21 = v13 * 0.5;
  v19 = v16 + 15.0;
  v20 = (float)(v12 * 0.5) + 15.0;
  v24 = v13 * 0.5;
  v22 = v16 + 15.0;
  v23 = (float)(v12 * 0.5) - 15.0;
  v27 = v13 * 0.5;
  v25 = v16 - 15.0;
  v26 = v20;
  v30 = v13 * 0.5;
  v28 = v16 - 15.0;
  v29 = v23;
  v14 = 0;
  v15 = &v16;
  if (!G_LocationalTracePassed(&v16, a2, a1->s.number, (int)&unk_802891)) {
    while (1) {
      ++v14;
      v15 += 3;
      if (v14 == 5)
        break;
      if (G_LocationalTracePassed(v15, a2, a1->s.number, (int)&unk_802891))
        return 1.0;
    }
    return 0.0;
  }
  return 1.0;
}

void __cdecl G_Damage(struct gentity_s *targ, struct gentity_s *inflictor,
                      struct gentity_s *attacker, float const *const dir,
                      float const *const point, int damage, int dflags, int mod,
                      enum hitLocation_t hitLoc, int timeOffset) {
  _DWORD *client; // eax
  int32_t weapon; // esi
  float v19;      // xmm0_4
  float v20;      // xmm0_4
  uint32_t flags; // edx
  int v22;        // eax
  int32_t health; // edx
  int32_t v24;    // eax
  void(__cdecl * v25)(gentity_s *, gentity_s *, int, float *, unsigned int,
                      float *, hitLocation_t); // eax
  int WeaponDef;                               // eax
  void(__cdecl * v27)(gentity_s *, gentity_s *, gentity_s *, int, unsigned int,
                      int32_t, float *, hitLocation_t, int); // edx
  float v28[9]; // [esp+44h] [ebp-24h] BYREF
  int v29;      // [esp+84h] [ebp+1Ch]

  client = (_DWORD *)a8->client;
  if (client) {
    if (a8->takedamage && !client[2539] && !client[2540] && client[2481] == 2) {
      if (a9) {
        weapon = a9->s.weapon;
      } else if (a10) {
        weapon = a10->s.weapon;
      } else {
        weapon = 0;
      }
      if (weapon) {
        WeaponDef = BG_GetWeaponDef(weapon);
        if (WeaponDef && !*(_DWORD *)(WeaponDef + 120))
          v19 = *(float *)(WeaponDef + 4 * a16 + 1456);
        else
          v19 = *((float *)&g_fHitLocDamageMult + a16);
      } else {
        v19 = *((float *)&g_fHitLocDamageMult + a16);
      }
      v20 = v19 * (float)a13;
      if ((int)v20 > 0)
        Scr_PlayerDamage(a1, v20, a3, a4, a5, a6, a7, a8, a9, a10, (int)v20,
                         a14, a15, weapon, a12, a11, a16, a17);
    }
  } else if (a8->takedamage) {
    if (!a9)
      a9 = &stru_186D620;
    if (!a10)
      a10 = &stru_186D620;
    Vec3NormalizeTo(a11, v28);
    flags = a8->flags;
    if ((flags & 1) == 0) {
      v22 = 1;
      if (a13 > 0)
        v22 = a13;
      v29 = v22;
      if ((flags & 2) != 0) {
        health = a8->health;
        if (health - v22 <= 0)
          v29 = health - 1;
      } else {
        health = a8->health;
      }
      if (*(_BYTE *)(g_debugDamage + 8)) {
        Com_Printf("target:%i health:%i damage:%i\n", a8->s.number, health,
                   v29);
        health = a8->health;
      }
      a8->health = health - v29;
      Scr_AddEntity(a2, a10);
      Scr_AddInt(a2, v29);
      Scr_Notify(a2, a8, word_195B088, 2u);
      v24 = a8->health;
      if (v24 <= 0) {
        if (v24 < -999)
          a8->health = -999;
        Scr_AddEntity(a2, a10);
        Scr_Notify(a2, a8, word_195B08A, 1u);
        v27 = (void(__cdecl *)(
            gentity_s *, gentity_s *, gentity_s *, int, unsigned int, int32_t,
            float *, hitLocation_t,
            int))entityHandlers[10 * (unsigned __int8)a8->handler + 6];
        if (v27)
          v27(a8, a9, a10, v29, a15, a9->s.weapon, v28, a16, a17);
      } else {
        v25 = (void(__cdecl *)(gentity_s *, gentity_s *, int, float *,
                               unsigned int, float *, hitLocation_t))
            entityHandlers[10 * (unsigned __int8)a8->handler + 5];
        if (v25)
          v25(a8, a10, v29, a12, a15, v28, a16);
      }
    }
  }
}

int __cdecl G_RadiusDamage(float const *const origin,
                           struct gentity_s *inflictor,
                           struct gentity_s *attacker, float fInnerDamage,
                           float fOuterDamage, float radius,
                           struct gentity_s *ignore, int mod) {
  UNIMPLEMENTED();
}

unsigned char *bulletPriorityMap;
unsigned char *riflePriorityMap;
char **modNames;
float *g_fHitLocDamageMult;
void __cdecl G_HitLocStrcpy(unsigned char *, char const *) {
  return strcpy(__dst, __src);
}
