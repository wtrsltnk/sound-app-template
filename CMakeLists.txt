cmake_minimum_required(VERSION 3.13)

include(cmake/CPM.cmake)

project(SoundApp)

find_package(OpenGL REQUIRED)

CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.7.0)

CPMAddPackage(
    NAME imgui
    GIT_TAG v1.79
    GITHUB_REPOSITORY ocornut/imgui
    DOWNLOAD_ONLY True
)

if (imgui_ADDED)
    add_library(imgui)
    target_include_directories(
        imgui
        PUBLIC
            "${imgui_SOURCE_DIR}/"
    )
            
    target_sources(
        imgui
        PUBLIC 
            "${imgui_SOURCE_DIR}/imgui.cpp"
            "${imgui_SOURCE_DIR}/imgui_demo.cpp"
            "${imgui_SOURCE_DIR}/imgui_draw.cpp"
            "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
            "${imgui_SOURCE_DIR}/examples/imgui_impl_opengl3.cpp"
            "${imgui_SOURCE_DIR}/examples/imgui_impl_win32.cpp"
    )
    
    target_compile_options(
        imgui
        PUBLIC 
            -DIMGUI_IMPL_OPENGL_LOADER_GLAD
    )

    target_include_directories(
        imgui
        PUBLIC
            include
    )

endif()

add_executable(SoundApp
    "src/application.cpp"
    "src/program.cpp"
    "src/glad.c"
    "src/wasapi.cpp"
)

target_include_directories(
    SoundApp
    PUBLIC
        include
)

target_link_libraries(
    SoundApp
    PUBLIC
        ${OPENGL_LIBRARIES}
        spdlog
        imgui
        winmm
)

target_compile_options(
    SoundApp
    PUBLIC 
        -DUNICODE
        -D_UNICODE
        -DIMGUI_IMPL_WIN32_DISABLE_GAMEPAD
)

if(MINGW)
    target_link_options(
        SoundApp
        PUBLIC
            -mwindows
            -municode
            -static
    )
endif()

target_compile_features(
    SoundApp
    PUBLIC
        cxx_std_17
)
