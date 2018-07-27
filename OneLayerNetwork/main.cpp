//
//  main.cpp
//  OneLayerNetwork
//
//  Created by Roman Degtyarev on 27.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
#include <vector>
#include "cmatrix.h"
#include "Neuron.hpp"



int main(int argc, const char * argv[]) {
    Cmatrix X(10, 1);
    Cmatrix y(10, 1);
    X.fill(5.);
    y.fill(1);
    
    Neuron *n = new Neuron(10);
    for (auto i = 0; i< 100; i++){
        n->forward(X);
        n->backward(y);
        std::cout<<"__________"<<std::endl;
    }
    return 0;
}
