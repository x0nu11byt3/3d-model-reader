#ifndef GRAPHIC_CC_FACE_H_
#define GRAPHIC_CC_FACE_H_

#include <iostream>
#include <string>
#include <vector>
#include "edge.h"

namespace graphic {

    // In reallity Face its same a Polygon
    class Face {

        public:

            Face();
            Face( std::vector<graphic::Edge> edges);
            Face( std::vector<int> vertex_index);
            ~Face();

            void set_edges(std::vector<graphic::Edge> edges);
            void set_index(std::vector<int> vertex_index);

            std::vector<graphic::Edge> get_edges();
            std::vector<int> get_indexes();

        private:
            std::vector<graphic::Edge> edges_;
            std::vector<int> indexes_;

    };


}  // end namespace graphic

#endif  // GRAPHIC_CC_FACE_H_
