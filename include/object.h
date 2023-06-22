#ifndef GRAPHIC_CC_OBJECT_H_
#define GRAPHIC_CC_OBJECT_H_

#include <iostream>
#include <string>
#include <vector>
#include "face.h"

namespace graphic {

    class Object {

        public:

            Object();
            Object(std::vector<graphic::Face> faces);
            ~Object();

            void set_faces(std::vector<graphic::Face> faces_);

            std::vector<graphic::Face> get_faces();

        private:
            std::vector<graphic::Face> faces_;
    };


}  // end namespace graphic

#endif  // GRAPHIC_CC_OBJECT_H_
