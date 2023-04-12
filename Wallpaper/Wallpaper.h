#pragma once
#include <iostream>
#include <string>

using namespace std;
class RollOfWallpaper {
public:
    RollOfWallpaper(string n, double w, double l, double p) : name(n), width(w), length(l), price(p) {}
    double getArea() const { return width * length; }
    double getPrice() const { return price; }
private:
    string name;
    double width;
    double length;
    double price;
};

class Room {
public:
    Room(string n, double l, double w, double h, bool c) : name(n), length(l), width(w), height(h), ceiling(c) {}
    double wallpaperNeeded(RollOfWallpaper r) const;
private:
    string name;
    double length;
    double width;
    double height;
    bool ceiling;
};

class Apartment {
public:
    Apartment(Room* rooms, int count) : rooms(rooms), count(count) {}
    double totalWallpaperNeeded(RollOfWallpaper r1, RollOfWallpaper r2) const;
private:
    Room* rooms;
    int count;
};

double Room::wallpaperNeeded(RollOfWallpaper r) const {
    double perimeter = 2 * (length + width);
    if (ceiling)
    {
        double area = perimeter * height;
        return area / r.getArea();
    }
    else
    {
        double area = perimeter * height + length * width;
        return area / r.getArea();
    }
}

double Apartment::totalWallpaperNeeded(RollOfWallpaper r1, RollOfWallpaper r2) const {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += rooms[i].wallpaperNeeded(r1);
        total += rooms[i].wallpaperNeeded(r2);
    }
    return total;
}

