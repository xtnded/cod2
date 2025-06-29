void __cdecl StatMon_Reset()
{
  int result; // eax

  result = 0;
  memset(&stats, 0, 0x38u);
  statCount = 0;
  return result;
}

void __cdecl StatMon_GetStatsArray(struct statmonitor_s const **array,
                                   int *count)
{
  int *result; // eax

  *a1 = (const statmonitor_s *)&stats;
  result = a2;
  *a2 = statCount;
  return result;
}

void __cdecl StatMon_Warning(int type, int duration, char const *materialName)
{
  int result; // eax

  result = com_statmon;
    if (*(_BYTE *)(com_statmon + 8)) {
        if (a1 > 6) {
          Com_Error(1, "\x15StatMon_UpdateEntry: invalid entry '%i'\n", a1);
          result = a2 + Sys_Milliseconds();
          stats[2 * a1] = result;
            if (dword_4ED7A4[2 * a1]) {
            LABEL_4:
                if ((int)a1 >= statCount) {
                  result = a1 + 1;
                  statCount = a1 + 1;
                }
              return result;
            }
        }
        else {
          result = a2 + Sys_Milliseconds();
          stats[2 * a1] = result;
          if (dword_4ED7A4[2 * a1])
            goto LABEL_4;
        }
      result = dword_1220A68;
        if (dword_1220A68) {
          result = dword_121C6B0(a3, 48, 1);
          stats[2 * a1 + 1] = result;
        }
      goto LABEL_4;
    }
  return result;
}

int marker_statmonitor;
