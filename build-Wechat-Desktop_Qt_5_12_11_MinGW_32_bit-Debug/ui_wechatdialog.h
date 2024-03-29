/********************************************************************************
** Form generated from reading UI file 'wechatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WECHATDIALOG_H
#define UI_WECHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_WeChatDialog
{
public:

    void setupUi(QDialog *WeChatDialog)
    {
        if (WeChatDialog->objectName().isEmpty())
            WeChatDialog->setObjectName(QString::fromUtf8("WeChatDialog"));
        WeChatDialog->resize(400, 300);

        retranslateUi(WeChatDialog);

        QMetaObject::connectSlotsByName(WeChatDialog);
    } // setupUi

    void retranslateUi(QDialog *WeChatDialog)
    {
        WeChatDialog->setWindowTitle(QApplication::translate("WeChatDialog", "WeChatDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeChatDialog: public Ui_WeChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATDIALOG_H
