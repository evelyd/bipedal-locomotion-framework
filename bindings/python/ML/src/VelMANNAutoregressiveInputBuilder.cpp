/**
 * @file VelMANNAutoregressiveInputBuilder.cpp
 * @authors Evelyn D'Elia
 * @copyright 2024 Istituto Italiano di Tecnologia (IIT). This software may be modified and
 * distributed under the terms of the BSD-3-Clause license.
 */

#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <BipedalLocomotion/ML/VelMANNAutoregressiveInputBuilder.h>
#include <BipedalLocomotion/bindings/ML/VelMANNAutoregressiveInputBuilder.h>
#include <BipedalLocomotion/bindings/System/Advanceable.h>

namespace BipedalLocomotion
{
namespace bindings
{
namespace ML
{

void CreateVelMANNAutoregressiveInputBuilder(pybind11::module& module)
{
    namespace py = ::pybind11;
    namespace ML = BipedalLocomotion::ML;
    namespace System = BipedalLocomotion::System;

    py::class_<ML::VelMANNHumanInput>(module, "VelMANNHumanInput")
        .def(py::init())
        .def_readwrite("human_base_position", &ML::VelMANNHumanInput::humanBasePosition)
        .def_readwrite("human_base_rotation", &ML::VelMANNHumanInput::humanBaseRotation)
        .def_readwrite("human_base_linear_velocity", &ML::VelMANNHumanInput::humanBaseLinearVelocity)
        .def_readwrite("human_base_angular_velocity", &ML::VelMANNHumanInput::humanBaseAngularVelocity);

    BipedalLocomotion::bindings::System::CreateAdvanceable<ML::VelMANNHumanInput, //
                                                           ML::VelMANNAutoregressiveInput> //
        (module, "VelMANNAutoregressiveInputBuilder");
    py::class_<ML::VelMANNAutoregressiveInputBuilder,
               System::Advanceable<ML::VelMANNHumanInput, //
                                   ML::VelMANNAutoregressiveInput>>(module,
                                                                 "VelMANNAutoregressiveInputBuilder")
        .def(py::init());
}

} // namespace ML
} // namespace bindings
} // namespace BipedalLocomotion
