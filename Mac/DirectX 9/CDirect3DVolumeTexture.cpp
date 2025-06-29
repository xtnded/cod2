CDirect3DVolume::GetDevice(IDirect3DDevice9 **) { UNIMPLEMENTED(); }

CDirect3DVolume::SetPrivateData(_GUID const &, void const *, unsigned long,
                                unsigned long) {
  UNIMPLEMENTED();
}

CDirect3DVolume::GetPrivateData(_GUID const &refguid, void *pData,
                                unsigned long *pSizeOfData) {
  UNIMPLEMENTED();
}

CDirect3DVolume::FreePrivateData(_GUID const &refguid) { UNIMPLEMENTED(); }

CDirect3DVolume::GetContainer(_GUID const &riid, void **ppContainer) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::GetDevice(IDirect3DDevice9 **ppDevice) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::SetPrivateData(_GUID const &, void const *,
                                       unsigned long, unsigned long) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::GetPrivateData(_GUID const &refguid, void *pData,
                                       unsigned long *pSizeOfData) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::FreePrivateData(_GUID const &refguid) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::SetPriority(unsigned long PriorityNew) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::GetPriority() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::PreLoad() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::GetType() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::SetLOD(unsigned long LODNew) { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::GetLOD() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::GetLevelCount() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::SetAutoGenFilterType(_D3DTEXTUREFILTERTYPE FilterType) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::GetAutoGenFilterType() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::GenerateMipSubLevels() { UNIMPLEMENTED(); }

CDirect3DVolume::AddRef() { UNIMPLEMENTED(); }

CDirect3DVolume::~CDirect3DVolume() { UNIMPLEMENTED(); }

CDirect3DVolume::QueryInterface(_GUID const &iid, void **ppvObj) {
  UNIMPLEMENTED();
}

CDirect3DVolume::Release() { UNIMPLEMENTED(); }

CDirect3DVolume::GetDesc(_D3DVOLUME_DESC *pDesc) { UNIMPLEMENTED(); }

CDirect3DVolume::UnlockBox() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::AddRef() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::QueryInterface(_GUID const &iid, void **ppvObj) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::Release() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::GetLevelDesc(unsigned int Level,
                                     _D3DVOLUME_DESC *pDesc) {
  UNIMPLEMENTED();
}

CDirect3DVolume::LockBox(_D3DLOCKED_BOX *pLockedVolume, _D3DBOX const *pBox,
                         unsigned long Flags) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::AddDirtyBox(_D3DBOX const *pDirtyBox) {
  UNIMPLEMENTED();
}

CDirect3DVolume::CreateOpenGLSurfaceObject() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::UnlockBox(unsigned int Level) { UNIMPLEMENTED(); }

CDirect3DVolume::IsDirty() const { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::~CDirect3DVolumeTexture() { UNIMPLEMENTED(); }

CDirect3DVolumeTexture::LockBox(unsigned int Level,
                                _D3DLOCKED_BOX *pLockedVolume,
                                _D3DBOX const *pBox, unsigned long Flags) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::GetVolumeLevel(unsigned int Level,
                                       IDirect3DVolume9 **ppVolumeSurface) {
  UNIMPLEMENTED();
}

CDirect3DVolume::UpdateOpenGLSurfaceObject(bool bRecreateSurface) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::UpdateOpenGLSurfaces(bool RecreateTextureData) {
  UNIMPLEMENTED();
}

std::vector<CDirect3DVolume *, std::allocator<CDirect3DVolume *>>::
    _M_insert_aux(__gnu_cxx::__normal_iterator<
                      CDirect3DVolume * * __position,
                      std::vector<CDirect3DVolume * __x,
                                  std::allocator<CDirect3DVolume *>>>,
                  CDirect3DVolume *const &) {
  UNIMPLEMENTED();
}

std::vector<CDirect3DVolume *, std::allocator<CDirect3DVolume *>>::reserve(
    unsigned long __n) {
  UNIMPLEMENTED();
}

CDirect3DVolumeTexture::CDirect3DVolumeTexture(unsigned int Width Width,
                                               unsigned int Height Height,
                                               unsigned int Depth Depth,
                                               unsigned int Levels Levels,
                                               unsigned long Usage Usage,
                                               _D3DFORMAT Format Format) {
  UNIMPLEMENTED();
}
