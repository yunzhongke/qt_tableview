/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年04月01日20时
*   描    述：
*
================================================================*/

/*
// 参考：http://qimo601.iteye.com/blog/1536453

#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtCore/QItemSelectionModel>
#include <QtGui/QStandardItemModel>
#include <QtWidgets/QTableView>
#include "delegate.h"

int main(int argc , char *argv[]){
    QApplication app(argc , argv);

    QStandardItemModel model(4 , 2);
    QTableView tableView;
    tableView.setModel(&model);

    SpinBoxDelegate delegate;
    tableView.setItemDelegate(&delegate);
    tableView.horizontalHeader()->setStretchLastSection(true);
    tableView.verticalHeader()->setStretchLastSection(true);
    for(int row = 0; row < 4; ++row){
        for (int column = 0; column < 2; ++column){
            QModelIndex index = model.index(row , column , QModelIndex());
            model.setData(index , QVariant((row + 1) * (column + 1)));
        }
    }

    tableView.setWindowTitle(QObject::tr("spin box delegate"));
    tableView.show();
    return app.exec();
}*/

#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtCore/QItemSelectionModel>
#include <QtWidgets/QTableView>
#include "tableview.h"

int main(int argc, char *argv[])  
{  
    QApplication app(argc, argv);  
  
    VIPModel *model = new VIPModel(5, 5);  
    QTableView *tableView = new QTableView;  
  
    //把表格的背景调成黄蓝相间  
    //这种方法是在网上看到的，用起来还真方便啊  
    tableView->setAlternatingRowColors(true);  
    tableView->setStyleSheet("QTableView{background-color: rgb(250, 250, 115);"  
        "alternate-background-color: rgb(141, 163, 215);}");  
  
    tableView->setWindowTitle("VIP List");  
    tableView->resize(700, 400);  
    tableView->setModel(model);  
    QStringList headerList;  
    headerList << "No." << "ID" << "Name" << "Age" << "Sex" << "Show";  
    model->setHorizontalHeaderLabels(headerList);  
    tableView->verticalHeader()->setVisible(false);  
    tableView->horizontalHeader()->setStretchLastSection(true);  
  
    //为每一列加载委托  
    ReadOnlyDelegate readonlydelegate;
    tableView->setItemDelegateForColumn(0, &readonlydelegate);  
    UserIDDelegate userIDDelegate;  
    tableView->setItemDelegateForColumn(1, &userIDDelegate);  
    AgeDelegate spinBoxDelegate;  
    tableView->setItemDelegateForColumn(3, &spinBoxDelegate);  
    SexDelegate comboBoxDelegate;  
    tableView->setItemDelegateForColumn(4, &comboBoxDelegate);  
    IconDelegate iconDelegate;  
    tableView->setItemDelegateForColumn(5, &iconDelegate);  
  
    for(int i=0; i<10; i++)  
    {  
        QModelIndex index = model->index(i, i, QModelIndex());  
        model->setData(index, i);  
    }
  
    tableView->show();  
    return app.exec();  
}  
