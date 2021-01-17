#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
class QCheckBox;
class QTreeWidget;
class QSpacerItem;
class QLabel;
class QPushButton;
class QComboBox;

class QTreeWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOfInsertinTest_clicked();
    void on_pushButtonOfRemoveinTest_clicked();
    void on_pushButtonOfSearchinTest_clicked();
    void selectOrUnselect(QTreeWidgetItem *widgetitem, int v);
    void selectAllChanged(bool var);

private:
    QGroupBox *groupBox = nullptr;
    QGroupBox *groupBox_2 = nullptr;
    QGroupBox *groupBox_3 = nullptr;
    QGroupBox *groupBox_4 = nullptr;

    QGroupBox *groupBox_5 = nullptr;
    QHBoxLayout *horizontalLayout_10 = nullptr;
    QHBoxLayout *horizontalLayout_9 = nullptr;
    QComboBox* combo = nullptr;

    QWidget *centralwidget = nullptr;
    QHBoxLayout *horizontalLayout = nullptr;
    QVBoxLayout *verticalLayout = nullptr;
    QVBoxLayout *verticalLayout_3 = nullptr;
    QCheckBox *checkBox = nullptr;
    QTreeWidget *treeWidget = nullptr;
    QVBoxLayout *verticalLayout_2 = nullptr;
    QHBoxLayout *horizontalLayout_2 = nullptr;
    QHBoxLayout *horizontalLayout_4 = nullptr;
    QHBoxLayout *horizontalLayout_3 = nullptr;
    QLabel *label = nullptr;
    QPushButton *pushButtonOfInsertinTest = nullptr;
    QHBoxLayout *horizontalLayout_6 = nullptr;
    QHBoxLayout *horizontalLayout_5 = nullptr;
    QLabel *label_2 = nullptr;
    QPushButton *pushButtonOfRemoveTest = nullptr;
    QHBoxLayout *horizontalLayout_8 = nullptr;
    QHBoxLayout *horizontalLayout_7 = nullptr;
    QLabel *label_3 = nullptr;
    QPushButton *pushButtonOfSearchTest = nullptr;
    QSpacerItem *verticalSpacer = nullptr;
    QMenuBar *menubar = nullptr;
    QStatusBar *statusbar = nullptr;

    void buildGui();

    void configureTexts();

    void connectEvents();

    int getQuantityOfZeros();

    void triggerEvent(int optionToRun);
};
#endif // MAINWINDOW_H
