#ifndef SDL2WIDGET_H
#define SDL2WIDGET_H

#include <SDL.h>
#include <QWidget>
#include <QTimer>

class SDL2Widget : public QWidget
{
	Q_OBJECT    
public:
    SDL2Widget(QWidget* parent = nullptr);
	~SDL2Widget();

private:	
    SDL_Window *sdlWindow;
    SDL_Renderer *sdlRenderer;

private:
    QTimer* timer;
    int position;
    int dir;

private slots:
    void Render();
};


#endif
