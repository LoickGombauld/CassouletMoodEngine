#include <filesystem>
#include <CassouletMoodEngineLibrarie/CassouletEngine.h>



CassouletEngine::CassouletEngine() : m_sAppName("Cassoulet Engine 3 (Parce que je vous jure que coder s'est pas facile !)"), m_bIsOver(false), m_iRenderWidth(1280), m_iRenderHeight(720), m_pMap(nullptr), m_pPlayer(nullptr)
{
}
CassouletEngine::~CassouletEngine()
{
}

bool CassouletEngine::Init()
{
    // Load WAD 
    LoadWAD();
    AssetsManager::GetInstance()->Init(&m_WADLoader);

    m_pDisplayManager = std::unique_ptr < DisplayManager>(new DisplayManager(m_iRenderWidth, m_iRenderHeight));
    m_pDisplayManager->Init(GetAppName());

    // Delay object creation to this point so renderer is inistilized correctly
    m_pViewRenderer = std::unique_ptr<ViewRenderer>(new ViewRenderer());
    m_pThings = std::unique_ptr<Things>(new Things());
    m_pPlayer = std::unique_ptr<Player>(new Player(m_pViewRenderer.get(), 1));
    m_pMap = std::unique_ptr<Map>(new Map(m_pViewRenderer.get(), "E1M1", m_pPlayer.get(), m_pThings.get()));

    ReadDataFromWAD();

    m_pViewRenderer->Init(m_pMap.get(), m_pPlayer.get(),m_iRenderWidth,m_iRenderHeight);
    m_pPlayer->Init((m_pMap->GetThings())->GetThingByID(m_pPlayer->GetID()));
    m_pMap->Init();

    return true;
}

void CassouletEngine::LoadWAD()
{
    m_WADLoader.SetWADFilePath(GetWADFileName());
    m_WADLoader.LoadWADToMemory();
}

std::string CassouletEngine::GetWADFileName()
{
    
    return std::filesystem::path("Resources/Map/DOOM1.WAD").string();
}

void CassouletEngine::Render()
{
    uint8_t* pScreenBuffer = m_pDisplayManager->GetScreenBuffer();

    m_pDisplayManager->InitFrame();
    m_pViewRenderer->Render(pScreenBuffer, m_iRenderWidth);
    m_pPlayer->Render(pScreenBuffer, m_iRenderWidth);

    m_pDisplayManager->Render();
}

void CassouletEngine::KeyPressed(SDL_Event& event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_TAB:
        //m_bRenderAutoMap = true;
        break;

    case SDLK_ESCAPE:
        Quit();
        break;

    default:
        break;
    }
}

void CassouletEngine::UpdateKeyStatus(const Uint8* KeyStates)
{
    //m_pPlayer->UpdateInput(KeyStates,m_iRenderWidth,m_iRenderHeight );

    if (KeyStates[SDL_SCANCODE_UP])
    {
        m_pPlayer->MoveForward();
    }

    if (KeyStates[SDL_SCANCODE_DOWN])
    {
        m_pPlayer->MoveBackward();
    }

    if (KeyStates[SDL_SCANCODE_LEFT])
    {
        m_pPlayer->RotateLeft();
    }

    if (KeyStates[SDL_SCANCODE_RIGHT])
    {
        m_pPlayer->RotateRight();
    }

    if (KeyStates[SDL_SCANCODE_Z])
    {
        m_pPlayer->Fly();
    }

    if (KeyStates[SDL_SCANCODE_X])
    {
        m_pPlayer->Sink();
    }
}


void CassouletEngine::KeyReleased(SDL_Event& event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_TAB:
        //m_bRenderAutoMap = false;
        break;

    default:
        break;
    }
}

void  CassouletEngine::Quit()
{
    m_bIsOver = true;
}

void CassouletEngine::Update()
{
    m_pPlayer->Think(m_pMap->GetPlayerSubSectorHeight());
}

bool CassouletEngine::IsOver()
{
    return m_bIsOver;
}

int CassouletEngine::GetRenderWidth()
{
    return m_iRenderWidth;
}

int CassouletEngine::GetRenderHeight()
{
    return m_iRenderHeight;
}

std::string CassouletEngine::GetAppName()
{
        return m_sAppName;
}



void CassouletEngine::ReadDataFromWAD()
{
    m_WADLoader.LoadPalette(m_pDisplayManager.get());
    m_WADLoader.LoadMapData(m_pMap.get());
}

int CassouletEngine::GetTimePerFrame()
{
    return 1000 / 144;
}