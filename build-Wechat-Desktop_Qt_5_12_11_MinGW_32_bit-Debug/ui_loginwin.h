/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_phone;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *le_pass;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_clear;
    QPushButton *pb_login;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *le_phone_r;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *le_pass_r;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_clear_r;
    QPushButton *pb_register;

    void setupUi(QDialog *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QString::fromUtf8("LoginWin"));
        LoginWin->resize(400, 300);
        tabWidget = new QTabWidget(LoginWin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(80, 40, 192, 130));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        le_phone = new QLineEdit(tab);
        le_phone->setObjectName(QString::fromUtf8("le_phone"));

        horizontalLayout->addWidget(le_phone);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        le_pass = new QLineEdit(tab);
        le_pass->setObjectName(QString::fromUtf8("le_pass"));

        horizontalLayout_2->addWidget(le_pass);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_clear = new QPushButton(tab);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));

        horizontalLayout_3->addWidget(pb_clear);

        pb_login = new QPushButton(tab);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));

        horizontalLayout_3->addWidget(pb_login);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        le_phone_r = new QLineEdit(tab_2);
        le_phone_r->setObjectName(QString::fromUtf8("le_phone_r"));

        horizontalLayout_4->addWidget(le_phone_r);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        le_pass_r = new QLineEdit(tab_2);
        le_pass_r->setObjectName(QString::fromUtf8("le_pass_r"));

        horizontalLayout_5->addWidget(le_pass_r);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pb_clear_r = new QPushButton(tab_2);
        pb_clear_r->setObjectName(QString::fromUtf8("pb_clear_r"));

        horizontalLayout_6->addWidget(pb_clear_r);

        pb_register = new QPushButton(tab_2);
        pb_register->setObjectName(QString::fromUtf8("pb_register"));

        horizontalLayout_6->addWidget(pb_register);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(LoginWin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QDialog *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "\346\254\242\350\277\216", nullptr));
        label->setText(QApplication::translate("LoginWin", "\350\264\246\345\217\267\357\274\232", nullptr));
        le_phone->setPlaceholderText(QApplication::translate("LoginWin", "\347\224\265\350\257\235", nullptr));
        label_2->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201\357\274\232", nullptr));
        le_pass->setText(QString());
        pb_clear->setText(QApplication::translate("LoginWin", "\346\270\205\347\251\272", nullptr));
        pb_login->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LoginWin", " \347\231\273\345\275\225", nullptr));
        label_3->setText(QApplication::translate("LoginWin", "\350\264\246\345\217\267\357\274\232", nullptr));
        le_phone_r->setPlaceholderText(QApplication::translate("LoginWin", "\347\224\265\350\257\235", nullptr));
        label_4->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201\357\274\232", nullptr));
        pb_clear_r->setText(QApplication::translate("LoginWin", "\346\270\205\347\251\272", nullptr));
        pb_register->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LoginWin", " \346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
