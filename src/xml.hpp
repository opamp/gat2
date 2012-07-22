#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QMap>
#include<QtXml>
#include<QDomDocument>
#include<QDomNode>
#include<QDomElement>
#include<QDomText>

class XmlParser{
public:
	XmlParser(){};

	bool open(const QString&);

	bool loadXmlData();

	void setAlarmFile(const QString&);
	void setCheckbox(QString&,bool);
	bool save();

	QString getAlarmFile(){return alarmFile;};

	bool getCheckbox(QString t){
		return checkboxes[t];
	};
private:
	void parseFile(QDomNode);
	void parseCheckbox(QDomNode);

	QString fp;
	QDomDocument doc;
//	QFile* file;

protected:
	QMap<QString,bool> checkboxes;
	QString alarmFile;
};

#endif
