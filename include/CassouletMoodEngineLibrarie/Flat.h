#pragma once
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/DataTypes.h>
#include <SDL.h>

class CASSOULET_DLL Flat
{
public: 

	Flat(WADPalette,PatchColumnData);

protected:
	WADPalette m_palette;
	PatchColumnData m_PatchData;
	SDL_;
};