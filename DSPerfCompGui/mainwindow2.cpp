#include "mainwindow2.h"

#include <QScrollArea>

//pra criar arquivo
#include <fstream>

#include <QDir>
#include <QMessageBox>

#include <QHBoxLayout>
#include <QTreeWidget>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QApplication>

MainWindow2::MainWindow2(QWidget *parent, SimulationResults simulationResults)
    : QMainWindow(parent),
      simulationResults(simulationResults)
{
    buildGui();
    configureTexts();
    connectEvents();
}

void MainWindow2::buildGui()
{
    this->resize(800, 600);
    centralwidget = new QWidget(this);
    horizontalLayout_2 = new QHBoxLayout(centralwidget);
    horizontalLayout = new QHBoxLayout();
    verticalLayoutOfList = new QVBoxLayout();
    treeWidget = new QTreeWidget(centralwidget);

    for (auto item: simulationResults.vectorOfResultsToType)
    {
        QTreeWidgetItem* topLevelItem = new QTreeWidgetItem(treeWidget);
        treeWidget->addTopLevelItem(topLevelItem);
        topLevelItem->setCheckState(0, Qt::CheckState::Checked);
        topLevelItem->setText(0, item.enumDataStrucutureType.getValue().c_str());
    }

    verticalLayoutOfList->addWidget(treeWidget);

    horizontalLayout->addLayout(verticalLayoutOfList);

    verticalLayoutOfData = new QVBoxLayout();
    groupBox = new QGroupBox(centralwidget);
    horizontalLayout_4 = new QHBoxLayout(groupBox);
    horizontalLayout_3 = new QHBoxLayout();
    label = new QLabel(groupBox);

    horizontalLayout_3->addWidget(label);

    pushButton = new QPushButton(groupBox);

    horizontalLayout_3->addWidget(pushButton);

    horizontalLayout_4->addLayout(horizontalLayout_3);


    verticalLayoutOfData->addWidget(groupBox);

    groupBox_3 = new QGroupBox(centralwidget);
    horizontalLayout_8 = new QHBoxLayout(groupBox_3);
    horizontalLayout_7 = new QHBoxLayout();
    checkBoxXAxis = new QCheckBox(groupBox_3);

    horizontalLayout_7->addWidget(checkBoxXAxis);

    checkBoxYAxys = new QCheckBox(groupBox_3);

    horizontalLayout_7->addWidget(checkBoxYAxys);


    horizontalLayout_8->addLayout(horizontalLayout_7);


    verticalLayoutOfData->addWidget(groupBox_3);

    groupBox_2 = new QGroupBox(centralwidget);
    horizontalLayout_5 = new QHBoxLayout(groupBox_2);
    scrollArea = new QScrollArea(groupBox_2);
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 363, 377));
    horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents);
    labelOfImage = new QLabel(scrollAreaWidgetContents);

    horizontalLayout_6->addWidget(labelOfImage);

    scrollArea->setWidget(scrollAreaWidgetContents);

    horizontalLayout_5->addWidget(scrollArea);


    verticalLayoutOfData->addWidget(groupBox_2);


    horizontalLayout->addLayout(verticalLayoutOfData);


    horizontalLayout_2->addLayout(horizontalLayout);

    this->setCentralWidget(centralwidget);

    /*menubar = new QMenuBar(this);
    menubar->setGeometry(QRect(0, 0, 800, 22));
    this->setMenuBar(menubar);
    statusbar = new QStatusBar(this);
    this->setStatusBar(statusbar);*/
}

void MainWindow2::configureTexts()
{
    std::string title = "Results analyser to ";
    //0-insert, 1-remove,2search
    if (simulationResults.operation == 0)
    {
        title += "INSERTION";
    }
    else if (simulationResults.operation == 1)
    {
        title += "REMOVE";
    }
    else if (simulationResults.operation == 2)
    {
        title += "SEARCH";
    }

    this->setWindowTitle(title.c_str());
    QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
    ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Data Structure", nullptr));

    const bool __sortingEnabled = treeWidget->isSortingEnabled();
    treeWidget->setSortingEnabled(false);

    treeWidget->setSortingEnabled(__sortingEnabled);

    groupBox->setTitle(QApplication::translate("MainWindow", "Update", nullptr));
    label->setText(QApplication::translate("MainWindow", "Update image:", nullptr));
    pushButton->setText(QApplication::translate("MainWindow", "Update Image", nullptr));
    groupBox_3->setTitle(QApplication::translate("MainWindow", "Log operations", nullptr));
    checkBoxXAxis->setText(QApplication::translate("MainWindow", "Apply log in axys-x", nullptr));
    checkBoxYAxys->setText(QApplication::translate("MainWindow", "Apply log in axys-y", nullptr));
    groupBox_2->setTitle(QApplication::translate("MainWindow", "Image", nullptr));
    labelOfImage->setText(QString());
}

void MainWindow2::on_pushButtonClick()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());

    std::vector<EnumDataStructureType> vecOfEnumDataStructureTypeSelected;
    for (auto item: simulationResults.vectorOfResultsToType)
    {
        vecOfEnumDataStructureTypeSelected.push_back(item.enumDataStrucutureType);
    }

    //Criar arquivo com os dados de simulationresults
    std::string data;
    data += "# Gnuplot script file for data structs comparisson\n";
    data += "#Operations ";
    for (auto enumType: vecOfEnumDataStructureTypeSelected)
    {
        data += enumType.getValue()+" ";
    }
    data+="\n";

    for (int index = 0; index < simulationResults.usedCounts.size(); ++index)
    {
        data += std::to_string(simulationResults.usedCounts.at(index)) + " ";

        for (int index2 = 0;
             index2 < simulationResults.vectorOfResultsToType.size();
             ++index2)
        {
            data += std::to_string(simulationResults.vectorOfResultsToType.at(index2).times.at(index));
            data += " ";
        }
        data += "\n";
    }

    //salva no disco
    std::ofstream myfile;
    myfile.open ("file.dat");
    myfile << data;
    myfile.close();

    updateImage();
    renderImage();
}

void MainWindow2::updateImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());

    std::string message = "set terminal png font arial 14 size 800,600;";
    message += "set output 'file.png';";

    if (checkBoxXAxis->isChecked())
    {
        message += "set logscale x;";
    }
    if (checkBoxYAxys->isChecked())
    {
        message += "set logscale y;";
    }

    message += "set xlabel 'Quantity of elements in operation';";
    message += "set ylabel 'Time spent in miliseconds';";


    std::string title = "Results analyser to ";
    //0-insert, 1-remove,2search
    if (simulationResults.operation == 0)
    {
        title += "INSERTION";
    }
    else if (simulationResults.operation == 1)
    {
        title += "REMOVE";
    }
    else if (simulationResults.operation == 2)
    {
        title += "SEARCH";
    }
    message += "set title 'Comparisson of "+title+" to DATA STRUCTURES';";

    std::vector<EnumDataStructureType> vecOfEnumDataStructureTypeSelected;
    for (auto item: simulationResults.vectorOfResultsToType)
    {
        vecOfEnumDataStructureTypeSelected.push_back(item.enumDataStrucutureType);
    }
    for (int index = 0; index < vecOfEnumDataStructureTypeSelected.size(); ++index)
    {
        if (index == 0)
            message += "plot ";

        message += "\"file.dat\" using 1:"+std::to_string(index+2)+
                  " title '"+vecOfEnumDataStructureTypeSelected.at(index).getValue()+"' with linespoints";

        if (index == vecOfEnumDataStructureTypeSelected.size()-1)
            message += ";";
        else if (index < vecOfEnumDataStructureTypeSelected.size()-1)
            message += ", ";
    }

    //salva no disco
    std::ofstream myscriptfile;
    myscriptfile.open ("scfile.dat");
    myscriptfile << message;
    myscriptfile.close();

    std::string message2 = "gnuplot scfile.dat";

    system(message2.c_str());
}

void MainWindow2::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    labelOfImage->setPixmap(image);
    labelOfImage->show();
}

void MainWindow2::connectEvents()
{
    QObject::connect(pushButton, &QPushButton::clicked,
                         this, &MainWindow2::on_pushButtonClick);
}

MainWindow2::~MainWindow2()
{

}

