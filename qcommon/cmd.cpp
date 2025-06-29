void __cdecl Cmd_ForEach(void(__cdecl *)(char const *)) { UNIMPLEMENTED(); }

void __cdecl Cmd_Shutdown() {
  void **i; // ebx

  for (i = (void **)cmd_functions; cmd_functions; i = (void **)cmd_functions) {
    cmd_functions = (int)*i;
    Z_FreeInternal(i[1]);
    Z_FreeInternal(i);
  }
}

void __cdecl Cmd_RemoveCommand(char const *cmdName) {
  int v1;  // ebx
  int *v2; // edi

  v1 = cmd_functions;
  if (cmd_functions) {
    v2 = &cmd_functions;
    while (strcmp(__s1, *(const char **)(v1 + 4))) {
      v2 = (int *)v1;
      v1 = *(_DWORD *)v1;
      if (!v1)
        return;
    }
    *v2 = *(_DWORD *)v1;
    if (*(_DWORD *)(v1 + 4))
      Z_FreeInternal(*(void **)(v1 + 4));
    Z_FreeInternal((void *)v1);
  }
}

struct cmd_function_s *__cdecl Cmd_FindCommand(char const *) {
  UNIMPLEMENTED();
}

char *__cdecl SV_Cmd_Argv(int arg arg) {
  if (cmd_argc <= a1)
    return &inData;
  else
    return (const gentity_s *)cmd_argv[a1];
}

char *__cdecl Cmd_Argv(int) {
  if (cmd_argc <= a1)
    return &inData;
  else
    return (const gentity_s *)cmd_argv[a1];
}

int __cdecl SV_Cmd_Argc() { return cmd_argc; }

int __cdecl Cmd_Argc(void) { return cmd_argc; }

void __cdecl Cbuf_InsertText(char const *) { UNIMPLEMENTED(); }

void __cdecl Cbuf_AddText(char const *text) {
  size_t v1; // edi
  int v2;    // ecx

  v1 = strlen(__src);
  v2 = cmd_text[2];
  if ((int)(v1 + v2) < cmd_text[1]) {
    memcpy((void *)(*cmd_text + v2), __src, v1);
    cmd_text[2] += v1;
  } else {
    Com_Printf("Cbuf_AddText: overflow\n");
  }
}

void __cdecl Cbuf_Init() {
  cmd_texts = (int)&cmd_text_buf;
  dword_FFEC08 = 0x10000;
  dword_FFEC0C = 0;
}

void __cdecl Cmd_Wait_f() {
  if (cmd_argc == 2)
    cmd_wait = atoi(dword_483084);
  else
    cmd_wait = 1;
}

void __cdecl Cbuf_SwitchToLocalClient(int) { UNIMPLEMENTED(); }

void __cdecl Cmd_SetAutoComplete(char const *cmdName, char const *dir,
                                 char const *ext) {
  int v3;             // ebx
  const char *result; // eax

  v3 = cmd_functions;
  if (cmd_functions) {
    while (strcmp(__s1, *(const char **)(v3 + 4))) {
      v3 = *(_DWORD *)v3;
      if (!v3)
        goto LABEL_4;
    }
  } else {
  LABEL_4:
    v3 = 0;
  }
  *(_DWORD *)(v3 + 8) = a2;
  result = a3;
  *(_DWORD *)(v3 + 12) = a3;
  return result;
}

char *__cdecl Cmd_Args(int start) {
  char **v2; // esi
  int v3;    // ebx

  cmd_args1 = 0;
  if (a1 >= cmd_argc)
    return &cmd_args1;
  v2 = (char **)&cmd_argv[a1];
  v3 = a1;
  do {
    I_strncat(&cmd_args1, 1024, *v2);
    if (v3 != cmd_argc - 1)
      I_strncat(&cmd_args1, 1024, " ");
    ++v3;
    ++v2;
  } while (cmd_argc > v3);
  return &cmd_args1;
}

void __cdecl SV_Cmd_ArgvBuffer(int arg arg, char *buffer buffer,
                               int bufferLength bufferLength) {
  if (a1 >= cmd_argc)
    return I_strncpyz(a2, (char *)&inData, a3);
  else
    return I_strncpyz(a2, (char *)cmd_argv[a1], a3);
}

void __cdecl Cmd_ArgvBuffer(int, char *, int) {
  if (a1 >= cmd_argc)
    return I_strncpyz(a2, (char *)&inData, a3);
  else
    return I_strncpyz(a2, (char *)cmd_argv[a1], a3);
}

void __cdecl SV_Cmd_TokenizeString2(char const *text_in, int max_tokens) {
  UNIMPLEMENTED();
}

void __cdecl Cmd_TokenizeString2(char const *, int) {
  int result; // eax

  result = Cmd_TokenizeStringInternal(a1, a2, (int)cmd_argv, cmd_tokenized);
  cmd_argc = result;
  return result;
}

void __cdecl Cmd_ArgsBuffer(char *buffer, int bufferLength) {
  int v2;  // ebx
  int *v3; // esi

  cmd_args1 = 0;
  if (cmd_argc > 1) {
    v2 = 1;
    v3 = cmd_argv;
    do {
      I_strncat(&cmd_args1, 1024, (char *)v3[1]);
      if (v2 != cmd_argc - 1)
        I_strncat(&cmd_args1, 1024, " ");
      ++v2;
      ++v3;
    } while (v2 < cmd_argc);
  }
  return I_strncpyz(__dst, &cmd_args1, a2);
}

void __cdecl SV_Cmd_TokenizeString(char const *text_in text_in) {
  int result; // eax

  result = Cmd_TokenizeStringInternal(a1, 0, (int)cmd_argv, cmd_tokenized);
  cmd_argc = result;
  return result;
}

void __cdecl Cmd_TokenizeString(char const *) {
  int result; // eax

  result = Cmd_TokenizeStringInternal(a1, 0, (int)cmd_argv, cmd_tokenized);
  cmd_argc = result;
  return result;
}

void __cdecl Cmd_ExecuteString(char const *text) {
  int v1;           // ebx
  int *v2;          // esi
  void (*v3)(void); // ecx

  cmd_argc = Cmd_TokenizeStringInternal(a1, 0, (int)cmd_argv, cmd_tokenized);
  if (cmd_argc) {
    v1 = cmd_functions;
    if (!cmd_functions)
      goto LABEL_6;
    v2 = &cmd_functions;
    while (I_stricmp((char *)cmd_argv[0], *(char **)(v1 + 4))) {
      v2 = (int *)v1;
      v1 = *(_DWORD *)v1;
      if (!v1)
        goto LABEL_6;
    }
    *v2 = *(_DWORD *)v1;
    *(_DWORD *)v1 = cmd_functions;
    cmd_functions = v1;
    v3 = *(void (**)(void))(v1 + 16);
    if (v3) {
      v3();
    } else {
    LABEL_6:
      if (!Dvar_Command() &&
          (!*(_DWORD *)(legacyHacks + 4) || !CL_GameCommand()) &&
          (!com_sv_running || !*(_BYTE *)(com_sv_running + 8) ||
           !SV_GameCommand())) {
        CL_ForwardCommandToServer(a1);
      }
    }
  }
}

void __cdecl SV_Cmd_ExecuteString(char const *text) { Cmd_ExecuteString(a1); }

void __cdecl Cbuf_Execute() { Cbuf_ExecuteInternal(); }

void __cdecl Cbuf_ExecuteText(int exec_when, char const *text) {
  unsigned int v3; // ebx
  void **v4;       // edx
  int v5;          // ecx
  int v6;          // ecx
  unsigned int v7; // edi
  size_t v8;       // ebx
  int v9;          // ecx

  if (a1 == 1) {
    v3 = strlen(__src) + 1;
    v4 = (void **)cmd_text;
    v5 = cmd_text[2];
    if ((int)(v3 + v5) > cmd_text[1]) {
      Com_Printf("Cbuf_InsertText overflowed\n");
    } else {
      v6 = v5 - 1;
      if (v6 >= 0) {
        v7 = v3 + v6;
        while (1) {
          *((_BYTE *)*v4 + v7--) = *((_BYTE *)*v4 + v6--);
          if (v6 == -1)
            break;
          v4 = (void **)cmd_text;
        }
        v4 = (void **)cmd_text;
      }
      memcpy(*v4, __src, v3 - 1);
      *(_BYTE *)(*cmd_text + v3 - 1) = 10;
      cmd_text[2] += v3;
    }
  } else if (a1 == 2) {
    v8 = strlen(__src);
    v9 = cmd_text[2];
    if ((int)(v8 + v9) < cmd_text[1]) {
      memcpy((void *)(*cmd_text + v9), __src, v8);
      cmd_text[2] += v8;
    } else {
      Com_Printf("Cbuf_AddText: overflow\n");
    }
  } else if (a1) {
    Com_Error(0, "\x15Cbuf_ExecuteText: bad exec_when", a3);
  } else if (__src && *__src) {
    Cmd_ExecuteString(__src);
  } else {
    Cbuf_ExecuteInternal();
  }
}

void __cdecl Cmd_List_f() {
  const char *v0; // esi
  int v1;         // ebx
  int v2;         // edi

  if (cmd_argc <= 1) {
    v0 = 0;
    v1 = cmd_functions;
    if (cmd_functions)
      goto LABEL_3;
  LABEL_10:
    Com_Printf("%i commands\n", 0);
    return;
  }
  v0 = dword_483084;
  v1 = cmd_functions;
  if (!cmd_functions)
    goto LABEL_10;
LABEL_3:
  if (v0) {
    v2 = 0;
    do {
      if ((unsigned __int8)Com_Filter(v0, *(char **)(v1 + 4), 0)) {
        Com_Printf("%s\n", *(const char **)(v1 + 4));
        ++v2;
      }
      v1 = *(_DWORD *)v1;
    } while (v1);
  } else {
    v2 = 0;
    do {
      Com_Printf("%s\n", *(const char **)(v1 + 4));
      ++v2;
      v1 = *(_DWORD *)v1;
    } while (v1);
  }
  Com_Printf("%i commands\n", v2);
}

cmd_function_s *__cdecl Cmd_AddCommand(char *__s1, void (*a2)(void))
{
  cmd_function_s *v2; // ebx
  cmd_function_s *result; // eax
  cmd_function_s *v4; // ebx

  v2 = cmd_functions;
  if ( cmd_functions )
  {
    while ( 1 )
    {
      result = (cmd_function_s *)strcmp(__s1, v2->name);
      if ( !result )
        break;
      v2 = (cmd_function_s *)v2->next;
      if ( !v2 )
        goto LABEL_4;
    }
    if ( a2 )
      return (cmd_function_s *)Com_Printf("Cmd_AddCommand: %s already defined\n", __s1);
  }
  else
  {
LABEL_4:
    v4 = (cmd_function_s *)Z_MallocInternal(0x14u);
    v4->name = CopyStringInternal(__s1);
    v4->function = (int32_t)a2;
    result = cmd_functions;
    v4->next = (int32_t)cmd_functions;
    cmd_functions = v4;
  }
  return result;
}

void __cdecl Cmd_Echo_f(void) { UNIMPLEMENTED(); }

void __cdecl Cmd_Vstr_f() {
  const char *v0;  // edi
  int Var;         // eax
  unsigned int v2; // ebx
  void **v3;       // edx
  int v4;          // ecx
  unsigned int v5; // edi
  int v6;          // ecx
  char *__src;     // [esp+1Ch] [ebp-1Ch]

  if (cmd_argc == 2) {
    v0 = dword_483084;
    Var = Dvar_FindVar(dword_483084);
    if (Var) {
      if ((unsigned __int8)(*(_BYTE *)(Var + 6) - 6) <= 1u) {
        __src = va("%s\n", *(const char **)(Var + 8));
        v2 = strlen(__src) + 1;
        v3 = (void **)cmd_text;
        v4 = cmd_text[2];
        if ((int)(v2 + v4) > cmd_text[1]) {
          Com_Printf("Cbuf_InsertText overflowed\n");
        } else {
          if (v4 - 1 >= 0) {
            v5 = v2 + v4 - 1;
            v6 = v4 - 1;
            while (1) {
              *((_BYTE *)*v3 + v5--) = *((_BYTE *)*v3 + v6--);
              if (v6 == -1)
                break;
              v3 = (void **)cmd_text;
            }
            v3 = (void **)cmd_text;
          }
          memcpy(*v3, __src, v2 - 1);
          *(_BYTE *)(*cmd_text + v2 - 1) = 10;
          cmd_text[2] += v2;
        }
      } else {
        Com_Printf("%s is not a string-based dvar\n", *(const char **)Var);
      }
    } else {
      Com_Printf("%s doesn't exist\n", v0);
    }
  } else {
    Com_Printf("vstr <variablename> : execute a variable command\n");
  }
}

void __cdecl Cmd_Init() {
  _DWORD *v0; // ebx
  int v1;     // edi
  _DWORD *v2; // ebx
  int v3;     // edi
  _DWORD *v4; // ebx
  int v5;     // edi
  _DWORD *v6; // ebx
  int v7;     // [esp+3Ch] [ebp-1Ch]
  int v8;     // [esp+3Ch] [ebp-1Ch]
  int v9;     // [esp+3Ch] [ebp-1Ch]
  int v10;    // [esp+3Ch] [ebp-1Ch]

  v7 = cmd_functions;
  if (cmd_functions) {
    while (strcmp("cmdlist", *(const char **)(v7 + 4))) {
      v7 = *(_DWORD *)v7;
      if (!v7)
        goto LABEL_4;
    }
    Com_Printf("Cmd_AddCommand: %s already defined\n", "cmdlist");
    v1 = cmd_functions;
  } else {
  LABEL_4:
    v0 = Z_MallocInternal(0x14u);
    v0[1] = CopyStringInternal("cmdlist");
    v0[4] = Cmd_List_f;
    *v0 = cmd_functions;
    cmd_functions = (int)v0;
    v1 = (int)v0;
  }
  v8 = v1;
  if (v1) {
    while (strcmp("exec", *(const char **)(v8 + 4))) {
      v8 = *(_DWORD *)v8;
      if (!v8)
        goto LABEL_8;
    }
    Com_Printf("Cmd_AddCommand: %s already defined\n", "exec");
    v3 = cmd_functions;
  } else {
  LABEL_8:
    v2 = Z_MallocInternal(0x14u);
    v2[1] = CopyStringInternal("exec");
    v2[4] = Cmd_Exec_f;
    *v2 = cmd_functions;
    cmd_functions = (int)v2;
    v3 = (int)v2;
  }
  v9 = v3;
  if (v3) {
    while (strcmp("vstr", *(const char **)(v9 + 4))) {
      v9 = *(_DWORD *)v9;
      if (!v9)
        goto LABEL_12;
    }
    Com_Printf("Cmd_AddCommand: %s already defined\n", "vstr");
    v5 = cmd_functions;
  } else {
  LABEL_12:
    v4 = Z_MallocInternal(0x14u);
    v4[1] = CopyStringInternal("vstr");
    v4[4] = Cmd_Vstr_f;
    *v4 = cmd_functions;
    cmd_functions = (int)v4;
    v5 = (int)v4;
  }
  v10 = v5;
  if (v5) {
    while (strcmp("wait", *(const char **)(v10 + 4))) {
      v10 = *(_DWORD *)v10;
      if (!v10)
        goto LABEL_16;
    }
    Com_Printf("Cmd_AddCommand: %s already defined\n", "wait");
  } else {
  LABEL_16:
    v6 = Z_MallocInternal(0x14u);
    v6[1] = CopyStringInternal("wait");
    v6[4] = Cmd_Wait_f;
    *v6 = cmd_functions;
    cmd_functions = (int)v6;
  }
}

struct cmd_t *cmd_text;
int cmd_wait;
int marker_cmd;
struct cmd_t *cmd_texts;
int __cdecl Cmd_TokenizeStringInternal(char const *, int, char **, char *) {
  UNIMPLEMENTED();
}

void __cdecl Cbuf_ExecuteInternal(void) {
  void **v0;        // edx
  int v1;           // ebx
  _BYTE *v2;        // edi
  int v3;           // esi
  size_t v4;        // eax
  int v5;           // edx
  char v6;          // cl
  char v7;          // dl
  char __dst[4120]; // [esp+10h] [ebp-1018h] BYREF

  v0 = (void **)cmd_text;
  v1 = cmd_text[2];
  if (v1) {
    while (!cmd_wait) {
      v2 = *v0;
      if (v1 > 0) {
        v6 = 0;
        v3 = 0;
        while (1) {
          v7 = v2[v3];
          if (v7 == 34)
            ++v6;
          if ((v6 & 1) == 0 && v7 == 59 || v7 == 10 || v7 == 13)
            break;
          if (v1 == ++v3) {
            v3 = v1;
            break;
          }
        }
        if (v3 <= 4094) {
          v4 = v3;
        } else {
          v3 = 4095;
          v4 = 4095;
        }
      } else {
        v3 = 0;
        v4 = 0;
      }
      memcpy(__dst, v2, v4);
      __dst[v3] = 0;
      v5 = cmd_text[2];
      if (v3 == v5) {
        cmd_text[2] = 0;
      } else {
        cmd_text[2] = v5 - (v3 + 1);
        memmove(v2, &v2[v3 + 1], cmd_text[2]);
      }
      Cmd_ExecuteString(__dst);
      v0 = (void **)cmd_text;
      v1 = cmd_text[2];
      if (!v1)
        return;
    }
    --cmd_wait;
  }
}

bool __cdecl Cmd_ExecFromFastFile(char const *) { UNIMPLEMENTED(); }

bool __cdecl Cmd_ExecFromDisk(char const *) { UNIMPLEMENTED(); }

void __cdecl Cmd_Exec_f(void) {
  unsigned int v0; // ebx
  void **v1;       // edx
  int v2;          // ecx
  unsigned int v3; // edi
  int v4;          // ecx
  const char *v5;  // eax
  void *__src;     // [esp+1Ch] [ebp-6Ch]
  char __dst[64];  // [esp+2Ch] [ebp-5Ch] BYREF
  int v8;          // [esp+6Ch] [ebp-1Ch] BYREF

  if (cmd_argc == 2) {
    I_strncpyz(__dst, dword_483084, 64);
    Com_DefaultExtension(__dst, 0x40u, ".cfg");
    FS_ReadFile(__dst, (char **)&v8);
    if (v8) {
      Com_Printf("execing %s\n", __dst);
      __src = (void *)v8;
      v0 = strlen((const char *)v8) + 1;
      v1 = (void **)cmd_text;
      v2 = cmd_text[2];
      if ((int)(v0 + v2) > cmd_text[1]) {
        Com_Printf("Cbuf_InsertText overflowed\n");
      } else {
        if (v2 - 1 >= 0) {
          v3 = v0 + v2 - 1;
          v4 = v2 - 1;
          while (1) {
            *((_BYTE *)*v1 + v3--) = *((_BYTE *)*v1 + v4--);
            if (v4 == -1)
              break;
            v1 = (void **)cmd_text;
          }
          v1 = (void **)cmd_text;
        }
        memcpy(*v1, __src, v0 - 1);
        *(_BYTE *)(*cmd_text + v0 - 1) = 10;
        cmd_text[2] += v0;
      }
      FS_FreeFile((void *)v8);
    } else {
      if (cmd_argc <= 1)
        v5 = (const char *)&inData;
      else
        v5 = dword_483084;
      Com_Printf("couldn't exec %s\n", v5);
    }
  } else {
    Com_Printf("exec <filename> : execute a script file\n");
  }
}

Cmd_GetAutoCompleteFileList(char const *cmdName, int *fileCount,
                            int allocTrackType) {
  UNIMPLEMENTED();
}
