void __cdecl R_FinishStaticIndexBuffer(struct D3DIndexBuffer *ib) {
  int result; // eax

  do
    result =
        (*(int(__cdecl **)(IDirect3DIndexBuffer9 *))(*(_DWORD *)a1 + 48))(a1);
  while (alwaysfails);
  return result;
}

void __cdecl R_FinishStaticVertexBuffer(struct D3DVertexBuffer *vb) {
  int result; // eax

  do {
    (*(void(__cdecl **)(IDirect3DVertexBuffer9 *))(*(_DWORD *)a1 + 48))(a1);
    result = alwaysfails;
  } while (alwaysfails);
  return result;
}

void __cdecl Load_IndexBuffer(struct D3DIndexBuffer *, void *, int) {
  UNIMPLEMENTED();
}

void __cdecl Load_VertexBuffer(struct D3DVertexBuffer *, void *, int, int) {
  UNIMPLEMENTED();
}

void *__cdecl R_AllocStaticIndexBuffer(struct D3DIndexBuffer *ib,
                                       int sizeInBytes) {
  _DWORD v3[3]; // [esp+2Ch] [ebp-Ch] BYREF

  if ((*(int(__cdecl **)(int, int, int, int, _DWORD, IDirect3DIndexBuffer9 **,
                         _DWORD))(*(_DWORD *)dword_117D8A8 + 108))(
          dword_117D8A8, a2, 8, 101, 0, a1, 0) >= 0) {
    if ((*(int(__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD *, _DWORD))(
            *(_DWORD *)*a1 + 44))(*a1, 0, 0, v3, 0) >= 0)
      return v3[0];
    (*(void(__cdecl **)(_DWORD))(*(_DWORD *)*a1 + 8))(*a1);
  }
  return 0;
}

void *__cdecl R_AllocStaticVertexBuffer(struct D3DVertexBuffer *vb,
                                        int sizeInBytes) {
  const char *v3; // eax
  char *v4;       // eax
  const char *v5; // eax
  char *v6;       // eax
  _DWORD v7[3];   // [esp+2Ch] [ebp-Ch] BYREF

  if ((*(int(__cdecl **)(int, int, int, _DWORD, _DWORD,
                         IDirect3DVertexBuffer9 **, _DWORD))(
          *(_DWORD *)dword_117D8A8 + 104))(dword_117D8A8, a2, 8, 0, 0, a1, 0) <
      0) {
    v5 = (const char *)R_ErrorDescription();
    v6 = va("DirectX didn't create a %i-byte vertex buffer: %s\n", a2, v5);
    R_FatalInitError(v6);
  }
  if ((*(int(__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD *, _DWORD))(
          *(_DWORD *)*a1 + 44))(*a1, 0, 0, v7, 0) < 0) {
    v3 = (const char *)R_ErrorDescription();
    v4 = va("DirectX didn't lock a vertex buffer: %s\n", v3);
    R_FatalInitError(v4);
  }
  return v7[0];
}

void *__cdecl R_AllocDynamicVertexBuffer(struct D3DVertexBuffer *, int) {
  UNIMPLEMENTED();
}

int marker_r_buffers;
void __cdecl R_AllocStaticIndexBufferInternal(struct D3DIndexBuffer *, void *,
                                              int) {
  UNIMPLEMENTED();
}

void __cdecl R_AllocStaticVertexBufferInternal(struct D3DVertexBuffer *, void *,
                                               int) {
  UNIMPLEMENTED();
}

void *__cdecl R_AllocStaticBuffer(int) { UNIMPLEMENTED(); }

R_FreeStaticVertexBuffer(IDirect3DVertexBuffer9 *vb) { UNIMPLEMENTED(); }

R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib) { UNIMPLEMENTED(); }
