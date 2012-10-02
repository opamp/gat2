#include "EnumeratedTimeView.hpp"

EnumeratedTimeView::EnumeratedTimeView(QWidget* parent):
    QDialog(parent)
{
    MainLabel = new QLabel(tr("unset data."));
    OKButton = new QPushButton(tr("OK"));
    connect(OKButton,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->addWidget(MainLabel);
    mainlayout->addWidget(OKButton);

    setLayout(mainlayout);
	setWindowTitle("Enumerated Time");
}

void EnumeratedTimeView::setData(ctd_d* td){
    QString h,m,s;
    h.setNum(td->get_h());
    m.setNum(td->get_m());
    s.setNum(td->get_s());
    QString str = "<h1>" + h + "[hour] " + m + "[min] " + s + "[sec]</h1>";
    MainLabel->setText(str);
}
