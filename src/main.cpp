#include "App.h"

int main(int argc, char const *argv[])
{
    App *app = new App();
    int result = app->Run();
    delete app;
    return result;
}
