#ifndef WEATHERUNIT_H
#define WEATHERUNIT_H

#include <QString>

// Простая структура данных олицетворяющая один день со следующими данными: ["город", "температура", "ощущается как", "скорость ветра", "влажность", "давление"]
struct WeatherUnit
{
    WeatherUnit() : city{""}, temperature{0.0}, tfeels_like{0.0}, wind_speed{0.0}, humidity{0}, pressure{0} {}
    WeatherUnit(const QString& c, double t, double tf, double ws, int h, int p) : city{c}, temperature{t}, tfeels_like{tf}, wind_speed{ws}, humidity{h}, pressure{p} {}

    QString city{""};
    double temperature{0.0}, tfeels_like{0.0},
           wind_speed{0.0};
    int humidity{0}, pressure{0};
};

#endif // WEATHERUNIT_H
