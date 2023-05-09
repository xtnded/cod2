#include <stdint.h>

struct weaponInfo_s
{
	int32_t viewModelDObj;
	char viewModelAnimRates[92];
	char handModel[64];
	int32_t iPrevAnim;
	int32_t tree;
	int32_t registered;
	int32_t item;
	int32_t pszTranslatedDisplayName;
	int32_t pszTranslatedModename;
	int32_t pszTranslatedAIOverlayDescription;
	int32_t worldSurfModel;
	int32_t viewFlashEffect;
	int32_t worldFlashEffect;
	char weaponMidpoint[12];
	int32_t missileSound;
	int32_t pullbackSound;
	int32_t flashSound;
	int32_t flashSoundPlayer;
	int32_t lastShotSound;
	int32_t lastShotSoundPlayer;
	int32_t meleeSwipeSound;
	int32_t rechamberSound;
	int32_t rechamberSoundPlayer;
	int32_t reloadSound;
	int32_t reloadSoundPlayer;
	int32_t reloadEmptySound;
	int32_t reloadEmptySoundPlayer;
	int32_t reloadStartSound;
	int32_t reloadStartSoundPlayer;
	int32_t reloadEndSound;
	int32_t reloadEndSoundPlayer;
	int32_t raiseSound;
	int32_t altSwitchSound;
	int32_t putawaySound;
	char noteTrackSound[16];
	int32_t ammoIcon;
	int32_t hHudIcon;
	int32_t hModeIcon;
	int32_t missileSurfModel;
	int32_t missileTrailFunc;
	int32_t missileDlight;
	char missileDlightColor[12];
	int32_t missileRenderfx;
	int32_t shellEjectEffect;
	int32_t lastShotEjectEffect;
	int32_t projExplosionEffect;
	int32_t projExplosionSound;
	int32_t projTrailEffect;
	int32_t trailRadius;
	int32_t wiTrailTime;
	int32_t hReticleCenter;
	int32_t hReticleSide;
	int32_t hADSOverlay;
	char vPositionOrg[24];
	char vPositionAng[24];
};

