COpenGLTexture::UpdateOpenGLSurfaces() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::AddRef() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::Release() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GetDevice(IDirect3DDevice9 **ppDevice) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::SetPrivateData(_GUID const &refguid, void const *pData,
                                     unsigned long SizeOfData,
                                     unsigned long Flags) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::GetPrivateData(_GUID const &refguid, void *pData,
                                     unsigned long *pSizeOfData) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::FreePrivateData(_GUID const &refguid) { UNIMPLEMENTED(); }

CDirect3DCubeTexture::SetPriority(unsigned long PriorityNew) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::GetPriority() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::PreLoad() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GetType() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::SetLOD(unsigned long LODNew) { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GetLOD() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GetLevelCount() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::SetAutoGenFilterType(_D3DTEXTUREFILTERTYPE FilterType) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::GetAutoGenFilterType() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GenerateMipSubLevels() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::QueryInterface(_GUID const &iid, void **ppvObj) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::AddDirtyRect(_D3DCUBEMAP_FACES FaceType,
                                   tagRECT const *pDirtyRect) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::UpdateOpenGLSurfaces(bool RecreateTextureData) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::GetLevelDesc(unsigned int Level,
                                   _D3DSURFACE_DESC *pDesc) {
  UNIMPLEMENTED();
}

COpenGLTexture::~COpenGLTexture() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::~CDirect3DCubeTexture() { UNIMPLEMENTED(); }

CDirect3DCubeTexture::GetCubeMapSurface(_D3DCUBEMAP_FACES FaceType,
                                        unsigned int Level,
                                        IDirect3DSurface9 **ppCubeMapSurface) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::LockRect(_D3DCUBEMAP_FACES FaceType, unsigned int Level,
                               _D3DLOCKED_RECT *pLockedRect,
                               tagRECT const *pRect, unsigned long Flags) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::UnlockRect(_D3DCUBEMAP_FACES FaceType,
                                 unsigned int Level) {
  UNIMPLEMENTED();
}

std::vector<CDirect3DSurface *, std::allocator<CDirect3DSurface *>>::
    _M_fill_insert(__gnu_cxx::__normal_iterator<
                       CDirect3DSurface * * __position,
                       std::vector<CDirect3DSurface * __n,
                                   std::allocator<CDirect3DSurface *>>>
                       __x,
                   unsigned long, CDirect3DSurface *const &) {
  UNIMPLEMENTED();
}

std::vector<CDirect3DSurface *, std::allocator<CDirect3DSurface *>>::erase(
    __gnu_cxx::__normal_iterator<
        CDirect3DSurface * * __first,
        std::vector<CDirect3DSurface * __last,
                    std::allocator<CDirect3DSurface *>>>,
    __gnu_cxx::__normal_iterator<
        CDirect3DSurface **,
        std::vector<CDirect3DSurface *, std::allocator<CDirect3DSurface *>>>) {
  UNIMPLEMENTED();
}

CDirect3DCubeTexture::CDirect3DCubeTexture(unsigned int EdgeLength EdgeLength,
                                           unsigned int Levels Levels,
                                           unsigned long Usage Usage,
                                           _D3DFORMAT Format Format) {
  UNIMPLEMENTED();
}
