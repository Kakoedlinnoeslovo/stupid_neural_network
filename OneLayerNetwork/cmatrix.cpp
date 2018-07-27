//
//  cmatrix.cpp
//  OneLayerNetwork
//
//  Created by Roman Degtyarev on 27.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <stdio.h>
#include "cmatrix.h"
#include <iostream>
#include <string>


Cmatrix::Cmatrix(int nrows, int ncols): nrows(nrows), ncols(ncols){
    total_size = nrows*ncols;
    values = new float[total_size]();
}

Cmatrix::~Cmatrix(){
    if (values) delete[] values;
}

Cmatrix Cmatrix::operator*(float scalar){
    Cmatrix result(nrows, ncols);
    for (auto i =0; i<total_size; i++){
        result.values[i] = values[i] * scalar;
    }
    return result;
}

Cmatrix Cmatrix::operator+(float scalar){
    Cmatrix result(nrows, ncols);
    for (auto i =0; i<total_size; i++){
        result.values[i] = values[i] + scalar;
    }
    return result;
}

void Cmatrix::fill(float value){
    for (auto i =0; i<total_size; i++)
        values[i]=value;
}

void Cmatrix::show(){
    if (values){
        for (auto i=0; i<nrows; i++){
            std::string delimer = "";
            for (auto j=0; j<ncols; j++){
                std::cout<<delimer<<values[i * ncols + j];
                delimer = ",";
            }
            std::cout<<std::endl;
        }
    }
}

Cmatrix& Cmatrix::operator=(const Cmatrix& rhs){
    if (&rhs == this)
        return *this;
    if (total_size == rhs.total_size){
        std::memcpy(values, rhs.values, rhs.total_size * sizeof(int));
    }
    else{
        delete [] values;
        values = new float [rhs.total_size]();
        std::memcpy(values, rhs.values, rhs.total_size * sizeof(float));
    }
    nrows = rhs.nrows;
    ncols = rhs.ncols;
    total_size = rhs.total_size;
    
    return *this;
};

int Cmatrix::size(){
    return this->total_size;
}

float Cmatrix::operator[](int i){
    return values[i];
}

float Cmatrix::get(int i, int j){
    return values[i*ncols + j];
}

void Cmatrix::change(int i, int j, float value){
    this->values[i*this->ncols +j] = value;
};

void Cmatrix::change(int i, float value){
    this->values[i*this->ncols] = value;
};

