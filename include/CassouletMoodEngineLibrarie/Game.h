#pragma once
#include <SDL.h>
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/CassouletEngine.h>

class CASSOULET_DLL Game
{
public:
    Game();
    virtual ~Game();

    void ProcessInput(); // Read user input
    void Render(); // Draw on the screen
    void Update(); // Update the world
    void Delay(); // A function that would just wait for an amount of time

    bool IsOver(); // Check if game is over
    bool Init(); // Initialize our objects

protected:

    SDL_Window* m_pWindow; // The windows we will create
    SDL_Renderer* m_pRenderer; // Were we will render our frames
    std::unique_ptr<CassouletEngine> m_pCassouletEngine; // This is an object that knows more details about game internal
};