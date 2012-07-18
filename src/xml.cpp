#include "xml.hpp"

bool XmlParser::open(QString& p){
	QDomDocument doc;
	QString error;int errorline;int errorColmun;
	QFile file(p);

	if(!file.open(QIODevice::ReadWrite)){
		return false;
    }


	file.close();
	return true;
}
