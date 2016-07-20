#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdlib>
#include <cassert>
#include <vector>
#include <algorithm>
#include <ifstream>
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;


class Net{
public:

    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals);
    void backProp(const vector<double> &targetVals);
    void getResults(vector <double> &resultVals) const;
    double getRecentAverageError(void) const{return m_recentAverageError;}

private:

    vector<Layer> m_layers;
    double m_error;
    double m_recentAverage;
    static double m_recentAverageSmoothingFactor;
};

double Net::m_recentAverageSmoothingFactor = 100.0;


void Net::getResults(vector <double> &resultVals) const{

    resultVals.clear();

    for(int n = 0; n < m_layers.back().size()-1;n++){
        resultVals.push_back(m_layers.back()[n].getOutputVal());
    }
}

Net::Net(const vector<unsigned> &topology){

    unsigned numLayers=topology.size();

    for(unsigned layerNum=0;layerNum<numLayers;layerNum++){

        m_layers.pb(Layer());
        unsigned numOutputs= layerNum==numLayers-1 ? 0: topology[layerNum+1];

        for(unsigned neuronNum=0; neuronNum<=topology[layerNum]; neuronNum++){

            m_layers.back().pb(Neuron(numOutputs, neuronNum));
            cout<<"Made a neuron!"<<endl;
        }

        m_layers.back().back().setOutputVal(1.0);
    }

}


int main(){

    return 0;
}
