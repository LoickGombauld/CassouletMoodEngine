#include <CassouletMoodEngineLibrarie/Weapon.h>
#include <CassouletMoodEngineLibrarie/AssetsManager.h>

Weapon::Weapon(const std::string& sWeaponPatch,int sizeX,int sizeY) : m_sizeX(sizeX),m_sizeY(sizeY)
{
    m_pPatch = AssetsManager::GetInstance()->GetPatch(sWeaponPatch);
}


Weapon::~Weapon()
{
}

void Weapon::Render(uint8_t* pScreenBuffer, int iBufferPitch)
{
    m_pPatch->Render(pScreenBuffer, iBufferPitch, -m_pPatch->GetXOffset(), -m_pPatch->GetYOffset());
}