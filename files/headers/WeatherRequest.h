#ifndef WEATHERREQUEST_H
#define WEATHERREQUEST_H

#include <QString>
#include <QByteArray>
#include <WeatherUnit.h>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "RequestSender.h"

// Класс осуществляющий сетевое взаимодействие клиента (Программы) с сервером (Openweathermap)
class WeatherRequest
{
public:
    enum WeatherError
    {
        NoError,
        ExpectedError
    };

    WeatherRequest(const QString& appid) : _appid{appid}, _error{WeatherError::NoError} {}

    const QString get_appid() const { return _appid; }
    void set_appid(const QString& appid) { _appid = appid; }

    // Главный метод возвращающий единицу данных (День с метеорогическими данным) полученную из информации от сервера;
    //Входным параметром является место (Город) в котором нужно узнать погоду и косвенно поле ключ для доступа к данным
    WeatherUnit request_weather(const QString& place);

    WeatherError error() const { return _error; }
private:
    // Поле хранящее ключ пользователя для доступа к метеорологическим данным
    QString _appid{""};
    // Поле сигнализирующее об отсутвии ошибки (Или её наличии) при попытке получить данные от сервера
    WeatherError _error;
};

#endif // WEATHERREQUEST_H
