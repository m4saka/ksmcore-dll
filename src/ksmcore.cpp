#include "ksmcore.h"

#include <string>
#include <cstdint>
#include "game_system.hpp"

bool CreateGameSystem(const char *chartFilename, double initialMs, GameSystem **pRet)
{
    try
    {
        *pRet = new GameSystem(chartFilename, initialMs);
        return true;
    }
    catch (...)
    {
        delete *pRet;
        return false;
    }
}

int GetVersion()
{
    return KSMCORE_VERSION;
}

void DestroyGameSystem(GameSystem *pGameSystem)
{
    delete pGameSystem;
}

void UpdateGameSystem(GameSystem *pGameSystem, double currentMs)
{
    pGameSystem->update(currentMs);
}

void GetCurrentCamValue(GameSystem *pGameSystem, CamParam camParam, double *pRet)
{
    const auto & camera = pGameSystem->camera();
    switch (camParam)
    {
    case CAM_ZOOM_TOP:
        *pRet = camera.currentZoomTop();
        break;

    case CAM_ZOOM_BOTTOM:
        *pRet = camera.currentZoomBottom();
        break;

    case CAM_ZOOM_SIDE:
        *pRet = camera.currentZoomSide();
        break;

    case CAM_CENTER_SPLIT:
        *pRet = camera.currentCenterSplit();
        break;

    case CAM_MANUAL_TILT:
        *pRet = camera.currentManualTilt();
        break;
    }
}
