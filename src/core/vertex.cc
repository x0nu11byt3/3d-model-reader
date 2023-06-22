#include "../../include/vertex.h"

namespace graphic {


    Vertex::Vertex(){
        
        this->x_float_ = 0;
        this->y_float_ = 0;
        this->z_float_ = 0;
        
        this->x_int_ = 0;
        this->y_int_ = 0;
        this->z_int_ = 0;
        
    }
    
    
    Vertex::Vertex(int x, int y, int z){
        this->x_int_ = x;
        this->y_int_ = y;
        this->z_int_ = z;
    }
    
    Vertex::Vertex(float x, float y, float z){
        this->x_float_ = x;
        this->y_float_ = y;
        this->z_float_ = z;
    }
    
    
    Vertex::~Vertex(){}
    
    void Vertex::set_x(float x_float) { x_float_ = x_float; }
    void Vertex::set_y(float y_float) { y_float_ = y_float; }
    void Vertex::set_z(float z_float) { z_float_ = z_float; }
    
    void Vertex::set_x_int(int x) { this->x_int_ = x; }
    void Vertex::set_y_int(int y) { this->y_int_ = y; }
    void Vertex::set_z_int(int z) { this->z_int_ = z; }
                  
    
    float Vertex::get_x(){ return x_float_; }
    float Vertex::get_y(){ return y_float_; }
    float Vertex::get_z(){ return z_float_; }
    
    int Vertex::get_x_int(){ return x_int_; }
    int Vertex::get_y_int(){ return y_int_; }
    int Vertex::get_z_int(){ return z_int_; }
    

}  // end namespace dictionary
