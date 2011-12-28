#ifndef P_HPP
#define P_HPP
#include<config.hpp>
#include<QString>
#include<QCoreApplication>

#ifdef P_UNIX
extern "C" {
#include<sys/types.h>
#include<pwd.h>
}

QString getHomeDir(){
	struct passwd *p;
	p = getpwuid(getuid());
	QString homepath = p->pw_dir;
	return homepath;
};

QString getSaveDir(){
	QString savedir = getHomeDir();
	savedir += "/.gat2.conf";

	return savedir;
};

#endif
#ifdef P_WIN

QString getHomeDir(){
	QString homepath = getenv("HOME");
	return homepath;
};

QString getSaveDir(){
	QString savedir = getHomeDir();
	savedir += "\\_gat2.conf"
};
#endif

#endif // end of header.
