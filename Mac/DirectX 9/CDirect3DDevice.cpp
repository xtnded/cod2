std::char_traits<char>::eq(char const &__c1, char const &__c2)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::EvictManagedResources()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetCreationParameters(_D3DDEVICE_CREATION_PARAMETERS *)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetCursorProperties(unsigned int XHotSpot,
                                     unsigned int YHotSpot,
                                     IDirect3DSurface9 *pCursorBitmap)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetCursorPosition(int XScreenSpace, int YScreenSpace,
                                   unsigned long Flags)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::ShowCursor(int bShow)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateAdditionalSwapChain(
    _D3DPRESENT_PARAMETERS_ *pPresentationParameters,
    IDirect3DSwapChain9 **pSwapChain)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetSwapChain(unsigned int iSwapChain,
                              IDirect3DSwapChain9 **pSwapChain)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetNumberOfSwapChains()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetRasterStatus(unsigned int iSwapChain,
                                 _D3DRASTER_STATUS *pRasterStatus)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetDialogBoxMode(int bEnableDialogs)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::UpdateSurface(IDirect3DSurface9 *pSourceSurface,
                               tagRECT const *pSourceRect,
                               IDirect3DSurface9 *pDestinationSurface,
                               tagPOINT const *pDestPoint)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetRenderTargetData(IDirect3DSurface9 *pRenderTarget,
                                     IDirect3DSurface9 *pDestSurface)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetFrontBufferData(unsigned int iSwapChain,
                                    IDirect3DSurface9 *pDestSurface)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::ColorFill(IDirect3DSurface9 *pSurface, tagRECT const *pRect,
                           unsigned long color)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateOffscreenPlainSurface(unsigned int Width,
                                             unsigned int Height,
                                             _D3DFORMAT Format, _D3DPOOL Pool,
                                             IDirect3DSurface9 **ppSurface,
                                             void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetRenderTarget(unsigned long RenderTargetIndex,
                                 IDirect3DSurface9 **ppRenderTarget)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::MultiplyTransform(_D3DTRANSFORMSTATETYPE, _D3DMATRIX const *)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetViewport(_D3DVIEWPORT9 *pViewport)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetMaterial(_D3DMATERIAL9 *pMaterial)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetLight(unsigned long Index, _D3DLIGHT9 *)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetLightEnable(unsigned long Index, int *pEnable)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetClipPlane(unsigned long Index, float const *pPlane)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetClipPlane(unsigned long Index, float *pPlane)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::BeginStateBlock()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateStateBlock(_D3DSTATEBLOCKTYPE Type,
                                  IDirect3DStateBlock9 **ppSB)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::EndStateBlock(IDirect3DStateBlock9 **ppSB)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetClipStatus(_D3DCLIPSTATUS9 const *pClipStatus)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetClipStatus(_D3DCLIPSTATUS9 *pClipStatus)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::ValidateDevice(unsigned long *pNumPasses)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetPaletteEntries(unsigned int PaletteNumber,
                                   tagPALETTEENTRY const *pEntries)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetPaletteEntries(unsigned int PaletteNumber,
                                   tagPALETTEENTRY *pEntries)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetCurrentTexturePalette(unsigned int PaletteNumber)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetCurrentTexturePalette(unsigned int *PaletteNumber)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetScissorRect(tagRECT const *pRect)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetScissorRect(tagRECT *pRect)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetSoftwareVertexProcessing(int bSoftware)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetSoftwareVertexProcessing()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetNPatchMode(float nSegments)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetNPatchMode()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetVertexDeclaration(IDirect3DVertexDeclaration9 **ppDecl)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetFVF(unsigned long *pFVF)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::DrawIndexedPrimitiveUP(
    _D3DPRIMITIVETYPE PrimitiveType, unsigned int MinVertexIndex,
    unsigned int NumVertexIndices, unsigned int PrimitiveCount,
    void const *pIndexData, _D3DFORMAT IndexDataFormat,
    void const *pVertexStreamZeroData, unsigned int VertexStreamZeroStride)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::ProcessVertices(unsigned int SrcStartIndex,
                                 unsigned int DestIndex,
                                 unsigned int VertexCount,
                                 IDirect3DVertexBuffer9 *pDestBuffer,
                                 IDirect3DVertexDeclaration9 *pVertexDecl,
                                 unsigned long Flags)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetVertexShader(IDirect3DVertexShader9 **ppShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetStreamSource(unsigned int StreamNumber,
                                 IDirect3DVertexBuffer9 *pStreamData,
                                 unsigned int OffsetInBytes,
                                 unsigned int Stride)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetVertexShaderConstantF(unsigned int StartRegister,
                                          float *pConstantData,
                                          unsigned int Vector4fCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetVertexShaderConstantI(unsigned int StartRegister,
                                          int const *pConstantData,
                                          unsigned int Vector4iCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetVertexShaderConstantI(unsigned int StartRegister,
                                          int *pConstantData,
                                          unsigned int Vector4iCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetVertexShaderConstantB(unsigned int StartRegister,
                                          int const *pConstantData,
                                          unsigned int BoolCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetVertexShaderConstantB(unsigned int StartRegister,
                                          int *pConstantData,
                                          unsigned int BoolCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetStreamSourceFreq(unsigned int StreamNumber,
                                     unsigned int Setting)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetStreamSourceFreq(unsigned int StreamNumber,
                                     unsigned int *pSetting)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetIndices(IDirect3DIndexBuffer9 *pIndexData)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetIndices(IDirect3DIndexBuffer9 **ppIndexData)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetPixelShader(IDirect3DPixelShader9 **ppShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetPixelShaderConstantF(unsigned int StartRegister,
                                         float *pConstantData,
                                         unsigned int Vector4fCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetPixelShaderConstantI(unsigned int StartRegister,
                                         int const *pConstantData,
                                         unsigned int Vector4iCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetPixelShaderConstantI(unsigned int StartRegister,
                                         int *pConstantData,
                                         unsigned int Vector4iCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetPixelShaderConstantB(unsigned int StartRegister,
                                         int const *pConstantData,
                                         unsigned int BoolCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetPixelShaderConstantB(unsigned int StartRegister,
                                         int *pConstantData,
                                         unsigned int BoolCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::DrawRectPatch(unsigned int Handle, float const *pNumSegs,
                               _D3DRECTPATCH_INFO const *pRectPatchInfo)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::DrawTriPatch(unsigned int Handle, float const *pNumSegs,
                              _D3DTRIPATCH_INFO const *pTriPatchInfo)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::DeletePatch(unsigned int Handle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateQuery(_D3DQUERYTYPE Type, IDirect3DQuery9 **ppQuery)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::AddRef()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::QueryInterface(_GUID const &iid, void **ppvObj)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::Release()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateIndexBuffer(unsigned int Length, unsigned long Usage,
                                   _D3DFORMAT Format, _D3DPOOL Pool,
                                   IDirect3DIndexBuffer9 **ppIndexBuffer,
                                   void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::TestCooperativeLevel()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetAvailableTextureMem()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetDirect3D(IDirect3D9 **ppD3D8)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetDeviceCaps(_D3DCAPS9 *pCaps)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetDisplayMode(unsigned int iSwapChain, _D3DDISPLAYMODE *pMode)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetBackBuffer(unsigned int iSwapChain, unsigned int BackBuffer,
                               _D3DBACKBUFFER_TYPE Type,
                               IDirect3DSurface9 **ppBackBuffer)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetGammaRamp(unsigned int iSwapChain, unsigned long Flags,
                              _D3DGAMMARAMP const *pRamp)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetGammaRamp(unsigned int iSwapChain, _D3DGAMMARAMP *pRamp)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateTexture(unsigned int Width, unsigned int Height,
                               unsigned int Levels, unsigned long Usage,
                               _D3DFORMAT Format, _D3DPOOL Pool,
                               IDirect3DTexture9 **ppTexture,
                               void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateVolumeTexture(
    unsigned int Width Width, unsigned int Height Height,
    unsigned int Depth Depth, unsigned int Levels Levels,
    unsigned long Usage Usage, _D3DFORMAT Format Format, _D3DPOOL Pool Pool,
    IDirect3DVolumeTexture9 **ppVolumeTexture ppVolumeTexture,
    void **pSharedHandle pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateCubeTexture(unsigned int EdgeLength, unsigned int Levels,
                                   unsigned long Usage, _D3DFORMAT Format,
                                   _D3DPOOL Pool,
                                   IDirect3DCubeTexture9 **ppCubeTexture,
                                   void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateVertexBuffer(unsigned int Length, unsigned long Usage,
                                    unsigned long FVF, _D3DPOOL Pool,
                                    IDirect3DVertexBuffer9 **ppVertexBuffer,
                                    void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::UpdateTexture(IDirect3DBaseTexture9 *pSourceTexture,
                               IDirect3DBaseTexture9 *pDestinationTexture)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::StartPixelOneToOneState()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetDepthStencilSurface(IDirect3DSurface9 **ppZStencilSurface)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::BeginScene()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::EndScene()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetTransform(_D3DTRANSFORMSTATETYPE State, _D3DMATRIX *pMatrix)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetViewport(_D3DVIEWPORT9 const *pViewport)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetAlphaFuncAndRef(unsigned long AlphaFuncValue,
                                    unsigned long AlphaRefValue)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetStencilOpFunc(unsigned int Value) const
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetRenderState(_D3DRENDERSTATETYPE State,
                                unsigned long *pValue)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateVertexDeclaration(
    _D3DVERTEXELEMENT9 const *pVertexElements,
    IDirect3DVertexDeclaration9 **ppDecl)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateVertexShader(unsigned long const *pFunction,
                                    IDirect3DVertexShader9 **ppShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetStreamSource(unsigned int StreamNumber,
                                 IDirect3DVertexBuffer9 **ppStreamData,
                                 unsigned int *pOffsetInBytes,
                                 unsigned int *pStride)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetTexture(unsigned long Stage,
                            IDirect3DBaseTexture9 **ppTexture)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateDepthStencilSurface(
    unsigned int Width, unsigned int Height, _D3DFORMAT Format,
    _D3DMULTISAMPLE_TYPE MultiSample, unsigned long MultisampleQuality,
    int Discard, IDirect3DSurface9 **ppSurface, void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreateRenderTarget(unsigned int Width, unsigned int Height,
                                    _D3DFORMAT Format,
                                    _D3DMULTISAMPLE_TYPE MultiSample,
                                    unsigned long MultisampleQuality,
                                    int Lockable, IDirect3DSurface9 **ppSurface,
                                    void **pSharedHandle)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetVertexDeclaration(IDirect3DVertexDeclaration9 *pDecl)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetVertexShader(IDirect3DVertexShader9 *pShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetFVF(unsigned long FVF)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::Clear(unsigned long Count, _D3DRECT const *pRects,
                       unsigned long Flags, unsigned long Color, float Z,
                       unsigned long Stencil)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetMaterial(_D3DMATERIAL9 const *pMaterial)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::LightEnable(unsigned long Index, int Enable)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CopyColorToRenderTargetTexture()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetRenderTarget(unsigned long RenderTargetIndex,
                                 IDirect3DSurface9 *pRenderTarget)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CTexStage::GetUsesTexture(bool &UsesTexFactor) const
{
  UNIMPLEMENTED();
}

CDirect3DDevice::Present(tagRECT const *pSourceRect, tagRECT const *pDestRect,
                         HWND__ *hDestWindowOverride,
                         _RGNDATA const *pDirtyRegion)
{
  UNIMPLEMENTED();
}

std::vector<CDirect3DDevice::CTexStage,
            std::allocator<CDirect3DDevice::CTexStage>>::
    erase(__gnu_cxx::__normal_iterator<
              CDirect3DDevice::CTexStage * __first,
              std::vector<CDirect3DDevice::CTexStage __last,
                          std::allocator<CDirect3DDevice::CTexStage>>>,
          __gnu_cxx::__normal_iterator<
              CDirect3DDevice::CTexStage *,
              std::vector<CDirect3DDevice::CTexStage,
                          std::allocator<CDirect3DDevice::CTexStage>>>)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetLight(unsigned long Index, _D3DLIGHT9 const *pLight)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetSamplerState(unsigned long Sampler,
                                 _D3DSAMPLERSTATETYPE Type, unsigned long Value)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetSamplerState(unsigned long Sampler,
                                 _D3DSAMPLERSTATETYPE Type,
                                 unsigned long *pValue)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetTextureStageState(unsigned long Stage,
                                      _D3DTEXTURESTAGESTATETYPE Type,
                                      unsigned long Value)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::GetTextureStageState(unsigned long Stage,
                                      _D3DTEXTURESTAGESTATETYPE Type,
                                      unsigned long *pValue)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetRenderState(_D3DRENDERSTATETYPE State, unsigned long Value)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerAlpha3(unsigned int Unit, unsigned long AlphaOp,
                              unsigned long Source0, unsigned long Operand0,
                              unsigned long Source1, unsigned long Operand1,
                              unsigned long Source2, unsigned long Operand2,
                              float Scale)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerRGB3(unsigned int Unit, unsigned long ColorOp,
                            unsigned long Source0, unsigned long Operand0,
                            unsigned long Source1, unsigned long Operand1,
                            unsigned long Source2, unsigned long Operand2,
                            float Scale)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::EndPixelOneToOneState()
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CTexStage::Init(unsigned int Stage, bool IsProgrammableStage)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetPixelShader(IDirect3DPixelShader9 *pShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::StretchRect(IDirect3DSurface9 *pSourceSurface,
                             tagRECT const *pSourceRect,
                             IDirect3DSurface9 *pDestSurface,
                             tagRECT const *pDestRect,
                             _D3DTEXTUREFILTERTYPE Filter)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerRGB1(unsigned int Unit, unsigned long ColorOp,
                            unsigned long Source0, unsigned long Operand0,
                            float Scale)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerRGB2(unsigned int Unit, unsigned long ColorOp,
                            unsigned long Source0, unsigned long Operand0,
                            unsigned long Source1, unsigned long Operand1,
                            float Scale)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerAlpha1(unsigned int Unit, unsigned long AlphaOp,
                              unsigned long Source0, unsigned long Operand0,
                              float Scale)
{
  UNIMPLEMENTED();
}

COpenGL::SetTexCombinerAlpha2(unsigned int Unit, unsigned long AlphaOp,
                              unsigned long Source0, unsigned long Operand0,
                              unsigned long Source1, unsigned long Operand1,
                              float Scale)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetPixelShaderConstantF(unsigned int StartRegister,
                                         float const *pConstantData,
                                         unsigned int Vector4fCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetVertexShaderConstantF(unsigned int StartRegister,
                                          float const *pConstantData,
                                          unsigned int Vector4fCount)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::SetTextureCoordStream(
    unsigned int TexUnit, unsigned int TransformFlags,
    _D3DMATRIX const &OriginalTexTransform, long VSize, unsigned int Tci,
    unsigned int StartVertex, unsigned int EndVertex, float const *pSrcCoords,
    unsigned int SrcStride, float const *pSrc2Coords, unsigned int Src2Stride)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::~CDirect3DDevice()
{
  UNIMPLEMENTED();
}

std::vector<CDirect3DDevice::CTexStage,
            std::allocator<CDirect3DDevice::CTexStage>>::
    _M_insert_aux(__gnu_cxx::__normal_iterator<
                      CDirect3DDevice::CTexStage * __position,
                      std::vector<CDirect3DDevice::CTexStage __x,
                                  std::allocator<CDirect3DDevice::CTexStage>>>,
                  CDirect3DDevice::CTexStage const &)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::Reset(_D3DPRESENT_PARAMETERS_ *pPresentationParameters)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CDirect3DDevice(
    unsigned int Adapter Adapter, _D3DDEVTYPE DeviceType DeviceType,
    OpaqueContextRef *Context Context,
    _D3DPRESENT_PARAMETERS_ *pPresentationParameters pPresentationParameters)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreatePixelShaderOpenGL(OpenGLPixelShaderType ShaderType,
                                         void const *pSrcData,
                                         IDirect3DPixelShader9 **ppShader)
{
  UNIMPLEMENTED();
}

CDirect3DDevice::CreatePixelShader(unsigned long const *pFunction,
                                   IDirect3DPixelShader9 **ppShader)
{
  UNIMPLEMENTED();
}
