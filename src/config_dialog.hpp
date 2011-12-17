#ifndef CONFIG_DIALOG_HPP
#define CONFIG_DIALOG_HPP
#include<QtGui>

/* 予定的ななにか 
 * ここで設定された内容は当初はsignalなどを使ってMainWindowに送る予定だったが、xmlに直接書き出して
 * 設定参照はxmlを読み込むことで行うようにしようか...
 */

class configDialog : public QDialog{
Q_OBJECT
public:
    configDialog(QWidget* parnet = 0);

signals:
    void chAudioFile(QString const&);

protected slots:
    void audioFileEditCallPathDialogButton_is_Pushed();
//    void chAudiofileEdit(const QString&);
private:
    QLabel* audioFileEditLabel;
    QLineEdit* audioFileEdit;
    QPushButton* audioFileEditCallPathDialogButton;
    QString audioFilePath;

};
#endif
