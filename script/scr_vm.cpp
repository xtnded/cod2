char const *__cdecl Scr_Allign2(char const *) { UNIMPLEMENTED(); }

char const *__cdecl Scr_Allign4(char const *) { UNIMPLEMENTED(); }

char const *__cdecl Scr_Allign4Strict(char const *) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetLocalVarAtIndex(int) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetLocalVar(char const *) { UNIMPLEMENTED(); }

short __cdecl Scr_ReadShort(char const **) { UNIMPLEMENTED(); }

int __cdecl Scr_ReadInt(char const **) { UNIMPLEMENTED(); }

float const *__cdecl Scr_ReadVector(char const **) { UNIMPLEMENTED(); }

int const *__cdecl Scr_ReadIntArray(char const **, int) { UNIMPLEMENTED(); }

unsigned short __cdecl Scr_ReadUnsignedShort(char const **) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_ReadUnsigned(char const **) { UNIMPLEMENTED(); }

float __cdecl Scr_ReadFloat(char const **) { UNIMPLEMENTED(); }

char const *__cdecl Scr_ReadCodePos(char const **) { UNIMPLEMENTED(); }

void __cdecl Scr_StackClear(void) { UNIMPLEMENTED(); }

void __cdecl Scr_DecTime(void) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetNumParam() { return dword_100821C; }

int __cdecl Scr_IsSystemActive(unsigned char sys) {
  return *(_DWORD *)&algn_100CEB8[4] != 0;
}

char const *__cdecl Scr_GetReturnPos(unsigned int *) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetNumScriptThreads() { return 0; }

void __cdecl Scr_SetLoading(int bLoading) {
  int result; // eax

  result = a1;
  dword_4EAD94 = a1;
  return result;
}

void __cdecl Scr_Abort() { UNIMPLEMENTED(); }

void __cdecl Scr_Settings(int developer, int developer_script,
                          int abort_on_error) {
  int result; // eax

  unk_100CEAA = a1 != 0;
  unk_100CEAB = a2 != 0;
  result = a3;
  byte_1008215 = a3 != 0;
  return result;
}

void __cdecl Scr_ClearErrorMessage() { UNIMPLEMENTED(); }

void __cdecl Scr_ResetTimeout() {
  unsigned __int64 v0; // rax
  __int64 result;      // rax

  v0 = __rdtsc();
  result = (unsigned int)v0 >> 2;
  dword_4EAD98 = result;
  return result;
}

void __cdecl Scr_ErrorWithDialogMessage(char const *, char const *) {
  UNIMPLEMENTED();
}

void __cdecl Scr_Error(char const *error) {
  int *result; // eax
  char v2;     // al

  result = (int *)dword_100CEB0;
  if (!dword_100CEB0) {
    result = (int *)a1;
    dword_100CEB0 = (int)a1;
  }
  if (byte_100CEAC || (result = scrCompilePub, byte_114CF44)) {
    if (!byte_1008216)
      return result;
  } else {
    if (unk_100CEAA) {
      v2 = 1;
      if (!dword_4EAD94)
        v2 = byte_1008216;
      byte_1008216 = v2;
    }
    if (dword_1008208 || byte_1008214)
      longjmp(&g_script_error[18 * g_script_error_level], -1);
  }
  return (int *)Com_Error(1, "\x15%s", dword_100CEB0);
}

int __cdecl Scr_GetPointerType(unsigned int index) { UNIMPLEMENTED(); }

char const *__cdecl Scr_GetTypeName(unsigned int index) { UNIMPLEMENTED(); }

int __cdecl Scr_GetType(unsigned int index) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetObject(unsigned int index) { UNIMPLEMENTED(); }

struct scr_entref_t __cdecl Scr_GetEntityRef(unsigned int index) {
  char **v1;                // ebx
  VariableValue_s *v2;      // esi
  int v3;                   // eax
  char *v4;                 // eax
  char v5;                  // al
  unsigned int intValue;    // edi
  int VarType;              // eax
  char *v8;                 // eax
  char v9;                  // al
  char *v10;                // eax
  __int16 v11;              // cx
  unsigned int v12;         // edx
  int v13;                  // ebx
  char v15;                 // al
  unsigned int EntityIdRef; // eax
  char v17[4];              // [esp+1Ch] [ebp-1Ch]

  LOWORD(v1) = a1;
  if (dword_100821C <= a1) {
    LOWORD(v1) = a1 + 1;
    v10 = va("parameter %d does not exist", a1 + 1);
    if (dword_100CEB0)
      goto LABEL_30;
  LABEL_37:
    dword_100CEB0 = (int)v10;
    goto LABEL_30;
  }
  v2 = &dword_1008210[-a1];
  if (v2->type != 1) {
    *(_DWORD *)v17 = a1 + 1;
    v3 = a1 + 1;
    goto LABEL_4;
  }
  intValue = v2->u.intValue;
  if (GetVarType(v2->u.intValue) == 21) {
    EntityIdRef = Scr_GetEntityIdRef(intValue);
    v12 = HIWORD(EntityIdRef);
    v11 = EntityIdRef;
    goto LABEL_35;
  }
  *(_DWORD *)v17 = a1 + 1;
  dword_100CEB4 = a1 + 1;
  VarType = GetVarType(intValue);
  v8 = va("type %s is not an entity",
          *(const char **)&var_typename[4 * VarType]);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v8;
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v9 = 1;
      if (!dword_4EAD94)
        v9 = byte_1008216;
      byte_1008216 = v9;
    }
    if (dword_1008208 || byte_1008214)
    LABEL_14:
      longjmp(&g_script_error[18 * g_script_error_level], -1);
    goto LABEL_47;
  }
  if (byte_1008216)
  LABEL_47:
    Com_Error(1, "\x15%s", dword_100CEB0);
  v3 = a1 + 1;
LABEL_4:
  v1 = &scrVarPub;
  dword_100CEB4 = v3;
  v4 = va("type %s is not an entity",
          *(const char **)&var_typename[4 * v2->type]);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v4;
  if (byte_100CEAC || byte_114CF44) {
    if (!byte_1008216)
      goto LABEL_29;
  } else {
    if (unk_100CEAA) {
      v5 = 1;
      if (!dword_4EAD94)
        v5 = byte_1008216;
      byte_1008216 = v5;
    }
    if (dword_1008208 || byte_1008214)
      goto LABEL_14;
  }
  Com_Error(1, "\x15%s", dword_100CEB0);
LABEL_29:
  v10 = va("parameter %d does not exist", *(_DWORD *)v17);
  if (!dword_100CEB0)
    goto LABEL_37;
LABEL_30:
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v15 = 1;
      if (!dword_4EAD94)
        v15 = byte_1008216;
      byte_1008216 = v15;
    }
    if (dword_1008208)
      goto LABEL_14;
    if (byte_1008214)
      longjmp(&g_script_error[18 * g_script_error_level], -1);
    goto LABEL_33;
  }
  if (byte_1008216)
  LABEL_33:
    Com_Error(1, "\x15%s", dword_100CEB0);
  v11 = 0;
  v12 = 0;
LABEL_35:
  v13 = (v12 << 16) | (unsigned __int16)v1;
  LOWORD(v13) = v11;
  return v13;
}

int __cdecl Scr_GetFunc(unsigned int) { UNIMPLEMENTED(); }

void __cdecl Scr_GetVector(unsigned int index, float *const vectorValue) {
  VariableValue_s *v2; // edx
  char *v3;            // eax
  char *result;        // eax
  char v5;             // al
  VariableUnion v6;    // edx
  char v7;             // al

  if (dword_100821C <= a1) {
    result = va("parameter %d does not exist", a1 + 1);
    if (dword_100CEB0)
      goto LABEL_12;
    goto LABEL_28;
  }
  v2 = &dword_1008210[-a1];
  if (v2->type == 4) {
    v6.intValue = (int32_t)v2->u;
    *a2 = *(float *)v6.intValue;
    a2[1] = *(float *)(v6.intValue + 4);
    result = *(char **)(v6.intValue + 8);
    *((_DWORD *)a2 + 2) = result;
    return result;
  }
  dword_100CEB4 = a1 + 1;
  v3 = va("type %s is not a vector",
          *(const char **)&var_typename[4 * v2->type]);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v3;
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v7 = 1;
      if (!dword_4EAD94)
        v7 = byte_1008216;
      byte_1008216 = v7;
    }
    if (dword_1008208 || byte_1008214)
    LABEL_20:
      longjmp(&g_script_error[18 * g_script_error_level], -1);
    goto LABEL_10;
  }
  if (byte_1008216)
  LABEL_10:
    Com_Error(1, "\x15%s", dword_100CEB0);
  result = va("parameter %d does not exist", a1 + 1);
  if (dword_100CEB0)
    goto LABEL_12;
LABEL_28:
  dword_100CEB0 = (int)result;
LABEL_12:
  if (!byte_100CEAC) {
    result = (char *)scrCompilePub;
    if (!byte_114CF44) {
      if (unk_100CEAA) {
        v5 = 1;
        if (!dword_4EAD94)
          v5 = byte_1008216;
        byte_1008216 = v5;
      }
      if (dword_1008208 || byte_1008214)
        goto LABEL_20;
      return (char *)Com_Error(1, "\x15%s", dword_100CEB0);
    }
  }
  if (byte_1008216)
    return (char *)Com_Error(1, "\x15%s", dword_100CEB0);
  return result;
}

unsigned int __cdecl Scr_GetConstIString(unsigned int) { UNIMPLEMENTED(); }

float __cdecl Scr_GetFloat(unsigned int index) {
  VariableValue_s *v1; // edx
  int32_t type;        // eax
  int v4;              // ebx
  char *v5;            // eax
  char v6;             // al
  char *v7;            // eax
  char v8;             // al

  if (dword_100821C <= a1) {
    v4 = a1 + 1;
    goto LABEL_7;
  }
  v1 = &dword_1008210[-a1];
  type = v1->type;
  if (type == 5)
    return v1->u.floatValue;
  if (type == 6)
    return (float)v1->u.intValue;
  v4 = a1 + 1;
  dword_100CEB4 = a1 + 1;
  v7 =
      va("type %s is not a float", *(const char **)&var_typename[4 * v1->type]);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v7;
  if (byte_100CEAC || byte_114CF44) {
    if (!byte_1008216)
      goto LABEL_7;
  } else {
    if (unk_100CEAA) {
      v8 = 1;
      if (!dword_4EAD94)
        v8 = byte_1008216;
      byte_1008216 = v8;
    }
    if (dword_1008208 || byte_1008214)
    LABEL_17:
      longjmp(&g_script_error[18 * g_script_error_level], -1);
  }
  Com_Error(1, "\x15%s", dword_100CEB0);
LABEL_7:
  v5 = va("parameter %d does not exist", v4);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v5;
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v6 = 1;
      if (!dword_4EAD94)
        v6 = byte_1008216;
      byte_1008216 = v6;
    }
    if (dword_1008208 || byte_1008214)
      goto LABEL_17;
    goto LABEL_19;
  }
  if (byte_1008216)
  LABEL_19:
    Com_Error(1, "\x15%s", dword_100CEB0);
  return 0.0;
}

int __cdecl Scr_GetInt(unsigned int index) {
  VariableValue_s *v1; // edx
  char *v2;            // eax
  char *v3;            // eax
  char v4;             // al
  char v6;             // al

  if (dword_100821C <= a1) {
    v3 = va("parameter %d does not exist", a1 + 1);
    if (dword_100CEB0)
      goto LABEL_12;
  LABEL_28:
    dword_100CEB0 = (int)v3;
    goto LABEL_12;
  }
  v1 = &dword_1008210[-a1];
  if (v1->type == 6)
    return v1->u;
  dword_100CEB4 = a1 + 1;
  v2 = va("type %s is not an int", *(const char **)&var_typename[4 * v1->type]);
  if (!dword_100CEB0)
    dword_100CEB0 = (int)v2;
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v6 = 1;
      if (!dword_4EAD94)
        v6 = byte_1008216;
      byte_1008216 = v6;
    }
    if (dword_1008208 || byte_1008214)
    LABEL_20:
      longjmp(&g_script_error[18 * g_script_error_level], -1);
    goto LABEL_10;
  }
  if (byte_1008216)
  LABEL_10:
    Com_Error(1, "\x15%s", dword_100CEB0);
  v3 = va("parameter %d does not exist", a1 + 1);
  if (!dword_100CEB0)
    goto LABEL_28;
LABEL_12:
  if (!byte_100CEAC && !byte_114CF44) {
    if (unk_100CEAA) {
      v4 = 1;
      if (!dword_4EAD94)
        v4 = byte_1008216;
      byte_1008216 = v4;
    }
    if (dword_1008208 || byte_1008214)
      goto LABEL_20;
    goto LABEL_25;
  }
  if (byte_1008216)
  LABEL_25:
    Com_Error(1, "\x15%s", dword_100CEB0);
  return 0;
}

void __cdecl Scr_ObjectError(char const *error) { UNIMPLEMENTED(); }

void __cdecl Scr_ParamError(unsigned int index, char const *error) {
  int *result; // eax
  char v3;     // al

  dword_100CEB4 = a1 + 1;
  result = (int *)dword_100CEB0;
  if (!dword_100CEB0) {
    result = (int *)a2;
    dword_100CEB0 = (int)a2;
  }
  if (byte_100CEAC || (result = scrCompilePub, byte_114CF44)) {
    if (!byte_1008216)
      return result;
  } else {
    if (unk_100CEAA) {
      v3 = 1;
      if (!dword_4EAD94)
        v3 = byte_1008216;
      byte_1008216 = v3;
    }
    if (dword_1008208 || byte_1008214)
      longjmp(&g_script_error[18 * g_script_error_level], -1);
  }
  return (int *)Com_Error(1, "\x15%s", dword_100CEB0);
}

char const *__cdecl Scr_GetIString(unsigned int index) { UNIMPLEMENTED(); }

int __cdecl Scr_FindAllThreads(unsigned int, unsigned int *, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_TraverseScript(char const *pos) {
  int result; // eax

  while (1) {
    result = *(unsigned __int8 *)a1;
    switch (*a1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x18:
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
    case 0x20:
    case 0x21:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x31:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x39:
    case 0x3C:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x51:
    case 0x53:
    case 0x58:
    case 0x59:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x64:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x6F:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7A:
    case 0x7B:
    case 0x7E:
      ++a1;
      break;
    case 4:
    case 5:
    case 0x17:
    case 0x1E:
    case 0x1F:
    case 0x22:
    case 0x32:
    case 0x33:
    case 0x37:
    case 0x3D:
    case 0x5A:
    case 0x85:
    case 0x86:
      a1 += 2;
      break;
    case 6:
    case 7:
    case 0xA:
    case 0xB:
    case 0x16:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x2C:
    case 0x2D:
    case 0x2E:
    case 0x2F:
    case 0x30:
    case 0x38:
    case 0x3A:
    case 0x3B:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x63:
      a1 += 3;
      break;
    case 8:
    case 9:
    case 0x13:
    case 0x15:
    case 0x4F:
    case 0x50:
    case 0x52:
    case 0x55:
    case 0x57:
    case 0x62:
    case 0x7C:
      a1 += 5;
      break;
    case 0xC:
      a1 += 13;
      break;
    case 0x44:
    case 0x4B:
      a1 += 4;
      break;
    case 0x54:
    case 0x56:
      a1 += 9;
      break;
    case 0x7D:
      a1 += 8 * *(unsigned __int16 *)(a1 + 1) + 3;
      break;
    default:
      return result;
    }
  }
}

bool __cdecl Scr_IsEndonThread(unsigned int) { UNIMPLEMENTED(); }

void __cdecl Scr_TerminalError(char const *error) { UNIMPLEMENTED(); }

void __cdecl Scr_InitSystem(int sys) { UNIMPLEMENTED(); }

void __cdecl Scr_AddArrayStringIndexed(unsigned int stringValue) {
  UNIMPLEMENTED();
}

void __cdecl Scr_AddArray() { UNIMPLEMENTED(); }

struct scr_animtree_t __cdecl Scr_GetAnimTree(unsigned int) {
  UNIMPLEMENTED();
}

struct scr_anim_s __cdecl Scr_GetAnim(unsigned int, struct XAnimTree_s *) {
  UNIMPLEMENTED();
}

void __cdecl Scr_ClearOutParams(void) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetConstLowercaseString(unsigned int index) {
  UNIMPLEMENTED();
}

unsigned int __cdecl Scr_GetConstString(unsigned int index) { UNIMPLEMENTED(); }

char const *__cdecl Scr_GetNextCodepos(struct VariableValue_s *top,
                                       char const *pos, int opcode, int mode,
                                       unsigned int *localId) {
  UNIMPLEMENTED();
}

void __cdecl Scr_Shutdown() {
  if (byte_100CED8) {
    byte_100CED8 = 0;
    if (*(_DWORD *)algn_100CED4) {
      FreeValue(a1, *(unsigned int *)algn_100CED4);
      *(_DWORD *)algn_100CED4 = 0;
    }
    Var_Shutdown(a1);
    SL_Shutdown();
  }
}

char const *__cdecl Scr_GetDebugString(unsigned int index) { UNIMPLEMENTED(); }

char const *__cdecl Scr_GetStringIncludeNull(unsigned int) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetConstStringIncludeNull(unsigned int index) {
  UNIMPLEMENTED();
}

char const *__cdecl Scr_GetString(unsigned int index) { UNIMPLEMENTED(); }

void __cdecl Scr_FreeThread(unsigned short handle) { UNIMPLEMENTED(); }

void __cdecl VM_CancelNotify(unsigned int notifyListOwnerId,
                             unsigned int startLocalId) {
  UNIMPLEMENTED();
}

bool __cdecl SetEntityFieldValue(unsigned int classnum, int entnum, int offset,
                                 struct VariableValue_s *value) {
  UNIMPLEMENTED();
}

void __cdecl Scr_CancelNotifyList(unsigned int notifyListOwnerId) {
  UNIMPLEMENTED();
}

void __cdecl Scr_SetStructField(unsigned int structId, unsigned int index) {
  UNIMPLEMENTED();
}

void __cdecl Scr_ShutdownSystem(unsigned char sys, int bComplete) {
  UNIMPLEMENTED();
}

void __cdecl Scr_SetDynamicEntityField(int entnum, int classnum,
                                       unsigned int index) {
  UNIMPLEMENTED();
}

void __cdecl Scr_MakeArray() { UNIMPLEMENTED(); }

void __cdecl Scr_AddVector(float const *value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddConstString(unsigned int value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddIString(char const *) { UNIMPLEMENTED(); }

void __cdecl Scr_AddString(char const *value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddObject(unsigned int id) { UNIMPLEMENTED(); }

void __cdecl Scr_AddUndefined() { UNIMPLEMENTED(); }

void __cdecl Scr_AddAnim(struct scr_anim_s) { UNIMPLEMENTED(); }

void __cdecl Scr_AddFloat(float value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddInt(int value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddBool(int value) { UNIMPLEMENTED(); }

void __cdecl Scr_AddStruct() { UNIMPLEMENTED(); }

void __cdecl Scr_AddEntityNum(int entnum, int classnum) { UNIMPLEMENTED(); }

struct VariableValue_s __cdecl GetEntityFieldValue(unsigned int classnum,
                                                   int entnum, int offset) {
  UNIMPLEMENTED();
}

void __cdecl Scr_NotifyNum(int entnum, int classnum, unsigned int stringValue,
                           unsigned int paramcount) {
  UNIMPLEMENTED();
}

void __cdecl Scr_Init() {
  if (!byte_100CED8) {
    SL_Init(a1);
    Var_Init();
    dword_1008204 = (int)&unk_100C518;
    dword_1008210 = (VariableValue_s *)&unk_1008520;
    dword_1008208 = 0;
    dword_100820C = (int)&unk_1008220;
    scrVmPub[0] = (int)&dword_4EAD98;
    byte_100CEAC = 0;
    byte_1008214 = 0;
    dword_100CEB0 = 0;
    dword_4EAD90 = 0;
    dword_100CEB4 = 0;
    byte_1008216 = 0;
    dword_100821C = 0;
    dword_1008218 = 0;
    *(_DWORD *)algn_100CED4 = AllocValue(a1);
    *(_DWORD *)&algn_100CEB8[4] = 0;
    dword_100CEC0 = 0;
    dword_100CEC4 = 0;
    dword_100CEC8 = 0;
    *(_DWORD *)algn_100CECC = 0;
    dword_100CED0 = 0;
    dword_1008524 = 7;
    dword_4EAD94 = 0;
    byte_114CF44 = 0;
    unk_114E438 = 0;
    dword_114CF2C = 0;
    dword_114CF28 = 0;
    scrAnimPub = 0;
    dword_114CF34 = 0;
    dword_114CF30 = 0;
    byte_100CED8 = 1;
  }
}

void __cdecl Scr_ExecCode(char const *, unsigned int) { UNIMPLEMENTED(); }

void __cdecl Scr_AddExecEntThreadNum(int, int, int, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_AddExecThread(int handle, unsigned int paramcount) {
  UNIMPLEMENTED();
}

unsigned short __cdecl Scr_ExecEntThreadNum(int entnum, int classnum,
                                            int handle,
                                            unsigned int paramcount) {
  UNIMPLEMENTED();
}

unsigned short __cdecl Scr_ExecThread(int handle, unsigned int paramcount) {
  UNIMPLEMENTED();
}

void __cdecl Scr_RunCurrentThreads() {
  unsigned int Variable; // eax
  unsigned int Object;   // eax

  if (*(_DWORD *)&algn_100CEB8[4]) {
    Variable = FindVariable(*(unsigned int *)&algn_100CEB8[4],
                            *(unsigned int *)algn_100CEB8);
    if (Variable) {
      Object = FindObject(Variable);
      VM_Resume(Object, a1);
      SafeRemoveVariable(a1, *(unsigned int *)&algn_100CEB8[4],
                         *(int **)algn_100CEB8);
    }
  }
}

void __cdecl Scr_IncTime() { UNIMPLEMENTED(); }

int g_script_error_level;
int marker_scr_vm;
struct scrVmDebugPub_t scrVmDebugPub;
struct SETJMP_VECTOR4 (*g_script_error)[20] {
  UNIMPLEMENTED();
}

struct scrVmPub_t scrVmPub;
char g_EndPos;
void __cdecl Scr_ErrorInternal(void) { UNIMPLEMENTED(); }

int __cdecl Scr_FindAllThreadsInternal(unsigned int, unsigned int, int, bool,
                                       unsigned int *) {
  UNIMPLEMENTED();
}

void __cdecl Scr_TerminateRunningThread(unsigned int) { UNIMPLEMENTED(); }

int __cdecl Scr_AddLocalVars(unsigned int) { UNIMPLEMENTED(); }

unsigned int __cdecl Scr_GetWaittillThreadStackId(unsigned int, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_VM_Init(void) { UNIMPLEMENTED(); }

void __cdecl VM_UnarchiveStack(unsigned int, struct function_stack_t *,
                               class VariableStackBuffer const *) {
  UNIMPLEMENTED();
}

class VariableStackBuffer *__cdecl VM_ArchiveStack(int, char const *,
                                                   struct VariableValue_s *,
                                                   unsigned int,
                                                   unsigned int *) {
  UNIMPLEMENTED();
}

void __cdecl VM_Shutdown(void) { UNIMPLEMENTED(); }

unsigned int __cdecl GetDummyFieldValue(void) { UNIMPLEMENTED(); }

unsigned int __cdecl GetDummyObject(void) { UNIMPLEMENTED(); }

void __cdecl VM_CancelNotifyInternal(unsigned int, unsigned int, unsigned int,
                                     unsigned int, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_CancelWaittill(unsigned int) { UNIMPLEMENTED(); }

void __cdecl VM_TrimStack(unsigned int, class VariableStackBuffer *, bool) {
  UNIMPLEMENTED();
}

void __cdecl VM_TerminateStack(unsigned int, unsigned int,
                               class VariableStackBuffer *) {
  UNIMPLEMENTED();
}

void __cdecl VM_TerminateTime(unsigned int) { UNIMPLEMENTED(); }

void __cdecl Scr_TerminateWaittillThread(unsigned int, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_TerminateWaitThread(unsigned int, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl Scr_TerminateThread(unsigned int) { UNIMPLEMENTED(); }

void __cdecl IncInParam(void) { UNIMPLEMENTED(); }

void __cdecl VM_Notify(unsigned int, unsigned int, struct VariableValue_s *) {
  UNIMPLEMENTED();
}

unsigned int __cdecl VM_Execute(struct function_stack_t) { UNIMPLEMENTED(); }

unsigned int __cdecl VM_Execute(unsigned int, char const *, unsigned int) {
  UNIMPLEMENTED();
}

void __cdecl VM_Resume(unsigned int) { UNIMPLEMENTED(); }

void __cdecl VM_SetTime(void) { UNIMPLEMENTED(); }
