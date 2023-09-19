#pragma once
#include <vector>
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/DataTypes.h>

class CASSOULET_DLL Block {
public:
	Block(BlockmapHeader header, BlockMapOffset offset);

protected:

	BlockMapOffset m_offset;
	BlockmapHeader m_header;
	Blocklists m_blocklists;
};