#ifndef MAINWINDOWSPOKE_H
#define MAINWINDOWSPOKE_H

#include <QMainWindow>
#include "graphicsview.h"

class MainWindowsPoke : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowsPoke(QWidget *parent = nullptr);
    //destructeur
    virtual ~MainWindowsPoke() throw();

signals:

public slots:

private:
    GraphicsView* view;
};

#endif // MAINWINDOWSPOKE_H
