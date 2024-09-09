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
#include <QComboBox>
#include <math.h>
#include <QSpinBox>

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

int MainWindow::getQuantityOfZeros()
{
    return combo->currentIndex() + 1;
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
            vecOfEnumDataStructureTypeSelected,
            getVectorOfSelectedOptions()
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

void MainWindow::showMessage(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox::information(parent, title, message);
}

void MainWindow::on_pushButtonOfInsertinTest_clicked()
{
    if (getCountOfSelectedOptions() == 0)
    {
        showMessage(this, "Atenção", "Selecione pelo menos uma quantidade de elementos");
    }
    else
        triggerEvent(0); //0-insert, 1-remove,2search
}

void MainWindow::on_pushButtonOfRemoveinTest_clicked()
{
    if (getCountOfSelectedOptions() == 0)
    {
        showMessage(this, "Atenção", "Selecione pelo menos uma quantidade de elementos");
    }
    else
        triggerEvent(1); //0-insert, 1-remove,2search
}

void MainWindow::on_pushButtonOfSearchinTest_clicked()
{
    if (getCountOfSelectedOptions() == 0)
    {
        showMessage(this, "Atenção", "Selecione pelo menos uma quantidade de elementos");
    }
    else
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

std::vector<int> MainWindow::getVectorOfSelectedOptions()
{
    std::vector<int> options = {};

    if (checkboxTmp1->isChecked())
        options.push_back(spinBox1->value());
    if (checkboxTmp2->isChecked())
        options.push_back(spinBox2->value());
    if (checkboxTmp3->isChecked())
        options.push_back(spinBox3->value());
    if (checkboxTmp4->isChecked())
        options.push_back(spinBox4->value());

    return options;
}

std::vector<int> MainWindow::getVectorOfDefaultOptions()
{
    std::vector<int> options = {100000, 150000, 200000, 250000};
    return options;
}

int MainWindow::getCountOfSelectedOptions()
{
    int count = 0;
    if (checkboxTmp1->isChecked())
        count++;
    if (checkboxTmp2->isChecked())
        count++;
    if (checkboxTmp3->isChecked())
        count++;
    if (checkboxTmp4->isChecked())
        count++;
    return count;
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

    //start of groupBox_3
    groupBox_3 = new QGroupBox(centralwidget);
    horizontalLayout_8 = new QHBoxLayout(groupBox_3);
    horizontalLayout_7 = new QHBoxLayout();
    label_3 = new QLabel(groupBox_3);

    horizontalLayout_7->addWidget(label_3);

    pushButtonOfSearchTest = new QPushButton(groupBox_3);

    horizontalLayout_7->addWidget(pushButtonOfSearchTest);


    horizontalLayout_8->addLayout(horizontalLayout_7);


    verticalLayout_2->addWidget(groupBox_3);
    //end of groupBox_3

    //begin of groupBox_5
    groupBox_5 = new QGroupBox(centralwidget);//9(7) e 10(8)

    newVertLQuantEntr = new QVBoxLayout();
    std::vector<int> options = getVectorOfDefaultOptions();

    //inserindo opção 1
    QHBoxLayout* tmp1 = new QHBoxLayout();
    checkboxTmp1 = new QCheckBox("Enable", groupBox_5);
    tmp1->addWidget(checkboxTmp1);
    // Criando um QSpinBox
    spinBox1 = new QSpinBox(groupBox_5);
    // Definindo o valor mínimo e máximo para o QSpinBox
    spinBox1->setMinimum(10000);
    spinBox1->setMaximum(1000000);
    spinBox1->setValue(options[0]);
    tmp1->addWidget(spinBox1);
    newVertLQuantEntr->addLayout(tmp1);

    //inserindo opção 2
    QHBoxLayout* tmp2 = new QHBoxLayout();
    checkboxTmp2 = new QCheckBox("Enable", groupBox_5);
    tmp2->addWidget(checkboxTmp2);
    // Criando um QSpinBox
    spinBox2 = new QSpinBox(groupBox_5);
    // Definindo o valor mínimo e máximo para o QSpinBox
    spinBox2->setMinimum(10000);
    spinBox2->setMaximum(1000000);
    spinBox2->setValue(options[1]);
    tmp2->addWidget(spinBox2);
    newVertLQuantEntr->addLayout(tmp2);

    //inserindo opção 3
    QHBoxLayout* tmp3 = new QHBoxLayout();
    checkboxTmp3 = new QCheckBox("Enable", groupBox_5);
    tmp3->addWidget(checkboxTmp3);
    // Criando um QSpinBox
    spinBox3 = new QSpinBox(groupBox_5);
    // Definindo o valor mínimo e máximo para o QSpinBox
    spinBox3->setMinimum(10000);
    spinBox3->setMaximum(1000000);
    spinBox3->setValue(options[2]);
    tmp3->addWidget(spinBox3);
    newVertLQuantEntr->addLayout(tmp3);

    //inserindo opção 4
    QHBoxLayout* tmp4 = new QHBoxLayout();
    checkboxTmp4 = new QCheckBox("Enable", groupBox_5);
    tmp4->addWidget(checkboxTmp4);
    // Criando um QSpinBox
    spinBox4 = new QSpinBox(groupBox_5);
    // Definindo o valor mínimo e máximo para o QSpinBox
    spinBox4->setMinimum(10000);
    spinBox4->setMaximum(1000000);
    spinBox4->setValue(options[3]);
    tmp4->addWidget(spinBox4);
    newVertLQuantEntr->addLayout(tmp4);


    /*for (int option: options)
    {
        QHBoxLayout* tmp = new QHBoxLayout();

        QCheckBox *checkboxTmp = new QCheckBox("Enable", groupBox_5);
        tmp->addWidget(checkboxTmp);

        // Criando um QSpinBox
        QSpinBox *spinBox = new QSpinBox(groupBox_5);

        // Definindo o valor mínimo e máximo para o QSpinBox
        spinBox->setMinimum(10000);
        spinBox->setMaximum(1000000);
        tmp->addWidget(spinBox);

        newVertLQuantEntr->addLayout(tmp);
    }*/

    groupBox_5->setLayout(newVertLQuantEntr);

    /*horizontalLayout_10 = new QHBoxLayout(groupBox_5);
    horizontalLayout_9 = new QHBoxLayout();
    combo = new QComboBox(groupBox_5);
    std::vector<int> options = {0, 100000, 150000, 200000, 250000};
    for(int index=1;index<options.size();++index)
    {
        //combo->insertItem(index-1, QString::number(pow(10,index),'d',0));
        combo->insertItem(
            index-1,
            QString::number(options[index])
        );
    }
    combo->setCurrentIndex(3);
    horizontalLayout_9->addWidget(combo);
    horizontalLayout_10->addLayout(horizontalLayout_9);*/
    verticalLayout_2->addWidget(groupBox_5);
    //end of groupBox_5

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

    groupBox_5->setTitle("Quantity of entries:");
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
