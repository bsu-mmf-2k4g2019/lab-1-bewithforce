#include "mainwindow.h"
#define STUDENT_CNT 5
#define MARK_CNT 5


MainWindow::MainWindow(QWidget *parent) : QDialog (parent)

{
    this->setWindowTitle("student marks");
    setBaseSize(200, 200);
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    Qt::WindowFlags flags = windowFlags();

    Qt::WindowFlags helpFlag =
    Qt::WindowContextHelpButtonHint;

    flags = flags & (~helpFlag);
    setWindowFlags(flags);

    QGridLayout* mainlayout=new QGridLayout;

    for(int i=0;i<STUDENT_CNT;i++)
    {
        marks.push_back(QVector<int>());
        marks[i].resize(MARK_CNT);
    }

    currentMarks=new QLabel*[MARK_CNT];
    current=new QLabel("Текущий");


    newMarks=new QSpinBox*[MARK_CNT];
    edit=new QLabel("Изменить");

    studentList=new QComboBox;
    for(int i(0);i<STUDENT_CNT;i++)
    {
        studentList->addItem("Студент №"+ QString::number(i + 1) );
    }

    ok=new QPushButton("Сохранить");
    exit=new QPushButton("Выход");

    for(int i(0);i<MARK_CNT;i++)
    {
        currentMarks[i]=new QLabel;
        mainlayout->addWidget(currentMarks[i], i + 1, 0);
    }

    for(int i(0);i<MARK_CNT;i++)
    {
        newMarks[i]=new QSpinBox;
        newMarks[i]->setMaximum(10);
        newMarks[i]->setMinimum(1);
        mainlayout->addWidget(newMarks[i], i + 1, 1);
    }

    mainlayout->addWidget(current, 0, 0);
    mainlayout->addWidget(edit, 0, 1);
    mainlayout->addWidget(studentList, 0, 2);
    mainlayout->addWidget(ok, 4, 2);
    mainlayout->addWidget(exit, 5, 2);


    setLayout(mainlayout);

    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(OkPressed()));
    connect(studentList,SIGNAL(currentIndexChanged(QString)),this,SLOT(BoxChanged()));
}
void MainWindow::OkPressed()
{
    int k=studentList->currentIndex();
    for(int i(0);i<MARK_CNT;i++)
    {
        marks[k].replace(i,newMarks[i]->value());
        currentMarks[i]->setText(QString::number(newMarks[i]->value()));
    }


}
void MainWindow::BoxChanged()
{
    int k=studentList->currentIndex();
    for(int i(0);i<MARK_CNT;i++)
    {

        if(marks [k][i]<=10 && marks [k][i]>=1)
        {
            currentMarks[i]->setText(QString::number(marks[k][i]));
        }

        else
        {
            currentMarks[i]->setText("Undefined");
        }

        newMarks[i]->setValue(1);
    }

}
MainWindow::~MainWindow()
{
    delete newMarks;
    delete currentMarks;
}
