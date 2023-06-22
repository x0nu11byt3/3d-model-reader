#ifndef GRAPHIC_CC_VERTEX_H_
#define GRAPHIC_CC_VERTEX_H_

#include <iostream>
#include <string>

namespace graphic {

    class Vertex {
    
        public:
             
            Vertex();
            Vertex(int x, int y, int z);
            Vertex(float x, float y, float z);
            ~Vertex();

            void set_x(float x);
            void set_y(float y);
            void set_z(float z);

            float get_x();
            float get_y();
            float get_z();
            
            void set_x_int(int x);
            void set_y_int(int y);
            void set_z_int(int z);

            int get_x_int();
            int get_y_int();
            int get_z_int();
                      
        private:
            float x_float_;
            float y_float_;
            float z_float_;
            
            int x_int_;
            int y_int_;
            int z_int_;
    };


}  // end namespace graphic

#endif  // GRAPHIC_CC_VERTEX_H_
