#include "countup_box.hpp"

countup_box::countup_box(QWidget* parent):
    QDialog(parent)
{
    p = new QLabel(tr("unset data."));
    b = new QPushButton("OK");
    connect(b,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->addWidget(p);
    mainlayout->addWidget(b);

    setLayout(mainlayout);

}

void countup_box::setData(ctd_d* td){
    QString h,m,s;
    h.setNum(td->get_h());
    m.setNum(td->get_m());
    s.setNum(td->get_s());
    QString str = "<h1>" + h + "[hour] " + m + "[min] " + s + "[sec]</h1>";
    p->setText(str);
}
