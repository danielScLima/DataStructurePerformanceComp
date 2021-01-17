#include "mainwindow.h"
#include "mainwindow2.h"
#include <QMessageBox>

#include "headers/datastructureenumtypes.h"
#include "headers/comparissonrunner.h"

//pra criar arquivo
#include <fstream>

#include <QTreeWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    buildGui();
    configureTexts();
    connectEvents();
}

MainWindow::~MainWindow()
{

}

void MainWindow::triggerEvent(int optionToRun)
{
    std::vector<EnumDataStructureType> vecOfEnumDataStructureTypeSelected;
    for(int index = 0;index<treeWidget->topLevelItemCount();++index)
    {
        QTreeWidgetItem *qtreewidgetTopItem = treeWidget->topLevelItem(index);

        for (int index2 = 0; index2 < qtreewidgetTopItem->childCount();++index2)
        {
            QTreeWidgetItem *subItem = qtreewidgetTopItem->child(index2);
            if (subItem->checkState(0) == Qt::CheckState::Checked)
            {
                EnumDataStructureType type =
                        vectorOfSetOfDataStructures.at(index).vecOfEnum.at(index2);
                vecOfEnumDataStructureTypeSelected.push_back(type);
            }
        }
    }

    //Consider the queue as the selected tree
    ComparissonRunner compRunner;

    try
    {
        SimulationResults simulationResults = compRunner.run
        (
            optionToRun, //0-insert, 1-remove,2search
            vecOfEnumDataStructureTypeSelected
        );

        MainWindow2* mw2 = new MainWindow2(this, simulationResults);
        mw2->show();
    }
    catch(std::runtime_error ex)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Atention");
        msgBox.setText("The following data structure does not have the required operation: "+QString(ex.what()));
        msgBox.exec();
    }
}

void MainWindow::on_pushButtonOfInsertinTest_clicked()
{
    triggerEvent(0); //0-insert, 1-remove,2search
}

void MainWindow::on_pushButtonOfRemoveinTest_clicked()
{
    triggerEvent(1); //0-insert, 1-remove,2search
}

void MainWindow::on_pushButtonOfSearchinTest_clicked()
{
    triggerEvent(2); //0-insert, 1-remove,2search
}

void MainWindow::selectOrUnselect(QTreeWidgetItem *widgetitem, int v)
{
    bool op = widgetitem->checkState(0) == Qt::CheckState::Checked;

    for (int index = 0; index < widgetitem->childCount(); ++index)
    {
        if (op)
            widgetitem->child(index)->setCheckState(0, Qt::CheckState::Checked);
        else
            widgetitem->child(index)->setCheckState(0, Qt::CheckState::Unchecked);
    }
}

void MainWindow::buildGui()
{
    this->resize(635, 600);
    centralwidget = new QWidget(this);
    horizontalLayout = new QHBoxLayout(centralwidget);
    verticalLayout = new QVBoxLayout();
    groupBox_4 = new QGroupBox(centralwidget);
    verticalLayout_3 = new QVBoxLayout(groupBox_4);
    checkBox = new QCheckBox(groupBox_4);

    verticalLayout_3->addWidget(checkBox);

    treeWidget = new QTreeWidget(groupBox_4);

    for (int index = 0; index < vectorOfSetOfDataStructures.size(); ++index)
    {
        SetOfDataStructures setAtIndex = vectorOfSetOfDataStructures.at(index);

        QTreeWidgetItem *widgetitem = new QTreeWidgetItem(treeWidget);
        widgetitem->setCheckState(0, Qt::Unchecked);
        widgetitem->setText(0, setAtIndex.nameOfSet.c_str());

        for (int index2=0; index2<setAtIndex.vecOfEnum.size(); ++index2)
        {
            auto entry = setAtIndex.vecOfEnum.at(index2);
            QTreeWidgetItem *subwidgetitem = new QTreeWidgetItem(widgetitem);
            subwidgetitem->setCheckState(0, Qt::Unchecked);
            subwidgetitem->setText(0, entry.getValue().c_str());
        }
    }

    verticalLayout_3->addWidget(treeWidget);

    verticalLayout->addWidget(groupBox_4);

    horizontalLayout->addLayout(verticalLayout);

    verticalLayout_2 = new QVBoxLayout();
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
    groupBox = new QGroupBox(centralwidget);
    horizontalLayout_4 = new QHBoxLayout(groupBox);
    horizontalLayout_3 = new QHBoxLayout();
    label = new QLabel(groupBox);

    horizontalLayout_3->addWidget(label);

    pushButtonOfInsertinTest = new QPushButton(groupBox);

    horizontalLayout_3->addWidget(pushButtonOfInsertinTest);


    horizontalLayout_4->addLayout(horizontalLayout_3);


    horizontalLayout_2->addWidget(groupBox);


    verticalLayout_2->addLayout(horizontalLayout_2);

    groupBox_2 = new QGroupBox(centralwidget);
    horizontalLayout_6 = new QHBoxLayout(groupBox_2);
    horizontalLayout_5 = new QHBoxLayout();
    label_2 = new QLabel(groupBox_2);

    horizontalLayout_5->addWidget(label_2);

    pushButtonOfRemoveTest = new QPushButton(groupBox_2);

    horizontalLayout_5->addWidget(pushButtonOfRemoveTest);


    horizontalLayout_6->addLayout(horizontalLayout_5);


    verticalLayout_2->addWidget(groupBox_2);

    groupBox_3 = new QGroupBox(centralwidget);
    horizontalLayout_8 = new QHBoxLayout(groupBox_3);
    horizontalLayout_7 = new QHBoxLayout();
    label_3 = new QLabel(groupBox_3);

    horizontalLayout_7->addWidget(label_3);

    pushButtonOfSearchTest = new QPushButton(groupBox_3);

    horizontalLayout_7->addWidget(pushButtonOfSearchTest);


    horizontalLayout_8->addLayout(horizontalLayout_7);


    verticalLayout_2->addWidget(groupBox_3);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer);


    horizontalLayout->addLayout(verticalLayout_2);

    this->setCentralWidget(centralwidget);

    /*menubar = new QMenuBar(this);
    menubar->setGeometry(QRect(0, 0, 635, 22));
    this->setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    this->setStatusBar(statusbar);*/
}

void MainWindow::configureTexts()
{
    this->setWindowTitle("Data structure performance comparator");
    groupBox_4->setTitle("List of data structures");
    checkBox->setText("Select/Unselect all");
    QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
    ___qtreewidgetitem->setText(0, "Data structure");

    const bool __sortingEnabled = treeWidget->isSortingEnabled();
    treeWidget->setSortingEnabled(false);

    treeWidget->setSortingEnabled(__sortingEnabled);

    groupBox->setTitle("Analysis of insertion");
    label->setText("Make analysis of insertion:");
    pushButtonOfInsertinTest->setText("Make");
    groupBox_2->setTitle("Analysis of remove");
    label_2->setText("Make analysis of remove:");
    pushButtonOfRemoveTest->setText("Make");
    groupBox_3->setTitle("Analysis of search");
    label_3->setText("Make analysis of search:");
    pushButtonOfSearchTest->setText("Make");
}

void MainWindow::selectAllChanged(bool var)
{
    for(int index = 0;index<treeWidget->topLevelItemCount();++index)
    {
        QTreeWidgetItem *qtreewidgetTopItem = treeWidget->topLevelItem(index);
        qtreewidgetTopItem->setCheckState
        (
            0, var ? Qt::CheckState::Checked:Qt::CheckState::Unchecked
        );
    }
}

void MainWindow::connectEvents()
{
    QObject::connect(pushButtonOfInsertinTest, &QPushButton::clicked,
                         this, &MainWindow::on_pushButtonOfInsertinTest_clicked);

    QObject::connect(pushButtonOfRemoveTest, &QPushButton::clicked,
                         this, &MainWindow::on_pushButtonOfRemoveinTest_clicked);

    QObject::connect(pushButtonOfSearchTest, &QPushButton::clicked,
                         this, &MainWindow::on_pushButtonOfSearchinTest_clicked);

    QObject::connect(treeWidget, &QTreeWidget::itemChanged,
            this, &MainWindow::selectOrUnselect);

    connect(checkBox, SIGNAL(toggled(bool)),
            this, SLOT(selectAllChanged(bool)));
}
