#include "edges.h"
#include "euler_characteristic.h"
#include <set>
using namespace std;

int euler_characteristic(const Eigen::MatrixXi &F)
{
  set<int> V(F.data(), F.data() + F.cols() * F.rows());
  Eigen::MatrixXi E = edges(F);
  return V.size() - E.rows() + F.rows();
}
