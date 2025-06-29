const UI_Component::`vftable'; void __cdecl Vec2Clear(float *const) {
  UNIMPLEMENTED();
}

public:
virtual void *__cdecl UI_Component::`vector deleting destructor'(unsigned int) {
  UNIMPLEMENTED();
}

public:
virtual void *__cdecl UI_Component::`scalar deleting destructor'(unsigned int) {
  UNIMPLEMENTED();
}

public:
virtual class UI_Component *__cdecl UI_VerticalDivider::GetCompAtLocation(
    float *const) {
  UNIMPLEMENTED();
}

public:
void __cdecl UI_VerticalDivider::DrawTop(float, float, float, float) {
  UNIMPLEMENTED();
}

public:
void __cdecl UI_LinesComponent::ClearFocus(void) { UNIMPLEMENTED(); }

public:
virtual void __cdecl UI_LinesComponent::AddText(char const *) {
  UNIMPLEMENTED();
}

public:
void __cdecl UI_LinesComponent::UpdateHeight(void) { UNIMPLEMENTED(); }

public:
void __cdecl UI_LinesComponent::DecSelectedLineFocus(bool) { UNIMPLEMENTED(); }

public:
void __cdecl UI_LinesComponent::IncSelectedLineFocus(bool) { UNIMPLEMENTED(); }

public:
virtual bool __cdecl UI_LinesComponent::SetSelectedLineFocus(int, bool) {
  UNIMPLEMENTED();
}

public:
virtual void __cdecl UI_ScrollPane::AddText(char const *) { UNIMPLEMENTED(); }

public:
bool __cdecl UI_ScrollPane::GetInnerSize(float *const) { UNIMPLEMENTED(); }

public:
int __cdecl UI_ScrollPane::GetLastDisplayedLine(void) { UNIMPLEMENTED(); }

public:
int __cdecl UI_ScrollPane::GetFirstDisplayedLine(void) { UNIMPLEMENTED(); }

public:
void __cdecl UI_ScrollPane::SetPos(void) { UNIMPLEMENTED(); }

public:
virtual void __cdecl UI_Component::AddText(char const *) { UNIMPLEMENTED(); }

public:
virtual class UI_Component *__cdecl UI_Component::GetCompAtLocation(
    float *const) {
  UNIMPLEMENTED();
}

public:
virtual __cdecl UI_Component::~UI_Component(void) { UNIMPLEMENTED(); }

public:
virtual void __cdecl UI_Component::Shutdown(void) { UNIMPLEMENTED(); }

public:
static void __cdecl UI_Component::GetCursorPos(int *, int *) {
  UNIMPLEMENTED();
}

int __cdecl UI_HideCursor(void) { UNIMPLEMENTED(); }

public:
static void __cdecl UI_Component::MouseEvent(int, int) { UNIMPLEMENTED(); }

public:
static struct Material *__cdecl UI_Component::RegisterMaterialNoMip(
    char const *, int) {
  UNIMPLEMENTED();
}

public:
static void __cdecl UI_Component::InitAssets(void) { UNIMPLEMENTED(); }

void __cdecl UI_Component_Init(void) {
  if (dword_1220A70) {
    memset(&UI_Component::g, 0, 0xACu);
    *(float *)&UI_Component::g = (float)dword_14C13C4;
    *(float *)&dword_195AF24 = (float)dword_14C13C8;
    dword_195AF28 = 1090519040;
    dword_195AF2C = 1098907648;
    dword_195AF30 = 1098907648;
    if (*(_DWORD *)(com_developer + 8)) {
      dword_195AF34 = dword_121C6B0("ui/assets/3_cursor3", 48, 1);
      dword_195AF44 = dword_121C6B0("ui/assets/sliderbutt_1", 48, 1);
    }
  }
}

public:
virtual bool __cdecl UI_VerticalDivider::KeyEvent(float *const, int) {
  UNIMPLEMENTED();
}

public:
virtual void __cdecl UI_VerticalDivider::Draw(float, float, float, float, float,
                                              float) {
  UNIMPLEMENTED();
}

public:
virtual bool __cdecl UI_LinesComponent::KeyEvent(float *const, int) {
  UNIMPLEMENTED();
}

public:
virtual class UI_Component *__cdecl UI_ScrollPane::GetCompAtLocation(
    float *const) {
  UNIMPLEMENTED();
}

public:
int __cdecl UI_ScrollPane::GetInnerLinesCount(void) { UNIMPLEMENTED(); }

public:
void __cdecl UI_ScrollPane::DisplaySelectedLine(void) { UNIMPLEMENTED(); }

public:
void __cdecl UI_ScrollPane::CheckMouseScroll(int, float *const, float *const,
                                             float) {
  UNIMPLEMENTED();
}

public:
virtual void __cdecl UI_Component::Init(void) { UNIMPLEMENTED(); }

public:
virtual void __cdecl UI_VerticalDivider::Init(void) { UNIMPLEMENTED(); }

public:
virtual void __cdecl UI_LinesComponent::Init(void) { UNIMPLEMENTED(); }

public:
virtual bool __cdecl UI_ScrollPane::KeyEvent(float *const, int) {
  UNIMPLEMENTED();
}

public:
virtual void __cdecl UI_ScrollPane::Init(void) { UNIMPLEMENTED(); }

public:
static void __cdecl UI_Component::DrawText(float, float, float, int,
                                           float const *const, char const *) {
  UNIMPLEMENTED();
}

public:
static void __cdecl UI_Component::DrawPicRotate(float, float, float, float,
                                                float *const,
                                                struct Material *) {
  UNIMPLEMENTED();
}

public:
static void __cdecl UI_Component::DrawPic(float, float, float, float,
                                          float *const, struct Material *) {
  UNIMPLEMENTED();
}

public:
virtual void __cdecl UI_ScrollPane::Draw(float, float, float, float, float,
                                         float) {
  UNIMPLEMENTED();
}

public:
static void __cdecl UI_Component::DrawCursor(void) { UNIMPLEMENTED(); }

int marker_ui_component;

public:
static class UI_Component *UI_Component::selectionComp;

public:
static struct UI_Component_data_t UI_Component::g;
bool __cdecl InRect(float *const, float *const, float *const) {
  UNIMPLEMENTED();
}
