#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QDialog>
#include<QPushButton>
#include<QComboBox>
#include<QLabel>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QVector>
#include<QMessageBox>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
  MainWindow(QWidget *parent=nullptr);
  ~MainWindow();
private:
   QLabel **currentMarks,*current,*edit;
   QSpinBox **newMarks;
   QComboBox *studentList;
   QPushButton *ok,*exit;
   QVector <QVector<int>> marks;
private slots:
   void OkPressed();
   void BoxChanged();

};

#endif // MAINWINDOW_H
