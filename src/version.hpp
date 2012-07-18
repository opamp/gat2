#ifndef GAT_VERSION_HPP
#define GAT_VERSION_HPP
#include<QString>

#define gat_version "2.5.3 dev"

const QString config_file_name = ".gat.xml";//設定ファイル名を指定。2.5.3から有効
const QString config_file_path = QString::fromStdString(QDir::homePath().toStdString() + "/" + config_file_name.toStdString());

#endif
