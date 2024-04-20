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

    void SetInfo(QString name, int icon = 1);

signals:
    void sig_destroy();
    void sig_create();
    void sig_join();

private slots:
    void on_pb_create_clicked();
    void on_pb_join_clicked();

private:
    Ui::WeChatDialog *ui;

    void closeEvent(QCloseEvent *);
};
#endif // WECHATDIALOG_H
