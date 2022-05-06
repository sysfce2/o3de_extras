/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/Interface/Interface.h>
#include <XR/XRFactory.h>

namespace XR
{
    //! Registers the global factory instance.
    void Factory::Register(Factory* instance)
    {
        AZ::Interface<Factory>::Register(instance);
    }

    //! Unregisters the global factory instance.
    void Factory::Unregister(Factory* instance)
    {
        AZ::Interface<Factory>::Unregister(instance);
    }

    bool Factory::IsReady()
    {
        return AZ::Interface<Factory>::Get() != nullptr;
    }

    //! Access the global factory instance.
    Factory& Factory::Get()
    {
        Factory* factory = AZ::Interface<Factory>::Get();
        AZ_Assert(factory, "XR::Factory failed to create!!!");
        return *factory;
    }
} // namespace XR
