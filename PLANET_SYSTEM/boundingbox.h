#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

struct ver
{
    float x, y, z;
    ver() {};
    ver(float a, float b, float c) { x = a; y = b; z = c; }
};

class BoundingBox
{
public:
    ver maxVer;  //AABB±ß½ç¿ò
    ver minVer;
public:
    BoundingBox();
};

#endif // BOUNDINGBOX_H
