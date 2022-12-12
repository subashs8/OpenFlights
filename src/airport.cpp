#include "airport.h"

airport::airport(string name, string city, string code, double lat, double lon) {
    this->name = name;
    this->city = city;
    this->code = code;
    this->lat = lat;
    this->lon = lon;
}

double airport::getDist(airport dest){
    double x_2 = pow(lat - dest.getLat(),2);
    double y_2 = pow(lon - dest.getLon(),2); 
    return x_2 + y_2;
}
string airport::getName() {
    return name;
}
string airport::getCity() {
    return city;
}
string airport::getCode() {
    return code;
}
double airport::getLat() {
    return lat;
}
double airport::getLon() {
    return lon;
}