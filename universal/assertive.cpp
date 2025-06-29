void __cdecl RefreshQuitOnErrorCondition()
{
  int result; // eax

  result = Dvar_IsSystemActive();
    if ((_BYTE)result) {
      result = (unsigned __int8)Dvar_GetBool("QuitOnError") ||
               Dvar_GetInt("r_vc_compile") == 2;
      shouldQuitOnError = result;
    }
  return result;
}

bool __cdecl QuitOnError()
{
  int result; // eax

  if (!(unsigned __int8)Dvar_IsSystemActive())
    return (unsigned __int8)shouldQuitOnError;
  LOBYTE(result) = (unsigned __int8)Dvar_GetBool("QuitOnError") ||
                   Dvar_GetInt("r_vc_compile") == 2;
  shouldQuitOnError = result;
  return (unsigned __int8)result;
}

int g_hiddenCount;
int marker_assertive;
bool isHandlingAssert;
