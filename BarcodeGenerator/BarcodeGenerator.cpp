#include "BarcodeGenerator.h"

BarcodeGenerator::BarcodeGenerator(BarcodeStrategy* strategy) : _strategy(strategy) {}

void BarcodeGenerator::GenerateEAN13(const std::string& data, int x, int y, int barWidth, int barHeight) {
    // Code 128 or EAN-13 generation logic here
    _strategy ->generate(data, x, y, barWidth, barHeight);
    // Use drawBar and drawPattern to draw the barcode
}


