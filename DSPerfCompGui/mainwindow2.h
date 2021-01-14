#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>

class QHBoxLayout;
class QVBoxLayout;
class QTreeWidget;
class QGroupBox;
class QLabel;
class QPushButton;
class QCheckBox;
class QScrollArea;

#include "simulationresults.h"

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent, SimulationResults simulationResults);

    void buildGui();

    void configureTexts();

    void connectEvents();

    void on_pushButtonClick();

    ~MainWindow2();

private:
    QWidget *centralwidget = nullptr;
    QHBoxLayout *horizontalLayout_2 = nullptr;
    QHBoxLayout *horizontalLayout = nullptr;
    QVBoxLayout *verticalLayoutOfList = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QVBoxLayout *verticalLayoutOfData = nullptr;
    QGroupBox *groupBox = nullptr;
    QHBoxLayout *horizontalLayout_4 = nullptr;
    QHBoxLayout *horizontalLayout_3 = nullptr;
    QLabel *label = nullptr;
    QPushButton *pushButton = nullptr;
    QGroupBox *groupBox_3 = nullptr;
    QHBoxLayout *horizontalLayout_8 = nullptr;
    QHBoxLayout *horizontalLayout_7 = nullptr;
    QCheckBox *checkBoxXAxis = nullptr;
    QCheckBox *checkBoxYAxys = nullptr;
    QGroupBox *groupBox_2 = nullptr;
    QHBoxLayout *horizontalLayout_5 = nullptr;
    QScrollArea *scrollArea = nullptr;
    QWidget *scrollAreaWidgetContents = nullptr;
    QHBoxLayout *horizontalLayout_6 = nullptr;
    QLabel *labelOfImage = nullptr;
    QMenuBar *menubar = nullptr;
    QStatusBar *statusbar = nullptr;

    SimulationResults simulationResults;
    void updateImage();
    void renderImage();
};
#endif // MAINWINDOW2_H
