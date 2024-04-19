#include "EAN13Strategy.h"

EAN13Strategy::EAN13Strategy(TFT_eSPI &tft) : BarcodeStrategy(tft) {  
}

int EAN13Strategy::calculateChecksum(const std::string& data) {
    int sum = 0;
    for (size_t i = 0; i < data.length(); i++) {
        sum += (i % 2 == 0) ? (data[i] - '0') : (data[i] - '0') * 3;
    }
    return (10 - (sum % 10)) % 10;
}

void EAN13Strategy::generate(const std::string& data, int x, int y, int barWidth, int barHeight) {
    int checksum = calculateChecksum(data);

    drawPattern("101", x, y, barWidth, barHeight); // 左边符号
    x += barWidth * 3;

    for (int i = 0; i < 6; i++) {
        drawPattern(ean13Patterns[data[i] - '0'], x, y, barWidth, barHeight);
        x += barWidth * 7;
    }

    drawPattern("01010", x, y, barWidth, barHeight);
    x += barWidth * 5;

    for (int i = 6; i < 12; i++) {
        drawPattern(ean13Patterns[data[i] - '0'], x, y, barWidth, barHeight);
        x += barWidth * 7;
    }

    drawPattern(ean13Patterns[checksum], x, y, barWidth, barHeight);
    x += barWidth * 7;

    drawPattern("101", x, y, barWidth, barHeight); // 右边符号
}
