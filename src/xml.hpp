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
	XmlParser(){initConfigData();};
	void initConfigData();

	bool open(const QString&);
//	void close();

	bool loadXmlData();

	void setAlarmFile(const QString&);
	void setCheckbox(QString&,bool);
	bool save();
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
