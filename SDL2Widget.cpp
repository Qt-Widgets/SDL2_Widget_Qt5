#include <SDL2Widget.h>

SDL2Widget::SDL2Widget(QWidget* parent) : QWidget(parent)
{
    // Turn off double buffering for this widget. Double buffering
    // interferes with the ability for SDL to be properly displayed
    // on the QWidget.
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NativeWindow, true);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setMouseTracking(true);

    /* setting setUpdatesEnabled to false is MOST important here!
     * if you set it to true or comment it out entirely then when you
     * resize the SDL2Widget by dragging it from corners you will
     * notice the widget will flicker with white frames which are
     * produced by the widget updates.
     */
    setUpdatesEnabled(false);

    SDL_Init(SDL_INIT_EVERYTHING);
    sdlWindow = SDL_CreateWindowFrom((void*)this->winId());
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Render()));
    timer->start(1000 / 60);
    position = 0;
    dir = 1;
}

SDL2Widget::~SDL2Widget()
{
    SDL_DestroyRenderer(sdlRenderer);	// Basic SDL garbage collection
    SDL_DestroyWindow(sdlWindow);
    delete timer;

    sdlRenderer = nullptr;
    sdlWindow = nullptr;
    timer = nullptr;
}

void SDL2Widget::Render() {
    // Basic square bouncing animation
    SDL_Rect spos;
    spos.h = 100;
    spos.w = 100;
    spos.y = height() / 2 - 50;
    spos.x = position;

    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderFillRect(sdlRenderer, nullptr);
    SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0x0, 0x0, 0xFF);
    SDL_RenderFillRect(sdlRenderer, &spos);
    SDL_RenderPresent(sdlRenderer);

    if (position >= width()-100)
        dir = 0;
    else if (position <= 0)
        dir = 1;

    if (dir)
        position += 5;
    else
        position -= 5;
}
