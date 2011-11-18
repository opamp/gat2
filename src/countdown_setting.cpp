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

    ok = new QPushButton(tr("OK"));

    QHBoxLayout *mainSpinBoxlayout = new QHBoxLayout();
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainSpinBoxlayout->addWidget(hb);
    mainSpinBoxlayout->addWidget(hl);
    mainSpinBoxlayout->addWidget(mb);
    mainSpinBoxlayout->addWidget(ml);
    mainSpinBoxlayout->addWidget(sb);
    mainSpinBoxlayout->addWidget(sl);

    mainLayout->addLayout(mainSpinBoxlayout);
    mainLayout->addWidget(ok);

    setLayout(mainLayout);
}
