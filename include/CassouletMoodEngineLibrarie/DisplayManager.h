
#pragma once

#include <SDL.h>
#include <string>
#include <vector>
#include <CassouletMoodEngineLibrarie/DataTypes.h>
#include <CassouletMoodEngineLibrarie/Export.h>


class CASSOULET_DLL DisplayManager
{
public:
    DisplayManager(int m_iWindowWidth, int iWindowHeight);
    ~DisplayManager();

    void InitFrame();
    void Render();
    void AddColorPalette(WADPalette& palette);

    uint8_t* GetScreenBuffer();
    SDL_Renderer* Init(const std::string& sWindowTitle);


protected:
    int m_iScreenWidth;
    int m_iScreenHeight;

    std::vector<WADPalette> m_ColorPalettes;

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    SDL_Texture* m_pTexture;
    SDL_Surface* m_pScreenBuffer;
    SDL_Surface* m_pRGBBuffer;
};