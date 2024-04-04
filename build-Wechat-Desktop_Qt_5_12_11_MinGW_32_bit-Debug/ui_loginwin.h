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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QHBoxLayout *horizontalLayout_7;
    QLabel *lb_Icon;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_phone;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_pass;
    QLineEdit *le_pass;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pb_clear;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_login;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QPushButton *pb_clear_r;
    QPushButton *pb_register;
    QLabel *lb_pass_r;
    QLabel *lb_name_r;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *le_pass_r;
    QLabel *lb_phone_r;
    QLabel *lb_pass_rp;
    QLineEdit *le_name_r;
    QLineEdit *le_phone_r;
    QLineEdit *le_pass_rp;

    void setupUi(QDialog *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QString::fromUtf8("LoginWin"));
        LoginWin->resize(512, 318);
        LoginWin->setMinimumSize(QSize(512, 318));
        LoginWin->setMaximumSize(QSize(512, 318));
        horizontalLayout_7 = new QHBoxLayout(LoginWin);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lb_Icon = new QLabel(LoginWin);
        lb_Icon->setObjectName(QString::fromUtf8("lb_Icon"));
        lb_Icon->setMinimumSize(QSize(167, 300));
        lb_Icon->setMaximumSize(QSize(167, 300));
        lb_Icon->setPixmap(QPixmap(QString::fromUtf8(":/images/register.png")));
        lb_Icon->setScaledContents(true);

        horizontalLayout_7->addWidget(lb_Icon);

        tabWidget = new QTabWidget(LoginWin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
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
        lb_pass = new QLabel(tab);
        lb_pass->setObjectName(QString::fromUtf8("lb_pass"));

        horizontalLayout_2->addWidget(lb_pass);

        le_pass = new QLineEdit(tab);
        le_pass->setObjectName(QString::fromUtf8("le_pass"));
        le_pass->setEchoMode(QLineEdit::Password);
        le_pass->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(le_pass);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pb_clear = new QPushButton(tab);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));

        horizontalLayout_3->addWidget(pb_clear);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pb_login = new QPushButton(tab);
        pb_login->setObjectName(QString::fromUtf8("pb_login"));

        horizontalLayout_3->addWidget(pb_login);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pb_clear_r = new QPushButton(tab_2);
        pb_clear_r->setObjectName(QString::fromUtf8("pb_clear_r"));

        gridLayout->addWidget(pb_clear_r, 4, 0, 1, 5);

        pb_register = new QPushButton(tab_2);
        pb_register->setObjectName(QString::fromUtf8("pb_register"));

        gridLayout->addWidget(pb_register, 4, 6, 1, 1);

        lb_pass_r = new QLabel(tab_2);
        lb_pass_r->setObjectName(QString::fromUtf8("lb_pass_r"));

        gridLayout->addWidget(lb_pass_r, 2, 0, 1, 1);

        lb_name_r = new QLabel(tab_2);
        lb_name_r->setObjectName(QString::fromUtf8("lb_name_r"));

        gridLayout->addWidget(lb_name_r, 1, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 5, 1, 1);

        le_pass_r = new QLineEdit(tab_2);
        le_pass_r->setObjectName(QString::fromUtf8("le_pass_r"));
        le_pass_r->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_pass_r, 2, 3, 1, 4);

        lb_phone_r = new QLabel(tab_2);
        lb_phone_r->setObjectName(QString::fromUtf8("lb_phone_r"));

        gridLayout->addWidget(lb_phone_r, 0, 0, 1, 1);

        lb_pass_rp = new QLabel(tab_2);
        lb_pass_rp->setObjectName(QString::fromUtf8("lb_pass_rp"));

        gridLayout->addWidget(lb_pass_rp, 3, 0, 1, 3);

        le_name_r = new QLineEdit(tab_2);
        le_name_r->setObjectName(QString::fromUtf8("le_name_r"));

        gridLayout->addWidget(le_name_r, 1, 3, 1, 4);

        le_phone_r = new QLineEdit(tab_2);
        le_phone_r->setObjectName(QString::fromUtf8("le_phone_r"));

        gridLayout->addWidget(le_phone_r, 0, 3, 1, 4);

        le_pass_rp = new QLineEdit(tab_2);
        le_pass_rp->setObjectName(QString::fromUtf8("le_pass_rp"));
        le_pass_rp->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(le_pass_rp, 3, 3, 1, 4);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_7->addWidget(tabWidget);

        QWidget::setTabOrder(le_phone, le_pass);
        QWidget::setTabOrder(le_pass, pb_clear);
        QWidget::setTabOrder(pb_clear, pb_login);
        QWidget::setTabOrder(pb_login, le_phone_r);
        QWidget::setTabOrder(le_phone_r, le_name_r);
        QWidget::setTabOrder(le_name_r, le_pass_r);
        QWidget::setTabOrder(le_pass_r, le_pass_rp);
        QWidget::setTabOrder(le_pass_rp, pb_clear_r);
        QWidget::setTabOrder(pb_clear_r, pb_register);
        QWidget::setTabOrder(pb_register, tabWidget);

        retranslateUi(LoginWin);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QDialog *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "\346\254\242\350\277\216\347\231\273\345\275\225", nullptr));
        lb_Icon->setText(QString());
        label->setText(QApplication::translate("LoginWin", "\347\224\265\350\257\235\357\274\232  ", nullptr));
#ifndef QT_NO_TOOLTIP
        le_phone->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\350\257\267\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_phone->setText(QApplication::translate("LoginWin", "15958206062", nullptr));
        le_phone->setPlaceholderText(QString());
        lb_pass->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201\357\274\232  ", nullptr));
#ifndef QT_NO_TOOLTIP
        le_pass->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_pass->setText(QString());
        pb_clear->setText(QApplication::translate("LoginWin", "\346\270\205\347\251\272", nullptr));
        pb_login->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("LoginWin", "\347\231\273\345\275\225", nullptr));
        pb_clear_r->setText(QApplication::translate("LoginWin", "\346\270\205\347\251\272", nullptr));
        pb_register->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", nullptr));
        lb_pass_r->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201\357\274\232", nullptr));
        lb_name_r->setText(QApplication::translate("LoginWin", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        le_pass_r->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\350\257\267\350\256\276\347\275\256\345\257\206\347\240\201</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_pass_r->setText(QApplication::translate("LoginWin", "123", nullptr));
        lb_phone_r->setText(QApplication::translate("LoginWin", "\347\224\265\350\257\235\357\274\232", nullptr));
        lb_pass_rp->setText(QApplication::translate("LoginWin", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
#ifndef QT_NO_TOOLTIP
        le_name_r->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215\347\224\261\346\225\260\345\255\227\343\200\201\345\255\227\347\254\246\343\200\201\344\270\213\345\210\222\347\272\277\347\273\204\346\210\220</p><p>\351\225\277\345\272\246\344\270\215\350\266\205\350\277\20710</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_name_r->setText(QApplication::translate("LoginWin", "\344\270\215\347\237\245\351\201\223.", nullptr));
        le_name_r->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        le_phone_r->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\350\257\267\350\276\223\345\205\24511\344\275\215\346\211\213\346\234\272\345\217\267</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_phone_r->setText(QApplication::translate("LoginWin", "15958206062", nullptr));
        le_phone_r->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        le_pass_rp->setToolTip(QApplication::translate("LoginWin", "<html><head/><body><p>\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\344\270\200\344\270\213\345\257\206\347\240\201</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        le_pass_rp->setText(QApplication::translate("LoginWin", "123", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("LoginWin", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
