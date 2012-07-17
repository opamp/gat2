#include "xml.hpp"

bool XmlParser::open(QString& p){
	QDomDocument doc;
	QString error;int errorline;int errorColmun;
	QFile file(p);

	if(!f.open(QIODevice::ReadWrite)){
		return false;
    }


	f.close();
	return true;
}
