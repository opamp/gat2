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
	XmlParser(){};

	bool open(QString&);
};

#endif
