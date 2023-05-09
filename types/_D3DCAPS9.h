#include <stdint.h>

struct _D3DCAPS9
{
	int32_t DeviceType;
	int32_t AdapterOrdinal;
	int32_t Caps;
	int32_t Caps2;
	int32_t Caps3;
	int32_t PresentationIntervals;
	int32_t CursorCaps;
	int32_t DevCaps;
	int32_t PrimitiveMiscCaps;
	int32_t RasterCaps;
	int32_t ZCmpCaps;
	int32_t SrcBlendCaps;
	int32_t DestBlendCaps;
	int32_t AlphaCmpCaps;
	int32_t ShadeCaps;
	int32_t TextureCaps;
	int32_t TextureFilterCaps;
	int32_t CubeTextureFilterCaps;
	int32_t VolumeTextureFilterCaps;
	int32_t TextureAddressCaps;
	int32_t VolumeTextureAddressCaps;
	int32_t LineCaps;
	int32_t MaxTextureWidth;
	int32_t MaxTextureHeight;
	int32_t MaxVolumeExtent;
	int32_t MaxTextureRepeat;
	int32_t MaxTextureAspectRatio;
	int32_t MaxAnisotropy;
	int32_t MaxVertexW;
	int32_t GuardBandLeft;
	int32_t GuardBandTop;
	int32_t GuardBandRight;
	int32_t GuardBandBottom;
	int32_t ExtentsAdjust;
	int32_t StencilCaps;
	int32_t FVFCaps;
	int32_t TextureOpCaps;
	int32_t MaxTextureBlendStages;
	int32_t MaxSimultaneousTextures;
	int32_t VertexProcessingCaps;
	int32_t MaxActiveLights;
	int32_t MaxUserClipPlanes;
	int32_t MaxVertexBlendMatrices;
	int32_t MaxVertexBlendMatrixIndex;
	int32_t MaxPointSize;
	int32_t MaxPrimitiveCount;
	int32_t MaxVertexIndex;
	int32_t MaxStreams;
	int32_t MaxStreamStride;
	int32_t VertexShaderVersion;
	int32_t MaxVertexShaderConst;
	int32_t PixelShaderVersion;
	int32_t PixelShader1xMaxValue;
	int32_t DevCaps2;
	int32_t MaxNpatchTessellationLevel;
	int32_t Reserved5;
	int32_t MasterAdapterOrdinal;
	int32_t AdapterOrdinalInGroup;
	int32_t NumberOfAdaptersInGroup;
	int32_t DeclTypes;
	int32_t NumSimultaneousRTs;
	int32_t StretchRectFilterCaps;
	D3DVSHADERCAPS2_0 VS20Caps;
	D3DPSHADERCAPS2_0 PS20Caps;
	int32_t VertexTextureFilterCaps;
	int32_t MaxVShaderInstructionsExecuted;
	int32_t MaxPShaderInstructionsExecuted;
	int32_t MaxVertexShader30InstructionSlots;
	int32_t MaxPixelShader30InstructionSlots;
};

