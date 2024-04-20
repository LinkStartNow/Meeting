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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeChatDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_tx;
    QLabel *lb_name;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_set;
    QHBoxLayout *horizontalLayout;
    QToolButton *pb_join;
    QToolButton *pb_create;
    QToolButton *pb_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *WeChatDialog)
    {
        if (WeChatDialog->objectName().isEmpty())
            WeChatDialog->setObjectName(QString::fromUtf8("WeChatDialog"));
        WeChatDialog->resize(362, 553);
        WeChatDialog->setMinimumSize(QSize(362, 553));
        verticalLayout = new QVBoxLayout(WeChatDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WeChatDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("color: rgb(85, 255, 255);\n"
"border-color: rgb(255, 255, 127);"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pb_tx = new QPushButton(widget);
        pb_tx->setObjectName(QString::fromUtf8("pb_tx"));
        pb_tx->setMinimumSize(QSize(60, 60));
        pb_tx->setMaximumSize(QSize(60, 60));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tx/37.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pb_tx->setIcon(icon);
        pb_tx->setIconSize(QSize(60, 60));
        pb_tx->setFlat(true);

        horizontalLayout_2->addWidget(pb_tx);

        lb_name = new QLabel(widget);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        lb_name->setFont(font);

        horizontalLayout_2->addWidget(lb_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pb_set = new QPushButton(widget);
        pb_set->setObjectName(QString::fromUtf8("pb_set"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/sett.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_set->setIcon(icon1);
        pb_set->setIconSize(QSize(30, 30));
        pb_set->setFlat(true);

        horizontalLayout_2->addWidget(pb_set);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pb_join = new QToolButton(widget);
        pb_join->setObjectName(QString::fromUtf8("pb_join"));
        pb_join->setMinimumSize(QSize(80, 80));
        pb_join->setMaximumSize(QSize(80, 80));
        pb_join->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_join->setIcon(icon2);
        pb_join->setIconSize(QSize(60, 60));
        pb_join->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_join->setAutoRaise(true);

        horizontalLayout->addWidget(pb_join);

        pb_create = new QToolButton(widget);
        pb_create->setObjectName(QString::fromUtf8("pb_create"));
        pb_create->setMinimumSize(QSize(80, 80));
        pb_create->setMaximumSize(QSize(80, 80));
        pb_create->setFont(font);
        pb_create->setIcon(icon2);
        pb_create->setIconSize(QSize(60, 60));
        pb_create->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_create->setAutoRaise(true);

        horizontalLayout->addWidget(pb_create);

        pb_3 = new QToolButton(widget);
        pb_3->setObjectName(QString::fromUtf8("pb_3"));
        pb_3->setMinimumSize(QSize(80, 80));
        pb_3->setMaximumSize(QSize(80, 80));
        pb_3->setFont(font);
        pb_3->setIcon(icon2);
        pb_3->setIconSize(QSize(60, 60));
        pb_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_3->setAutoRaise(true);

        horizontalLayout->addWidget(pb_3);


        verticalLayout_2->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 340, 375));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget);


        retranslateUi(WeChatDialog);

        QMetaObject::connectSlotsByName(WeChatDialog);
    } // setupUi

    void retranslateUi(QDialog *WeChatDialog)
    {
        WeChatDialog->setWindowTitle(QApplication::translate("WeChatDialog", "WeChat", nullptr));
        pb_tx->setText(QString());
        lb_name->setText(QApplication::translate("WeChatDialog", "\346\265\213\350\257\225\344\270\200\344\270\213\345\220\215\345\255\227", nullptr));
        pb_set->setText(QString());
        pb_join->setText(QApplication::translate("WeChatDialog", "\345\212\240\345\205\245\344\274\232\350\256\256", nullptr));
        pb_create->setText(QApplication::translate("WeChatDialog", "\345\277\253\351\200\237\344\274\232\350\256\256", nullptr));
        pb_3->setText(QApplication::translate("WeChatDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeChatDialog: public Ui_WeChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WECHATDIALOG_H
