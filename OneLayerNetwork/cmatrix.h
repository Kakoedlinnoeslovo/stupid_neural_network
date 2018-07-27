//
//  cmatrix.h
//  OneLayerNetwork
//
//  Created by Roman Degtyarev on 27.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#ifndef cmatrix_h
#define cmatrix_h

class Cmatrix{
private:
    float *values;
    int total_size;
    int nrows;
    int ncols;
public:
    Cmatrix(int nrows, int ncols);
    ~Cmatrix();
    Cmatrix operator +(float scalar);
    Cmatrix operator *(float scalar);
    void fill(float value);
    float operator[](int index);
    float get(int i, int j);
    void change(int i, int j, float value);
    void change(int i, float value);
    void show();
    int size();
    Cmatrix& operator=(const Cmatrix& rhs);
};

#endif /* cmatrix_h */
