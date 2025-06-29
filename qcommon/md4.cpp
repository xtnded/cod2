void __cdecl MD4Init(struct MD4_CTX *)
{
  UNIMPLEMENTED();
}

void __cdecl MD4Update(struct MD4_CTX *context, unsigned char const *input,
                       unsigned int inputLen)
{
  int v3;                    // ecx
  unsigned int v4;           // eax
  int v5;                    // edx
  size_t v6;                 // esi
  const unsigned __int8 *v8; // ebx
  size_t i;                  // esi

  v3 = (LODWORD(a1->count) >> 3) & 0x3F;
  v4 = 8 * a3 + LODWORD(a1->count);
  LODWORD(a1->count) = v4;
    if (8 * a3 <= v4) {
      HIDWORD(a1->count) += a3 >> 29;
      v6 = 64 - v3;
      if (a3 < 64 - v3)
        return Com_Memcpy(&a1->buffer[v3], a2, a3);
    }
    else {
      v5 = HIDWORD(a1->count) + 1;
      HIDWORD(a1->count) = v5;
      HIDWORD(a1->count) = v5 + (a3 >> 29);
      v6 = 64 - v3;
      if (a3 < 64 - v3)
        return Com_Memcpy(&a1->buffer[v3], a2, a3);
    }
  Com_Memcpy(&a1->buffer[v3], a2, v6);
  MD4Transform((int *)a1, (int)a1->buffer);
  if (a3 <= v6 + 63)
    return Com_Memcpy(a1->buffer, &a2[v6], a3 - v6);
  v8 = &a2[v6];
    for (i = v6 + 127;; i += 64) {
      MD4Transform((int *)a1, (int)v8);
      v8 += 64;
      if (a3 <= i)
        break;
    }
  return Com_Memcpy(a1->buffer, &a2[i - 63], a3 - (i - 63));
}

void __cdecl MD4Final(unsigned char *const digest, struct MD4_CTX *context)
{
  int i;                   // ebx
  uint8_t *v3;             // ecx
  unsigned __int8 *v4;     // edx
  unsigned int v5;         // eax
  size_t v6;               // edx
  int j;                   // ebx
  char *v8;                // ecx
  unsigned __int8 *v9;     // edx
  unsigned __int8 v11[32]; // [esp+18h] [ebp-20h] BYREF

    for (i = 1; i != 3; ++i) {
      v3 = &__b->state[4 * i + 16];
      v4 = &v11[4 * i];
      *((_WORD *)v4 - 2) = *((_DWORD *)v3 - 1);
      *(v4 - 2) = *((_WORD *)v3 - 1);
      *(v4 - 1) = *(v3 - 1);
    }
  v5 = (LODWORD(__b->count) >> 3) & 0x3F;
  if (v5 > 0x37)
    v6 = 120 - v5;
  else
    v6 = 56 - v5;
  MD4Update(__b, &PADDING, v6);
  MD4Update(__b, v11, 8u);
    for (j = 1; j != 5; ++j) {
      v8 = (char *)__b + 4 * j;
      v9 = &a1[4 * j];
      *((_WORD *)v9 - 2) = *((_DWORD *)v8 - 1);
      *(v9 - 2) = *((_WORD *)v8 - 1);
      *(v9 - 1) = *(v8 - 1);
    }
  return Com_Memset(__b, 0, 0x58u);
}

unsigned int __cdecl Com_BlockChecksumKey(void *buffer, int length, int key)
{
  MD4_CTX __b;           // [esp+18h] [ebp-70h] BYREF
  unsigned __int8 v4[4]; // [esp+70h] [ebp-18h] BYREF
  int v5;                // [esp+74h] [ebp-14h]
  int v6;                // [esp+78h] [ebp-10h]
  int v7;                // [esp+7Ch] [ebp-Ch]
  va_list va;            // [esp+98h] [ebp+10h] BYREF

  va_start(va, a2);
  __b.count = 0;
  *(_DWORD *)__b.state = 1732584193;
  *(_DWORD *)&__b.state[4] = -271733879;
  *(_DWORD *)&__b.state[8] = -1732584194;
  *(_DWORD *)&__b.state[12] = 271733878;
  MD4Update(&__b, (unsigned __int8 *)va, 4u);
  MD4Update(&__b, a1, a2);
  MD4Final(v4, &__b);
  return v7 ^ v6 ^ v5 ^ *(_DWORD *)v4;
}

unsigned int __cdecl Com_BlockChecksum(void const *buffer, int length)
{
  MD4_CTX __b;           // [esp+18h] [ebp-70h] BYREF
  unsigned __int8 v4[4]; // [esp+70h] [ebp-18h] BYREF
  int v5;                // [esp+74h] [ebp-14h]
  int v6;                // [esp+78h] [ebp-10h]
  int v7;                // [esp+7Ch] [ebp-Ch]

  __b.count = 0;
  *(_DWORD *)__b.state = 1732584193;
  *(_DWORD *)&__b.state[4] = -271733879;
  *(_DWORD *)&__b.state[8] = -1732584194;
  *(_DWORD *)&__b.state[12] = 271733878;
  MD4Update(&__b, a1, a2);
  MD4Final(v4, &__b);
  return v7 ^ v6 ^ v5 ^ *(_DWORD *)v4;
}

int marker_md4;

void __cdecl Decode(unsigned long *, unsigned char const *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl Encode(unsigned char *, unsigned long *, unsigned int)
{
  UNIMPLEMENTED();
}

void __cdecl MD4Transform(unsigned long *const, unsigned char const *const)
{
  UNIMPLEMENTED();
}
