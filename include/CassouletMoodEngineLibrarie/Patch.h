#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <memory>

#include <CassouletMoodEngineLibrarie/DataTypes.h>
#include <CassouletMoodEngineLibrarie/Export.h>

class CASSOULET_DLL Patch
{
public:
    Patch(std::string sName);
    ~Patch();

    void Initialize(WADPatchHeader& PatchHeader);
    void AppendPatchColumn(PatchColumnData& PatchColumn);
    void Render(uint8_t* pScreenBuffer, int iBufferPitch, int iXScreenLocation, int iYScreenLocation);
    void RenderColumn(uint8_t* pScreenBuffer, int iBufferPitch, int iColumn, int iXScreenLocation, int iYScreenLocation, int iMaxHeight, int iYOffset);
    void AppendColumnStartIndex();
    void ComposeColumn(uint8_t* m_pOverLapColumnData, int m_iHeight, int& iPatchColumnIndex, int iColumnOffsetIndex, int iYOrigin);

    int GetHeight();
    int GetWidth();
    int GetXOffset();
    int GetYOffset();
    void SetSize(int height,int width);

    int GetColumnDataIndex(int iIndex);

protected:
    int m_iHeight;
    int m_iWidth;
    int m_iXOffset;
    int m_iYOffset;

    std::string m_sName;
    std::vector<PatchColumnData> m_PatchData;
    std::vector<int> m_ColumnIndex;
    WADPalette m_palette;
};