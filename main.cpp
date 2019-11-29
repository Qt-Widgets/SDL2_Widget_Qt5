#include <QApplication>

#include <SDL2Widget.h>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>

#undef main
int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

    /* The SDL2Widget must have a parent widget else it doesn't fill
     * the entire widget.
     * You can see the above stated effect by not passing sdlWidgetContainer
     * to the SDL2Widget constructor.
     */
    QWidget* sdlWidgetContainer = new QWidget();
    SDL2Widget* sdlWidget = new SDL2Widget(sdlWidgetContainer);
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(sdlWidget);
    sdlWidgetContainer->setLayout(gridLayout);

    QPushButton* button = new QPushButton("Button");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(sdlWidgetContainer);
    layout->addWidget(button);

    QWidget widget;
    widget.setLayout(layout);
    widget.resize(640, 480);
    widget.show();

	return app.exec();
}
