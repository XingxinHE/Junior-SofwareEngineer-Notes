#include "edges.h"
#include <iterator>
#include <set>
using namespace std;

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  set<set<int>> edgeSet;
  for (size_t i = 0; i < F.rows(); i++)
  {
    auto face = F.row(i);
    edgeSet.insert(set<int>{face[0], face[1]});
    edgeSet.insert(set<int>{face[0], face[2]});
    edgeSet.insert(set<int>{face[1], face[2]});
  }
  E.conservativeResize(edgeSet.size(), 2);
  for (auto edgeIter = edgeSet.cbegin(); edgeIter != edgeSet.cend(); ++edgeIter)
  {
    auto edge = *edgeIter;
    for (auto edgeVertIter = edge.cbegin(); edgeVertIter != edge.cend(); ++edgeVertIter)
    {
      E(
        distance(edgeSet.cbegin(), edgeIter ),
        distance(edge.cbegin(), edgeVertIter)
       ) = *edgeVertIter;
    }
  }
  return E;
}
