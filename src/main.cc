// Includes
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iterator>
#include <armadillo>
#include <typeinfo>

// personal includes
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/face.h"
#include "../include/object.h"

// namespaces to use
using namespace std; 
using namespace graphic;

bool is_number(const string& str);

int main( int argc, char* argv[] ) {

    cout << ":: Reader Obj / ply Files :: " << endl;
    vector<Vertex> vertices = {};
    vector<Face> faces = {};
    vector<array<int, 2>> conexions = {};

    string line, name_oject;
    string path = "";
    string filename = "";
    string ply_init = "";
    string ply_title = "";
    string ply_format = "";
    
    vector<string> ply_properties_face = {};
    
    int vertex_index = 0;
    int vertex_amount = 0;
    int face_index = 0;
    int face_amount = 0;
    
    if ( argc > 1) 
        filename = argv[1];
    
    ifstream file;
    file.open( path + filename , ios::in );

    int flag_x_int = 0;
    int flag_x_float = 0;
    int flag_y_int = 0;
    int flag_y_float = 0;
    int flag_z_int = 0;
    int flag_z_float = 0;
    
    int x_int, y_int, z_int;
    float x_float, y_float, z_float;
    
    // 0 - nothing | 1 - vertices | 2 - faces
    int flag_current_element = 0;  
    
    
    if ( file.is_open() ) {
        while ( getline (file, line) ) {
            
            x_int = y_int = z_int = 0;
            x_float = y_float = z_float = 0;
            
            stringstream str_stream(line);
            istream_iterator<string> begin(str_stream);
            istream_iterator<string> end;
            vector<string> sub_str(begin, end);
            string type_line = "";
                
                if ( sub_str[0] == "ply" )
                    ply_init = ":: Init PLY File ::";
                
                else if ( sub_str[0] == "format")
                    for ( size_t i = 0; i < sub_str.size(); ++i ) 
                        ply_format = ply_format + " " + sub_str[i];
                
                else if ( sub_str[0] == "comment") 
                    for ( size_t i = 0; i < sub_str.size(); ++i )
                        ply_title = ply_title + " " + sub_str[i];
                
                else if ( sub_str[0] == "element" ) {
                    
                    if ( sub_str[ 1 ] == "vertex" ){
                       
                        if ( is_number(sub_str[ 2 ]) )
                            vertex_amount = stoi(sub_str[ 2 ]);
                        else 
                            cout << " :: Not its digit UPS! :: " << endl; 
                        flag_current_element = 1;
                        
                    } 
                    if ( sub_str[  1 ] == "face" ) {
                        
                        if ( is_number(sub_str[ 2 ]) )
                            face_amount = stoi(sub_str[ 2 ]);
                        else 
                            cout << " :: Not its digit UPS! :: " << endl;
                        flag_current_element = 2;
                    }
                        
                    
                }  else if ( sub_str[0] == "property" && flag_current_element == 1 ) {
                   
                    if (  sub_str[  1 ]  == "int" && sub_str[  2 ]  == "x")
                        flag_x_int = 1;
                    else if (  sub_str[  1 ]  == "float" && sub_str[  2 ]  == "x" )
                        flag_x_float = 1;
                    
                    if (  sub_str[  1 ]  == "int" && sub_str[  2 ]  == "y")
                         flag_y_int = 1;
                     else if (  sub_str[  1 ]  == "float" && sub_str[  2 ]  == "y" )
                        flag_y_float = 1;
                    
                    if (  sub_str[  1 ]  == "int" && sub_str[  2 ]  == "z")
                        flag_z_int = 1;
                    else if (  sub_str[  1 ]  == "float" && sub_str[  2 ]  == "z" )
                        flag_z_float = 1;
                    
                } else if ( sub_str[0] == "property" && flag_current_element == 2 ) { 
                    // fix section
                    ply_properties_face.push_back(sub_str[1]);
                    ply_properties_face.push_back(sub_str[2]);
                    ply_properties_face.push_back(sub_str[3]);
                    ply_properties_face.push_back(sub_str[4]);
                } else if ( sub_str[0] != "ply" && sub_str[0] != "format" && sub_str[0] != "comment" && sub_str[0] != "element" && sub_str[0] != "property" && sub_str[0] != "end_header"){
                    
                    if ( vertex_index < vertex_amount ) {
                        //void *x = NULL;
                        //void *y = NULL;
                        //void *z = NULL;
                       
                        if ( flag_x_int  )
                             x_int =  stoi(sub_str[0]);
                        if ( flag_x_float ) 
                             x_float =  stof(sub_str[0]);
                    
                        if ( flag_y_int )
                            y_int =  stoi(sub_str[1]);
                        else
                            y_float =  stof(sub_str[1]);
                            
                        if ( flag_z_int )
                            z_int =  stoi(sub_str[2]);
                        else 
                            z_float =  stof(sub_str[2]);
                        
                        Vertex vertex = Vertex();
                        if ( flag_x_int && flag_y_int && flag_z_int){
                            
                            vertex.set_x_int(x_int);
                            vertex.set_y_int(y_int);
                            vertex.set_z_int(z_int);
                            
                        } else if ( flag_x_float && flag_y_float && flag_z_float ){
                            vertex.set_x(x_float);
                            vertex.set_y(y_float);
                            vertex.set_z(z_float);
                        }
                            
                        vertices.push_back(vertex);
                        vertex_index++;
                        
                    } else if ( vertex_index == vertex_amount && face_index < face_amount ) {
                        
                        vector<int> indexes = {};
                        for ( size_t i = 0; i < sub_str.size(); ++i ) {
                            int index_tmp = stoi(sub_str[i]);
                            indexes.push_back(index_tmp);
                        }
                        Face face = Face(indexes);
                        faces.push_back(face);
                        face_index++;
                    }  //end if face amount
                } // end if != header metadata 
        } // end while
    } // end if
    
    Object object = Object(faces);
    
    cout << ":: Init project :: " << endl;
    cout << ":: INIT :: Header PLY File :: " << endl;
    
    cout << "[+] ply_init :" << ply_init << endl;
    cout << "[+] ply_format :" << ply_format << endl;
    cout << "[+] ply_comment :" << ply_title << endl;
    
    cout << ":: Metadata - Vertices  :: " << endl;
    cout << "[+] Amount vertices :" << vertex_amount << endl;
    string res_x = (flag_x_int) ? "int x" : "float x";
    cout << "::  property : " <<  res_x << endl;
    string res_y = (flag_y_int) ? "int y" : "float y";
    cout << "::  property : " <<  res_y << endl;
    string res_z = (flag_z_int) ? "int z" : "float z";
    cout << "::  property : " <<  res_z << endl;
    
    cout << ":: ply_properties_face : " << ply_properties_face[0] << " " << ply_properties_face[1] <<  " " << ply_properties_face[2] <<  " " << ply_properties_face[3] << endl;
    cout << ":: flag_current_element : " << flag_current_element << endl; 
    
    cout << ":: Metadata - Vertices  :: " << endl;
    cout << "[+] Amount faces :" << face_amount << endl;
    
    cout << ":: END :: Header PLY File :: " << endl;
    
    for ( size_t i = 0; i < vertices.size(); ++i ) 
        cout << "vertice[ " << i+1 << " ]" << ":: X: " << vertices[i].get_x() << " Y: " << vertices[i].get_y() << " Z: " << vertices[i].get_z() << endl;
    
    for ( size_t j = 0; j < faces.size(); ++j ){
        
        cout << "face[ " << j+1 << " ]";
        
        vector<int> indx = faces[j].get_indexes();
        
        for ( size_t k = 0; k < indx.size(); ++k )
            
            cout << " " << indx[k] << " ";
        
        cout << endl;
            
        
    } 
         
    return 0;  
}

bool is_number(const string& str) {
    for (char const &c : str) 
        if ( std::isdigit(c) == 0 )
            return false;
    return true;
}
