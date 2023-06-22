#include "../../include/vertex.h"
#include "../../include/edge.h"

namespace graphic {

    Edge::Edge(){
        this->vertex_a_ = graphic::Vertex();
        this->vertex_b_ = graphic::Vertex();
    }

    Edge::Edge(graphic::Vertex vertex_a, graphic::Vertex vertex_b){
        this->vertex_a_ = vertex_a;
        this->vertex_b_ = vertex_b;
    }

    Edge::~Edge(){}

    void Edge::set_vertex_a(graphic::Vertex vertex_a) { this->vertex_a_ = vertex_a; }
    void Edge::set_vertex_b(graphic::Vertex vertex_b) { this->vertex_b_ = vertex_b; }

    graphic::Vertex Edge::get_vertex_a(){ return vertex_a_; }
    graphic::Vertex Edge::get_vertex_b(){ return vertex_b_; }

}
