#ifndef XML_HPP
#define XML_HPP
#include<QString>
#include<QFile>
#include<QMap>
#include<QtXml>
#include<QDomDocument>
#include<QDomNode>
#include<QDomElement>

class XmlParser{
public:
	XmlParser(){initConfigData();};
	void initConfigData();

	bool open(QString&);
	void close();

	bool loadXmlData();
private:
	void parseFile(QDomNode);
	void parseCheckbox(QDomNode);

	QFile* file;
	QDomDocument doc;

protected:
	QMap<QString,bool> checkboxes;
	QString alarmFile;
};

#endif
