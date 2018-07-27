//
//  Neuron.cpp
//  OneLayerNetwork
//
//  Created by Roman Degtyarev on 27.07.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include "Neuron.hpp"
#include <iostream>
#include <random>
#include <vector>

Neuron::Neuron(int numinputs): numinputs(numinputs),
inputs(numinputs, 1), weights(numinputs, 1),
result(0), target(numinputs, 1), prediction(numinputs, 1){
    std::default_random_engine generator;
    std::normal_distribution<double> normal_distribution( 0, 1);
    prediction.fill(0);
    
    
    for (auto i = 0; i <numinputs; i++){
        //xavier initialization
        weights.change(i, normal_distribution(generator));
    }
    
}

void Neuron::forward(Cmatrix &X){
    //save X for backward, it is local gradient
    this->inputs= X;
    
    for (auto i = 0; i< numinputs; i++)
        prediction.change(i, X.get(i, 0) * weights.get(i, 0));
    
     prediction.show();
}

void Neuron::backward(Cmatrix &target){
    assert(target.size()==prediction.size());
    Cmatrix error = Cmatrix(numinputs, 1);
    error.fill(0);
    float tot_error = 0;
    for (auto i = 0; i< numinputs; i++){
        error.change(i, (prediction.get(i, 0) - target.get(i, 0))*inputs[i]);
        tot_error+=(prediction.get(i, 0) - target.get(i, 0));
    }
    
    
    for (auto i = 0; i< numinputs; i++)
        weights.change(i, (weights[i] - lr * error[i]));
    
    
}


