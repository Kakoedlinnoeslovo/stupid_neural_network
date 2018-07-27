//
//  Neuron.hpp
//  OneLayerNetwork
//
//  Created by Roman Degtyarev on 27.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <vector>
#include "cmatrix.h"

class Neuron{
private:
    int numinputs;
    float output;
    Cmatrix inputs;
    Cmatrix target;
    Cmatrix prediction;
    Cmatrix weights;
    float lr = 0.01;
public:
    float result;
    Neuron(int numinputs);
    void forward(Cmatrix &X);
    void backward(Cmatrix &target);
};

#endif /* Neuron_hpp */
