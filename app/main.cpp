#include <FreeImage.h>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <FreeImagePlus.h>

std::string cropame(std::string n){
    std::size_t pos = n.find_last_of('.');
    std::string res = n.substr(0,pos);

    return res;
}

fipImage openFile(std::string n){
    fipImage image;

    if(!image.load(n.c_str())){
        std::cout << "Could not load " << n << std::endl;
        exit(EXIT_FAILURE);
    }

    return image;
}

void convert(fipImage image, std::string name){
    int n;

    std::string aux = cropame(name);
    std::string outputName;

    std::cout << "Choose a path and name for the output image (Write the name only for current path): ";
    std::cin >> outputName;
    //outputName.append(aux);
    std::cout << "Choose a supported format for the conversion: 1-bpm 2-jpeg 3-png 4-webp 5-tiff 6-ppm 7-hdr 8-exr 9-xmp" << std::endl;
    std::cin >> n;
    
switch (n) {
            case 1: outputName += ".bmp"; image.save(outputName.c_str(), BMP_DEFAULT); break;
            case 2: outputName += ".jpg"; image.save(outputName.c_str(), JPEG_DEFAULT); break;
            case 3: outputName += ".png"; image.save(outputName.c_str(), PNG_DEFAULT); break;
            case 4: outputName += ".webp"; image.save(outputName.c_str(), WEBP_DEFAULT); break;
            case 5: outputName += ".tiff"; image.save(outputName.c_str(), TIFF_DEFAULT); break;
            case 6: outputName += ".ppm"; image.save(outputName.c_str(), FIF_PPM); break;
            case 7: outputName += ".hdr"; image.save(outputName.c_str(), HDR_DEFAULT); break;
            case 8: outputName += ".exr"; image.save(outputName.c_str(), EXR_DEFAULT); break;
            case 9: outputName += ".xpm"; image.save(outputName.c_str(), XPM_DEFAULT); break;
            default: std::cerr << "Invalid option selected\n"; break;
}
}

int main(int argc, char *argv[]){

    std::string name;

    std::cout << "Select the image to covert: ";
    std::cin >> name;

    fipImage image = openFile(name);
    convert(image, name);
    
    return 0;
}