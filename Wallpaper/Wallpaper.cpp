#include <iostream>
#include <string>
#include"Wallpaper.h"
using namespace std;

int main() 
{
    setlocale(0, "");
    RollOfWallpaper r1("Морские", 0.53, 10, 10.99);
    RollOfWallpaper r2("С узором", 0.52, 11, 11.99);
    Room rooms[2] = { Room("Зал", 6, 5, 2.7, true), Room("Спальня", 4, 3, 2.7, true) };
    Apartment apartment(rooms, 2);
    double totalWallpaperNeeded = apartment.totalWallpaperNeeded(r1, r2);
    cout << "Всего нужно: " << totalWallpaperNeeded << " метров обоев." << endl;
    return 0;
}
