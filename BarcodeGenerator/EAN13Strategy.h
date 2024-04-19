#ifndef EAN13STRATEGY_H
#define EAN13STRATEGY_H

#include "BarcodeStrategy.h"
#include <string>

class EAN13Strategy : public BarcodeStrategy {
private:
    const char* ean13Patterns[10] = {
        "0001101", "0011001", "0010011", "0111101", "0100011",
        "0110001", "0101111", "0111011", "0110111", "0001011"
    };

    int calculateChecksum(const std::string& data);

public:
    EAN13Strategy(TFT_eSPI &tft);
    virtual void generate(const std::string& data, int x, int y, int barWidth, int barHeight) override;
    
};

#endif // EAN13STRATEGY_H
