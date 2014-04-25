void setColorHSB(int hue, unsigned int saturation, unsigned int value) {
  // Adaptation of http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB
  long chroma = value * saturation / 255;
  long secondary = chroma * (60 - abs((hue % 120) - 60)) / 60;
  int offset = value - chroma;
  byte r = 0, g = 0, b = 0;

  if (hue < 60) {
    r = chroma;
    g = secondary;
  } else if (hue < 120) {
    r = secondary;
    g = chroma;
  } else if (hue < 180) {
    g = chroma;
    b = secondary;
  } else if (hue < 240) {
    g = secondary;
    b = chroma;
  } else if (hue < 300) {
    r = secondary;
    b = chroma;
  } else if (hue < 360) {
    r = chroma;
    b = secondary;
  }

  setColorAdjusted(r+offset, g+offset, b+offset);
}