#ifndef APPLICATION_H
#define APPLICATION_H

#include <iapplication.h>
#include <imgui.h>

class Application :
    public IApplication
{
public:
    Application();

    virtual bool Setup();

    virtual void Render2d();

    virtual void Cleanup();
    
private:
    ImFont *_monofont;
    ImFont *_fkFont;
    ImFont *_fadFont;

};

#endif // APPLICATION_H
