/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：tableview.h
*   创 建 者：yunzhongke
*   创建日期：2018年04月01日21时
*   描    述：
*
================================================================*/


#ifndef _TABLEVIEW_H
#define _TABLEVIEW_H

#include <iostream>
#include <QtGui/QStandardItemModel>
#include <QtWidgets/QItemDelegate>
#include <QtCore/QModelIndex>
#include <QtCore/QObject>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>

//编号列，只读委托  
//这个方法我还真想不到，呵呵  
class ReadOnlyDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    explicit ReadOnlyDelegate(QObject *parent = NULL);
    virtual QWidget *createEditor(QWidget *, const QStyleOptionViewItem &,  
            const QModelIndex &) const;
      
    ~ReadOnlyDelegate();

};


//ID列，只能输入1－12个数字  
//利用QLineEdit委托和正则表达式对输入进行限制  
class UserIDDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    UserIDDelegate(QObject *parent = 0);
    ~UserIDDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,  
        const QModelIndex &) const; 
    void setEditorData(QWidget *editor, const QModelIndex &index) const ;
    void setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  ;
    void updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  ;
};  
  
//年龄列，利用QSpinBox委托进行输入限制，只能输入1－100之间的数字  
class AgeDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    AgeDelegate(QObject *parent = 0);
    ~AgeDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,  
        const QModelIndex &) const  ;
    void setEditorData(QWidget *editor, const QModelIndex &index) const  ;
    void setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  ;
    void updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  ;
};  

// 时间
class TimeDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    TimeDelegate(QObject *parent = 0);
    ~TimeDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,  
        const QModelIndex &) const  ;
    void setEditorData(QWidget *editor, const QModelIndex &index) const  ;
    void setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  ;
    void updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  ;
};  

  
//性别列，利用QComboBox委托对输入进行限制  
//这一列的单元格只能输入Male或Female  
class SexDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    SexDelegate(QObject *parent = 0);
    ~SexDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,  
        const QModelIndex &index) const  ;
    void setEditorData(QWidget *editor, const QModelIndex &index) const  ;
    void setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  ;
    void updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &index) const  ;
};  
  
//头像列，只是在单元格中央放一张小图而已  
class IconDelegate : public QItemDelegate  
{  
    Q_OBJECT  
public:  
    IconDelegate(QObject *parent = 0);
    ~IconDelegate();
    void paint(QPainter *painter, const QStyleOptionViewItem &option,  
        const QModelIndex & index ) const  ;
};  
  
//代理类，把所有单元格中的字符居中显示  
class VIPModel : public QStandardItemModel  
{  
    Q_OBJECT  
public:  
    VIPModel(QObject *parent=NULL);
    ~VIPModel();
    VIPModel(int row, int column, QObject *parent=NULL);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  
}; 

#endif //TABLEVIEW_H
