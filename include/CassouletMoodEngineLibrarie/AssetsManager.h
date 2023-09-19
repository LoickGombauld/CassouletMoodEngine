#pragma once
#include <map>
#include <vector>
#include <memory>

#include <CassouletMoodEngineLibrarie/Patch.h>
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/Wall.h>
#include <CassouletMoodEngineLibrarie/DataTypes.h>

#include <CassouletMoodEngineLibrarie/WADLoader.h>

class WADLoader;

class CASSOULET_DLL AssetsManager
{
public:
    static AssetsManager* GetInstance();
    void Init(WADLoader* pWADLoader);

    ~AssetsManager();

    Patch* AddPatch(const std::string& sPatchName, WADPatchHeader& PatchHeader);
    Patch* GetPatch(const std::string& sPatchName);

    Wall* AddTexture(WADTextureData& TextureData);
    Wall* GetTexture(const std::string& sTextureName);

    void AddPName(const std::string& PName);
    std::string GetPName(int PNameIndex);


protected:
    static bool m_bInitialized;
    static std::unique_ptr <AssetsManager> m_pInstance;

    AssetsManager();

    void LoadPatch(const std::string& sPatchName);
    void LoadTextures();


    std::map<std::string, std::shared_ptr<Patch>> m_PatchesCache;
    std::map<std::string, std::shared_ptr<Wall>> m_TexturesCache;


    std::vector<std::string> m_PNameLookup;

    WADLoader* m_pWADLoader;
};