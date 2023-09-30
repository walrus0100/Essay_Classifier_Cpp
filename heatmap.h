/*
FIXME: bounds check for the input vector
TODO:scale bmp for better quality
TODO:image classifier
 **/

#ifndef  HEATMAP_H
#define  HEATMAP_H


#include <vector>
#include <iostream>
#include <fstream>


void ScoreToRgb(double d, double good_threshold, double bad_threshold, uint8_t* rgb) {
  if (d > good_threshold) {
    rgb[0] = 255;
    rgb[1] = 255;
    rgb[2] = 255;
  } else if (d < good_threshold) {
    rgb[0] = 0 * (d - good_threshold) / (bad_threshold - good_threshold);
    rgb[1] = 255;
    rgb[2] = 255;
  } else {
    rgb[0] = 255;
    rgb[1] = 0 * (bad_threshold - d) / (bad_threshold - good_threshold);
    rgb[2] = 255;
  }
}


void scoreSSE(double d, double good_threshold, double bad_threshold, uint8_t* rgb) {
  if (d < good_threshold) {
    rgb[0] = 255;
    rgb[1] = 255;
    rgb[2] = 255;
  } else if (d < bad_threshold) {
    rgb[0] = 0 * (d - good_threshold) / (bad_threshold - good_threshold);
    rgb[1] = 255;
    rgb[2] = 255;
  } else {
    rgb[0] = 255;
    rgb[1] = 0 * (bad_threshold - d) / (bad_threshold - good_threshold);
    rgb[2] = 255;
  }
}




void 
createHMIsse(
const std::vector<double>& distmap,
double good_threshold, 
double bad_threshold,
size_t xsize,
size_t ysize,
std::vector<uint8_t>* heatmap,
const std::string& filename) {
 

  
  
  heatmap->resize(3 * xsize * ysize);
 
  for (size_t y = 0; y < ysize; ++y) {
    for (size_t x = 0; x < xsize; ++x) {
      int px = xsize * y + x;
      double d = distmap[px];
      uint8_t* rgb = &(*heatmap)[3 * px];
      scoreSSE(d, good_threshold, bad_threshold, rgb);
    }
  }

  // Create the bitmap file
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file << "BM";
    int file_size = xsize * ysize * 3 + 54;
    file.write((char*)&file_size, sizeof(int));
    int reserved = 0;
    file.write((char*)&reserved, sizeof(int));
    int offset = 54;
    file.write((char*)&offset, sizeof(int));
    int header_size = 40;
    file.write((char*)&header_size, sizeof(int));
    file.write((char*)&xsize, sizeof(int));
    file.write((char*)&ysize, sizeof(int));
    short planes = 1;
    file.write((char*)&planes, sizeof(short));
    short bpp = 24;
    file.write((char*)&bpp, sizeof(short));
    int compression = 0;
    file.write((char*)&compression, sizeof(int));
    int image_size = ysize * xsize * 3;
    file.write((char*)&image_size, sizeof(int));
    int hres = 0;
    file.write((char*)&hres, sizeof(int));
    int vres = 0;
    file.write((char*)&vres, sizeof(int));
    int colors = 5;
    file.write((char*)&colors, sizeof(int));
    int important_colors = 0;
    file.write((char*)&important_colors, sizeof(int));

  // Write the BMP image data
  for (size_t y = 0; y < ysize; ++y) {
    for (size_t x = 0; x < xsize; ++x) {
      uint8_t* rgb = &(*heatmap)[3 * (xsize * y + x)];
      file.write((char*)rgb, 3);
    }
  }

  file.close();
  std::cout << "Heatmap image saved as " << filename << std::endl;
}


void 
createHMI(
const std::vector<double>& distmap,
double good_threshold, 
double bad_threshold,
std::vector<uint8_t>* heatmap,
const std::string& filename) {
 
 size_t xsize {distmap.size()} ;
 size_t ysize {distmap.size()} ;
  
  
  heatmap->resize(3 * xsize * ysize);
 
  for (size_t y = 0; y < ysize; ++y) {
    for (size_t x = 0; x < xsize; ++x) {
      int px = xsize * y + x;
      double d = distmap[px];
      uint8_t* rgb = &(*heatmap)[3 * px];
      ScoreToRgb(d, good_threshold, bad_threshold, rgb);
    }
  }

  // Create the bitmap file
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    file << "BM";
    int file_size = xsize * ysize * 3 + 54;
    file.write((char*)&file_size, sizeof(int));
    int reserved = 0;
    file.write((char*)&reserved, sizeof(int));
    int offset = 54;
    file.write((char*)&offset, sizeof(int));
    int header_size = 40;
    file.write((char*)&header_size, sizeof(int));
    file.write((char*)&xsize, sizeof(int));
    file.write((char*)&ysize, sizeof(int));
    short planes = 1;
    file.write((char*)&planes, sizeof(short));
    short bpp = 24;
    file.write((char*)&bpp, sizeof(short));
    int compression = 0;
    file.write((char*)&compression, sizeof(int));
    int image_size = ysize * xsize * 3;
    file.write((char*)&image_size, sizeof(int));
    int hres = 0;
    file.write((char*)&hres, sizeof(int));
    int vres = 0;
    file.write((char*)&vres, sizeof(int));
    int colors = 5;
    file.write((char*)&colors, sizeof(int));
    int important_colors = 0;
    file.write((char*)&important_colors, sizeof(int));

  // Write the BMP image data
  for (size_t y = 0; y < ysize; ++y) {
    for (size_t x = 0; x < xsize; ++x) {
      uint8_t* rgb = &(*heatmap)[3 * (xsize * y + x)];
      file.write((char*)rgb, 3);
    }
  }

  file.close();
  std::cout << "Heatmap image saved as " << filename << std::endl;
}


#endif //heatmap.h
