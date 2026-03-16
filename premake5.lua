workspace "Breakout"

    architecture "x64"
    startproject "Breakout"

    configurations {
        "Debug",
        "Release"
    }

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Breakout"
    location "."
    kind "ConsoleApp"
    language "C++"

    cppdialect "C++20"
    staticruntime "Off"
    systemversion "latest"

    targetdir ("binaries/" .. outputDir .. "/%{prj.name}")
    objdir    ("intermediate/" .. outputDir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "deps/sdl2/include",
        "src"
    }

    libdirs {
        "deps/sdl2/lib"
    }

    links {

        -- SDL
        "SDL2.lib",

        -- DirectX
        "d3d11.lib",
        "dxgi.lib",
        "d3dcompiler.lib"
    }

    defines {
        "SDL_MAIN_HANDLED"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"
        defines { "_DEBUG" }

    filter "configurations:Release"
        runtime "Release"
        optimize "On"