void fill(vector < vector < int > > &image, int sr, int sc, int newColor, int oldColor) {
  if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldColor) {
    return;
  }

  if (image[sr][sc] == oldColor) {
    image[sr][sc] = newColor;
  }

  fill(image, sr - 1, sc, newColor, oldColor);
  fill(image, sr, sc - 1, newColor, oldColor);
  fill(image, sr + 1, sc, newColor, oldColor);
  fill(image, sr, sc + 1, newColor, oldColor);

}

vector < vector < int > > floodFill(vector < vector < int > > &image, int sr, int sc, int newColor) {
  int oldColor = image[sr][sc];
  if (oldColor == newColor) {
    return image;
  }
  fill(image, sr, sc, newColor, oldColor);
  return image;
}
