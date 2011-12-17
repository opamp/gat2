#ifndef P_HPP
#define P_HPP
#include<config.hpp>
#include<QString>
#include<QCoreApplication>

#ifdef P_UNIX
#include<sys/types.h>
#include<pwd.h>

QString& getSaveDir(){
	struct passwd *p;
	p = getpwuid(getuid());
	QString homepath = p->pw_home;
	return homepath;
};

#endif
#ifdef P_WIN

QString& gehSaveDir(){
	return QCoreApplication::applicationFilePath();
};

#endif

#endif // end of header.
