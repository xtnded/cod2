CBaseVA::~CBaseVA() { UNIMPLEMENTED(); }

CColorArray::Enable() { UNIMPLEMENTED(); }

CColorArray::Disable() { UNIMPLEMENTED(); }

CSecondaryColorArray::Enable() { UNIMPLEMENTED(); }

CSecondaryColorArray::Disable() { UNIMPLEMENTED(); }

CNormalArray::Enable() { UNIMPLEMENTED(); }

CNormalArray::Disable() { UNIMPLEMENTED(); }

CVertexArray::Enable() { UNIMPLEMENTED(); }

CVertexArray::Disable() { UNIMPLEMENTED(); }

CTexCoordArray::Enable() { UNIMPLEMENTED(); }

CTexCoordArray::Disable() { UNIMPLEMENTED(); }

CTexCoordArray::~CTexCoordArray() { UNIMPLEMENTED(); }

COpenGL::SetColorMaterialEnable(bool) { UNIMPLEMENTED(); }

COpenGL::SetActiveTexUnit(unsigned int Unit) { UNIMPLEMENTED(); }

COpenGL::SetDither(bool Value) { UNIMPLEMENTED(); }

COpenGL::SetBlendEXT(bool ForceValidation, unsigned long SrcFactorRGB,
                     unsigned long DstFactorRGB, unsigned long SrcFactorAlpha,
                     unsigned long DstFactorAlpha) {
  UNIMPLEMENTED();
}

COpenGL::SetBlend(bool ForceValidation, unsigned long SrcFactorRGB,
                  unsigned long DstFactorRGB) {
  UNIMPLEMENTED();
}

COpenGL::SetVertexProgram(COpenGLVertexProgram const *pOGLVertexProgramInfo) {
  UNIMPLEMENTED();
}

COpenGL::SetVARInfo(void const *pVAStart, unsigned int Size) {
  UNIMPLEMENTED();
}

COpenGL::DisableVertexProgramStream(unsigned int AttribArray) {
  UNIMPLEMENTED();
}

COpenGL::CTexUnit::SetTex(unsigned long Target,
                          COpenGLTexture const *pOpenGLTexInfo) {
  UNIMPLEMENTED();
}

COpenGL::SetVertexProgramStreamInfo(unsigned int AttribArray, long VSize,
                                    unsigned long VType,
                                    unsigned char Normalized, long Stride,
                                    void const *pStream) {
  UNIMPLEMENTED();
}

COpenGL::CTexUnit::Reset(bool SupportsAnisotropicFiltering,
                         bool SupportsLODBias, bool IsProgramableOnly) {
  UNIMPLEMENTED();
}

COpenGL::SetVAO(COpenGLVAO const &VAO, bool IsFixedFunction,
                bool ForceValidation) {
  UNIMPLEMENTED();
}

COpenGL::EnableColorArray(long Size, unsigned long Type, long Stride,
                          void const *Pointer) {
  UNIMPLEMENTED();
}

COpenGL::DisableColorArray() { UNIMPLEMENTED(); }

COpenGL::EnableNormalArray(unsigned long Type, long Stride,
                           void const *Pointer) {
  UNIMPLEMENTED();
}

COpenGL::DisableNormalArray() { UNIMPLEMENTED(); }

COpenGL::EnableVertexArray(long Size, unsigned long Type, long Stride,
                           void const *Pointer) {
  UNIMPLEMENTED();
}

COpenGL::SetLight(unsigned int Light, LightInfoType const &Src) {
  UNIMPLEMENTED();
}

COpenGL::EnableTexCoordArray(unsigned int Unit, long Size, unsigned long Type,
                             long Stride, void const *Pointer) {
  UNIMPLEMENTED();
}

COpenGL::DisableTexCoordArray(unsigned int Unit) { UNIMPLEMENTED(); }

CColorArray::~CColorArray() { UNIMPLEMENTED(); }

CSecondaryColorArray::~CSecondaryColorArray() { UNIMPLEMENTED(); }

CVertexArray::~CVertexArray() { UNIMPLEMENTED(); }

CNormalArray::~CNormalArray() { UNIMPLEMENTED(); }

COpenGL::SetTexMatrix(unsigned int Unit, float const *m) { UNIMPLEMENTED(); }

COpenGL::SetTexMatrixIdentity(unsigned int Unit) { UNIMPLEMENTED(); }

COpenGL::Shutdown() { UNIMPLEMENTED(); }

COpenGL::SetTexGenEnable(unsigned int Unit, bool Enable, bool EnableReflection,
                         bool EnableNormalMap) {
  UNIMPLEMENTED();
}

COpenGL::DisableTexUnit(unsigned int Unit) { UNIMPLEMENTED(); }

std::list<unsigned long *, std::allocator<unsigned long *>>::erase(
    std::_List_iterator<unsigned long *> __position) {
  UNIMPLEMENTED();
}

COpenGL::ReleaseVAOBinding(unsigned long const *TexID) { UNIMPLEMENTED(); }

COpenGL::ReleaseTextureBinding(unsigned long const *TexID) { UNIMPLEMENTED(); }

std::vector<COpenGL::CTexUnit, std::allocator<COpenGL::CTexUnit>>::
    _M_insert_aux(__gnu_cxx::__normal_iterator<
                      COpenGL::CTexUnit * __position,
                      std::vector<COpenGL::CTexUnit __x,
                                  std::allocator<COpenGL::CTexUnit>>>,
                  COpenGL::CTexUnit const &) {
  UNIMPLEMENTED();
}

std::vector<COpenGL::CTexUnit, std::allocator<COpenGL::CTexUnit>>::erase(
    __gnu_cxx::__normal_iterator<
        COpenGL::CTexUnit * __first,
        std::vector<COpenGL::CTexUnit __last,
                    std::allocator<COpenGL::CTexUnit>>>,
    __gnu_cxx::__normal_iterator<
        COpenGL::CTexUnit *,
        std::vector<COpenGL::CTexUnit, std::allocator<COpenGL::CTexUnit>>>) {
  UNIMPLEMENTED();
}

COpenGL::Init(unsigned int Buffers, unsigned int MaxTextureUnits,
              unsigned int MaxTextureImageUnits) {
  UNIMPLEMENTED();
}

COpenGL::~COpenGL() { UNIMPLEMENTED(); }

COpenGL::COpenGL() { UNIMPLEMENTED(); }

COpenGLVertexProgram::COpenGLVertexProgram(char const *pSrcData pSrcData) {
  UNIMPLEMENTED();
}

COpenGLVertexProgram::~COpenGLVertexProgram() { UNIMPLEMENTED(); }
