#include "mainwindowspoke.h"
#include "Scene/pokebatlescene.h"

//----------------------------------------------------------------------
//-----------------------------constructeur-----------------------------
//----------------------------------------------------------------------

MainWindowsPoke::MainWindowsPoke(QWidget *parent) : QMainWindow(parent)
{
    this->view = new GraphicsView(this);
    this->view->setScene(new PokeBatleScene(view));
    this->setCentralWidget(view);
}

//----------------------------------------------------------------------
//------------------------------Destructeur-----------------------------
//----------------------------------------------------------------------

MainWindowsPoke::~MainWindowsPoke() throw(){

}
