#ifndef CONFIG_DIALOG_HPP
#define CONFIG_DIALOG_HPP
#include<QtGui>


class configDialog : public QDialog{
Q_OBJECT
public:
    configDialog(QWidget* parnet = 0);

signals:
    void chAudioFile(QString);

protected slots:
    void audioFileEditCallPathDialogButton_is_Pushed();
    void chAudiofileEdit(const QString&);
private:
    QLabel* audioFileEditLabel;
    QLineEdit* audioFileEdit;
    QPushButton* audioFileEditCallPathDialogButton;
    QString audioFilePath;

};
#endif
