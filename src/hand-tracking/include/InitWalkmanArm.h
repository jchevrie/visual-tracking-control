#ifndef INITWALKMANBARM_H
#define INITWALKMANBARM_H

#include <InitPoseParticles.h>

#include <yarp/os/Bottle.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/ConstString.h>
#include <yarp/sig/Vector.h>


class InitWalkmanArm : public InitPoseParticles
{
public:
    InitWalkmanArm(const yarp::os::ConstString& cam_sel, const yarp::os::ConstString& laterality,
                   const yarp::os::ConstString& port_prefix) noexcept;

    InitWalkmanArm(const yarp::os::ConstString& cam_sel, const yarp::os::ConstString& laterality) noexcept;

    ~InitWalkmanArm() noexcept;

protected:
    Eigen::VectorXd readPose() override;

private:
    const yarp::os::ConstString  log_ID_ = "[InitWalkmanArm]";
    yarp::os::ConstString port_prefix_;

    yarp::os::BufferedPort<yarp::os::Bottle> port_arm_pose_;

    yarp::sig::Vector readRootToEE();
};

#endif /* INITWALKMANBARM_H */