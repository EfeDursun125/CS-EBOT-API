#include "main.h"
#include "../sdk/hlsdk/extdll.h"

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#define GetProcAddress dlsym
__asm__(".symver dlsym,dlsym@GLIBC_2.0");
__asm__(".symver dlopen,dlopen@GLIBC_2.0");
#endif

typedef bool(*_EBOT) (void);
_EBOT Amxx_EBOT{nullptr};

typedef float(*_EBotVersion) (void);
_EBotVersion Amxx_EBotVersion{nullptr};

typedef int(*_IsEBot) (int);
_IsEBot Amxx_IsEBot{nullptr};

typedef int(*_EBotSeesEnemy) (int);
_EBotSeesEnemy Amxx_EBotSeesEnemy{nullptr};

typedef int(*_EBotSeesEntity) (int);
_EBotSeesEntity Amxx_EBotSeesEntity{nullptr};

typedef int(*_EBotSeesFriend) (int);
_EBotSeesFriend Amxx_EBotSeesFriend{nullptr};

typedef int(*_EBotGetEnemy) (int);
_EBotGetEnemy Amxx_EBotGetEnemy{nullptr};

typedef int(*_EBotGetEntity) (int);
_EBotGetEntity Amxx_EBotGetEntity{nullptr};

typedef int(*_EBotGetFriend) (int);
_EBotGetFriend Amxx_EBotGetFriend{nullptr};

typedef int(*_EBotSetEnemy) (int, int);
_EBotSetEnemy Amxx_EBotSetEnemy{nullptr};

typedef int(*_EBotSetEntity) (int, int);
_EBotSetEntity Amxx_EBotSetEntity{nullptr};

typedef int(*_EBotSetFriend) (int, int);
_EBotSetFriend Amxx_EBotSetFriend{nullptr};

typedef float(*_EBotGetEnemyDistance) (int);
_EBotGetEnemyDistance Amxx_EBotGetEnemyDistance{nullptr};

typedef float(*_EBotGetEntityDistance) (int);
_EBotGetEntityDistance Amxx_EBotGetEntityDistance{nullptr};

typedef float(*_EBotGetFriendDistance) (int);
_EBotGetFriendDistance Amxx_EBotGetFriendDistance{nullptr};

typedef int(*_EbotSetEntityAction) (int, int, int);
_EbotSetEntityAction Amxx_EbotSetEntityAction{nullptr};

typedef void(*_EBotSetLookAt) (int, Vector, Vector);
_EBotSetLookAt Amxx_EBotSetLookAt{nullptr};

typedef int(*_EBotGetCurrentProcess) (int);
_EBotGetCurrentProcess Amxx_EBotGetCurrentProcess{nullptr};

typedef int(*_EBotGetRememberedProcess) (int);
_EBotGetRememberedProcess Amxx_EBotGetRememberedProcess{nullptr};

typedef float(*_EBotGetCurrentProcessTime) (int);
_EBotGetCurrentProcessTime Amxx_EBotGetCurrentProcessTime{nullptr};

typedef float(*_EBotGetRememberedProcessTime) (int);
_EBotGetRememberedProcessTime Amxx_EBotGetRememberedProcessTime{nullptr};

typedef int(*_EBotSetCurrentProcess) (int, int, int, float);
_EBotSetCurrentProcess Amxx_EBotSetCurrentProcess{nullptr};

typedef void(*_EBotForceCurrentProcess) (int, int);
_EBotForceCurrentProcess Amxx_EBotForceCurrentProcess{nullptr};

typedef void(*_EBotFinishCurrentProcess) (int);
_EBotFinishCurrentProcess Amxx_EBotFinishCurrentProcess{nullptr};

typedef int(*_EBotOverrideCurrentProcess) (int, int, float, int, int, int);
_EBotOverrideCurrentProcess Amxx_EBotOverrideCurrentProcess{nullptr};

typedef int(*_EBotGetOverrideProcessID) (int);
_EBotGetOverrideProcessID Amxx_EBotGetOverrideProcessID{nullptr};

typedef int(*_EBotHasOverrideChecks) (int);
_EBotHasOverrideChecks Amxx_EBotHasOverrideChecks{nullptr};

typedef int(*_EBotHasOverrideLookAI) (int);
_EBotHasOverrideLookAI Amxx_EBotHasOverrideLookAI{nullptr};

typedef void(*_EBotForceFireWeapon) (int, float);
_EBotForceFireWeapon Amxx_EBotForceFireWeapon{nullptr};

typedef void(*_EBotLookAtAround) (int);
_EBotLookAtAround Amxx_EBotLookAtAround{nullptr};

typedef void(*_EBotCallNewRound) (int);
_EBotCallNewRound Amxx_EBotCallNewRound{nullptr};

typedef void(*_EBotSetIgnoreClient) (int, int);
_EBotSetIgnoreClient Amxx_EBotSetIgnoreClient{nullptr};

typedef int(*_EBotIsClientIgnored) (int);
_EBotIsClientIgnored Amxx_EBotIsClientIgnored{nullptr};

typedef int(*_EBotGetClientWaypoint) (int);
_EBotGetClientWaypoint Amxx_EBotGetClientWaypoint{nullptr};

typedef int(*_EBotIsClientOwner) (int);
_EBotIsClientOwner Amxx_EBotIsClientOwner{nullptr};

typedef int(*_EBotIsClientInGame) (int);
_EBotIsClientInGame Amxx_EBotIsClientInGame{nullptr};

typedef int(*_EBotIsClientAlive) (int);
_EBotIsClientAlive Amxx_EBotIsClientAlive{nullptr};

typedef int(*_EBotIsEnemyReachable) (int);
_EBotIsEnemyReachable Amxx_EBotIsEnemyReachable{nullptr};

typedef void(*_EBotSetEnemyReachable) (int, int);
_EBotSetEnemyReachable Amxx_EBotSetEnemyReachable{nullptr};

typedef int(*_EBotIsStuck) (int);
_EBotIsStuck Amxx_EBotIsStuck{nullptr};

typedef float(*_EBotGetStuckTime) (int);
_EBotGetStuckTime Amxx_EBotGetStuckTime{nullptr};

typedef int(*_EBotGetAmmo) (int, int);
_EBotGetAmmo Amxx_EBotGetAmmo{nullptr};

typedef int(*_EBotGetAmmoInClip) (int);
_EBotGetAmmoInClip Amxx_EBotGetAmmoInClip{nullptr};

typedef int(*_EBotGetCurrentWeapon) (int);
_EBotGetCurrentWeapon Amxx_EBotGetCurrentWeapon{nullptr};

typedef void(*_EBotSelectKnife) (int);
_EBotSelectKnife Amxx_EBotSelectKnife{nullptr};

typedef void(*_EBotBestWeapon) (int);
_EBotBestWeapon Amxx_EBotBestWeapon{nullptr};

typedef int(*_EBotIsSlowThink) (int);
_EBotIsSlowThink Amxx_EBotIsSlowThink{nullptr};

typedef void(*_EBotSetSlowThink) (int, int);
_EBotSetSlowThink Amxx_EBotSetSlowThink{nullptr};

typedef int(*_EBotIsZombie) (int);
_EBotIsZombie Amxx_EBotIsZombie{nullptr};

typedef void(*_EBotSetZombie) (int, int);
_EBotSetZombie Amxx_EBotSetZombie{nullptr};

typedef int(*_EBotIsAlive) (int);
_EBotIsAlive Amxx_EBotIsAlive{nullptr};

typedef void(*_EBotSetAlive) (int, int);
_EBotSetAlive Amxx_EBotSetAlive{nullptr};

typedef int(*_EBotGetWaypointNumer) (void);
_EBotGetWaypointNumer Amxx_EBotGetWaypointNumer{nullptr};

typedef void(*_EBotGetWaypointOrigin) (int, Vector**);
_EBotGetWaypointOrigin Amxx_EBotGetWaypointOrigin{nullptr};

typedef void(*_EBotGetWaypointFlags) (int, int**);
_EBotGetWaypointFlags Amxx_EBotGetWaypointFlags{nullptr};

typedef void(*_EBotGetWaypointRadius) (int, int**);
_EBotGetWaypointRadius Amxx_EBotGetWaypointRadius{nullptr};

typedef void(*_EBotGetWaypointMesh) (int, int**);
_EBotGetWaypointMesh Amxx_EBotGetWaypointMesh{nullptr};

typedef void(*_EBotGetWaypointConnections) (int, int**, int);
_EBotGetWaypointConnections Amxx_EBotGetWaypointConnections{nullptr};

typedef void(*_EBotGetWaypointConnectionFlags) (int, int**, int);
_EBotGetWaypointConnectionFlags Amxx_EBotGetWaypointConnectionFlags{nullptr};

typedef void(*_EBotGetWaypointGravity) (int, int**);
_EBotGetWaypointGravity Amxx_EBotGetWaypointGravity{nullptr};

typedef void(*_EBotMoveTo) (int, Vector, int);
_EBotMoveTo Amxx_EBotMoveTo{nullptr};

typedef void(*_EBotMoveOut) (int, Vector, int);
_EBotMoveOut Amxx_EBotMoveOut{nullptr};

typedef void(*_EBotFindPathTo) (int, int);
_EBotFindPathTo Amxx_EBotFindPathTo{nullptr};

typedef void(*_EBotFindShortestPathTo) (int, int);
_EBotFindShortestPathTo Amxx_EBotFindShortestPathTo{nullptr};

typedef int(*_EBotGetCurrentWaypoint) (int);
_EBotGetCurrentWaypoint Amxx_EBotGetCurrentWaypoint{nullptr};

typedef int(*_EBotGetGoalWaypoint) (int);
_EBotGetGoalWaypoint Amxx_EBotGetGoalWaypoint{nullptr};

typedef void(*_EBotSetCurrentWaypoint) (int, int);
_EBotSetCurrentWaypoint Amxx_EBotSetCurrentWaypoint{nullptr};

typedef void(*_EBotSetGoalWaypoint) (int, int);
_EBotSetGoalWaypoint Amxx_EBotSetGoalWaypoint{nullptr};

typedef int(*_EBotGetCampWaypoint) (int);
_EBotGetCampWaypoint Amxx_EBotGetCampWaypoint{nullptr};

typedef int(*_EBotGetMeshWaypoint) (int);
_EBotGetMeshWaypoint Amxx_EBotGetMeshWaypoint{nullptr};

typedef int(*_EBotCanFollowPath) (int);
_EBotCanFollowPath Amxx_EBotCanFollowPath{nullptr};

typedef void(*_EBotFollowPath) (int);
_EBotFollowPath Amxx_EBotFollowPath{nullptr};

typedef void(*_EBotStopFollowingPath) (int);
_EBotStopFollowingPath Amxx_EBotStopFollowingPath{nullptr};

typedef void(*_EBotShiftPath) (int);
_EBotShiftPath Amxx_EBotShiftPath{nullptr};

typedef void(*_EBotClearPath) (int);
_EBotClearPath Amxx_EBotClearPath{nullptr};

typedef int(*_EBotGetPath) (int, int);
_EBotGetPath Amxx_EBotGetPath{nullptr};

typedef int(*_EBotGetPathLength) (int);
_EBotGetPathLength Amxx_EBotGetPathLength{nullptr};

typedef int(*_EBotIsNodeReachable) (Vector, Vector);
_EBotIsNodeReachable Amxx_EBotIsNodeReachable{nullptr};

typedef int(*_EBotFindNearestWaypoint) (Vector, float);
_EBotFindNearestWaypoint Amxx_EBotFindNearestWaypoint{nullptr};

typedef int(*_EBotFindFarestWaypoint) (Vector, float);
_EBotFindFarestWaypoint Amxx_EBotFindFarestWaypoint{nullptr};

typedef int(*_EBotFindNearestWaypointToEntity) (Vector, float, int);
_EBotFindNearestWaypointToEntity Amxx_EBotFindNearestWaypointToEntity{nullptr};

typedef float(*_EBotGetWaypointDistance) (int, int);
_EBotGetWaypointDistance Amxx_EBotGetWaypointDistance{nullptr};

typedef int(*_EBotIsValidWaypoint) (int);
_EBotIsValidWaypoint Amxx_EBotIsValidWaypoint{nullptr};

typedef int(*_EBotIsMatrixReady) (void);
_EBotIsMatrixReady Amxx_EBotIsMatrixReady{nullptr};

typedef int(*_EBotIsCamping) (int);
_EBotIsCamping Amxx_EBotIsCamping{nullptr};

typedef int(*_EBotRegisterEnemyEntity) (int);
_EBotRegisterEnemyEntity Amxx_EBotRegisterEnemyEntity{nullptr};

typedef int(*_EBotRemoveEnemyEntity) (int);
_EBotRemoveEnemyEntity Amxx_EBotRemoveEnemyEntity{nullptr};

typedef void(*_EBotClearRegisteredEnemyEntities) (void);
_EBotClearRegisteredEnemyEntities Amxx_EBotClearRegisteredEnemyEntities{nullptr};

int LogToFile(const char *szLogText, ...)
{
	char fileHere[512];
	sprintf(fileHere, "ebot_amxx.txt");

	FILE *fp;

	fp = fopen(fileHere, "a");
	if (fp)
	{
		va_list vArgptr;
		char szText[1024];

		va_start(vArgptr, szLogText);
		vsprintf(szText, szLogText, vArgptr);
		va_end(vArgptr);

		fprintf(fp, " %s\n", szText);
		fclose(fp);
		return 1;
	}

	return 0;
}

void LoadEBot(void)
{
#ifdef WIN32
	const HMODULE dll = GetModuleHandle("ebot.dll");
#else
	void* dll = dlopen("ebot.so", RTLD_LAZY);
#endif

	if (!dll)
	{
#ifdef WIN32
		LogToFile("ebot.dll is not found!");
#else
		LogToFile("ebot.so is not found!");
#endif
		return;
	}

	Amxx_EBOT = (_EBOT)GetProcAddress(dll, "Amxx_RunEBot");
	if (!Amxx_EBOT)
	{
		LogToFile("ebot does not function correctly!");
		return;
	}

	Amxx_EBOT();
	Amxx_EBotVersion = (_EBotVersion)GetProcAddress(dll, "Amxx_EBotVersion");
	Amxx_IsEBot = (_IsEBot)GetProcAddress(dll, "Amxx_IsEBot");
	Amxx_EBotSeesEnemy = (_EBotSeesEnemy)GetProcAddress(dll, "Amxx_EBotSeesEnemy");
	Amxx_EBotSeesEntity = (_EBotSeesEntity)GetProcAddress(dll, "Amxx_EBotSeesEntity");
	Amxx_EBotSeesFriend = (_EBotSeesFriend)GetProcAddress(dll, "Amxx_EBotSeesFriend");
	Amxx_EBotGetEnemy = (_EBotGetEnemy)GetProcAddress(dll, "Amxx_EBotGetEnemy");
	Amxx_EBotGetEntity = (_EBotGetEntity)GetProcAddress(dll, "Amxx_EBotGetEntity");
	Amxx_EBotGetFriend = (_EBotGetFriend)GetProcAddress(dll, "Amxx_EBotGetFriend");
	Amxx_EBotSetEnemy = (_EBotSetEnemy)GetProcAddress(dll, "Amxx_EBotSetEnemy");
	Amxx_EBotSetEntity = (_EBotSetEntity)GetProcAddress(dll, "Amxx_EBotSetEntity");
	Amxx_EBotSetFriend = (_EBotSetFriend)GetProcAddress(dll, "Amxx_EBotSetFriend");
	Amxx_EBotGetEnemyDistance = (_EBotGetEnemyDistance)GetProcAddress(dll, "Amxx_EBotGetEnemyDistance");
	Amxx_EBotGetEntityDistance = (_EBotGetEntityDistance)GetProcAddress(dll, "Amxx_EBotGetEntityDistance");
	Amxx_EBotGetFriendDistance = (_EBotGetFriendDistance)GetProcAddress(dll, "Amxx_EBotGetFriendDistance");
	Amxx_EbotSetEntityAction = (_EbotSetEntityAction)GetProcAddress(dll, "Amxx_EbotSetEntityAction");
	Amxx_EBotSetLookAt = (_EBotSetLookAt)GetProcAddress(dll, "Amxx_EBotSetLookAt");
	Amxx_EBotGetCurrentProcess = (_EBotGetCurrentProcess)GetProcAddress(dll, "Amxx_EBotGetCurrentProcess");
	Amxx_EBotGetRememberedProcess = (_EBotGetRememberedProcess)GetProcAddress(dll, "Amxx_EBotGetRememberedProcess");
	Amxx_EBotGetCurrentProcessTime = (_EBotGetCurrentProcessTime)GetProcAddress(dll, "Amxx_EBotGetCurrentProcessTime");
	Amxx_EBotGetRememberedProcessTime = (_EBotGetRememberedProcessTime)GetProcAddress(dll, "Amxx_EBotGetRememberedProcessTime");
	Amxx_EBotSetCurrentProcess = (_EBotSetCurrentProcess)GetProcAddress(dll, "Amxx_EBotSetCurrentProcess");
	Amxx_EBotForceCurrentProcess = (_EBotForceCurrentProcess)GetProcAddress(dll, "Amxx_EBotForceCurrentProcess");
	Amxx_EBotFinishCurrentProcess = (_EBotFinishCurrentProcess)GetProcAddress(dll, "Amxx_EBotFinishCurrentProcess");
	Amxx_EBotOverrideCurrentProcess = (_EBotOverrideCurrentProcess)GetProcAddress(dll, "Amxx_EBotOverrideCurrentProcess");
	Amxx_EBotGetOverrideProcessID = (_EBotGetOverrideProcessID)GetProcAddress(dll, "Amxx_EBotGetOverrideProcessID");
	Amxx_EBotHasOverrideChecks = (_EBotHasOverrideChecks)GetProcAddress(dll, "Amxx_EBotHasOverrideChecks");
	Amxx_EBotHasOverrideLookAI = (_EBotHasOverrideLookAI)GetProcAddress(dll, "Amxx_EBotHasOverrideLookAI");
	Amxx_EBotForceFireWeapon = (_EBotForceFireWeapon)GetProcAddress(dll, "Amxx_EBotForceFireWeapon");
	Amxx_EBotLookAtAround = (_EBotLookAtAround)GetProcAddress(dll, "Amxx_EBotLookAtAround");
	Amxx_EBotCallNewRound = (_EBotCallNewRound)GetProcAddress(dll, "Amxx_EBotCallNewRound");
	Amxx_EBotSetIgnoreClient = (_EBotSetIgnoreClient)GetProcAddress(dll, "Amxx_EBotSetIgnoreClient");
	Amxx_EBotIsClientIgnored = (_EBotIsClientIgnored)GetProcAddress(dll, "Amxx_EBotIsClientIgnored");
	Amxx_EBotGetClientWaypoint = (_EBotGetClientWaypoint)GetProcAddress(dll, "Amxx_EBotGetClientWaypoint");
	Amxx_EBotIsClientOwner = (_EBotIsClientOwner)GetProcAddress(dll, "Amxx_EBotIsClientOwner");
	Amxx_EBotIsClientInGame = (_EBotIsClientInGame)GetProcAddress(dll, "Amxx_EBotIsClientInGame");
	Amxx_EBotIsClientAlive = (_EBotIsClientAlive)GetProcAddress(dll, "Amxx_EBotIsClientAlive");
	Amxx_EBotIsEnemyReachable = (_EBotIsEnemyReachable)GetProcAddress(dll, "Amxx_EBotIsEnemyReachable");
	Amxx_EBotSetEnemyReachable = (_EBotSetEnemyReachable)GetProcAddress(dll, "Amxx_EBotSetEnemyReachable");
	Amxx_EBotIsStuck = (_EBotIsStuck)GetProcAddress(dll, "Amxx_EBotIsStuck");
	Amxx_EBotGetStuckTime = (_EBotGetStuckTime)GetProcAddress(dll, "Amxx_EBotGetStuckTime");
	Amxx_EBotGetAmmo = (_EBotGetAmmo)GetProcAddress(dll, "Amxx_EBotGetAmmo");
	Amxx_EBotGetAmmoInClip = (_EBotGetAmmoInClip)GetProcAddress(dll, "Amxx_EBotGetAmmoInClip");
	Amxx_EBotGetCurrentWeapon = (_EBotGetCurrentWeapon)GetProcAddress(dll, "Amxx_EBotGetCurrentWeapon");
	Amxx_EBotSelectKnife = (_EBotSelectKnife)GetProcAddress(dll, "Amxx_EBotSelectKnife");
	Amxx_EBotBestWeapon = (_EBotBestWeapon)GetProcAddress(dll, "Amxx_EBotBestWeapon");
	Amxx_EBotIsSlowThink = (_EBotIsSlowThink)GetProcAddress(dll, "Amxx_EBotIsSlowThink");
	Amxx_EBotSetSlowThink = (_EBotSetSlowThink)GetProcAddress(dll, "Amxx_EBotSetSlowThink");
	Amxx_EBotIsZombie = (_EBotIsZombie)GetProcAddress(dll, "Amxx_EBotIsZombie");
	Amxx_EBotIsAlive = (_EBotIsAlive)GetProcAddress(dll, "Amxx_EBotIsAlive");
	Amxx_EBotSetAlive = (_EBotSetAlive)GetProcAddress(dll, "Amxx_EBotSetAlive");
	Amxx_EBotGetWaypointNumer = (_EBotGetWaypointNumer)GetProcAddress(dll, "Amxx_EBotGetWaypointNumer");
	Amxx_EBotGetWaypointOrigin = (_EBotGetWaypointOrigin)GetProcAddress(dll, "Amxx_EBotGetWaypointOrigin");
	Amxx_EBotGetWaypointFlags = (_EBotGetWaypointFlags)GetProcAddress(dll, "Amxx_EBotGetWaypointFlags");
	Amxx_EBotGetWaypointRadius = (_EBotGetWaypointRadius)GetProcAddress(dll, "Amxx_EBotGetWaypointRadius");
	Amxx_EBotGetWaypointMesh = (_EBotGetWaypointMesh)GetProcAddress(dll, "Amxx_EBotGetWaypointMesh");
	Amxx_EBotGetWaypointConnections = (_EBotGetWaypointConnections)GetProcAddress(dll, "Amxx_EBotGetWaypointConnections");
	Amxx_EBotGetWaypointConnectionFlags = (_EBotGetWaypointConnectionFlags)GetProcAddress(dll, "Amxx_EBotGetWaypointConnectionFlags");
	Amxx_EBotGetWaypointGravity = (_EBotGetWaypointGravity)GetProcAddress(dll, "Amxx_EBotGetWaypointGravity");
	Amxx_EBotMoveTo = (_EBotMoveTo)GetProcAddress(dll, "Amxx_EBotMoveTo");
	Amxx_EBotMoveOut = (_EBotMoveOut)GetProcAddress(dll, "Amxx_EBotMoveOut");
	Amxx_EBotFindPathTo = (_EBotFindPathTo)GetProcAddress(dll, "Amxx_EBotFindPathTo");
	Amxx_EBotFindShortestPathTo = (_EBotFindShortestPathTo)GetProcAddress(dll, "Amxx_EBotFindShortestPathTo");
	Amxx_EBotGetCurrentWaypoint = (_EBotGetCurrentWaypoint)GetProcAddress(dll, "Amxx_EBotGetCurrentWaypoint");
	Amxx_EBotGetGoalWaypoint = (_EBotGetGoalWaypoint)GetProcAddress(dll, "Amxx_EBotGetGoalWaypoint");
	Amxx_EBotSetCurrentWaypoint = (_EBotSetCurrentWaypoint)GetProcAddress(dll, "Amxx_EBotSetCurrentWaypoint");
	Amxx_EBotSetGoalWaypoint = (_EBotSetGoalWaypoint)GetProcAddress(dll, "Amxx_EBotSetGoalWaypoint");
	Amxx_EBotGetCampWaypoint = (_EBotGetCampWaypoint)GetProcAddress(dll, "Amxx_EBotGetCampWaypoint");
	Amxx_EBotGetMeshWaypoint = (_EBotGetMeshWaypoint)GetProcAddress(dll, "Amxx_EBotGetMeshWaypoint");
	Amxx_EBotCanFollowPath = (_EBotCanFollowPath)GetProcAddress(dll, "Amxx_EBotCanFollowPath");
	Amxx_EBotFollowPath = (_EBotFollowPath)GetProcAddress(dll, "Amxx_EBotFollowPath");
	Amxx_EBotStopFollowingPath = (_EBotStopFollowingPath)GetProcAddress(dll, "Amxx_EBotStopFollowingPath");
	Amxx_EBotShiftPath = (_EBotShiftPath)GetProcAddress(dll, "Amxx_EBotShiftPath");
	Amxx_EBotClearPath = (_EBotClearPath)GetProcAddress(dll, "Amxx_EBotClearPath");
	Amxx_EBotGetPath = (_EBotGetPath)GetProcAddress(dll, "Amxx_EBotGetPath");
	Amxx_EBotGetPathLength = (_EBotGetPathLength)GetProcAddress(dll, "Amxx_EBotGetPathLength");
	Amxx_EBotIsNodeReachable = (_EBotIsNodeReachable)GetProcAddress(dll, "Amxx_EBotIsNodeReachable");
	Amxx_EBotFindNearestWaypoint = (_EBotFindNearestWaypoint)GetProcAddress(dll, "Amxx_EBotFindNearestWaypoint");
	Amxx_EBotFindFarestWaypoint = (_EBotFindFarestWaypoint)GetProcAddress(dll, "Amxx_EBotFindFarestWaypoint");
	Amxx_EBotFindNearestWaypointToEntity = (_EBotFindNearestWaypointToEntity)GetProcAddress(dll, "Amxx_EBotFindNearestWaypointToEntity");
	Amxx_EBotGetWaypointDistance = (_EBotGetWaypointDistance)GetProcAddress(dll, "Amxx_EBotGetWaypointDistance");
	Amxx_EBotIsValidWaypoint = (_EBotIsValidWaypoint)GetProcAddress(dll, "Amxx_EBotIsValidWaypoint");
	Amxx_EBotIsMatrixReady = (_EBotIsMatrixReady)GetProcAddress(dll, "Amxx_EBotIsMatrixReady");
	Amxx_EBotIsCamping = (_EBotIsCamping)GetProcAddress(dll, "Amxx_EBotIsCamping");
	Amxx_EBotRegisterEnemyEntity = (_EBotRegisterEnemyEntity)GetProcAddress(dll, "Amxx_EBotRegisterEnemyEntity");
	Amxx_EBotRemoveEnemyEntity = (_EBotRemoveEnemyEntity)GetProcAddress(dll, "Amxx_EBotRemoveEnemyEntity");
	Amxx_EBotClearRegisteredEnemyEntities = (_EBotClearRegisteredEnemyEntities)GetProcAddress(dll, "Amxx_EBotClearRegisteredEnemyEntities");
}

static cell AMX_NATIVE_CALL amxx_is_ebot_running(AMX* amx, cell* params)
{
	if (!Amxx_EBOT)
		return false;

	return Amxx_EBOT();
}

static cell AMX_NATIVE_CALL amxx_get_ebot_version(AMX* amx, cell* params) 
{
	if (!Amxx_EBotVersion)
		return 0;

	return amx_ftoc(Amxx_EBotVersion());
}

static cell AMX_NATIVE_CALL amxx_is_user_ebot(AMX* amx, cell* params)
{
	if (!Amxx_EBOT || !Amxx_IsEBot)
		return 0;

	return Amxx_IsEBot(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_sees_enemy(AMX* amx, cell* params)
{
	if (!Amxx_EBotSeesEnemy)
		return 0;

	return Amxx_EBotSeesEnemy(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_sees_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotSeesEntity)
		return 0;

	return Amxx_EBotSeesEntity(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_sees_friend(AMX* amx, cell* params)
{
	if (!Amxx_EBotSeesFriend)
		return 0;

	return Amxx_EBotSeesFriend(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_enemy(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetEnemy)
		return 0;

	return Amxx_EBotGetEnemy(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetEntity)
		return 0;

	return Amxx_EBotGetEntity(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_friend(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetFriend)
		return 0;

	return Amxx_EBotGetFriend(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_enemy(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetEnemy)
		return 0;

	return Amxx_EBotSetEnemy(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetEntity)
		return 0;

	return Amxx_EBotSetEntity(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_friend(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetFriend)
		return 0;

	return Amxx_EBotSetFriend(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_enemy_distance(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetEnemyDistance)
		return 0;

	return Amxx_EBotGetEnemyDistance(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_entity_distance(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetEntityDistance)
		return 0;

	return Amxx_EBotGetEntityDistance(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_friend_distance(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetFriendDistance)
		return 0;

	return Amxx_EBotGetFriendDistance(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_entity_action(AMX* amx, cell* params)
{
	if (!Amxx_EbotSetEntityAction)
		return -2;

	return Amxx_EbotSetEntityAction(params[1], params[2], params[3]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_look_at(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetLookAt)
		return 0;

	const cell* cpVec1 = g_fn_GetAmxAddr(amx, params[2]);
	const cell* cpVec2 = g_fn_GetAmxAddr(amx, params[3]);
	Amxx_EBotSetLookAt(params[1], Vector(amx_ctof(cpVec1[0]), amx_ctof(cpVec1[1]), amx_ctof(cpVec1[2])), Vector(amx_ctof(cpVec2[0]), amx_ctof(cpVec2[1]), amx_ctof(cpVec2[2])));
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_current_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetCurrentProcess)
		return 0;

	return Amxx_EBotGetCurrentProcess(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_remembered_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetRememberedProcess)
		return 0;

	return Amxx_EBotGetRememberedProcess(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_current_process_time(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetCurrentProcessTime)
		return 0;

	return amx_ftoc(Amxx_EBotGetCurrentProcessTime(params[1]));
}

static cell AMX_NATIVE_CALL amxx_ebot_get_remembered_process_time(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetRememberedProcessTime)
		return 0;

	return amx_ftoc(Amxx_EBotGetRememberedProcessTime(params[1]));
}

static cell AMX_NATIVE_CALL amxx_ebot_set_current_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetCurrentProcess)
		return 0;

	return Amxx_EBotSetCurrentProcess(params[1], params[2], params[3], amx_ctof(params[4]));
}

static cell AMX_NATIVE_CALL amxx_ebot_force_current_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotForceCurrentProcess)
		return 0;

	Amxx_EBotForceCurrentProcess(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_finish_current_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotFinishCurrentProcess)
		return 0;

	Amxx_EBotFinishCurrentProcess(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_override_current_process(AMX* amx, cell* params)
{
	if (!Amxx_EBotOverrideCurrentProcess)
		return 0;

	return Amxx_EBotOverrideCurrentProcess(params[1], params[2], amx_ctof(params[3]), params[4], params[5], params[6]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_override_process_id(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetOverrideProcessID)
		return 0;

	return Amxx_EBotGetOverrideProcessID(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_has_override_checks(AMX* amx, cell* params)
{
	if (!Amxx_EBotHasOverrideChecks)
		return 0;

	return Amxx_EBotHasOverrideChecks(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_has_override_look_ai(AMX* amx, cell* params)
{
	if (!Amxx_EBotHasOverrideLookAI)
		return 0;

	return Amxx_EBotHasOverrideLookAI(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_force_fire_weapon(AMX* amx, cell* params)
{
	if (!Amxx_EBotForceFireWeapon)
		return 0;

	Amxx_EBotForceFireWeapon(params[1], amx_ctof(params[2]));
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_look_at_around(AMX* amx, cell* params)
{
	if (!Amxx_EBotLookAtAround)
		return 0;

	Amxx_EBotLookAtAround(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_call_new_round(AMX* amx, cell* params)
{
	if (!Amxx_EBotCallNewRound)
		return 0;

	Amxx_EBotCallNewRound(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_set_ignore_user(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetIgnoreClient)
		return 0;

	Amxx_EBotSetIgnoreClient(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_is_user_ignored(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsClientIgnored)
		return 0;

	return Amxx_EBotIsClientIgnored(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_user_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetClientWaypoint)
		return 0;

	return Amxx_EBotGetClientWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_user_owner(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsClientOwner)
		return 0;

	return Amxx_EBotIsClientOwner(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_user_in_game(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsClientInGame)
		return 0;

	return Amxx_EBotIsClientInGame(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_user_alive(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsClientAlive)
		return 0;

	return Amxx_EBotIsClientAlive(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_enemy_reachable(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsEnemyReachable)
		return 0;

	return Amxx_EBotIsEnemyReachable(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_enemy_reachable(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetEnemyReachable)
		return 0;

	Amxx_EBotSetEnemyReachable(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_is_stuck(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsStuck)
		return 0;

	return Amxx_EBotIsStuck(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_stuck_time(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetStuckTime)
		return 0;

	return amx_ftoc(Amxx_EBotGetStuckTime(params[1]));
}

static cell AMX_NATIVE_CALL amxx_ebot_get_ammo(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetAmmo)
		return 0;

	return Amxx_EBotGetAmmo(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_ammo_in_clip(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetAmmoInClip)
		return 0;

	return Amxx_EBotGetAmmoInClip(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_current_weapon(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetCurrentWeapon)
		return 0;

	return Amxx_EBotGetCurrentWeapon(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_select_knife(AMX* amx, cell* params)
{
	if (!Amxx_EBotSelectKnife)
		return 0;

	Amxx_EBotSelectKnife(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_select_best_weapon(AMX* amx, cell* params)
{
	if (!Amxx_EBotBestWeapon)
		return 0;

	Amxx_EBotBestWeapon(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_is_slow_think(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsSlowThink)
		return 0;

	return Amxx_EBotIsSlowThink(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_slow_think(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetSlowThink)
		return 0;

	Amxx_EBotSetSlowThink(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_is_zombie(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsZombie)
		return 0;

	return Amxx_EBotIsZombie(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_zombie(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetZombie)
		return 0;

	Amxx_EBotSetZombie(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_is_alive(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsAlive)
		return 0;

	return Amxx_EBotIsAlive(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_alive(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetAlive)
		return 0;

	Amxx_EBotSetAlive(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_number(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointNumer)
		return 0;

	return Amxx_EBotGetWaypointNumer();
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_origin(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointOrigin)
		return 0;

	Vector* origin;
	Amxx_EBotGetWaypointOrigin(params[1], &origin);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = amx_ftoc(origin->x);
	ret[1] = amx_ftoc(origin->y);
	ret[2] = amx_ftoc(origin->z);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_flags(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointFlags)
		return 0;

	int* flags;
	Amxx_EBotGetWaypointFlags(params[1], &flags);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *flags;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_radius(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointRadius)
		return 0;

	int* radius;
	Amxx_EBotGetWaypointRadius(params[1], &radius);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *radius;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_mesh(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointMesh)
		return 0;

	int* mesh;
	Amxx_EBotGetWaypointMesh(params[1], &mesh);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *mesh;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_connections(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointConnections)
		return 0;

	int* con;
	Amxx_EBotGetWaypointConnections(params[1], &con, params[3]);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *con;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_connection_flags(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointConnectionFlags)
		return 0;

	int* conFlags;
	Amxx_EBotGetWaypointConnectionFlags(params[1], &conFlags, params[3]);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *conFlags;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_gravity(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointGravity)
		return 0;

	int* gravity;
	Amxx_EBotGetWaypointGravity(params[1], &gravity);
	cell* ret = g_fn_GetAmxAddr(amx, params[2]);
	ret[0] = *gravity;
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_move_to(AMX* amx, cell* params)
{
	if (!Amxx_EBotMoveTo)
		return 0;

	const cell* cpVec = g_fn_GetAmxAddr(amx, params[2]);
	Amxx_EBotMoveTo(params[1], Vector(amx_ctof(cpVec[0]), amx_ctof(cpVec[1]), amx_ctof(cpVec[2])), params[3]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_move_out(AMX* amx, cell* params)
{
	if (!Amxx_EBotMoveOut)
		return 0;

	const cell* cpVec = g_fn_GetAmxAddr(amx, params[2]);
	Amxx_EBotMoveOut(params[1], Vector(amx_ctof(cpVec[0]), amx_ctof(cpVec[1]), amx_ctof(cpVec[2])), params[3]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_find_path_to(AMX* amx, cell* params)
{
	if (!Amxx_EBotFindPathTo)
		return 0;

	Amxx_EBotFindPathTo(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_find_shortest_path_to(AMX* amx, cell* params)
{
	if (!Amxx_EBotFindShortestPathTo)
		return 0;

	Amxx_EBotFindShortestPathTo(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_current_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetCurrentWaypoint)
		return 0;

	return Amxx_EBotGetCurrentWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_goal_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetGoalWaypoint)
		return 0;

	return Amxx_EBotGetGoalWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_set_current_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetCurrentWaypoint)
		return 0;

	Amxx_EBotSetCurrentWaypoint(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_set_goal_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotSetGoalWaypoint)
		return 0;

	Amxx_EBotSetGoalWaypoint(params[1], params[2]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_camp_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetCampWaypoint)
		return 0;

	return Amxx_EBotGetCampWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_mesh_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetMeshWaypoint)
		return 0;

	return Amxx_EBotGetMeshWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_can_follow_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotCanFollowPath)
		return 0;

	return Amxx_EBotCanFollowPath(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_follow_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotFollowPath)
		return 0;

	Amxx_EBotFollowPath(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_stop_following_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotStopFollowingPath)
		return 0;

	Amxx_EBotStopFollowingPath(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_shift_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotShiftPath)
		return 0;

	Amxx_EBotShiftPath(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_clear_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotClearPath)
		return 0;

	Amxx_EBotClearPath(params[1]);
	return 1;
}

static cell AMX_NATIVE_CALL amxx_ebot_get_path(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetPath)
		return 0;

	return Amxx_EBotGetPath(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_path_length(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetPathLength)
		return 0;

	return Amxx_EBotGetPathLength(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_node_reachable(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsNodeReachable)
		return 0;

	const cell* cpVec1 = g_fn_GetAmxAddr(amx, params[1]);
	const cell* cpVec2 = g_fn_GetAmxAddr(amx, params[2]);
	return Amxx_EBotIsNodeReachable(Vector(amx_ctof(cpVec1[0]), amx_ctof(cpVec1[0]), amx_ctof(cpVec1[0])), Vector(amx_ctof(cpVec2[0]), amx_ctof(cpVec2[0]), amx_ctof(cpVec2[0])));
}

static cell AMX_NATIVE_CALL amxx_ebot_find_nearest_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotFindNearestWaypoint)
		return -1;

	const cell* cpVec = g_fn_GetAmxAddr(amx, params[1]);
	return Amxx_EBotFindNearestWaypoint(Vector(amx_ctof(cpVec[0]), amx_ctof(cpVec[0]), amx_ctof(cpVec[0])), amx_ftoc(params[2]));
}

static cell AMX_NATIVE_CALL amxx_ebot_find_farest_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotFindFarestWaypoint)
		return -1;

	const cell* cpVec = g_fn_GetAmxAddr(amx, params[1]);
	return Amxx_EBotFindFarestWaypoint(Vector(amx_ctof(cpVec[0]), amx_ctof(cpVec[0]), amx_ctof(cpVec[0])), amx_ftoc(params[2]));
}

static cell AMX_NATIVE_CALL amxx_ebot_find_nearest_waypoint_to_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotFindNearestWaypointToEntity)
		return -1;

	const cell* cpVec = g_fn_GetAmxAddr(amx, params[1]);
	return Amxx_EBotFindNearestWaypointToEntity(Vector(amx_ctof(cpVec[0]), amx_ctof(cpVec[0]), amx_ctof(cpVec[0])), amx_ftoc(params[2]), params[3]);
}

static cell AMX_NATIVE_CALL amxx_ebot_get_waypoint_distance(AMX* amx, cell* params)
{
	if (!Amxx_EBotGetWaypointDistance)
		return 0;

	return Amxx_EBotGetWaypointDistance(params[1], params[2]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_valid_waypoint(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsValidWaypoint)
		return 0;

	return Amxx_EBotIsValidWaypoint(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_is_matrix_ready(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsMatrixReady)
		return 0;

	return Amxx_EBotIsMatrixReady();
}

static cell AMX_NATIVE_CALL amxx_ebot_is_camping(AMX* amx, cell* params)
{
	if (!Amxx_EBotIsCamping)
		return 0;

	return Amxx_EBotIsCamping(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_register_enemy_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotRegisterEnemyEntity)
		return 0;

	return Amxx_EBotRegisterEnemyEntity(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_unregister_enemy_entity(AMX* amx, cell* params)
{
	if (!Amxx_EBotRemoveEnemyEntity)
		return 0;

	return Amxx_EBotRemoveEnemyEntity(params[1]);
}

static cell AMX_NATIVE_CALL amxx_ebot_clear_all_registered_enemy_entities(AMX* amx, cell* params)
{
	if (!Amxx_EBotClearRegisteredEnemyEntities)
		return 0;

	Amxx_EBotClearRegisteredEnemyEntities();
	return 1;
}

AMX_NATIVE_INFO ebot_natives[] =
{
	{ "is_ebot_running", amxx_is_ebot_running },
	{ "ebot_get_version", amxx_get_ebot_version },
	{ "is_user_ebot", amxx_is_user_ebot },
	{ "ebot_sees_enemy", amxx_ebot_sees_enemy }, 
	{ "ebot_sees_entity", amxx_ebot_sees_entity }, 
	{ "ebot_sees_friend", amxx_ebot_sees_friend }, 
	{ "ebot_get_enemy", amxx_ebot_get_enemy }, 
	{ "ebot_get_entity", amxx_ebot_get_entity }, 
	{ "ebot_get_friend", amxx_ebot_get_friend },
	{ "ebot_set_enemy", amxx_ebot_set_enemy }, 
	{ "ebot_set_entity", amxx_ebot_set_entity },
	{ "ebot_set_friend", amxx_ebot_set_friend },
	{ "ebot_get_enemy_distance", amxx_ebot_get_enemy_distance },
	{ "ebot_get_entity_distance", amxx_ebot_get_entity_distance },
	{ "ebot_get_friend_distance", amxx_ebot_get_friend_distance },
	{ "ebot_set_entity_action", amxx_ebot_set_entity_action }, 
	{ "ebot_set_set_look_at", amxx_ebot_set_look_at }, 
	{ "ebot_get_current_process", amxx_ebot_get_current_process }, 
	{ "ebot_get_remembered_process", amxx_ebot_get_remembered_process }, 
	{ "ebot_get_current_process_time", amxx_ebot_get_current_process_time }, 
	{ "ebot_get_remembered_process_tym", amxx_ebot_get_remembered_process_time }, 
	{ "ebot_set_current_process", amxx_ebot_set_current_process }, 
	{ "ebot_force_current_process", amxx_ebot_force_current_process }, 
	{ "ebot_finish_current_process", amxx_ebot_finish_current_process }, 
	{ "ebot_override_current_process", amxx_ebot_override_current_process }, 
	{ "ebot_get_override_process_id", amxx_ebot_get_override_process_id }, 
	{ "ebot_has_override_checks", amxx_ebot_has_override_checks }, 
	{ "ebot_has_override_look_ai", amxx_ebot_has_override_look_ai }, 
	{ "ebot_force_fire_weapon", amxx_ebot_force_fire_weapon }, 
	{ "ebot_look_at_around", amxx_ebot_look_at_around }, 
	{ "ebot_call_new_round", amxx_ebot_call_new_round }, 
	{ "ebot_set_ignore_user", amxx_ebot_set_ignore_user }, 
	{ "ebot_is_user_ignored", amxx_ebot_is_user_ignored }, 
	{ "ebot_get_user_waypoint", amxx_ebot_get_user_waypoint }, 
	{ "ebot_is_user_owner", amxx_ebot_is_user_owner }, 
	{ "ebot_is_user_in_game", amxx_ebot_is_user_in_game }, 
	{ "ebot_is_user_alive", amxx_ebot_is_user_alive }, 
	{ "ebot_is_enemy_reachable", amxx_ebot_is_enemy_reachable }, 
	{ "ebot_set_enemy_reachable", amxx_ebot_set_enemy_reachable }, 
	{ "ebot_is_stuck", amxx_ebot_is_stuck }, 
	{ "get_ebot_stuck_time", amxx_ebot_get_stuck_time }, 
	{ "ebot_get_ammo", amxx_ebot_get_ammo }, 
	{ "ebot_get_ammo_in_clip", amxx_ebot_get_ammo_in_clip }, 
	{ "ebot_get_current_weapon", amxx_ebot_get_current_weapon }, 
	{ "ebot_select_knife", amxx_ebot_select_knife }, 
	{ "ebot_select_best_weapon", amxx_ebot_select_best_weapon }, 
	{ "ebot_is_slow_think", amxx_ebot_is_slow_think }, 
	{ "ebot_set_slow_think", amxx_ebot_set_slow_think }, 
	{ "ebot_is_zombie", amxx_ebot_is_zombie }, 
	{ "ebot_set_zombie", amxx_ebot_set_zombie }, 
	{ "ebot_is_alive", amxx_ebot_is_alive }, 
	{ "ebot_set_alive", amxx_ebot_set_alive }, 
	{ "ebot_get_waypoint_number", amxx_ebot_get_waypoint_number }, 
	{ "ebot_get_waypoint_origin", amxx_ebot_get_waypoint_origin }, 
	{ "ebot_get_waypoint_flags", amxx_ebot_get_waypoint_flags }, 
	{ "ebot_get_waypoint_radius", amxx_ebot_get_waypoint_radius }, 
	{ "ebot_get_waypoint_mesh", amxx_ebot_get_waypoint_mesh }, 
	{ "ebot_get_waypoint_connections", amxx_ebot_get_waypoint_connections }, 
	{ "ebot_get_waypoint_con_flags", amxx_ebot_get_waypoint_connection_flags }, 
	{ "ebot_get_waypoint_gravity", amxx_ebot_get_waypoint_gravity }, 
	{ "ebot_move_to", amxx_ebot_move_to }, 
	{ "ebot_move_out", amxx_ebot_move_out }, 
	{ "ebot_find_path_to", amxx_ebot_find_path_to }, 
	{ "ebot_find_shortest_path_to", amxx_ebot_find_shortest_path_to }, 
	{ "ebot_get_current_waypoint", amxx_ebot_get_current_waypoint }, 
	{ "ebot_get_goal_waypoint", amxx_ebot_get_goal_waypoint }, 
	{ "ebot_set_current_waypoint", amxx_ebot_set_current_waypoint }, 
	{ "ebot_get_camp_waypoint", amxx_ebot_get_camp_waypoint }, 
	{ "ebot_get_mesh_waypoint", amxx_ebot_get_mesh_waypoint }, 
	{ "ebot_can_follow_path", amxx_ebot_can_follow_path }, 
	{ "ebot_follow_path", amxx_ebot_follow_path }, 
	{ "ebot_stop_following_path", amxx_ebot_stop_following_path }, 
	{ "ebot_shift_path", amxx_ebot_shift_path }, 
	{ "ebot_clear_path", amxx_ebot_clear_path }, 
	{ "ebot_get_path", amxx_ebot_get_path }, 
	{ "ebot_get_path_length", amxx_ebot_get_path_length }, 
	{ "ebot_is_node_reachable", amxx_ebot_is_node_reachable }, 
	{ "ebot_find_nearest_waypoint", amxx_ebot_find_nearest_waypoint }, 
	{ "ebot_find_farest_waypoint", amxx_ebot_find_farest_waypoint }, 
	{ "ebot_find_nearest_waypoint_ent", amxx_ebot_find_nearest_waypoint_to_entity }, 
	{ "ebot_get_waypoint_distance", amxx_ebot_get_waypoint_distance }, 
	{ "ebot_is_valid_waypoint", amxx_ebot_is_valid_waypoint }, 
	{ "ebot_is_matrix_ready", amxx_ebot_is_matrix_ready }, 
	{ "ebot_is_camping", amxx_ebot_is_camping }, 
	{ "ebot_register_enemy_entity", amxx_ebot_register_enemy_entity }, 
	{ "ebot_unregister_enemy_entity", amxx_ebot_unregister_enemy_entity }, 
	{ "ebot_clear_entity_list", amxx_ebot_clear_all_registered_enemy_entities }, 
	{ nullptr, nullptr },
};
