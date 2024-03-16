#ifndef WECHATDIALOG_H
#define WECHATDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class WeChatDialog; }
QT_END_NAMESPACE

class WeChatDialog : public QDialog
{
    Q_OBJECT

public:
    WeChatDialog(QWidget *parent = nullptr);
    ~WeChatDialog();

private:
    Ui::WeChatDialog *ui;
};
#endif // WECHATDIALOG_H
