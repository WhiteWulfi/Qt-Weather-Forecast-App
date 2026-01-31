#ifndef WEATHERMAINWINDOW_H
#define WEATHERMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class WeatherMainWindow;
}
QT_END_NAMESPACE

class WeatherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    WeatherMainWindow(QWidget *parent = nullptr);
    ~WeatherMainWindow();

private slots:
    void on_show_weather_clicked();

private:
    Ui::WeatherMainWindow *ui;
};
#endif // WEATHERMAINWINDOW_H
