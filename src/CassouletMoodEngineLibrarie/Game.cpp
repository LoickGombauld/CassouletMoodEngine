#include <CassouletMoodEngineLibrarie/Game.h>
#include <iostream>

Game::Game() 
{
}

Game::~Game()
{
}

bool Game::Init()
{
    m_pCassouletEngine = std::unique_ptr<CassouletEngine>(new CassouletEngine());

    if (!m_pCassouletEngine || !m_pCassouletEngine->Init())
    {
       std::cout << m_pCassouletEngine->GetAppName() << " failed to initialize!" <<std::endl;
        return false;
    }
    return true;
}

void Game::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            m_pCassouletEngine->KeyPressed(event);
            break;

        case SDL_KEYUP:
            m_pCassouletEngine->KeyReleased(event);
            break;

        case SDL_QUIT:
            m_pCassouletEngine->Quit();
            break;
        }
    }

    m_pCassouletEngine->UpdateKeyStatus(SDL_GetKeyboardState(NULL));
}

void Game::Render()
{
    //Game objects to draw themselves
    m_pCassouletEngine->Render();
}

void Game::Update()
{
    m_pCassouletEngine->Update();
}

bool Game::IsOver()
{
    return m_pCassouletEngine->IsOver();
}


void Game::Delay()
{
    SDL_Delay(m_pCassouletEngine->GetTimePerFrame());
}