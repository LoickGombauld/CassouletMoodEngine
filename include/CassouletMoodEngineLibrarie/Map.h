#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include<CassouletMoodEngineLibrarie/DataTypes.h>
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/Player.h>
#include <CassouletMoodEngineLibrarie/Things.h>
#include <CassouletMoodEngineLibrarie/Block.h>
class CASSOULET_DLL Map
{
public:
    Map(ViewRenderer* pViewRenderer, std::string sName, Player* pPlayer, Things* pThings);
    ~Map();

    std::string GetName();
    void AddVertex(Vertex& v);
    void AddLinedef(WADLinedef& l);
    void AddNode(Node& node);
    void AddSubsector(Subsector& subsector);
    void AddSeg(WADSeg& seg);
    void AddSidedef(WADSidedef& sidedef);
    void AddSector(WADSector& sector);
    void AddBlock(Block& block);
    void Render3DView();
    void SetLumpIndex(int iIndex);
    void Init();

    int GetXMin();
    int GetXMax();
    int GetYMin();
    int GetYMax();
    int GetLumpIndex();

    Things* GetThings();
    int GetPlayerSubSectorHeight();

protected:
    void BuildSectors();
    void BuildSidedefs();
    void BuildLinedef();
    void BuildSeg();
    void RenderBSPNodes();
    void RenderAutoMapNode(int iNodeID);
    void RenderBSPNodes(int iNodeID);
    void RenderSubsector(int iSubsectorID);

    bool IsPointOnLeftSide(int XPosition, int YPosition, int iNodeID);

    std::string m_sName;

    std::vector<Vertex> m_Vertexes;
    std::vector<Sector> m_Sectors;
    std::vector<Sidedef> m_Sidedefs;
    std::vector<Linedef> m_Linedefs;
    std::vector<Seg> m_Segs;
    std::vector<Subsector> m_Subsector;
    std::vector<Node> m_Nodes;
    std::vector<Block> m_blocks;

    std::vector<WADSector>* m_pSectors;
    std::vector<WADSidedef>* m_pSidedefs;
    std::vector<WADLinedef>* m_pLinedefs;
    std::vector<WADSeg>* m_pSegs;

    int m_XMin;
    int m_XMax;
    int m_YMin;
    int m_YMax;
    int m_iLumpIndex;

    Player* m_pPlayer;
    Things* m_pThings;
    ViewRenderer* m_pViewRenderer;
};