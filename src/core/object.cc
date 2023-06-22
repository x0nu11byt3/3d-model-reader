#include <vector>
#include "../../include/object.h"
#include "../../include/face.h"

namespace graphic {

    Object::Object(){}

    Object::Object(std::vector<graphic::Face> faces){
        this->faces_= faces;
    }

    Object::~Object(){}

    void Object::set_faces(std::vector<graphic::Face> faces) {
        this->faces_ = faces;
    }

    std::vector<graphic::Face> Object::get_faces(){ return faces_; }

}
