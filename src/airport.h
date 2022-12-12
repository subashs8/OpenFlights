#pragma once
#include <string>
#include<cmath>
using namespace std;

class airport {
    public:
        airport(string name, string city, string code, double lat, double lon);
        double getDist(airport dest);
        string getName();
        string getCity();
        string getCode();
        double getLat();
        double getLon();

    private:
        string name;
        string city;
        string code;
        double lat;
        double lon;
};