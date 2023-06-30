// Includes
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <iterator>

#include <typeinfo>

// personal includes
#include "../include/vertex.h"
#include "../include/edge.h"
#include "../include/face.h"
#include "../include/object.h"

// namespaces to use
using namespace std; 
using namespace graphic;

int main( int argc, char* argv[] ) {

    cout << ":: Reader Obj Files :: " << endl;
    /*
    vector<Vertex> vertices = {};
    vector<Face> faces = {};
    vector<array<int, 2>> conexions = {};

    string line, name_oject;
    ifstream file;
    file.open("models/cube.obj", ios::in );

    if ( file.is_open() ) {
        while ( getline (file, line) ) {

            stringstream str_stream(line);
            istream_iterator<string> begin(str_stream);
            istream_iterator<string> end;
            vector<string> sub_str(begin, end);

            int i = 0;
            string type_line;

            float x = 0;
            float y = 0;
            float z = 0;

            for (auto item : sub_str) {

                if (item == "g")
                    type_line = "g";

                else if (item == "v")
                    type_line = "v";

                else if (item == "vn")
                    type_line = "vn";

                else if (item == "f")
                    type_line = "f";

                if (type_line == "g")
                    name_oject = item;

                else if (type_line == "v") {

                    if (i == 1)
                        x = stof(item);
                    else if (i == 2)
                        y = stof(item);
                    else if (i == 1)
                        z = stof(item);

                }  else if (i != 0 && type_line == "f") {

                    int item_a = item[0] - '0';
                    int item_b = item[3] - '0';

                    array<int, 2>  p2p = { item_a ,item_b };
                    conexions.push_back(p2p);
                }

                i++;
            } // end for

            if ( type_line == "v" ){
                Vertex v(x, y, z);
                vertices.push_back(v);
            }

        } // end while
    }

    int j = 0;
    vector<Edge> edges = {};
    for (auto conexion : conexions) {
        // conexion[0] & conexion[1] its indexes p2p
        Edge edge = Edge(vertices.at(conexion[0]-1), vertices.at(conexion[1]-1));
        edges.push_back(edge);

        if ( j == 2 ){
            Face face = Face(edges);
            faces.push_back(face);
            j = 0;
            edges = {};
        }

        j++;
    }

    Object object = Object(faces);

    return 0;  
    */
    string line;
    ifstream file;
    file.open("models/cube.obj", ios::in );

    if ( file.is_open() ) {
        while ( file ) {
            getline (file, line);

            stringstream str_stream(line);
            istream_iterator<string> begin(str_stream);
            istream_iterator<string> end;
            vector<string> sub_str(begin, end);


            //cout << ":: first sub string => " << sub_str << endl;
             for (auto item : sub_str)
                cout <<  item << " ";

            cout << endl;
        }
    }


    /*

    vector<Vertex> vertices = {};
    vector<Face> faces = {};

    //ifstream file("cube.obj");
    ifstream file;
    file.open("cube.obj", ios::in );

    if ( file.is_open() ) {
        while ( file ) {
            getline (file, line);
            cout << line << ": " << file.tellg() << '\n';
        }
    } else
        cout << "Ups!" << endl;
     */
    //while (getline(file, line)) {
        //cout << line << endl;
        //stringstream str_stream(line);
        //istream_iterator<string> begin(str_stream);
        //istream_iterator<string> end;
        //vector<string> sub_str(begin, end);

        // for (auto item : sub_str)
        //    cout <<  item << " ";

        //cout << endl;
        //if (line[0] == 'v') {
           // if (line[1] != 'n') {
                //cout << line << endl;
                // Vertex v(x, y, z)
                // vertices.push_back(v);
          //  }
        //} else if (line[0] == 'f') {
            //cout << line << endl;
            // Vertex va = vertices[ind-1]
            // Vertex vb
            // Vertex vc
            // Edges ea(va, vb)
            // Edges eb(vb, vc)
            // Edges ec(vc, va)
            // Face f( {ea, eb, ec} )
            // faces.push_back(f);
        //}

    //}


/*

        stringstream str_stream(line);
        istream_iterator<string> begin(str_stream);
        istream_iterator<string> end;
        vector<string> sub_str(begin, end);

        for (auto i : sub_str)
            cout <<  i << endl;

    cout << endl << ":: An Object Or Model :: " << endl;
    Vertex v1 = Vertex(0,0,0);
    Vertex v2 = Vertex(0,0,1);
    Vertex v3 = Vertex(0,1,0);
    Vertex v4 = Vertex(0,1,1);
    Vertex v5 = Vertex(1,0,0);
    Vertex v6 = Vertex(1,0,1);
    Vertex v7 = Vertex(1,1,0);
    Vertex v8 = Vertex(1,1,1);

    cout << endl << "v8 data ->  x :" << v8.get_x() << " y: " << v8.get_y() << " z: " << v8.get_z() << endl;

    Edge edge_1 = Edge(v1, v2);
    Edge edge_2 = Edge(v2, v3);
    Edge edge_3 = Edge(v3, v4);
    Edge edge_4 = Edge(v4, v1);

    vector<Edge> edges_a = {edge_1,edge_2,edge_3};
    vector<Edge> edges_b = {edge_4,edge_3,edge_1};
    Face face_1 = Face(edges_a);
    Face face_2 = Face(edges_b);
    vector<Face> faces = {face_1,face_2};

    Object obj = Object(faces);

    */
    return 0;
}
