#include <stdlib.h>

typedef struct {
	char *name;
	unsigned short int age;
} person;

typedef struct {
	int width, height;
	unsigned char* data;
	person* photographer;
} image;

void fill_person(person* p) {
	p->name = "Ben Bitdiddle";
	p->age = 20;
}

void fill_image(image *img, int height, int width) {
	if (img == NULL) {
		return;
	}
	img->data = (unsigned char*) malloc(height * width * sizeof(unsigned char));
	if (img->data == NULL) {
		return;
	}
	img->height = height;
	img->width = width;
	int x, y;
	for (y = 0; y < img->height; y++) {
		for (x = 0; x < img->width; x++) {
			int loc = y * img->width + x;
			img->data[loc] = (char) (x * y % 256);
		}
	}
}

int main() {
	image* img = (image*) malloc(sizeof(image));
	fill_image(img, 100, 100);
	person* p = (person*) malloc(sizeof(person));
	fill_person(p);
	img->photographer = p;
	return 0;
}

