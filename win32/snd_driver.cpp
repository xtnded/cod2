float __cdecl XAudioSampleRateToPitch(unsigned long, unsigned long)
{
  UNIMPLEMENTED();
}

public:
unsigned long __cdecl IXAudioVoice::Release(void)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioVoice::SetEffectParam(unsigned char, unsigned char,
                                          unsigned char,
                                          union XAUDIOFXPARAM const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioVoice::SetVoiceOutputVolume(
    struct XAUDIOVOICEOUTPUTVOLUME const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioVoice::GetVoiceState(unsigned char *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::SubmitPacket(struct XAUDIOPACKET const *,
                                              unsigned char)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::Start(unsigned char)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::Stop(unsigned char)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::Discontinuity(void)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::SetPacketPosition(
    union XAUDIOPACKETPOSITION const *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::GetStreamPosition(unsigned long *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::GetVolume(float *)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::SetVolume(float)
{
  UNIMPLEMENTED();
}

public:
long __cdecl IXAudioSourceVoice::SetPitch(float)
{
  UNIMPLEMENTED();
}

int __cdecl SND_RawSamplesTime()
{
  int result; // eax

  result = dword_4A3C5C;
  if (dword_4A3C5C)
    return (int)((double)AIL_sample_position(dword_4A3C5C) *
                     *(double *)&qword_4A3CA8 +
                 *(double *)&qword_4A3CA0);
  return result;
}

void __cdecl SND_EndRawSamples()
{
    if (dword_4A3C5C) {
      AIL_end_sample(dword_4A3C5C);
      AIL_release_sample_handle(dword_4A3C5C);
      dword_4A3C5C = 0;
      Z_FreeInternal((void *)dword_4A3C6C);
    }
}

void __cdecl SND_RawSamples(int samples, int rate, int width, int s_channels,
                            unsigned char const *data)
{
  int result;  // eax
  int v7;      // ebx
  size_t v8;   // edi
  int i;       // edx
  int v10;     // eax
  int32_t v11; // ebx
  int v12;     // eax
  int v13;     // edx
  char v14;    // [esp+8h] [ebp-20h]

  result = (int)g_snd;
  if (!g_snd[0])
    return result;
  if (dword_4A3C5C)
    goto LABEL_3;
  dword_4A3C5C = (int)AIL_allocate_sample_handle();
  if (!dword_4A3C5C)
    Com_Error(1, "\x15MILES 2D sound sample allocation failed on raw channel\n",
              v14);
  dword_4A3C60 = a2;
  dword_4A3C64 = a3;
  dword_4A3C68 = a4;
  AIL_init_sample(dword_4A3C5C);
    if (a4 == 1) {
      if (a3 != 2)
        goto LABEL_20;
      v11 = 1;
    }
    else if (a3 == 1) {
      v11 = 2;
    }
    else {
        if (a3 != 2) {
        LABEL_20:
          v11 = 0;
          goto LABEL_21;
        }
      v11 = 3;
    }
LABEL_21:
  AIL_set_sample_type(dword_4A3C5C, v11);
  AIL_set_sample_playback_rate(dword_4A3C5C, a2);
  AIL_set_sample_volume_levels(dword_4A3C5C, 0.5 * *(float *)&dword_FFD824,
                               0.5 * *(float *)&dword_FFD824);
  v12 = AIL_minimum_sample_buffer_size();
  v13 = 0x2000;
  if (v12 >= 8193)
    v13 = v12;
  dword_4A3C90 = v13;
  dword_4A3C6C = (int)Z_MallocInternal(32 * v13);
  memset(byte_4A3C70, 0, sizeof(byte_4A3C70));
  dword_4A3C98 = 0;
  dword_4A3C9C = 0;
  dword_4A3C94 = 0;
  qword_4A3CA0 = 0;
  result = dword_4A3C68 * dword_4A3C64 * dword_4A3C60;
  *(double *)&qword_4A3CA8 = (float)(1000.0 / (float)result);
    if (dword_4A3C5C) {
    LABEL_3:
      v7 = a4 * a1 * a3;
        while (v7) {
            for (i = dword_4A3C9C; byte_4A3C70[dword_4A3C9C];
                 i = dword_4A3C9C) {
              SND_Update();
              i = dword_4A3C9C;
              if (!byte_4A3C70[dword_4A3C9C])
                break;
              SND_Update();
            }
          v8 = dword_4A3C90 - dword_4A3C94;
            if (v7 < dword_4A3C90 - dword_4A3C94) {
              v8 = v7;
              v7 = 0;
            }
            else {
              v7 -= v8;
            }
          Com_Memcpy((void *)(dword_4A3C94 + dword_4A3C6C + i * dword_4A3C90),
                     __src, v8);
          __src += v8;
          result = dword_4A3C94 + v8;
          dword_4A3C94 = result;
            if (result == dword_4A3C90) {
              dword_4A3C94 = 0;
              v10 = dword_4A3C9C;
              byte_4A3C70[dword_4A3C9C] = 1;
              result = (v10 + 1) % 32;
              dword_4A3C9C = result;
            }
        }
    }
  return result;
}

int __cdecl SND_GetDriverCPUPercentage()
{
  return AIL_digital_CPU_percent();
}

void __cdecl SND_DriverPreUpdate(int frametime)
{
  ;
}

int __cdecl SND_GetSoundFileSize(void const *pSoundFile)
{
  return a1[2] + 36;
}

int __cdecl SND_GetStreamChannelLength(int index)
{
  _DWORD v2[3]; // [esp+1Ch] [ebp-Ch] BYREF

  AIL_stream_ms_position((int)*(&dword_4A3BA8 + a1), (int)v2, 0);
  return v2[0];
}

void __cdecl SND_Update3DChannelReverb(int index)
{
  int v1; // edx

  v1 = *(_DWORD *)&g_snd[80 * a1 + 856];
  if (v1 &&
      (!*(_BYTE *)(snd_enableReverb + 8) || (*(_BYTE *)(v1 + 44) & 0x10) != 0))
    AIL_set_3D_sample_effects_level(*(&dword_4A3BA8 + a1), 0);
  else
    AIL_set_3D_sample_effects_level(*(&dword_4A3BA8 + a1),
                                    *(_DWORD *)(dword_FFDAD8 + 16));
}

int __cdecl SND_GetStreamChannelPlaybackRate(int index)
{
  return AIL_stream_playback_rate((int)*(&dword_4A3BA8 + a1));
}

int __cdecl SND_Get3DChannelPlaybackRate(int index)
{
  return AIL_3D_sample_playback_rate(*(&dword_4A3BA8 + a1));
}

int __cdecl SND_Get2DChannelPlaybackRate(int index)
{
  return AIL_sample_playback_rate(dword_4A3AD4[a1]);
}

bool __cdecl SND_IsStreamChannelFree(int index)
{
  int v1;   // ebx
  char *v2; // eax
  char *v3; // eax

  v1 = a1 - 32;
  if (!dword_4A3C28[a1 - 32])
    return 1;
  v2 = &g_snd[80 * a1];
  if (v2[892] || *((_DWORD *)v2 + 207))
    return 0;
  v3 = v2 + 848;
    if (*((_DWORD *)v3 + 2) || *((_DWORD *)v3 + 3)) {
        if (AIL_stream_status(dword_4A3C28[a1 - 32]) == 2) {
          AIL_close_stream(dword_4A3C28[v1]);
          dword_4A3C20[v1 + 2] = 0;
          return 1;
        }
      return 0;
    }
  return 1;
}

bool __cdecl SND_Is3DChannelFree(int index)
{
  char *v1; // eax
  char *v2; // eax

  v1 = &g_snd[80 * a1];
  if (v1[892] || *((_DWORD *)v1 + 207))
    return 0;
  v2 = v1 + 848;
  return !*((_DWORD *)v2 + 2) && !*((_DWORD *)v2 + 3) ||
         AIL_3D_sample_status(*(&dword_4A3BA8 + a1)) == 2;
}

bool __cdecl SND_Is2DChannelFree(int index)
{
  char *v1; // eax
  char *v2; // eax

  v1 = &g_snd[80 * a1];
  if (v1[892] || *((_DWORD *)v1 + 207))
    return 0;
  v2 = v1 + 848;
  return !*((_DWORD *)v2 + 2) && !*((_DWORD *)v2 + 3) ||
         AIL_sample_status(dword_4A3AD4[a1]) == 2;
}

void __cdecl XA_PacketCacheInit(void)
{
  UNIMPLEMENTED();
}

int __cdecl SND_Get3DChannelLength(int index)
{
  return AIL_3D_sample_length(*(&dword_4A3BA8 + a1));
}

int __cdecl SND_Get2DChannelLength(int)
{
  _DWORD v2[3]; // [esp+1Ch] [ebp-Ch] BYREF

  AIL_sample_ms_position(dword_4A3AD4[a1], (int)v2, 0);
  return v2[0];
}

void __cdecl SND_Set3DPosition(int index, float const *const org)
{
  int v2;   // eax
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm4_4

  v2 = 56 * SND_GetListenerIndexNearestToOrigin();
  v3 = *a2 - *(float *)&g_snd[v2 + 756];
  v4 = a2[1] - *(float *)&g_snd[v2 + 760];
  v5 = a2[2] - *(float *)&g_snd[v2 + 764];
  AIL_set_3D_position(
      *(&dword_4A3BA8 + a1),
      -(float)((float)((float)(v3 * *(float *)&g_snd[v2 + 780]) +
                       (float)(v4 * *(float *)&g_snd[v2 + 784])) +
               (float)(v5 * *(float *)&g_snd[v2 + 788])),
      (float)((float)(v3 * *(float *)&g_snd[v2 + 792]) +
              (float)(v4 * *(float *)&g_snd[v2 + 796])) +
          (float)(v5 * *(float *)&g_snd[v2 + 800]),
      (float)((float)(v3 * *(float *)&g_snd[v2 + 768]) +
              (float)(v4 * *(float *)&g_snd[v2 + 772])) +
          (float)(v5 * *(float *)&g_snd[v2 + 776]));
}

void __cdecl SND_GetStreamChannelSaveInfo(int index,
                                          struct snd_save_stream_t *info)
{
  int v2;          // edi
  float v3;        // xmm1_4
  unsigned int v4; // edx
  float v5;        // xmm0_4
  float v6;        // xmm0_4
  int result;      // eax
  float v8;        // [esp+1Ch] [ebp-2Ch]
  int v9;          // [esp+28h] [ebp-20h] BYREF
  int v10[7];      // [esp+2Ch] [ebp-1Ch] BYREF

  v2 = (int)*(&dword_4A3BA8 + a1);
  AIL_stream_ms_position(v2, (int)&v9, (int)v10);
    if (v10[0] < 0) {
      v3 = (float)(v10[0] & 1 | ((unsigned int)v10[0] >> 1)) +
           (float)(v10[0] & 1 | ((unsigned int)v10[0] >> 1));
      v4 = v9;
      if (v9 >= 0)
        goto LABEL_3;
    }
    else {
      v3 = (float)v10[0];
      v4 = v9;
        if (v9 >= 0) {
        LABEL_3:
          v5 = (float)(int)v4;
          goto LABEL_4;
        }
    }
  v5 = (float)(v4 & 1 | (v4 >> 1)) + (float)(v4 & 1 | (v4 >> 1));
LABEL_4:
  a2->fraction = v3 / v5;
  v6 = (float)((float)AIL_stream_playback_rate(v2) / *(float *)&dword_FFD810) +
       0.5;
  v8 = floorf(v6);
  a2->rate = (int)v8;
  a2->basevolume = *(_DWORD *)&g_snd[80 * a1 + 840];
  AIL_stream_volume_pan(v2, (float *)&a2->volume, (float *)&a2->pan);
  if (*(float *)&dword_FFD824 == 0.0)
    a2->volume = *(_DWORD *)&g_snd[80 * a1 + 840];
  else
    *(float *)&a2->volume = *(float *)&a2->volume / *(float *)&dword_FFD824;
  a2->org[0] = *(float *)&g_snd[80 * a1 + 868];
  a2->org[1] = *(float *)&g_snd[80 * a1 + 872];
  result = *(_DWORD *)&g_snd[80 * a1 + 876];
  LODWORD(a2->org[2]) = result;
  return result;
}

void __cdecl SND_Get3DChannelSaveInfo(int index,
                                      struct snd_save_3D_sample_t *info)
{
  void *v2;      // edi
  signed int v3; // ebx
  signed int v4; // eax
  float v5;      // xmm1_4
  float v6;      // xmm0_4
  float v7;      // [esp+1Ch] [ebp-1Ch]

  v2 = *(&dword_4A3BA8 + a1);
  v3 = AIL_3D_sample_offset(v2);
  v4 = AIL_3D_sample_length(v2);
    if (v3 < 0) {
      v5 = (float)(v3 & 1 | ((unsigned int)v3 >> 1)) +
           (float)(v3 & 1 | ((unsigned int)v3 >> 1));
      if (v4 >= 0)
        goto LABEL_3;
    }
    else {
      v5 = (float)v3;
        if (v4 >= 0) {
        LABEL_3:
          v6 = (float)v4;
          goto LABEL_4;
        }
    }
  v6 = (float)(v4 & 1 | ((unsigned int)v4 >> 1)) +
       (float)(v4 & 1 | ((unsigned int)v4 >> 1));
LABEL_4:
  a2->fraction = v5 / v6;
  a2->pitch = *(_DWORD *)&g_snd[80 * a1 + 848];
  v7 = AIL_3D_sample_volume(v2);
  *(float *)&a2->volume = v7;
  if (*(float *)&dword_FFD824 == 0.0)
    a2->volume = *(_DWORD *)&g_snd[80 * a1 + 840];
  else
    *(float *)&a2->volume = v7 / *(float *)&dword_FFD824;
  AIL_3D_position(v2, a2->org, &a2->org[1], &a2->org[2]);
}

void __cdecl SND_Get2DChannelSaveInfo(int index,
                                      struct snd_save_2D_sample_t *info)
{
  float v2;             // xmm1_4
  unsigned int v3;      // edx
  float v4;             // xmm0_4
  CSoundObject *result; // eax
  int v6;               // [esp+1Ch] [ebp-2Ch]
  int v7;               // [esp+28h] [ebp-20h] BYREF
  int v8[7];            // [esp+2Ch] [ebp-1Ch] BYREF

  v6 = dword_4A3AD4[a1];
  AIL_sample_ms_position(v6, (int)&v7, (int)v8);
    if (v8[0] < 0) {
      v2 = (float)(v8[0] & 1 | ((unsigned int)v8[0] >> 1)) +
           (float)(v8[0] & 1 | ((unsigned int)v8[0] >> 1));
      v3 = v7;
      if (v7 >= 0)
        goto LABEL_3;
    }
    else {
      v2 = (float)v8[0];
      v3 = v7;
        if (v7 >= 0) {
        LABEL_3:
          v4 = (float)(int)v3;
          goto LABEL_4;
        }
    }
  v4 = (float)(v3 & 1 | (v3 >> 1)) + (float)(v3 & 1 | (v3 >> 1));
LABEL_4:
  a2->fraction = v2 / v4;
  a2->pitch = *(_DWORD *)&g_snd[80 * a1 + 848];
  result = AIL_sample_volume_pan(v6, (float *)&a2->volume, (float *)&a2->pan);
    if (*(float *)&dword_FFD824 == 0.0) {
      result = *(CSoundObject **)&g_snd[80 * a1 + 840];
      a2->volume = (int32_t)result;
    }
    else {
      *(float *)&a2->volume = *(float *)&a2->volume / *(float *)&dword_FFD824;
    }
  return result;
}

void __cdecl SND_UpdateStreamChannelReverb(int index)
{
  int v1; // edx

  v1 = *(_DWORD *)&g_snd[80 * a1 + 856];
  if (v1 &&
      (!*(_BYTE *)(snd_enableReverb + 8) || (*(_BYTE *)(v1 + 44) & 0x10) != 0))
    AIL_set_stream_reverb_levels((int)*(&dword_4A3BA8 + a1), 1065353216, 0);
  else
    AIL_set_stream_reverb_levels((int)*(&dword_4A3BA8 + a1), 1065353216,
                                 *(_DWORD *)(dword_FFDAD8 + 16));
}

void __cdecl SND_Update2DChannelReverb(int index)
{
  int v1; // edx

  v1 = *(_DWORD *)&g_snd[80 * a1 + 856];
  if (v1 &&
      (!*(_BYTE *)(snd_enableReverb + 8) || (*(_BYTE *)(v1 + 44) & 0x10) != 0))
    AIL_set_sample_reverb_levels(dword_4A3AD4[a1], 1065353216, 0);
  else
    AIL_set_sample_reverb_levels(dword_4A3AD4[a1], 1065353216,
                                 *(_DWORD *)(dword_FFDAD8 + 16));
}

void __cdecl SND_SetStreamChannelPlaybackRate(int index, int rate)
{
  return AIL_set_stream_playback_rate((int)*(&dword_4A3BA8 + a1), a2);
}

void __cdecl SND_Set3DChannelPlaybackRate(int index, int rate)
{
  return AIL_set_3D_sample_playback_rate(*(&dword_4A3BA8 + a1), a2);
}

void __cdecl SND_Set2DChannelPlaybackRate(int index, int rate)
{
  return AIL_set_sample_playback_rate(dword_4A3AD4[a1], a2);
}

void __cdecl SND_SetStreamChannelVolume(int, float)
{
  UNIMPLEMENTED();
}

float __cdecl SND_GetStreamChannelVolume(int index)
{
  char *v1;    // ebx
  float v4;    // [esp+28h] [ebp-10h] BYREF
  float v5[3]; // [esp+2Ch] [ebp-Ch] BYREF

  AIL_stream_volume_levels((int)*(&dword_4A3BA8 + a1), v5, &v4);
  v1 = &g_snd[80 * a1];
  if (*((_DWORD *)v1 + 213) != 2 ||
      SND_IsAliasChannel3D((*(_DWORD *)(*((_DWORD *)v1 + 214) + 44) & 0x780) >>
                           7))
    return (float)(v5[0] + v4);
  else
    return v5[0];
}

void __cdecl SND_Set3DChannelVolume(int, float)
{
  UNIMPLEMENTED();
}

float __cdecl SND_Get3DChannelVolume(int index)
{
  return AIL_3D_sample_volume(*(&dword_4A3BA8 + a1));
}

void __cdecl SND_Set2DChannelVolume(int, float)
{
  UNIMPLEMENTED();
}

float __cdecl SND_Get2DChannelVolume(int index)
{
  float v2;    // [esp+28h] [ebp-10h] BYREF
  float v3[3]; // [esp+2Ch] [ebp-Ch] BYREF

  AIL_sample_volume_levels(dword_4A3AD4[a1], v3, &v2);
  if (*(_DWORD *)&g_snd[80 * a1 + 852] == 2)
    return v3[0];
  else
    return (float)(v3[0] + v2);
}

struct IXAudioSourceVoice *__cdecl XA_GetNewSourceVoice(
    int, struct XAUDIOSOURCEFORMAT *)
{
  UNIMPLEMENTED();
}

void __cdecl SND_PauseStreamChannel(int index)
{
  int result; // eax

  result = AIL_pause_stream((int)*(&dword_4A3BA8 + a1), 1);
  g_snd[80 * a1 + 892] = 1;
  return result;
}

void __cdecl SND_StopStreamChannel(int index)
{
  char *v1; // ebx

  AIL_close_stream(dword_4A3C20[a1 - 30]);
  dword_4A3C20[a1 - 30] = 0;
  v1 = &g_snd[80 * a1];
  v1[892] = 0;
  *((_DWORD *)v1 + 207) = 0;
}

void __cdecl SND_Pause3DChannel(int index)
{
  void *result; // eax

  result = AIL_stop_3D_sample(*(&dword_4A3BA8 + a1));
  g_snd[80 * a1 + 892] = 1;
  return result;
}

void __cdecl SND_Stop3DChannel(int index)
{
  void *result; // eax
  char *v2;     // ebx

  result = AIL_end_3D_sample(*(&dword_4A3BA8 + a1));
  v2 = &g_snd[80 * a1];
  v2[892] = 0;
  *((_DWORD *)v2 + 207) = 0;
  return result;
}

void __cdecl SND_Pause2DChannel(int index)
{
  int result; // eax

  result = AIL_stop_sample(dword_4A3AD4[a1]);
  g_snd[80 * a1 + 892] = 1;
  return result;
}

void __cdecl SND_Stop2DChannel(int index)
{
  int result; // eax
  char *v2;   // ebx

  result = AIL_end_sample(dword_4A3AD4[a1]);
  v2 = &g_snd[80 * a1];
  v2[892] = 0;
  *((_DWORD *)v2 + 207) = 0;
  return result;
}

void __cdecl XA_ShutdownChannels(void)
{
  UNIMPLEMENTED();
}

void __cdecl SND_SetRoomtype(int roomtype)
{
  AIL_set_digital_master_room_type(milesGlob, a1);
  AIL_set_digital_master_reverb_levels();
  return AIL_set_3D_room_type(dword_4A3B84, a1);
}

void __cdecl SND_DriverPostUpdate(int frametime)
{
  unsigned int v0; // eax
  int v1;          // edx

    if (dword_4A3C5C) {
      AIL_set_sample_volume_levels(dword_4A3C5C, 0.5 * *(float *)&dword_FFD824,
                                   0.5 * *(float *)&dword_FFD824);
        if (byte_4A3C70[dword_4A3C98]) {
          v0 = AIL_sample_buffer_ready(dword_4A3C5C);
            if (v0 != -1) {
              *(double *)&qword_4A3CA0 =
                  (double)dword_4A3C90 * *(double *)&qword_4A3CA8 +
                  *(double *)&qword_4A3CA0;
              AIL_load_sample_buffer(
                  dword_4A3C5C, v0,
                  (const void *)(dword_4A3C6C + dword_4A3C98 * dword_4A3C90),
                  dword_4A3C90);
              v1 = dword_4A3C98;
              *((_BYTE *)&dword_4A3C60 + dword_4A3C98 + 16) = 0;
              dword_4A3C98 = (v1 + 1) % 32;
            }
        }
    }
}

void __cdecl SND_SetStreamChannelFromSaveInfo(int index,
                                              struct snd_save_stream_t *info)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = *(float *)&a2->pan;
  v3 = *(float *)&a2->volume * *(float *)&dword_FFD824;
    if (*(_DWORD *)&g_snd[80 * a1 + 852] != 2 ||
        SND_IsAliasChannel3D(
            (*(_DWORD *)(*(_DWORD *)&g_snd[80 * a1 + 856] + 44) & 0x780) >>
            7)) {
      AIL_set_stream_volume_levels((int)*(&dword_4A3BA8 + a1),
                                   v3 * (float)(1.0 - v2), v2 * v3);
    }
    else {
      AIL_set_stream_volume_levels((int)*(&dword_4A3BA8 + a1), v3, v3);
    }
}

void __cdecl SND_Set2DChannelFromSaveInfo(int index,
                                          struct snd_save_2D_sample_t *info)
{
  float v2; // xmm1_4

  v2 = *(float *)&a2->volume * *(float *)&dword_FFD824;
  if (*(_DWORD *)&g_snd[80 * a1 + 852] == 2)
    AIL_set_sample_volume_levels(dword_4A3AD4[a1], v2, v2);
  else
    AIL_set_sample_volume_levels(dword_4A3AD4[a1],
                                 v2 * (float)(1.0 - *(float *)&a2->pan),
                                 *(float *)&a2->pan * v2);
}

void __cdecl SND_UnpauseStreamChannel(int index, int timeshift)
{
  char *v2;   // ebx
  int result; // eax

  v2 = &g_snd[80 * a1];
  if (!*((_DWORD *)v2 + 207))
    AIL_pause_stream((int)*(&dword_4A3BA8 + a1), 0);
  result = a2;
  *((_DWORD *)v2 + 209) += a2;
  v2[892] = 0;
  return result;
}

void __cdecl SND_Unpause3DChannel(int index, int timeshift)
{
  char *v2;   // ebx
  int result; // eax

  v2 = &g_snd[80 * a1];
  if (!*((_DWORD *)v2 + 207))
    AIL_resume_3D_sample(*(&dword_4A3BA8 + a1));
  result = a2;
  *((_DWORD *)v2 + 209) += a2;
  v2[892] = 0;
  return result;
}

void __cdecl SND_Unpause2DChannel(int index, int timeshift)
{
  char *v2;   // ebx
  int result; // eax

  v2 = &g_snd[80 * a1];
  if (!*((_DWORD *)v2 + 207))
    AIL_resume_sample(dword_4A3AD4[a1]);
  result = a2;
  *((_DWORD *)v2 + 209) += a2;
  v2[892] = 0;
  return result;
}

void __cdecl SND_UpdateStreamChannel(int i, int frametime)
{
  char *result;                // eax
  char *v3;                    // esi
  int v4;                      // edi
  int v5;                      // eax
  float v6;                    // xmm1_4
  char *v7;                    // ecx
  int v8;                      // edx
  int v9;                      // eax
  float v10;                   // xmm2_4
  float v11;                   // xmm3_4
  float v12;                   // xmm4_4
  float LerpedSlavePercentage; // [esp+1Ch] [ebp-4Ch]
  float v14;                   // [esp+38h] [ebp-30h]
  int v15;                     // [esp+3Ch] [ebp-2Ch]
  int v16;                     // [esp+48h] [ebp-20h] BYREF
  float v17[7];                // [esp+4Ch] [ebp-1Ch] BYREF

  result = (char *)a1;
  v3 = &g_snd[80 * a1];
    if (!v3[892]) {
        if (a1 > 34 ||
            (result = (char *)SND_UpdateBackgroundVolume(a1 - 32, a2),
             (_BYTE)result)) {
          v4 = *((_DWORD *)v3 + 214);
          result = (char *)*((_DWORD *)v3 + 215);
            if (v4) {
                if (result) {
                  v17[0] = *((float *)v3 + 210);
                  v16 = 1056964608;
                    if (SND_IsAliasChannel3D((*(_DWORD *)(v4 + 44) & 0x780) >>
                                             7)) {
                      SND_GetCurrent3DPosition(*((_DWORD *)v3 + 205),
                                               (float *)&g_snd[80 * a1 + 880],
                                               (float *)&g_snd[80 * a1 + 868]);
                      v15 = a1 - 32;
                      MSS_SpatializeStream(a1 - 32, v17, (float *)&v16);
                        if (AIL_is_3D_stream(dword_4A3C28[a1 - 32])) {
                          v9 = 56 * SND_GetListenerIndexNearestToOrigin();
                          v10 = *(float *)&g_snd[80 * a1 + 868] -
                                *(float *)&g_snd[v9 + 756];
                          v11 = *(float *)&g_snd[80 * a1 + 872] -
                                *(float *)&g_snd[v9 + 760];
                          v12 = *(float *)&g_snd[80 * a1 + 876] -
                                *(float *)&g_snd[v9 + 764];
                          AIL_set_3D_stream_position(
                              dword_4A3C28[v15],
                              -(float)((float)((float)(v10 *
                                                       *(float *)&g_snd[v9 +
                                                                        780]) +
                                               (float)(v11 *
                                                       *(float *)&g_snd[v9 +
                                                                        784])) +
                                       (float)(v12 *
                                               *(float *)&g_snd[v9 + 788])),
                              (float)((float)(v10 *
                                              *(float *)&g_snd[v9 + 792]) +
                                      (float)(v11 *
                                              *(float *)&g_snd[v9 + 796])) +
                                  (float)(v12 * *(float *)&g_snd[v9 + 800]),
                              (float)((float)(v10 *
                                              *(float *)&g_snd[v9 + 768]) +
                                      (float)(v11 *
                                              *(float *)&g_snd[v9 + 772])) +
                                  (float)(v12 * *(float *)&g_snd[v9 + 776]));
                          v16 = 1056964608;
                        }
                    }
                    else {
                      v15 = a1 - 32;
                    }
                    if (*(float *)&dword_FFDA74 == 0.0 ||
                        g_snd[80 * a1 + 893]) {
                      v5 = *(_DWORD *)(v4 + 44);
                    }
                    else {
                      v5 = *(_DWORD *)(v4 + 44);
                        if ((v5 & 4) != 0) {
                          LerpedSlavePercentage =
                              SND_GetLerpedSlavePercentage(*(float *)(v4 + 48));
                          v17[0] = LerpedSlavePercentage * v17[0];
                          v5 = *(_DWORD *)(v4 + 44);
                        }
                    }
                  v17[0] = *(float *)(dword_FFDA54 + 12 * ((v5 & 0x780) >> 7)) *
                           v17[0];
                  v14 = *(float *)&v16;
                  v6 = v17[0] * *(float *)&dword_FFD824;
                    if (*(_DWORD *)&g_snd[80 * a1 + 852] != 2 ||
                        SND_IsAliasChannel3D(
                            (*(_DWORD *)(*(_DWORD *)&g_snd[80 * a1 + 856] +
                                         44) &
                             0x780) >>
                            7)) {
                      AIL_set_stream_volume_levels(
                          dword_4A3C28[v15], v6 * (float)(1.0 - v14), v14 * v6);
                    }
                    else {
                      AIL_set_stream_volume_levels(dword_4A3C28[v15], v6, v6);
                    }
                  result = &g_snd[80 * a1];
                  v7 = result + 816;
                  v8 = *((_DWORD *)result + 207);
                    if (v8) {
                      result = (char *)(v8 - a2);
                      if (a2 - v8 >= 0)
                        result = 0;
                      *((_DWORD *)v7 + 3) = result;
                      if (!result)
                        return (char *)AIL_pause_stream(dword_4A3C28[v15], 0);
                    }
                }
            }
        }
    }
  return result;
}

int __cdecl SND_StartAliasStreamOnChannel(
    struct snd_alias_t const *pAlias0, struct snd_alias_t const *pAlias1,
    float lerp, int entnum, float const *const org, float volume, float pitch,
    int timeshift, float fraction, int startDelay, bool master, int index,
    enum snd_alias_system_t system)
{
  const char *v13;             // eax
  char *v14;                   // eax
  CSoundObject *v15;           // edi
  uint32_t flags;              // ecx
  float v17;                   // xmm1_4
  float v18;                   // xmm0_4
  int32_t v19;                 // eax
  int v20;                     // esi
  int v21;                     // eax
  uint32_t v22;                // edx
  int v23;                     // eax
  int v24;                     // ebx
  const char *v26;             // ebx
  const char *SoundFileName;   // eax
  uint32_t v28;                // ecx
  float v29;                   // xmm2_4
  const char *error;           // eax
  int v31;                     // eax
  float v32;                   // xmm2_4
  float v33;                   // xmm3_4
  float v34;                   // xmm4_4
  char *v35;                   // [esp+64h] [ebp-154h]
  float v36;                   // [esp+68h] [ebp-150h]
  float v37;                   // [esp+6Ch] [ebp-14Ch]
  char v38;                    // [esp+73h] [ebp-145h]
  int v39;                     // [esp+74h] [ebp-144h]
  float LerpedSlavePercentage; // [esp+78h] [ebp-140h]
  float v41;                   // [esp+7Ch] [ebp-13Ch]
  int32_t v42;                 // [esp+80h] [ebp-138h]
  int v43;                     // [esp+84h] [ebp-134h]
  float *v44;                  // [esp+88h] [ebp-130h]
  char __big[256];             // [esp+94h] [ebp-124h] BYREF
  int v46;                     // [esp+194h] [ebp-24h] BYREF
  float v47;                   // [esp+198h] [ebp-20h] BYREF
  int v48[7];                  // [esp+19Ch] [ebp-1Ch] BYREF

  v38 = a11;
    if (!*(_BYTE *)(*(_DWORD *)a1->soundFile + 8)) {
      v26 = *(const char **)a1->pszAliasName;
      SoundFileName = (const char *)Com_GetSoundFileName(a1);
      Com_DPrintf(
          "Tried to play streamed sound '%s' from alias '%s', but it was "
          "not found at load time.\n",
          SoundFileName, v26);
      return 0;
    }
  v39 = a12 - 32;
    if (dword_4A3C28[a12 - 32]) {
      AIL_close_stream(dword_4A3C28[a12 - 32]);
      dword_4A3C20[v39 + 2] = 0;
    }
  v13 = (const char *)Com_GetSoundFileName(a1);
  sprintf(__big, "sound/%s", v13);
    if (!*(_BYTE *)(mss_q3fs + 8) ||
        (v15 = AIL_open_stream(milesGlob, __big)) == 0) {
      v14 = FS_ShortOSFilePath(__big);
      v15 = AIL_open_stream(milesGlob, v14);
        if (!v15) {
          error = AIL_last_error();
          Com_Printf("Couldn't play stream '%s' from alias '%s' - %s\n", __big,
                     *(const char **)a1->pszAliasName, error);
          return 0;
        }
    }
  dword_4A3C20[v39 + 2] = v15;
  AIL_stream_info((int)v15, 0, &v46, 0, 0);
  v43 = 2 - ((v46 & 2) == 0);
  v42 = AIL_stream_playback_rate((int)v15);
  v37 = floorf(
      (float)((float)((float)v42 * *(float *)&a7) * *(float *)&dword_FFD810) +
      0.5);
  AIL_set_stream_playback_rate((int)v15, (int)v37);
  flags = a1->flags;
  v17 = (float)(*(float *)&dword_FFD824 * *(float *)&a6) *
        *(float *)(dword_FFDA54 + 12 * ((int)(flags & 0x780) >> 7));
    if (*(float *)&dword_FFDA74 != 0.0 && !v38 && (flags & 4) != 0) {
      LerpedSlavePercentage =
          SND_GetLerpedSlavePercentage(*(float *)&a1->fSlavePercentage);
      v17 = v17 * LerpedSlavePercentage;
    }
  if (v43 == 1)
    v18 = 0.5;
  else
    v18 = 1.0;
  v47 = v18;
  AIL_set_stream_volume_levels((int)v15, v18 * v17, v18 * v17);
  AIL_set_stream_loop_count((int)v15, !(a1->flags & 1));
  if (*(_BYTE *)(snd_enableReverb + 8) && (a1->flags & 0x10) == 0)
    v19 = *(_DWORD *)(dword_FFDAD8 + 16);
  else
    v19 = 0;
  AIL_set_stream_reverb_levels((int)v15, 1065353216, v19);
  AIL_stream_ms_position((int)v15, (int)v48, 0);
  if (v48[0] <= a8)
    return 0;
    if (!v48[0]) {
      Com_Printf("^1ERROR: Sound file '%s' is zero length, invalid\n", __big);
      return 0;
    }
    if (a9 == 0.0) {
      v20 = a8;
    }
    else {
      a9 = (float)v48[0] * a9;
      v36 = floorf(a9 + 0.5);
      v20 = (int)v36;
    }
  v21 = 0;
  if (!v20)
    v21 = a10;
  a10 = v21;
  AIL_set_stream_ms_position((int)v15, v20);
    if (a10) {
      v22 = a1->flags;
    }
    else if (!byte_FFD802 ||
             (v22 = a1->flags, !g_snd[((int)(v22 & 0x780) >> 7) + 743])) {
      AIL_pause_stream((int)v15, 0);
      v22 = a1->flags;
    }
  v48[0] += a10;
  v23 = 0;
  if ((v22 & 1) == 0)
    v23 = v48[0];
  v48[0] = v23;
  v24 = 80 * a12;
  v35 = &g_snd[80 * a12 + 864];
  v44 = (float *)&g_snd[80 * a12 + 868];
  *v44 = *a5;
  v44[1] = a5[1];
  v44[2] = a5[2];
  SND_SetChannelInfo(a12, (unsigned int)a4, a1, a2, a3, a5, a6, a7, v43, v42,
                     v48[0], v20, a10, v38, a13);
  if (!SND_IsAliasChannel3D(
          (*(_DWORD *)(*(_DWORD *)&g_snd[v24 + 856] + 44) & 0x780) >> 7))
    return v48[0];
  MSS_SpatializeStream(v39, (float *)&a6, &v47);
    if (AIL_is_3D_stream((int)v15)) {
      v31 = 56 * SND_GetListenerIndexNearestToOrigin();
      v32 = *((float *)v35 + 1) - *(float *)&g_snd[v31 + 756];
      v33 = v44[1] - *(float *)&g_snd[v31 + 760];
      v34 = v44[2] - *(float *)&g_snd[v31 + 764];
      AIL_set_3D_stream_position(
          (int)v15,
          -(float)((float)((float)(v32 * *(float *)&g_snd[v31 + 780]) +
                           (float)(v33 * *(float *)&g_snd[v31 + 784])) +
                   (float)(v34 * *(float *)&g_snd[v31 + 788])),
          (float)((float)(v32 * *(float *)&g_snd[v31 + 792]) +
                  (float)(v33 * *(float *)&g_snd[v31 + 796])) +
              (float)(v34 * *(float *)&g_snd[v31 + 800]),
          (float)((float)(v32 * *(float *)&g_snd[v31 + 768]) +
                  (float)(v33 * *(float *)&g_snd[v31 + 772])) +
              (float)(v34 * *(float *)&g_snd[v31 + 776]));
      v47 = 0.5;
    }
  v28 = a1->flags;
  v29 = (float)(*(float *)&dword_FFD824 * *(float *)&a6) *
        *(float *)(dword_FFDA54 + 12 * ((int)(v28 & 0x780) >> 7));
    if (*(float *)&dword_FFDA74 != 0.0 && !v38 && (v28 & 4) != 0) {
      v41 = SND_GetLerpedSlavePercentage(*(float *)&a1->fSlavePercentage);
      v29 = v29 * v41;
    }
  AIL_set_stream_volume_levels((int)v15, v29 * (float)(1.0 - v47), v29 * v47);
  return v48[0];
}

int __cdecl SND_StartAlias3DSample(struct snd_alias_t const *pAlias0,
                                   struct snd_alias_t const *pAlias1,
                                   float lerp, int entnum,
                                   float const *const org, float volume,
                                   float pitch, int timeshift, float fraction,
                                   int startDelay, bool master, int *pChannel,
                                   enum snd_alias_system_t system)
{
  int Free3DChannel;                // eax
  void *v13;                        // esi
  int ListenerIndexNearestToOrigin; // eax
  int v15;                          // ecx
  float v16;                        // xmm1_4
  int32_t v17;                      // eax
  int v18;                          // eax
  float v19;                        // xmm1_4
  int v20;                          // ebx
  int v21;                          // edi
  int v22;                          // eax
  int v23;                          // edx
  float v24;                        // xmm0_4
  int v25;                          // edx
  int v27;                          // ebx
  int v28;                          // eax
  float v29;                        // [esp+4h] [ebp-A4h]
  float v30;                        // [esp+4Ch] [ebp-5Ch]
  float v31;                        // [esp+68h] [ebp-40h]
  float v32;                        // [esp+6Ch] [ebp-3Ch]
  float v33;                        // [esp+70h] [ebp-38h]
  float v34;                        // [esp+74h] [ebp-34h]
  float LerpedSlavePercentage;      // [esp+7Ch] [ebp-2Ch]
  int v36;                          // [esp+80h] [ebp-28h]
  _DWORD *SoundFileMem;             // [esp+84h] [ebp-24h]
  float v38;                        // [esp+88h] [ebp-20h]
  float v39;                        // [esp+8Ch] [ebp-1Ch]
  int v40;                          // [esp+D4h] [ebp+2Ch]

  Free3DChannel =
      SND_FindFree3DChannel(a3, (*(_DWORD *)(a1 + 44) & 0x780) >> 7);
  v36 = Free3DChannel;
  if (a11)
    *a11 = Free3DChannel;
  if (Free3DChannel < 0)
    return 0;
  v13 = *(&dword_4A3BA8 + Free3DChannel);
  SoundFileMem = (_DWORD *)Com_GetSoundFileMem((const snd_alias_t *)a1);
  v38 = (float)(*(float *)&a2 * *(float *)(HIDWORD(a1) + 36)) +
        (float)((float)(1.0 - *(float *)&a2) * *(float *)(a1 + 36));
  v39 = (float)(*(float *)&a2 * *(float *)(HIDWORD(a1) + 40)) +
        (float)((float)(1.0 - *(float *)&a2) * *(float *)(a1 + 40));
  AIL_set_3D_sample_info(v13, SoundFileMem);
  ListenerIndexNearestToOrigin = SND_GetListenerIndexNearestToOrigin();
  v29 = Vec3Distance(a4,
                     (float *)&g_snd[56 * ListenerIndexNearestToOrigin + 756]);
  v30 = SND_Attenuate((SndCurve *)*(_DWORD *)(a1 + 64), v29, v38, v39);
  v15 = *(_DWORD *)(a1 + 44);
  v16 = (float)((float)(v30 * *(float *)&a5) *
                *(float *)(dword_FFDA54 + 12 * ((v15 & 0x780) >> 7))) *
        *(float *)&dword_FFD824;
    if (*(float *)&dword_FFDA74 != 0.0 && !a10 && (v15 & 4) != 0) {
      LerpedSlavePercentage = SND_GetLerpedSlavePercentage(*(float *)(a1 + 48));
      v16 = v16 * LerpedSlavePercentage;
    }
  AIL_set_3D_sample_volume(v13, SLODWORD(v16));
  AIL_set_3D_sample_distances(v13, *(float *)(a1 + 40), *(float *)(a1 + 36));
  v17 = AIL_3D_sample_playback_rate(v13);
  v34 = floorf(
      (float)((float)((float)v17 * *(float *)&a6) * *(float *)&dword_FFD810) +
      0.5);
  AIL_set_3D_sample_playback_rate(v13, (int)v34);
  SND_Set3DPosition(v36, a4);
  AIL_set_3D_sample_loop_count(v13, !(*(_BYTE *)(a1 + 44) & 1));
  AIL_set_3D_sample_effects_level(v13, *(_DWORD *)(dword_FFDAD8 + 16));
  v18 = 1000 * SoundFileMem[6];
  v19 = v18 < 0
            ? (float)((unsigned int)v18 >> 1) + (float)((unsigned int)v18 >> 1)
            : (float)v18;
  v33 = floorf(
      (float)((float)(v19 * *(float *)&dword_FFD810) / (float)(int)v34) + 0.5);
  v20 = (int)v33;
  if ((int)v33 <= a7)
    return 0;
    if (a8 != 0.0) {
      v32 = floorf((float)((float)v20 * a8) + 0.5);
      v21 = (int)v32;
      v28 = 0;
      if (!(int)v32)
        v28 = a9;
      v40 = v28;
      v23 = SoundFileMem[2];
      if (v23 >= 0)
        goto LABEL_12;
    LABEL_28:
      v24 = (float)(v23 & 1 | ((unsigned int)v23 >> 1)) +
            (float)(v23 & 1 | ((unsigned int)v23 >> 1));
      goto LABEL_13;
    }
  v21 = a7;
  v22 = 0;
  if (!a7)
    v22 = a9;
  v40 = v22;
  v23 = SoundFileMem[2];
  if (v23 < 0)
    goto LABEL_28;
LABEL_12:
  v24 = (float)v23;
LABEL_13:
  v31 = floorf((float)(v24 * a8) + 0.5);
  AIL_set_3D_sample_offset(v13, (int)v31);
    if (v40) {
      v25 = *(_DWORD *)(a1 + 44);
    }
    else if (!byte_FFD802 ||
             (v25 = *(_DWORD *)(a1 + 44), !g_snd[((v25 & 0x780) >> 7) + 743])) {
      AIL_resume_3D_sample(v13);
      v25 = *(_DWORD *)(a1 + 44);
    }
  v27 = v40 + v20;
  if ((v25 & 1) != 0)
    v27 = 0;
  SND_SetChannelInfo(v36, a3, (const snd_alias_t *)a1,
                     (const snd_alias_t *)HIDWORD(a1), a2, a4, a5, a6,
                     SoundFileMem[5], SoundFileMem[3], v27, v21, v40, a10, a12);
  return v27;
}

int __cdecl SND_StartAlias2DSample(struct snd_alias_t const *pAlias0,
                                   struct snd_alias_t const *pAlias1,
                                   float lerp, int entnum, float volume,
                                   float pitch, int timeshift, float fraction,
                                   int startDelay, bool master, int *pChannel,
                                   enum snd_alias_system_t system)
{
  int Free2DChannel;           // eax
  int v13;                     // esi
  int SoundFileMem;            // edi
  int v15;                     // edx
  int v16;                     // eax
  int32_t v17;                 // ecx
  int v18;                     // edx
  float v19;                   // xmm0_4
  uint32_t flags;              // ecx
  float v21;                   // xmm1_4
  float v22;                   // xmm0_4
  int32_t v23;                 // eax
  int v24;                     // ebx
  int v25;                     // eax
  uint32_t v26;                // ecx
  int v27;                     // edx
  float v29;                   // [esp+5Ch] [ebp-3Ch]
  float v30;                   // [esp+60h] [ebp-38h]
  float LerpedSlavePercentage; // [esp+68h] [ebp-30h]
  int v32;                     // [esp+6Ch] [ebp-2Ch]
  int v33[7];                  // [esp+7Ch] [ebp-1Ch] BYREF
  int v34;                     // [esp+C0h] [ebp+28h]

  Free2DChannel =
      SND_FindFree2DChannel(a4, (signed int)(a1->flags & 0x780) >> 7);
  v32 = Free2DChannel;
  if (a11)
    *a11 = Free2DChannel;
  if (Free2DChannel < 0)
    return 0;
  v13 = dword_4A3AD4[Free2DChannel];
  SoundFileMem = Com_GetSoundFileMem(a1);
  AIL_init_sample(v13);
  v15 = *(_DWORD *)(SoundFileMem + 16);
  v16 = *(_DWORD *)SoundFileMem;
    if (*(_DWORD *)(SoundFileMem + 20) == 1) {
        if (v16 == 17) {
          v17 = 5;
        }
        else if (v15 > 8) {
          v17 = 1;
          if (v15 > 16)
            v17 = 8;
        }
        else {
          v17 = 0;
        }
    }
    else if (v16 == 17) {
      v17 = 7;
    }
    else if (v15 > 8) {
      v17 = 3;
      if (v15 > 16)
        v17 = 10;
    }
    else {
      v17 = 2;
    }
  AIL_set_sample_type(v13, v17);
  AIL_set_sample_address(v13, *(const void **)(SoundFileMem + 4),
                         *(_DWORD *)(SoundFileMem + 8));
  AIL_set_sample_adpcm_block_size(v13, *(_DWORD *)(SoundFileMem + 28));
  v18 = *(_DWORD *)(SoundFileMem + 12);
  if (v18 < 0)
    v19 = (float)(*(_DWORD *)(SoundFileMem + 12) & 1u |
                  (*(_DWORD *)(SoundFileMem + 12) >> 1)) +
          (float)(*(_DWORD *)(SoundFileMem + 12) & 1u |
                  (*(_DWORD *)(SoundFileMem + 12) >> 1));
  else
    v19 = (float)v18;
  v30 = floorf((float)((float)(v19 * *(float *)&a6) * *(float *)&dword_FFD810) +
               0.5);
  AIL_set_sample_playback_rate(v13, (int)v30);
  flags = a1->flags;
  v21 = (float)(*(float *)&a5 * *(float *)&dword_FFD824) *
        *(float *)(dword_FFDA54 + 12 * ((int)(flags & 0x780) >> 7));
    if (*(float *)&dword_FFDA74 != 0.0 && !a10 && (flags & 4) != 0) {
      LerpedSlavePercentage =
          SND_GetLerpedSlavePercentage(*(float *)&a1->fSlavePercentage);
      v21 = v21 * LerpedSlavePercentage;
    }
  v22 = *(_DWORD *)(SoundFileMem + 20) == 1 ? 0.5 : 1.0;
  AIL_set_sample_volume_levels(v13, v22 * v21, v22 * v21);
  AIL_set_sample_loop_count(v13, !(a1->flags & 1));
  if (!*(_BYTE *)(snd_enableReverb + 8) || (a1->flags & 0x10) != 0)
    v23 = 0;
  else
    v23 = *(_DWORD *)(dword_FFDAD8 + 16);
  AIL_set_sample_reverb_levels(v13, 1065353216, v23);
  AIL_sample_ms_position(v13, (int)v33, 0);
  if (v33[0] <= a7)
    return 0;
    if (a8 == 0.0) {
      v24 = a7;
    }
    else {
      v29 = floorf((float)((float)v33[0] * a8) + 0.5);
      v24 = (int)v29;
    }
  v25 = 0;
  if (!v24)
    v25 = a9;
  v34 = v25;
  AIL_set_sample_ms_position(v13, v24);
    if (v34) {
      v26 = a1->flags;
    }
    else if (!byte_FFD802 ||
             (v26 = a1->flags, !g_snd[((int)(v26 & 0x780) >> 7) + 743])) {
      AIL_resume_sample(v13);
      v26 = a1->flags;
    }
  v27 = v33[0] + v34;
  v33[0] += v34;
    if ((v26 & 1) != 0) {
      v27 = 0;
      v33[0] = 0;
    }
  SND_SetChannelInfo(v32, a4, a1, a2, a3, 0, a5, a6,
                     *(_DWORD *)(SoundFileMem + 20),
                     *(_DWORD *)(SoundFileMem + 12), v27, v24, v34, a10, a12);
  return v33[0];
}

void __cdecl SND_Update3DChannel(int i, int frametime)
{
  char *v2;                         // ecx
  int result;                       // eax
  int v4;                           // edi
  int v5;                           // esi
  int ListenerIndexNearestToOrigin; // eax
  int v7;                           // eax
  float v8;                         // xmm1_4
  int v9;                           // edx
  float v10;                        // [esp+4h] [ebp-54h]
  char *v11;                        // [esp+18h] [ebp-40h]
  float v12;                        // [esp+1Ch] [ebp-3Ch]
  float LerpedSlavePercentage;      // [esp+20h] [ebp-38h]
  float v14;                        // [esp+24h] [ebp-34h]
  float v15;                        // [esp+28h] [ebp-30h]
  float v16;                        // [esp+28h] [ebp-30h]
  float v17;                        // [esp+2Ch] [ebp-2Ch]
  float v18;                        // [esp+2Ch] [ebp-2Ch]
  float v19[9];                     // [esp+34h] [ebp-24h] BYREF

  v2 = &g_snd[80 * a1];
  result = (int)(v2 + 880);
  v11 = v2 + 880;
  if (v2[892])
    return result;
  result = (int)(v2 + 848);
  v4 = *((_DWORD *)v2 + 214);
  v5 = *((_DWORD *)v2 + 215);
  if (!v4 || !v5)
    return result;
  v15 = *((float *)v2 + 216);
  v17 = *((float *)v2 + 210);
  SND_GetCurrent3DPosition(*((_DWORD *)v2 + 205),
                           (float *)&g_snd[80 * a1 + 880], v19);
  SND_Set3DPosition(a1, v19);
  v14 = (float)(v15 * *(float *)(v5 + 36)) +
        (float)((float)(1.0 - v15) * *(float *)(v4 + 36));
  v16 = (float)((float)(1.0 - v15) * *(float *)(v4 + 40)) +
        (float)(v15 * *(float *)(v5 + 40));
  ListenerIndexNearestToOrigin = SND_GetListenerIndexNearestToOrigin();
  v10 = Vec3Distance(v19,
                     (float *)&g_snd[56 * ListenerIndexNearestToOrigin + 756]);
  v12 = SND_Attenuate((SndCurve *)*(_DWORD *)(v4 + 64), v10, v14, v16);
  v18 = v17 * v12;
    if (*(float *)&dword_FFDA74 == 0.0 || v11[13]) {
      v7 = *(_DWORD *)(v4 + 44);
    LABEL_7:
      v8 = v18;
      goto LABEL_8;
    }
  v7 = *(_DWORD *)(v4 + 44);
  if ((v7 & 4) == 0)
    goto LABEL_7;
  LerpedSlavePercentage = SND_GetLerpedSlavePercentage(*(float *)(v4 + 48));
  v7 = *(_DWORD *)(v4 + 44);
  v8 = v18 * LerpedSlavePercentage;
LABEL_8:
  AIL_set_3D_sample_volume(
      *(&dword_4A3BA8 + a1),
      COERCE_INT32_T(
          (float)(v8 * *(float *)(dword_FFDA54 + 12 * ((v7 & 0x780) >> 7))) *
          *(float *)&dword_FFD824));
  result = 80 * a1;
  v9 = *(_DWORD *)&g_snd[80 * a1 + 828];
    if (v9) {
      result = v9 - a2;
      if (a2 - v9 >= 0)
        result = 0;
      *(_DWORD *)&g_snd[80 * a1 + 828] = result;
      if (!result)
        return (int)AIL_resume_3D_sample(*(&dword_4A3BA8 + a1));
    }
  return result;
}

void __cdecl SND_Update2DChannel(int i, int frametime)
{
  int result;                  // eax
  char *v3;                    // edx
  int v4;                      // esi
  int v5;                      // eax
  float v6;                    // xmm0_4
  float v7;                    // xmm0_4
  int v8;                      // ecx
  int v9;                      // edx
  float LerpedSlavePercentage; // [esp+18h] [ebp-20h]
  float v11;                   // [esp+1Ch] [ebp-1Ch]

  result = 80 * a1;
  v3 = &g_snd[80 * a1];
  if (v3[892])
    return result;
  v4 = *((_DWORD *)v3 + 214);
  result = *((_DWORD *)v3 + 215);
  if (!v4 || !result)
    return result;
  v11 = *((float *)v3 + 210);
    if (*(float *)&dword_FFDA74 == 0.0 || v3[893]) {
      v5 = *(_DWORD *)(v4 + 44);
    }
    else {
      v5 = *(_DWORD *)(v4 + 44);
        if ((v5 & 4) != 0) {
          LerpedSlavePercentage =
              SND_GetLerpedSlavePercentage(*(float *)(v4 + 48));
          v6 = v11 * LerpedSlavePercentage;
          v5 = *(_DWORD *)(v4 + 44);
          goto LABEL_7;
        }
    }
  v6 = *((float *)v3 + 210);
LABEL_7:
  v7 = (float)(v6 * *(float *)(dword_FFDA54 + 12 * ((v5 & 0x780) >> 7))) *
       *(float *)&dword_FFD824;
  if (*(_DWORD *)&g_snd[80 * a1 + 852] != 2)
    v7 = v7 * 0.5;
  AIL_set_sample_volume_levels(dword_4A3AD4[a1], v7, v7);
  result = (int)&g_snd[80 * a1];
  v8 = result + 816;
  v9 = *(_DWORD *)(result + 828);
    if (v9) {
      result = v9 - a2;
      if (a2 - v9 >= 0)
        result = 0;
      *(_DWORD *)(v8 + 12) = result;
      if (!result)
        return AIL_resume_sample(dword_4A3AD4[a1]);
    }
  return result;
}

void __cdecl SND_ShutdownDriver()
{
  UNIMPLEMENTED();
}

void __cdecl XA_SndStreamReadThread(void)
{
  UNIMPLEMENTED();
}

bool __cdecl SND_InitDriver()
{
  UNIMPLEMENTED();
}

struct dvar_s const *const snd_omnidirectionalPercentage;
struct dvar_s const *const snd_speakerConfiguration;

unsigned int __cdecl SND_HashForName(char const *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_ApplyOmnidirectionality(float **)
{
  UNIMPLEMENTED();
}

void __cdecl XA_InitSpatializationCurves(void)
{
  UNIMPLEMENTED();
}

void __cdecl XA_OverlappedFileReadCompletion(unsigned long, unsigned long,
                                             struct _OVERLAPPED *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_FreeStreamPacket(struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_RemoveFromFreeList(struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_MoveToFreeTail(struct XaCacheEntry *, struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_MoveToFreeHead(struct XaCacheEntry *, struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

unsigned char *__cdecl XA_GetCacheEntryBuffer(struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_CloseStreamFile(struct XaStreamReadInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_CleanFilename(char *)
{
  UNIMPLEMENTED();
}

float __cdecl XA_GetWetLevel(struct snd_alias_t const *)
{
  UNIMPLEMENTED();
}

float __cdecl XA_GetDryLevel(struct snd_alias_t const *)
{
  UNIMPLEMENTED();
}

int __cdecl XA_CalcTotalSamples(int, int)
{
  UNIMPLEMENTED();
}

unsigned long __cdecl XA_GetSampleIndexFromMsec(int, int)
{
  UNIMPLEMENTED();
}

unsigned char __cdecl XA_GetSpeakerCount(void)
{
  UNIMPLEMENTED();
}

bool __cdecl XA_Init3D(void)
{
  UNIMPLEMENTED();
}

void __cdecl XA_ReleaseStreamPacket(struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_TouchEntry(struct XaCacheEntry *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_InitVoiceOutputAndBaseVolumesForReverb(
    int, int, bool, struct XAUDIOCHANNELMAP *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_51_SpecificVolumeCoefficientAdjustments(float)
{
  UNIMPLEMENTED();
}

void __cdecl XA_SetSpatializationCurves(int)
{
  UNIMPLEMENTED();
}

void __cdecl XA_UpdateXAudioListener(float const *const)
{
  UNIMPLEMENTED();
}

void __cdecl XA_StreamPacketCallback(struct XAUDIOVOICEPACKETCALLBACK *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_SetStreamPacket(struct XaStreamReadInfo *, int, unsigned char *,
                                int)
{
  UNIMPLEMENTED();
}

struct XaCacheEntry *__cdecl XA_GetStreamPacket(struct XaStreamReadInfo *, int)
{
  UNIMPLEMENTED();
}

float __cdecl XA_CalcXAudioPitch(int, unsigned long)
{
  UNIMPLEMENTED();
}

void __cdecl XA_InitSpatializationParams(void)
{
  UNIMPLEMENTED();
}

void __cdecl XA_SetStreamPacketPosition(struct IXAudioSourceVoice *,
                                        struct XaStreamReadInfo *,
                                        struct XAUDIOPACKET *)
{
  UNIMPLEMENTED();
}

bool __cdecl XA_SubmitStreamPacket(struct IXAudioSourceVoice *,
                                   struct XaStreamReadInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_SpatializeStreamChannel(int)
{
  UNIMPLEMENTED();
}

void __cdecl XA_Spatialize3DChannel(int)
{
  UNIMPLEMENTED();
}

bool __cdecl XA_Init2D(void)
{
  UNIMPLEMENTED();
}

void __cdecl XA_ReadStreamPacketData(struct XaStreamReadInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_ExecuteStreamRead(struct XaStreamReadInfo *)
{
  UNIMPLEMENTED();
}

void __cdecl XA_InitChannels(void)
{
  UNIMPLEMENTED();
}

SND_LoadSoundFile(SoundFile *soundFile)
{
  UNIMPLEMENTED();
}
