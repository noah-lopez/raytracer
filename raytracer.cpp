#include <iostream>
#include <fstream>
#include <vector>



class Vec3f {
    public:
        float x, y, z;
        Vec3f(float x=0, float y=0, float z=0) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        Vec3f operator-(const Vec3f v2) {
            return Vec3f(this->x-v2.x, this->y-v2.y, this->z-v2.z);
        }

        // Compute the Dot Product
        float operator* (const Vec3f& v2) {
            return (this->x*v2.x) + (this->y*v2.y) + (this->z*v2.z);
        }

};

class Sphere {
    public:
        Vec3f c;
        float r;
        Sphere(Vec3f c, float r) {
            this->c = c;
            this->r = r;
        }
};

void render() {
    /* documentation on .ppm file format can be found at:
       http://netpbm.sourceforge.net/doc/ppm.html */ 
    int height = 256;
    int width = 256;
    Vec3f framebuffer[height][width];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y % 2 == 0) {
                framebuffer[y][x] = Vec3f(255.f, 0.f, 0.f);
            } else {
                framebuffer[y][x] = Vec3f(0.f, 0.f, 255.f);
            }
        }
    }


    std::ofstream image;
    image.open("image.ppm", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
    image << "P6" << " " << height << " "  << width << " " << 255 << std::endl; 
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < 256; x++) {
            image << (char) framebuffer[y][x].x << (char) framebuffer[y][x].y << (char) framebuffer[y][x].z;
        }
    }
    image.close();
}


int main() {
    render();
    return 0;
}