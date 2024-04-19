#ifndef BARCODEGENERATOR_H
#define BARCODEGENERATOR_H

#include "TFT_eSPI.h"
#include <string>
#include "BarcodeStrategy.h"

class BarcodeGenerator {
private:
    BarcodeStrategy* _strategy;

public:
    BarcodeGenerator( BarcodeStrategy* strategy);
    void GenerateEAN13(const std::string& data, int x, int y, int barWidth, int barHeight);
};

#endif // BARCODEGENERATOR_H
