void __cdecl Vec3Avg(float const *const, float const *const, float *const)
{
  UNIMPLEMENTED();
}

int __cdecl IsItemRegistered(int iItemIndex)
{
  return itemRegistered[a1];
}

void __cdecl ClearRegisteredItems()
{
  UNIMPLEMENTED();
}

void __cdecl DroppedItemClearOwner(struct gentity_s *pSelf)
{
  gentity_s *result; // eax

  result = a1;
  a1->s.clientNum = 1022;
  return result;
}

void __cdecl Fill_Clip(struct playerState_s *, int)
{
  UNIMPLEMENTED();
}

int __cdecl Add_Ammo(struct gentity_s *ent, int weapon, int count, int fillClip)
{
  int v4;                // esi
  int v5;                // edi
  int32_t client;        // eax
  int v7;                // ebx
  int v8;                // ebx
  int v9;                // ebx
  int MaxPickupableAmmo; // ebx
  int32_t v11;           // eax
  int v13;               // ebx
  int32_t v14;           // ebx
  int32_t v15;           // ebx
  int v16;               // ebx
  int v17;               // eax
  int v18;               // edx
  int v19;               // [esp+18h] [ebp-30h]
  int v20;               // [esp+1Ch] [ebp-2Ch]
  int v21;               // [esp+20h] [ebp-28h]
  int32_t v22;           // [esp+24h] [ebp-24h]
  int v23;               // [esp+28h] [ebp-20h]
  int v24;               // [esp+2Ch] [ebp-1Ch]

  v4 = BG_AmmoForWeapon(a2);
  v5 = BG_ClipForWeapon(a2);
  client = a1->client;
  v20 = *(_DWORD *)(client + 4 * v4 + 324);
  v21 = *(_DWORD *)(client + 4 * v5 + 836);
  *(_DWORD *)(client + 4 * v4 + 324) = a3 + v20;
    if (BG_WeaponIsClipOnly(a2)) {
      G_GivePlayerWeapon((playerState_s *)a1->client, a2);
      v19 = 1;
    }
    else {
      v19 = 0;
    }
  if (!a4 && !v19)
    goto LABEL_5;
  v22 = a1->client;
  v23 = BG_AmmoForWeapon(a2);
  v24 = BG_ClipForWeapon(a2);
    if (a2 > 0 && a2 <= BG_GetNumWeapons()) {
      v16 = *(_DWORD *)(v22 + 4 * v24 + 836);
      v17 = BG_GetAmmoClipSize(v24) - v16;
      v18 = *(_DWORD *)(v22 + 4 * v23 + 324);
      if (v17 > v18)
        v17 = *(_DWORD *)(v22 + 4 * v23 + 324);
        if (v17) {
          *(_DWORD *)(v22 + 4 * v23 + 324) = v18 - v17;
          *(_DWORD *)(v22 + 4 * v24 + 836) += v17;
        }
    }
    if (v19) {
      *(_DWORD *)(a1->client + 4 * v4 + 324) = 0;
      v13 = *(_DWORD *)(a1->client + 4 * v5 + 836);
      if (v13 > BG_GetAmmoClipSize(v5))
        goto LABEL_16;
    }
    else {
    LABEL_5:
      v7 = *(_DWORD *)(a1->client + 4 * v4 + 324);
        if (v7 > BG_GetAmmoTypeMax(v4)) {
          v15 = a1->client;
          *(_DWORD *)(v15 + 4 * v4 + 324) = BG_GetAmmoTypeMax(v4);
        }
      v8 = *(_DWORD *)(a1->client + 4 * v5 + 836);
        if (v8 > BG_GetAmmoClipSize(v5)) {
        LABEL_16:
          v14 = a1->client;
          *(_DWORD *)(v14 + 4 * v5 + 836) = BG_GetAmmoClipSize(v5);
          v9 = a2;
          if (*(int *)(BG_GetWeaponDef(a2) + 484) < 0)
            goto LABEL_17;
          goto LABEL_9;
        }
    }
  v9 = a2;
    if (*(int *)(BG_GetWeaponDef(a2) + 484) < 0) {
    LABEL_17:
      v11 = a1->client;
      return *(_DWORD *)(v11 + 4 * v4 + 324) - v20 +
             *(_DWORD *)(v11 + 4 * v5 + 836) - v21;
    }
LABEL_9:
  MaxPickupableAmmo =
      BG_GetMaxPickupableAmmo((const playerState_s *)a1->client, v9);
    if (MaxPickupableAmmo >= 0) {
      v11 = a1->client;
      return *(_DWORD *)(v11 + 4 * v4 + 324) - v20 +
             *(_DWORD *)(v11 + 4 * v5 + 836) - v21;
    }
    if (!BG_WeaponIsClipOnly(a2)) {
      *(_DWORD *)(a1->client + 4 * v4 + 324) += MaxPickupableAmmo;
      v11 = a1->client;
        if (*(int *)(v11 + 4 * v4 + 324) < 0) {
          *(_DWORD *)(v11 + 4 * v4 + 324) = 0;
          v11 = a1->client;
        }
      return *(_DWORD *)(v11 + 4 * v4 + 324) - v20 +
             *(_DWORD *)(v11 + 4 * v5 + 836) - v21;
    }
  *(_DWORD *)(a1->client + 4 * v5 + 836) += MaxPickupableAmmo;
  v11 = a1->client;
  if (*(int *)(v11 + 4 * v5 + 836) > 0)
    return *(_DWORD *)(v11 + 4 * v4 + 324) - v20 +
           *(_DWORD *)(v11 + 4 * v5 + 836) - v21;
  *(_DWORD *)(v11 + 4 * v5 + 836) = 0;
  BG_TakePlayerWeapon((playerState_s *)a1->client, a2);
  return 0;
}

void __cdecl G_GetItemClassname(struct gitem_s const *, unsigned short *)
{
  UNIMPLEMENTED();
}

void __cdecl SaveRegisteredItems()
{
  UNIMPLEMENTED();
}

void __cdecl SaveRegisteredWeapons()
{
  UNIMPLEMENTED();
}

void __cdecl RegisterItem(int iItemIndex, int bUpdateCS)
{
  int *result; // eax
  _BYTE *v3;   // eax
  char *v4;    // eax
  _DWORD *v5;  // ebx
  char *v6;    // eax

  result = (int *)itemRegistered[a1];
    if (!result) {
        if (!dword_193449C) {
          v3 = (_BYTE *)bg_itemlist[11 * a1 + 5];
            if (v3 && *v3) {
              v4 = va(
                  "game tried to register the item '%s' after initialization "
                  "finished\n",
                  (const char *)bg_itemlist[11 * a1 + 5]);
              Scr_Error(v4);
            }
            else {
              v6 = va(
                  "game tried to register the item '%s' after initialization "
                  "finished\n",
                  "<<unknown>>");
              Scr_Error(v6);
            }
        }
      itemRegistered[a1] = 1;
      v5 = &bg_itemlist[11 * a1];
      if (v5[2])
        G_ModelIndex((char *)v5[2]);
      result = (int *)v5[3];
      if (result)
        result = (int *)G_ModelIndex((char *)v5[3]);
        if (a2) {
          result = level;
          dword_1937A80 = 1;
        }
    }
  return result;
}

void __cdecl G_RegisterWeapon(int weapIndex)
{
  UNIMPLEMENTED();
}

void __cdecl G_SpawnItem(struct gentity_s *ent, struct gitem_s const *item)
{
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl Drop_Item(struct gentity_s *ent,
                                    struct gitem_s const *item, float angle,
                                    int novelocity)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunItem(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunCorpseMove(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl FinishSpawningItem(struct gentity_s *ent)
{
  uint32_t clipmask; // ebx
  float v2;          // xmm1_4
  char *v4;          // ebx
  const char *v5;    // eax
  trace_t v6;        // [esp+30h] [ebp-A8h] BYREF
  float v7[3];       // [esp+54h] [ebp-84h] BYREF
  float v8[3];       // [esp+60h] [ebp-78h] BYREF
  float v9[3];       // [esp+6Ch] [ebp-6Ch] BYREF
  float v10[3];      // [esp+78h] [ebp-60h] BYREF
  float v11;         // [esp+84h] [ebp-54h] BYREF
  float v12;         // [esp+88h] [ebp-50h]
  float v13;         // [esp+8Ch] [ebp-4Ch]
  float v14;         // [esp+90h] [ebp-48h] BYREF
  int v15;           // [esp+94h] [ebp-44h]
  int v16;           // [esp+98h] [ebp-40h]
  trace_t v17;       // [esp+9Ch] [ebp-3Ch] BYREF

  __b->handler = 17;
    if ((__b->spawnflags & 1) != 0) {
      G_SetOrigin(__b, __b->r.currentOrigin);
      return SV_LinkEntity(__b);
    }
    if (bg_itemlist[11 * __b->unnamed_field.item.index + 7] == 1) {
      v17.fraction = -1.0;
      v17.normal[0] = -1.0;
      v17.normal[1] = -1.0;
      v14 = 1.0;
      v15 = 1065353216;
      v16 = 1065353216;
    }
    else {
      v17.fraction = -1.0;
      v17.normal[0] = -1.0;
      v17.normal[1] = 0.0;
      v14 = 1.0;
      v15 = 1065353216;
      v16 = 0x40000000;
    }
  clipmask = __b->clipmask;
  if (!clipmask)
    clipmask = 1169;
  v11 = __b->r.currentOrigin[0];
  v12 = __b->r.currentOrigin[1];
  v13 = __b->r.currentOrigin[2];
  v17.normal[2] = v11;
  *(float *)&v17.surfaceFlags = v12;
  *(float *)&v17.contents = v13 - 4096.0;
  G_TraceCapsule(&v6, &v11, &v17, &v14, &v17.normal[2], __b->s.number,
                 (const float *)clipmask);
  if (!v6.startsolid)
    goto LABEL_8;
  v11 = __b->r.currentOrigin[0];
  v12 = __b->r.currentOrigin[1];
  v2 = __b->r.currentOrigin[2];
  v13 = v2 - 15.0;
  v17.normal[2] = v11;
  *(float *)&v17.surfaceFlags = v12;
  *(float *)&v17.contents = v2 - 4096.0;
  G_TraceCapsule(&v6, &v11, &v17, &v14, &v17.normal[2], __b->s.number,
                 (const float *)clipmask);
    if (!v6.startsolid) {
    LABEL_8:
      __b->s.groundEntityNum = v6.entityNum;
      v10[0] = v11 + (float)((float)(v17.normal[2] - v11) * v6.fraction);
      v10[1] = v12 + (float)((float)(*(float *)&v17.surfaceFlags - v12) *
                             v6.fraction);
      v10[2] =
          v13 + (float)(v6.fraction * (float)(*(float *)&v17.contents - v13));
      G_SetOrigin(__b, v10);
        if (v6.fraction < 1.0) {
          v9[0] = v6.normal[0];
          v9[1] = v6.normal[1];
          v9[2] = v6.normal[2];
          AngleVectors(__b->r.currentAngles, v7, 0, 0);
          Vec3Cross(v9, v7, v8);
          Vec3Cross(v8, v9, v7);
          AxisToAngles(v7, (float *)&v17.material);
          if (bg_itemlist[11 * __b->s.index.item + 7] == 1)
            *(float *)&v17.partGroup = *(float *)&v17.partGroup + 90.0;
          G_SetAngle(__b, (const float *)&v17.material);
        }
      return SV_LinkEntity(__b);
    }
  v4 = vtos(__b->r.currentOrigin);
  v5 = (const char *)SL_ConvertToString(*(unsigned __int16 *)__b->classname);
  Com_Printf("FinishSpawningItem: %s startsolid at %s\n", v5, v4);
  return (svEntity_s *)G_FreeEntity(v2 - 15.0, __b);
}

struct gentity_s *__cdecl Drop_Weapon(struct gentity_s *pEnt, int iWeaponIndex,
                                      unsigned int tag)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunCorpse(struct gentity_s *ent)
{
  UNIMPLEMENTED();
}

void __cdecl Touch_Item(struct gentity_s *ent, struct gentity_s *other,
                        int bTouched)
{
  UNIMPLEMENTED();
}

void __cdecl Touch_Item_Auto(struct gentity_s *ent, struct gentity_s *other,
                             int bTouched)
{
  UNIMPLEMENTED();
}

int *itemRegistered;

int __cdecl G_ItemClipMask(struct gentity_s *)
{
  UNIMPLEMENTED();
}

void __cdecl G_OrientItemToGround(struct gentity_s *, struct trace_t *)
{
  UNIMPLEMENTED();
}

void __cdecl G_GetAnimDeltaForCorpse(struct gentity_s *, struct corpseInfo_t *,
                                     float *const)
{
  UNIMPLEMENTED();
}

void __cdecl G_BounceCorpse(struct gentity_s *, struct corpseInfo_t *,
                            struct trace_t *, float *const)
{
  UNIMPLEMENTED();
}

void __cdecl RegisterWeaponRumbles(struct WeaponDef *)
{
  UNIMPLEMENTED();
}

int __cdecl GetFreeCueSpot(void)
{
  UNIMPLEMENTED();
}

void __cdecl G_RunCorpseAnimate(struct gentity_s *)
{
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl LaunchItem(struct gitem_s const *, float *const,
                                     float *const, int)
{
  UNIMPLEMENTED();
}

int __cdecl Pickup_Health(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Pickup_Ammo(struct gentity_s *, struct gentity_s *)
{
  UNIMPLEMENTED();
}

int __cdecl Pickup_Weapon(struct gentity_s *, struct gentity_s *, int *, int)
{
  UNIMPLEMENTED();
}
