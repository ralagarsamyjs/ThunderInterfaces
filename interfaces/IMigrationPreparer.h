/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2022 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

struct EXTERNAL IMigrationPreparer : virtual public Core::IUnknown {
    enum { ID = ID_MIGRATION_PREPARER };

    struct EXTERNAL INotification : virtual public Core::IUnknown {
        enum { ID = ID_MIGRATION_PREPARER_NOTIFICATION };

        virtual void ValueChanged(const string &name, const string &value) = 0;
    };

    virtual uint32_t Register(Exchange::IMigrationPreparer::INotification *notification) = 0;
    virtual uint32_t Unregister(Exchange::IMigrationPreparer::INotification *notification) = 0;
    virtual uint32_t Write(const string &name, const string &value) = 0;
    virtual uint32_t Read(const string& name, string &value/* @out */) = 0;
    virtual uint32_t Delete(const string &name) = 0;
    virtual uint32_t getComponentReadiness(RPC::IStringIterator*& compList/* @out */) = 0;
    virtual uint32_t setComponentReadiness(const string &compName) = 0;
    virtual uint32_t reset(const string &type) = 0;
};

} // namespace Exchange
} // namespace WPEFramework
