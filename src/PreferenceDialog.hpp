#ifndef CONFIG_DIALOG_HPP
#define CONFIG_DIALOG_HPP
#include <QtGui>
#include <QDialog>
#include <QDir>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <config.hpp>
#include "version.hpp"

class PreferenceDialog : public QDialog{
Q_OBJECT
public:
    PreferenceDialog(QWidget* parnet = 0);

signals:
    void chAudioFile(QString const&);
	void chNotificationCheckBox(bool);

protected slots:
    void audioFileEditCallPathDialogButton_is_Pushed();
	void notificationCheckChanged(int);
private:
    QLabel* audioFileEditLabel;
    QLineEdit* audioFileEdit;
    QPushButton* audioFileEditCallPathDialogButton;
    QString audioFilePath;

    QCheckBox* announcementCheck;

	bool writeToFile(const QString&);

};
#endif
