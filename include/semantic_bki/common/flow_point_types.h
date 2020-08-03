#ifndef FLOW_POINT_TYPES_H
#define FLOW_POINT_TYPES_H

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/pcl_macros.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>

namespace semantic_bki{
      /// PCL PointCloud types as input
    typedef pcl::PointXYZL PCLPointType;
    typedef pcl::PointCloud<PCLPointType> PCLPointCloud;

   //New Point Cloud that is annotated with the flow in each dimension
    // Computed with FlowNet3d as of 8/02/20

    struct XYZFlowL
    {
        PCL_ADD_POINT4D;
        float vx;
        float vy;
        float vz;
        int label;
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    } EIGEN_ALIGN16;

    typedef pcl::PointCloud<XYZFlowL> PC;


}

POINT_CLOUD_REGISTER_POINT_STRUCT (semantic_bki::XYZFlowL,           // here we assume a XYZ + "test" (as fields)
                                   (float, x, x)
                                   (float, y, y)
                                   (float, z, z)
                                   (float, vx, vx)
				   (float, vy, vy)
				   (float, vz, vz)
				   (int, label, label)
				   ) //declared inside namespace, defined outside namespace.
#endif
