#include "weathermainwindow.h"
#include "ui_weathermainwindow.h"

#include "WeatherRequest.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

WeatherMainWindow::WeatherMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeatherMainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("F:/Projects/QT_projects/Weather_forecast_project/clouds.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

WeatherMainWindow::~WeatherMainWindow()
{
    delete ui;
}

// Попытка получить метеорологические данные от сервера с пользовательским вводом места (Города) и вывести их или сообщить об ошибке
void WeatherMainWindow::on_show_weather_clicked()
{
    WeatherRequest weather{"6ba8c96d004d2b5e82c97742cbc2366b"};

    WeatherUnit data{weather.request_weather(ui->place_input->text())};

    if (weather.error() == WeatherRequest::NoError)
    {
        ui->info_error->setText("");

        ui->place_name->setText(data.city);
        ui->place_temperature->setText(QString::number(data.temperature) + "°C");
        ui->place_fltemperature->setText(QString::number(data.tfeels_like) + "°C");
        ui->place_windspeed->setText(QString::number(data.wind_speed) + " метров в секунду");
        ui->place_humidity->setText(QString::number(data.humidity) + "%");
        ui->place_pressure->setText(QString::number(data.pressure * 0.7500615) + " мм рт. ст.");
    }
    else ui->info_error->setText("* Нет ответа от сервера");
}

