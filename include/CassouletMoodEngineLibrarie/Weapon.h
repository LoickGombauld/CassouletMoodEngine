#pragma once
#include <CassouletMoodEngineLibrarie/Patch.h>
#include <CassouletMoodEngineLibrarie/Export.h>

class CASSOULET_DLL Weapon
{
public:
    Weapon(const std::string& sWeaponPatch, int sizex, int sizey);
    virtual ~Weapon();

    void Render(uint8_t* pScreenBuffer, int iBufferPitch);

protected:
    Patch* m_pPatch;
    int m_sizeX;
    int m_sizeY;
};