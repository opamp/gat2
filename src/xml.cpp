#include "xml.hpp"

void XmlParser::initConfigData(){
	checkboxes["notification"] = true;
}

bool XmlParser::open(QString& p){
	QString error;int errorline;int errorColmun;
	file->setFileName(p);
	if(!file->open(QIODevice::ReadWrite)){
		return false;
    }
	if(!doc.setContent(file,true,&error,&errorline,&errorColmun)){
		file->close();
		return false;
	}


	return true;
}

void XmlParser::close(){
	file->close();
}

bool XmlParser::loadXmlData(){
	QDomElement root = doc.documentElement();
	if(root.tagName().toStdString() != "gat"){
		return false;
	}
	
	QDomNode node = root.firstChild();
	while(!node.isNull()){
		if(node.toElement().tagName().toStdString() == "file"){
			//file
			this->parseFile(node);
		}else if(node.toElement().tagName().toStdString() == "checkbox"){
			//checkbox
			this->parseCheckbox(node);
		}else{
			// else
		}
		node = node.nextSibling();
	}
	return true;
}

void XmlParser::parseFile(QDomNode n){
	QDomNode node = n.toElement().firstChild();
	while(!node.isNull()){
		if(node.toElement().tagName().toStdString() == "AlarmFile"){
			if(node.toElement().text().isEmpty() != true)
				alarmFile = node.toElement().text();
		}
		node = node.nextSibling();
	}
}

void XmlParser::parseCheckbox(QDomNode n){
	QDomNode node = n.toElement().firstChild();
	while(!node.isNull()){
		if(node.toElement().tagName().toStdString() == "notification"){
			if(node.toElement().attribute(QString::fromStdString("enable"),QString::fromStdString("true")) == "true"){
				checkboxes["notification"] = true;
			}else{
				checkboxes["notification"] = false;
			}
		}
		node = node.nextSibling();
	}
}
