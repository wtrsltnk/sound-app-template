#include "application.h"

#include <algorithm>
#include <iapplication.h>
#include <imgui.h>
#include <map>

#include "IconsFontaudio.h"
#include "IconsForkAwesome.h"

Application::Application()
    : _monofont(nullptr),
      _fkFont(nullptr),
      _fadFont(nullptr)
{}

bool Application::Setup()
{
    auto &style = ImGui::GetStyle();

    ImGui::StyleColorsDark();

    style.TabRounding = 4;
    style.GrabRounding = 0;
    style.ChildRounding = 0;
    style.PopupRounding = 0;
    style.ScrollbarRounding = 0;
    style.WindowRounding = 0;
    style.Colors[ImGuiCol_Border] = ImVec4(30 / 255.0f, 30 / 255.0f, 30 / 255.0f, 240 / 255.0f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(21 / 255.0f, 37 / 255.0f, 61 / 255.0f, 240 / 255.0f);

    ImGuiIO &io = ImGui::GetIO();
    io.Fonts->Clear();
    ImFont *font = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    if (font != nullptr)
    {
        io.FontDefault = font;
    }
    else
    {
        io.Fonts->AddFontDefault();
    }

    ImFontConfig config;
    config.MergeMode = true;
    config.GlyphMinAdvanceX = 13.0f;

    static const ImWchar fontaudio_icon_ranges[] = {ICON_MIN_FAD, ICON_MAX_FAD, 0};
    _fadFont = io.Fonts->AddFontFromFileTTF("assets/fonts/fontaudio.ttf", 18.0f, &config, fontaudio_icon_ranges);

    static const ImWchar forkawesome_icon_ranges[] = {ICON_MIN_FK, ICON_MAX_FK, 0};
    _fkFont = io.Fonts->AddFontFromFileTTF("assets/fonts/forkawesome-webfont.ttf", 12.0f, &config, forkawesome_icon_ranges);

    _monofont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\SourceCodePro-Bold.ttf", 14.0f);

    io.Fonts->Build();

    return true;
}

void Application::Render2d()
{
    static bool _showStats = false;
    ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;

    ImGui::Begin("Stats", &_showStats);
    {
    }
    ImGui::End();
}

void Application::Cleanup()
{
}

extern IApplication *CreateApplication();

IApplication *CreateApplication()
{
    return new Application();
}