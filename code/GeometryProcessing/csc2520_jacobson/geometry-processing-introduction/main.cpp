#include <chrono>
#include "edges.h"
#include "euler_characteristic.h"
#include "igl/edges.h"
#include "igl/euler_characteristic.h"
#include <igl/read_triangle_mesh.h>
#include <igl/opengl/glfw/Viewer.h>

int main(int argc, char *argv[])
{
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  // Load in a mesh
  igl::read_triangle_mesh(argc>1 ? argv[1] : "../data/bunny.off", V, F);


  // My Implementation
  std::cout <<"My implementation: " << std::endl;
  auto start = std::chrono::high_resolution_clock::now();
  Eigen::MatrixXi E = edges(F);
  int Chi = euler_characteristic(F);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Edge list E is "<<E.rows() << "x" << E.cols() << std::endl;
  std::cout << "Euler Characteristic: " << Chi << std::endl;
  std::cout << "Time: " << duration.count() << std::endl;

  // Libigl Implementation
  std::cout << "Libigl implementation: " << std::endl;
  start = std::chrono::high_resolution_clock::now();
  Eigen::MatrixXi EIGL;
  igl::edges(F, EIGL);
  Chi = igl::euler_characteristic(F);
  stop = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "Edge list E is " << EIGL.rows() << "x" << EIGL.cols() << std::endl;
  std::cout << "Euler Characteristic: " << Chi << std::endl;
  std::cout << "Time: " << duration.count() << std::endl;

  // Create a libigl Viewer object 
  igl::opengl::glfw::Viewer viewer;
  // Set the vertices and faces for the viewer
  viewer.data().set_mesh(V, F);
  // Launch a viewer instance
  viewer.launch();
  return 0;
}

