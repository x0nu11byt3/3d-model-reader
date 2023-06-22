#ifndef GRAPHIC_CC_EDGE_H_
#define GRAPHIC_CC_EDGE_H_

#include <iostream>
#include <string>
#include "vertex.h"

namespace graphic {

    class Edge {

        public:

            Edge();
            Edge(graphic::Vertex vertex_a, graphic::Vertex vertex_b);
            ~Edge();

            void set_vertex_a(graphic::Vertex vertex_a);
            void set_vertex_b(graphic::Vertex vertex_b);

            graphic::Vertex get_vertex_a();
            graphic::Vertex get_vertex_b();

        private:
            graphic::Vertex vertex_a_;
            graphic::Vertex vertex_b_;

    };


}  // end namespace graphic

#endif  // GRAPHIC_CC_EDGE_H_
