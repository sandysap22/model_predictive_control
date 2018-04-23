#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

class MPC {
 public:
  MPC();

  virtual ~MPC();

  // Solve the model given an initial state and polynomial coefficients.
  // Return the first actuatotions.
  //vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
  vector<double> Solve(Eigen::VectorXd x0, Eigen::VectorXd coeffs,vector<double> & mpc_xs, vector<double> & mpc_ys);
};

#endif /* MPC_H */
