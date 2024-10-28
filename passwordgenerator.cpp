#include "passwordgenerator.h"
#include "./ui_passwordgenerator.h"

#include <QRandomGenerator>
#include <QMessageBox>
#include <QString>


PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);

    ui->labelLengthDisplay->setText(QString::number(ui->sliderLength->value())); // initialize length display

    connect(ui->btnGenerate, &QPushButton::clicked, this, &PasswordGenerator::generatePassword); //connect generate button to gen slot
    connect(ui->sliderLength, &QSlider::valueChanged, this, &PasswordGenerator::updateLengthLabel); // connect slider to update slot
}

PasswordGenerator::~PasswordGenerator()
{
    delete ui;
}

void PasswordGenerator::generatePassword(){

    QString password;
    int passLength = ui->sliderLength->value();

    //character sets
    QString lower = "abcdefghijklmnopqrstuvwxyz";
    QString numbers = "1234567890";
    QString upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString special = "[]{}|;:,.<>?!@#$%^&*()_+-=";

    QString customSelection;

    // build custom selection based on checkbox
    if (ui->checkboxNumbers->isChecked()) {
        customSelection += numbers;
    }
    if (ui->checkboxUppercase->isChecked()) {
        customSelection += upper;
    }
    if (ui->checkboxSpecial->isChecked()) {
        customSelection += special;
    }
    // base case
    customSelection += lower;

    // select one random character in custom library until length is achieved
    for (int i = 0; i < passLength; ++i) {
        int index = QRandomGenerator::global()->bounded(customSelection.length());
        password.append(customSelection[index]);
    }

    // display password
    ui->labelGeneratedPass->setText(password);
}

//real time length display
void PasswordGenerator::updateLengthLabel(int value){

    ui->labelLengthDisplay->setText(QString::number(value));

}
