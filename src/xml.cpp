#include "xml.hpp"
#include<QTextStream>
#include<iostream>
#include<QIODevice>

#define save_xml_indent 4


bool XmlParser::open(const QString& p){
	fp = p;
	QFile file(fp);
	QString error;int errorline;int errorColmun;
//	file->setFileName(p);
	if(!file.open(QIODevice::ReadOnly)){
		std::cout<<"fail to file open. file path is "<<p.toStdString()<<std::endl;
		return false;
    }
	if(!doc.setContent(&file,true,&error,&errorline,&errorColmun)){
		file.close();
		std::cout<<"fail to doc.setContent"<<std::endl;
		return false;
	}

	file.close();
	return true;
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


void XmlParser::setAlarmFile(const QString& filename){
	alarmFile = filename;
}

void XmlParser::setCheckbox(QString& v,bool b){
	if(checkboxes.contains(v))
		checkboxes.insert(v,b);
	std::cout<<"b="<<b<<"ch="<<checkboxes[v]<<std::endl;
}

bool XmlParser::save(){
	QDomElement root = doc.documentElement();
	if(root.tagName().toStdString() != "gat"){
		return false;
	}
	QDomElement newroot = doc.createElement("gat");
	doc.replaceChild(newroot,root);

	QDomElement fileElement = doc.createElement("file");
	QDomElement alarmElement = doc.createElement("AlarmFile");
	QDomText alarmtext = doc.createTextNode(this->alarmFile);
	newroot.appendChild(fileElement);
	fileElement.appendChild(alarmElement);
	alarmElement.appendChild(alarmtext);

	QDomElement checkboxElement = doc.createElement("checkbox");
	QDomElement notificationElement = doc.createElement("notification");
	if(checkboxes["notification"] == true){
		notificationElement.setAttribute(QString::fromStdString("enable"),"true");
	}else{
		notificationElement.setAttribute(QString::fromStdString("enable"),"false");
	}
	newroot.appendChild(checkboxElement);
	checkboxElement.appendChild(notificationElement);

	QFile file(fp);
	file.open(QIODevice::WriteOnly);
	QTextStream out(&file);
	doc.save(out,save_xml_indent);
	file.close();
	return true;
}

