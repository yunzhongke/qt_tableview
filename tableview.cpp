/*================================================================
 *   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
 *   
 *   文件名称：tableview.h
 *   创 建 者：yunzhongke
 *   创建日期：2018年04月01日21时
 *   描    述：
 *
 ================================================================*/


#include "tableview.h"
#include <QtWidgets/QDateTimeEdit>
#include <cstdio>

//编号列，只读委托  
//这个方法我还真想不到，呵呵  
ReadOnlyDelegate::ReadOnlyDelegate(QObject *parent ) : QItemDelegate(parent)
{

}
QWidget* ReadOnlyDelegate::createEditor(QWidget *, const QStyleOptionViewItem &,  
        const QModelIndex &) const{
    return NULL;
}

ReadOnlyDelegate::~ReadOnlyDelegate()
{

} 


//ID列，只能输入1－12个数字  
//利用QLineEdit委托和正则表达式对输入进行限制  
UserIDDelegate::UserIDDelegate(QObject *parent): QItemDelegate(parent) { }  
UserIDDelegate::~UserIDDelegate(){}
QWidget* UserIDDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,  
        const QModelIndex &) const  
{  
    QLineEdit *editor = new QLineEdit(parent);  
    QRegExp regExp("[0-9]{0,10}");  
    editor->setValidator(new QRegExpValidator(regExp, parent));  
    return editor;  
}  
void UserIDDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const  
{  
    QString text = index.model()->data(index, Qt::EditRole).toString();  
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);  
    lineEdit->setText(text);  
}  
void UserIDDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  
{  
    QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);  
    QString text = lineEdit->text();  
    model->setData(index, text, Qt::EditRole);  
}  
void UserIDDelegate::updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  
{  
    editor->setGeometry(option.rect);  
}  

//时间
TimeDelegate::TimeDelegate(QObject *parent):QItemDelegate(parent){

}
TimeDelegate::~TimeDelegate(){}
QWidget* TimeDelegate::createEditor(QWidget* parent , const QStyleOptionViewItem& , const QModelIndex&) const{
    QDateTimeEdit *time = new QDateTimeEdit(QDate::currentDate() , parent);    
    time->setDisplayFormat("HH:mm:ss");
    return time;
}
void TimeDelegate::setEditorData(QWidget* editor , const QModelIndex &index)const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    printf("value:%s\n" , value.toStdString().c_str());
    QDateTimeEdit *time = static_cast<QDateTimeEdit*>(editor);  
    QTime data = QTime::fromString(value);
    time->setTime(data);  
}
void TimeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  
{  
    QDateTimeEdit *time = static_cast<QDateTimeEdit*>(editor);  
    QTime data = time->time();
    model->setData(index, data, Qt::EditRole);  
}  
void TimeDelegate::updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  
{  
    editor->setGeometry(option.rect);  
}  

//年龄列，利用QSpinBox委托进行输入限制，只能输入1－100之间的数字  
AgeDelegate::AgeDelegate(QObject *parent ): QItemDelegate(parent) { }  
AgeDelegate::~AgeDelegate(){}
QWidget* AgeDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,  
        const QModelIndex &) const  
{  
    QSpinBox *editor = new QSpinBox(parent);  
    editor->setMinimum(1);  
    editor->setMaximum(100);  
    return editor;  
}  
void AgeDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const  
{  
    int value = index.model()->data(index, Qt::EditRole).toInt();  
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);  
    spinBox->setValue(value);  
}  
void AgeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  
{  
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);  
    spinBox->interpretText();  
    int value = spinBox->value();  
    model->setData(index, value, Qt::EditRole);  
}  
void AgeDelegate::updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &) const  
{  
    editor->setGeometry(option.rect);  
}  

//性别列，利用QComboBox委托对输入进行限制  
//这一列的单元格只能输入Male或Female  
SexDelegate::SexDelegate(QObject *parent ): QItemDelegate(parent) { }  
SexDelegate::~SexDelegate(){}
QWidget* SexDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,  
        const QModelIndex &index) const  
{  
    QComboBox *editor = new QComboBox(parent);  
    editor->addItem("Female");  
    editor->addItem("Male");  
    return editor;  
}  
void SexDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const  
{  
    QString text = index.model()->data(index, Qt::EditRole).toString();  
    QComboBox *comboBox = static_cast<QComboBox*>(editor);  
    int tindex = comboBox->findText(text);  
    comboBox->setCurrentIndex(tindex);  
}  
void SexDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,  
        const QModelIndex &index) const  
{  
    QComboBox *comboBox = static_cast<QComboBox*>(editor);  
    QString text = comboBox->currentText();  
    model->setData(index, text, Qt::EditRole);  
}  
void SexDelegate::updateEditorGeometry(QWidget *editor,  
        const QStyleOptionViewItem &option, const QModelIndex &index) const  
{  
    editor->setGeometry(option.rect);  
}  

//头像列，只是在单元格中央放一张小图而已  
IconDelegate::IconDelegate(QObject *parent ): QItemDelegate(parent) { }  
IconDelegate::~IconDelegate(){}
void IconDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,  
        const QModelIndex & index ) const  
{  
    //show.bmp是在工程目录中的一张图片（其实就是QQ的图标啦，呵呵）  
    QPixmap pixmap = QPixmap("show.bmp").scaled(24, 24);  
    //->style()->drawItemPixmap(painter, option.rect,  Qt::AlignCenter, QPixmap(pixmap));  
}  

//代理类，把所有单元格中的字符居中显示  
VIPModel::VIPModel(QObject *parent) : QStandardItemModel(parent) { }  
VIPModel::~VIPModel(){}
VIPModel::VIPModel(int row, int column, QObject *parent)  
    : QStandardItemModel(row, column, parent) { }  

    QVariant VIPModel::data(const QModelIndex &index, int role ) const  
{  
    if( Qt::TextAlignmentRole == role )  
        return Qt::AlignCenter;   
    return QStandardItemModel::data(index, role);  
}  

