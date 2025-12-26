#pragma once
#include "clay.h"

#ifdef CLAY_IMPLEMENTATION
#ifdef CLAY_RENDERER_CAIRO
#include "clay/renderers/cairo/clay_renderer_cairo.c"
#endif
#ifdef CLAY_RENDERER_PLAYDATE
#include "clay/renderers/playdate/clay_renderer_playdate.c"
#endif
#ifdef CLAY_RENDERER_RAYLIB
#include "clay/renderers/raylib/clay_renderer_raylib.c"
#endif
#ifdef CLAY_RENDERER_SDL2
#include "clay/renderers/sdl2/clay_renderer_sdl2.c"
#endif
#ifdef CLAY_RENDERER_SDL3
#include "clay/renderers/sdl3/clay_renderer_sdl3.c"
#endif
#ifdef CLAY_RENDERER_SOKOL
#include "clay/renderers/sokol/sokol_clay.h"
#endif
#ifdef CLAY_RENDERER_TERMBOX2
#include "clay/renderers/termbox2/clay_renderer_termbox2.c"
#endif
#ifdef CLAY_RENDERER_TERMINAL
#include "clay/renderers/terminal/clay_renderer_terminal_ansi.c"
#endif
#ifdef CLAY_RENDERER_WIN32_GDI
#include "clay/renderers/win32_gdi/clay_renderer_gdi.c"
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
// #pragma comment(lib, "kernel32.lib")
// #pragma comment(lib, "comdlg32.lib")
// #pragma comment(lib, "ole32.lib")
#endif
#endif
