#include <CassouletMoodEngineLibrarie/Game.h>

int main(int argc, char* argv[])
{
    Game game;
    game.Init();

    while (!game.IsOver())
    {
        game.ProcessInput();
        game.Update();
        game.Render();
        game.Delay();
    }

    std::cout << "See you in space CowBoy" << std::endl;
    return 0;
}
