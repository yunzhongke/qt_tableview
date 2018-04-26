/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：delegate.h
*   创 建 者：yunzhongke
*   创建日期：2018年04月01日19时
*   描    述：
*
================================================================*/


#ifndef _DELEGATE_H
#define _DELEGATE_H

#include <QtWidgets/QItemDelegate>
#include <QtCore/QModelIndex>
#include <QtCore/QObject>
#include <QtWidgets/QSpinBox>

class SpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
    public:
        SpinBoxDelegate(QObject *parent = 0);

        QWidget *createEditor(QWidget *parent , const QStyleOptionViewItem &option , 
                const QModelIndex &index) const;
        
        void setEditorData(QWidget *edit , const QModelIndex &index) const;

        void setModelData(QWidget *editor , QAbstractItemModel *model , 
                const QModelIndex &index) const;

        void updateEditorGeometry(QWidget *editor , 
                const QStyleOptionViewItem &option , 
                const QModelIndex &index) const;

};

#endif //DELEGATE_H
