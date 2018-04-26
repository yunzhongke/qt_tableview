/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：delegate.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年04月01日19时
*   描    述：
*
================================================================*/

#include "delegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) : QItemDelegate(parent){

}

QWidget *SpinBoxDelegate::createEditor(QWidget *parents , 
        const QStyleOptionViewItem & , 
        const QModelIndex &) const{
    QSpinBox *editor = new QSpinBox(parents);
    editor->setMinimum(0);
    editor->setMaximum(100);

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor , 
        const QModelIndex &index) const{
    int value = index.model()->data(index , Qt::EditRole).toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor , 
        QAbstractItemModel *model , 
        const QModelIndex &index) const{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index , value , Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor , 
        const QStyleOptionViewItem &option , 
        const QModelIndex &) const{
    editor->setGeometry(option.rect);
}
