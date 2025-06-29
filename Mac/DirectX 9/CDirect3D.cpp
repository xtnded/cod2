CDirect3D::RegisterSoftwareDevice(void *pInitializeFunction) {
  UNIMPLEMENTED();
}

CDirect3D::CheckDeviceType(unsigned int, _D3DDEVTYPE, _D3DFORMAT, _D3DFORMAT,
                           int) {
  UNIMPLEMENTED();
}

CDirect3D::CheckDeviceFormatConversion(unsigned int Adapter,
                                       _D3DDEVTYPE DeviceType,
                                       _D3DFORMAT SourceFormat,
                                       _D3DFORMAT TargetFormat) {
  UNIMPLEMENTED();
}

CDirect3D::GetAdapterMonitor(unsigned int Adapter) { UNIMPLEMENTED(); }

CVAOPacketFixedFunction::IsFixedFunction() const { UNIMPLEMENTED(); }

CVAOPacketProgrammable::IsFixedFunction() const { UNIMPLEMENTED(); }

CDirect3DDevice::DrawPrimitive(_D3DPRIMITIVETYPE PrimitiveType,
                               unsigned int StartVertex,
                               unsigned int PrimitiveCount) {
  UNIMPLEMENTED();
}

CDirect3DDevice::DrawPrimitiveUP(_D3DPRIMITIVETYPE, unsigned int, void const *,
                                 unsigned int) {
  UNIMPLEMENTED();
}

CVAOPacketProgrammable::~CVAOPacketProgrammable() { UNIMPLEMENTED(); }

CVAOPacketFixedFunction::~CVAOPacketFixedFunction() { UNIMPLEMENTED(); }

CDirect3D::AddRef() { UNIMPLEMENTED(); }

CDirect3D::~CDirect3D() { UNIMPLEMENTED(); }

CDirect3D::QueryInterface(_GUID const &iid, void **ppvObj) { UNIMPLEMENTED(); }

CDirect3D::Release() { UNIMPLEMENTED(); }

CDirect3D::GetAdapterCount() { UNIMPLEMENTED(); }

CDirect3D::GetAdapterIdentifier(unsigned int Adapter, unsigned long Flags,
                                _D3DADAPTER_IDENTIFIER9 *pIdentifier) {
  UNIMPLEMENTED();
}

CDirect3D::GetAdapterModeCount(unsigned int Adapter, _D3DFORMAT Format) {
  UNIMPLEMENTED();
}

CDirect3D::EnumAdapterModes(unsigned int Adapter, _D3DFORMAT Format,
                            unsigned int Mode, _D3DDISPLAYMODE *pMode) {
  UNIMPLEMENTED();
}

CDirect3D::GetAdapterDisplayMode(unsigned int Adapter, _D3DDISPLAYMODE *pMode) {
  UNIMPLEMENTED();
}

CDirect3D::CheckDeviceFormat(unsigned int Adapter, _D3DDEVTYPE DeviceType,
                             _D3DFORMAT AdapterFormat, unsigned long Usage,
                             _D3DRESOURCETYPE RType, _D3DFORMAT CheckFormat) {
  UNIMPLEMENTED();
}

CDirect3D::CheckDeviceMultiSampleType(unsigned int Adapter,
                                      _D3DDEVTYPE DeviceType,
                                      _D3DFORMAT SurfaceFormat, int Windowed,
                                      _D3DMULTISAMPLE_TYPE MultiSampleType,
                                      unsigned long *pQualityLevels) {
  UNIMPLEMENTED();
}

CDirect3D::CheckDepthStencilMatch(unsigned int Adapter, _D3DDEVTYPE DeviceType,
                                  _D3DFORMAT AdapterFormat,
                                  _D3DFORMAT RenderTargetFormat,
                                  _D3DFORMAT DepthStencilFormat) {
  UNIMPLEMENTED();
}

CDirect3D::GetDeviceCaps(unsigned int Adapter, _D3DDEVTYPE DeviceType,
                         _D3DCAPS9 *pCaps) {
  UNIMPLEMENTED();
}

CDirect3D::CreateDevice(unsigned int Adapter, _D3DDEVTYPE DeviceType,
                        HWND__ *hFocusWindow, unsigned long BehaviorFlags,
                        _D3DPRESENT_PARAMETERS_ *pPresentationParameters,
                        IDirect3DDevice9 **ppReturnedDeviceInterface) {
  UNIMPLEMENTED();
}

CDirect3DDevice::SetDepthStencilSurface(IDirect3DSurface9 *pNewZStencil) {
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateAndSetGenericProgrammableVAO(unsigned int StartVertex,
                                                    unsigned int NumVertices,
                                                    void const *pIndices,
                                                    unsigned int NumIndices) {
  UNIMPLEMENTED();
}

COpenGL::SetTexBorderColor(unsigned int Unit, unsigned long Target,
                           unsigned long Value) {
  UNIMPLEMENTED();
}

CDirect3DDevice::SetTexture(unsigned long Stage,
                            IDirect3DBaseTexture9 *pTexture) {
  UNIMPLEMENTED();
}

CDirect3DDevice::GetStreamPtrs(unsigned int StartVertex) { UNIMPLEMENTED(); }

CDirect3DDevice::GetCanUseVAOWithTexCoordStreams(bool CanUseVAO) {
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateAndSetGenericFixedFunctionVAO(unsigned int StartVertex,
                                                     unsigned int NumVertices,
                                                     void const *pIndices,
                                                     unsigned int NumIndices,
                                                     bool NeedsNormals) {
  UNIMPLEMENTED();
}

CDirect3DDevice::ValidateLighting() { UNIMPLEMENTED(); }

COpenGL::SetTex(unsigned int Unit, unsigned long Target,
                COpenGLTexture const *pOpenGLTexInfo) {
  UNIMPLEMENTED();
}

CDirect3DDevice::SetStream(bool &IsTexCoordStream, unsigned int ActiveStream,
                           unsigned int VertexRegisterAddress,
                           unsigned int Offset, unsigned int Stride, long VSize,
                           unsigned long VType) {
  UNIMPLEMENTED();
}

CDirect3DDevice::ParseShaderDeclaration(bool IsFixedFunction, bool &CanUseVAO) {
  UNIMPLEMENTED();
}

CDirect3DDevice::ValidateModelViewMatrix() { UNIMPLEMENTED(); }

CDirect3DDevice::SetTransform(_D3DTRANSFORMSTATETYPE State,
                              _D3DMATRIX const *pMatrix) {
  UNIMPLEMENTED();
}

CDirect3D::GetDirect3DInterface() { UNIMPLEMENTED(); }

CDirect3DDevice::CreateAndSetFixedFunctionVAO(
    bool &CanUseVAO, unsigned int StartVertex, unsigned int NumVertices,
    void const *pIndices, unsigned int NumIndices, bool NeedsNormals) {
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateAndSetProgrammableVAO(unsigned int StartVertex,
                                             unsigned int NumVertices,
                                             void const *pIndices,
                                             unsigned int NumIndices) {
  UNIMPLEMENTED();
}

CDirect3DDevice::ValidateTransformation(unsigned int StartVertex,
                                        unsigned int NumVertices,
                                        void const *pIndices,
                                        unsigned int NumIndices) {
  UNIMPLEMENTED();
}

CDirect3DDevice::SynchronizeD3DAndOpenGLTextureState(
    IDirect3DBaseTexture9 *pTex, unsigned int Stage) {
  UNIMPLEMENTED();
}

CDirect3DDevice::ValidateRasterization(unsigned int StartVertex,
                                       unsigned int EndVertex) {
  UNIMPLEMENTED();
}

CDirect3DDevice::DrawIndexedPrimitive(_D3DPRIMITIVETYPE PrimitiveType,
                                      int BaseVertexIndex,
                                      unsigned int MinIndex,
                                      unsigned int NumVertices,
                                      unsigned int StartIndex,
                                      unsigned int PrimitiveCount) {
  UNIMPLEMENTED();
}
