#ifndef WECHATDIALOG_H
#define WECHATDIALOG_H

#include <QDialog>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class WeChatDialog; }
QT_END_NAMESPACE

class WeChatDialog : public QDialog
{
    Q_OBJECT

public:
    WeChatDialog(QWidget *parent = nullptr);
    ~WeChatDialog();

signals:
    void sig_destroy();

private:
    Ui::WeChatDialog *ui;

    void closeEvent(QCloseEvent *);
};
#endif // WECHATDIALOG_H
