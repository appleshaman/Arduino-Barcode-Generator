#ifndef BARCODESTRATEGY_H
#define BARCODESTRATEGY_H
#include "TFT_eSPI.h"

class BarcodeStrategy
{
public:
    virtual ~BarcodeStrategy() {}

    virtual void generate(const std::string &data, int x, int y, int barWidth, int barHeight) = 0;

    BarcodeStrategy(TFT_eSPI &tft);

protected:
    void drawBar(int x, int y, int width, int height, bool black);
    void drawPattern(const char *pattern, int &x, int y, int barWidth, int barHeight);

    TFT_eSPI &_tft;
};

#endif // BARCODESTRATEGY_H
