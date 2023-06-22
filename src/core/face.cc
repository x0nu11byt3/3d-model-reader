#include <vector>
#include "../../include/face.h"
#include "../../include/edge.h"

namespace graphic {

    Face::Face(){}

    Face::Face(std::vector<graphic::Edge> edges){
        this->edges_= edges;
    }
    
    Face::Face(std::vector<int> vertex_index){
        this->indexes_= vertex_index;
    }

    Face::~Face(){}

    void Face::set_edges(std::vector<graphic::Edge> edges) {
        this->edges_ = edges;
    }
    
    void Face::set_index(std::vector<int> vertex_index) {
        this->indexes_ = vertex_index;
    }

    std::vector<graphic::Edge> Face::get_edges(){ return edges_; }
    std::vector<int> Face::get_indexes(){ return indexes_; }

}
