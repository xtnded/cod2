int __cdecl G_SpawnString(char const *key, char const *defaultString,
                          char const **out) {
  return G_SpawnStringInternal(&stru_19357C8, __s1, a2, (const char **)a3);
}

struct game_hudelem_s *__cdecl Scr_GetHudElem(unsigned int) {
  UNIMPLEMENTED();
}

struct gentity_s *__cdecl Scr_GetEntity(unsigned int index) {
  int EntityRef; // eax

  EntityRef = Scr_GetEntityRef(a1);
  if (!HIWORD(EntityRef))
    return &g_entities + (unsigned __int16)EntityRef;
  Scr_ParamError(a1, "not an entity");
  return 0;
}

int __cdecl G_SpawnVector(char const *key, char const *defaultString,
                          float *out) {
  int v3;   // esi
  char *v5; // [esp+2Ch] [ebp-Ch] BYREF

  v3 = G_SpawnStringInternal(&stru_19357C8, __s1, a2, (const char **)&v5);
  *a3 = 0.0;
  a3[1] = 0.0;
  a3[2] = 0.0;
  sscanf(v5, "%f %f %f", a3, a3 + 1, a3 + 2);
  return v3;
}

int __cdecl G_SpawnInt(char const *key, char const *defaultString, int *out) {
  int v3;   // ebx
  char *v5; // [esp+1Ch] [ebp-Ch] BYREF

  v3 = G_SpawnStringInternal(&stru_19357C8, __s1, a2, (const char **)&v5);
  *a3 = atoi(v5);
  return v3;
}

int __cdecl G_SpawnFloat(char const *key, char const *defaultString,
                         float *out) {
  int v3;   // ebx
  float v4; // xmm0_4
  char *v6; // [esp+2Ch] [ebp-Ch] BYREF

  v3 = G_SpawnStringInternal(&stru_19357C8, __s1, a2, (const char **)&v6);
  v4 = atof(v6);
  *a3 = v4;
  return v3;
}

void __cdecl Scr_FreeEntityConstStrings(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl G_DuplicateEntityFields(struct gentity_s *dest,
                                     struct gentity_s const *source) {
  UNIMPLEMENTED();
}

void __cdecl GScr_AddFieldsForEntity() {
  const char *v0;  // edx
  int v1;          // esi
  const char **v2; // ebx

  v0 = fields;
  if (fields) {
    v1 = 0;
    v2 = (const char **)&unk_333370;
    do {
      Scr_AddClassField(0, v0, v1 >> 4);
      v0 = *v2;
      v1 += 16;
      v2 += 4;
    } while (v0);
  }
  return GScr_AddFieldsForClient();
}

void __cdecl G_DuplicateScriptFields(struct gentity_s *,
                                     struct gentity_s const *) {
  UNIMPLEMENTED();
}

void __cdecl Scr_SetGenericField(unsigned char *b, enum fieldtype_t type,
                                 int ofs) {
  UNIMPLEMENTED();
}

void __cdecl Scr_FreeHudElem(struct game_hudelem_s *hud) { UNIMPLEMENTED(); }

void __cdecl Scr_FreeEntity(struct gentity_s *ent) { UNIMPLEMENTED(); }

int __cdecl Scr_SetObjectField(unsigned int classnum, int entnum, int offset) {
  UNIMPLEMENTED();
}

void __cdecl GScr_SetDynamicEntityField(struct gentity_s *, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl SP_worldspawn() { UNIMPLEMENTED(); }

void __cdecl Scr_AddHudElem(struct game_hudelem_s *) { UNIMPLEMENTED(); }

void __cdecl Scr_AddEntity(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl Scr_GetGenericField(unsigned char *b, enum fieldtype_t type,
                                 int ofs) {
  UNIMPLEMENTED();
}

void __cdecl Scr_GetEntArray() { UNIMPLEMENTED(); }

void __cdecl Scr_GetEnt() { UNIMPLEMENTED(); }

void __cdecl Scr_GetEntityField(int, int) { UNIMPLEMENTED(); }

void __cdecl Scr_GetObjectField(unsigned int classnum, int entnum, int offset) {
  UNIMPLEMENTED();
}

void __cdecl GScr_AddFieldsForRadiant() {
  return Scr_AddFields("radiant", "txt");
}

int __cdecl G_CallSpawnEntity(struct gentity_s *ent) { UNIMPLEMENTED(); }

void __cdecl G_CallSpawn() { UNIMPLEMENTED(); }

void __cdecl G_SpawnEntitiesFromString() { UNIMPLEMENTED(); }

void __cdecl Scr_Notify(struct gentity_s *ent, unsigned short stringValue,
                        unsigned int paramcount) {
  UNIMPLEMENTED();
}

void __cdecl Scr_AddExecEntThread(struct gentity_s *, int, unsigned int) {
  UNIMPLEMENTED();
}

unsigned short __cdecl Scr_ExecEntThread(struct gentity_s *ent, int handle,
                                         unsigned int paramcount) {
  return (unsigned __int16)Scr_ExecEntThreadNum(a1->s.number, 0, a2, a3);
}

void __cdecl G_LoadStructs() { UNIMPLEMENTED(); }

struct spawn_t *spawns;
void __cdecl Scr_ReadOnlyField(struct gentity_s *, int) {
  return Scr_Error("Tried to set a read only entity field");
}

int __cdecl Scr_SetEntityField(int, int) { UNIMPLEMENTED(); }

unsigned int __cdecl G_SetEntityScriptVariableInternal(char const *,
                                                       char const *) {
  UNIMPLEMENTED();
}

void __cdecl G_SetEntityScriptVariable(char const *, char const *,
                                       struct gentity_s *) {
  UNIMPLEMENTED();
}

struct gitem_s const *__cdecl G_GetItemForClassname(char const *) {
  UNIMPLEMENTED();
}

void __cdecl G_ParseEntityField(char const *, char const *,
                                struct gentity_s *) {
  UNIMPLEMENTED();
}

void __cdecl G_ParseEntityFields(struct gentity_s *) { UNIMPLEMENTED(); }

void __cdecl G_SpawnStruct(void) { UNIMPLEMENTED(); }
