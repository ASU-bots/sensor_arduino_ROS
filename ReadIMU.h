#ifndef __READIMU_H_
#define __READIMU_H_

extern const int IMU_pins;

template <class T>
inline void getIMUData(T& gx, T& gy, T& gz,
                       T& ax, T& ay, T& az,
                       T& mx, T& my, T& mz)
{
  //INSERT READ FUNCTIONS HERE!
  ++gx.data;++gy.data;++gz.data;
  ++ax.data;++ay.data;++az.data;
  ++mx.data;++my.data;++mz.data;
}

#endif
