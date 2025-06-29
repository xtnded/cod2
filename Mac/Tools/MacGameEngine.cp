void __cdecl CMacGameEngine::CMacGameEngine(CMacGameEngine *this) {
  this->_vptr$CMacGameEngine = off_32FD68;
  this->mArgc = 0;
  this->mArgv = 0;
  this->mAppHandlerRef = 0;
  this->mWindowHandlerRef = 0;
  this->mFakeRightButtonDown = 0;
  this->mLastModifierSet = 0;
  this->mIsQuitting = 0;
  this->mIsRunning = 0;
  this->mWheelEventPosted = 0;
  GetMainEventQueue();
}
void __cdecl CMacGameEngine::~CMacGameEngine(CMacGameEngine *this) {
  this->_vptr$CMacGameEngine = off_32FD68;
  if (this->mAppHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mAppHandlerRef);
  if (this->mWindowHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mWindowHandlerRef);
}
// 32FD68: using guessed type void (__cdecl *off_32FD68[2])(CMacGameEngine
// *__hidden this);

//----- (00026454) --------------------------------------------------------
void __cdecl CMacGameEngine::~CMacGameEngine(CMacGameEngine *this) {
  this->_vptr$CMacGameEngine = off_32FD68;
  if (this->mAppHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mAppHandlerRef);
  if (this->mWindowHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mWindowHandlerRef);
}
// 32FD68: using guessed type void (__cdecl *off_32FD68[2])(CMacGameEngine
// *__hidden this);

//----- (00026488) --------------------------------------------------------
void __cdecl CMacGameEngine::~CMacGameEngine(CMacGameEngine *this) {
  this->_vptr$CMacGameEngine = off_32FD68;
  if (this->mAppHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mAppHandlerRef);
  if (this->mWindowHandlerRef)
    RemoveEventHandler((EventHandlerRef)this->mWindowHandlerRef);
  operator delete(this);
}

char __cdecl CMacGameEngine::Run(CMacGameEngine *this, int32_t a2, char **a3) {
  int v3;                              // eax
  OpaqueEventQueueRef *MainEventQueue; // eax

  this->mArgc = a2;
  this->mArgv = (int32_t)a3;
  if (!(*((unsigned __int8(__cdecl **)(
              CMacGameEngine *))this->_vptr$CMacGameEngine +
          2))(this))
    goto LABEL_4;
  v3 = MacDisplay::Initialize();
  if (!v3) {
    MacPreferences::Synchronize();
    MainEventQueue = GetMainEventQueue();
    FlushEventQueue(MainEventQueue);
    (*((void(__cdecl **)(CMacGameEngine *))this->_vptr$CMacGameEngine + 3))(
        this);
  LABEL_4:
    LOBYTE(v3) = MacPreferences::Synchronize();
  }
  return v3;
}

int __cdecl CMacGameEngine::ProcessAllEvents(CMacGameEngine *this) {
  CMacGameEngine *MacGameEngine; // esi
  EventRef inEvent;              // [esp+2Ch] [ebp-Ch] BYREF

  MacGameEngine = GetMacGameEngine();
  MacGameEngine->mWheelEventPosted = 0;
  while (!ReceiveNextEvent(0, 0, 0.0, 1u, &inEvent)) {
    SendEventToEventTarget(inEvent, sEventTargetRef);
    ReleaseEvent(inEvent);
  }
  return (unsigned __int8)MacGameEngine->mIsQuitting;
}
CMacGameEngine *__cdecl CMacGameEngine::Quit(CMacGameEngine *this) {
  CMacGameEngine *result; // eax

  result = GetMacGameEngine();
  if (result->mIsRunning) {
    result = GetMacGameEngine();
    result->mIsQuitting = 1;
  }
  return result;
}


//----- (00026638) --------------------------------------------------------
void __cdecl CMacGameEngine::DrawSplashScreen(CMacGameEngine *this) {
  const __CFURL *v1;  // eax
  const __CFURL *v2;  // esi
  CGDataProvider *v3; // eax
  CGDataProvider *v4; // edi
  CGrafPtr MainPort;  // eax
  CGrafPtr v6;        // eax
  CGRect v7;          // [esp+4h] [ebp-C4h]
  CGRect v8;          // [esp+4h] [ebp-C4h]
  CGImage *image;     // [esp+24h] [ebp-A4h]
  int32_t v10;        // [esp+28h] [ebp-A0h]
  uint32_t v11;       // [esp+2Ch] [ebp-9Ch]
  FSRef fsRef;        // [esp+34h] [ebp-94h] BYREF
  CGRect rect;        // [esp+84h] [ebp-44h]
  CGRect v14;         // [esp+94h] [ebp-34h]
  CGContextRef c;     // [esp+A4h] [ebp-24h] BYREF
  int v16;            // [esp+A8h] [ebp-20h] BYREF
  int v17[7];         // [esp+ACh] [ebp-1Ch] BYREF

  if (!MacFolders::GetDataFolderItemRef((MacFolders *)this, &fsRef)) {
    v1 = CFURLCreateFromFSRef(0, &fsRef);
    v2 = v1;
    if (v1) {
      v3 = CGDataProviderCreateWithURL(v1);
      v4 = v3;
      if (v3) {
        image = CGImageCreateWithPNGDataProvider(v3, 0, 1,
                                                 kCGRenderingIntentDefault);
        if (image) {
          MacDisplay::GetCurrentDimensions((MacDisplay *)v17, &v16);
          MainPort = MacDisplay::GetMainPort();
          if (!QDBeginCGContext(MainPort, &c)) {
            *(float *)&v10 = (float)v16;
            *(float *)&v11 = (float)v17[0];
            *(float *)&rect.size.height = (float)v16;
            *(float *)&rect.size.width = (float)v17[0];
            rect.origin.y = 0;
            rect.origin.x = 0;
            v7.origin = 0;
            *(float *)&v7.size.width = (float)v17[0];
            *(float *)&v7.size.height = (float)v16;
            CGContextClearRect(c, v7);
            v14.size.height = v10;
            v14.size.width = v11;
            v14.origin.y = 0;
            v14.origin.x = 0;
            v8.origin = 0;
            v8.size = (CGSize)__PAIR64__(v10, v11);
            CGContextDrawImage(c, v8, image);
            CGContextFlush(c);
            v6 = MacDisplay::GetMainPort();
            QDEndCGContext(v6, &c);
          }
          CGImageRelease(image);
        }
        CGDataProviderRelease(v4);
      }
      CFRelease(v2);
    }
  }
}


//----- (000267E2) --------------------------------------------------------
int __cdecl CMacGameEngine::Initialize(CMacGameEngine *this) {
  const __CFString *NeedsNewerOSError;      // eax
  signed __int64 v3;                        // rcx
  FSVolumeRefNum ApplicationVRefNum;        // ax
  const __CFString *MissingDataFolderError; // eax
  const __CFString *NoQuickTimeError;       // eax
  const __CFString *InsertDiscError;        // eax
  const __CFString *DiscName;               // eax
  const __CFString *CantRunFromDiscError;   // eax
  rlimit v10;                               // [esp+2Ch] [ebp-4ACh] BYREF
  FSVolumeInfo info;                        // [esp+42Eh] [ebp-AAh] BYREF
  int v12[5];                               // [esp+4ACh] [ebp-2Ch] BYREF
  EventRecord theEvent;                     // [esp+4C0h] [ebp-18h] BYREF

  EventAvail(0, &theEvent);
  if (!strcmp((const char *)kBuildTag, kProductTag))
    return 0;
  if ((__int16)MacFeatures::GetSystemVersion() > 4152) {
    if (!getrlimit(3, &v10)) {
      v3 = 3 * v10.rlim_cur;
      v10.rlim_cur *= 3LL;
      if (v3 > (__int64)v10.rlim_max)
        v10.rlim_cur = v10.rlim_max;
      setrlimit(3, &v10);
    }
    if ((unsigned __int16)EnterMovies()) {
      NoQuickTimeError = MacResources::GetNoQuickTimeError();
      MacTools::MessageAlert(NoQuickTimeError, (const __CFString *)1);
      return 0;
    } else {
      ApplicationVRefNum = MacFolders::GetApplicationVRefNum();
      if (FSGetVolumeInfo(ApplicationVRefNum, 0, 0, 0x2000u, &info, 0, 0) ||
          SLOBYTE(info.flags) >= 0 && info.flags >= 0) {
        if (MacFolders::GetDataFolderID()) {
          while (1) {
            DiscName = MacResources::GetDiscName();
            if ((unsigned __int16)MacTools::FindDiscVolume(DiscName,
                                                           (__CFString *)&v10))
              break;
            InsertDiscError =
                (const __CFString *)MacResources::GetInsertDiscError();
            if (!MacTools::QuestionAlert(InsertDiscError, 0))
              return 0;
            MacTools::SetCursorID((MacTools *)4);
          }
          v12[0] = 20;
          GetCompressionInfo(0, 1313820229, 2, 16, v12);
          MacTools::SetCursorID((MacTools *)4);
          return 1;
        } else {
          MissingDataFolderError =
              (const __CFString *)MacResources::GetMissingDataFolderError();
          MacTools::MessageAlert(MissingDataFolderError, (const __CFString *)1);
          return 0;
        }
      } else {
        CantRunFromDiscError =
            (const __CFString *)MacResources::GetCantRunFromDiscError();
        MacTools::MessageAlert(CantRunFromDiscError, (const __CFString *)1);
        return 0;
      }
    }
  } else {
    NeedsNewerOSError =
        (const __CFString *)MacResources::GetNeedsNewerOSError();
    MacTools::MessageAlert(NeedsNewerOSError, (const __CFString *)1);
    return 0;
  }
}

void __cdecl CMacGameEngine::MacMain(CMacGameEngine *this) {
  OpaqueEventLoopRef *MainEventLoop; // eax
  EventLoopTimerRef outTimer;        // [esp+2Ch] [ebp-Ch] BYREF

  MainEventLoop = GetMainEventLoop();
  InstallEventLoopTimer(MainEventLoop, 0.0, 0.0,
                        (EventLoopTimerUPP)CMacGameEngine::OneShotTimerProc,
                        this, &outTimer);
  RunApplicationEventLoop();
  MacDisplay::ReleaseDisplay();
}

CMacGameEngine *__cdecl CMacGameEngine::SetIsRunning(CMacGameEngine *this,
                                                     int8_t a2) {
  CMacGameEngine *result; // eax

  result = this;
  this->mIsRunning = a2;
  return result;
}
//----- (00026A74) --------------------------------------------------------
void __cdecl CMacGameEngine::DoMouseDown(CMacGameEngine *this) { ; }

//----- (00026A7A) --------------------------------------------------------
void __cdecl CMacGameEngine::DoMouseUp(CMacGameEngine *this) { ; }

//----- (00026A80) --------------------------------------------------------
void __cdecl CMacGameEngine::DoMouseMoved(CMacGameEngine *this) { ; }

//----- (00026A86) --------------------------------------------------------
void __cdecl CMacGameEngine::DoMouseWheel(CMacGameEngine *this) { ; }

//----- (00026A8C) --------------------------------------------------------
void __cdecl CMacGameEngine::DoKeyDown(CMacGameEngine *this) { ; }

//----- (00026A92) --------------------------------------------------------
void __cdecl CMacGameEngine::DoKeyUp(CMacGameEngine *this) { ; }

//----- (00026A98) --------------------------------------------------------
void __cdecl CMacGameEngine::DoTextInput(CMacGameEngine *this) { ; }

//----- (00026A9E) --------------------------------------------------------
int __cdecl CMacGameEngine::IsQuitAvailable(CMacGameEngine *this) { return 1; }

int __cdecl CMacGameEngine::DoQuit(CMacGameEngine *this) {
  int result; // eax

  result = (*((int(__cdecl **)(CMacGameEngine *))this->_vptr$CMacGameEngine +
              13))(this);
  if ((_BYTE)result)
    this->mIsQuitting = 1;
  return result;
}
unsigned int __cdecl CMacGameEngine::HandleEventProc(EventHandlerCallRef a1,
                                                     EventRef a2, void *a3) {
  return (*(unsigned __int8(__cdecl **)(void *, EventRef))(*(_DWORD *)a3 + 20))(
             a3, a2) == 0
             ? 0xFFFFD96E
             : 0;
}
int __cdecl CMacGameEngine::HandleAppleEvent(const AppleEvent *a1,
                                             AppleEvent *a2, SRefCon a3) {
  if (!a3)
    return -1708;
  if (!(*(unsigned __int8(__cdecl **)(SRefCon))(*(_DWORD *)a3 + 52))(a3))
    return -128;
  (*(void(__cdecl **)(SRefCon))(*(_DWORD *)a3 + 56))(a3);
  return 0;
}
OSErr __cdecl CMacGameEngine::InstallEventHandlers(CMacGameEngine *this) {
  OpaqueEventTargetRef *ApplicationEventTarget; // eax
  OSStatus v2;                                  // ebx
  OpaqueWindowPtr *MainWindow;                  // eax
  OpaqueEventTargetRef *WindowEventTarget;      // eax
  OpaqueMenuRef *MenuHandle;                    // ebx
  OpaqueEventTargetRef *v6;                     // eax
  OpaqueEventTargetRef *MenuEventTarget;        // eax
  _DWORD *exception;                            // eax
  EventTypeSpec __dst[13];                      // [esp+20h] [ebp-88h] BYREF
  MenuRef outMenu;                              // [esp+88h] [ebp-20h] BYREF
  MenuItemIndex outNewItem[13];                 // [esp+8Eh] [ebp-1Ah] BYREF

  sEventTargetRef = GetEventDispatcherTarget();
  if ((unsigned __int8)MacDisplay::IsWindowMode()) {
    memcpy(__dst, &CMacGameEngine::InstallEventHandlers(void)::C .133,
           sizeof(__dst));
    ApplicationEventTarget = GetApplicationEventTarget();
    v2 = InstallEventHandler(ApplicationEventTarget,
                             (EventHandlerUPP)CMacGameEngine::HandleEventProc,
                             0xDu, __dst, this,
                             (EventHandlerRef *)&this->mAppHandlerRef);
    if (!v2) {
      __dst[0].eventClass = 1836021107;
      __dst[0].eventKind = 1;
      __dst[1].eventClass = 1836021107;
      __dst[1].eventKind = 2;
      __dst[2].eventClass = 1801812322;
      __dst[2].eventKind = 1;
      __dst[3].eventClass = 1801812322;
      __dst[3].eventKind = 2;
      __dst[4].eventClass = 1801812322;
      __dst[4].eventKind = 3;
      __dst[5].eventClass = 1801812322;
      __dst[5].eventKind = 4;
      __dst[6].eventClass = 1952807028;
      __dst[6].eventKind = 2;
      __dst[7].eventClass = 2003398244;
      __dst[7].eventKind = 72;
      MainWindow = MacDisplay::GetMainWindow();
      WindowEventTarget = GetWindowEventTarget(MainWindow);
      v2 = InstallEventHandler(
          WindowEventTarget, (EventHandlerUPP)CMacGameEngine::HandleEventProc,
          8u, __dst, this, (EventHandlerRef *)&this->mWindowHandlerRef);
      if (!v2) {
        MenuHandle = GetMenuHandle(128);
        if (MenuHandle &&
            !AppendMenuItemTextWithCFString(MenuHandle, CFSTR("toggle"),
                                            0x1020u, 0x546F676Cu, outNewItem)) {
          SetItemCmd(MenuHandle, outNewItem[0], 84);
        }
        return AEInstallEventHandler(
            0x61657674u, 0x71756974u,
            (AEEventHandlerUPP)CMacGameEngine::HandleAppleEvent, (SRefCon)this,
            0);
      }
    }
  LABEL_11:
    exception = __cxa_allocate_exception(4u);
    *exception = v2;
    __cxa_throw(exception, (struct type_info *)&`typeinfo for'long, 0);
  }
  memcpy(__dst, &CMacGameEngine::InstallEventHandlers(void)::C .135,
         sizeof(__dst));
  v6 = GetApplicationEventTarget();
  v2 = InstallEventHandler(v6, (EventHandlerUPP)CMacGameEngine::HandleEventProc,
                           0xDu, __dst, this,
                           (EventHandlerRef *)&this->mAppHandlerRef);
  if (v2)
    goto LABEL_11;
  if (!GetIndMenuItemWithCommandID(0, 0x68696465u, 1u, &outMenu, outNewItem)) {
    __dst[0].eventClass = 1668113523;
    __dst[0].eventKind = 1;
    MenuEventTarget = GetMenuEventTarget(outMenu);
    InstallEventHandler(
        MenuEventTarget, (EventHandlerUPP)CMacGameEngine::HandleEventProc, 1u,
        __dst, this, (EventHandlerRef *)&this->mWindowHandlerRef);
  }
  return AEInstallEventHandler(
      0x61657674u, 0x71756974u,
      (AEEventHandlerUPP)CMacGameEngine::HandleAppleEvent, (SRefCon)this, 0);
}

int __cdecl CMacGameEngine::OneShotTimer(CMacGameEngine *this) {
  const __CFString *DiscName; // eax
  int result;                 // eax
  OSStatus v3;                // ebx
  _DWORD *exception;          // eax
  UInt8 path[1032];           // [esp+10h] [ebp-408h] BYREF

  DiscName = MacResources::GetDiscName();
  result = MacTools::FindDiscVolume(DiscName, 0);
  if ((_WORD)result) {
    MacFolders::GetDataFolderPath(path, 0x400u);
    chdir((const char *)path);
    v3 = MacDisplay::SetupDisplay((MacDisplay *)0x280, 480);
    if (v3) {
      exception = __cxa_allocate_exception(4u);
      *exception = v3;
      __cxa_throw(exception, (struct type_info *)&`typeinfo for'long, 0);
    }
    CMacGameEngine::InstallEventHandlers(this);
    MacTools::HideCursor((MacTools *)1);
    return (*((int(__cdecl **)(CMacGameEngine *))this->_vptr$CMacGameEngine +
              4))(this);
  }
  return result;
}

void __cdecl CMacGameEngine::OneShotTimerProc(EventLoopTimerRef a1,
                                              CMacGameEngine *a2) {
  CMacGameEngine::OneShotTimer(a2);
  QuitApplicationEventLoop();
}

_BOOL4 __cdecl CMacGameEngine::HandleEvent(CMacGameEngine *this,
                                           EventRef inEvent) {
  char v2;                  // si
  UInt32 EventKind;         // ebx
  OSType EventClass;        // eax
  bool v5;                  // cc
  _BOOL4 result;            // eax
  unsigned __int16 v7;      // ax
  CMacGameEngine *v8;       // edx
  CMacGameEngine *v9;       // ecx
  int32_t mLastModifierSet; // edx
  int32_t v11;              // ebx
  bool v12;                 // dl
  Point globalMouse;        // [esp+22h] [ebp-36h] BYREF
  int v14;                  // [esp+26h] [ebp-32h]
  MenuRef theMenu;          // [esp+2Ah] [ebp-2Eh]
  MenuItemIndex v16;        // [esp+2Eh] [ebp-2Ah]
  int v17;                  // [esp+30h] [ebp-28h] BYREF
  int32_t v18;              // [esp+34h] [ebp-24h] BYREF
  int outData;              // [esp+38h] [ebp-20h] BYREF
  _DWORD v20[7];            // [esp+3Ch] [ebp-1Ch] BYREF

  if (!this->mIsRunning || MacGlobals::IsSystemLocked()) {
    v2 = 1;
    EventKind = GetEventKind(inEvent);
    EventClass = GetEventClass(inEvent);
    v5 = EventClass <= 0x6D656E75;
    if (EventClass == 1835363957)
      goto LABEL_19;
  } else {
    v2 = 0;
    EventKind = GetEventKind(inEvent);
    EventClass = GetEventClass(inEvent);
    v5 = EventClass <= 0x6D656E75;
    if (EventClass == 1835363957) {
    LABEL_19:
      if (!this->mIsRunning)
        return 0;
      if (EventKind != 1) {
        if (EventKind == 2) {
          MacGlobals::UnlockSystem();
          return 0;
        }
        return 0;
      }
    LABEL_46:
      MacGlobals::LockSystem();
      return 0;
    }
  }
  if (v5) {
    if (EventClass == 1668113523) {
      if (EventKind == 1) {
        if (GetEventParameter(inEvent, 0x2D2D2D2Du, 0x68636D64u, 0, 0xEu, 0,
                              &globalMouse))
          return 0;
        switch (v14) {
        case 1751737445:
          return MacDisplay::IsFullscreen();
        case 1903520116:
          (*((void(__cdecl **)(CMacGameEngine *))this->_vptr$CMacGameEngine +
             14))(this);
          return 1;
        case 1416587116:
          if ((unsigned __int8)MacTools::IsCursorVisible()) {
            MacTools::HideCursor((MacTools *)1);
            MacGlobals::UnlockSystem();
          } else {
            MacTools::ShowCursor(0, 0);
            MacGlobals::LockSystem();
          }
          return 1;
        default:
          return 0;
        }
      } else {
        if (EventKind != 2 ||
            GetEventParameter(inEvent, 0x2D2D2D2Du, 0x68636D64u, 0, 0xEu, 0,
                              &globalMouse) ||
            (globalMouse.v & 1) == 0 || v14 != 1903520116) {
          return 0;
        }
        if (!(*((unsigned __int8(__cdecl **)(
                    CMacGameEngine *))this->_vptr$CMacGameEngine +
                13))(this) &&
            (globalMouse.v & 1) != 0) {
          DisableMenuItem(theMenu, v16);
          return 1;
        } else {
          return 1;
        }
      }
    } else {
      if (EventClass != 1801812322) {
        if (EventClass != 1634758764 || !this->mIsRunning)
          return 0;
        if (EventKind == 2)
          goto LABEL_46;
        if (EventKind > 2) {
          if (EventKind == 107) {
            MacTools::ShowCursor(0, 0);
            goto LABEL_46;
          }
          if (EventKind != 108)
            return 0;
          MacTools::HideCursor((MacTools *)1);
        } else if (EventKind != 1) {
          return 0;
        }
        MacGlobals::UnlockSystem();
        return 0;
      }
      if (v2)
        return 0;
      switch (EventKind) {
      case 3u:
        GetEventParameter(inEvent, 0x6B636872u, 0x54455854u, 0, 1u, 0,
                          &outData);
        GetEventParameter(inEvent, 0x6B636F64u, 0x6D61676Eu, 0, 4u, 0, &v18);
        (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                             int32_t))this->_vptr$CMacGameEngine +
           11))(this, (unsigned __int8)outData, v18);
        return 0;
      case 4u:
        GetEventParameter(inEvent, 0x6B6D6F64u, 0x6D61676Eu, 0, 4u, 0, &v18);
        mLastModifierSet = this->mLastModifierSet;
        v11 = v18;
        if (((mLastModifierSet & 0x200) != 0) != ((v18 & 0x200) != 0)) {
          if ((this->mLastModifierSet & 0x200) != 0) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               11))(this, 0, 56);
            v11 = v18;
            mLastModifierSet = this->mLastModifierSet;
          } else if ((v18 & 0x200) != 0) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               10))(this, 0, 56);
            v11 = v18;
            mLastModifierSet = this->mLastModifierSet;
          }
        }
        if (((mLastModifierSet & 0x1000) != 0) != ((v11 & 0x1000) != 0)) {
          if ((mLastModifierSet & 0x1000) != 0) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               11))(this, 0, 59);
            v11 = v18;
            mLastModifierSet = this->mLastModifierSet;
          } else if ((v11 & 0x1000) != 0) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               10))(this, 0, 59);
            v11 = v18;
            mLastModifierSet = this->mLastModifierSet;
          }
        }
        v12 = (mLastModifierSet & 0x800) != 0;
        if (v12 != ((v11 & 0x800) != 0)) {
          if (v12) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               11))(this, 0, 58);
            v11 = v18;
          } else if ((v11 & 0x800) != 0) {
            (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                                 int))this->_vptr$CMacGameEngine +
               10))(this, 0, 58);
            v11 = v18;
          }
        }
        this->mLastModifierSet = v11;
        return 0;
      case 1u:
        GetEventParameter(inEvent, 0x6B636872u, 0x54455854u, 0, 1u, 0,
                          &outData);
        GetEventParameter(inEvent, 0x6B636F64u, 0x6D61676Eu, 0, 4u, 0, &v18);
        (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                             int32_t))this->_vptr$CMacGameEngine +
           10))(this, (unsigned __int8)outData, v18);
        return 0;
      default:
        return 0;
      }
    }
  } else if (EventClass == 1952807028) {
    if (v2 || EventKind != 2)
      return 0;
    GetEventParameter(inEvent, 0x74737478u, 0x75747874u, 0, 2u, 0, &outData);
    v7 = 13;
    if ((_WORD)outData != 3)
      v7 = outData;
    LOWORD(outData) = v7;
    (*((void(__cdecl **)(CMacGameEngine *, _DWORD))this->_vptr$CMacGameEngine +
       12))(this, v7);
    return 0;
  } else if (EventClass == 2003398244) {
    if (!this->mIsRunning)
      return 0;
    if (EventKind == 27) {
      GetGlobalMouse(&globalMouse);
      MacDisplay::GlobalToLocal((MacDisplay *)&globalMouse);
      if ((unsigned __int8)MacDisplay::PointInWindow(
              *(MacDisplay **)&globalMouse)) {
        if (!CMacGameEngine::UpdateOSCursor(Point)::sSystemCursorVisible)
          return 0;
        SwitchToWinCursor();
        CMacGameEngine::UpdateOSCursor(Point)::sSystemCursorVisible = 0;
        return 0;
      } else {
        if (CMacGameEngine::UpdateOSCursor(Point)::sSystemCursorVisible)
          return 0;
        SwitchToMacCursor();
        CMacGameEngine::UpdateOSCursor(Point)::sSystemCursorVisible = 1;
        return 0;
      }
    } else {
      if (EventKind != 72)
        return 0;
      (*((void(__cdecl **)(CMacGameEngine *))this->_vptr$CMacGameEngine + 14))(
          this);
      return 1;
    }
  } else {
    if (EventClass != 1836021107 || v2)
      return 0;
    switch (EventKind) {
    case 1u:
      GetEventParameter(inEvent, 0x6D62746Eu, 0x6D62746Eu, 0, 2u, 0, &outData);
      GetEventParameter(inEvent, 0x6D6C6F63u, 0x51447074u, 0, 4u, 0,
                        &globalMouse);
      MacDisplay::GlobalToLocal((MacDisplay *)&globalMouse);
      GetEventParameter(inEvent, 0x6B6D6F64u, 0x6D61676Eu, 0, 4u, 0, &v18);
      GetEventParameter(inEvent, 0x63636E74u, 0x6D61676Eu, 0, 4u, 0, &v17);
      if ((_WORD)outData == 1 && (v18 & 0x100) != 0) {
        LOWORD(outData) = 2;
        this->mFakeRightButtonDown = 1;
      }
      if ((unsigned __int8)MacDisplay::InWindowMode() &&
          !(unsigned __int8)MacDisplay::PointInWindow(
              *(MacDisplay **)&globalMouse)) {
        return 0;
      }
      (*((void(__cdecl **)(CMacGameEngine *, _DWORD, Point, int32_t,
                           int))this->_vptr$CMacGameEngine +
         6))(this, (unsigned __int16)outData, globalMouse, v18, v17);
      result = 0;
      break;
    case 2u:
      GetEventParameter(inEvent, 0x6D62746Eu, 0x6D62746Eu, 0, 2u, 0, &outData);
      GetEventParameter(inEvent, 0x6D6C6F63u, 0x51447074u, 0, 4u, 0,
                        &globalMouse);
      MacDisplay::GlobalToLocal((MacDisplay *)&globalMouse);
      if ((_WORD)outData == 1) {
        if (this->mFakeRightButtonDown) {
          LOWORD(outData) = 2;
          this->mFakeRightButtonDown = 0;
        }
        v8 = this;
        v9 = this;
      } else {
        v8 = this;
        v9 = this;
      }
      (*((void(__cdecl **)(CMacGameEngine *, _DWORD,
                           Point))v8->_vptr$CMacGameEngine +
         7))(v9, (unsigned __int16)outData, globalMouse);
      result = 0;
      break;
    case 5u:
    case 6u:
      GetEventParameter(inEvent, 0x6D647461u, 0x51447074u, 0, 4u, 0, v20);
      GetEventParameter(inEvent, 0x6D6C6F63u, 0x51447074u, 0, 4u, 0,
                        &globalMouse);
      MacDisplay::GlobalToLocal((MacDisplay *)&globalMouse);
      GetEventParameter(inEvent, 0x6B6D6F64u, 0x6D61676Eu, 0, 4u, 0, &outData);
      (*((void(__cdecl **)(CMacGameEngine *, _DWORD, Point,
                           int))this->_vptr$CMacGameEngine +
         8))(this, v20[0], globalMouse, outData);
      return 0;
    case 0xAu:
      if (!this->mWheelEventPosted) {
        this->mWheelEventPosted = 1;
        GetEventParameter(inEvent, 0x6D77646Cu, 0x6C6F6E67u, 0, 4u, 0,
                          &outData);
        GetEventParameter(inEvent, 0x6D6C6F63u, 0x51447074u, 0, 4u, 0,
                          &globalMouse);
        MacDisplay::GlobalToLocal((MacDisplay *)&globalMouse);
        GetEventParameter(inEvent, 0x6B6D6F64u, 0x6D61676Eu, 0, 4u, 0, &v18);
        (*((void(__cdecl **)(CMacGameEngine *, int, Point,
                             int32_t))this->_vptr$CMacGameEngine +
           9))(this, outData, globalMouse, v18);
      }
      return 0;
    default:
      return 0;
    }
  }
  return result;
}
