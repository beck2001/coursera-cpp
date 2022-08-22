#include <iostream>
struct box {
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
}; 

void display(box);
void display(const box*);
 
int main() {
  box b = {"man in the box", 30, 30, 30, 27000};
  display(b);
  display(&b);
  return 0;
}
 
void display(box b) {
  std::cout << b.maker << " " << b.height << " " << b.width << " " << b.length << " " << b.volume << std::endl;
}
 
void display(const box* b) {
  std::cout << b->maker << " " << b->height << " " << b->width << " " << b->length << " " << b->volume << std::endl;
}
