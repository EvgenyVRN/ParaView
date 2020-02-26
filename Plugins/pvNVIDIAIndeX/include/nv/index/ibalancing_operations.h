/******************************************************************************
 * Copyright 2020 NVIDIA Corporation. All rights reserved.
 *****************************************************************************/
/// \file
/// \brief Workload balancing operations

#ifndef NVIDIA_INDEX_IBALANCING_OPERATIONS_H
#define NVIDIA_INDEX_IBALANCING_OPERATIONS_H

#include <mi/base/types.h>
#include <mi/dice.h>
#include <mi/base/interface_declare.h>

namespace nv
{
namespace index
{

/// The interface class for all balancing operations generated by NVIDIA IndeX when redistributing
/// workload in the cluster. Each operation provides a descriptive explanation 
/// of the operation itself.
///
/// \ingroup nv_index_workload_balancing
///
class IBalancing_operation :
    public mi::base::Interface_declare<0x3eec45f1,0x171f,0x4259,0xb1,0xef,0xfd,0x6f,0xae,0xef,0x9b,0xab>
{
public:
    /// Returns a descriptive string detailing the balancing operation.
    ///
    /// \return         The description of the operation in textual form.
    ///
    virtual const char* get_description() const = 0;
};

/// \ingroup nv_index_workload_balancing
class IReassignment_operation :
    public mi::base::Interface_declare<0xa09228d8,0x46d9,0x4c68,0xb9,0xdc,0xae,0xba,0x3e,0xb4,0x13,0xb9,
        nv::index::IBalancing_operation>
{
};

/// \ingroup nv_index_workload_balancing
class IMerge_operation :
    public mi::base::Interface_declare<0xb5ad623b,0xc47f,0x483e,0x99,0xea,0x41,0x58,0x47,0xea,0xa5,0x2b,
        nv::index::IBalancing_operation>
{
};

/// \ingroup nv_index_workload_balancing
class ISplit_operation :
    public mi::base::Interface_declare<0x7c4a3ac0,0x519d,0x461d,0xbe,0x8a,0x20,0x71,0x7f,0x73,0x52,0x43,
        nv::index::IBalancing_operation>
{
};

/// \ingroup nv_index_workload_balancing
/// This class serves as a collection of all workload balancing operations that occurred and the NVIDIA IndeX
/// produced when redistributing workload for scalable rendering and data processing.
///
class IBalancing_operations :
    public mi::base::Interface_declare<0xe65365e8,0x52ed,0x4874,0xbd,0x73,0x1c,0xd8,0x26,0xdf,0x1a,0x5a>
{
public:
    /// Returns a descriptive string detailing the balancing operation.
    ///
    /// \return         The description of the operation in textual form.
    ///
    virtual const char* get_event_description() const = 0;

    /// Returns the number of workload balancing operations.
    ///
    /// \return         Returns the number of the contained workload balancing operations.
    ///
    virtual mi::Uint32  get_nb_operation() const = 0;

    /// Allows accessing each instances of \c IBalancing_operation interfaces that are exposed.
    ///
    /// \note Use the \c mi::base::Handle template to store the returned interface pointer in order
    ///       to guarantee the correct destruction of the returned interface.
    ///
    /// \param[in] idx  The index of the requested \c IBalancing_operation interface instance.
    ///
    /// \return         Returns interface pointer to the requested error instance or a null-pointer
    ///                 to indicate an invalid access index.
    ///
    virtual const IBalancing_operation* get_operation(mi::Uint32 idx) const = 0;
};

}} // namespace index / nv

#endif // NVIDIA_INDEX_IBALANCING_OPERATIONS_H
