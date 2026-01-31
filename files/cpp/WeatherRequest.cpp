#include "WeatherRequest.h"

WeatherUnit WeatherRequest::request_weather(const QString& place)
{
    Network::RequestSender request_sender{};
    Network::Request request{"http://api.openweathermap.org/data/2.5/weather?q=" + place + "&units=metric&lang=ru&appid=" + _appid};

    QByteArray weather_data{request_sender.get(request)};
    if (request_sender.error() != Network::RequestSender::NoError) { qDebug() << "Ошибка в получении данных"; _error = WeatherError::ExpectedError; }

    QJsonDocument document{QJsonDocument::fromJson(weather_data)};
    if (!document.isObject()) { qDebug() << "Ошибка в трансформировании Json в Document"; _error = WeatherError::ExpectedError; }

    QJsonObject object{document.object()};

    QJsonArray main_array{object.value("main")};
    QJsonArray wind_array{object.value("wind")};

    QJsonObject main_subtree{main_array.at(0).toObject()};
    QJsonObject wind_subtree{wind_array.at(0).toObject()};

    QString city_name{object.value("name").toString()};
    double temperature{main_subtree.value("temp").toDouble()}, tfeels_like{main_subtree.value("feels_like").toDouble()},
           wind_speed{wind_subtree.value("speed").toDouble()};
    int pressure{main_subtree.value("pressure").toInt()}, humidity{main_subtree.value("humidity").toInt()};

    return WeatherUnit(city_name, temperature, tfeels_like, wind_speed, humidity, pressure);
}
