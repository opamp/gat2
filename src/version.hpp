#ifndef GAT_VERSION_HPP
#define GAT_VERSION_HPP
#include<QString>

#define gat_version "2.5.3"

const QString config_file_name = ".gat.xml";
const QString config_file_path = QString::fromStdString(QDir::homePath().toStdString() + "/" + config_file_name.toStdString());
const QString template_xml = ":/xmls/resource/xmls/template.xml";

#endif
