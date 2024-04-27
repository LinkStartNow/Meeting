/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <usershow.h>

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_room;
    QPushButton *pb_hide;
    QPushButton *pb_show;
    QPushButton *pb_exit;
    QHBoxLayout *horizontalLayout;
    QWidget *wd_user_big;
    QHBoxLayout *horizontalLayout_4;
    UserShow *wd_user_show;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *wd_list;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cb_video;
    QCheckBox *cb_audio;
    QCheckBox *cb_desk;
    QComboBox *cb_moij;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName(QString::fromUtf8("RoomDialog"));
        RoomDialog->resize(537, 330);
        RoomDialog->setMinimumSize(QSize(537, 330));
        RoomDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RoomDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(537, 35));
        widget->setMaximumSize(QSize(16777215, 35));
        widget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lb_room = new QLabel(widget);
        lb_room->setObjectName(QString::fromUtf8("lb_room"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        lb_room->setFont(font);

        horizontalLayout_2->addWidget(lb_room);

        pb_hide = new QPushButton(widget);
        pb_hide->setObjectName(QString::fromUtf8("pb_hide"));
        pb_hide->setMinimumSize(QSize(30, 30));
        pb_hide->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        pb_hide->setFont(font1);

        horizontalLayout_2->addWidget(pb_hide);

        pb_show = new QPushButton(widget);
        pb_show->setObjectName(QString::fromUtf8("pb_show"));
        pb_show->setMinimumSize(QSize(30, 30));
        pb_show->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(16);
        pb_show->setFont(font2);

        horizontalLayout_2->addWidget(pb_show);

        pb_exit = new QPushButton(widget);
        pb_exit->setObjectName(QString::fromUtf8("pb_exit"));
        pb_exit->setMinimumSize(QSize(30, 30));
        pb_exit->setMaximumSize(QSize(30, 30));
        pb_exit->setFont(font1);

        horizontalLayout_2->addWidget(pb_exit);


        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        wd_user_big = new QWidget(RoomDialog);
        wd_user_big->setObjectName(QString::fromUtf8("wd_user_big"));
        wd_user_big->setMinimumSize(QSize(371, 260));
        wd_user_big->setMaximumSize(QSize(16777215, 16777215));
        wd_user_big->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(wd_user_big);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        wd_user_show = new UserShow(wd_user_big);
        wd_user_show->setObjectName(QString::fromUtf8("wd_user_show"));

        horizontalLayout_4->addWidget(wd_user_show);


        horizontalLayout->addWidget(wd_user_big);

        widget_4 = new QWidget(RoomDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(166, 260));
        widget_4->setMaximumSize(QSize(166, 16777215));
        widget_4->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_4);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 164, 258));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        wd_list = new QWidget(scrollAreaWidgetContents);
        wd_list->setObjectName(QString::fromUtf8("wd_list"));

        verticalLayout_3->addWidget(wd_list);

        verticalSpacer = new QSpacerItem(20, 221, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        horizontalLayout->addWidget(widget_4);


        verticalLayout->addLayout(horizontalLayout);

        widget_2 = new QWidget(RoomDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(537, 35));
        widget_2->setMaximumSize(QSize(16777215, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        widget_2->setFont(font3);
        widget_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cb_video = new QCheckBox(widget_2);
        cb_video->setObjectName(QString::fromUtf8("cb_video"));

        horizontalLayout_3->addWidget(cb_video);

        cb_audio = new QCheckBox(widget_2);
        cb_audio->setObjectName(QString::fromUtf8("cb_audio"));

        horizontalLayout_3->addWidget(cb_audio);

        cb_desk = new QCheckBox(widget_2);
        cb_desk->setObjectName(QString::fromUtf8("cb_desk"));

        horizontalLayout_3->addWidget(cb_desk);

        cb_moij = new QComboBox(widget_2);
        cb_moij->addItem(QString());
        cb_moij->addItem(QString());
        cb_moij->addItem(QString());
        cb_moij->setObjectName(QString::fromUtf8("cb_moij"));

        horizontalLayout_3->addWidget(cb_moij);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_2);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QApplication::translate("RoomDialog", "Dialog", nullptr));
        lb_room->setText(QApplication::translate("RoomDialog", "\346\210\277\351\227\264\345\217\267\357\274\23212345678", nullptr));
        pb_hide->setText(QApplication::translate("RoomDialog", "\344\270\200", nullptr));
        pb_show->setText(QApplication::translate("RoomDialog", "\345\217\243", nullptr));
        pb_exit->setText(QApplication::translate("RoomDialog", "X", nullptr));
        cb_video->setText(QApplication::translate("RoomDialog", "\350\247\206\351\242\221", nullptr));
        cb_audio->setText(QApplication::translate("RoomDialog", "\351\237\263\351\242\221", nullptr));
        cb_desk->setText(QApplication::translate("RoomDialog", "\346\241\214\351\235\242", nullptr));
        cb_moij->setItemText(0, QApplication::translate("RoomDialog", "\346\227\240\346\273\244\351\225\234", nullptr));
        cb_moij->setItemText(1, QApplication::translate("RoomDialog", "\345\234\243\350\257\236\345\270\275", nullptr));
        cb_moij->setItemText(2, QApplication::translate("RoomDialog", "\345\205\224\350\200\263\346\234\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
