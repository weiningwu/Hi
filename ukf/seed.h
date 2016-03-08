/**
 * \file seed.h
 * \brief Contains data structure for storing seed point information.
*/

#ifndef SEED_H_
#define SEED_H_

#include "unscented_kalman_filter.h"
#include "linalg.h"

/**
 * \class SeedPointInfo
 * \brief Describes a seed point
 *
 * Stores all information for a seed point to start tractography. The
 * start_dir is only used for the simple model and the angles only for the
 * complex/full representation.
*/
class SeedPointInfo
  {
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  /** The state of the state-space represenation of the model. */
  State state;
  /** The covariance matrix of the state */
  ukfMatrixType covariance;
  /** The location of the seed */
  vec3_t point;
  /** The starting direction for the simple model */
  vec3_t start_dir;
  /** Fractional Anisotropy of the first tensor */
  ukfPrecisionType fa;
  /** Fractional Anisotropy of the second tensor */
  ukfPrecisionType fa2;
  /** Trace of the first tensor */
  ukfPrecisionType trace;
  /** Trace of the second tensor */
  ukfPrecisionType trace2;
  };

/** Writes debug information about seeds to stdout. */
void PrintSeedInfo(const std::vector<SeedPointInfo>& seed_infos);

#endif
