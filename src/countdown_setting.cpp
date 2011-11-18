#include "countdown_setting.hpp"

countdown_setting::countdown_setting(QWidget *parent):
    QDialog(parent)
{
    h = m = s = as = 0;
    hb = new QSpinBox();
    mb = new QSpinBox();
    sb = new QSpinBox();

    hl = new QLabel(tr("h"));
    ml = new QLabel(tr("m"));
    sl = new QLabel(tr("s"));

    QHBoxLayout *mainlayout = new QHBoxLayout();
    mainlayout->addWidget(hb);
    mainlayout->addWidget(hl);
    mainlayout->addWidget(mb);
    mainlayout->addWidget(ml);
    mainlayout->addWidget(sb);
    mainlayout->addWidget(sl);

    setLayout(mainlayout);
}
