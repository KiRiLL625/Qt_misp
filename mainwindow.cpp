#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shapes.h"
#include <string>
#include <cstdlib>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_circleRadioButton_clicked()
{
    ui->circleGroupBox->setEnabled(true);
    ui->rectangleGroupBox->setEnabled(false);
    ui->triangleGroupBox->setEnabled(false);
}


void MainWindow::on_rectangleRadioButton_clicked()
{
    ui->circleGroupBox->setEnabled(false);
    ui->rectangleGroupBox->setEnabled(true);
    ui->triangleGroupBox->setEnabled(false);
}


void MainWindow::on_triangleRadioButton_clicked()
{
    ui->circleGroupBox->setEnabled(false);
    ui->rectangleGroupBox->setEnabled(false);
    ui->triangleGroupBox->setEnabled(true);
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->circleGroupBox->isEnabled()){
        std::string radiusStr = ui->radiusCircleLineEdit->text().toStdString();
        float radius = atof(radiusStr.c_str());;
        if(radius == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->radiusCircleLineEdit->setText("");
            return;
        }
        Circle circle(radius);
        ui->nameLabel->setText("Фигура: круг");
        ui->perimeterLabel->setText(QString::fromStdString(std::to_string(circle.perimeter())));
        ui->areaLabel->setText(QString::fromStdString(std::to_string(circle.area())));
    }
    if(ui->rectangleGroupBox->isEnabled()){
        std::string widthStr = ui->widthRectangleLineEdit->text().toStdString();
        float width = atof(widthStr.c_str());
        if(width == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->widthRectangleLineEdit->setText("");
            ui->heightRectangleLineEdit->setText("");
            return;
        }
        std::string heightStr = ui->heightRectangleLineEdit->text().toStdString();
        float height = atof(heightStr.c_str());;
        if(height == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->widthRectangleLineEdit->setText("");
            ui->heightRectangleLineEdit->setText("");
            return;
        }
        Rectangle rectangle(width, height);
        ui->nameLabel->setText("Фигура: прямоугольник");
        ui->perimeterLabel->setText(QString::fromStdString(std::to_string(rectangle.perimeter())));
        ui->areaLabel->setText(QString::fromStdString(std::to_string(rectangle.area())));
    }
    if(ui->triangleGroupBox->isEnabled()){
        std::string aStr = ui->aTriangleLineEdit->text().toStdString();
        float a = atof(aStr.c_str());
        if(a == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->aTriangleLineEdit->setText("");
            ui->bTriangleLineEdit->setText("");
            ui->cTriangleLineEdit->setText("");
            return;
        }
        std::string bStr = ui->bTriangleLineEdit->text().toStdString();
        float b = atof(bStr.c_str());;
        if(b == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->aTriangleLineEdit->setText("");
            ui->bTriangleLineEdit->setText("");
            ui->cTriangleLineEdit->setText("");
            return;
        }
        std::string cStr = ui->cTriangleLineEdit->text().toStdString();
        float c = atof(cStr.c_str());
        if(c == 0){
            QMessageBox::warning(this, "Ошибка", "Нужно ввести число!");
            ui->aTriangleLineEdit->setText("");
            ui->bTriangleLineEdit->setText("");
            ui->cTriangleLineEdit->setText("");
            return;
        }
        Triangle triangle(a, b, c);
        ui->nameLabel->setText("Фигура: треугольник");
        ui->perimeterLabel->setText(QString::fromStdString(std::to_string(triangle.perimeter())));
        ui->areaLabel->setText(QString::fromStdString(std::to_string(triangle.area())));
    }
}
