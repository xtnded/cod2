CDirect3DSurface::GetDevice(IDirect3DDevice9 **) { UNIMPLEMENTED(); }

CDirect3DSurface::SetPrivateData(_GUID const &, void const *, unsigned long,
                                 unsigned long) {
  UNIMPLEMENTED();
}

CDirect3DSurface::GetPrivateData(_GUID const &refguid, void *pData,
                                 unsigned long *pSizeOfData) {
  UNIMPLEMENTED();
}

CDirect3DSurface::FreePrivateData(_GUID const &refguid) { UNIMPLEMENTED(); }

CDirect3DSurface::SetPriority(unsigned long PriorityNew) { UNIMPLEMENTED(); }

CDirect3DSurface::GetPriority() { UNIMPLEMENTED(); }

CDirect3DSurface::PreLoad() { UNIMPLEMENTED(); }

CDirect3DSurface::GetType() { UNIMPLEMENTED(); }

CDirect3DSurface::GetContainer(_GUID const &riid, void **ppContainer) {
  UNIMPLEMENTED();
}

CDirect3DSurface::GetDC(HDC__ **phdc) { UNIMPLEMENTED(); }

CDirect3DSurface::ReleaseDC(HDC__ *hdc) { UNIMPLEMENTED(); }

CDirect3DSurface::AddRef() { UNIMPLEMENTED(); }

CDirect3DSurface::~CDirect3DSurface() { UNIMPLEMENTED(); }

CDirect3DSurface::QueryInterface(_GUID const &iid, void **ppvObj) {
  UNIMPLEMENTED();
}

CDirect3DSurface::Release() { UNIMPLEMENTED(); }

CDirect3DSurface::GetDesc(_D3DSURFACE_DESC *pDesc) { UNIMPLEMENTED(); }

CDirect3DSurface::LockRect(_D3DLOCKED_RECT *pLockedRect, tagRECT const *pRect,
                           unsigned long Flags) {
  UNIMPLEMENTED();
}

CDirect3DSurface::UnlockRect() { UNIMPLEMENTED(); }

CDirect3DSurface::CreateOpenGLSurfaceObject() { UNIMPLEMENTED(); }

CDirect3DSurface::CDirect3DSurface(
    SurfaceType s s, unsigned long CubemapID CubemapID,
    unsigned int Level Level, unsigned int Width Width,
    unsigned int Height Height, _D3DFORMAT Format Format,
    void *pSurfaceMemory pSurfaceMemory,
    COpenGLTexture *pOpenGLTextureInfo pOpenGLTextureInfo) {
  UNIMPLEMENTED();
}

CDirect3DSurface::IsDirty() const { UNIMPLEMENTED(); }

CDirect3DSurface::RecreateSurface() { UNIMPLEMENTED(); }

CDirect3DSurface::UpdateOpenGLSurfaceObject(bool bRecreateSurface) {
  UNIMPLEMENTED();
}
