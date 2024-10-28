#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class PasswordGenerator;
}
QT_END_NAMESPACE

class PasswordGenerator : public QMainWindow
{
    Q_OBJECT

public:
    PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();

private:

    // all widgets
    QPushButton *btnGenerate;

    QCheckBox *checkboxNumbers;
    QCheckBox *checkboxUppecase;
    QCheckBox *checkboxSpecial;

    QLabel *labelGeneratedPass;

    QSlider *sliderLength;

    QLabel *labelLengthDisplay;

    // all slots
    void generatePassword();
    void updateLengthLabel(int value);

    Ui::PasswordGenerator *ui;
};
#endif // PASSWORDGENERATOR_H
