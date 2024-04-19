#include "BarcodeStrategy.h"

BarcodeStrategy::BarcodeStrategy(TFT_eSPI &tft) : _tft(tft) {}

void BarcodeStrategy::drawBar(int x, int y, int width, int height, bool black) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            _tft.drawPixel(x + i, y + j, black ? TFT_BLACK : TFT_WHITE);
        }
    }
}

void BarcodeStrategy::drawPattern(const char* pattern, int& x, int y, int barWidth, int barHeight) {
    for (int i = 0; pattern[i] != '\0'; i++) {
        int barLength = pattern[i] - '0';
        drawBar(x, y, barWidth, barHeight * barLength, i % 2 == 0);
        x += barWidth;
    }
}