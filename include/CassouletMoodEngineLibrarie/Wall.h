#pragma once
#include <vector>

#include <CassouletMoodEngineLibrarie/DataTypes.h>
#include <CassouletMoodEngineLibrarie/Patch.h>
#include <CassouletMoodEngineLibrarie/Export.h>


class CASSOULET_DLL Wall
{
public:
    Wall(WADTextureData& TextureData);
    ~Wall();

    bool IsComposed();
    bool Initialize();
    bool Compose();

    void Render(uint8_t* pScreenBuffer, int iBufferPitch, int iXScreenLocation, int iYScreenLocation);
    void RenderColumn(uint8_t* pScreenBuffer, int iBufferPitch, int iXScreenLocation, int iYScreenLocation, int iCurrentColumnIndex);

protected:
    //int m_Flags; // Ignored
    int m_iWidth;
    int m_iHeight;
    int m_iOverLapSize;

    bool m_IsComposed;

    int m_PNameIndex;

    std::string m_sName;

    std::vector<int> m_ColumnPatchCount;
    std::vector<int> m_ColumnIndex;
    std::vector<int> m_ColumnPatch;
    std::vector<WADTexturePatch> m_TexturePatches;
    std::unique_ptr<uint8_t[]> m_pOverLapColumnData;
};