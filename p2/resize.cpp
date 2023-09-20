// Project UID af1f95f547e44c8ea88730dfb185559d

#include <iostream>
#include <fstream>
#include "Image.h"
#include "processing.h"

using namespace std;

// REQUIRES: 4 or 5 arguments (including the executable name itself). 
//           Desired width must be greater than 0 and less 
//           than or equal to original image width.
//           Desired height must be greater than 0 and less 
//           than or equal to original image height.
// MODIFIES:   
// EFFECTS: 
int main(int argc, char *argv[]) {

    if ((argc < 4) || (5 < argc)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    
    ifstream is;
    is.open(argv[1]);

    if (!is.is_open()) {
        cout << "Error opening file: " << argv[1] << endl;
        return 1;
    }

    Image* img = new Image;
    Image_init(img, is);

    int width = atoi(argv[3]);
    int height = Image_height(img);

    if (argc == 5) {
        height = atoi(argv[4]);
    } 

    if (!((0 < width) && (width <= Image_width(img)) 
         && (0 < height) && (height <= Image_height(img)))) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        delete img;
        return 1;
    }

    seam_carve(img, width, height);

    ofstream os;    
    os.open(argv[2]);
    Image_print(img, os);

    delete img;
}