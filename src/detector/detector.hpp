// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __ETCD_DETECTOR_HPP
#define __ETCD_DETECTOR_HPP

#include <string>

#include <process/future.hpp>

#include <stout/nothing.hpp>
#include <stout/option.hpp>

#include "client.hpp"

namespace etcd {

// Forward declaration.
class LeaderDetectorProcess;

// Provides an abstraction for detecting the leader of a etcd node.
class LeaderDetector
{
public:
  LeaderDetector(const URL& url,
                 const uint8_t& retry_times,
                 const Duration& retry_interval);

  virtual ~LeaderDetector();

  process::Future<Option<std::string>> detect(
    const Option<std::string>& previous);

private:
  LeaderDetectorProcess* process;
};

} // namespace etcd {

#endif // __ETCD_DETECTOR_HPP
