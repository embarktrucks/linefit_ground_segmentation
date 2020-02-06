#ifndef GROUND_SEGMENTATION_BIN_H_
#define GROUND_SEGMENTATION_BIN_H_

#include <utils/point_cloud/point_types.h>
#include <atomic>

class Bin
{
 public:
  struct MinZPoint
  {
    MinZPoint() : z(0), d(0), intensity(0), ring(0)
    {
    }
    MinZPoint(const float& d, const float& z, const float& intensity, const uint16_t& ring)
      : z(z), d(d), intensity(intensity), ring(ring)
    {
    }
    bool operator==(const MinZPoint& comp)
    {
      return z == comp.z && d == comp.d;
    }

    float z;
    float d;

    float intensity;
    uint16_t ring;
  };

 private:
  std::atomic<bool> has_point_;
  std::atomic<float> min_z;
  std::atomic<float> min_z_range;
  std::atomic<float> min_z_intensity;
  std::atomic<uint16_t> min_z_ring;

 public:
  Bin();

  /// \brief Fake copy constructor to allow vector<vector<Bin> > initialization.
  Bin(const Bin& segment);

  void addPoint(const PointXYZITLaser& point);

  void addPoint(const float& d, const float& z, const float& intensity, const uint16_t& ring);

  MinZPoint getMinZPoint();

  inline bool hasPoint()
  {
    return has_point_;
  }
};

#endif /* GROUND_SEGMENTATION_BIN_H_ */
